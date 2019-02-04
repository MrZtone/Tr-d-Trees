#ifndef LSYSTEM_H
#define LSYSTEM_H

#include "rule.h"

class LSystem {
    private:
    std::vector<Component*> axiom;
    void apply_rules();

    public:
    LSystem();
    ~LSystem();
    std::vector<rule> rules;

    void apply_rules(int counter);
    std::string getAxiom();

    //tree functions
    static void grow(double distance);
    static void split(double angle);
    static void rotate(double angle);
};

#endif //LSYSTEM_H