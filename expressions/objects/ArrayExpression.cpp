#include "ArrayExpression.h"

ArrayExpression::ArrayExpression(ExpressionList *expressions, const location_type &loc)
    : Expression(loc, "ArrayExpression"), expressions_(expressions) {
}

void ArrayExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}


