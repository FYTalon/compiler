cmake_minimum_required(VERSION 3.0.0)
project(Compile VERSION 0.1.0)

find_package(BISON)
find_package(FLEX)
BISON_TARGET(Parser1 src/SysY2Eeyore/SysY2Eeyore.y ${PROJECT_SOURCE_DIR}/lib/SysY2Eeyore.tab.cpp)
FLEX_TARGET(Scanner1 src/SysY2Eeyore/SysY2Eeyore.l  ${PROJECT_SOURCE_DIR}/lib/SysY2Eeyore.yy.cpp)
BISON_TARGET(Parser2 src/Eeyore2Tigger/Eeyore2Tigger.y ${PROJECT_SOURCE_DIR}/lib/Eeyore2Tigger.tab.cpp)
FLEX_TARGET(Scanner2 src/Eeyore2Tigger/Eeyore2Tigger.l  ${PROJECT_SOURCE_DIR}/lib/Eeyore2Tigger.yy.cpp)
BISON_TARGET(Parser3 src/Tigger2RiscV/Tigger2RiscV.y ${PROJECT_SOURCE_DIR}/lib/Tigger2RiscV.tab.cpp)
FLEX_TARGET(Scanner3 src/Tigger2RiscV/Tigger2RiscV.l  ${PROJECT_SOURCE_DIR}/lib/Tigger2RiscV.yy.cpp)

ADD_FLEX_BISON_DEPENDENCY(Scanner1 Parser1)
ADD_FLEX_BISON_DEPENDENCY(Scanner2 Parser2)
ADD_FLEX_BISON_DEPENDENCY(Scanner3 Parser3)

include_directories(src)
include_directories(src/Eeyore2Tigger)
include_directories(src/SysY2Eeyore)
include_directories(src/Tigger2RiscV)
include_directories(lib)

file(GLOB srcs src/*.cpp src/*/*.cpp lib/*.cpp)

add_executable(Compile
    ${srcs}
    ${BISON_Parser1_OUTPUTS}
    ${FLEX_Scanner1_OUTPUTS}
    ${BISON_Parser2_OUTPUTS}
    ${FLEX_Scanner2_OUTPUTS}
    ${BISON_Parser3_OUTPUTS}
    ${FLEX_Scanner3_OUTPUTS}
)

