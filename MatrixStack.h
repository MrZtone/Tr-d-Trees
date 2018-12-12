#ifndef MATRIXSTACK_H
#define MATRIXSTACK_H

#include<glm/glm.hpp>

struct Matrix {
    glm::mat4 matrix;
    Matrix *previous;
};

class MatrixStack {
    private:
    Matrix* M;
    public:
    void flush();
    MatrixStack();
    ~MatrixStack();
    glm::mat4 getMatrix();

    void push(glm::mat4 m);
    void pop();
};

#endif