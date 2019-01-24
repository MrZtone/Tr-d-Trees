#ifndef LSYSTEM_H
#define LSYSTEM_H

#include "rule.h"

class LSystem {
    private:
    std::string axiom;
    void apply_rules();

    public:
    LSystem(std::string ax ="A");
    std::vector<rule> rules;

    void apply_rules(int counter);
    std::string getAxiom();
};

#endif //LSYSTEM_H