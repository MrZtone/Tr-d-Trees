#include "Value.h"

Value::Value(char sig, void (*fun)(double) , double p) : Component(sig), function(fun), parameter(p) {}

bool Value::isConstant(){return false;}

Value::Value(const Value& v) : Component(v.signifier), function(v.function), parameter(v.parameter) {}

bool Value::equals(const Component& C) {
    const Value* b = dynamic_cast< const Value* >( &C );
    return b != NULL && function == b->function;
}