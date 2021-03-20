#pragma once

#include "assignments/Assignment.h"
#include "BaseElement.h"
#include <vector>

class AssignmentList : public BaseElement {
public:
    AssignmentList(const location_type& loc) : BaseElement(loc, "AssignmentList"){};
    void AddAssignment(Assignment* assignment);
    void Accept(Visitor* visitor) override;

    std::vector<Assignment*> assignments_;
};
