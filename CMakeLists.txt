cmake_minimum_required(VERSION 3.16)
project(PhysicsFormula)

set(CMAKE_CXX_STANDARD 20)

add_executable(PhysicsFormula testFactory.cpp Angle.h AtomicPhysics.h BinarySearchTree.h BinarySpacePartition.h Boundries.h Bounds.h Circle.h Circuits.h Cone.h Convexhull.h Core.h Cube.h Cylinder.h Distance.h Drag.h Forces.h Elasticity.h ElectricCharge.h ElectricCurrent.h ElectricPotential.h ElectroMagneticInduction.h ElectroMagneticWaves.h Energy.h ETL.h FluidDynamics.h Friction.h GeometricOptics.h GeoUtils.h Hearing.h Heat.h Inclusion.h Intersection.h KDTree.h Kinematics.h Line.h LinearAlgebra.h LinearRegression.h LogisticRegression.h Magnetism.h MathFx.h MatrixND.h LinearMomentum.h MonotonePartition.h Parallelogram.h PeriodicElements.h Physics_World.h Plane.h Point.h Point2D.h Polygon.h PolygonDCEL.h Polyhedron.h Pyramid.h QuadTree.h QuantumPhysics.h RandomNumbers.h Rectangle.h RectangularPrism.h RedBlackTree.h RegexHelper.h RotationalMotion.h RunTimer.h Segment.h SpecialRelativity.h Sphere.h Square.h Statics.h StringHelper.h Temperature.h TemplateClass.h Testing.h Thermodynamics.h Torque.h TransitiveClosure.h TriangleSolver.h Triangulation.h UniformCircularMotion.h Vector.h Vector2D.h Vector3D.h VectorND.h VisionOpticalInstruments.h Voronoi.h WaveOptics.h Waves.h Angle.cpp Convexhull.cpp Distance.cpp GeoUtils.cpp Inclusion.cpp Intersection.cpp KDTree.cpp Line.cpp MonotonePartition.cpp Point.cpp Polygon.cpp QuadTree.cpp Triangulation.cpp Vector.cpp Voronoi.cpp FluidStatics.h TemplateBST.h templateGraph.h templateGraph.cpp Calculus.h Derivation.h EuclideanGraph.h Constants.h StaticEquilibrium.h UnitVector.h Kirschoff.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(D:/src/CLionProjects/PhysicsFormulaClass_lessDependecnies/includes/SFML/include)
target_link_libraries(PhysicsFormula sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
