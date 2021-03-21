#pragma once
#include "class_declarations.h"

#include <string>

class Visitor {
public:
    virtual void Visit(StatementList* assignment_list) = 0;

    virtual void Visit(BinaryExpression* expression) = 0;
    virtual void Visit(IdentExpression* expression) = 0;
    virtual void Visit(ObjectExpression* expression) = 0;
    virtual void Visit(UnaryExpression* expression) = 0;
    virtual void Visit(SubscriptExpression* expression) = 0;
    virtual void Visit(FunctionCallExpression* expression) = 0;
    virtual void Visit(ArrayExpression* expression) = 0;

    virtual void Visit(DeclarationList* declarations) = 0;
    virtual void Visit(ExpressionList* expressions) = 0;
    virtual void Visit(CodeBlock* code) = 0;
    virtual void Visit(FunctionDeclaration* function) = 0;

    virtual void Visit(Pattern* pattern) = 0;
    virtual void Visit(PatternList* pattern_list) = 0;

    virtual void Visit(Program* expression) = 0;
};
