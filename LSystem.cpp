#include "LSystem.h"
#include <iostream>

//TODO Change from double to float
glm::mat4 LSystem::grow( double distance ) {
    //return glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, (float)distance, 0.0f));
    glm::mat4 bleh = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, (float)distance, 0.0f));
    glm::mat4 bleh2 = glm::scale(glm::mat4(1.0f), glm::vec3(0.92f, 1.0f, 0.92f));
    return bleh*bleh2;
}

glm::mat4 LSystem::split(double angle) {
    return glm::rotate(glm::mat4(1.0f), (float)angle, glm::vec3(0.0f, 0.0f, -1.0f));
}

glm::mat4 LSystem::rotate(double angle) {
    return glm::rotate(glm::mat4(1.0f), (float)angle, glm::vec3(0.0f, 1.0f, 0.0f));
}

LSystem::LSystem() {
    axiom.reserve(5000); //Reserving for 200 elements in axiom, Explicit size reserving is needed to prevent iterator invalidation
    axiom.push_back(new Value('X', (nullptr), 2.0));
    std::vector<Component*> BAB, C1, C2, C3;
    BAB.push_back(new Value('F', (LSystem::grow), 0.2));
    BAB.push_back(new Value('+', (LSystem::split), 45.0));
    BAB.push_back(new Value('P', (LSystem::rotate), 45.0));
    BAB.push_back(new Constant('['));
    BAB.push_back(new Constant('['));
    BAB.push_back(new Value('X', (nullptr), 2.0));
    BAB.push_back(new Constant(']'));
    BAB.push_back(new Value('-', (LSystem::split), -45.0));
    BAB.push_back(new Value('M', (LSystem::rotate), -45.0));
    BAB.push_back(new Value('X', (nullptr), 2.0));
    BAB.push_back(new Constant(']'));
    BAB.push_back(new Value('-', (LSystem::split), -45.0));
    BAB.push_back(new Value('M', (LSystem::rotate), -45.0));
    BAB.push_back(new Value('F', (LSystem::grow), 0.2));
    BAB.push_back(new Constant('['));
    BAB.push_back(new Value('-', (LSystem::split), -45.0));
    BAB.push_back(new Value('M', (LSystem::rotate), -45.0));
    BAB.push_back(new Value('F', (LSystem::grow), 0.2));
    BAB.push_back(new Value('X', (nullptr), 2.0));
    BAB.push_back(new Constant(']'));
    BAB.push_back(new Value('+', (LSystem::split), 45.0));
    BAB.push_back(new Value('P', (LSystem::rotate), 45.0));
    BAB.push_back(new Value('X', (nullptr), 2.0));

    C1.push_back(new Value('F', (LSystem::grow), 0.2));
    C1.push_back(new Value('F', (LSystem::grow), 0.2));
    C2.push_back(new Value('F', (LSystem::grow), 0.2));
    C2.push_back(new Value('F', (LSystem::grow), 0.2));
    C3.push_back(new Value('F', (LSystem::grow), 0.2));
    C3.push_back(new Value('F', (LSystem::grow), 0.2));

    std::vector<std::vector<Component*>> replacement1{BAB, BAB, BAB};
    std::vector<std::vector<Component*>> replacement2{C1, C2, C3};
    std::discrete_distribution<int> distribution {1,1,1};

    rules.push_back(rule(Value('X', (nullptr), 2.0),replacement1, distribution));
    rules.push_back(rule(Value('F', (LSystem::grow), 2.0),replacement2, distribution));
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
            if(temp->function != nullptr)
                (temp->function)(temp->parameter);
        }
    }
    return returnString;
}