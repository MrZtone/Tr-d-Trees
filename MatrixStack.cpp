#include "MatrixStack.h"

MatrixStack::MatrixStack()
{
    M = new Matrix{glm::mat4(1.0f), nullptr};
}

MatrixStack::~MatrixStack()
{
    flush();
    delete M;
}

void MatrixStack::flush()
{
    while(M->previous !=nullptr)
        pop();
}

void MatrixStack::push(glm::mat4 m)
{
    Matrix* temp = M;
    M = new Matrix{M->matrix*m, temp};
}

void MatrixStack::pop()
{
    if(M->previous !=nullptr)
    {
        Matrix* temp = M;
        M= M-> previous;
        delete temp;
    }
}

glm::mat4 MatrixStack::getMatrix()
{
    return M->matrix;
}