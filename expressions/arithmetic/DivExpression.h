#pragma once
#include "expressions/BinaryExpression.h"

class DivExpression: public BinaryExpression {
 public:
    DivExpression(Expression* lhs, Expression* rhs, const location_type& loc);
    void Accept(Visitor* visitor) override;
};
