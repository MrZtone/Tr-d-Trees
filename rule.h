#ifndef RULE_H
#define RULE_H

#include <string>
#include <vector>
#include <random>
#include "Value.h"
#include "Constant.h"

class rule {
    friend class LSystem;
    private:
    Value condition;
    std::vector<std::vector<Component*>> replacements;
    std::discrete_distribution<int> distribution;

    std::random_device rd;
    std::mt19937 gen;

    public:
    rule(Value cond, std::vector<std::vector<Component*>> rep, std::discrete_distribution<> dist);
    rule(rule && r);
    ~rule();
    std::vector<Component*> getReplacement();
};

 #endif