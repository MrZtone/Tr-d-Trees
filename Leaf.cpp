#include "Leaf.h"

Leaf::Leaf(float h) {
    height = h;
    glm::vec3 green(0.0f, 1.0f, 1.0f);
    vertices.push_back(Vertex(glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0), green));
    vertices.push_back(Vertex(glm::vec3(-0.3*height, 0.3*height, 0.0), glm::vec3(0.0, 0.0, 1.0), green));
    vertices.push_back(Vertex(glm::vec3(0.3*height, 0.3*height, 0.0), glm::vec3(0.0, 0.0, 1.0), green));
    vertices.push_back(Vertex(glm::vec3(0.0, height, 0.0), glm::vec3(0.0, 0.0, 1.0), green));

    vertices.push_back(Vertex(glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, -1.0), green));
    vertices.push_back(Vertex(glm::vec3(-0.3*height, 0.3*height, 0.0), glm::vec3(0.0, 0.0, -1.0), green));
    vertices.push_back(Vertex(glm::vec3(0.3*height, 0.3*height, 0.0), glm::vec3(0.0, 0.0, -1.0), green));
    vertices.push_back(Vertex(glm::vec3(0.0, height, 0.0), glm::vec3(0.0, 0.0, -1.0), green));

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