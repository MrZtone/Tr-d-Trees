#include "Component.h"

Component::Component(char sig) : signifier(sig) {}

char Component::getSignifier() {
    return signifier;
}