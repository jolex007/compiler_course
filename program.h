#pragma once

#include "statements/StatementList.h"
#include "expressions/Expression.h"

class Program {
public:
    Program(DeclarationList* assignments);
    DeclarationList* declarations_;
};