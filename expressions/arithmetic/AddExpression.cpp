#include "AddExpression.h"

AddExpression::AddExpression(Expression* lhs, Expression* rhs, const location_type& loc) :
    BinaryExpression(lhs, rhs, loc, "AddExpression") {}

void AddExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
