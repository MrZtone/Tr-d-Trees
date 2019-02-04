#ifndef VALUE_H
#define VALUE_H

#include "Component.h"

class Value : public Component
{
    friend class LSystem;
    
private:
    void (*function)(double);
    double parameter;
public:
    Value(char sig, void (*fun)(double) , double p);
    Value(const Value& v);
    bool isConstant();
    bool equals(const Component& C);
};

#endif