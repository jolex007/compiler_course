#pragma once
#include "expressions/BinaryExpression.h"

class OrExpression: public BinaryExpression {
public:
    OrExpression(Expression* lhs, Expression* rhs, const location_type& loc);
    void Accept(Visitor* visitor) override;
};
