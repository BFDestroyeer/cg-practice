#version 430

#define EPSILON 0.001
#define BIG 1000000.0

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

struct Material
{
	float ambient;
	float diffuse;
	float specular;
	float specular_power;
};

struct Intersection
{
	float time;
	vec3 point;
	vec3 normal;
	vec3 color;
	int material_idx;
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

struct Fleet
{
	float level;
	vec3 color;
};

//--------Buffers---------------------------------------------------------------

layout(std430, binding = 0) buffer SphereBuffer
{
	Sphere sphere_data[];
};

//--------Setup default values-------------------------------------------------

Material material = {0.1, 0.9, 0.0, 512.0};
vec3 light_pos = vec3(0, 1, -8);
Fleet fleet = { -5, {1.0, 1.0, 1.0} };
//--------Uniform values--------------------------------------------------------

uniform Camera camera;

uniform vec2 scale;

//--------Functions declaration-------------------------------------------------

//Ray generation function
Ray GenerateRay (Camera camera);

//Intersection functions
bool Intersect (Ray ray, float start, float final, inout Intersection intersect);
bool IntersectSphere (Sphere sphere, Ray ray, float start, float final, out float time);
bool IntersectFleet (Fleet fleet, Ray ray, float start, float final, out float time);

//Lighting and shadowing functions
vec3 Phong (Intersection interset, vec3 light_position, float shadow);
float Shadow (vec3 light_position, vec3 point);

//Main raytracing function
vec4 Raytrace (Ray primary_ray);

//--------Functions-------------------------------------------------------------

Ray GenerateRay (Camera camera)
{
	vec2 coords = interpolated_vertex.xy * normalize(scale);
	vec3 direction = camera.view + camera.side * coords.x + camera.up * coords.y;
	return Ray(camera.position, normalize(direction));
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
	if (IntersectFleet(fleet, ray, start, final, time) && time < intersect.time)
		{
			intersect.time = time;
			intersect.point = ray.origin + ray.direction * time;
			intersect.normal = vec3(0, 1, 0);
			intersect.color = fleet.color;
			intersect.material_idx = 0;
			result = true;
		}
	return result;
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

bool IntersectFleet (Fleet fleet, Ray ray, float start, float final, out float time)
{
	float t = (fleet.level - ray.origin.y) / ray.direction.y;
	if (t > 0)
	{
		time = t;
		return true;
	}
	return false;
}

vec3 Phong (Intersection intersect, vec3 light_position, float shadow)
{
	vec3 light = normalize (light_position - intersect.point);
	float diffuse = max(dot(light, intersect.normal), 0.0);
	vec3 view = normalize(camera.position - intersect.point);
	vec3 reflected = reflect(view, -intersect.normal);
	float specular = pow(max(dot(reflected, light), 0.0), material.specular_power);

	return material.ambient * intersect.color + shadow *
		(material.diffuse * diffuse * intersect.color + material.specular * specular * vec3(1, 1, 1));
}

float Shadow (vec3 light_position, vec3 point)
{
	float light = 1.0;

	vec3 direction = normalize(light_position - point);
	Ray shadow_ray = Ray(point + direction * EPSILON, direction);
	
	Intersection intersect;
	intersect.time = distance(light_position, point);
	
	if (Intersect(shadow_ray, 0, intersect.time, intersect))
	{
		light = 0.0;
	}
	return light;
}

vec4 Raytrace (Ray primary_ray)
{
	vec4 resultColor = vec4(0, 0 ,0 ,0);
	Ray ray = primary_ray;

	Intersection intersect;
	intersect.time = BIG;
	float start = 0;
	float final =  BIG;

	if (Intersect(ray, start, final, intersect))
	{
		float shadowing = Shadow(light_pos, intersect.point);
		resultColor += vec4(Phong(intersect, light_pos, shadowing), 0);
	}
	return resultColor;
}

//--------Main------------------------------------------------------------------

void main (void)
{
	Ray ray = GenerateRay(camera);
	FragColor = Raytrace(ray);
}