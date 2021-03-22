#pragma once
#include "expressions/Expression.h"

enum class InfixOperator {
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
    EQUAL,
    NOTEQUAL
};

class BinaryExpression : public Expression {
public:
    BinaryExpression(Expression* lhs, Expression* rhs, InfixOperator sign, const location_type& loc);
    void Accept(Visitor* visitor) override;

    Expression* lhs;
    Expression* rhs;
    InfixOperator operator_;
};

