#include "ObjectExpression.h"

#include <utility>

ObjectExpression::ObjectExpression(int value, const location_type &loc) :
    Expression(loc, "IntegerExpression") {
    object_ptr_ = new IntegerObject(value);
}

ObjectExpression::ObjectExpression(std::string value, const location_type &loc) :
    Expression(loc, "StringExpression") {
    object_ptr_ = new StringObject(std::move(value));
}

ObjectExpression::ObjectExpression(bool value, const location_type &loc) :
    Expression(loc, "BooleanExpression") {
    object_ptr_ = new BooleanObject(value);
}

void ObjectExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}

BaseObject* ObjectExpression::GetObjectPtr() const {
    return object_ptr_;
}
