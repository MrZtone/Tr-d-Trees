#ifndef RULE_H
#define RULE_H

#include <string>
#include <vector>
#include <random>

class rule {
    friend class LSystem;
    private:
    char condition;
    std::vector<std::string> replacements;
    std::discrete_distribution<int> distribution;

    std::random_device rd;
    std::mt19937 gen;

    public:
    rule(char cond, std::vector<std::string> rep, std::discrete_distribution<> dist);
    rule(rule && r);
    std::string getReplacement();
};

 #endif