#include "CodeBlock.h"

CodeBlock::CodeBlock(StatementList *statements, const location_type &loc)
    : BaseElement(loc, "CodeBlock"), statements(statements) {
}

void CodeBlock::Accept(Visitor *visitor) {
    visitor->Visit(this);
}
