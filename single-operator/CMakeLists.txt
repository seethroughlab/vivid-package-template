cmake_minimum_required(VERSION 3.20)
project(your_package_name LANGUAGES CXX)

if(NOT DEFINED VIVID_SRC_DIR)
  message(FATAL_ERROR "VIVID_SRC_DIR not set. Build through vivid package tooling.")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

option(BUILD_PACKAGE_TESTS "Build package-local C++ tests" OFF)

include_directories(${VIVID_SRC_DIR}/src)

function(add_vivid_pkg_operator name src)
  add_library(${name} SHARED ${src})
  set_target_properties(${name} PROPERTIES PREFIX "" SUFFIX ".dylib")
endfunction()

add_vivid_pkg_operator(example_op operators/control/example_op/example_op.cpp)

if(BUILD_PACKAGE_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
