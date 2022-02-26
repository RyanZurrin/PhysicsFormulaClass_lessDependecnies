//
// Created by Ryan.Zurrin001 on 12/15/2021.
//

#ifndef PHYSICSFORMULA_FORCES_H
#define PHYSICSFORMULA_FORCES_H
#pragma once
/**
 * @class Forces
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @date   10/15/2020
 */
#include <iostream>
#include <vector>
#include "Vector2D.h"
constexpr auto GA = 9.81;

static int forces_objectCount = 0;


class Forces
{

public:

    Forces()
    {
        _force = 0.0;
        _mass = 0.0;
        _acceleration = 0.0;
        _angle = 0.0;
        countIncrease();
    }
    /**
     * @brief constructor for Forces
     * @param mass
     * @param acceleration
     */
    Forces(double mass_force, double acc_angle, const string& type = "force")
    {
        if (type == "force")
        {
            _force = mass_force;
            _mass = 0.0;
            _acceleration = 0.0;
            _angle = acc_angle;
        }
        else
        {
            _mass = mass_force;
            _force = mass_force * acc_angle;
            _acceleration = acc_angle;
            _angle = 0.0;
        }
        countIncrease();
    }
    Forces(double mass, double acceleration, double angle) {
        _mass = mass;
        _acceleration = acceleration;
        _force = _mass * _acceleration;
        _angle = angle;
        countIncrease();
    }
    /**
     * @brief copy constructor
     */
    Forces(const Forces& t)
    {
        _force = t._force;
        _mass = t._mass;
        _acceleration = t._acceleration;
        _angle = t._angle;
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    Forces(Forces&& t) noexcept
    {
        _force = t._force;
        _mass = t._mass;
        _acceleration = t._acceleration;
        _angle = t._angle;
        countIncrease();
    }
    /**
     * @brief copy assignment operator
     */
    Forces& operator=(const Forces& t)
    {
        if (this != &t)
        {
            _force = t._force;
            _mass = t._mass;
            _acceleration = t._acceleration;
            _angle = t._angle;
            countIncrease();
        }
        return *this;
    }

    static void show_forces_objectCount() { std::cout << "\ndynamics and forces object count: "
    << forces_objectCount << std::endl; }
    static int get_forces_objectCount() { return forces_objectCount; }
    void setForce(long double val) { _force = val; }
    [[nodiscard]] long double getForce() const { return _force; }
    void setMass(long double val) { _mass = val; }
    [[nodiscard]] long double getMass() const { return _mass; }
    void setAcceleration(long double val) { _acceleration = val; }
    [[nodiscard]] long double getAcceleration() const { return _acceleration; }
    void setAngle(long double val) { _angle = val; }
    [[nodiscard]] long double getAngle() const { return _angle; }
    [[nodiscard]] string toString() const
    {
        stringstream ss;
        ss << "Force: " << _force << " N\n"
        << "Mass: " << _mass << " kg\n"
        << "Acceleration: " << _acceleration << " m/s^2\n"
        << "Angle: " << _angle*DEGREE << " degrees\n";
        return ss.str();
    }

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
    static long double force(const long double mass, const long double acceleration)
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
    static auto acceleration(const T F, const T m)
    {
        return F / m;
    }

    /**
     * method: newtons_second_law_for_mass(long double netForce, long double acceleration) const
     * arguments: netForce, acceleration
     * purpose:calculates the mass of an object from the force and acceleration
     * returns: long double, mass
     */
    static long double mass(long double netForce, long double acceleration)
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
     * method: normal_force
     * _angle(const long double mass, const long double angleTheta)
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
        const long double friction_ = fCoeff * Nf;
        const long double accF = mass * a;
        return friction_ + accF;
    }

    /**
     * @brief calculates the tension on a horizontal rope as it gets hung from
     * @param mass1 in kg of object1
     * @param mass2 in kg of object2
     * @returns tension in Newtons
     */
    static long double tensionOnMultipleStrandsIdealPulley(const long double mass1, const long double mass2)
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
    static vector<long double>
    tensionOnMultipleStrandsHangingObject(const long double mass, const long double theta1,
                                          const long double theta2, bool print = false)
    {
        vector<long double> result = { 0.0, 0.0, 0.0 };
        auto mg = mass * GA;
        auto T1x = cos(theta1 * RADIAN);
        auto T1y = sin(theta1 * RADIAN);
        auto T2x = cos(theta2 * RADIAN);
        auto T2y = sin(theta2 * RADIAN);
        auto T2 = T1x/T2x;
        auto temp = T2y*T2+T1y;
        auto T1_tot = mg/temp;
        auto T2_tot = T1_tot*T2;
        result[0] = T1_tot;
        result[1] = T2_tot;
        result[2] = T1_tot + T2_tot;

        if (print)
        {
            cout << "Tension on side 1: " << result[0] << endl;
            cout << "Tension on side 2: " << result[1] << endl;
            cout << "Tension on both sides: " << result[2] << endl;
        }
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

    /**
     * @brief In a front-end collision, a car of mass m with shock-absorbing bumpers can
     * withstand a maximum force of f before damage occurs. If the maximum speed
     * for a non-damaging collision is v by how much must the bumper be able to
     * move relative to the car?
     * @param m mass of car
     * @param f maximum force of impact on car bumper
     * @param v maximum speed of car
     * @returns the maximum distance the bumper can move
     */
     static long double maxCompression(const long double m, const long double f, const long double v)
     {
         return (v*v)/(2.0*(f/m));
     }

     /**
      * Find an expression for the thrust (force) of a model rocket's engine required
      * to accelerate a spacecraft of total mass m from rest on the ground to speed v
      * while rising a vertical distance h.
      * @param m total mass of spacecraft
      * @param v speed of spacecraft
      * @param h vertical distance of spacecraft
      * @returns the thrust of the rocket's engine
      */
     static long double rocketThrust(const long double m, const long double v, const long double h)
     {
         return m*(GA*((v*v)/(2.0*h)));
     }
     /**
      * Two forces, both in the x-y plane, act on a object of mass m (M) that
      * accelerates at acc (L/T^2) in a direction theta counterclockwise from
      * the x-axis. One force has magnitude F_1 and points in the +x-direction.
      * Find the other force F_2 magnitude and direction.
      * @param m mass of object
      * @param acc acceleration of object
      * @param theta angle of object
      * @param F1 magnitude of force 1
      * @returns a vector with the magnitude and direction of force 2
      */
     static vector<long double>
     forceOnObject(const long double m, const long double acc, const long double theta,
                   const long double F1, bool print = false){
         vector<long double> result = { 0.0, 0.0};
         auto ax = (m*acc*cos(theta*RADIAN) - F1);
         auto ay = (m*acc*sin(theta*RADIAN));
         auto F2 = sqrt(ax*ax + ay*ay);
         auto theta2 = atan2(ay, ax)*DEGREE;
         if(print){
             cout << "F2 = " << F2 << endl;
             cout << "theta = " << theta2 << endl;
         }
         result[0] = F2;
         result[1] = theta2;
         return result;
     }

     /**
      * Two forces act on a object of mass m(M) that undergoes acceleration
      * ai and aj. If one force is F1i and F1j what's the i and j components
      * as well as the magnitude and direction of the other force?
      */
     static vector<long double>
     forceOnObject(const long double m, const long double ai, const long double aj,
                   const long double F1i, const long double F1j, bool print = false){
         vector<long double> result = { 0.0, 0.0, 0.0, 0.0};
         auto F2i = (m*ai) - F1i;
         auto F2j = (m*aj) - F1j;
         auto F2 = sqrt(F2i*F2i + F2j*F2j);
         auto theta2 = atan2(F2j, F2i)*DEGREE;
         if(print){
             cout << "F2 = " << F2 << endl;
             cout << "theta = " << theta2 << endl;
             cout << "F2i = " << F2i << endl;
             cout << "F2j = " << F2j << endl;
         }
         result[0] = F2;
         result[1] = theta2;
         result[2] = F2i;
         result[3] = F2j;
         return result;
     }

     /**
      * At what angle should you tilt an air table (on Earth) to simulate free
      * fall at the surface of some other planet, with an acceleration of g?
      * @param g acceleration of gravity on other planet
      * @return  angle of tilt
      */
     static long double tiltAngle(const long double g, bool print = false){
         auto theta = asin(g/GA)*DEGREE;
         if(print){
             cout << "theta = " << theta << endl;
         }
         return theta;
     }

     /**
      * A skier starts from rest at the top of a slope at angel of theta and that
      *  is d long. Neglecting friction, how long does it take to reach the bottom?
      */
     static long double skierTime(const long double theta, const long double d, bool print = false){
         auto a = GA*sin(theta*RADIAN);
         auto t = sqrt(2.0*d/a);
         if(print){
             cout << "t = " << t << endl;
         }
         return t;
     }

     /**
      * @brief Your baby sister of mass m_s(M) pulls on the bottom of the tablecloth with
      * all her weight. On the table, distance d(L) from the edge, is a roast
      * turkey of mass m_t(M). \n
      * (a) What's the turkey's acceleration?
      * (b) From the time your sister starts pulling, how long do you have to
      * intervene before the turkey goes over the edge? Neglect friction.
      */
     static vector<long double> tablecloth(const long double m_s, const long double m_t, const long double d, bool print = false){
         vector<long double> result = { 0.0, 0.0};
         auto a = (m_s*GA)/(m_s+m_t);
         auto t = sqrt(2.0*d/a);
         if(print){
             cout << "acceleration = " << a << endl;
             cout << "time to save = " << t << endl;
         }
         result[0] = a;
         result[1] = t;
         return result;
     }

     static long double
     acceleration2masses(const long double m_1, const long double theta_1,
                         const long double m_2, const long double theta_2,
                         bool print = false){
         auto a =
                 ((m_1*GA*sin(theta_1*RADIAN)) + (m_2*GA*sin(theta_2*RADIAN)))
                 / (m_1+m_2);
         if(print){
             cout << "acceleration = " << a << endl;
         }
         return a;
     }

     static long double
     forceToKeepMassInCircularPath(const long double m, const long double r,
                                   const long double periodT, bool print = false){
         auto F = (4.0*(PI_*PI_)*m*r)/(periodT*periodT);
         if(print){
             cout << "F = " << F << endl;
         }
         return F;
     }


    Forces operator+(const Forces& other) const
    {
        Forces result;
        // add two forces using the triangular method a2 = b2 + c2 - 2*b*c*Cos (A)
        auto ax = this->_force * cos(this->_angle*RADIAN);
        auto ay = this->_force * sin(this->_angle*RADIAN);
        auto bx = other._force * cos(other._angle*RADIAN);
        auto by = other._force * sin(other._angle*RADIAN);
        auto totX = ax + bx;
        auto totY = ay + by;
        result._force = sqrt(totX * totX + totY * totY);
        result._angle = atan2(totY, totX);
        return result;
    }
    // overload the - operator to subtract two Forces objects
    Forces operator-(const Forces& other) const
    {
        Forces result;
        // subtract two forces using the triangular method a2 = b2 + c2 - 2*b*c*Cos (A)
        auto ax = this->_force * cos(this->_angle*RADIAN);
        auto ay = this->_force * sin(this->_angle*RADIAN);
        auto bx = other._force * cos(other._angle*RADIAN);
        auto by = other._force * sin(other._angle*RADIAN);
        auto totX = ax - bx;
        auto totY = ay - by;
        result._force = sqrt(totX * totX + totY * totY);
        result._angle = atan2(totY, totX);
        return result;
    }


    ~Forces()
    {
        countDecrease();
    }
    // overload the << operator
    friend ostream& operator<<(ostream& os, const Forces& f) {
        os << "Forces: " << endl;
        os << f.toString();
        return os;
    }


private:
    long double _force;
    long double _acceleration;
    long double _mass;
    long double _angle;
    static void countIncrease() { forces_objectCount += 1; }
    static void countDecrease() { forces_objectCount -= 1; }

};

#endif //PHYSICSFORMULA_FORCES_H
