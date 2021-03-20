#include "DivExpression.h"

DivExpression::DivExpression(Expression* lhs, Expression* rhs,
                             const location_type &loc) :
    BinaryExpression(lhs, rhs, loc, "DivExpression") {}

void DivExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
