#pragma once

#include "expressions/Expression.h"

class FunctionCallExpression : public Expression {
public:
    FunctionCallExpression(const std::string& ident, ExpressionList* expressions, const location_type& loc);

    void Accept(Visitor* visitor) override;

    const std::string& ident_;
    ExpressionList* expressions_;
};
