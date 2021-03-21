#include "UnaryExpression.h"

UnaryExpression::UnaryExpression(Expression *exp, const std::string& sign, const location_type &loc)
    : Expression(loc, "UnaryExpression"), exp(exp) {
    if (sign == "-") {
        operator_ = PRMINUS;
    } else if (sign == "not") {
        operator_ = NOT;
    }
}

void UnaryExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}


