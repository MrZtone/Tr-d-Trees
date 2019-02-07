#ifndef COMPONENT_H
#define COMPONENT_H

#include <stddef.h>
#include <glm/glm.hpp>

class Component {
    friend class LSystem;
    friend class rule;
    friend class Tree;
    
    protected:
    char signifier;
    glm::mat4 (*function)(double);
    double parameter;

    public:
    Component(char sig, glm::mat4 (*fun)(double) , double p);
    Component(const Component& c);
    Component(char sig);
    char getSignifier();
    bool equals(const Component& C);
    //updateParameter(pointer to function that is used to update parameter and condition components parameter); 
};

#endif