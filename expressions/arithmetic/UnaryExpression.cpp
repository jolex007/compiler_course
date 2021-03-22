#include "UnaryExpression.h"

UnaryExpression::UnaryExpression(Expression *exp, PrefixOperator sign, const location_type &loc)
    : Expression(loc, "UnaryExpression"), operator_(sign), exp(exp) {
}

void UnaryExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}


