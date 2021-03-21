#pragma once

#include "visitor.h"

#include <fstream>
#include <string>

class SymbolTreeVisitor: public Visitor {
 public:
    SymbolTreeVisitor(const std::string& filename);
    ~SymbolTreeVisitor();
    void Visit(StatementList* expression) override;

    void Visit(BinaryExpression* expression) override;
    void Visit(UnaryExpression* expression) override;
    void Visit(IdentExpression* expression) override;
    void Visit(ObjectExpression* expression) override;
    void Visit(SubscriptExpression* expression) override;
    void Visit(FunctionCallExpression* expression) override;
    void Visit(ArrayExpression* expression) override;

    void Visit(DeclarationList* declarations) override;

    void Visit(ExpressionList* expressions) override;
    void Visit(CodeBlock* code) override;
    void Visit(FunctionDeclaration* function) override;

    void Visit(Pattern* pattern) override;
    void Visit(PatternList* pattern_list) override;

    void Visit(Program* program) override;

 private:

    void PrintTabs();

    void PrintObjectValue(BaseObject* object_ptr);
    std::ofstream stream_;
    int num_tabs_ = 0;
};
