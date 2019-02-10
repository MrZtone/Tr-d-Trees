#include "Mesh.h"
class Leaf :public Mesh
{
    public:
    Leaf(float h, glm::vec3 col=glm::vec3(0.95f, 0.41f, 0.88f));

    private:
    float height;
};