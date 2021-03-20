#include "IdentExpression.h"

#include <utility>

IdentExpression::IdentExpression(std::string ident, Expression* exp, const location_type &loc):
    Expression(loc, "IdentExpression"),
    ident_(std::move(ident)) {
    expression_ = exp;
}


void IdentExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
