#ifndef MESH_H
#define MESH_H

#include <vector>
#include"Shader.h"
#include"Vertex.h"

#ifndef M_PI
#define M_PI (3.141592653589793)
#endif


class Mesh {
    public:
        /*  Mesh Data  */
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        //vector<Texture> textures;
        /*  Functions  */
        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);//), vector<Texture> textures);
        void Draw(Shader shader);
    private:
        /*  Render data  */
        unsigned int VAO, VBO, EBO;
        /*  Functions    */
        void setupMesh();
};  


#endif //MESH_H