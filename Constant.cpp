#include "Constant.h"

Constant::Constant(char sig) : Component(sig) {}

Constant::Constant(const Constant & c): Component(c.signifier) {}

bool Constant::isConstant() {return true;}

bool Constant::equals(const Component& C) {
    const Constant* b = dynamic_cast< const Constant* >( &C );
    return b != NULL && signifier == b->signifier;
}