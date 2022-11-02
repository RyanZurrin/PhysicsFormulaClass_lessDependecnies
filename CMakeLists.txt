cmake_minimum_required(VERSION 3.16)
project(PhysicsFormula)

set(CMAKE_CXX_STANDARD 20)

if(EXISTS "E:/Program Files/vcpkg/scripts/buildsystems/vcpkg.cmake")
    set(DMAKE_TOOLCHAIN_FILE "E:/Program Files/vcpkg/scripts/buildsystems/vcpkg.cmake")
else()
    set(DMAKE_TOOLCHAIN_FILE "D:/src/vcpkg/scripts/buildsystems/vcpkg.cmake")
endif()




add_executable(PhysicsFormula testFactory.cpp Angle.h AtomicPhysics.h
        BinarySearchTree.h BinarySpacePartition.h Boundries.h Bounds.h Circle.h
        Circuits.h Cone.h Convexhull.h Core.h Cube.h Cylinder.h Distance.h
        Drag.h Forces.h Elasticity.h ElectricCharge.h ElectricCurrent.h
        ElectricPotential.h ElectroMagneticInduction.h ElectroMagneticWaves.h
        Energy.h ETL.h FluidDynamics.h Friction.h GeometricOptics.h GeoUtils.h
        Hearing.h Heat.h Inclusion.h Intersection.h KDTree.h Kinematics.h
        Line.h LinearAlgebra.h LinearRegression.h LogisticRegression.h
        Magnetism.h MathFx.h MatrixND.h LinearMomentum.h MonotonePartition.h
        Parallelogram.h PeriodicElements.h Physics_World.h Plane.h Point.h
        Point2D.h Polygon.h PolygonDCEL.h Polyhedron.h Pyramid.h QuadTree.h
        QuantumPhysics.h RandomNumbers.h Rectangle.h RectangularPrism.h
        RedBlackTree.h RegexHelper.h RotationalMotion.h RunTimer.h Segment.h
        SpecialRelativity.h Sphere.h Square.h Statics.h StringHelper.h
        Temperature.h TemplateClass.h Testing.h Thermodynamics.h Torque.h
        TransitiveClosure.h TriangleSolver.h Triangulation.h
        UniformCircularMotion.h Vector.h Vector2D.h Vector3D.h VectorND.h
        VisionOpticalInstruments.h Voronoi.h WaveOptics.h Waves.h Angle.cpp
        Convexhull.cpp Distance.cpp GeoUtils.cpp Inclusion.cpp Intersection.cpp
        KDTree.cpp Line.cpp MonotonePartition.cpp Point.cpp Polygon.cpp
        QuadTree.cpp Triangulation.cpp Vector.cpp Voronoi.cpp FluidStatics.h
        TemplateBST.h templateGraph.h templateGraph.cpp Calculus.h Derivation.h
        EuclideanGraph.h Constants.h StaticEquilibrium.h UnitVector.h
        Kirschoff.h pbPlots.hpp pbPlots.cpp supportLib.hpp supportLib.cpp Plots.h Dimensions.h ElectricField.h Scale.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/SFML/include)
target_link_libraries(PhysicsFormula sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

#Add the installation prefix of "Eigen3" to CMAKE_PREFIX_PATH or set
#"Eigen3_DIR" to a directory containing one of the above files.  If "Eigen3"
#provides a separate development package or SDK, be sure it has been
#installed.
#set the Eigen3_DIR to the directory where the Eigen3Config.cmake file is located
set(Eigen3_DIR D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/eigen-3.3.7/build/)
find_package(Eigen3 CONFIG REQUIRED)

target_link_libraries(PhysicsFormula Eigen3::Eigen)

