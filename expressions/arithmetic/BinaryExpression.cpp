//
// Created by Алексей Зерцалов on 20.03.2021.
//

#include "BinaryExpression.h"

BinaryExpression::BinaryExpression(Expression *lhs,
                                   Expression *rhs,
                                   const std::string& sign,
                                   const location_type& loc)
    : lhs(lhs), rhs(rhs), Expression(loc, "BinaryExpression") {
    if (sign == "+") {
        operator_ = PLUS;
    } else if (sign == "*") {
        operator_ = MUL;
    } else if (sign == "/") {
        operator_ = DIV;
    } else if (sign == "-") {
        operator_ = MINUS;
    } else if (sign == "and") {
        operator_ = AND;
    } else if (sign == "or") {
        operator_ = OR;
    } else if (sign == "=") {
        operator_ = ASSIGN;
    } else if (sign == ">") {
        operator_ = GREATER;
    } else if (sign == ">=") {
        operator_ = GREATEREQUAL;
    } else if (sign == "<") {
        operator_ = LESS;
    } else if (sign == "<=") {
        operator_ = LESSEQUAL;
    } else if (sign == "==") {
        operator_ = EQUAL;
    }
}

void BinaryExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}
