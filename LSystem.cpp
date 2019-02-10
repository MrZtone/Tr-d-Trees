#include "LSystem.h"
#include <iostream>

glm::mat4 LSystem::grow( float distance ) {
    glm::mat4 bleh = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, distance, 0.0f));
    glm::mat4 bleh2 = glm::scale(glm::mat4(1.0f), glm::vec3(0.92f, 1.0f, 0.92f));
    return bleh*bleh2;
}

glm::mat4 LSystem::split(float angle) {
    return glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 0.0f, -1.0f));
}

glm::mat4 LSystem::rotate(float angle) {
    return glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 1.0f, 0.0f));
}

LSystem::LSystem() {
    axiom.reserve(20000); //Reserving for 200 elements in axiom, Explicit size reserving is needed to prevent iterator invalidation
    axiom.push_back(Symbol('X'));
    std::vector<Symbol> BAB, C1, C2, C3, A;
    
    BAB.push_back(Symbol('G', (LSystem::grow), 0.5));
    BAB.push_back(Symbol('['));
    BAB.push_back(Symbol('S', (LSystem::split), 45.0));
    BAB.push_back(Symbol('R', (LSystem::rotate), 137.5));
    BAB.push_back(Symbol('G', (LSystem::grow), 0.2));
    BAB.push_back(Symbol(']'));
    BAB.push_back(Symbol('X'));
    
    C1.push_back(Symbol('G', (LSystem::grow), 0.2));
    C1.push_back(Symbol('R', (LSystem::rotate), 137.5));
    C1.push_back(Symbol('['));
    C1.push_back(Symbol('S', (LSystem::split), -45.0));
    C1.push_back(Symbol('R', (LSystem::rotate), -137.5));
    C1.push_back(Symbol('G', (LSystem::grow), 0.2));
    C1.push_back(Symbol('X'));
    C1.push_back(Symbol(']'));
    C1.push_back(Symbol('['));
    C1.push_back(Symbol('S', (LSystem::split), -45.0));
    C1.push_back(Symbol('R', (LSystem::rotate), -137.5));
    C1.push_back(Symbol('G', (LSystem::grow), 0.2));
    C1.push_back(Symbol(']'));
    C1.push_back(Symbol('G', (LSystem::grow), 0.2));

    C2.push_back(Symbol('G', (LSystem::grow), 0.2));
    C2.push_back(Symbol('R', (LSystem::rotate), 137.5));
    C2.push_back(Symbol('['));
    C2.push_back(Symbol('S', (LSystem::split), 45.0));
    C1.push_back(Symbol('R', (LSystem::rotate), 137.5));
    C2.push_back(Symbol('G', (LSystem::grow), 0.2));
    C2.push_back(Symbol('X'));
    C2.push_back(Symbol(']'));
    C2.push_back(Symbol('G', (LSystem::grow), 0.2));

    C3.push_back(Symbol('G', (LSystem::grow), 0.3));
    C3.push_back(Symbol('['));
    C3.push_back(Symbol('X'));
    C3.push_back(Symbol(']'));

    A.push_back(Symbol('R', (LSystem::rotate), 137.5));

    std::vector<std::vector<Symbol>> replacement1{BAB};
    std::discrete_distribution<int> distribution1 {1};
    std::vector<std::vector<Symbol>> replacement2{C1, C2, C3};
    std::discrete_distribution<int> distribution2 {3,3,1};
    std::vector<std::vector<Symbol>> replacement3{A};

    rules.push_back(rule(Symbol('X'),replacement1, distribution1));
    rules.push_back(rule(Symbol('G', (LSystem::grow), 2.0),replacement2, distribution2));
    rules.push_back(rule(Symbol('R', (LSystem::rotate), 137.5),replacement3, distribution1));
    std::cout << "Constructor done" << std::endl;
}

void LSystem::apply_rules() {
    std::vector<Symbol>::iterator it =  axiom.begin(), next;
    
    while(it != axiom.end()) { //go through values in axiom
        next = it + 1;
        //go through, check and apply rules to axiom value
        for(std::vector<rule>::iterator rule = rules.begin(); rule != rules.end(); rule++) {
            if((*it).equals((*rule).condition)) {
                std::vector<Symbol> replacement = (*rule).getReplacement((*it));
                axiom.insert(it+1,replacement.begin(), replacement.end());
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
    std::vector<Symbol>::iterator it =  axiom.begin();
    for ( ; it != axiom.end(); it++) {
        returnString += (*it).signifier;
    }
    return returnString;
}