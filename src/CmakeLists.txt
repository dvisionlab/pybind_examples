cmake_minimum_required(VERSION 3.5)

project(foo)

# add pybind11
add_subdirectory(../pybind11 ../pybind11)

# adds a library pybindings that can be called by python
pybind11_add_module(foo foo.cpp)
