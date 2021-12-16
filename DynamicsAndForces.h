//
// Created by Ryan.Zurrin001 on 12/15/2021.
//

#ifndef PHYSICSFORMULA_DYNAMICSANDFORCES_H
#define PHYSICSFORMULA_DYNAMICSANDFORCES_H
#pragma once
/**
 * @class DynamicsAndForces
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @date   10/15/2020
 */
#include <iostream>
#include <vector>
#include "Vector2D.h"
constexpr auto GA = 9.81;

static int dynamicsAndForces_objectCount = 0;


class DynamicsAndForces
{

public:
    DynamicsAndForces* _dynamicForcePtr;

    DynamicsAndForces()
    {
        _dynamicForcePtr = nullptr;
        _dynamicForceVal = 0.0;
        countIncrease();
    }

    /**
     * @brief copy constructor
     */
    DynamicsAndForces(const DynamicsAndForces& t)
    {
        _dynamicForcePtr = t._dynamicForcePtr;
        _dynamicForceVal = t._dynamicForceVal;
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    DynamicsAndForces(DynamicsAndForces&& t) noexcept
    {
        _dynamicForcePtr = t._dynamicForcePtr;
        _dynamicForceVal = t._dynamicForceVal;
        countIncrease();
    }
    /**
     * @brief copy assignment operator
     */
    DynamicsAndForces& operator=(const DynamicsAndForces& t)
    {
        if (this != &t)
        {
            _dynamicForcePtr = t._dynamicForcePtr;
            _dynamicForceVal = t._dynamicForceVal;
            countIncrease();
        }
        return *this;
    }

    static void show_dynamicsAndForces_objectCount() { std::cout << "\ndynamics and forces object count: " << dynamicsAndForces_objectCount << std::endl; }
    static int get_dynamicsAndForces_objectCount() { return dynamicsAndForces_objectCount; }
    void setDynamicForceVal(long double val) { _dynamicForceVal = val; }

    /**
     * method: netForce(const long double totalForces, const long double totalFriction)
     * arguments: 1)total forces  2)total friction
     * purpose:	calculates the forces total including frictions
     * returns: long double net force
     */
    static long double netForce(const long double totalForces, const long double totalFriction)
    {
        return totalForces - totalFriction;
    }

    /**
     * method: gravitational_force_on_mass(long double mass) const
     * arguments: mass
     * purpose:	applies the force of gravity on a mass to give the weight
     * returns: long double weight
     */
    static long double weight(const long double mass)
    {
        return mass * GA;
    }

    /**
     * method: newtons_second_law_for_force(long double mass, long double acceleration)
     * arguments: long double mass, long double acceleration
     * purpose:	uses Newtons second law of motion to calculate the force of a something
     * returns: long double, force
     */
    static long double newtons_second_law_for_force(const long double mass, const long double acceleration)
    {
        return mass * acceleration;
    }

    /// <summary>
    /// Calculates acceleration from force and mass.
    /// </summary>
    /// <param name="F">The force in Newtons.</param>
    /// <param name="m">The mass.</param>
    /// <returns>acceleration</returns>
    template<typename T>
    static auto acceleration_from_force_mass(const T F, const T m)
    {
        return F / m;
    }

    /**
     * method: newtons_second_law_for_mass(long double netForce, long double acceleration) const
     * arguments: netForce, acceleration
     * purpose:calculates the mass of an object from the force and acceleration
     * returns: long double, mass
     */
    static long double newtons_second_law_for_mass(long double netForce, long double acceleration)
    {
        return netForce / acceleration;
    }

    /**
     * method: drag_force(const long double appliedForce, const long double mass, const long double acceleration)
     * arguments: 1)appliedForce 2)mass 3)acceleration
     * purpose:calculates the drag or resistance
     * returns: long double, drag
     */
    static long double drag_force(const long double appliedForce, const long double mass, const long double acceleration)
    {
        return appliedForce - (mass * acceleration);
    }

    /**
     * method: normal_force(const long double mass, const long double acceleration = GA)
     * arguments: 1)mass 2)acceleration
     * purpose: calculates the normal force, weight
     * returns: long double, normal force
     */
    static long double normalForce(const long double mass, const long double acceleration = GA)
    {
        return mass * acceleration;
    }

    /**
     * method: normal_force_angle(const long double mass, const long double angleTheta)
     * arguments: 1)mass 2)acceleration
     * purpose: calculates the normal force on an angle
     * returns: long double, normal force
     */
    static long double normalForce_angleDOWN(const long double mass, const long double angleTheta)
    {
        return mass * GA * cos(angleTheta * RADIAN);
    }
    /**
     * method: normal_force_angleUp(const long double mass, const long double angleTheta)
     * arguments: 1)mass 2)acceleration
     * purpose: calculates the normal force on an angle
     * returns: long double, normal force
     */
    static long double normalForce_angleUP(const long double mass, const long double angleTheta)
    {
        return mass * GA * sin(angleTheta * RADIAN);
    }

    /**
     * @brief calculates the normal force on an angle
     * @param angleTheta angle in degrees
     * @param kC kineticCoefficient
     * @returns long double, normal force
     */
    static long double acceleration_slope_simpleFriction(const long double angleTheta, const long double kC)
    {
        return GA * (sin(angleTheta * RADIAN) - (kC * cos(angleTheta * RADIAN)));
    }

    /**
     * @brief finds the ratio between two numbers
     * @param top is the top part of the ratio
     * @param bottom is the bottom part of the ratio
     * @returns the ratio between two numbers
     */
    static long double ratio(const long double top, const long double bottom)
    {
        return top / bottom;
    }

    /**
     * @brief calculates the tension on a horizontal rope as it gets hung from
     * @param mass in kg of object causing tension
     * @returns tension in Newtons
     */
    static long double tensionOnSingleStrand(const long double mass)
    {
        return mass * GA;
    }

    /**
     * @brief calculates the tension on a horizontal rope as it gets hung from
     * @param mass in kg of object causing tension
     * @param a acceleration m/s
     * @returns tension in Newtons
     */
    static long double tensionOnSingleStrandWithAccelerationUpward(const long double mass, const long double a)
    {
        return (mass * GA) + (mass * a);
    }

    /**
     * @brief calculates the tension on a horizontal rope as it gets hung from
     * @param mass in kg of object causing tension
     * @param fCoeff kinetic frictional coefficient
     * @param a acceleration m/s
     * @returns tension in Newtons
     */
    static long double tensionOnSingleStrandWithFrictionWhileAccelerating(const long double mass, const long double fCoeff, const long double a)
    {
        const long double Nf = mass * GA;
        const long double friction = fCoeff * Nf;
        const long double accF = mass * a;
        return friction + accF;
    }

    /**
     * @brief calculates the tension on a horizontal rope as it gets hung from
     * @param mass1 in kg of object1
     * @param mass2 in kg of object2
     * @returns tension in Newtons
     */
    static long double tensionOnMultipleStrandsIdealPully(const long double mass1, const long double mass2)
    {
        return ((2.0*GA)*(mass1*mass2))/(mass1 + mass2);
    }


    /**
     * @brief calculates the tension on a horizontal rope as it gets hung from
     * @param mass in kg of object1
     * @param theta1 angle side 1 in degrees
     * @param theta2 angle side 2 in degrees
     * @returns tension in Newtons
     */
    static vector<long double> tensionOnMultipleStrandsHangingObject(const long double mass, const long double theta1, const long double theta2)
    {
        vector<long double> result = { 0.0, 0.0, 0.0 };
        result[0] = cos(theta1 * RADIAN) * (mass * GA);
        result[1] = cos(theta2 * RADIAN) * (mass * GA);
        result[2] = result[0] + result[1];
        return result;
    }
    /**
     * @brief calculates the tension on a horizontal rope as it gets hung from
     * @param mass1 in kg of object1
     * @param mass2 in kg of object2
     * @returns tension in Newtons
     */
    static long double tensionOnCableMultipleStrandsMiddle(const long double mass, const long double theta)
    {
        return (mass * GA)/(2.0*sin(theta*RADIAN));
    }

    ~DynamicsAndForces()
    {
        delete _dynamicForcePtr;
    }

private:
    long double _dynamicForceVal;
    static void countIncrease() { dynamicsAndForces_objectCount += 1; }
    static void countDecrease() { dynamicsAndForces_objectCount -= 1; }

};

#endif //PHYSICSFORMULA_DYNAMICSANDFORCES_H
