#include "Leaf.h"

Leaf::Leaf(float h, glm::vec3 col) {
    height = h;
    
    vertices.push_back(Vertex(glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0), col));
    vertices.push_back(Vertex(glm::vec3(-0.3*height, 0.3*height, 0.0), glm::vec3(0.0, 0.0, 1.0), col));
    vertices.push_back(Vertex(glm::vec3(0.3*height, 0.3*height, 0.0), glm::vec3(0.0, 0.0, 1.0), col));
    vertices.push_back(Vertex(glm::vec3(0.0, height, 0.0), glm::vec3(0.0, 0.0, 1.0), col));

    vertices.push_back(Vertex(glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, -1.0), col));
    vertices.push_back(Vertex(glm::vec3(-0.3*height, 0.3*height, 0.0), glm::vec3(0.0, 0.0, -1.0), col));
    vertices.push_back(Vertex(glm::vec3(0.3*height, 0.3*height, 0.0), glm::vec3(0.0, 0.0, -1.0), col));
    vertices.push_back(Vertex(glm::vec3(0.0, height, 0.0), glm::vec3(0.0, 0.0, -1.0), col));

    indices.push_back(0);
    indices.push_back(3);
    indices.push_back(1);

    indices.push_back(3);
    indices.push_back(0);
    indices.push_back(2);

    indices.push_back(5);
    indices.push_back(7);
    indices.push_back(4);

    indices.push_back(6);
    indices.push_back(4);
    indices.push_back(7);

    setupMesh();
}