#ifndef VALUE_H
#define VALUE_H

#include "Component.h"
#include <glm/glm.hpp>

class Value : public Component
{
    friend class LSystem;
    friend class Tree;
    
private:
    glm::mat4 (*function)(double);
    double parameter;
public:
    Value(char sig, glm::mat4 (*fun)(double) , double p);
    Value(const Value& v);
    bool isConstant();
    bool equals(const Component& C);
    void setParameter(double p);
};

#endif