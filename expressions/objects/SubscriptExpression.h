#pragma once
#include "expressions/Expression.h"
#include <string>

class SubscriptExpression : public Expression {
public:
    SubscriptExpression(Expression* exp_of, Expression* exp_indx, const location_type& loc);

    void Accept(Visitor* visitor) override;

    Expression* expression_of;
    Expression* expression_indx;
};
