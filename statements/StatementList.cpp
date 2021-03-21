#include "StatementList.h"

StatementList::StatementList(const location_type& loc)
    : BaseElement(loc, "AssignmentList") {
}

void StatementList::AddStatement(Statement* statement) {
    statements_.push_back(statement);
}

void StatementList::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
