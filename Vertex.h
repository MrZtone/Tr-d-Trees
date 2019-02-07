#ifndef VERTEX_H
#define VERTEX_H

#include <glm/glm.hpp>

class Vertex {
    public:
    
    Vertex();
    Vertex(glm::vec3 p, glm::vec3 n, glm::vec3 c);

    private:
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec3 Color;
    friend class Mesh;
};

#endif