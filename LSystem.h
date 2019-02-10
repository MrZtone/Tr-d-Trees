#ifndef LSYSTEM_H
#define LSYSTEM_H
#define GLM_ENABLE_EXPERIMENTAL

#include "rule.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

class LSystem {
    friend class Tree;
    private:
    std::vector<Symbol> axiom;
    void apply_rules();

    public:
    LSystem();
    std::vector<rule> rules;

    void apply_rules(int counter);
    std::string getAxiom();

    //tree functions
    static glm::mat4 grow(float distance);
    static glm::mat4 split(float angle);
    static glm::mat4 rotate(float angle);
};

#endif //LSYSTEM_H