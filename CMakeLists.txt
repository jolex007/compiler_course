cmake_minimum_required(VERSION 3.0)

project(Compiler)

# Set c++ standard
set(CMAKE_CXX_STANDARD 20)

# All binary files will be in /bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Compilers_SOURCE_DIR}/bin)

# Include flex & bison 
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(
    HEADERS
    
)

