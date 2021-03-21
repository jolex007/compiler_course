#pragma once

#include "BaseElement/BaseElement.h"
#include "Declaration.h"

class DeclarationList : public BaseElement {
public:
    DeclarationList(const location_type& loc);

    void AddDeclaration(Declaration* declaration);
    void Accept(Visitor* visitor) override;

    std::vector<Declaration*> declarations_;
};
