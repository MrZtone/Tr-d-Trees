#include "Symbol.h"

Symbol::Symbol(char sig) : signifier(sig), function(nullptr) {}

Symbol::Symbol(char sig, glm::mat4 (*fun)(float) , float p =0.0f) : signifier(sig), function(fun), parameter(p) {}

Symbol::Symbol(const Symbol& c) : signifier(c.signifier), function(c.function), parameter(c.parameter) {}

char Symbol::getSignifier() {
    return signifier;
}

bool Symbol::equals(const Symbol& C) {
    return signifier == C.signifier && function == C.function;
}