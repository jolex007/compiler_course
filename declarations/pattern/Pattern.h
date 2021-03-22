#pragma once

#include "BaseElement/BaseElement.h"

class Pattern : public BaseElement {
public:
    Pattern(const std::string& identifier, const location_type& loc);
    Pattern(const std::string& identifier, const std::string& type, const location_type& loc);
    void Accept(Visitor* visitor) override;

    std::string identifier_;
    std::string type_;
};