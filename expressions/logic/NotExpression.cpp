#include "NotExpression.h"

NotExpression::NotExpression(Expression* exp, const location_type &loc) :
    UnaryExpression(exp, loc, "NotExpression") {}

void NotExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
