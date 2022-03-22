//
// Created by Ryan.Zurrin001 on 12/15/2021.
//

#ifndef PHYSICSFORMULA_DRAG_H
#define PHYSICSFORMULA_DRAG_H
// Drag class for extending the physics class
// author: Ryan Zurrin
// last Modified: 10/10/2020
#include <algorithm>
#include <iostream>
#include "Friction.h"
#include "Vector2D.h"

//drag objects static counter
static int drag_objectCount = 0;

static constexpr  struct DragCoefficients
{
    const long double toyotaCamry = .28; // returns .28
    const long double fordFocus = .32; // returns .32
    const long double hodnaCivic = .36; // returns .36
    const long double ferrariTestarossa = .37; // returns .37
    const long double dodgeRamPickup = .43; // returns .43
    const long double sphere = .45; // returns.45
    const long double hummerH2SUV = .64; // returns .64
    const long double skyDiver_feetFirst = .70; // returns .70
    const long double bicycle = .90; // returns .90
    const long double skyDiver_horizontal = 1.0; // returns  1.0
    const long double circularFlatPlate = 1.12; // returns 1.12
    const long double dolphin = .0036; // returns .0036
    const long double bird = .4; // returns .4
    const long double frisbee = .080; // returns .080
    const long double rectangularBox = 2.1; //returns 2.1
    const long double longFlatPlate90deg = 1.98; // returns 1.98
    const long double motorcycleAndRider = 1.8; // returns 1.8
    const long double personUpright = 1.15; // returns 1.15
    const long double convertibleOpenTop = .65; // returns .65
    const long double supersonicFighter = .016; // returns .016
    const long double solarPanelArray6x4 = 4.1; // returns 4.1


}drag_coefficients;

class Drag:
        public Friction
{

private:
    static void countIncrease() { drag_objectCount += 1; }
    static void countDecrease() { drag_objectCount -= 1; }
    long double _dragForce_;
    long double _dragCoefficient_;
    long double _dragVal;

public:
    static void countShow() { std::cout << "drag count: " << drag_objectCount << std::endl; }
    Drag* _ptrDrag;

    /**
     * @brief displays the data stored in the dragForce variable
     */
    void show_dragForce()const { std::cout << "drag force: " << _dragForce_ << std::endl; }
    /**
     * @brief displays the data stored in the dragCoefficient variable
     */
    void show_dragCoefficient()const { std::cout << "drag coefficient: " << _dragCoefficient_ << std::endl; }

    /**
     * @brief sets the dragForce variable;
     */
    void set_dragForce(const long double dF) { _dragForce_ = dF; }
    /**
     * @brief sets the dragCoefficient variable;
     */
    void set_dragCoefficient(const long double C) { _dragCoefficient_ = C; }

    void setDragVal(long double val) { _dragVal = val; }


    //suppresses the default constructor
    Drag()
    {
        _ptrDrag =  nullptr;
        _dragForce_ = 0.0;
        _dragCoefficient_ = 0.0;
        _dragVal = 0.0;
        countIncrease();
        //countShow();
    }
    Drag(string obj)
    {

        _ptrDrag = nullptr;
        _dragForce_ = 0.0;
        _dragVal = 0.0;
        _dragCoefficient_ = setCoefficient(obj);
        countIncrease();
    }

    Drag(long double dC)
    {
        _ptrDrag = nullptr;
        _dragForce_ = 0.0;
        _dragCoefficient_ = dC;
        _dragVal = 0.0;
        countIncrease();
    }

    //copy constructor
    Drag(const Drag& r)
    {
        _ptrDrag = r._ptrDrag;
        _dragForce_ = r._dragForce_;
        _dragCoefficient_ = r._dragCoefficient_;
        _dragVal = r._dragVal;
        countIncrease();
        //countShow();
    }

    //copy assignment operator
    Drag& operator=(const Drag& r)
    {
        if (this != &r)
        {
            _dragForce_ = r._dragForce_;
            _ptrDrag = r._ptrDrag;
            _dragCoefficient_ = r._dragCoefficient_;
            _dragVal = r._dragVal;
            countIncrease();
            //countShow();
        }
        return *this;
    }
private:
    static long double setCoefficient(string &test)
    {
        long double val = 0;
        transform(test.begin(), test.end(), test.begin(), ::tolower);
        if (test == "airfoil") { return val = .05; }
        if (test == "toyotacamry" || test == "toyota camry") { return val = .28; }
        if (test == "fordfocus" || test == "Ford focus") { return val = .32; }
        if (test == "hodnacivic") { return val = .36; }
        if (test == "ferrariTestarossa") { return val = .37; }
        if (test == "dodgeRamPickup") { return val = .43; }
        if (test == "sphere") { return val = .45; }
        if (test == "hummerH2SUV") { return val = .64; }
        if (test == "skyDiverFeetFirst" || test == "skyDiverff") { return val = .70; }
        if (test == "skyDiver_horizontal") { return val = 1.0; }
        if (test == "bicycle") { return val = .90; }
        if (test == "dolphin") { return val = .0036; }
        if (test == "bird") { return val = .4; }
        if (test == "frisbee") { return val = .080; }
        if (test == "rectangularBox") { return val = 2.1; }
        if (test == "longFlatPlate90deg") { return val = 1.98; }
        if (test == "motorcycleAndRider") { return val = 1.8; }
        if (test == "personUpright") { return val = 1.15; }
        if (test == "convertibleOpenTop") { return val = .65; }
        if (test == "supersonicFighter") { return val = .016; }
        if (test == "solarPanels") { return val = 4.1; }
        else
            val = stod(test);

        return val;
    }

public:
    /**
     * @brief Returns the value in the dragForce variable
     * @returns dragForce
     */
    long double return_dragForce()const { return _dragForce_; }

    /**
     * @brief Returns the value in the dragCoefficient variable
     * @returns drag coefficient
     */
    long double return_dragCoefficient()const { return _dragCoefficient_; }

    /**
     * @brief Returns the terminal velocity from drag force equation.
     * fx = sqrt((2 * (mass * acceleration))/(density * dragCoeff * areaFace))
     * @param mass of the object
     * @param dragCoeff is the drag coefficient
     * @param areaFace is the area the drag is working against
     * @param density of the material falling
     * @param acceleration is default to gravity 9.8
     * @returns the terminal velocity.
     */
    static long double terminal_velocity(const long double mass,
                                         const long double dragCoeff,
                                         const long double areaFace,
                                         const long double density,
                                         const long double acceleration = 9.8)
    {
        return sqrt((2 * (mass * acceleration))/(density * dragCoeff * areaFace));
    }

    /**
     * @brief Returns the drag force experienced by an object.
     * fx =.5 * (dragCoeff * density * areaFace * pow(velocity, 2))
     * @param dragCoeff can be found with tables or by computation
     * @param areaFace is total area being effected by drag and resistance
     * @param density of the moving object
     * @param velocity is the speed with a direction
     * @returns: drag force
     */
    static long double drag_force(const long double dragCoeff, const long double areaFace, const long double density, const long double velocity)
    { return .5 * (dragCoeff * density * areaFace * pow(velocity, 2)); }

    /**
     * @brief Returns the frictional force – also called drag force – exerted on spherical objects with very
     * small Reynolds numbers in a viscous fluid. fx = 6 * PI * radius * viscosity * velocity
     * @param radius of object
     * @param viscosity of fluid
     * @param velocity of object in fluid
     * @returns force of sphere moving through a viscous matter
     */
    static long double stokes_law(const long double radius, const long double viscosity, const long double velocity)
    { return 6.0 * _PI_ * radius * viscosity * velocity; }

    /**
     * @brief Returns the viscosity of a fluid by using the time it takes an objects with
     * know density and diameter.
     * fx = (2 * density * time * (radius * radius) * _G_) / (9 * distance)
     * @param density of object being measured
     * @param diameter of the object
     * @param distance the object is falling through the fluid
     * @param time it takes in seconds for the objects to reach bottom
     * @returns the viscosity of a fluid
     */
    static long double viscosity(const long double density, const long double diameter, const long double distance, const long double time)
    {
        const long double radius = diameter / 2;
        return (2 * density * time * (radius * radius) * _Ga_) / (9 * distance);
    }


    /**
     * destructor
     */
    ~Drag()
    {
        delete _ptrDrag;
        countDecrease();
        //countShow();
    }

};
#endif //PHYSICSFORMULA_DRAG_H


