#include "Mesh.h"
class Cylinder :public Mesh
{
    public:
    static const int NumberOfSegment = 20;
    //rgb(243, 104, 224)
    Cylinder(float h, float r, glm::vec3 col=glm::vec3(0.95f, 0.41f, 0.88f));

    private:
    float height, radius;


};