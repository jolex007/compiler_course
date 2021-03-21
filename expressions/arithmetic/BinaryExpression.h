#pragma once
#include "expressions/Expression.h"

enum InfixOperator {
    PLUS,
    MUL,
    DIV,
    MINUS,
    AND,
    OR,
    ASSIGN,
    GREATER,
    GREATEREQUAL,
    LESS,
    LESSEQUAL,
    EQUAL
};

class BinaryExpression : public Expression {
public:
    BinaryExpression(Expression* lhs, Expression* rhs, const std::string& sign, const location_type& loc);
    void Accept(Visitor* visitor) override;

    Expression* lhs;
    Expression* rhs;
    InfixOperator operator_;
};

