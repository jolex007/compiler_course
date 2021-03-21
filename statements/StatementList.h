#pragma once

#include "statements/Statement.h"
#include "BaseElement/BaseElement.h"
#include <vector>

class StatementList : public BaseElement {
public:
    StatementList(const location_type& loc);
    void AddStatement(Statement* statement);
    void Accept(Visitor* visitor) override;

    std::vector<Statement*> statements_;
};
