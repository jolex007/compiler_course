#pragma once
#include "expressions/BinaryExpression.h"

class SubtractExpression: public BinaryExpression {
 public:
    SubtractExpression(Expression* lhs, Expression* rhs, const location_type &loc);
    void Accept(Visitor* visitor) override;
};

