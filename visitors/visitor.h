#pragma once
#include "class_declarations.h"

#include <string>

class Visitor {
public:
    virtual void Visit(Assignment* assignment) = 0;
    virtual void Visit(AssignmentList* assignment_list) = 0;

    virtual void Visit(AddExpression* expression) = 0;
    virtual void Visit(AndExpression* expression) = 0;
    virtual void Visit(AssignmentExpression* expression) = 0;
    virtual void Visit(ComparisonExpression* expression) = 0;
    virtual void Visit(DivExpression* expression) = 0;
    virtual void Visit(IdentExpression* expression) = 0;

    virtual void Visit(MulExpression* expression) = 0;
    virtual void Visit(NotExpression* expression) = 0;
    virtual void Visit(ObjectExpression* expression) = 0;

    virtual void Visit(OrExpression* expression) = 0;
    virtual void Visit(SubtractExpression* expression) = 0;
    virtual void Visit(UnaryMinusExpression* expression) = 0;

    virtual void Visit(Program* expression) = 0;
};
