# Install script for directory: D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen" TYPE FILE FILES
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/Cholesky"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/CholmodSupport"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/Core"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/Dense"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/Eigen"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/Eigenvalues"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/Geometry"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/Householder"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/IterativeLinearSolvers"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/Jacobi"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/LU"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/MetisSupport"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/OrderingMethods"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/PaStiXSupport"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/PardisoSupport"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/QR"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/QtAlignedMalloc"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/SPQRSupport"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/SVD"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/Sparse"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/SparseCholesky"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/SparseCore"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/SparseLU"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/SparseQR"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/StdDeque"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/StdList"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/StdVector"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/SuperLUSupport"
    "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/UmfPackSupport"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen" TYPE DIRECTORY FILES "D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/Eigen/src" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

