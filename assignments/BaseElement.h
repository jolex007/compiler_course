#pragma once

#include <utility>

#include "visitors/visitor.h"
#include "parser.hh"

using location_type = yy::parser::location_type;

class BaseElement {
public:
    BaseElement() = default;
    BaseElement(const location_type& location, std::string  name) :
            location_(location),
            name_(std::move(name)) {}

    virtual void Accept(Visitor* visitor) = 0;

    const location_type& GetLocation() const {
        return location_;
    }

    const std::string& GetName() const {
        return name_;
    }

    virtual ~BaseElement() = default;

private:
    location_type location_;
    std::string name_;
};
