#pragma once

#include "BaseElement/BaseElement.h"
#include <string>

class Statement : public BaseElement {
public:
    Statement(const location_type &loc, const std::string& name);
};
