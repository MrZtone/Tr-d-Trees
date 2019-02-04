#ifndef CONSTANT_H
#define CONSTANT_H

#include "Component.h"

class Constant : public Component
{    
public:
    Constant(char sig);
    Constant(const Constant & c);
    bool equals(const Component& C);
    bool isConstant();
};

#endif