#include "Cone.h"

Cone::Cone(float h, float r)
{
    height = h;
    radius = r;
    float angleIncrement = 2*M_PI/((float) NumberOfSegment);
    float angle = angleIncrement;
    float segmentStart = 0.0;
    float segmentEnd = angle;

    glm::vec3 brown(1.0f, 0.5f, 0.5f);

    glm::vec3 centerBottom(0.0, 0.0, 0.0);
    glm::vec3 centerTop(0.0, height, 0.0);

    vertices.push_back(Vertex(centerBottom, glm::vec3(0.0f, -1.0f, 0.0f), brown)); // 0
    vertices.push_back(Vertex(centerTop, glm::vec3(0.0f, 1.0f, 0.0f), brown)); // 1

    //Botom
    vertices.push_back(Vertex(glm::vec3(radius, 0.0, 0.0), glm::vec3(1.0, 0.0, 0.0), brown)); // 2 + 0*3 + 0 = 2
    vertices.push_back(Vertex(glm::vec3(radius, 0.0, 0.0), glm::vec3(0.0, -1.0, 0.0), brown)); // 2 + 0*3 + 1 = 3
    //Top
    vertices.push_back(Vertex(centerTop, glm::vec3(1.0, 0.0, 0.0), brown)); // 2 + 0*3 + 2 = 4
    //vertices.push_back(Vertex(glm::vec3(radius, height, 0.0), glm::vec3(0.0, 1.0, 0.0), brown)); // 2 + 0*4 + 3 = 5


    for(int i = 1; i <= NumberOfSegment; ++i)
    {
        glm::vec2 start(radius*cosf(segmentStart), radius*sinf(segmentStart));
        glm::vec2 end(radius*cosf(segmentEnd), radius*sinf(segmentEnd));

        if (i < NumberOfSegment)
        {
            glm::vec3 cotangent(cosf(angle+M_PI/2.0), 0.0, sinf(angle+ M_PI/2.0));
            float coneAngle = tanf(radius/height);
            glm::mat3 rotate = glm::rotate(glm::mat4(1.0f), coneAngle, cotangent);
            //Botom Vertices
            vertices.push_back(Vertex(glm::vec3(radius*cosf(angle), 0.0, radius*sinf(angle)), rotate*glm::vec3(cosf(angle), 0.0, sinf(angle)), brown)); // 2 + 0*0 + 0
            vertices.push_back(Vertex(glm::vec3(radius*cosf(angle), 0.0, radius*sinf(angle)), glm::vec3(0.0, -1.0, 0.0), brown)); // 2 + 0*0 + 1
            //Top Vertices
            vertices.push_back(Vertex(centerTop, rotate*glm::vec3(cosf(angle), 0.0, sinf(angle)), brown)); // 2 + 0*0 + 2
            //vertices.push_back(Vertex(glm::vec3(radius*cosf(angle), height, radius*sinf(angle)), glm::vec3(0.0, 1.0, 0.0), brown)); // 2 + 0*0 + 3
        }

        int index = i%NumberOfSegment;
        
        //Bottom
        indices.push_back(0);
        indices.push_back(2 + (i-1)*3 + 1);
        indices.push_back(2 + index*3 + 1);

        //Side 1
        indices.push_back(2 + (i-1)*3 + 2);
        indices.push_back(2 + index*3 + 0);
        indices.push_back(2 + (i-1)*3 + 0);

        angle+=angleIncrement;
    }
    setupMesh();
}