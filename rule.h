#ifndef RULE_H
#define RULE_H

#include <string>
#include <vector>
#include <random>
#include "Component.h"

class rule {
    friend class LSystem;
    private:
    Component condition;
    std::vector<std::vector<Component>> replacements;
    std::discrete_distribution<int> distribution;

    std::random_device rd;
    std::mt19937 gen;

    public:
    rule(Component cond, std::vector<std::vector<Component>> rep, std::discrete_distribution<> dist);
    rule(rule && r);
    std::vector<Component> getReplacement(const Component& c);
};

 #endif