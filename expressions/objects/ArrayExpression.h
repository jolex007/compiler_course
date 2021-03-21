#pragma once

#include "expressions/Expression.h"

class ArrayExpression : public Expression {
public:
    ArrayExpression(ExpressionList* expressions, const location_type& loc);

    void Accept(Visitor* visitor) override;

    ExpressionList* expressions_;
};

