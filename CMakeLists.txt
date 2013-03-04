cmake_minimum_required (VERSION 2.6)
project (polyran) 

# Sets custom compile flags
set(CMAKE_CXX_FLAGS "-fPIC -O3 -ffast-math -msse3 -mfpmath=sse")

# Sets custom module path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

find_package(Eigen3 REQUIRED)

find_package(Boost 1.49 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

enable_testing()

set(PACKAGE_STRING polyran)
set(PACKAGE_BUGREPORT roland.kwitt@kitware.com)

# Add our source dir
add_subdirectory(src)
