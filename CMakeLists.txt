cmake_minimum_required(VERSION 3.0.0)
project(motionPrimitives VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(motionPrimitives ./src/main.cpp)
include_directories($(motionPrimitives_SOURCE_DIR)/include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
