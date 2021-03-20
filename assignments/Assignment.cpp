#include "Assignment.h"

Assignment::Assignment(const std::string& variable,
                       Expression* expression, const location_type &loc) :
        BaseElement(loc, "Assignment"), variable_(variable), expression_(expression) {}

void Assignment::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
