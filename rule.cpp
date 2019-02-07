#include "rule.h"
#include <iostream>

rule::rule(Value cond, std::vector<std::vector<Component*>> rep, std::discrete_distribution<> dist) :
    condition(cond),
    replacements(rep),
    distribution(dist),
    gen(rd()){}


rule::rule(rule && r) :condition(std::move(r.condition)), replacements(std::move(r.replacements)), gen(std::move(r.gen)), distribution(std::move(r.distribution)) {
}

rule::~rule() {
    std::vector<std::vector<Component*>>::iterator outIt = replacements.begin();
    while (outIt != replacements.end())  {
        std::vector<Component*>::iterator inIt = (*outIt).begin();
        while(inIt != (*outIt).end()) {
            //Will crash if same pointer is used multiple times in replacements
            delete (*inIt);
            inIt++;
        }
        (*outIt).clear();
        outIt++;
    }
    replacements.clear();
}

std::vector<Component*> rule::getReplacement() {
    int index = distribution(gen);
    std::vector<Component*> rep;
    std::vector<Component*>::iterator it = replacements[index].begin();
    while(it != replacements[index].end())
    {
        if((*it)->isConstant()) {
            rep.push_back(new Constant(*(static_cast<Constant*>(*it))));
        }
        else {
            Value* temp = new Value(*(static_cast<Value*>(*it)));
            if(temp->signifier == 'P' || temp->signifier == 'M')
                temp->setParameter(222.0);
            rep.push_back(temp);
        }
        it++;
    }
    return rep;
}