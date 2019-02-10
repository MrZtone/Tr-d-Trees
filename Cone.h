#include "Mesh.h"
#include <glm/gtc/matrix_transform.hpp>

class Cone :public Mesh
{
    public:
    static const int NumberOfSegment = 20;
    Cone(float h, float r, glm::vec3 col=glm::vec3(0.95f, 0.41f, 0.88f));

    private:
    float height, radius;


};