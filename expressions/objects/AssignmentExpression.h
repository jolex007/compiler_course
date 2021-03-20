#pragma once

#include "expressions/Expression.h"

#include <string>

class AssignmentExpression : public Expression {
 public:
    AssignmentExpression(std::string  variable, Expression* expression, const location_type& loc);
    void Accept(Visitor* visitor) override;

    std::string variable_;
    Expression* expression_;
};
