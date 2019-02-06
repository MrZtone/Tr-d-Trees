#ifndef COMPONENT_H
#define COMPONENT_H

#include <stddef.h>

class Component {
    friend class LSystem;
    friend class rule;
    
    protected:
    char signifier;

    public:
    Component(char sig);
    char getSignifier();
    virtual bool equals(const Component& C) = 0;
    virtual bool isConstant() = 0;
    //updateParameter(pointer to function that is used to update parameter and condition components parameter); 
};

#endif