#pragma once
#include "expressions/Expression.h"
#include "expressions/BinaryExpression.h"

#include <string>
#include <vector>

enum class ComparisonType {
    LT,
    GT,
    LE,
    GE,
    EQ,
    NE
};

class ComparisonExpression: public BinaryExpression {
public:
    ComparisonExpression(Expression* lhs, Expression* rhs, const std::string& sign, const location_type& loc);
    void Accept(Visitor* visitor) override;

    ComparisonType GetType() const;

    const std::string& GetSign() const;

private:
    ComparisonType DefineComparisonType(const std::string& sign) const;

    std::string sign_;
    ComparisonType type_;
};
