cmake_minimum_required(VERSION 3.0.0)
project(Compile VERSION 0.1.0)

find_package(BISON)
find_package(FLEX)
BISON_TARGET(Parser src/parser.y ${PROJECT_SOURCE_DIR}/src/parser.cpp)
FLEX_TARGET(Scanner src/token.l  ${PROJECT_SOURCE_DIR}/src/token.cpp)
ADD_FLEX_BISON_DEPENDENCY(Scanner Parser)
include_directories(src)

file(GLOB srcs src/*.cpp)

add_executable(Compile
    ${srcs}
    ${BISON_Parser_OUTPUTS}
    ${FLEX_Scanner_OUTPUTS}
)

