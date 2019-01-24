#include "LSystem.h"
#include <iostream>

LSystem::LSystem(std::string ax) {
    axiom=ax;
    //If axiom value equals condition replace with replacement
    std::discrete_distribution<int> distribution {1,1,1};
    std::vector<std::string> replacement1{"BAB", "BAB", "BAB"};
    std::vector<std::string> replacement2{"C", "D", "E"}; 
    rules.push_back(rule('A',replacement1, distribution));
    rules.push_back(rule('B',replacement2, distribution));
}

void LSystem::apply_rules() {
    std::string tempAxiom= "";
    std::string::iterator it =  axiom.begin(), next;
    
    
    while(it != axiom.end()) { //go through values in axiom
        next = it + 1;
        //go through, check and apply rules to axiom value
        for(std::vector<rule>::iterator rule = rules.begin(); rule != rules.end(); rule++) {
            if((*it) == (*rule).condition) {
                std::string replacement = (*rule).getReplacement();
                axiom.replace(it, it+1, replacement);
                next = it + replacement.size();
                break;
            }
        }
        it = next;
    }
}

void LSystem::apply_rules(int counter) {
    for(int i = 0; i <counter; i++) {
        apply_rules();
    }
}

std::string LSystem::getAxiom() {
    return axiom;
}