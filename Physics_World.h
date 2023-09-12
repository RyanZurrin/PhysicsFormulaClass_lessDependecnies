//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_PHYSICS_WORLD_H
#define PHYSICSFORMULA_PHYSICS_WORLD_H
/**
 * @class PhysicsWorld
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @date   10/15/2020
 */

#define TYPE long double

#include <iostream>
#include <Eigen/Dense>
#include "Testing.h"
#include "StringHelper.h"
#include "RegexHelper.h"
#include "AtomicPhysics.h"
#include "TemplateBST.h"
#include "Circuits.h"
#include "CircuitBoard.h"
#include "Cone.h"
#include "Cylinder.h"
#include "Cube.h"
#include "Dimensions.h"
#include "Drag.h"
#include "Forces.h"
#include "Elasticity.h"
#include "FluidStatics.h"
#include "Hearing.h"
#include "Kinematics.h"
#include "LinearAlgebra.h"
#include "LogisticRegression.h"
#include "MathFx.h"
#include "LinearMomentum.h"
#include "Parallelogram.h"
#include "Pyramid.h"
#include "RandomNumbers.h"
#include "Rectangle.h"
#include "RectangularPrism.h"
#include "RotationalMotion.h"
#include "Scale.h"
#include "Sphere.h"
#include "Statics.h"
#include "TemplateBST.h"
#include "templateGraph.h"
#include "Thermodynamics.h"
#include "Torque.h"
#include "TransitiveClosure.h"
#include "TriangleSolver.h"
#include "Vector.h"
#include "VisionOpticalInstruments.h"
#include "Square.h"
#include "QuantumPhysics.h"
#include "EuclideanGraph.h"
#include "FluidDynamics.h"
#include "Circle.h"
#include "StaticEquilibrium.h"
#include "Plots.h"

typedef TriangleSolver TS;
typedef QuantumPhysics QP;
typedef SpecialRelativity SR;
typedef WaveOptics WO;
typedef VisionOpticalInstruments VOI;
typedef UniformCircularMotion UCM;
typedef Thermodynamics TD;
typedef Temperature TEMP;
typedef RotationalMotion RM;
typedef GeometricOptics GO;
typedef FluidStatics FS;
typedef FluidDynamics FD;
typedef ElectromagneticWaves EMW;
typedef ElectroMagneticInduction EMI;
typedef ElectricPotential EP;
typedef ElectricCurrent EC;
typedef ElectricCharge ECH;
typedef Forces DAF;
typedef RandomNumbers RN;
typedef AtomicPhysics AP;
typedef LinearMomentum LM;
typedef LinearAlgebra LA;
typedef Plots PLT;





static auto physics_objectCount = 0;
template<typename T>
void print_type_properties()
{
    std::cout <<'\n'
              << "min="
              << std::numeric_limits<T>::min() << '\n'
              << "max="
              << std::numeric_limits<T>::max() << '\n'
              << "bits="
              << std::numeric_limits<T>::digits << '\n'
              << "decdigits="
              << std::numeric_limits<T>::digits10 << '\n'
              << "integral="
              << std::numeric_limits<T>::is_integer << '\n'
              << "signed="
              << std::numeric_limits<T>::is_signed << '\n'
              << "exact="
              << std::numeric_limits<T>::is_exact << '\n'
              << "infinity="
              << std::numeric_limits<T>::has_infinity << '\n';
}

//_____________________________________________________________________________
//global constants, methods and structures
//
//


static long double _val_;// = 0.0;


/// <summary>
/// Sets the value of the static member _val_
/// </summary>
/// <param name="v">The value to set val too.</param>
/// <returns>returns the value of v</returns>
static auto setVal = []<class T>(const T & v) {
    _val_ = v;
    return _val_;
};

/// <summary>
/// Gets the value.
/// </summary>
/// <returns></returns>
static auto getVal = []<class T>() {
    return  _val_;
};

/// <summary>
/// Shows the value with a label in front and units in back
/// </summary>
/// <param name="label">The label.</param>
/// <param name="units">The units.</param>
static auto show_val = []<class T>(const T label = "", const T units = "") {
    cout << "\n"<<label<<": " << _val_ << " "<<units <<endl;
};

/// <summary>
/// Prints the vector values of passed in vector.
/// </summary>
/// <param name="v">The v.</param>
/*
static void printVectorValues(vector<long double>& v)
{
	cout << "vector: ";
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << ", ";
	}
	std::cout << std::endl;
}//end printVectorValues
*/
/// <summary>
/// Prints the vector values of a vector
/// </summary>
/// <param name="v">The vector to print.</param>
template<typename T>
static auto printVector(vector<T>& v)
{
    cout << "vector: ";
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << (i<v.size()-1?", ":"");
    }
    std::cout << std::endl;
}//end printVectorValues

/// <summary>
/// Prints the vector of any type
/// </summary>
/// <param name="t">The vector to print.</param>
template<typename T>
void printVector(const T& t) {
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, ", "));
}//end printVector

/// <summary>
/// Prints out a multidimensional vector values of any type.
/// </summary>
/// <param name="t">The vector to print.</param>
template<typename T>
void printVectorInVector(const T& t) {
    std::for_each(t.cbegin(), t.cend(), printVector<typename T::value_type>);
}//end printVectorInVector

/// <summary>
/// Prints an array of any type
/// </summary>
/// <param name="array">The array.</param>
template <typename T, size_t size>
void static printArray(const T(&array)[size])
{
    for (size_t i = 0; i < size; i++)
        cout << array[i] << " ";

    cout << endl;
}//end printArray

/// <summary>
/// Prints a map of any types out in its entirety.
/// </summary>
/// <param name="m">The map to print.</param>
template<typename K, typename V>
void printMap(std::map<K,V> const &m)
{
    for (auto const& pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}//end print_map

/// <summary>
/// Searches any type map by found value. only use if you need the values saved.\n
/// WARNING*** printMapValues allows you to pass only a map and a search value in
/// and it instantiates a vector within its scope and then fills it as well as
/// prints out the values to screen.*****\n
/// Use this method when you need to find the
/// values that match and then use them in other calculations within client code.
/// </summary>
/// <param name="vec">The vector to store the results in.</param>
/// <param name="mapOfElemen">The map of elements to search by values.</param>
/// <param name="value">The value to look for.</param>
/// <returns>true if a match was found: else false</returns>
template<typename K, typename V>
bool searchMapByValue(std::vector<K> & vec, std::map<K, V> mapOfElemen, V value)
{
    bool bResult = false;
    auto it = mapOfElemen.begin();
    while(it != mapOfElemen.end())
    {
        if(it->second == value)
        {
            bResult = true;
            vec.push_back(it->first);
        }
        it++;
    }
    return bResult;
}//end searchMapByValue
template<typename K, typename V>
bool searchMapByValue(std::vector<K> & vec, std::multimap<K, V> mapOfElemen, V value)
{
    bool bResult = false;
    auto it = mapOfElemen.begin();
    while(it != mapOfElemen.end())
    {
        if(it->second == value)
        {
            bResult = true;
            vec.push_back(it->first);
        }
        it++;
    }
    return bResult;
}//end searchMapByValue

/// <summary>
/// Prints the map keys found by search value.
/// </summary>
/// <param name="m">The map to search.</param>
/// <param name="val">The value to search for.</param>
template<typename K, typename V>
void printMapByValue(std::map<K,V> m, const V val)
{
    std::cout << "looking for value: "<< val<<endl;
    std::vector<std::string> results;
    bool tests = searchMapByValue(results, m, val);
    if(tests)
    {
        std::cout<<"Keys with value "<< val<< " are:"<<std::endl;
        printVector(results);

    }
    else
    {
        std::cout<<"No Key is found with the given value"<<std::endl;
    }

}//end printMapByValue

/// <summary>
/// Prints the map keys found by search value.
/// </summary>
/// <param name="m">The map to search.</param>
/// <param name="val">The value to search for.</param>
template<typename K, typename V>
void printMapByValue(std::multimap<K,V> m, const V val)
{
    std::cout << "looking for value: "<< val<<endl;
    std::vector<std::string> results;
    bool tests = searchMapByValue(results, m, val);
    if(tests)
    {
        std::cout<<"Keys with value "<< val<< " are:"<<std::endl;
        printVector(results);

    }
    else
    {
        std::cout<<"No Key is found with the given value"<<std::endl;
    }

}//end printMapByValue

/// <summary>
/// Prints an array of long doubles with a size of n
/// </summary>
/// <param name="arr">The array.</param>
/// <param name="n">= sizeof( arr ) / sizeof( *arr )</param>
void static printArr(const long double arr[], const int n)
{
    cout << "array values: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
}//end printArr




/// <summary>
/// Calculates the area of a sphere.
/// </summary>
/// <param name="r">The radius.</param>
/// <returns>the area of sphere (m^2)</returns>
static auto sphereArea = []<class T>(const T r)
{
    return 4.0 * constants::PI * (r * r);
};


/// <summary>
/// Calculates the volume of a sphere.
/// </summary>
/// <param name="r">The radius.</param>
/// <returns>the volume of sphere(m^3)</returns>
static auto sphereVolume = []<class T>(const long double r)
{
    return (4.0 / 3.0) * (constants::PI * (r * r * r));
};


/// <summary>
/// Calculates the circumference of a circle.
/// </summary>
/// <param name="rd">The radius or diameter, use mode to specify.</param>
/// <param name="mode">use 'd' to specify if you use diameter and not
/// radius. Do not add anything here if it is the radius you are using
/// as it is defaulted to radius</param>
/// <returns>circumference of circle (m)</returns>
static auto circleCircumference = []<class T>(const T rd, const char mode = 'r')
{
    if (mode == 'r')
    {
        return 2.0 * constants::PI * rd;
    }
    return constants::PI * rd;
};

/// <summary>
/// Calculates the area of a circle.
/// </summary>
/// <param name="rd">The radius or diameter, use mode to specify.</param>
/// <param name="mode">use 'd' to specify if you use diameter and not
/// radius. Do not add anything here if it is the radius you are using
/// as it is defaulted to radius</param>
/// <returns>area of a circle (m^2)</returns>
static auto circleArea = []<class T>(const T rcd, const char mode = 'r')
{
    if (mode == 'r')
    {
        // calculate from radius
        return constants::PI * (rcd * rcd);
    }
    else if (mode == 'c')
    {
        // calculate from circumference
        return (rcd*rcd) / (4.0 * constants::PI);
    }
    else
    {
        // calculate from diameter
        return (constants::PI * (rcd * rcd)) / 4.0;
    }
};

/// <summary>
/// Calculates the change in any two values xi and xf.
/// </summary>
/// <param name="xi">The  initial starting value.</param>
/// <param name="xf">The final value.</param>
/// <returns>the change in a value</returns>
static auto delta = []<class T>(const T xi, const T xf)
{
    return xf - xi;
};





/// <summary>
/// the Physics world class that is the driver class of many smaller more
/// specific classes. This class instantiates all them classes for use in the
/// testFactory.cpp driver file.
/// </summary>
class Physics_World
{
private:
    static void countIncrease() { physics_objectCount += 1; }
    static void countDecrease() { physics_objectCount -= 1; }

public:

    /**
     * @brief Template method to print out an array that is passed to it
     * @param array of values
     */
    template <typename T, size_t size>
    void static print_array(const T(&array)[size])
    {
        for (size_t i = 0; i < size; i++)
            cout << array[i] << " ";

        cout << endl;
    }

    unique_ptr<AtomicPhysics> atomic;
    unique_ptr<LinearAlgebra> linear_algebra;
    unique_ptr<LinearRegression<TYPE>> linear_regression;
    unique_ptr<LogisticRegression<TYPE>> logistic_regression;
    unique_ptr<ETL<TYPE>> etl;
    unique_ptr<MatrixND<TYPE>> matrixNd;
    unique_ptr<VectorND<TYPE>> vectorNd;
    unique_ptr<TriangleSolver> triangle;
    unique_ptr<Kinematics> kinematics;
    unique_ptr<Friction> friction;
    unique_ptr<Drag> drag;
    unique_ptr<Elasticity> elasticity;
    unique_ptr<UniformCircularMotion> uniformCircularMotion;
    unique_ptr<Vector2D> vector2d;
    unique_ptr<Vector3D> vector3d;
    unique_ptr<Energy> energy;
    unique_ptr<LinearMomentum> momentum;
    unique_ptr<Torque> torque;
    unique_ptr<Statics> statics;
    unique_ptr<RotationalMotion> rotationalMotion;
    unique_ptr<Temperature> temperature;
    unique_ptr<Heat> heat;
    unique_ptr<Thermodynamics> thermodynamic;
    unique_ptr<Forces> dynamics_and_forces;
    unique_ptr <FluidStatics> fluid_statics;
    unique_ptr<FluidDynamics> fluid_dynamics;
    unique_ptr<Waves> waves;
    unique_ptr<Hearing> hearing;
    unique_ptr<ElectricCharge> electric_charge;
    unique_ptr<ElectricPotential> electric_potential;
    unique_ptr<ElectricCurrent> electric_current;
    unique_ptr<Circuits> circuits;
    unique_ptr<Magnetism> magnetism;
    unique_ptr<EMI> emi;
    unique_ptr<EMW> emWaves;
    unique_ptr<GO> geometric_optics;
    unique_ptr<WO> wave_optics;
    unique_ptr<VOI> vision_optical;
    unique_ptr<SR> relativity;
    unique_ptr<QP> quantum;
    unique_ptr<Square> square;
    unique_ptr<Cube> cube;
    unique_ptr<Rectangle> rectangle;
    unique_ptr<RectangularPrism> rectangular_prism;
    unique_ptr<Cylinder> cylinder;
    unique_ptr<Cone> cone;
    unique_ptr<Sphere> sphere;
    unique_ptr<Pyramid> pyramid;
    unique_ptr<Circle> circle;
    unique_ptr<Parallelogram> parallelogram;
    unique_ptr<Point2D<TYPE>> point2d;
    unique_ptr<rez::Vector<TYPE>> vector;
    unique_ptr<Scale> scale;


    Physics_World();
    Physics_World(TYPE t1, TYPE t2, TYPE t3);
    Physics_World(TYPE t1, TYPE t2);
    Physics_World(const Physics_World&); //copy constructor
    Physics_World& operator=(const Physics_World&); //copy assignment operator
    Physics_World(Physics_World&& o) noexcept :
            atomic(std::move(o.atomic)),
            linear_algebra(std::move(o.linear_algebra)),
            linear_regression(std::move(o.linear_regression)),
            logistic_regression(std::move(o.logistic_regression)),
            etl(std::move(o.etl)),
            matrixNd(std::move(o.matrixNd)),
            vectorNd(std::move(o.vectorNd)),
            triangle(std::move(o.triangle)),
            kinematics(std::move(o.kinematics)),
            friction(std::move(o.friction)),
            drag(std::move(o.drag)),
            elasticity(std::move(o.elasticity)),
            uniformCircularMotion(std::move(o.uniformCircularMotion)),
            vector2d(std::move(o.vector2d)),
            vector3d(std::move(o.vector3d)),
            energy(std::move(o.energy)),
            momentum(std::move(o.momentum)),
            torque(std::move(o.torque)),
            statics(std::move(o.statics)),
            rotationalMotion(std::move(o.rotationalMotion)),
            temperature(std::move(o.temperature)),
            heat(std::move(o.heat)),
            thermodynamic(std::move(o.thermodynamic)),
            dynamics_and_forces(std::move(o.dynamics_and_forces)),
            fluid_statics(std::move(o.fluid_statics)),
            fluid_dynamics(std::move(o.fluid_dynamics)),
            waves(std::move(o.waves)),
            hearing(std::move(o.hearing)),
            electric_charge(std::move(o.electric_charge)),
            electric_potential(std::move(o.electric_potential)),
            electric_current(std::move(o.electric_current)),
            circuits(std::move(o.circuits)),
            magnetism(std::move(o.magnetism)),
            emi(std::move(o.emi)),
            emWaves(std::move(o.emWaves)),
            geometric_optics(std::move(o.geometric_optics)),
            wave_optics(std::move(o.wave_optics)),
            vision_optical(std::move(o.vision_optical)),
            relativity(std::move(o.relativity)),
            quantum(std::move(o.quantum)),
            square(std::move(o.square)),
            cube(std::move(o.cube)),
            rectangle(std::move(o.rectangle)),
            rectangular_prism(std::move(o.rectangular_prism)),
            cylinder(std::move(o.cylinder)),
            cone(std::move(o.cone)),
            sphere(std::move(o.sphere)),
            pyramid(std::move(o.pyramid)),
            circle(std::move(o.circle)),
            parallelogram(std::move(o.parallelogram)),
            point2d(std::move(o.point2d)),
            vector(std::move(o.vector)),
            scale(std::move(o.scale)){} // move constructor

    /**========================================================================
     * overloaded operators
     */
    Physics_World operator+(const Physics_World& r)const
    {
        long double x, y, z;
        x = vector3d->getX() + r.vector3d->getX();
        y = vector3d->getY() + r.vector3d->getY();
        z = vector3d->getZ() + r.vector3d->getZ();
        std::unique_ptr<Physics_World> sum = std::make_unique<Physics_World>();
        sum->vector3d->set_coordinates(x, y, z);
        x = vector2d->getX() + r.vector2d->getX();
        y = vector2d->getY() + r.vector2d->getY();
        sum->vector2d->setCoordinates(x, y);
        sum->vector3d->mode = r.vector3d->mode;
        sum->vector2d->mode = this->vector2d->mode;
        return *sum;
    }
    Physics_World operator+(long double n)const
    {
        long double x, y, z;
        x = vector3d->getX() + n;
        y = vector3d->getY() + n;
        z = vector3d->getZ() + n;
        std::unique_ptr<Physics_World> sum = std::make_unique<Physics_World>();
        sum->vector3d->set_coordinates(x, y, z);
        x = vector2d->getX() + n;
        y = vector2d->getY() + n;
        sum->vector2d->setCoordinates(x, y);
        sum->vector3d->mode = this->vector3d->mode;
        sum->vector2d->mode = this->vector2d->mode;
        _val_ = +n;
        return *sum;
    }

    Physics_World& operator+=(const Physics_World& r) const
    {
        long double x, y, z;
        x = vector3d->getX() + r.vector3d->getX();
        y = vector3d->getY() + r.vector3d->getY();
        z = vector3d->getZ() + r.vector3d->getZ();
        std::unique_ptr<Physics_World> sum = std::make_unique<Physics_World>();
        sum->vector3d->set_coordinates(x, y, z);
        x = vector2d->getX() + r.vector2d->getX();
        y = vector2d->getY() + r.vector2d->getY();
        sum->vector2d->setCoordinates(x, y);
        sum->vector3d->mode = r.vector3d->mode;
        sum->vector2d->mode = this->vector2d->mode;
        return *sum;

    }
    Physics_World operator+()const
    {
        long double x, y, z;
        x = vector3d->getX() + 1.0;
        y = vector3d->getY() + 1.0;
        z = vector3d->getZ() + 1.0;
        Physics_World sum;
        sum.vector3d->set_coordinates(x, y, z);
        x = vector2d->getX() + 1.0;
        y = vector2d->getY() + 1.0;
        vector2d->setCoordinates(x, y);
        vector3d->mode = this->vector3d->mode;
        vector2d->mode = this->vector2d->mode;
        _val_ += 1;

        return sum;
    }

    // destructor
    ~Physics_World();

    static void setGravity(double d);
};
#endif //PHYSICSFORMULA_PHYSICS_WORLD_H

//=============================================================================
//in-line class Implementation

/**
 *default constructor
 */
inline Physics_World::Physics_World()
{
    atomic = std::make_unique<AtomicPhysics>();
    linear_algebra = std::make_unique<LinearAlgebra>();
    linear_regression = std::make_unique<LinearRegression<TYPE>>();
    logistic_regression = std::make_unique<LogisticRegression<TYPE>>();
    etl = std::make_unique<ETL<TYPE>>();
    matrixNd = std::make_unique<MatrixND<TYPE>>();
    vectorNd = std::make_unique<VectorND<TYPE>>();
    triangle = std::make_unique<TriangleSolver>();
    kinematics = std::make_unique<Kinematics>();
    drag = std::make_unique<Drag>();
    elasticity = std::make_unique<Elasticity>();
    friction = std::make_unique<Friction>();
    uniformCircularMotion = std::make_unique<UCM>();
    vector2d = std::make_unique<Vector2D>();
    vector3d = std::make_unique<Vector3D>();
    energy = std::make_unique<Energy>();
    momentum = std::make_unique<LinearMomentum>();
    torque = std::make_unique<Torque>();
    statics = std::make_unique<Statics>();
    rotationalMotion = std::make_unique<RM>();
    temperature = std::make_unique<Temperature>();
    heat = std::make_unique<Heat>();
    thermodynamic = std::make_unique<Thermodynamics>();
    dynamics_and_forces = std::make_unique<DAF>();
    fluid_statics = std::make_unique<FS>();
    fluid_dynamics = std::make_unique<FD>();
    waves = std::make_unique<Waves>();
    hearing = std::make_unique<Hearing>();
    electric_charge = std::make_unique<ECH>();
    electric_potential = std::make_unique<EP>();
    electric_current = std::make_unique<EC>();
    circuits =std::make_unique<Circuits>();
    magnetism = std::make_unique<Magnetism>();
    emi = std::make_unique<EMI>();
    emWaves = std::make_unique<EMW>();
    geometric_optics = std::make_unique<GO>();
    wave_optics = std::make_unique<WO>();
    vision_optical = std::make_unique<VOI>();
    relativity = std::make_unique<SR>();
    quantum = std::make_unique<QP>();
    square = std::make_unique<Square>();
    cube = std::make_unique<Cube>();
    rectangle = std::make_unique<Rectangle>();
    rectangular_prism = std::make_unique<RectangularPrism>();
    cylinder = std::make_unique<Cylinder>();
    cone = std::make_unique<Cone>();
    sphere = std::make_unique<Sphere>();
    pyramid = std::make_unique<Pyramid>();
    circle = std::make_unique<Circle>();
    parallelogram = std::make_unique<Parallelogram>();
    point2d = std::make_unique<Point2D<TYPE>>();
    vector = std::make_unique <rez::Vector<TYPE>>();
    scale = std::make_unique<Scale>();
    countIncrease();
    //countShow();
}
/**
 *copy constructor
 */
inline Physics_World::Physics_World(const Physics_World& p)
{
    countIncrease();
}
/**
 *copy assignment operator
 */
inline Physics_World& Physics_World::operator=(const Physics_World& r)
{
    if(this != &r)
    {
        countIncrease();
    }
    return *this;
}

inline Physics_World::Physics_World(const TYPE t1, const TYPE t2, const TYPE t3)
{
    atomic = std::make_unique<AtomicPhysics>();
    linear_algebra = std::make_unique<LinearAlgebra>();
    linear_regression = std::make_unique<LinearRegression<TYPE>>();
    logistic_regression = std::make_unique<LogisticRegression<TYPE>>();
    etl = std::make_unique<ETL<TYPE>>();
    matrixNd = std::make_unique<MatrixND<TYPE>>();
    vectorNd = std::make_unique<VectorND<TYPE>>();
    triangle = std::make_unique<TriangleSolver>();
    kinematics = std::make_unique<Kinematics>();
    drag = std::make_unique<Drag>();
    elasticity = std::make_unique<Elasticity>();
    friction = std::make_unique<Friction>();
    uniformCircularMotion = std::make_unique<UCM>();
    vector2d = std::make_unique<Vector2D>();
    vector3d = std::make_unique<Vector3D>();
    energy = std::make_unique<Energy>();
    momentum = std::make_unique<LinearMomentum>();
    torque = std::make_unique<Torque>();
    statics = std::make_unique<Statics>();
    rotationalMotion = std::make_unique<RM>();
    temperature = std::make_unique<Temperature>();
    heat = std::make_unique<Heat>();
    thermodynamic = std::make_unique<Thermodynamics>();
    dynamics_and_forces = std::make_unique<DAF>();
    fluid_statics = std::make_unique<FS>();
    fluid_dynamics = std::make_unique<FD>();
    waves = std::make_unique<Waves>();
    hearing = std::make_unique<Hearing>();
    electric_charge = std::make_unique<ECH>();
    electric_potential = std::make_unique<EP>();
    electric_current = std::make_unique<EC>();
    circuits =std::make_unique<Circuits>();
    magnetism = std::make_unique<Magnetism>();
    emi = std::make_unique<EMI>();
    emWaves = std::make_unique<EMW>();
    geometric_optics = std::make_unique<GO>();
    wave_optics = std::make_unique<WO>();
    vision_optical = std::make_unique<VOI>();
    relativity = std::make_unique<SR>();
    quantum = std::make_unique<QP>();
    square = std::make_unique<Square>();
    cube = std::make_unique<Cube>();
    rectangle = std::make_unique<Rectangle>();
    rectangular_prism = std::make_unique<RectangularPrism>();
    cylinder = std::make_unique<Cylinder>();
    cone = std::make_unique<Cone>();
    sphere = std::make_unique<Sphere>();
    pyramid = std::make_unique<Pyramid>();
    circle = std::make_unique<Circle>();
    parallelogram = std::make_unique<Parallelogram>();
    point2d = std::make_unique<Point2D<TYPE>>();
    vector = std::make_unique <rez::Vector<TYPE>>();
    scale = std::make_unique<Scale>();
    this->vector3d->set_coordinates(t1, t2, t3);

    countIncrease();
}

inline Physics_World::Physics_World(const TYPE t1, const TYPE t2)
{
    atomic  = std::make_unique<AtomicPhysics>();
    linear_algebra = std::make_unique<LinearAlgebra>();
    linear_regression = std::make_unique<LinearRegression<TYPE>>();
    logistic_regression = std::make_unique<LogisticRegression<TYPE>>();
    etl = std::make_unique<ETL<TYPE>>();
    matrixNd = std::make_unique<MatrixND<TYPE>>();
    vectorNd = std::make_unique<VectorND<TYPE>>();
    triangle = std::make_unique<TriangleSolver>();
    kinematics = std::make_unique<Kinematics>();
    drag = std::make_unique<Drag>();
    elasticity = std::make_unique<Elasticity>();
    friction = std::make_unique<Friction>();
    uniformCircularMotion = std::make_unique<UCM>();
    vector2d = std::make_unique<Vector2D>();
    vector3d = std::make_unique<Vector3D>();
    energy = std::make_unique<Energy>();
    momentum = std::make_unique<LinearMomentum>();
    torque = std::make_unique<Torque>();
    statics = std::make_unique<Statics>();
    rotationalMotion = std::make_unique<RM>();
    temperature = std::make_unique<Temperature>();
    heat = std::make_unique<Heat>();
    thermodynamic = std::make_unique<Thermodynamics>();
    dynamics_and_forces = std::make_unique<DAF>();
    fluid_statics = std::make_unique<FS>();
    fluid_dynamics = std::make_unique<FD>();
    waves = std::make_unique<Waves>();
    hearing = std::make_unique<Hearing>();
    electric_charge = std::make_unique<ECH>();
    electric_potential = std::make_unique<EP>();
    electric_current = std::make_unique<EC>();
    circuits =std::make_unique<Circuits>();
    magnetism = std::make_unique<Magnetism>();
    emi = std::make_unique<EMI>();
    emWaves = std::make_unique<EMW>();
    geometric_optics = std::make_unique<GO>();
    wave_optics = std::make_unique<WO>();
    vision_optical = std::make_unique<VOI>();
    relativity = std::make_unique<SR>();
    quantum = std::make_unique<QP>();
    square = std::make_unique<Square>();
    cube = std::make_unique<Cube>();
    rectangle = std::make_unique<Rectangle>();
    rectangular_prism = std::make_unique<RectangularPrism>();
    cylinder = std::make_unique<Cylinder>();
    cone = std::make_unique<Cone>();
    sphere = std::make_unique<Sphere>();
    pyramid = std::make_unique<Pyramid>();
    circle = std::make_unique<Circle>();
    parallelogram = std::make_unique<Parallelogram>();
    point2d = std::make_unique<Point2D<TYPE>>();
    vector = std::make_unique <rez::Vector<TYPE>>();
    scale = std::make_unique<Scale>();
    this->vector2d->setCoordinates(t1, t2);
}

inline Physics_World::~Physics_World()
{
    countDecrease();
}

void Physics_World::setGravity(double d) {
    constants::set_Ga(d);
}
