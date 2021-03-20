#include "SubtractExpression.h"

SubtractExpression::SubtractExpression(Expression* lhs, Expression* rhs, const location_type& loc):
    BinaryExpression(lhs, rhs, loc, "SubExpression") {}

void SubtractExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
