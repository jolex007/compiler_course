#pragma once

#include "BaseElement/BaseElement.h"

class Pattern : public BaseElement {
public:
    Pattern(IdentExpression* identifier, const location_type& loc);
    void Accept(Visitor* visitor) override;

    IdentExpression* identifier_;
};