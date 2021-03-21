#include "FunctionCallExpression.h"

FunctionCallExpression::FunctionCallExpression(const std::string& ident, ExpressionList *expressions, const location_type &loc)
    : Expression(loc, "FunctionCallExpression"), ident_(ident), expressions_(expressions) {
}

void FunctionCallExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}
