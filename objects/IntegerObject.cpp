#include "IntegerObject.h"

IntegerObject::IntegerObject() :
    BaseObject(SimpleType::INT,
            "IntegerObject") {}

IntegerObject::IntegerObject(int value) :
    BaseObject(SimpleType::INT,
                "IntegerObject"),
                value(value) {}

int IntegerObject::GetValue() const {
    return value;
}

