cmake_minimum_required(VERSION 3.5)

project(foo)

# add pybind11
# add_subdirectory(../pybind11 ../pybind11)

# include pybind11
find_path(PYBIND_DIRECTORY ${PYBIND_DIRECTORY} pybind11.egg-info)
# add pybind11
add_subdirectory(${PYBIND_DIRECTORY} ${PYBIND_DIRECTORY})

# adds a library pybindings that can be called by python
pybind11_add_module(foo foo.cpp)
