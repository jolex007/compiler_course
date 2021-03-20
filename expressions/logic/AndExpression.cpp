#include "AndExpression.h"

AndExpression::AndExpression(Expression* lhs, Expression* rhs
, const location_type &loc): BinaryExpression(lhs, rhs, loc, "AndExpression") {}

void AndExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
