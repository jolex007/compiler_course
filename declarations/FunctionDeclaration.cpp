#include "FunctionDeclaration.h"

FunctionDeclaration::FunctionDeclaration(PatternList* arguments, CodeBlock* code, const location_type &loc)
    : Declaration(loc, "FunctionDeclaration"), arguments_(arguments), code_(code) {
}

void FunctionDeclaration::Accept(Visitor *visitor) {
    visitor->Visit(this);
}
