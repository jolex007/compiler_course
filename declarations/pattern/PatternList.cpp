#include "PatternList.h"


PatternList::PatternList(const location_type &loc)
    : BaseElement(loc, "PatternList") {
}

void PatternList::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

void PatternList::AddPattern(Pattern *pattern) {
    patterns_.push_back(pattern);
}
