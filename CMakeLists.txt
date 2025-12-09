cmake_minimum_required(VERSION 3.10)
project(Lab3Figures)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(main ${SOURCES} main.cpp)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(tests tests/test_figures.cpp ${SOURCES})
target_link_libraries(tests ${GTEST_LIBRARIES} pthread)
add_test(NAME FigureTests COMMAND tests)
