#pragma once
#include "assignments/BaseElement.h"

class Expression : public BaseElement {
public:
    Expression(const location_type& loc, const std::string& name) : BaseElement(loc, name) {};
    virtual ~Expression() = default;
};

