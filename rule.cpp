#include "rule.h"
#include <iostream>

rule::rule(char cond, std::vector<std::string> rep, std::discrete_distribution<> dist) {
    condition=cond;
    replacements= rep;
    distribution=dist;
    gen = std::mt19937(rd());
}

rule::rule(rule && r) :condition(std::move(r.condition)), replacements(std::move(r.replacements)), gen(std::move(r.gen)), distribution(std::move(r.distribution)) {
}

std::string rule::getReplacement() {
    int index = distribution(gen);
    return replacements[index];
}