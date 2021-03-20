#pragma once
#include "expressions/UnaryExpression.h"

class UnaryMinusExpression: public UnaryExpression {
public:
    UnaryMinusExpression(Expression* exp, const location_type& loc);
    void Accept(Visitor* visitor) override;
};
