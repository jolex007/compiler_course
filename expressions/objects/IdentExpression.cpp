#include "IdentExpression.h"

#include <utility>

IdentExpression::IdentExpression(std::string ident, const location_type &loc):
    Expression(loc, "IdentExpression"),
    ident_(std::move(ident)) {
}


void IdentExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
