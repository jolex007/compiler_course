#pragma once

#include "expressions/Expression.h"
#include "BaseElement.h"
#include <string>

class Assignment : public BaseElement {
public:
    Assignment(const std::string& variable, Expression* expression, const location_type &loc);
    void Accept(Visitor* visitor) override;

    std::string variable_;
    Expression* expression_;
};
