#include "DeclarationList.h"

DeclarationList::DeclarationList(const location_type& loc)
    : BaseElement(loc, "DeclarationList") {
}

void DeclarationList::AddDeclaration(Declaration* declaration) {
    declarations_.push_back(declaration);
}

void DeclarationList::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
