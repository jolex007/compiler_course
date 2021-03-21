cmake_minimum_required(VERSION 3.15)

project(Compiler)

if (${APPLE})
    set(ENV{CMAKE_INCLUDE_PATH} "/usr/local/opt/flex/include:ENV{CMAKE_INCLUDE_PATH}")
    set(ENV{CMAKE_LIBRARY_PATH} "/usr/local/opt/flex/lib;/usr/local/opt/bison/lib:ENV{CMAKE_LIBRARY_PATH}")
    set(ENV{PATH} "/usr/local/opt/flex/bin:/usr/local/opt/bison/bin:ENV{PATH}")

    set(BISON_EXECUTABLE "/usr/local/opt/bison/bin/bison")
    set(FLEX_EXECUTABLE "/usr/local/opt/flex/bin/flex")
endif()

# Set c++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(
        HEADERS
        driver.hh
        parser.hh
)

# All binary files will be in /bin
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Compiler_SOURCE_DIR}/bin)

# Include flex & bison
find_package(BISON 3.5 REQUIRED)
BISON_TARGET(
        MyParser
        parser.y
        ${Compiler_SOURCE_DIR}/parser.cpp
        DEFINES_FILE ${Compiler_SOURCE_DIR}/parser.hh
)

find_package(FLEX 2.6.4 REQUIRED)
FLEX_TARGET(
        MyScanner
        scanner.l
        ${Compiler_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(
        Compiler

        main.cpp
        driver.cpp
        ${BISON_MyParser_OUTPUTS}
        ${FLEX_MyScanner_OUTPUTS}

        statements/Statement.cpp
        statements/StatementList.cpp

        expressions/objects/ObjectExpression.cpp
        expressions/objects/IdentExpression.cpp

        objects/IntegerObject.cpp
        objects/BooleanObject.cpp
        objects/StringObject.cpp

        visitors/printvisitor.cpp

        program.cpp
        expressions/arithmetic/BinaryExpression.cpp expressions/arithmetic/BinaryExpression.h expressions/arithmetic/UnaryExpression.cpp declarations/Declaration.h declarations/DeclarationList.cpp declarations/DeclarationList.h declarations/ClassDeclaration.cpp declarations/ClassDeclaration.h declarations/FunctionDeclaration.cpp declarations/FunctionDeclaration.h declarations/VariableDeclaration.cpp declarations/VariableDeclaration.h declarations/ConstantDeclaration.cpp declarations/ConstantDeclaration.h declarations/ExtensionDeclaration.cpp declarations/ExtensionDeclaration.h declarations/InitializerDeclaration.cpp declarations/InitializerDeclaration.h declarations/DeinitializerDeclaration.cpp declarations/DeinitializerDeclaration.h expressions/ExpressionList.cpp expressions/ExpressionList.h CodeUtils/CodeBlock.cpp CodeUtils/CodeBlock.h declarations/pattern/Pattern.cpp declarations/pattern/Pattern.h declarations/pattern/PatternList.cpp declarations/pattern/PatternList.h expressions/objects/SubscriptExpression.cpp expressions/objects/SubscriptExpression.h expressions/other/FunctionCallExpression.cpp expressions/other/FunctionCallExpression.h expressions/objects/ArrayExpression.cpp expressions/objects/ArrayExpression.h)

target_include_directories(
        Compiler PRIVATE ${Compiler_SOURCE_DIR}
)
target_include_directories(Compiler PUBLIC ${FLEX_INCLUDE_DIRS})


