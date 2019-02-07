#include "Component.h"

Component::Component(char sig) : signifier(sig), function(nullptr) {}

Component::Component(char sig, glm::mat4 (*fun)(double) , double p =0.0) : signifier(sig), function(fun), parameter(p) {}

Component::Component(const Component& c) : signifier(c.signifier), function(c.function), parameter(c.parameter) {}

char Component::getSignifier() {
    return signifier;
}

bool Component::equals(const Component& C) {
    return signifier == C.signifier && function == C.function;
}