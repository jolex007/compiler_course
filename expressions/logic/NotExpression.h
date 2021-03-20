#pragma once
#include "expressions/UnaryExpression.h"

class NotExpression: public UnaryExpression {
public:
    NotExpression(Expression* exp, const location_type& loc);
    void Accept(Visitor* visitor) override;
};
