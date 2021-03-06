#ifdef VERTEX

layout(location = 0) in vec3 position;
layout(location = 1) in vec4 color;

out VertexData
{
	vec4 color;
} vert;

uniform mat4 viewProj;

void main()
{
	vert.color = color;
	gl_Position = viewProj * vec4(position, 1.0);
}

#endif

#ifdef FRAGMENT

in VertexData
{
	vec4 color;
} vert;

out vec4 fragColor;

void main()
{
    fragColor = vert.color;
}

#endif
