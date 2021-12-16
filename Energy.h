//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_ENERGY_H
#define PHYSICSFORMULA_ENERGY_H
/**
 * @class Energy
 * @details sub class contained within the Physics class and used for solving
 * complex physics problems
 * @author Ryan Zurrin
 * @date   10/21/2020
 */
#include <iostream>
#include "Vector2D.h"
using namespace std;
#include <cmath>
typedef  long double ld;

static int energy_objectCount = 0;

class Energy
{

public:

    // Energy pointer
    Energy* _energyPtr;


    static void countShow() { std::cout << "energy object count: " << energy_objectCount << std::endl; }

    /**
     * @brief  a structure containing the energy in joules of some common phenomena
     */
    struct EnergyOfEventsInJoules
    {
        const ld big_bang = pow(10, 68);
        const ld super_nova = pow(10, 44);
        const ld fusion_all_hydrogen_earths_oceans = pow(10, 34);
        const ld annual_world_energy_use = 4 * pow(10, 20);
        const ld large_fusion_bomb_9megaTon = 3.8 * pow(10, 16);
        const ld hydrogen_1kg_fusion_to_helium = 6.4 * pow(10, 14);
        const ld uranium_1kg_nuclear_fission = 8 * pow(10, 13);
        const ld fission_bomb_10kiloton = 4.2 * pow(10, 13);
        const ld barrel_crude_oil = 5.9 * pow(10, 9);
        const ld tnt_1ton = 4.2 * pow(10, 9);
        const ld gasoline_1gallon = 1.2 * pow(10, 8);
        const ld electricity_use_daily_per_home = 7 * pow(10, 7);
        const ld food_intake_adult_daily_recommended = 1.2 * pow(10, 7);
        const ld car_1000kg_at_90kmh = 3.1 * pow(10, 5);
        const ld fat_1g_or_9point3_kcal = 3.9 * pow(10, 4);
        const ld carbohydrate_1g_or_4point1_kcal = 1.7 * pow(10, 4);
        const ld protein_1g_or_4point1_kcal = 1.7 * pow(10, 4);
        const ld tennis_ball_100kmh = 22;
        const ld mosquito_point5ms = 1.3 * pow(10, -6);
        const ld single_electron_in_tv_tube_beam = 4.0 * pow(10, -15);
        const ld energy_to_break_dna_strand = pow(10, -19);
    }joules;
    /**
     * @brief a structure containing the efficiency percent of common human
     * body and mechanical devices
     */
    struct Efficiency
    {
        const int cycling_and_climbing = 20;
        const int swimming_surface = 2;
        const int swimming_submerged = 4;
        const int shoveling = 3;
        const int weightlifting = 9;
        const int steam_engine = 17;
        const int gasoline_engine = 30;
        const int diesel_engine = 35;
        const int nuclear_power_plant = 35;
        const int coal_power_plant = 42;
        const int electric_motor = 98;
        const int compact_fluorescent_light = 20;
        const int gas_heater_residential = 90;
        const int solar_cell = 10;
    }eff;
    /**
     * @brief Power output or consumption in watts per hour of some common things
     */
    struct Watts_Per_Hour
    {
        const ld supernova_peak = 5 * pow(10, 37);
        const ld milky_way_galaxy = pow(10, 37);
        const ld crab_nebula_pulsar = pow(10, 28);
        const ld sun_ours = 4 * pow(10, 26);
        const ld volcanic_eruption_maximum = 4 * pow(10, 15);
        const ld lightning_bolt = 2 * pow(10, 12);
        const ld nuclear_power_plant_total_electric_and_heat_transfer = 3 * pow(10, 9);
        const ld aircraft_carrier_total_useful_and_heat_transfer = pow(10, 8);
        const ld dragster_total_useful_and_heat_transfer = 2 * pow(10, 6);
        const ld car_total_useful_and_heat_transfer = 8 * pow(10, 4);
        const ld football_player_total_useful_and_heat_transfer = 5 * pow(10, 3);
        const ld clothes_dryer = 4 * pow(10, 3);
        const ld person_at_rest_all_heat_transfer = 100;
        const ld typical_incandescent_light_buld_total_useful_and_heat_transfer = 60;
        const ld heart_person_at_rest_total_useful_and_heat_transfer = 8;
        const ld electric_clock = 3;
        const ld pocket_calculator = pow(10, -3);

    }watts;

    //constructor
    Energy()
    {
        _energyPtr =  nullptr;
        _energyVal = 0.0;
        countIncrease();
    }

    Energy(ld val)
    {
        _energyPtr =  nullptr;
        _energyVal = 0.0;
        countIncrease();
    }


    /**
     * @brief Returns the conversion from joules to kilo calories
     * @param joules J
     * @returns kilocalories kc
     */
    static ld conversion_joules_to_kcal(const ld joules)
    {
        const int num = 4184;
        return joules / num;
    }
    /**
     * @brief Returns the work(W) done on a system by a constant force in the
     * direction of motion times the distance through which the force acts
     * @param force is the magnitude of the force on the system
     * @param displacement_magnitude is the displacement of the system
     * @param theta is the angle between the force vector and the displacement vector
     * @returns the work done on a system
     */
    static ld work(const ld force, const ld displacement_magnitude, const ld theta = 0)
    {
        return force * displacement_magnitude * cos(theta * RADIAN);
    }
    /**
     * @brief Returns the work when the mass, final velocity, and height of y are known
     * @param mass is the mass in kg
     * @param vf is the final velocity
     * @param h is the height of the y component
     * @param g is the acceleration which is defaulted to 9.8 for gravity
     * @returns the total work
     */
    static ld work2(const ld mass, const ld vf, const ld h, const ld g = 9.8)
    {
        return (.5 * mass * (vf * vf) + (mass * g * h));
    }
    /**
     * @brief Returns the work going up stairs with constant acceleration
     * F = mgh
     * @param mass in kg
     * @param height in m
     * @returns total work
     */
    static ld work3(const ld mass, const ld height)
    {
        return mass * _Ga_ * height;
    }
    /**
     * @brief calculates the amount of useful power output by elevator motor
     * P = (.5 * (balanceWeight * (velocityFinal * velocityFinal)) + ((9.8 * elevatorWeight * liftHeight) + 750 * (-35.0)))/(time)
     * @param elevatorWeight in kg
     * @param balanceWeight in kg
     * @param liftHeight in m, specifies the height the elevator must travel up
     * @param velocityFinal is the speed the elevator will achieve starting from a resting position,
     * initial velocity is assumed 0 in this formula
     * @param time in s the elevator travels up
     * @returns power output for elevator motor
     */
    static ld power_output_of_useful_energy_by_elevator_motor(const ld elevatorWeight, const ld balanceWeight, const ld liftHeight, const ld velocityFinal, const ld time)
    {
        const ld calculatedMass = balanceWeight - elevatorWeight;
        const ld v2 = pow(velocityFinal, 2);
        const ld m1 = _Ga_ * balanceWeight * liftHeight;
        const ld m2 = _Ga_ * calculatedMass * -liftHeight;
        const ld m3 = m1 + m2;
        const ld m = (.5 * balanceWeight) * v2;

        return (m + m3)/time ;
    }
    /**
     * @brief Returns the work down by friction lowering something down a slope
     * @param coefficient is of friction
     * @param mass in kg
     * @param theta1 in angle of force
     * @param distance is how far they travel over
     * @param theta2 is defaulted to 180 degrees if you set your coordinate system perpendicular to the motion
     * @returns the work done by friction
     */
    static ld work_friction_down_slope(const ld coefficient, const ld mass, const ld theta1, const ld distance, const ld theta2 = 180)
    {
        return coefficient * mass * _Ga_ * cos(theta1 * RADIAN) * distance * cos(theta2);
    }
    /**
     * @brief Returns the kinetic energy of an object
     * fx = .5 * mass * (velocity * velocity)
     * @param mass of object in kg
     * @param velocity of object in m/s
     * @returns KE (kinetic energy)
     */
    static ld kinetic_energy_translational(const ld mass, const ld velocity)
    {
        return .5 * mass * (velocity * velocity);
    }
    /**
     * @brief Returns the velocity(speed) solved by rearranging the work-energy theorem
     * fx = sqrt((2 * netWork) / (mass))
     * @param netWork is the total energy in newtons
     * @param mass in kg
     * @returns the velocity
     */
    static ld velocity_from_work_energy_theorem(const ld netWork, const ld mass)
    {
        return sqrt((2 * netWork) / (mass));
    }
    /**
     * @brief calculates the initial velocity of a falling mass when friction is negligible
     * such as a roller coaster
     * @param h height in m
     * @param vi velocity initial
     * @returns the final velocity
     */
    static ld velocityFinal_fromHeight(const ld h, const ld vi = 0.0)
    {
        return sqrt((2 *_Ga_* abs(h) + (vi * vi)));
    }

    /**
     * @brief calculates the final velocity of a falling mass when friction is negligible
     * such as a roller coaster
     * @param h height in m
     * @param vf velocity initial
     * @returns the final velocity
     */
    static ld velocityInitial_fromHeight(const ld h, const ld vf = 0.0)
    {
        return sqrt((vf*vf)-2*_Ga_*abs(h));
    }

    /**
     * @brief Returns the speed calculated from something falling from a specified height
     * @param height is the height of the object
     * @param initialVelocity is the initial speed if not starting from a rest.
     * Default is 0 assumed to be starting from rest
     * @returns final speed
     */
    static ld speed_from_height(const ld height, const ld initialVelocity = 0)
    {
        return sqrt(2 * _Ga_ * height ) + initialVelocity;
    }
    /**
     * @brief Returns the distance traveld
     * @param netWork is the total work from a system
     * @param frictionForce is the force the friction is causing on the system
     * @returns the distance
     */
    static ld distance(const ld netWork, const ld frictionForce)
    {
        return abs(netWork / frictionForce);
    }
    /**
     * @brief Returns the change in gravitational potential energy
     * fx = mass * _G_ * height;
     * @param mass is in kg
     * @param height is the displacement in the y value
     */
    static ld potential_energy_gravity_PEg(const ld mass, const ld height)
    {
        return mass * _Ga_ * height;
    }
    /**
     * @brief Returns the potential energy of a conservative source, such as a spring
     * @param forceConstant us unitless
     * @param deformation is the amount of change in the system
     */
    static ld potential_energy_conservative_PE(const ld forceConstant, const ld deformation)
    {
        return .5 * (forceConstant * (deformation * deformation));
    }
    /**
     * @brief Returns the force on impact
     * @param mass in kg
     * @param height from which the fall occurs
     * @param compressionDistance is the distance of deformation on impact
     * @returns the net force acting on the system
     */
    static ld force_to_stop(const ld mass, const ld height, const ld compressionDistance)
    {
        return ((mass * _Ga_) * height)/ (compressionDistance);
    }
    /**
     * @brief Returns the speed of object just after release using the equation
     * for the conservation of mechanical energy solved for the final velocity just
     * after toy car released by spring
     * @param k is the force in Newtons/min
     * @param m is the mass in kg of object
     * @param x is the deformation of the spring used or object of PE
     * @returns the speed m/s
     */
    static ld conservation_equation_for_velocityFinal_bottom(const ld k, const ld m, const ld x)
    {
        return sqrt(k / m) * x;
    }
    /**
     * @brief Returns the speed of an object after it reaches the top of a slope
     * from being pushed by a spring
     * @param k is the force in N/m
     * @param m is the mass in kg
     * @param x is the deformation of the spring
     * @param y is the change in the y component value
     * @returns the final speed
     *
     */
    static ld conservation_equation_for_velocityFinal_top(const ld k, const ld m, const ld x, const ld y)
    {
        return sqrt((k / m) * (x * x) - (2 * _Ga_ * y));
    }
    /**
     * @brief Returns the distance traveled sliding on level surface
     * fx = m * (vi * vi) / (2 * ff)
     * @param m is the mass in kg
     * @param vi is the initial velocity
     * @param ff is the frictional force
     * @returns the distance traveled while sliding on level surface
     */
    static ld distance_traveled_sliding_level(const ld m, const ld vi, const ld ff)
    {
        return (m * (vi * vi) / (2 * ff));
    }
    /**
     * @brief Returns the distance traveled sliding on an incline
     * fx = (.5 * (m * (vi * vi)) / (ff + (m * _G_) * sin(theta * RADIAN)))
     * @param m is the mass in kg
     * @param vi is the initial velocity
     * @param ff is the frictional force
     * @param theta is the angle of the slope
     * @returns the distance traveled while sliding on incline
     */
    static ld distance_traveled_sliding_slope(const ld m, const ld vi, const ld ff, const ld theta)
    {
        return (.5 * (m * (vi * vi)) / (ff + (m * _Ga_) * sin(theta * RADIAN)));
    }
    /**
     * @brief Returns the efficiency (Eff) of an energy conversion process
     * fx = workEnergyOut / totalEnergyIn
     * @param workEnergyOut is the total energy used
     * @param totalEnergyIn is the total amount of energy being provided to a system for work
     * @returns the efficiency
     */
    static ld efficiency(const ld workEnergyOut, const ld totalEnergyIn)
    {
        return workEnergyOut / totalEnergyIn;
    }
    /**
     * @brief Returns the power
     */
    static ld power(const ld work, const ld time)
    {
        return work / time;
    }
    /**
     * @brief Returns the power output of someone jumping
     * @param mass in kg
     * @param distanceBottom in meters is the height from ground to shoulder
     * @param distanceTop in meters is the height from the ground to hight of jump
     * @returns watts used to make the jump
     */
    static ld power_to_jump(const ld mass, const ld distanceBottom, const ld distanceTop)
    {
        return mass * _Ga_ * distanceTop * sqrt((_Ga_ * ((distanceTop / distanceBottom) - 1) / (2 * distanceBottom)));
    }
    /**
     * @brief calculates the time to do work based off of power output
     * @param work is in joules. w = Fd = mgh
     * @param power is in watts
     * @returns the time to perform work
     */
    static ld time_to_do_work(const ld work, const ld power)
    {
        return work / power;
    }

    /**
     * @brief Returns the power in watts required to accelerate an object from rest to a specific velocity
     * over a period of time given the objects mass
     * @param mass in kg
     * @param velocity in m/s^2
     * @param time in s
     * @returns power in watts
     */
    static ld power_to_reach_velocity_from_rest_given_mass(const ld mass, const ld velocity, const ld time)
    {
        return (mass * (velocity * velocity) / (2 * _Ga_ * time));
    }

    /**
     * @brief calculates the force needed to bring a car to rest given its mass, its speed and the distance
     * it took to stop. This can be used to calculate the force from crashes and similar scenarios
     * @param mass in gk
     * @param velocity in m/s
     * @param distance in m
     * @returns the force exerted to make stop
     */
    static ld force_needed_to_bring_car_to_rest(const ld mass, const ld velocity, const ld distance)
    {
        return (.5 * mass * (velocity * velocity)) / (distance);
    }
    /**
     * @brief calculates the weight of a system from the loss in PE over a distance
     * @param jouleLoss is the total loss in PE(potential energy)
     * @param distance is the total distance that caused the energy loss
     * @returns the weight of a system
     */
    static ld weight_from_joule_loss_over_distance(const ld jouleLoss, const ld distance)
    {
        return jouleLoss / distance;
    }
    /**
     * @brief Returns the calculation of the amount of compression on a spring with a given K constant
     * and knowing the mass and velocity of the object that collides with it.
     * x = sqrt((mass * (velocity * velocity)) / k)
     * @param mass in kg
     * @param velocity in m/s
     * @param k is the spring constant
     * @returns distance of compression in meters
     */
    static ld compressionDistanceCollisionWithSpring(const ld mass, const ld velocity, const ld k)
    {
        return sqrt((mass * (velocity * velocity)) / k);
    }
    /**
     * @brief calculates the spring constant when the mass, velocity, and total amount of compression on the spring is known
     * @param mass in kg
     * @param velocity in m/s
     * @param totalCompression in m
     * @returns the spring constant k
     */
    static ld spring_constant(const ld mass, const ld velocity, const ld totalCompression)
    {
        return mass * (velocity * velocity) / (totalCompression * totalCompression);
    }
    /**
     * @brief calculate the initial velocity needed to compress a spring a specified value
     * @param mass in kg
     * @param k is the spring constant
     * @param x is the distance of compression
     * @returns the initial speed needed to compress spring
     */
    static ld initial_speed_to_compress_spring(const ld mass, const ld k, const ld x)
    {
        return sqrt((k * (x * x) / mass));
    }
    /**
     * @brief calculates the height of something from two velocities
     * @param velocityStart is the initial velocity
     * @param velocityEnd is the velocity at the height in question
     * @returns height in meters
     */
    static ld height_from_velocity(const ld velocityStart, const ld velocityEnd)
    {
        return ((velocityStart * velocityStart) - (velocityEnd * velocityEnd)) / (2 * _Ga_);
    }
    /**
     * @brief calculates the kinetic energy in a falling mass.
     * @param mass in kg
     * @param finalDistance is the distance we are measureing the fall to ususally in a negitive
     * @param initialDistance is the where it fell from if not using zero as a start
     * @returns the kinetic energy
     */
    static ld kinetic_energy_falling_mass(const ld mass, const ld finalDistance, const ld initialDistance = 0)
    {
        return -mass * _Ga_ * (finalDistance + initialDistance);
    }
    /**
     * @brief Calculates the cost of an electrical unit based on the charge rate and power usage
     * @param powerUsage in Watts
     * @param cost per kw/h
     * @returns cost per hour
     */
    static ld cost_to_run_per_hour(const ld powerUsage, const ld cost)
    {
        return abs((powerUsage * cost) / 1000);
    }
    /**
     * @brief Calculates the cost of an electrical unit based on the charge rate and power usage
     * @param powerUsage in Watts
     * @param cost per kw/h
     * @returns cost per sec
     */
    static ld cost_to_run_per_sec(const ld powerUsage, const ld cost)
    {
        return abs((powerUsage * cost) / 1000) * 12/3600 * 100;
    }
    /**
     * @brief calculates and returns the tension force on a elevator cable
     * @param mass in kg
     * @param acceleration in m/s^2
     * @param friction frictional force
     */
    static ld tension_elevator_cable(const ld mass, const ld acceleration, const ld friction)
    {
        return mass * (acceleration + _Ga_) + friction;
    }
    /**
     * @brief Returns the final velocity
     * vf = sqrt(2 * acceleration * distance)
     * @param acceleration in m/s^2
     * @param distance in m
     * @returns final velocity
     */
    static ld final_velocity(const ld acceleration, const ld distance)
    {
        return sqrt(2 * acceleration * distance);
    }
    /**
     * @brief calculates the force needed to jump between two points
     * @param mass in kg
     * @param distanceTop in m
     * @param distanceBottom in m
     * @returns force in N(newtons)
     */
    static ld force_needed_to_jump_a_distance(const ld mass, const ld distanceTop, const ld distanceBottom)
    {
        return (mass * _Ga_ * distanceTop) / distanceBottom;
    }

    void setEnergyVal(ld val) { _energyVal = val; }

    ~Energy()
    {
        delete _energyPtr;
        countDecrease();
    }

private:
    static void countIncrease() { energy_objectCount += 1; }
    static void countDecrease() { energy_objectCount -= 1; }
    ld _energyVal;


};
#endif //PHYSICSFORMULA_ENERGY_H