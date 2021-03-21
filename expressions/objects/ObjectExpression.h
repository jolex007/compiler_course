#pragma once

#include "../Expression.h"
#include "../../objects/BaseObject.h"
#include "../../objects/IntegerObject.h"
#include "../../objects/BooleanObject.h"
#include "../../objects/StringObject.h"

class ObjectExpression: public Expression {
public:
    explicit ObjectExpression(int value, const location_type& loc);
    explicit ObjectExpression(std::string value, const location_type& loc);
    explicit ObjectExpression(bool value, const location_type& loc);

    void Accept(Visitor* visitor) override;
    BaseObject* GetObjectPtr() const;

private:
    BaseObject* object_ptr_;
};
