#include "LSystem.h"
#include <iostream>

void LSystem::grow( double distance ) {
    std::cout << "Grow" << std::endl;
}

void LSystem::split(double angle) {
    std::cout << "Split" << std::endl;
}

void LSystem::rotate(double angle) {
    std::cout << "Rotate" << std::endl;
}

LSystem::LSystem() {
    axiom.reserve(200); //Reserving for 200 elements in axiom, Explicit size reserving is needed to prevent iterator invalidation
    axiom.push_back(new Value('A', (LSystem::split), 2.0));
    std::vector<Component*> BAB, C1, C2, C3;
    BAB.push_back(new Value('B', (LSystem::grow), 2.0));
    BAB.push_back(new Value('A', (LSystem::split), 2.0));
    BAB.push_back(new Value('B', (LSystem::grow), 2.0));

    C1.push_back(new Constant('C'));
    C2.push_back(new Constant('C'));
    C3.push_back(new Constant('C'));

    std::vector<std::vector<Component*>> replacement1{BAB, BAB, BAB};
    std::vector<std::vector<Component*>> replacement2{C1, C2, C3};
    std::discrete_distribution<int> distribution {1,1,1};

    rules.push_back(rule(Value('A', (this->split), 2.0),replacement1, distribution));
    rules.push_back(rule(Value('B', (this->grow), 2.0),replacement2, distribution));
    std::cout << "Constructor done" << std::endl;
}

LSystem::~LSystem() {
    std::vector<Component*>::iterator it = axiom.begin();
    while(it != axiom.end()) {
        delete (*it);
        it++;
    }
}

void LSystem::apply_rules() {
    std::vector<Component*>::iterator it =  axiom.begin(), next;
    
    while(it != axiom.end()) { //go through values in axiom
        next = it + 1;
        //go through, check and apply rules to axiom value
        for(std::vector<rule>::iterator rule = rules.begin(); rule != rules.end(); rule++) {
            if((*it)->equals((*rule).condition)) {
                std::vector<Component*> replacement = (*rule).getReplacement();
                axiom.insert(it+1,replacement.begin(), replacement.end());
                delete (*it);
                axiom.erase(it);
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
        std::cout << "applied rules once" << std::endl;
    }
}

std::string LSystem::getAxiom() {
    std::string returnString = "";
    std::vector<Component*>::iterator it =  axiom.begin();
    for ( ; it != axiom.end(); it++) {
        returnString += (*it)->signifier;
        if(!(*it)->isConstant()) {
            Value* temp = static_cast<Value*>(*it);
            (temp->function)(temp->parameter);
        }
    }
    return returnString;
}