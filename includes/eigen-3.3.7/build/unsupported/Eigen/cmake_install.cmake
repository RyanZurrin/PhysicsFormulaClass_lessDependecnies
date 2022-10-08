# Install script for directory: D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/unsupported/Eigen

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Eigen3")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/unsupported/Eigen" TYPE FILE FILES
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/unsupported/Eigen/AdolcForward"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/unsupported/Eigen/AlignedVector3"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/unsupported/Eigen/ArpackSupport"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/unsupported/Eigen/AutoDiff"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/unsupported/Eigen/BVH"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/unsupported/Eigen/EulerAngles"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/unsupported/Eigen/FFT"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/unsupported/Eigen/IterativeSolvers"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/unsupported/Eigen/KroneckerProduct"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/unsupported/Eigen/LevenbergMarquardt"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/unsupported/Eigen/MatrixFunctions"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/unsupported/Eigen/MoreVectorization"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/unsupported/Eigen/MPRealSupport"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/unsupported/Eigen/NonLinearOptimization"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/unsupported/Eigen/NumericalDiff"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/unsupported/Eigen/OpenGLSupport"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/unsupported/Eigen/Polynomials"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/unsupported/Eigen/Skyline"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/unsupported/Eigen/SparseExtra"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/unsupported/Eigen/SpecialFunctions"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/unsupported/Eigen/Splines"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/unsupported/Eigen" TYPE DIRECTORY FILES "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/unsupported/Eigen/src" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/build/unsupported/Eigen/CXX11/cmake_install.cmake")

endif()

