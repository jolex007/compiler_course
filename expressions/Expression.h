#pragma once
#include "statements/Statement.h"
#include <string>

class Expression : public Statement {
public:
    Expression(const location_type& loc, const std::string& name) : Statement(loc, name) {};
    ~Expression() override = default;
};

