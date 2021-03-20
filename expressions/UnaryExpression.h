#pragma once
#include "expressions/Expression.h"

class UnaryExpression: public Expression {
public:
    UnaryExpression(Expression* exp, const location_type& loc, const std::string& name) :
            Expression(loc, name),
            exp(exp) {};
    Expression* exp;
};
