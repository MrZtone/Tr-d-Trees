#ifndef VERTEX_H
#define VERTEX_H

#include <glm/glm.hpp>

class Vertex {
    public:
    
    Vertex();
    Vertex(glm::vec3 p, glm::vec3 n);

    private:
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
    friend class Mesh;
};

#endif