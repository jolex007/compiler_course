#pragma once

#include "BaseElement/BaseElement.h"
#include "Pattern.h"

class PatternList : public BaseElement {
public:
    PatternList(const location_type& loc);
    void Accept(Visitor* visitor) override;
    void AddPattern(Pattern* pattern);

    std::vector<Pattern*> patterns_;
    // TODO: add type
};

