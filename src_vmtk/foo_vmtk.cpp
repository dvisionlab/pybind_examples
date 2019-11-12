#include <pybind11/pybind11.h>

#include "vtkPolyData.h"
#include "vtkSTLReader.h"

// Simple function to export
void readSTL(std::string filepath) {
  vtkSTLReader* reader = vtkSTLReader::New();
  vtkPolyData* polyData = vtkPolyData::New();
  reader->SetFileName(filepath.c_str());
  reader->Update();
  polyData->DeepCopy(reader->GetOutput());
  std::cout << "n points:" << polyData->GetNumberOfPoints() << std::endl;
  reader->Delete();
  polyData->Delete();
}

// define a module to be imported by python
PYBIND11_MODULE(foo_vmtk, m) {
  // export the readSTL method
  m.def("readSTL", &readSTL, "Read and STL file", "filepath");
}
