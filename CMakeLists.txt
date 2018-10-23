cmake_minimum_required(VERSION 2.8.12)
project(sarray)


set (CMAKE_CXX_STANDARD 11)
# Use just one of these for Pybind11:
# GCC/clang:
#set(PYBIND11_CPP_STANDARD -std=c++11)
#set(PYBIND11_CPP_STANDARD -std=c++14)
# MSVC:
#set(PYBIND11_CPP_STANDARD /std:c++14)

# Uncomment below 3 lines for Pybind11
#set(PYBIND11_PYTHON_VERSION 3.6.6)
#add_subdirectory(pybind11)
#pybind11_add_module(sarray sarray4py.cpp)



add_executable(test_sarray  test_sarray.cpp)

add_executable(test_sarray3D  test_sarray3D.cpp)
