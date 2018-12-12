#version 330 core
layout (location = 0) in vec3 Position;
layout (location = 1) in vec3 Normal;
layout (location = 2) in vec3 texCoords;

uniform mat4 MV;

out vec3 ourColor; // specify a color output to the fragment shader

void main()
{
    gl_Position = MV * vec4(Position, 1.0);
    //vertexColor = vec4(0.5, 0.0, 0.0, 1.0);
    ourColor = vec3(0.4, 0.3, 0.8);
}