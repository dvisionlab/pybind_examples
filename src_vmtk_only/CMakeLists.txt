cmake_minimum_required(VERSION 3.5)

project(foo_vmtk)

# include vtk headers
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

# include itk headers
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

# include vmtk headers
find_path(VMTK_DIRECTORY ${VMTK_DIRECTORY} vmtk_env.sh)
include_directories(${VMTK_DIRECTORY}/include/vmtk)

# link vmtk libraries
IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    link_directories(${VMTK_DIRECTORY}/lib)
    FILE(GLOB vmtk ${VMTK_DIRECTORY}/lib/*.a)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    link_directories(${VMTK_DIRECTORY}/lib)
    FILE(GLOB vmtk ${VMTK_DIRECTORY}/lib/*a)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

IF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
  link_directories(${VMTK_DIRECTORY}/lib)
  FILE(GLOB vmtk ${VMTK_DIRECTORY}/lib/*.lib)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")

add_executable(foo_vmtk foo_vmtk.cpp)

# link external libraries
target_link_libraries(foo_vmtk ${VTK_LIBRARIES} ${ITK_LIBRARIES} ${vmtk} )
