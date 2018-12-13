#include "Mesh.h"
class Cylinder :public Mesh
{
    public:
    static const int NumberOfSegment = 20;
    Cylinder(float h, float r);

    private:
    float height, radius;


};