#include "OrExpression.h"

OrExpression::OrExpression(Expression* lhs, Expression* rhs, const location_type &loc):
    BinaryExpression(lhs, rhs, loc, "OrExpression") {}

void OrExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
