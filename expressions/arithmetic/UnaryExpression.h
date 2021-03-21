#pragma once
#include "expressions/Expression.h"

enum PrefixOperator{
    PRMINUS,
    NOT
};

class UnaryExpression: public Expression {
public:
    UnaryExpression(Expression *exp, const std::string& sign, const location_type &loc);
    void Accept(Visitor* visitor) override;
    ~UnaryExpression() override = default;

public:
    Expression* exp;
    PrefixOperator operator_;
};
