//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_UNIFORMCIRCULARMOTION_H
#define PHYSICSFORMULA_UNIFORMCIRCULARMOTION_H
// class for doing physics problems
// author: Ryan Zurrin
// last Modified: 2/5/2022
#include <cmath>
#include "VectorND.h"
#include "Circle.h"
//constant for the degrees in one radian
constexpr auto _RAD_ = 360.0 / (2.0 * _PI_);
//Gravitational Constant 6.67408(31) * 10^(-11) * N
constexpr auto _Gc_ = 6.674e-11;
//Radius of the earth 6,371km
constexpr auto EARTH_RADIUS = 6.371e6;
constexpr auto EARTH_MASS = 5.972e24;
constexpr auto MOON_RADIUS = 1737.1e3;
constexpr auto MOON_MASS = 7.34767309e22;
constexpr auto SUN_RADIUS = 6.963e8;
constexpr auto SUN_MASS = 1.989e30;

static int circularMotion_objectCount = 0;


static struct AstronomicalObject {
    AstronomicalObject() {}

    const struct SUN {
        /**
         * The mass of the sun in kg (1.989e30)
         */
        const ld mass = 1.989e30; // kg
        /**
         * The radius of the sun in meters (6.963e8)
         */
        const ld radius = 6.963e8; // m
        /**
         * The surface gravity of the sun in N (274.0)
         */
        const ld surfaceGravity = 274.0; // m/s^2
        /**
         * The surface acceleration of the sun in m/s^2 (618)
         */
        const ld escapeSpeed = 618.0e3; // m/s
        /**
         * The sidereal rotation period of the sun in seconds 2114208
         *  or (24.47) days
         */
        const ld siderealRotationPeriod = 2114208; // seconds
        /**
         * The mean distance from central body (galaxy center)
         * of the sun in m (2.6e20)
         */
        const ld meanDistanceFromCentralBody = 2.6e20; // m
        /**
         * The orbital period of the sun in days (7.30485e10)
         */
        const ld orbitalPeriod = 7.30485e10;
        /**
         * The orbital velocity of the sun in m/s (250.0e3)
         */
        const ld orbitalVelocity = 250.0e3;
    }sun;

    const struct MERCURY {
        /**
         * @brief mass of the planet in kg (1.65e-7)
         */
        const ld mass = .330e24; // kg
        /**
         * @brief radius of the planet in m (2439.7)
         */
        const ld radius = 2.44e6; // m
        /**
         * @brief surface gravity of the planet in m/s^2 (3.711)
         */
        const ld surfaceGravity = 3.71; // m/s^2
        /**
         * @brief escape velocity of the planet in km/s (35.02)
         */
        const ld escapeSpeed = 4.25e3; // m/s
        /**
         * @brief sidereal rotation period of the planet in days (88.0)
         */
        const ld siderealRotationPeriod = 58.6; // days
        /**
         * @brief mean distance from the sun to the planet in m (57.91e9)
         */
        const ld meanDistanceFromCentralBody = 57.9e9; // m
        /**
         * @brief orbital period of the planet in days (88.0)
         */
        const ld orbitalPeriod = 88.0; // days around sun
        /**
         * @brief orbital velocity of the planet in m/s (47.4)
         */
        const ld orbitalVelocity = 47.4e3; // m/s
    }mercury;

    const struct VENUS {
        const ld mass = 4.87e24; // kg
        const ld radius = 6.05e6; // m
        const ld surfaceGravity = 8.87; // m/s^2
        const ld escapeSpeed = 10.4e3; // m/s
        const ld siderealRotationPeriod = -243.0; // days
        const ld meanDistanceFromCentralBody = 108.0e9; // m
        const ld orbitalPeriod = 225.0; // days around sun
        const ld orbitalVelocity = 35.0e3; // m/s
    }venus;

    const struct EARTH {
        const ld mass = 5.97e24; // kg
        const ld radius = 6.37e6; // m
        const ld surfaceGravity = 9.81; // m/s^2
        const ld escapeSpeed = 11.2e3; // m/s
        const ld siderealRotationPeriod = .997; // days
        const ld meanDistanceFromCentralBody = 149.6e9; // m
        const ld orbitalPeriod = 365.2; // days around sun
        const ld orbitalVelocity = 29.8e3; // m/s
    }earth;

    const struct MOON {
        const ld mass = .0735e24; // kg
        const ld radius = 1.74e6; // m
        const ld surfaceGravity = 1.62; // m/s^2
        const ld escapeSpeed = 2.38e3; // m/s
        const ld siderealRotationPeriod = 27.3; // days
        const ld meanDistanceFromCentralBody = .3844e9; // m
        const ld orbitalPeriod = 27.3; // days around sun
        const ld orbitalVelocity = 1.02e3; // m/s
    }moon;

    const struct MARS {
        const ld mass = .642e24; // kg
        const ld radius = 3.38e6; // m
        const ld surfaceGravity = 3.71; // m/s^2
        const ld escapeSpeed =5.03e3; // m/s
        const ld siderealRotationPeriod = 1.03; // days
        const ld meanDistanceFromCentralBody = 228.0e9; // m
        const ld orbitalPeriod = 686.0; // days around sun
        const ld orbitalVelocity = 24.1e3; // m/s
    }mars;

    const struct PHOBOS {
        const ld mass = 1.07e16; // kg
        const ld radius = 11.0e6; // m
        const ld surfaceGravity = .0057; // m/s^2
        const ld escapeSpeed =.0114e3; // m/s
        const ld siderealRotationPeriod = .319; // days
        const ld meanDistanceFromCentralBody = 9.4e6; // m
        const ld orbitalPeriod = .319; // days around sun
        const ld orbitalVelocity = 2.14e3; // m/s
    }phobos;
//
//    const struct DEIMOS {
//        const ld mass = e24; // kg
//        const ld radius = e6; // m
//        const ld surfaceGravity = ; // m/s^2
//        const ld escapeSpeed =; // km/s
//        const ld siderealRotationPeriod = ; // days
//        const ld meanDistanceFromCentralBody = e6; // km
//        const ld orbitalPeriod = ; // days around sun
//        const ld orbitalVelocity = e3; // m/s
//    }deimos;
//
    const struct JUPITER {
        const ld mass = 1.90e27; // kg
        const ld radius = 69.9e6; // m
        const ld surfaceGravity = 24.8; // m/s^2
        const ld escapeSpeed = 60.2e3; // m/s
        const ld siderealRotationPeriod = .414; // days
        const ld meanDistanceFromCentralBody = 778e9; // m
        const ld orbitalPeriod = 4.34588e3; // days around sun
        const ld orbitalVelocity = 13.1e3; // m/s
    }jupiter;

    const struct IO {
        const ld mass = .0893e24; // kg
        const ld radius = 1.82e6; // m
        const ld surfaceGravity = 1.80; // m/s^2
        const ld escapeSpeed = 2.38e3; // m/s
        const ld siderealRotationPeriod = 1.77; // days
        const ld meanDistanceFromCentralBody = .422e9; // m
        const ld orbitalPeriod = 1.77; // days around sun
        const ld orbitalVelocity = 17.3e3; // m/s
    }io;
//
//    const struct EUROPA {
//        const ld mass = e24; // kg
//        const ld radius = e6; // m
//        const ld surfaceGravity = ; // m/s^2
//        const ld escapeSpeed =; // km/s
//        const ld siderealRotationPeriod = ; // days
//        const ld meanDistanceFromCentralBody = e6; // km
//        const ld orbitalPeriod = ; // days around sun
//        const ld orbitalVelocity = e3; // m/s
//    }europa;
//
//    const struct GANYMEDE {
//        const ld mass = e24; // kg
//        const ld radius = e6; // m
//        const ld surfaceGravity = ; // m/s^2
//        const ld escapeSpeed =; // km/s
//        const ld siderealRotationPeriod = ; // days
//        const ld meanDistanceFromCentralBody = e6; // km
//        const ld orbitalPeriod = ; // days around sun
//        const ld orbitalVelocity = e3; // m/s
//    }ganymede;
//
//    const struct CALLISTO {
//        const ld mass = e24; // kg
//        const ld radius = e6; // m
//        const ld surfaceGravity = ; // m/s^2
//        const ld escapeSpeed =; // km/s
//        const ld siderealRotationPeriod = ; // days
//        const ld meanDistanceFromCentralBody = e6; // km
//        const ld orbitalPeriod = ; // days around sun
//        const ld orbitalVelocity = e3; // m/s
//    }callisto;
//
//    const struct SATURN {
//        const ld mass = e24; // kg
//        const ld radius = e6; // m
//        const ld surfaceGravity = ; // m/s^2
//        const ld escapeSpeed =; // km/s
//        const ld siderealRotationPeriod = ; // days
//        const ld meanDistanceFromCentralBody = e6; // km
//        const ld orbitalPeriod = ; // days around sun
//        const ld orbitalVelocity = e3; // m/s
//    }saturn;
//
//    const struct TETHYS {
//        const ld mass = e24; // kg
//        const ld radius = e6; // m
//        const ld surfaceGravity = ; // m/s^2
//        const ld escapeSpeed =; // km/s
//        const ld siderealRotationPeriod = ; // days
//        const ld meanDistanceFromCentralBody = e6; // km
//        const ld orbitalPeriod = ; // days around sun
//        const ld orbitalVelocity = e3; // m/s
//    }tethys;
//
//    const struct DIONE {
//        const ld mass = e24; // kg
//        const ld radius = e6; // m
//        const ld surfaceGravity = ; // m/s^2
//        const ld escapeSpeed =; // km/s
//        const ld siderealRotationPeriod = ; // days
//        const ld meanDistanceFromCentralBody = e6; // km
//        const ld orbitalPeriod = ; // days around sun
//        const ld orbitalVelocity = e3; // m/s
//    }dione;
//
//    const struct RHEA {
//        const ld mass = e24; // kg
//        const ld radius = e6; // m
//        const ld surfaceGravity = ; // m/s^2
//        const ld escapeSpeed =; // km/s
//        const ld siderealRotationPeriod = ; // days
//        const ld meanDistanceFromCentralBody = e6; // km
//        const ld orbitalPeriod = ; // days around sun
//        const ld orbitalVelocity = e3; // m/s
//    }rhea;
//
//    const struct TITAN {
//        const ld mass = e24; // kg
//        const ld radius = e6; // m
//        const ld surfaceGravity = ; // m/s^2
//        const ld escapeSpeed =; // km/s
//        const ld siderealRotationPeriod = ; // days
//        const ld meanDistanceFromCentralBody = e6; // km
//        const ld orbitalPeriod = ; // days around sun
//        const ld orbitalVelocity = e3; // m/s
//    }titan;
//
//
//    const struct URANUS {
//        const ld mass = e24; // kg
//        const ld radius = e6; // m
//        const ld surfaceGravity = ; // m/s^2
//        const ld escapeSpeed =; // km/s
//        const ld siderealRotationPeriod = ; // days
//        const ld meanDistanceFromCentralBody = e6; // km
//        const ld orbitalPeriod = ; // days around sun
//        const ld orbitalVelocity = e3; // m/s
//    }uranus;
//
//    const struct NEPTUNE {
//        const ld mass = e24; // kg
//        const ld radius = e6; // m
//        const ld surfaceGravity = ; // m/s^2
//        const ld escapeSpeed =; // km/s
//        const ld siderealRotationPeriod = ; // days
//        const ld meanDistanceFromCentralBody = e6; // km
//        const ld orbitalPeriod = ; // days around sun
//        const ld orbitalVelocity = e3; // m/s
//    }neptune;
//
//    const struct CERES {
//        const ld mass = e24; // kg
//        const ld radius = e6; // m
//        const ld surfaceGravity = ; // m/s^2
//        const ld escapeSpeed =; // km/s
//        const ld siderealRotationPeriod = ; // days
//        const ld meanDistanceFromCentralBody = e6; // km
//        const ld orbitalPeriod = ; // days around sun
//        const ld orbitalVelocity = e3; // m/s
//    }ceres;
//
//    const struct PLUTO {
//        const ld mass = e24; // kg
//        const ld radius = e6; // m
//        const ld surfaceGravity = ; // m/s^2
//        const ld escapeSpeed =; // km/s
//        const ld siderealRotationPeriod = ; // days
//        const ld meanDistanceFromCentralBody = e6; // km
//        const ld orbitalPeriod = ; // days around sun
//        const ld orbitalVelocity = e3; // m/s
//    }pluto;
//
//    const struct ERIS {
//        const ld mass = e24; // kg
//        const ld radius = e6; // m
//        const ld surfaceGravity = ; // m/s^2
//        const ld escapeSpeed =; // km/s
//        const ld siderealRotationPeriod = ; // days
//        const ld meanDistanceFromCentralBody = e6; // km
//        const ld orbitalPeriod = ; // days around sun
//        const ld orbitalVelocity = e3; // m/s
//    }eris;
//
//





}celestialObjects;

class UniformCircularMotion
{
    // radius variable of object
    ld  _radius_;

    // rotational angle variable of object
    ld  _rotationAngle_;

    // angular velocity variable of object
    ld  _angularVelocityW_;

    // linear velocity variable
    ld _linearVelocity;

    // arc length variable of object
    ld  _arcLength_;

    // centripetal acceleration variable of object
    ld _centripetalAcceleration_;

    ld _frequency_;

    ld _time_period_;

    // array to hold the value of two masses



public:

    static void countShow() { std::cout << "circular motion count: " << circularMotion_objectCount << std::endl; }
    // suppresses default constructor
    UniformCircularMotion()
    {
        _radius_ = 0.0;
        _rotationAngle_ = 0.0;
        _angularVelocityW_ = 0.0;
        _linearVelocity = 0.0;
        _arcLength_ = 0.0;
        _centripetalAcceleration_ = 0.0;
        _frequency_ = 0.0;
        _time_period_ = 0.0;

        countIncrease();
    }
    // assignment constructor
    UniformCircularMotion(ld radius, ld velocity)
    {
        _radius_ = radius;
        _angularVelocityW_ = velocity / radius;
        _linearVelocity = radius * _angularVelocityW_;
        _rotationAngle_ = 0.0;
        _arcLength_ = 0.0;
        _centripetalAcceleration_ = (velocity * velocity)/(radius);
        _time_period_ = 2.0* _PI_ * _radius_ / (radius*_angularVelocityW_);
        _frequency_ = 1.0 / _time_period_;
        countIncrease();
    }
    // overloaded constructor
    UniformCircularMotion(ld radius, ld velocity, ld time)
    {
        _radius_ = radius;
        _angularVelocityW_ = velocity / radius;
        _linearVelocity = radius * _angularVelocityW_;
        _rotationAngle_ = 0.0;
        _arcLength_ = 0.0;
        _centripetalAcceleration_ = (velocity * velocity) / (radius);
        _frequency_ = radius * (_angularVelocityW_ * _angularVelocityW_);
        _time_period_ = time;
        countIncrease();
    }
    //copy constructor
    UniformCircularMotion(const UniformCircularMotion& r)
    {
        _angularVelocityW_ = r._angularVelocityW_;
        _centripetalAcceleration_ = r._centripetalAcceleration_;
        _linearVelocity = r._linearVelocity;
        _arcLength_ = r._arcLength_;
        _radius_ = r._radius_;
        _rotationAngle_ = r._rotationAngle_;
        _frequency_ = r._frequency_;
        _time_period_ = r._time_period_;
        countIncrease();
        //countShow();
    }
    //copy assignment operator
    UniformCircularMotion& operator=(UniformCircularMotion&& r) noexcept
    {
        if (this != &r)
        {
            _centripetalAcceleration_ = r._centripetalAcceleration_;
            _angularVelocityW_ = r._angularVelocityW_;
            _linearVelocity = r._linearVelocity;
            _arcLength_ = r._arcLength_;
            _radius_ = r._radius_;
            _rotationAngle_ = r._rotationAngle_;
            _frequency_ = r._frequency_;
            _time_period_ = r._time_period_;
            countIncrease();

        }
        return *this;
    }
    /*===================================================================
     * setters
     */
    void setRadius_(const ld r) { _radius_ = r; }
    void setRotationalAngle_(const ld ra) {
        _rotationAngle_ = ra;
        _arcLength_ = _radius_ * _rotationAngle_ * _RAD_;
    }
    void setAngularVelocityW_(const ld av) { _angularVelocityW_ = av; }
    void setLinearVelocity_(const ld lv) { _linearVelocity = lv; }
    void setArcLength_(const ld al) {
        _arcLength_ = al;
        _rotationAngle_ = _arcLength_ / (_radius_ * _RAD_);
    }
    void setCentripetalAcceleration_(const ld ca) { _centripetalAcceleration_ = ca; }
    void setFrequency_(const ld f) { _frequency_ = f; }
    void setTimePeriod_(const ld tp) { _time_period_ = tp; }

    /*===================================================================
     * getters
     */
    ld getRadius()const { return _radius_; }
    ld getRotationalAngle()const { return  _rotationAngle_; }
    ld getAngularVelocityW()const { return _angularVelocityW_; }
    ld getLinearVelocity()const { return _linearVelocity; }
    ld getArcLength()const { return _arcLength_; }
    ld getCentripetalAcceleration()const { return _centripetalAcceleration_; }
    ld getFrequency()const { return _frequency_; }
    ld getTimePeriod()const { return _time_period_; }

    /*===================================================================
     * display methods
     */
    void showRadius()const { cout << "radius: " << _radius_ << "m" <<endl; }
    void showRotationalAngle()const { cout << "rotational angle: " << _rotationAngle_ << "degrees" << endl;	}
    void showAngularVelocityW()const { cout << "angular velocity: " << _angularVelocityW_ << "rad/s" << endl;	}
    void showLinearVelocity()const { cout << "linear velocity: " << _linearVelocity << "m/s" << endl; }
    void showArcLength()const { cout << "arcLength: " << _arcLength_ << "m" << endl; }
    void showCentripetalAcceleration()const { cout << "centripetal acceleration: " << _centripetalAcceleration_ << "m/s^2" << endl; }
    void showFrequency()const {
        cout << "frequency: " << _frequency_ << "Hz" << endl;
        // calculate freq in RPM
        cout << "rev per min: " << _frequency_ * 60 << "RPM" << endl;
    }
    void show_time_period()const { cout << "time period: " << _time_period_ << "s" << endl; }
    void show_all_data()const {
        showRadius();
        showAngularVelocityW();
        showLinearVelocity();
        showCentripetalAcceleration();
        showFrequency();
        show_time_period();
        showRotationalAngle();
        showArcLength();
    }


    /*===================================================================
     * conversion methods
     */

    ld static radiansToRevolutions(const ld radTotal, bool print = false)
    {
        ld rev = radTotal / (2 * M_PI);
        if (print)
            cout << "radians to revolutions: " << rev << endl;
        return rev;
    }

    /**
     * @brief Returns the revolutions in radians per second which is the angular velocity as well
     * @param revMin revolutions per minute
     * @returns revolutions in radians per second
     */
    ld static revMin_to_radSec(const ld revMin, bool print = false)
    {
        ld radSec = revMin * (2 * M_PI) / 60;
        if (print)
            cout << "rev per min to rad per sec: " << radSec << endl;
        return radSec;
    }

    /**
     * @brief Returns the conversion from revolutions per radian second to revolutions per minute
     * @param radSec is the rotation speed in radians per second
     * @returns the revolutions per minute
     */
    ld static radSec_to_revMin(const ld radSec, bool print = false)
    {
        ld revMin = (radSec * 60) / (2 * M_PI);
        if (print)
            cout << "rad per sec to rev per min: " << revMin << endl;
        return revMin;
    }

    /**
     *  @brief Returns the ratio of the value of one gravitational acceleration to earths gravity
     *  @param unit can be whatever you are dividing by gravity acceleration
     *  @returns the gravity ratio
     */
    ld static gravityRatio(const ld unit)
    {
        return unit / celestialObjects.earth.surfaceGravity;
    }

    /*====================================================================
     * static methods
     */

    /**
     * @brief Returns the arc length when the radius and rotations are known
     * @param radius is half the diameter
     * @param rotations are the number of rotations counted
     * @returns the arc length - linear distance traveled
     */
    ld static arcLength_meters(const ld radius, const ld rotations)
    {
        return (rotations * 2 * _PI_) * radius;
    }

    /**
     * @brief Returns the arc length in radians when the total rotations are known
     * @param rotations are the number of rotations counted
     * @returns the arc length - in radians
     */
    ld static arcLength_radians(const ld rotations)
    {
        return (rotations * 2 * _PI_);
    }

    /**
     * @brief Returns the angular velocity(w) given the radius and speed
     * @param v is the velocity or angle change
     * @param rt radius or time
     * @returns angular velocity
     */
    ld static angularVelocity(const ld v, const ld rt)
    {
        return v / rt;
    }

    /**
     * @brief Returns the angular velocity(w) given the radius and speed
     * @param r is the radius of the spinning thing
     * @param av the angular velocity
     * @returns linear velocity
     */
    ld static linearVelocity(const ld r, const ld av)
    {
        return r * av;
    }
    /**
     * @brief Returns the centripetal acceleration using the radius and the angular velocity
     * @param r radius
     * @param w angular velocity in radian revolutions per second
     * @returns the centripetal acceleration
     */
    ld static centripetalAcceleration_W(const ld r, const ld w)
    {
        return r * (w * w);
    }

    /**
     * @brief Returns the centripetal acceleration using the radius and the velocity
     * @param r radius
     * @param v angular velocity in radian revolutions per second
     * @returns the centripetal acceleration
     */
    ld static centripetalAcceleration_V(const ld r, const ld v, bool print = false)
    {
        ld w = (v * v) / r;
        if (print)
            cout << "centripetal acceleration: " << w << endl;
        return w;
    }

    /**
     * @brief Returns the centripetal force using mass velocity and radius of object
     * @param mass in kg of object
     * @param velocity or speed of object in m/s
     * @param radius
     * @returns the centripetal force
     */
    ld static centripetalForce_V(const ld mass, const ld velocity, const ld radius)
    {
        return (mass * (velocity * velocity)) / (radius);
    }

    /**
     * @brief Returns the centripetal force using the mass the angular velocity and radius
     * @param mass in the mass in kg of object
     * @param angularVelocity is the rotation in radians per second
     * @param radius form center
     * @returns the centripetal force
     */
    ld static centripetalForce_W(const ld mass, const ld angularVelocity, const ld radius)
    {
        return mass * radius * (angularVelocity * angularVelocity);
    }

    /**
     * @brief Returns the frictional coefficient given the velocity and radius
     * @param v is the velocity
     * @param r is the radius
     * @returns the frictional coefficient
     */
    ld static coefficient(const ld v, const ld r)
    {
        return (v * v) / (r * _Ga_);
    }

    /**
     * @brief Returns the minimum static coefficient needed to safely take a turn with an specified
     * embankment angle at a specified speed with a radius of r.
     * fx = ((r * _G_) * tan(angle * RADIAN) - (speed * speed)) / ((r * _G_) + (speed * speed) * tan(15*RADIAN))
     * @param r is the radius to the center of the turn
     * @param angle is the angle of the embankment
     * @param speed is in m/s meters per second
     * @returns the minimum static coefficient needed
     */
    ld static minCoefficientOfFrictionForEmbankedTurn(const ld r, const ld angle, const ld speed)
    {
        return ((r * _Ga_) * tan(angle * RADIAN) - (speed * speed)) / ((r * _Ga_) + (speed * speed) * tan(15*RADIAN));
    }
    /**
     * @brief Returns the minimum static coefficient needed to safely take a turn with an specified
     * embankment angle at a specified speed with a radius of r.
     * fx = ((r * _G_) * tan(angle * RADIAN) - (speed * speed)) / ((r * _G_) + (speed * speed) * tan(15*RADIAN))
     * @param r is the radius to the center of the turn
     * @param angle is the angle of the embankment
     * @param speed is in m/s meters per second
     * @returns the minimum static coefficient needed
     */
    ld static minCoefficientFrictionForFlatCurve(const ld r,  const ld speed)
    {
        return (speed * speed) / (r * _Ga_);
    }
    /**
     * @brief Returns the ideal speed to take going around a banked curve,
     * fx = pow(r * _G_ * tan(angle * RADIAN), .5)
     * @param r is the radius of the curve
     * @param angle of the embankment
     * @returns the ideal velocity to take the corner
     */
    ld static idealSpeedBankedCurve(const ld r, const ld angle)
    {
        return pow(r * _Ga_ * tan(angle * RADIAN), .5);
    }

    /**
     * @brief Returns the ideal angle of an embankment for a given radius and velocity(speed m/s),
     * fx = atan((v * v) / (r * _G_))*DEGREE
     * @param r is the radius to the center of the curve
     * @param v is the velocity or speed in m/s
     * @returns the ideal angle in degrees
     */
    ld static idealAngleBankedCurve(const ld r, const ld v)
    {
        return atan((v * v) / (r * _Ga_))*DEGREE;
    }

    /**
     * @brief Returns the magnitude of the gravitational acceleration of two objects,
     * use 1 as a value as one of the m arguments if you want to calculate the gravitational
     * acceleration of one mass and use the radius to the center of the singe object.
     * fx = _Gc_ * (m * M) / (r * r), where _Gc_ is the gravitational constant
     * @param m mass 1
     * @param M mass 2
     * @param r is the distance from the center of one mass to the center of the other mass
     * @returns magnitude of acceleration between two masses
     */
    ld static universalGravitation_force(const ld m, const ld M, const ld r, bool print = true)
    {
        auto f =  _Gc_ * (m * M) / (r * r);
        if(print)
        {
            std::cout << "Gravitational Force: " << f << " N" << std::endl;
        }
        return f;
    }

    ld static universalGravitation_acceleration(const ld r, const ld M = celestialObjects.earth.mass, bool print = false)
    {
        auto acc = _Gc_ * (M) / (r * r);
        if(print)
        {
            std::cout << "Acceleration: " << acc << std::endl;
        }
        return acc;
    }

    /**
     * @brief Prints the masses of two objects from knowing the radius and the magnitude of force between them
     * as well as the combined weights of the two.
     * @param force is the magnitude of the force between the two
     * @param r is the distance from the center of one mass to the center of the other mass
     * @param totalMass is the total mass of both objects combined
     */
    vector<ld> static universalGravitation_masses(const ld force, const ld r, const ld totalMass, bool print = true)
    {
        ld temp = (force * (r*r)) / (_Gc_);
        auto m1 = (totalMass + sqrt((totalMass * totalMass) - 4 * temp)) / (2);
        auto m2 = (totalMass - sqrt((totalMass * totalMass) - 4 * temp)) / (2);
        vector<ld> masses = {m1, m2};
        if(print)
        {
            cout << "The masses of the two objects are: " << endl;
            for(auto i : masses)
            {
                cout << i << endl;
            }
        }
        return masses;
    }

    /**
    * @brief Prints the masses of two objects from knowing the radius and the magnitude of force between them
    * as well as the combined weights of the two.
    * @param force is the magnitude of the force between the two
    * @param r is the distance from the center of one mass to the center of the other mass
    */
    static ld universalGravitation_masses(const ld force, const ld r,  bool print = true)
    {
        ld totalMass = sqrt((force * (r*r)) / (_Gc_));
        if(print)
        {
            cout << "The masses of the two objects are: " << endl;
            cout << totalMass << "kg, or " << (totalMass) / 2.0 << "kg each" << endl;
        }
        return totalMass/2.0;
    }

    /**
     * @brief Prints the masses from the mass array
     * @param obj is reference to a array holding twwo masses
     */
    template <typename T, std::size_t size>
    void static showArray(const T(&array)[size])
    {
        for (size_t i = 0; i < size; i++)
            cout << array[i] << " ";

        cout << endl;
    }

    /**
     * @brief Global Positioning System (GPS) satellites circle Earth at altitudes of
     * approximately oH, where the gravitational acceleration has pL (%) of its surface
     * value. To the nearest hour, what's the orbital period of the GPS satellites?\n
     * fx = (2 * PI * sqrt(oH_ / (_Ga_ * pL_))) / 3600
     * @param oH is the altitude of the satellite in meters
     * @param pL is the percentage of the surface gravity of the earth
     * @returns the orbital period in hours
     */
    ld static orbitTimeEarthSatellite(ld oH, ld pL, ld planetRadius = EARTH_RADIUS)
    {
        // turn the percentage into a decimal
        ld pL_ = pL / 100.0;
        // add the radius of the earth to the altitude
        ld oH_ = oH + planetRadius;
        return (2 * PI * sqrt(oH_ / (_Ga_ * pL_))) / 3600;
    }
    /**
     * @brief Calculates the frequency from a known period time
     * @param period  is the period of the wave in seconds
     * @return  the frequency in hertz
     */
    ld static frequency(const ld period)
    {
        return 1.0 / period;
    }
    /**
     * @brief Calculates the period from a known frequency
     * @param frequency is the frequency of the wave in hertz
     * @return  the period in seconds
     */
    ld static period(const ld frequency)
    {
        return 1.0 / frequency;
    }

    /**
     * @brief Pilots of high-performance aircraft risk loss of consciousness if they
     * undergo accelerations exceeding about Xg's. For a jet flying at a speed of
     * v0 (L/T), what's the minimum radius for a turn that will keep the
     * acceleration below Xg's?
     * fx = pow(v0, ) / (Xg * _G_)
     * @param v0 is the speed of the aircraft in meters per second
     * @param Xg is the acceleration in meters per second squared
     * @returns the minimum radius in meters
     */
    ld static minTurnRadius(const ld v0, const ld Xg) {
        // r = v0^2 / Xg*gravity
        return pow(v0, 2) / (Xg * _G_);
    }
    /**
     * @brief calulates the circular orbit speed of a satellite from the radius and mass
     * @param radius  is the radius of the orbit in meters
     * @param mass  is the mass of the satellite in kilograms
     * @param print  is a boolean to print the result
     * @return  the speed of the satellite in meters per second
     */
    ld static circularOrbitSpeed(const ld radius, const ld mass, bool print = false)
    {
        ld v = sqrt((_Gc_ * mass) / radius);
        if(print)
        {
            cout << "The circular orbit speed is: " << v << endl;
        }
        return v;
    }

    /**
     * @brief calculates the orbital period of a satellite from the radius and mass
     * @param radius is the radius of the orbit in meters
     * @param mass is the mass of the satellite in kilograms
     * @param print is a boolean to print the result
     * @return the orbital period in seconds
     */
    static ld orbitalPeriod(const ld r, const ld m, bool print = false)
    {
        auto period = sqrt((4.0 * (PI * PI) * (r*r*r)) / (_Gc_ * m));
        if(print)
        {
            cout << "The orbital period is: " << period << endl;
        }
        return period;
    }

    static ld orbitAltitude(const ld mass, const ld T, bool print = false)
    {
        ld radius = pow((mass * _Gc_ * (T*T)) / (4 * (PI * PI)), 1.0 / 3.0);
        if(print)
        {
            cout << "The orbital altitude is: " << radius << endl;
        }
        return radius;
    }

    static ld gravitationalPE(const ld M, const ld m, const ld r1, const ld r2, bool print = false)
    {
        ld PE = (_Gc_ * M * m)*(1/r1 - 1/r2);
        if(print)
        {
            cout << "The gravitational potential energy is: " << PE << " J" << endl;
        }
        return PE;
    }

    static ld gravitationalPE(const ld M, const ld m, const ld r, bool print = false)
    {
        ld PE = -(M * _G_ * m)/r;
        if(print)
        {
            cout << "The gravitational potential energy is: " << PE << endl;
        }
        return PE;
    }

    static ld escapeVelocity(const ld m, const ld r, bool print = false)
    {
        ld v = sqrt((2 * _G_ * m) / r);
        if(print)
        {
            cout << "The escape velocity is: " << v << endl;
        }
        return v;
    }

    static ld launchVelocity(const ld m, const ld r, const ld h, bool print = false)
    {
        ld v = sqrt((2.0 * _Gc_ * m) *((1.0/r) - (1.0/(r+h))));
        if(print)
        {
            cout << "The launch velocity is: " << v << endl;
        }
        return v;
    }

    static ld heightRocket(const ld M,  const ld r, const ld v0, bool print = false)
    {
        ld h = 1.0/((1.0/r) - ((v0*v0)/(2.0 * _Gc_* M))) - r;
        if(print)
        {
            cout << "The height of the rocket is: " << h << endl;
        }
        return h;
    }

    static ld gravitationalField(const ld M, const ld r, const tuple<ld, ld, ld> position, bool print = false)
    {
        ld rx, ry, rz;
        tie(rx, ry, rz) = position;
        ld r2 = rx*rx + ry*ry + rz*rz;
        ld r3 = r2*sqrt(r2);
        ld G = _G_ * M / r3;
        if(print)
        {
            cout << "The gravitational field is: " << G << endl;
        }
        return G;
    }

    static ld radius_v(const ld M, const ld v0, bool print = false)
    {
        ld r = pow(((v0*v0)/(2*_Gc_*M)), -1);
        if(print)
        {
            cout << "The radius is: " << r << endl;
        }
        return r;
    }

    static ld radius_a(const ld m, const ld a, bool print = false)
    {
        ld r = sqrt((_Gc_ * m) / a);
        if(print)
        {
            cout << "The radius is: " << r << endl;
        }
        return r;
    }

    static ld radius_Vesc(const ld m, const ld v0, bool print = false)
    {
        ld r = (2.0 * _Gc_ * m) / (v0*v0);
        if(print)
        {
            cout << "The radius is: " << r << endl;
        }
        return r;
    }

    /**
     * @brief call like this:
     * UniformCircularMotion::altitudeSatelliteCompleteOrbitOfPlanetInTime(
            AstronomicalObject::EARTH(), 2.0*3600.0, true
            );
     * @tparam T is the AstronomicalObject::ObjectType()
     * @param planet  is the reference planet AstronomicalObject::PLANET()
     * @param time  is the time in seconds
     * @param print  is a boolean to print the result
     * @return  the altitude of the satellite in meters
     */
    template<typename T>
    static ld altitudeSatelliteCompleteOrbitOfPlanetInTime(
            T planet, ld time, bool print = false) {
        auto radius = planet.radius;
        auto mass = planet.mass;
        auto rad_total = cbrt(((time*time)*_Gc_*mass) / (4 * PI * PI));
        auto alt = rad_total - radius;
        if(print)
        {
            cout << "The altitude of the satellite is: " << alt << endl;
        }
        return alt;
    }

    template<typename T>
    static ld geostationaryOrbitVelocityOfSatellite(
            T mass, ld period, bool print = false) {
        auto v = cbrt((2.0*PI*_Gc_*mass) / period);
        if(print)
        {
            cout << "The geostationary orbit velocity is: " << v << endl;
        }
        return v;
    }







    ~UniformCircularMotion() {
        countDecrease();
    };

private:
    static void countIncrease() { circularMotion_objectCount += 1; }
    static void countDecrease() { circularMotion_objectCount -= 1; }

};
#endif //PHYSICSFORMULA_UNIFORMCIRCULARMOTION_H
