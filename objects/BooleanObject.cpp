#include "BooleanObject.h"

BooleanObject::BooleanObject() :
    BaseObject(SimpleType::BOOLEAN,
            "BooleanObject") {}

BooleanObject::BooleanObject(bool value) :
    BaseObject(SimpleType::BOOLEAN,
            "BooleanObject"),
            value(value) {}

bool BooleanObject::GetValue() const {
    return value;
}