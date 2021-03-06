#ifndef MATRIXSTACK_H
#define MATRIXSTACK_H

#include<glm/glm.hpp>

struct Matrix {
    glm::mat4 matrix;
    Matrix *previous;
    Matrix(glm::mat4 m, Matrix* pre) : matrix(m), previous(pre){};
};

class MatrixStack {
    private:
    Matrix* M;
    public:
    void flush();
    MatrixStack();
    ~MatrixStack();
    glm::mat4 getMatrix();

    void push();
    void pop();

    void addTransformation(glm::mat4 m);
    void resetToPush();
};

#endif