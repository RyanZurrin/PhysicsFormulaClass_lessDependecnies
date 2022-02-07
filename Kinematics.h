//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_KINEMATICS_H
#define PHYSICSFORMULA_KINEMATICS_H
/**
 * @class Kinematics
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @dateBuilt  1/1/2021
 * @lastEdit 1/1/2021
 */
#include "VectorND.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long double ld;

static int kinematics_objectCount = 0;


/// <summary>
/// The vector values is for storing answers when there requires multiple
/// answers
/// </summary>
static std::vector<ld> vector_values = { 0.0,0.0,0.0,0.0 };
/// <summary>
/// Sets the vector.
/// </summary>
/// <param name="v">The vector to add too.</param>
/// <param name="val">value to add</param>
/// <param name="index">position to add to</param>
template<typename T>
static auto setVector(vector<T>& v, T val, int index)
{
    if (index < v.size())
    {
        v[index] = val;
        return true;
    }
    return false;
}

/// <summary>
/// Returns the vector.
/// </summary>
/// <param name="v">The v.</param>
/// <returns></returns>
static vector<ld> return_vector(vector<ld>& v) { return v; }
/// <summary>
/// Shows the vector.
/// </summary>
static void showVector()
{
    for (auto it : vector_values)
    {
        std::cout << it << ", ";
    }
    std::cout << std::endl;
}

class Kinematics
{
public:
    Kinematics* _kinematicPtr;

    Kinematics()
    {
        _kinematicPtr = nullptr;
        countIncrease();
    }

    /**
     * @brief copy constructor
     */
    Kinematics(const Kinematics& t)
    {
        _kinematicPtr = t._kinematicPtr;
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    Kinematics(Kinematics&& t) noexcept
    {
        _kinematicPtr = t._kinematicPtr;
        countIncrease();
    }
    /**
     * @brief copy assignment operator
     */
    Kinematics& operator=(const Kinematics& t)
    {
        if (this != &t)
        {
            _kinematicPtr = t._kinematicPtr;
            countIncrease();
        }
        return *this;
    }

    static void show_objectCount() { std::cout << "\n kinematics object count: "
                                     << kinematics_objectCount << std::endl; }
    static int get_objectCount() { return kinematics_objectCount; }


    //=========================================================================
    //chapter 2 formulas

    /**
     * @brief Returns the displacement between two positions
     * @param startPos starting position
     * @param endPos ending position
     * @returns displacement.
     */
    static ld displacement(const ld startPos,const ld endPos)
    { return endPos - startPos; }

    /**
     * @brief Returns the displacement from knowing the velocity and time.
     * @param velocity in m/s
     * @param time in seconds
     * @returns displacement.
     */
    static ld displacement_VxT(const ld velocity, const ld time)
    { return velocity * time; }

    /**
     * method: displacement_accelerating_object(ld acceleration, ld time)
     * arguments: acceleration m/s , time in s
     * purpose: find the displacement of an accelerating object
     * returns:	ld, displacement
     */
    static ld displacement_accelerating_object(const ld acceleration, const ld time)
    { return ((acceleration) * (time * time)) / 2; }

    /**
     * method: displacement_accelerating_object_PV(ld acceleration, ld time)
     * arguments: velocity, acceleration m/s , position = 0m default, time in s
     * purpose: find the displacement of an accelerating object with a starting
     * 			position and an initial velocity along with acceleration and a time
     * returns:	ld, displacement
     */
    static ld displacement_accelerating_object_PV(const ld velocity,
                                                  const ld acceleration,
                                                  const ld time,
                                                  const ld pos = 0)
    { return pos + (velocity * time) + (acceleration * (time * time)) / 2; }

    /**
     * @brief calculates the displacement using the kinematic formula
     * X = Vi*t+ 1/2*a*t^2
     * @param velocity in m/s
     * @param acceleration in m/s^2
     * @param time in s
     */
    static ld displacement_using_kinematic(const ld velocity,
                                           const ld acceleration,
                                           const ld time)
    {
        return (velocity * time) + (acceleration * (time * time)) / 2;
    }


    /// <summary>
    /// calculate displacement for the distance to stop from moving object
    /// </summary>
    /// <param name="velocityStart">The velocity start.</param>
    /// <param name="velocityFinal">The velocity final.</param>
    /// <param name="acceleration">The acceleration.</param>
    /// <param name="pos">The starting position, default is 0.</param>
    /// <returns>final displacement</returns>
    static ld distance(const ld velocityStart, const ld velocityFinal, const ld acceleration, const ld pos = 0.0)
    { return abs(((velocityFinal * velocityFinal) - (velocityStart * velocityStart)) / (2.0 * acceleration)) + pos; }

    /**
     * method: velocity_vStart_plus_vEndD2(const ld velocityStart, const ld velocityEnd)
     * arguments: vStart = starting velocity m/s, vEnd = ending velocity m/s
     * purpose:	find the displacement when start and end velocity is know
     * returns: ld, displacement
     */
    static ld velocity_vStart_plus_vEndD2(const ld velocityStart, const ld velocityEnd)
    { return (velocityStart + velocityEnd) / 2;	}


    static ld velocity_final_from_kinematic_time(const ld initialVelocity, const ld acceleration, const ld time)
    {	return initialVelocity + acceleration * time; }

    /**
     *@brief calculates the final velocity using the kinematic formula vf^2 = vi^2 + 2*a*d
     *@param initialVelocity m/s
     *@param acceleration m/s^2
     *@param displacement m
     *@returns the final velocity
     */
    static ld velocity_final_kinematic_no_time(const ld initialVelocity, const ld acceleration , const ld displacement)
    { return sqrt(initialVelocity * initialVelocity + (2 * (acceleration * displacement))); }

    /**
     * @brief calculates the average velocity
     * @param d the displacement
     * @param t  the time
     * @return  the average velocity
     */
    static ld average_velocity(const ld d, const ld t)
    { return  d / t; }


    /**
     * @brief v^2 = vi^2 + 2*a*(x0 - xf) == v = sqrt(vi^2 + 2*a*(x0 - xf))
     * @param x0  the initial position
     * @param xf  the final position
     * @param v0  the initial velocity
     * @param a  the acceleration
     * @return  final velocity
     */
    static ld final_velocity(const ld x0, const ld xf, const ld v0, const ld a)
    { return sqrt((v0 * v0) + (2 * (a * (xf - x0)))); }

    /**
     * @brief v = vi + a*t
     * @param vi  the initial velocity
     * @param a  the acceleration
     * @param t  the time
     * @return  final velocity
     */
    static ld final_velocity(const ld vi,const ld a, const ld t)
    {
        return vi + a*t;
    }

    /**
     * @brief calculates the initial velocity given the final velocity, distance s
     *  and time t
     * @param v_f  final velocity
     * @param s  distance
     * @param t  time
     * @return  the initial velocity
     */
    static auto initial_velocity(const ld v_f, const ld s, const ld t) {
        return (2.0 * s - t * v_f) / t;
    }


    /// <summary>
    /// Constant Acceleration average using final velocity, starting velocity and time.
    /// </summary>
    /// <param name="u_">The final velocity.</param>
    /// <param name="v_">The initial velocity.</param>
    /// <param name="t">The time taken.</param>
    /// <returns>average acceleration</returns>
    static ld acceleration_avg(const ld u_, const ld v_, const ld t)
    { return (u_ - v_) / t; }

    /// <summary>
    /// Constant Acceleration average using change in velocity and time.
    /// </summary>
    /// <param name="deltaV">The change in velocity.</param>
    /// <param name="t">The time.</param>
    /// <returns>average acceleration</returns>
    template<typename T>
    static auto acceleration_avg(const T deltaV, const T t)
    { return deltaV / t; }


    /// <summary>
    /// Calculates the constant accelerations from distance, speed, and time.
    /// </summary>
    /// <param name="u">The initial speed.</param>
    /// <param name="s">The distance.</param>
    /// <param name="t">The time.</param>
    /// <returns>acceleration</returns>
    template<typename T>
    static auto acceleration_from_distance_speed_time(const T u, const T s, const T t)
    { return (2 * (s - (u * t)) / (t * t)); }


    /// <summary>
    /// Calculates the constant accelerations from initialize velocity, final velocity
    /// and the displacement.
    /// </summary>
    /// <param name="u">The initial velocity.</param>
    /// <param name="v">The final velocity.</param>
    /// <param name="s">The distance.</param>
    /// <returns>acceleration</returns>
    template<typename T>
    static auto acceleration_from_initV_finV_displacement(const T u, const T v, const T s)
    { return (v * v - u * u) / (2.0 * s); }

    /**
     * @brief calulates the average speed
     * @param s  the distance
     * @param t  the time
     * @return  the average speed
     */
    static ld average_speed(const ld s, const ld t)
    { return abs(s / t); }

    /**
     * method: time_by_avgVdA(ld acceleration, ld velocityStart, ld velocityEnd)
     * arguments: a = acceleration, sV = start velocity(default 0), fV = final velocity
     * purpose: calculate time with know acceleration and final velocity end point
     * returns: ld, time
     */
    static ld time_by_velocity_acceleration(const ld acceleration, const ld velocityStart, const ld velocityEnd)
    { return (velocityEnd - velocityStart) / acceleration; }

    /**
     * method: time_by_DisTdV(ld distance, ld velocity)
     * arguments: distance , average velocity
     * purpose: find the velocity of a falling object thrown downwards
     * returns: ld, velocity
     */
    static ld time_by_distance_velocity(const ld distance, const ld velocity)
    { return distance / velocity; }

    /**
     * method: time_finalPos_acceleration(ld displacement, ld acceleration)
     * arguments: displacement of object, acceleration of object
     * purpose: find how long it takes an object with a known acceleration to travel a know distance
     * returns: ld, time to accelerate a distance
     */
    static ld time_by_finalPos_acceleration(const ld displacement, const ld acceleration)
    { return sqrt((2 * displacement) / acceleration); }

    /**
     * method: time(ld startTime, ld endTime)
     * arguments: y = startTime = beginning time in seconds, endTime = endTime in seconds
     * purpose: find the amount of time between two periods
     * returns: ld, difference in two times
     */
    static ld time_difference(const ld startTime, const ld endTime)
    { return endTime - startTime; }

    /**
     * method: time_kinematic_rearranged(ld velocity, ld y0, ld acceleration) const
     * arguments: velocity, y0 = position from 0, acceleration
     * purpose: find the amount of time between two periods
     * returns: ld, difference in two times
     */
    static ld time_kinematic_rearranged(const ld velocity, const ld displacement, const ld acceleration)
    { return (-(velocity)-sqrt((velocity * velocity) - 2 * (acceleration) * (displacement))) / (acceleration); }

    /**
     * method: slope_formula(ld y1, ld y0, ld x1, ld x0)
     * arguments: y1 , y0, x1, x0
     * purpose:	the general slope equation of (y1 - y0)/(x1 - x0)
     *  to find the slope of a line between two points
     * returns: ld, slope of line between two points
     */
    static ld slope_formula(const ld y1, const ld y0, const ld x1, const ld x0)
    { return (y1 - y0) / (x1 - x0);	}

    /**
     * method: rotation_speed_2PIxRdT(ld radius, ld rotations, ld time)
     * arguments: radius = length in m from center of rotation
     *	rotations = how many rotations in a time period
     *	time = time units
     * purpose: find the speed of a spinning object, such as fan blade
     * returns: average speed of spinning object
     */
    static ld rotation_speed_2PIxRdT(const ld radius, const ld rotations, const ld time)
    { return (2.0 * _PI_ * radius) / (time / rotations); }

    /**
     * method: rotation_avgVelocity_2PIxRdT_in_1_rotation(ld radius, ld time)
     * arguments: radius , time = time for one rotation
     * purpose: find average velocity of a spinning object
     * returns: ld, average velocity
     */
    static ld rotation_avgVelocity_2PIxRdT_in_1_rotation(const ld radius, const ld time)
    { return (2.0 * _PI_ * radius) / time; }

    /**
     * @brief Returns the conversion of given value divided by the acceleration of gravity on earth, 9.80 m/s^2
     * @param value the value to find the multiples of gravity of
     * returns: g's
     */
    static ld conversion_multiple_of_gravity(const ld value)
    { return value / _Ga_; }

    /**
     * method: time_using_quadratic(ld a, ld b, ld c)
     * arguments: a1 = default to 1, b_velocity = constant velocity, c_displacement = total distance to travel
     * purpose: calculate the time of a merging object when velocity and displacement is know
     * returns: ld, total time
     */
    static std::vector<ld> time_using_quadratic(ld a1, ld b_velocity, ld c_displacement)
    {
        vector_values[0] = (-b_velocity + sqrt((b_velocity * b_velocity) - 4 * a1 * c_displacement)) / (2 * a1);
        vector_values[1] = (-b_velocity - sqrt((b_velocity * b_velocity) - 4 * a1 * c_displacement)) / (2 * a1);

        return vector_values;
    }

    /**
     * method: pos_vel_falling_object_upDown(double p, double v_, double a, double t)
     * arguments: p = position (0),  v_ = velocity, a = acceleration, t = time is s
     * purpose: this method will fill a vector with four pieces of data in order from the right to left it
     *			is: time, position, velocity, acceleration. use the print_vector_values() to see contents.
     * returns: ld, vector of the time, position, velocity, acceleration.
     */
    static std::vector<ld> pos_vel_falling_object_upDown(ld v_, ld a, ld t, ld p = 0.0)
    {
        ld temp;
        vector_values[0] = t;
        vector_values[1] = Kinematics::displacement_accelerating_object_PV(v_, a, t, p);
        //Solution for Velocity:
        temp = Kinematics::velocity_final_from_kinematic_time(v_, a, t);
        vector_values[2] = temp;
        vector_values[3] = a;
        //this->show_vector_values();
        return vector_values;
    }

    static std::vector<pair<string, ld>>
    time_and_velocity_falling_obj_to_P_Q(ld seperationPQ, ld timeBetweenPQ) {
        vector<pair<string, ld>> timeAndVelocity;
        timeAndVelocity.emplace_back("time to P", 0.0);
        timeAndVelocity.emplace_back("time to Q", 0.0);
        timeAndVelocity.emplace_back("velocity at P", 0.0);
        timeAndVelocity.emplace_back("velocity at Q", 0.0);
        auto timeToP =
                (seperationPQ - ((1.0/2.0)*_ga_*(timeBetweenPQ*timeBetweenPQ))) /
                (timeBetweenPQ*_ga_);
        auto timeToQ = timeToP + timeBetweenPQ;
        auto velAtP = timeToP * _ga_;
        auto velAtQ = timeToQ * _ga_;
        timeAndVelocity[0].second = timeToP;
        timeAndVelocity[1].second = timeToQ;
        timeAndVelocity[2].second = velAtP;
        timeAndVelocity[3].second = velAtQ;
        return timeAndVelocity;
    }

    /// <summary>
    /// Calculates the horizontal range of a projectile.
    /// </summary>
    /// <param name="v">The velocity.</param>
    /// <param name="theta">The angle theta.</param>
    /// <returns>range of projectile</returns>
    template<typename T>
    static auto horizontal_range_projectile(const T v, const T theta)
    { return  ((v * v) * sin(2 * theta * RADIAN) / (_Ga_));	}

    /// <summary>
    /// calculates the angle theta of a projectile
    /// </summary>
    /// <param name="distance">The distance.</param>
    /// <param name="velocity">The velocity.</param>
    /// <returns>theta</returns>
    static ld projectile_theta(const ld distance, const ld velocity)
    {
        return (asinh(distance * _Ga_) / (velocity * velocity)) / 2;
    }

    /// <summary>
    /// Calculates the trajectories equation for a projectile
    /// </summary>
    /// <param name="v">The initial velocity.</param>
    /// <param name="theta">The angle theta of projectiles launch.</param>
    /// <param name="h_0">The height initially started from.</param>
    /// <returns>a string with the trajectory equation of projectile's parabola</returns>
    template<typename T>
    static auto trajectory_equation(T v, T theta, T h_0)
    {
        auto prt1 = tan(theta * RADIAN);
        auto prt2 = _Ga_ / (2.0 * (v * v) * pow(cos(theta * RADIAN), 2));
        string results ="y = -" + to_string(prt2) + "x^2" + " + " + to_string(prt1) +"x + "+ to_string(h_0) ;
        return results;
    }

    /// <summary>
    /// calculates the time a projectile with an initial velocity and angle
    /// take to reach the same level from which it was launched, forms a parabolic curve
    /// (2* launchVelocity*sin(angleTheta))/(-GA);
    /// </summary>
    /// <param name="launchVelocity">The launch velocity.</param>
    /// <param name="angleTheta">The angle theta.</param>
    /// <returns>air time</returns>
    static ld time_for_projectile_to_reach_level(ld launchVelocity, ld angleTheta)
    {
        return (2 * launchVelocity * sin(angleTheta)) / (_Ga_);
    }

    /// <summary>
    /// Time of projectile in flight.
    /// </summary>
    /// <param name="angle">The angle.</param>
    /// <param name="initialHeight">The initial height.</param>
    /// <param name="velocity">The velocity.</param>
    /// <returns>time in seconds projectile was in flight</returns>
    static ld time_of_projectiles_flight(ld angle, ld initialHeight, ld velocity)
    {
        ld vy = velocity * sin(angle * RADIAN);
        cout << "vy = " << vy << endl;
        cout <<"initialHeight = " << initialHeight << endl;
        return (vy + (sqrt((vy * vy) + 2.0 * _Ga_ * initialHeight))) / _Ga_;
    }

    /// <summary>
    /// calculates the range of a projectiles flight.
    /// </summary>
    /// <param name="angle">The angle.</param>
    /// <param name="initialHeight">The initial height.</param>
    /// <param name="velocity">The velocity.</param>
    /// <returns></returns>
    static ld range_of_projectile_flight(ld angle, ld initialHeight, ld velocity)
    {
        return velocity * cos(angle * RADIAN) * time_of_projectiles_flight(angle, initialHeight, velocity);
    }

    /// <summary>
    /// calculates the maximum height of a projectile.
    /// </summary>
    /// <param name="angle">The angle.</param>
    /// <param name="initialHeight">The initial height.</param>
    /// <param name="velocity">The velocity.</param>
    /// <returns></returns>
    static ld maximum_height_of_projectile(ld angle, ld initialHeight, ld velocity)
    {
        ld vy = velocity * sin(angle * RADIAN);
        return initialHeight + ((vy * vy) / (2.0 * _Ga_));
    }

    /// <summary>
    /// calculates the air time from an initial velocity of 0
    /// </summary>
    /// <param name="displacement">The total displacement.</param>
    /// <returns>time is seconds in air</returns>
    static ld air_time_initial_velocity0_y0(ld displacement)
    {
        return sqrt((-2*(displacement))/_Ga_);
    }


    /// <summary>
    /// calculates the initial velocity of the horizontal component
    /// </summary>
    /// <param name="y0">The initial starting height.</param>
    /// <param name="displacement">The displacement.</param>
    /// <returns></returns>
    static ld velocity_initial_horizontal_component(ld y0, ld displacement)
    {
        return sqrt((-_Ga_/(-2 * y0)))* displacement;
    }

    /**
     * method: velocity_final_vertical_component(ld y0, ld yf = 0) const
     * arguments: y0 = starting height, yf = final vertical component default = 0
     * purpose:	calculates the final vertical component
     * returns: ld, final vertical velocity
     */
    static ld velocity_vertical_component(ld y0, ld yf)
    {
        return -sqrt(2 * (-_Ga_) * (yf - y0));
    }


    /**
     * method: velocity_final_vertical_component(ld y0, ld yf = 0) const
     * arguments: y0 = starting height, yf = final vertical component default = 0
     * purpose:	calculates the final vertical component
     * returns: ld, final vertical velocity
     */
    static vector<ld> final_projectile_velocity_vector(ld velocityY, ld velocityX)
    {
        vector_values[0] = sqrt(velocityY * velocityY + velocityX * velocityX);
        vector_values[1] = atan(velocityY / velocityX)*DEGREE;
        return vector_values;
    }

    /**NOT WORKING RIGHT
     * method: velocity_soccer_kick(ld toGoal, ld height_at_goal, ld angle) const
     * arguments: distance to goal, height ball is at goal, and initial angle of kick
     * purpose:	calculates the final velocity of both component vectors
     * returns: ld, magnitude of final velocity vector
     */
    static ld velocity_soccer_kick(ld toGoal, ld height_at_goal, ld angle)
    {
        return sqrt(pow(horizontal_velocity_using_distance_angle_height(toGoal, height_at_goal, angle), 2) +
                    pow(vertical_velocity_by_Xvelocity_with_angle(horizontal_velocity_using_distance_angle_height(toGoal, height_at_goal, angle), angle), 2));
    }

    /**
     * method: horizontal_velocity_using_distance_angle_height(ld targetDistance, ld targetHeight, ld angle, ld acceleration)
     * arguments: distance, height, angle, acceleration = default is -9.8
     * purpose:	finds x component velocity
     * returns: ld, velocity of X component
     */
    static ld horizontal_velocity_using_distance_angle_height(ld targetDistance, ld targetHeight, ld angle, ld acceleration = _Ga_)
    {
        return targetDistance * sqrt(-acceleration/((2 * (targetDistance * tan(angle*RADIAN) - targetHeight))));
    }
    /**
     * @brief
     * @param xVelocity
     * @param angle
     * @return
     */
    static ld vertical_velocity_by_Xvelocity_with_angle(ld xVelocity, ld angle)
    {
        return xVelocity * tan(angle*RADIAN);
    }

    static ld horizontal_velocity_of_projectile_at_max_altitude(ld angle, ld velocity)
    {
        return velocity * cos(angle * RADIAN);
    }
    static ld vertical_velocity_of_projectile_at_max_altitude(ld angle, ld velocity)
    {
        return velocity * sin(angle * RADIAN);
    }


    /// <summary>
    /// uses quadratic formula to return two angles in a vector, the larger angle
    /// is the best angle to use
    /// </summary>
    /// <param name="launchVelocity">The launch velocity.</param>
    /// <param name="releaseHeight">Height of the ball at its release.</param>
    /// <param name="hoopDistance">The hoop distance from shot.</param>
    /// <returns>angle to shoot</returns>
    template<typename T>
    static vector<T> basketball_angles(T launchVelocity, T releaseHeight, T hoopDistance, ld hoopHeight = 3.048)
    {
        vector<T> angles;
        ld a = (((_Ga_) * (hoopDistance * hoopDistance)) / (2 * (launchVelocity * launchVelocity)));
        ld b = -hoopDistance;
        ld c = ((hoopHeight - releaseHeight) + a);
        angles.push_back(atan(-((b)+sqrt((b * b) - 4 * a * c)) / (2 * a))*DEGREE);
        angles.push_back(atan(-((b)-sqrt((b * b) - 4 * a * c)) / (2 * a))*DEGREE);

        return angles;
    }

    static ld starting_height_of_projectile(ld angle, ld velocity)
    {
        return (velocity * sin(angle * RADIAN)) / (-_Ga_);
    }
    static ld height(ld time, ld a = _Ga_)
    {
        return (a * time * time) / 2;
    }
    static ld height(ld x, ld v, ld a)
    {
        auto t = x / v;
        return (a * t * t) / 2;
    }
    /**
     * @brief You're windsurfing at v0 (L/T) when a gust hits, accelerating your sailboard
     * at acc (L/T^2) at degrees theta to your original direction. If the gust lasts
     * t (T), what's the magnitude of the board's displacement during this time?
     * @param v0 The initial velocity of the board (L/T)
     * @param acc The acceleration of the board (L/T^2)
     * @param theta The angle of the gust (degrees)
     * @param t The duration of the gust (T)
     * @return The magnitude of the board's displacement during this time
     */
    static ld displacement_2d(ld v0, ld acc, ld theta, ld t) {
        auto x_a = acc * cos(theta*RADIAN);
        auto y_a = acc * sin(theta*RADIAN);
        auto x_d = v0*t + (1.0/2.0)*x_a*t*t;
        auto y_d = (1.0/2.0)*y_a*t*t;
        return sqrt(pow(x_d, 2) + pow(y_d, 2));
    }

    /**
     * @brief You're windsurfing at v0 (L/T) when a gust hits, accelerating your sailboard
     * at theta (degrees) to your original direction. The gust lasts t (T), and
     * the board's displacement during this time is d (L). Find the magnitude of
     * the board's acceleration during the gust.
     * @param v0 The initial velocity of the board (L/T)
     * @param theta The angle of the gust (degrees)
     * @param t The duration of the gust (T)
     * @param d The magnitude of the board's displacement during this time (L)
     * @return The magnitude of the board's acceleration during the gust
     */
    static ld acceleration_2d(ld v0, ld theta, ld t, ld d) {
        auto x_d = d*cos(theta*RADIAN);
        auto y_d = d*sin(theta*RADIAN);
        auto x_a = (2*x_d - v0*t)/(t*t);
        auto y_a = (2*y_d)/(t*t);
        return sqrt(pow(x_a, 2) + pow(y_a, 2));
    }

    /**
     * @brief A delivery drone approaches a customer's porch, flying h (L) above the porch
     * at v0 (L/T). (a) At what horizontal distance from the desired landing spot
     * should it release a package? (b) At what speed will the package hit the porch?
     */
    static vector<ld> delivery_drone_package_drop_data(ld h, ld v0) {
        vector<ld> results;
        auto time_y = sqrt(2*h/(_Ga_));
        results.push_back(v0*time_y);
        auto vy = GA*time_y;
        results.push_back(sqrt(vy*vy + v0*v0));
        return results;
    }

    /**
     * A projectile has horizontal range R (L) on level ground and reaches maximum
     * height h (L). Find its initial speed.
     */
    static ld projectile_initial_speed(ld R, ld h) {
        return sqrt(2*h*_Ga_ + (((R*R) * _Ga_)/(8.0 * h)));
    }




    ~Kinematics()
    {
        delete _kinematicPtr;
    }

private:
    static void countIncrease() { kinematics_objectCount += 1; }
    static void countDecrease() { kinematics_objectCount -= 1; }
};


#endif //PHYSICSFORMULA_KINEMATICS_H
