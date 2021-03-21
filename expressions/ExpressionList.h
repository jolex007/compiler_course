#pragma once

#include "BaseElement/BaseElement.h"

class ExpressionList : public BaseElement {
public:
    ExpressionList(const location_type& loc);
    void AddExpression(Expression* expression);
    void Accept(Visitor* visitor) override;

    std::vector<Expression*> expressions_;
};
