#pragma once

#include "BaseElement/BaseElement.h"
#include "CodeUtils/CodeBlock.h"
#include "Declaration.h"

class FunctionDeclaration : public Declaration {
public:
    FunctionDeclaration(PatternList* arguments, CodeBlock* code_, const location_type& loc);
    void Accept(Visitor* visitor) override;

    PatternList* arguments_;
    CodeBlock* code_;
};
