#version 430

#define EPSILON 0.001
#define BIG 1000000.0
const int DIFFUSE = 1;
const int REFLECTION = 2;
const int REFRACTION = 3;

in vec3 interpolated_vertex;
out vec4 FragColor;

//--------Data structures-------------------------------------------------------

struct Camera
{
	vec3 position;
	vec3 view;
	vec3 up;
	vec3 side;
};

struct Ray
{
	vec3 origin;
	vec3 direction;
};

/*struct Material
{
	float ambient;
	float diffuse;
	float specular;
	float specular_power;
};*/

struct Material
{
	vec3 Color;

	vec4 LightCoeffs;

	float ReflectionCoef;
	float RefractionCoef;
	int MaterialType;
};

struct Intersection
{
	float time;
	vec3 point;
	vec3 normal;
	vec3 color;
	int material_idx;

	vec4 LightCoeffs;
};

struct Light
{
	vec3 position;
};

struct Sphere
{
	vec3 center;
	float radius;
	vec3 color;
	int material_idx;
};

struct STriangle
{
	vec3 v1;
	vec3 v2;
	vec3 v3;
	int material_idx;
};

//--------Buffers---------------------------------------------------------------

layout(std430, binding = 0) buffer SphereBuffer
{
	Sphere sphere_data[];
};

//--------Setup default values-------------------------------------------------

//Material material = {0.4, 0.9, 0.0, 512.0};
vec3 light_pos = vec3(1, 0, -8);

//--------Uniform values--------------------------------------------------------

uniform Camera camera;

uniform vec2 scale;

//--------Functions declaration-------------------------------------------------

Ray GenerateRay (Camera camera);
bool IntersectSphere (Sphere sphere, Ray ray, float start, float final, out float time);
bool Intersect (Ray ray, float start, float final, inout Intersection intersect);
vec3 Phong (Intersection interset, Light currLight);
float Shadow (Light currLight, Intersection intersect);
vec4 Raytrace (Ray primary_ray);

//--------Functions-------------------------------------------------------------

Ray GenerateRay (Camera camera)
{
	vec2 coords = interpolated_vertex.xy * normalize(scale);
	vec3 direction = camera.view + camera.side * coords.x + camera.up * coords.y;
	return Ray(camera.position, normalize(direction));
}

bool IntersectSphere (Sphere sphere, Ray ray, float start, float final, out float time)
{
	ray.origin -= sphere.center;
	float A = dot (ray.direction, ray.direction);
	float B = dot (ray.direction, ray.origin);
	float C = dot (ray.origin, ray.origin) - sphere.radius * sphere.radius;
	float D = B * B - A * C;
	if (D > 0.0)
	{
		D = sqrt(D);
		float t1 = (-B - D) / A;
		float t2 = (-B + D) / A;
		if (t1 < 0 && t2 < 0)
		{
			return false;
		}
		if (min(t1, t2) < 0)
		{
			time = max(t1, t2);
			return true;
		}
		time = min(t1, t2);
		return true;
	}
	return false;
}

bool Intersect (Ray ray, float start, float final, inout Intersection intersect)
{
	bool result = false;
	float time = start;
	intersect.time = final;

	for(int i = 0; i < sphere_data.length(); i++)
	{
		if (IntersectSphere(sphere_data[i], ray, start, final, time) && time < intersect.time)
		{
			intersect.time = time;
			intersect.point = ray.origin + ray.direction * time;
			intersect.normal = normalize(intersect.point - sphere_data[i].center);
			intersect.color = sphere_data[i].color;
			intersect.material_idx = sphere_data[i].material_idx;
			result = true;
		}
	}
	return result;
}

vec3 Phong (Intersection intersect, Light currLight)
{
	vec3 light = normalize (currLight.position - intersect.point);
	float diffuse = max(dot(light, intersect.normal), 0.0);
	vec3 view = normalize(camera.position - intersect.point);
	vec3 reflected = reflect(-view, intersect.normal);
	float specular = pow(max(dot(reflected, light), 0.0), intersect.LightCoeffs.w);
	return intersect.LightCoeffs.x * intersect.color + intersect.LightCoeffs.y * diffuse * intersect.color +
		intersect.LightCoeffs.z * specular /** Unit*/;
}

float Shadow (Light currLight, Intersection intersect)
{
	float shadowing = 1.0;
	vec3 direction = normalize(currLight.position - intersect.point);
	float distanceLight = distance(currLight.position, intersect.point);
	Ray shadowRay = Ray(intersect.point + direction * EPSILON, direction);
	Intersection shadowIntersect;
	shadowIntersect.time = BIG;
	if (Raytrace(shadowRay) == vec4(0, 0, 0 ,0))
	{
		shadowing = 0.0;
	}
	return shadowing;
}

vec4 Raytrace (Ray primary_ray)
{
	vec4 resultColor = vec4(0, 0 ,0 ,0);
	Ray ray = primary_ray;

	Intersection intersect;
	intersect.time = BIG;
	float start = 0;
	float final =  BIG;

	Light light;
	light.position = light_pos;

	if (Intersect(ray, start, final, intersect))
	{
		//float shadowing = Shadow(light_pos, intersect);
		//resultColor += vec4(Phong(intersect, light), 0);
		resultColor += vec4(1, 0, 0, 0);
	}
	return resultColor;
}

//--------Main------------------------------------------------------------------

void main (void)
{
	Ray ray = GenerateRay(camera);
	//FragColor = vec4 (abs(ray.direction.xy), 0, 1.0);
	FragColor = Raytrace(ray);
}