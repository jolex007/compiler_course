#include "SubscriptExpression.h"

SubscriptExpression::SubscriptExpression(Expression *exp_of, Expression *exp_indx, const location_type &loc)
    : Expression(loc, "SubscriptExpression"), expression_of(exp_of), expression_indx(exp_indx){
}

void SubscriptExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}
