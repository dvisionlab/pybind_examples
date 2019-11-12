#include <pybind11/pybind11.h>

// Simple function to export
int add(int x, int y) { return x + y; }

// define a module to be imported by python
PYBIND11_MODULE(foo, m) {
  // export the add method
  m.def("add", &add, "Add 2 numbers together", "x", "y");
}
