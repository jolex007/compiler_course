#include "ComparisonExpression.h"

ComparisonExpression::ComparisonExpression(Expression* lhs,
                                           Expression* rhs,
                                           const std::string& sign, const location_type &loc) :
                                           BinaryExpression(lhs, rhs, loc, "MulExpression"),
                                           sign_(sign),
                                           type_(DefineComparisonType(sign)) {}

ComparisonType ComparisonExpression::DefineComparisonType(const std::string &sign) const{
    ComparisonType comparisonType;
    if (sign == "<") {
        comparisonType = ComparisonType::LT;
    } else if (sign == ">") {
        comparisonType = ComparisonType::GT;
    } else if (sign == "<=") {
        comparisonType = ComparisonType::LE;
    } else if (sign == ">=") {
        comparisonType = ComparisonType::GE;
    } else if (sign == "==") {
        comparisonType = ComparisonType::EQ;
    } else {
        comparisonType = ComparisonType::NE;
    }
    return comparisonType;
}

const std::string& ComparisonExpression::GetSign() const {
    return sign_;
}

void ComparisonExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}

ComparisonType ComparisonExpression::GetType() const {
    return type_;
}
