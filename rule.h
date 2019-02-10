#ifndef RULE_H
#define RULE_H

#include <string>
#include <vector>
#include <random>
#include "Symbol.h"

class rule {
    friend class LSystem;
    private:
    Symbol condition;
    std::vector<std::vector<Symbol>> replacements;
    std::discrete_distribution<int> distribution;

    std::random_device rd;
    std::mt19937 gen;

    public:
    rule(Symbol cond, std::vector<std::vector<Symbol>> rep, std::discrete_distribution<> dist);
    rule(rule && r);
    std::vector<Symbol> getReplacement(const Symbol& c);
};

 #endif