#include "MulExpression.h"

MulExpression::MulExpression(Expression* lhs, Expression* rhs
, const location_type &loc): BinaryExpression(lhs, rhs, loc, "MulExpression") {}

void MulExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
