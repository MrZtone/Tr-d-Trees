#ifndef SYMBOL_H
#define SYMBOL_H

#include <stddef.h>
#include <glm/glm.hpp>

class Symbol {
    
    private:
    char signifier;
    glm::mat4 (*function)(float);
    float parameter;

    public:
    Symbol(char sig, glm::mat4 (*fun)(float) , float p);
    Symbol(const Symbol& c);
    Symbol(char sig);
    char getSignifier();
    bool equals(const Symbol& C);

    friend class LSystem;
    friend class rule;
    friend class Tree;
};

#endif