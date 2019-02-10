#include "rule.h"
#include <iostream>

rule::rule(Symbol cond, std::vector<std::vector<Symbol>> rep, std::discrete_distribution<> dist) :
    condition(cond),
    replacements(rep),
    distribution(dist),
    gen(rd()){}


rule::rule(rule && r) :condition(r.condition), replacements(std::move(r.replacements)), gen(std::move(r.gen)), distribution(std::move(r.distribution)) {
}

std::vector<Symbol> rule::getReplacement(const Symbol& c) {
    int index = distribution(gen);
    std::vector<Symbol> rep;
    std::vector<Symbol>::iterator it = replacements[index].begin();
    while(it != replacements[index].end())
    {
        Symbol temp = (*it);
        if(temp.signifier == 'R')
            temp.parameter= c.parameter + 137.5;
        rep.push_back(temp);
        it++;
    }
    return rep;
}