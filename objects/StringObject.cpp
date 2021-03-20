#include "StringObject.h"

#include <utility>

StringObject::StringObject() :
    BaseObject(SimpleType::STRING,
            "StringObject") {}

StringObject::StringObject(std::string value) :
    BaseObject(SimpleType::STRING,
            "StringObject"),
            value(std::move(value)) {}

const std::string& StringObject::GetValue() const {
    return value;
}
