# HOW TO USE C++ code from python using pybind11

## Prepare the environment

Clone and prepare folder

    $ git clone https://github.com/dvisionlab/pybind_examples
    $ cd pybind_examples

Prepare a virtual environment where to install pybind11

    $ python3 -m venv venv
    $ . ./venv/bin/activate

Get pybind11 from github, clone it into `pybind_test` directory and install it

    (venv) $ git clone https://github.com/pybind/pybind11
    (venv) $ cd pybind11
    (venv) $ python setup.py install

## Standard example (`src` folder)

Create a build folder, cd into it and run

    (venv) $ ccmake ../src

A TUI should pop up, press `c` to configure, then

- set `USE_PYTHON_INCLUDE_DIR ON`
- set `CMAKE_BUILD_TYPE Release`

Press `c` and `g` to generate the makefile, then

    (venv) $ make

The module `foo` should be now present:

    (venv) $ python
    >>> import foo
    >>> foo.add(1, 5)
    6

## Advanced example (`src_vmtk` folder)

### Pre-requisite: install vmtk

    $ git clone https://github.com/vmtk/vmtk
    $ mkdir vmtk-build
    $ cd vmtk-build
    $ ccmake ../vmtk

Then do the following:

- set `BUILD_SHARED_LIBS OFF`
- set `VTK_VMTK_WRAP_PYTHON OFF`
- set `CMAKE_BUILD_TYPE Release`

Then configure with `c` and generate by pressing `g` and build:

    $ make -j2

### Compiling the example

    (venv) $ cd pybind_examples
    (venv) $ mkdir build_vmtk
    (venv) $ cd build_vmtk
    $ ccmake ../src_vmtk

Configure using the following:

- set `USE_PYTHON_INCLUDE_DIR ON`
- set `CMAKE_BUILD_TYPE Release`
- set `ITK_DIRECTORY` as `path_to_vmtk_build/ITK-Build`
- set `VTK_DIRECTORY` as `path_to_vmtk_build/VTK-Build`
- set `VMTK_DIRECTORY` as `path_to_vmtk_build/Install`

Configure and generate using "c" and "g"

    (venv) $ make
    (venv) $ python3
    >>> import vmtk
