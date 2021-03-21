#pragma once

#include "statements/Statement.h"

class Declaration : public Statement {
public:
    Declaration(const location_type& loc, const std::string& name)
        : Statement(loc, name) {}
};
