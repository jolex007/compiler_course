#pragma once
#include "expressions/Expression.h"

enum class PrefixOperator{
    PRMINUS,
    NOT
};

class UnaryExpression: public Expression {
public:
    UnaryExpression(Expression *exp, PrefixOperator sign, const location_type &loc);
    void Accept(Visitor* visitor) override;
    ~UnaryExpression() override = default;

public:
    Expression* exp;
    PrefixOperator operator_;
};
