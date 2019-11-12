## HOW TO USE C++ code from python using pybind11

# get pybind11 from github and clone it into pybind_test directory
# cd into pybind11 and run python setup.py install

# Standard example (src folder)
# create a build folder and cd into it
# ccmake ../src
# set USE_PYTHON_INCLUDE_DIR ON
# set CMAKE_BUILD_TYPE Release
# configure and generate using ("c" and "g")
# make
# import module from python


# Advanced example (src_vmtk folder)
# first of all get and compile vmtk if not already installed
# clone vmtk from github
# create vmtk-build folder and cd into it
# ccmake ../vmtk
# set BUILD_SHARED_LIBS OFF
# set VTK_VMTK_WRAP_PYTHON OFF
# set CMAKE_BUILD_TYPE Release
# configure and generate using ("c" and "g")
# make -j2

# create a build_vmtk folder and cd into it
# ccmake ../src_vmtk
# set USE_PYTHON_INCLUDE_DIR ON
# set CMAKE_BUILD_TYPE Release
# set ITK_DIRECTORY as path_to_vmtk_build/ITK-Build
# set VTK_DIRECTORY as path_to_vmtk_build/VTK-Build
# set VMTK_DIRECTORY as path_to_vmtk_build/Install
# configure and generate using ("c" and "g")

# make
# import module from python
