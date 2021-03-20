#pragma once
#include "expressions/BinaryExpression.h"

class MulExpression: public BinaryExpression {
 public:
    MulExpression(Expression* lhs, Expression* rhs, const location_type& loc);
    void Accept(Visitor* visitor) override;
};
