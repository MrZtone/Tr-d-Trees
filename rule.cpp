#include "rule.h"
#include <iostream>

rule::rule(Component cond, std::vector<std::vector<Component>> rep, std::discrete_distribution<> dist) :
    condition(cond),
    replacements(rep),
    distribution(dist),
    gen(rd()){}


rule::rule(rule && r) :condition(r.condition), replacements(std::move(r.replacements)), gen(std::move(r.gen)), distribution(std::move(r.distribution)) {
}

std::vector<Component> rule::getReplacement(const Component& c) {
    int index = distribution(gen);
    std::vector<Component> rep;
    std::vector<Component>::iterator it = replacements[index].begin();
    while(it != replacements[index].end())
    {
        Component* temp = new Component((*it));
        if(temp->signifier == 'M' && temp->signifier == 'P')
            temp->parameter= c.parameter + 222;
        rep.push_back(*temp);
        it++;
    }
    return rep;
}