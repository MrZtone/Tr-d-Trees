#version 330 core
layout (location = 0) in vec3 Position;
layout (location = 1) in vec3 Normal;
layout (location = 2) in vec3 texCoords;

uniform mat4 MV;
uniform mat4 PER;

out vec3 outNormal; // specify a color output to the fragment shader

void main()
{
    gl_Position = (PER * MV) * vec4(Position, 1.0f);
    outNormal = mat3(MV) * Normal;
}