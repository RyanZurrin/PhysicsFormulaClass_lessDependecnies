//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_FRICTION_H
#define PHYSICSFORMULA_FRICTION_H
#include <iostream>
#include <cmath>
// class for doing physics problems
// author: Ryan Zurrin
// last Modified: 10/11/2020

typedef long double ld;
//Gravitational Constant 6.67408(31) * 10^(-11) * N
constexpr auto _GRAV_CONSTANT_ =  6.67408e-11; //N m^2 kg^-2
//Acceleration due to gravity = 9.81
constexpr auto _G_ = 9.81; //m/s^2
//pi = 3.14159265359
constexpr auto _PI = 3.14159265359; //radians
// convert radian value to degrees
constexpr auto _DEGREE_ = 180 / _PI; //degrees
//convert degrees to radian value
constexpr auto _RADIAN_ = _PI / 180; //radians

//static object counter for class
static int friction_objectCount = 0;

// static friction coefficients
static struct FrictionCoefficient
{
    struct StaticCoefficient
    {
        const ld static_rubber_concrete_dry = 1.0;//returns 1.0
        const ld static_rubber_concrete_wet = .7; //returns 0.7
        const ld static_wood_wood = .5;  //returns 0.5
        const ld static_waxedWood_wetSnow = .14;  //returns 0.14
        const ld static_metal_wood = .5;  //returns 0.5
        const ld static_steel_steel_dry = .6;  //returns 0.6
        const ld static_steel_steel_oiled = .05;  //returns 0.05
        const ld static_teflon_steel = .04;  //returns 0.04
        const ld static_bone_lubricated_synovial_fluid = .016;  //returns 0.016
        const ld static_shoes_wood = .9;  //returns 0.9
        const ld static_shoes_ice = .1;  //returns 0.1
        const ld static_ice_ice = .1;  //returns 0.1
        const ld static_steel_ice = 0.4; // returns 0.4
    }static_friction_coefficient;

    // Kinetic friction coefficients
    struct KineticCoefficient
    {
        const ld kinetic_rubber_concrete_dry = .7;  //returns 0.7
        const ld kinetic_rubber_concrete_wet = .5;  //returns 0.5
        const ld kinetic_wood_wood = .3; //return 0.3
        const ld kinetic_waxedWood_wetSnow = .1;//return 0.1
        const ld kinetic_metal_wood = .3; //returns 0.3
        const ld kinetic_steel_steel_dry = .3;  //returns 0.3
        const ld kinetic_steel_steel_oiled = .03;  //return 0.03
        const ld kinetic_teflon_steel = .4;  //return 0.4
        const ld kinetic_bone_lubricated_synovial_fluid = .015; //returns 0.015
        const ld kinetic_shoes_wood = .5;  //returns 0.5
        const ld kinetic_shoes_ice = .5;  //return 0.5
        const ld kinetic_ice_ice = .03;  //return 0.03
        const ld kinetic_steel_ice = .04;  // return .04
    }kinetic_friction_coefficient;

}friction;



class Friction
{

public:
    static void countShow() { std::cout << "friction count: " << friction_objectCount << std::endl; }
    Friction* _ptrFriction;

    void set_frictionalCoefficient(const ld fC) { _frictionCoefficient_ = fC; }
    ld return_frictionCoefficient()const { return _frictionCoefficient_; }
    void show_frictionalCoefficient()const { std::cout << "frictional coefficient: " << return_frictionCoefficient() << std::endl; }


    // constructor
    Friction()
    {
        _ptrFriction =  nullptr;
        _frictionCoefficient_ = 0.0;
        _frictionVal = 0.0;
        countIncrease();
        //countShow();
    }
    Friction(ld val)
    {
        _ptrFriction =  nullptr;
        _frictionCoefficient_ = 0.0;
        _frictionVal = 0.0;
        countIncrease();
    }

    Friction(ld fC, char mode)
    {
        _ptrFriction = nullptr;
        _frictionCoefficient_ = fC;
        _frictionVal = 0.0;
        countIncrease();
        //countShow();
    }

    // copy constructor
    Friction(const Friction& f)
    {
        _ptrFriction = f._ptrFriction;
        _frictionCoefficient_ = f.return_frictionCoefficient();
        _frictionVal = f._frictionVal;
        countIncrease();
        //countShow();
    }

    /**
     * Returns the calculated force of friction, which is the same as the force
     * @param mass
     * @param coefficient of friction
     * @returns frictional force
     */
    static ld friction_force(const ld mass,  const ld coefficient)
    {
        return coefficient * mass * _G_;
    }

    /**
     * Returns the friction coefficient using the Normal Force and the Friction Force as known data
     * @param normalForce is the amount of normal force found by multiplying mass(kg) * 9.8 (m/s^2)
     * @param frictionForce is the amount of force the friction is pushing back against something.
     * @returns the frictional coefficient of objects in question
     */
    static ld friction_coefficient(const ld normalForce, const ld frictionForce)
    {
        return (frictionForce) / (normalForce);
    }

    /**
     * Returns the acceleration of an object taking into account its mass and the frictional coefficient
     * of the materials.
     * @param mass in kg
     * @param frictionCoefficient of the materials
     * @returns magnitude of the acceleration of an object
     */
    static ld acceleration_magnitude(const ld mass, const ld frictionCoefficient)
    {
        const ld normalForce = mass * _G_;
        const ld frictionForce = normalForce * frictionCoefficient;
        return frictionForce / mass;
    }

    /**
     * Returns the initial velocity when giving the amount of time it takes something
     * to come to a stop
     * @param mass of object in kg
     * @param frictionCoefficient for the materials in consideration
     * @param time in seconds it took to come to a stop
     * @returns initial velocity
     */
    static ld initial_velocity(const ld mass, const ld frictionCoefficient, const ld time)
    {
        const ld normalForce = mass * _G_;
        const ld frictionForce = normalForce * frictionCoefficient;
        const ld acceleration = frictionForce / mass;
        return acceleration * time;
    }

    /**
     * method: acceleration_slope_friction(const ld angleTheta, const ld kineticCoefficient)
     * arguments: 1)angleTheta 2)kineticCoefficient
     * purpose: calculates the normal force on an angle
     * returns: ld, normal force
     */
    static ld acceleration_down_slope_friction(const ld angleTheta, const ld kineticCoefficient)
    {
        return _G_ * (sin(angleTheta * _RADIAN_) - (kineticCoefficient * cos(angleTheta * _RADIAN_)));
    }

    /**
     * method: acceleration_up_slope_friction(const ld angleTheta, const ld frictionalCoefficient)
     * arguments: 1)angleTheta 2)frictionalCoefficient
     * purpose: calculates the acceleration of an object going up a slope, like a 4 wheel drive car
     * returns: ld, acceleration
     */
    static ld acceleration_up_slope_friction(const ld angleTheta, const ld frictionalCoefficient)
    {
        return _G_ * ((frictionalCoefficient*cos(angleTheta * _RADIAN_) - sin(angleTheta*_RADIAN_)));
    }

    /**
     * method: car2wheel_acceleration_up_slope_friction(const ld angleTheta, const ld kineticCoefficient)
     * arguments: 1)angleTheta 2)kineticCoefficient
     * purpose: calculates the normal force on an angle
     * returns: ld, normal force
     */
    static ld car2wheel_acceleration_up_slope_friction(const ld angleTheta, const ld kineticCoefficient)
    {
        return _G_ * ((kineticCoefficient*cos(angleTheta*_RADIAN_)/2)-(sin(angleTheta * _RADIAN_)));
    }

    /**
     * method: tension_rope_rockClimber(const ld angleRope, const ld angleLegs,  const ld mass)
     * arguments: 1)angleRope 2)angleLegs 3)mass
     * purpose: calculates the tension on a rope from a hanging rock climber or similar situation
     * returns: ld, tension force
     */
    static ld tension_rope_rockClimber(const ld angleRope, const ld angleLegs,  const ld mass)
    {
        return (mass * _G_) / (cos(angleRope*_RADIAN_) + sin(angleRope*_RADIAN_) * tan(angleLegs*_RADIAN_));
    }

    /**
     * method:  tension_legs_rockClimber(const ld angleRope, const ld angleLegs, const ld mass)
     * arguments: 1)angleRope 2)angleLegs 3)mass
     * purpose: calculates the tension on a rope from a hanging rock climber or similar situation
     * returns: ld, tension force on legs
     */
    static ld tension_legs_rockClimber(const ld angleRope, const ld angleLegs, const ld mass)
    {
        return (tension_rope_rockClimber(angleRope, angleLegs, mass)*sin(angleRope*_RADIAN_)/cos(angleLegs*_RADIAN_));
    }

    /**
     * method:  minimum_force_start_move_push(const ld mass, const ld pushAngle, const ld frictionCoefficient)
     * arguments: 1)mass 2)pushAngle 3)frictionCoefficient
     * purpose: calculates the minimum force it takes to start moving an object pushing at a downward angle
     * returns: ld, minimum force to start moving block
     */
    static ld minimum_force_start_move_downPush(const ld mass, const ld pushAngle, const ld staticCoefficient)
    {
        return (staticCoefficient * mass*_G_) / (cos(pushAngle*_RADIAN_)- staticCoefficient * sin(pushAngle*_RADIAN_));
    }

    /**
     * method:  magnitude_acceleration_moving_object_downPush(const ld mass, const ld pushAngle, const ld frictionCoefficient)
     * arguments: 1)mass 2)pushAngle 3)frictionCoefficient
     * purpose: calculates the acceleration of the object once it starts moving if force is maintained
     * returns: ld, acceleration
     */
    static ld magnitude_acceleration_moving_object_downPush(const ld mass, const ld pushAngle, const ld kineticCoefficient, const ld staticCoefficient)
    {
        return ((minimum_force_start_move_downPush(mass, pushAngle, staticCoefficient) * cos(pushAngle*_RADIAN_) - kineticCoefficient *sin(pushAngle*_RADIAN_))-(kineticCoefficient)*mass*_G_)/(mass);
    }

    /**
     * method:   minimum_force_start_move_upPull(const ld mass, const ld pullAngle, const static ldCoefficient)
     * arguments: 1)mass 2)pushAngle 3)frictionCoefficient
     * purpose: calculates the minimum force it takes to start moving an object pulling on it upward by a rope
     * returns: ld, minimum force to start moving block fro pulling up
     */
    static ld minimum_force_start_move_upPull(const ld mass, const ld pullAngle, const ld staticCoefficient)
    {
        return (staticCoefficient*mass*_G_)/(cos(pullAngle*_RADIAN_) + staticCoefficient*sin(pullAngle*_RADIAN_));
    }

    /**
     * method:  magnitude_acceleration_moving_object_pullingUp(const ld mass, const ld pullAngle, const ld kineticCoefficient)
     * arguments: 1)mass 2)pushAngle 3)frictionCoefficient
     * purpose: calculates the minimum force it takes to start moving an object pulling on it upward by a rope
     * returns: ld, minimum force to start moving block fro pulling up
     */
    static ld magnitude_acceleration_moving_object_pullingUp(const ld mass, const ld pullAngle, const ld kineticCoefficient, const ld maintainingForce)
    {
        ld a, b;
        a = maintainingForce * cos(pullAngle * _RADIAN_);
        b = kineticCoefficient * ((mass * _G_) - maintainingForce * sin(pullAngle * _RADIAN_));
        return  (a-b)/(mass);
    }

    void setFrictionVal(ld val) { _frictionVal = val; }

    // destructor
    ~Friction()
    {
        delete _ptrFriction;
        countDecrease();
        //countShow();
    }

private:
    ld _frictionCoefficient_;
    ld _frictionVal;
    static void countIncrease() { friction_objectCount += 1; }
    static void countDecrease() { friction_objectCount -= 1; }

};

#endif //PHYSICSFORMULA_FRICTION_H
