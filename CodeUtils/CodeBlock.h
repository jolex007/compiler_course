#pragma once

#include "BaseElement/BaseElement.h"

class CodeBlock : public BaseElement {
public:
    CodeBlock(StatementList* statements, const location_type& loc);
    void Accept(Visitor* visitor) override;
    StatementList* statements;
};
