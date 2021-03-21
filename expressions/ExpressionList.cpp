//
// Created by Алексей Зерцалов on 21.03.2021.
//

#include "ExpressionList.h"

ExpressionList::ExpressionList(const location_type &loc)
    : BaseElement(loc, "ExpressionList") {
}

void ExpressionList::AddExpression(Expression *expression) {
    expressions_.push_back(expression);
}

void ExpressionList::Accept(Visitor *visitor) {
    visitor->Visit(this);
}
