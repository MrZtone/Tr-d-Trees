#include "Vertex.h"

Vertex::Vertex(glm::vec3 p, glm::vec3 n, glm::vec3 c)
{
    this->Position = p;
    this->Normal = n;
    this->Color = c;
}