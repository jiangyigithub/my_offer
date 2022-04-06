cmake_minimum_required(VERSION 3.0.0)
project(code VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(code32a cpp/algorithm/32tree_a.cpp)
add_executable(code47dp cpp/algorithm/47dp.cpp)
add_executable(code48dp cpp/algorithm/48dp.cpp)
add_executable(code01stl cpp/stl/src/functor.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
