#ifndef LSYSTEM_H
#define LSYSTEM_H
#define GLM_ENABLE_EXPERIMENTAL

#include "rule.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

class LSystem {
    friend class Tree;
    private:
    std::vector<Component> axiom;
    void apply_rules();

    public:
    LSystem();
    std::vector<rule> rules;

    void apply_rules(int counter);
    std::string getAxiom();

    //tree functions
    static glm::mat4 grow(double distance);
    static glm::mat4 split(double angle);
    static glm::mat4 rotate(double angle);
};

#endif //LSYSTEM_H