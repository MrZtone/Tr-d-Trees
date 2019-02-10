#ifndef TREE_H
#define TREE_H

#include "LSystem.h"
#include "Cylinder.h"
#include "Leaf.h"
#include "Cone.h"
#include "MatrixStack.h"

class Tree {

    private:
    LSystem L;
    Cylinder branch;
    Leaf leaf;
    Cone cone;

    public:
    Tree();
    void Draw(Shader shader, MatrixStack& MS);
};

#endif