#pragma once
#include <string>
#include <typeinfo>

enum class SimpleType {
    INT,
    BOOLEAN,
    STRING,
    DOUBLE,
    VOID
};


class BaseObject {
public:
    BaseObject(SimpleType type, std::string name) :
        type_(type), name_(std::move(name)) {}


    SimpleType GetType() const {
        return type_;
    }

    const std::string& GetName() const {
        return name_;
    }

    virtual ~BaseObject() = default;

private:
    SimpleType type_;
    std::string name_;
};