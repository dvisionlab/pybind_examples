
#include "vtkPolyData.h"
#include "vtkSTLReader.h"
#include "vtkvmtkPolyDataCenterlines.h"
#include "vtkSmartPointer.h"

// Simple function to export
void readSTL(std::string filepath) {
  vtkSTLReader* reader = vtkSTLReader::New();
  vtkPolyData* polyData = vtkPolyData::New();
  vtkvmtkPolyDataCenterlines* centerlineFilter = vtkvmtkPolyDataCenterlines::New();
  centerlineFilter->Delete();
  
  reader->SetFileName(filepath.c_str());
  reader->Update();
  polyData->DeepCopy(reader->GetOutput());
  std::cout << "n points:" << polyData->GetNumberOfPoints() << std::endl;
  reader->Delete();
  polyData->Delete();
}

int main (int argc, char* argv[]) {
  readSTL("/home/daron1337/Desktop/foo.stl");
}