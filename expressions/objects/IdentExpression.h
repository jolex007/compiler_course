#pragma once
#include "expressions/Expression.h"
#include "objects/BaseObject.h"
#include <string>

class IdentExpression : public Expression {
 public:
    IdentExpression(std::string ident, const location_type& loc);

    void Accept(Visitor* visitor) override;

    std::string ident_;
};
