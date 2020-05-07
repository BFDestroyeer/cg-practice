#version 430

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

//--------Uniform values--------------------------------------------------------

uniform Camera camera;

uniform vec2 scale;

//--------Functions-------------------------------------------------------------

Ray GenerateRay (Camera camera)
{
	vec2 coords = interpolated_vertex.xy * normalize(scale);
	vec3 direction = camera.view + camera.side * coords.x + camera.up * coords.y;
	return Ray(camera.position, normalize(direction));
}

//--------Main------------------------------------------------------------------

void main (void)
{
	Ray ray = GenerateRay(camera);
	FragColor = vec4 (abs(ray.direction.xy), 0, 1.0);
}