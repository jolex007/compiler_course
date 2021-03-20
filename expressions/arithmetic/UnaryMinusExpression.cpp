#include "UnaryMinusExpression.h"


UnaryMinusExpression::UnaryMinusExpression(Expression* exp, const location_type &loc) :
    UnaryExpression(exp, loc, "UnaryMinusExpression") {}

void UnaryMinusExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
