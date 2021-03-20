#include "AssignmentExpression.h"

#include <utility>

AssignmentExpression::AssignmentExpression(std::string  variable,
    Expression* expression, const location_type &loc) :
    Expression(loc, "AssignmentExpression"),
    variable_(std::move(variable)),
    expression_(expression) {}

void AssignmentExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
