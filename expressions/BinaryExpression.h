#pragma once
#include "expressions/Expression.h"

class BinaryExpression: public Expression {
public:
    BinaryExpression(Expression* lhs, Expression* rhs, const location_type& loc, const std::string& name) :
            Expression(loc, name),
            lhs(lhs),
            rhs(rhs) {};
    Expression* lhs;
    Expression* rhs;
};
