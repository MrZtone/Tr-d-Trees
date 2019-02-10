#ifndef LSYSTEM_H
#define LSYSTEM_H
#define GLM_ENABLE_EXPERIMENTAL

#include "rule.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

class LSystem {

    private:
    std::vector<Symbol> axiom;
    std::vector<rule> rules;

    void apply_rules();

    public:
    LSystem();
    void apply_rules(int counter); // apply rules multiple times
    std::string getAxiom();

    //tree functions
    static glm::mat4 grow(float distance);
    static glm::mat4 split(float angle);
    static glm::mat4 rotate(float angle);

    friend class Tree;
};

#endif //LSYSTEM_H