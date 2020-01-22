#version 460

layout(location = 0) in vec2 vert_position;
layout(location = 1) in vec2 vert_texcoord;
layout(location = 2) in vec4 vert_color;

out VertexData
{
	vec2 texcoord;
	vec4 color;
} vert;

uniform mat4 projMatrix;

void main()
{
	vert.texcoord = vert_texcoord;
	vert.color = vert_color;
	gl_Position = projMatrix * vec4(vert_position.xy, 1.0, 1.0);
}
