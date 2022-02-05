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

static int circularMotion_objectCount = 0;
ld static _masses_[] = { 0.0, 0.0 };

class UniformCircularMotion
{

    // pointer for the class object to use
    UniformCircularMotion* _circlePtr;

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
        _circlePtr = nullptr;
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
        _circlePtr =  nullptr;
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
        _circlePtr = nullptr;
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
        _circlePtr = r._circlePtr;
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
            _circlePtr = r._circlePtr;
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
    void set_radius_(const ld r) { _radius_ = r; }
    void set_rotationalAngle_(const ld ra) {
        _rotationAngle_ = ra;
        _arcLength_ = _radius_ * _rotationAngle_ * _RAD_;
    }
    void set_angularVelocityW_(const ld av) { _angularVelocityW_ = av; }
    void set_linearVelocity_(const ld lv) { _linearVelocity = lv; }
    void set_arcLength_(const ld al) {
        _arcLength_ = al;
        _rotationAngle_ = _arcLength_ / (_radius_ * _RAD_);
    }
    void set_centripetalAcceleration_(const ld ca) { _centripetalAcceleration_ = ca; }
    void set_frequency_(const ld f) { _frequency_ = f; }
    void set_time_period_(const ld tp) { _time_period_ = tp; }

    /*===================================================================
     * getters
     */
    ld get_radius()const { return _radius_; }
    ld get_rotationalAngle()const { return  _rotationAngle_; }
    ld get_angularVelocityW()const { return _angularVelocityW_; }
    ld get_linearVelocity()const { return _linearVelocity; }
    ld get_arcLength()const { return _arcLength_; }
    ld get_centripetalAcceleration()const { return _centripetalAcceleration_; }
    ld get_frequency()const { return _frequency_; }
    ld get_time_period()const { return _time_period_; }

    /*===================================================================
     * display methods
     */
    void show_radius()const { cout << "radius: " << _radius_ << "m" <<endl; }
    void show_rotationalAngle()const { cout << "rotational angle: " << _rotationAngle_ << "degrees" << endl;	}
    void show_angularVelocityW()const { cout << "angular velocity: " << _angularVelocityW_ << "rad/s" << endl;	}
    void show_linearVelocity()const { cout << "linear velocity: " << _linearVelocity << "m/s" << endl; }
    void show_arcLength()const { cout << "arcLength: " << _arcLength_ << "m" << endl; }
    void show_centripetalAcceleration()const { cout << "centripetal acceleration: " << _centripetalAcceleration_ << "m/s^2" << endl; }
    void show_frequency()const {
        cout << "frequency: " << _frequency_ << "Hz" << endl;
        // calculate freq in RPM
        cout << "rev per min: " << _frequency_ * 60 << "RPM" << endl;
    }
    void show_time_period()const { cout << "time period: " << _time_period_ << "s" << endl; }
    void show_all_data()const {
        show_radius();
        show_angularVelocityW();
        show_linearVelocity();
        show_centripetalAcceleration();
        show_frequency();
        show_time_period();
        show_rotationalAngle();
        show_arcLength();
    }


    /*===================================================================
     * conversion methods
     */

    ld static conversion_revolutions(const ld radTotal)
    {
        cout << "revolutions: " << radTotal / (2.0 * _PI_) << endl;
        return radTotal / (2.0 * _PI_);
    }

    /**
     * @brief Returns the revolutions in radians per second which is the angular velocity as well
     * @param revMin revolutions per minute
     * @returns revolutions in radians per second
     */
    ld static conversion_revolutions_min_to_radians_second(const ld revMin)
    {
        return (revMin * 2.0 * _PI_) / 60;
    }

    /**
     * @brief Returns the conversion from revolutions per radian second to revolutions per minute
     * @param radSec is the rotation speed in radians per second
     * @returns the revolutions per minute
     */
    ld static conversion_radians_second_to_revolutions_minute(const ld radSec)
    {
        return (radSec * 60.0) / (2.0 * _PI_);
    }

    /**
     *  @brief Returns the ratio of the value to gravity
     *  @param unit can be whatever you are dividing by gravity acceleration
     *  @returns the gravity ratio
     */
    ld static conversion_gravity_ratio(const ld unit)
    {
        return unit / _Ga_;
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
    ld static arc_length_meters(const ld radius, const ld rotations)
    {
        return (rotations * 2 * _PI_) * radius;
    }

    /**
     * @brief Returns the arc length in radians when the total rotations are known
     * @param rotations are the number of rotations counted
     * @returns the arc length - in radians
     */
    ld static arc_length_radians(const ld rotations)
    {
        return (rotations * 2 * _PI_);
    }

    /**
     * @brief Returns the angular velocity(w) given the radius and speed
     * @param v is the velocity or angle change
     * @param rt radius or time
     * @returns angular velocity
     */
    ld static angular_velocity(const ld v, const ld rt)
    {
        return v / rt;
    }

    /**
     * @brief Returns the angular velocity(w) given the radius and speed
     * @param r is the radius of the spinning thing
     * @param av the angular velocity
     * @returns linear velocity
     */
    ld static linear_velocity(const ld r, const ld av)
    {
        return r * av;
    }
    /**
     * @brief Returns the centripetal acceleration using the radius and the angular velocity
     * @param r radius
     * @param w angular velocity in radian revolutions per second
     * @returns the centripetal acceleration
     */
    ld static centripetal_acceleration_W(const ld r, const ld w)
    {
        return r * (w * w);
    }

    /**
     * @brief Returns the centripetal acceleration using the radius and the velocity
     * @param r radius
     * @param v angular velocity in radian revolutions per second
     * @returns the centripetal acceleration
     */
    ld static centripetal_acceleration_V(const ld r, const ld v)
    {
        return (v * v) / r;
    }

    /**
     * @brief Returns the centripetal force using mass velocity and radius of object
     * @param mass in kg of object
     * @param velocity or speed of object in m/s
     * @param radius
     * @returns the centripetal force
     */
    ld static centripetal_force_V(const ld mass, const ld velocity, const ld radius)
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
    ld static centripetal_force_W(const ld mass, const ld angularVelocity, const ld radius)
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
    ld static coefficientOfFriction_minimumForEmbankedTurn(const ld r, const ld angle, const ld speed)
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
    ld static coefficientFriction_minimumForFlatCurve(const ld r,  const ld speed)
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
    ld static ideal_speed_banked_curve(const ld r, const ld angle)
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
    ld static ideal_angle_banked_curve(const ld r, const ld v)
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
    ld static newtons_universal_law_gravitation(const ld m, const ld M, const ld r)
    {
        return _Gc_ * (m * M) / (r * r);
    }

    /**
     * @brief Prints the masses of two objects from knowing the radius and the magnitude of force between them
     * as well as the combined weights of the two.
     * @param force is the magnitude of the force between the two
     * @param r is the distance from the center of one mass to the center of the other mass
     * @param totalMass is the total mass of both objects combined
     */
    void static newtons_universal_law_gravitation2(const ld force, const ld r, const ld totalMass)
    {
        ld temp = (force * (r*r)) / (_Gc_);
        _masses_[0] = (totalMass + sqrt((totalMass * totalMass) - 4 * temp)) / (2);
        _masses_[1] = (totalMass - sqrt((totalMass * totalMass) - 4 * temp)) / (2);
        show_array(_masses_);

    }
    /**
     * @brief Prints the masses from the mass array
     * @param obj is reference to a array holding twwo masses
     */
    template <typename T, std::size_t size>
    void static show_array(const T(&array)[size])
    {
        for (size_t i = 0; i < size; i++)
            cout << array[i] << " ";

        cout << endl;
    }

    /**
     * @warning Not working needs to get worked on
     * @brief Returns the time it takes a satellite to orbit the earth when the distance from the earth is known
     * @param r2 is the radius from the center of the earth to the satellite. Earth core to crust is 6380 km
     * @param r1 is the radius to a first body and we use the moon as the default because the values are known
     * @param t1 is the time it takes the first body to orbit the earth, moon is default
     * @returns the time is hours to orbit the earth
     */
    ld static orbit_time_earth_satellite()
    {
        return 1.0;
    }

    ld static calculate_frequency(const ld period)
    {
        return 1.0 / period;
    }

    ld static calculate_period(const ld frequency)
    {
        return 1.0 / frequency;
    }

    ~UniformCircularMotion() {
        delete _circlePtr;
        countDecrease();
    };

private:
    static void countIncrease() { circularMotion_objectCount += 1; }
    static void countDecrease() { circularMotion_objectCount -= 1; }

};
#endif //PHYSICSFORMULA_UNIFORMCIRCULARMOTION_H
