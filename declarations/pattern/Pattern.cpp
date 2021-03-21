#include "Pattern.h"


Pattern::Pattern(IdentExpression *identifier, const location_type &loc)
    : BaseElement(loc, "Pattern"), identifier_(identifier) {
}

void Pattern::Accept(Visitor *visitor) {
    visitor->Visit(this);
}
