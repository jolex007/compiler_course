#include "Pattern.h"


Pattern::Pattern(const std::string& identifier, const location_type &loc)
    : BaseElement(loc, "Pattern"), identifier_(identifier) {
}

Pattern::Pattern(const std::string &identifier, const std::string &type, const location_type &loc)
    : BaseElement(loc, "Pattern"), identifier_(identifier), type_(type) {
}

void Pattern::Accept(Visitor *visitor) {
    visitor->Visit(this);
}
