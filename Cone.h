#include "Mesh.h"
#include <glm/gtc/matrix_transform.hpp>

class Cone :public Mesh
{
    public:
    static const int NumberOfSegment = 20;
    Cone(float h, float r);

    private:
    float height, radius;


};