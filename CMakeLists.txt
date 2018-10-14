cmake_minimum_required(VERSION 2.8.12)
project(sarray)

# Use just one of these:
# GCC/clang:
#set(PYBIND11_CPP_STANDARD -std=c++11)
#set(PYBIND11_CPP_STANDARD -std=c++14)
#set(PYBIND11_CPP_STANDARD -std=c++1z) # Experimental C++17 support
# MSVC:
set(PYBIND11_CPP_STANDARD /std:c++14)
#set(PYBIND11_CPP_STANDARD /std:c++latest) # Enables some MSVC C++17 features

set(PYBIND11_PYTHON_VERSION 3.6.6)
#set(PYTHON_EXECUTABLE path/to/python)

add_subdirectory(pybind11)

# PyBind11 modules are here. Uncomment to make .pyd file
# pybind11_add_module(sarray sarray4py.cpp)



add_executable(test_sarray  test_sarray.cpp)

add_executable(test_sarray3D  test_sarray3D.cpp)
