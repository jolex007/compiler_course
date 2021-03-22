#include "printvisitor.h"

#include "elements.h"
#include <iostream>


///______________________Constructor/Destructor_______________________________///

SymbolTreeVisitor::SymbolTreeVisitor(const std::string& filename) :
    stream_(filename) {}

SymbolTreeVisitor::~SymbolTreeVisitor() {
    stream_.close();
}

///________________________Helper_____________________________________________///

void SymbolTreeVisitor::PrintTabs() {
    for (int i = 0; i < num_tabs_; ++i) {
        stream_ << '\t';
    }
}

void SymbolTreeVisitor::PrintObjectValue(BaseObject* object_ptr) {
    SimpleType type = object_ptr->GetType();
    PrintTabs();
    switch(type) {
        case SimpleType::INT : {
            auto* casted_ptr = dynamic_cast<IntegerObject*>(object_ptr);
            stream_ << casted_ptr->GetValue() << std::endl;
            break;
        }
        case SimpleType::BOOLEAN : {
            auto* casted_ptr = dynamic_cast<BooleanObject*>(object_ptr);
            stream_ << casted_ptr->GetValue() << std::endl;
            break;
        }
        case SimpleType::STRING : {
            auto* casted_ptr = dynamic_cast<StringObject*>(object_ptr);
            stream_ << casted_ptr->GetValue() << std::endl;
            break;
        }
        default: {
            stream_ << "Unexpected type\n";
        }
    }
}

///______________________VisitGeneralExpression_______________________________///

void SymbolTreeVisitor::Visit(BinaryExpression* exp) {
    PrintTabs();
    stream_ << exp->GetName() << " (loc): " << exp->GetLocation() << " operator: ";
    switch (exp->operator_) {
    case InfixOperator::PLUS:
        stream_ << "+";
        break;

    case InfixOperator::MUL:
        stream_ << "*";
        break;

    case InfixOperator::DIV:
        stream_ << "/";
        break;

    case InfixOperator::MINUS:
        stream_ << "-";
        break;

    case InfixOperator::AND:
        stream_ << "and";
        break;

    case InfixOperator::OR:
        stream_ << "or";
        break;

    case InfixOperator::ASSIGN:
        stream_ << "=";
        break;

    case InfixOperator::GREATER:
        stream_ << ">";
        break;

    case InfixOperator::GREATEREQUAL:
        stream_ << ">=";
        break;

    case InfixOperator::LESS:
        stream_ << "<";
        break;

    case InfixOperator::LESSEQUAL:
        stream_ << "<=";
        break;

    case InfixOperator::EQUAL:
        stream_ << "==";
        break;

    case InfixOperator::NOTEQUAL:
        stream_ << "!=";
        break;
    }
    stream_ << std::endl;

    ++num_tabs_;
    exp->lhs->Accept(this);
    exp->rhs->Accept(this);
    --num_tabs_;
}

void SymbolTreeVisitor::Visit(UnaryExpression* exp) {
    PrintTabs();

    stream_ << exp->GetName() << " (loc): " << exp->GetLocation() << " operator: ";
    switch (exp->operator_) {
    case PrefixOperator::PRMINUS:
        stream_ << "-";
        break;
    case PrefixOperator::NOT:
        stream_ << "not";
        break;
    }
    stream_ << std::endl;
    ++num_tabs_;
    exp->exp->Accept(this);
    --num_tabs_;
}

///___________________________Statements_______________________________________///

void SymbolTreeVisitor::Visit(StatementList* assignment_list) {
    PrintTabs();
    stream_ << "StatementList (loc): " << assignment_list->GetLocation() << ' ' << std::endl;

    ++num_tabs_;
    for (Statement* statement : assignment_list->statements_) {
        statement->Accept(this);
    }
    --num_tabs_;
}

void SymbolTreeVisitor::Visit(IdentExpression* expression) {
    PrintTabs();
    stream_ << "IdentExpression (loc): " << expression->GetLocation() << std::endl;
    ++num_tabs_;
    PrintTabs();
    stream_ << expression->ident_ << std::endl;
    --num_tabs_;
}

void SymbolTreeVisitor::Visit(ObjectExpression* expression) {
    PrintTabs();
    stream_ << expression->GetName() << " (loc): " << expression->GetLocation() << ' '  << std::endl;
    ++num_tabs_;
    PrintObjectValue(expression->GetObjectPtr());
    --num_tabs_;
}



///______________________________Program___________________________///
void SymbolTreeVisitor::Visit(Program* program) {
    stream_ << "Program (loc): " << std::endl;

    ++num_tabs_;

    program->declarations_->Accept(this);

    --num_tabs_;
}

void SymbolTreeVisitor::Visit(DeclarationList *declaration_list) {
    PrintTabs();
    stream_ << "DeclarationList (loc): " << declaration_list->GetLocation() << ' ' << std::endl;

    ++num_tabs_;
    for (Declaration* declaration : declaration_list->declarations_) {
        declaration->Accept(this);
    }
    --num_tabs_;
}

void SymbolTreeVisitor::Visit(ExpressionList *expression_list) {
    PrintTabs();
    stream_ << "ExpressionList (loc): " << expression_list->GetLocation() << ' ' << std::endl;

    ++num_tabs_;
    for (Expression* expression : expression_list->expressions_) {
        expression->Accept(this);
    }
    --num_tabs_;
}

void SymbolTreeVisitor::Visit(CodeBlock *code) {
    PrintTabs();
    stream_ << "CodeBlock (loc): " << code->GetLocation() << ' ' << std::endl;

    ++num_tabs_;
    code->statements->Accept(this);
    --num_tabs_;
}

void SymbolTreeVisitor::Visit(FunctionDeclaration *function) {
    PrintTabs();
    stream_ << "FunctionDeclaration (loc): " << function->GetLocation() << ' ' << std::endl;

    ++num_tabs_;
    function->arguments_->Accept(this);
    function->code_->Accept(this);
    --num_tabs_;
}

void SymbolTreeVisitor::Visit(Pattern *pattern) {
    PrintTabs();
    stream_ << "Pattern (loc): " << pattern->GetLocation() << ' ' << std::endl;

    ++num_tabs_;
    PrintTabs();
    stream_ << "name: " << pattern->identifier_ << std::endl;
    --num_tabs_;
}

void SymbolTreeVisitor::Visit(PatternList *pattern_list) {
    PrintTabs();
    stream_ << "PatternList (loc): " << pattern_list->GetLocation() << ' ' << std::endl;

    ++num_tabs_;
    for (Pattern* pattern : pattern_list->patterns_) {
        pattern->Accept(this);
    }
    --num_tabs_;
}

void SymbolTreeVisitor::Visit(SubscriptExpression *expression) {
    PrintTabs();
    stream_ << "SubscriptExpression (loc): " << expression->GetLocation() << ' ' << std::endl;

    ++num_tabs_;
    expression->expression_of->Accept(this);
    expression->expression_indx->Accept(this);

    --num_tabs_;
}

void SymbolTreeVisitor::Visit(FunctionCallExpression *expression) {
    PrintTabs();
    stream_ << "FunctionCallExpression (loc): " << expression->GetLocation() << " name: " << expression->ident_ << std::endl;

    ++num_tabs_;
    expression->expressions_->Accept(this);
    --num_tabs_;
}

void SymbolTreeVisitor::Visit(ArrayExpression *expression) {
    PrintTabs();
    stream_ << "ArrayExpression (loc): " << expression->GetLocation() << " " << std::endl;

    ++num_tabs_;
    expression->expressions_->Accept(this);
    --num_tabs_;
}

