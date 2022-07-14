//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_TORQUE_H
#define PHYSICSFORMULA_TORQUE_H
#include "Constants.h"
/**
 * @class Torque
 * @details class for composition with Physics class to help in solving complex physics problems
 * @author Ryan Zurrin
 * @date   10/26/2020
 */

class Torque
{
public:

    //constructor
    Torque(){}

    /**
     * @brief Returns the magnitude of torque
     * @param r is the distance from the pivot point to the point where the force
     * is applied
     * @param F is the magnitude of the force
     * @param theta is the angle between the force and the vector directed from the
     * point of application to the pivot point
     * @returns magnitude of torque
     */
    ld static torque(const ld r, const ld F, const ld theta)
    {
        return r * F * sin(theta * constants::RADIAN);
    }

    /**
     * @brief Returns the torque using the perpendicular lever arm and Force as input values
     * @param pla is the value of the perpendicularLeverArm
     * @param F is the magnitude of the force
     * @returns magnitude of torque
     */
    ld static torque(const ld pla, const ld F)
    {
        return pla * F;
    }

    /**
     * @brief Returns magnitude of the perpendicular lever arm
     * @param r is the distance from the pivot point to the point where the force
     * is applied
     * @param theta is the angle between the force and the vector directed from the
     * point of application to the pivot point
     */
    ld static perpendicular_lever_arm(const ld r, const ld theta)
    {
        return r * sin(theta * constants::RADIAN);
    }

    /**
     * @brief Returns the unknown r value for one side of a balance seesaw occupied by two different sized masses
     * @param m1 is the mass of the first object on the side of the known r value
     * @param r1 is the distance from the pivot to the point of applied force, center of seesaw to center of sitting spot
     * @param m2 is the mass of the second object on the side of the unknown r value
     * @returns the second r value needed to balance a seesaw system
     */
    ld static torque_r2_val_seesaw(const ld m1, const ld r1, const ld m2)
    {
        return r1 * (m1 / m2);
    }

    /**
     * @brief return the net force on a pivot calculated by adding up the total
     * weight of a system.
     * @param m is a vector of the masses of the objects in the system
     * same pivot, these are all defaulted to 0 so you only enter the masses you need making sure
     * to include any negative forces in the calculation if there are any
     */
    ld static net_force_by_pivot(const vector<ld>& m)
    {
        ld net_force = 0;
        for (ld i : m)
        {
            net_force += i * constants::Ga;
        }
        return net_force;
    }

    /**
     * @brief solves a system for an unknown r value
     * @param m1 is the mass of the first weight
     * @param r1 is the length of the first mass cg to the pivot
     * @param theta1 is the angle of the applied force
     * @param m2 is the mass of the second weight
     * @param r2 is the length of the first mass cg to pivot
     * @param theta2 is the angle of the second force
     * @param mRod is the mass of the rod used
     * @param lRod is length of the rod used
     * @param mr3 is the mass or the distance of given variable from which we need to find the other part
     * @param theta3 is the angle of the mr3 force
     * @returns vector with the mass, distance, force up on pin, force down on pin
     */
    vector<ld> static rod_of_mass_m_and_length_l(const ld m1,
                                                 const ld r1,
                                                 const ld theta1,
                                                 const ld m2,
                                                 const ld r2,
                                                 const ld theta2,
                                                 const ld mRod,
                                                 const ld lRod,
                                                 const ld mr3 = 0,
                                                 const ld theta3 = 90)
    {
        vector<ld> result = { 0.0,0.0,0.0};
        double fu, fd, fd2;
        if(ceill( mr3) == 0)
        {

            result[0] = m1 + m2 - mRod;
            result[1] = ((m1 * r1 * sin(theta1 * constants::RADIAN)) +
                    (m2 * r2 * sin(theta2* constants::RADIAN)) -
                    (mRod * (.5 * lRod) * sin(theta3 * constants::RADIAN))) /
                            (result[0]);
            fu = (m1/1000 + m2/1000) * constants::Ga;
            fd = mRod/1000 + result[0]/1000;
            result[2] = fu - fd;
            return result;
        }


        result[0] = ((m1 * r1 * sin(theta1 * constants::RADIAN)) +
                (m2 * r2 * sin(theta2 * constants::RADIAN)) -
                (mRod * (.5 * lRod) * sin(theta3 * constants::RADIAN))) / (mr3);
        fu = (m1 / 1000 + m2 / 1000) * constants::Ga;
        fd = (mRod / 1000 + mr3 / 1000) * constants::Ga;
        fd2 = (mRod / 1000 + result[0] / 1000) * constants::Ga;
        result[1] = fu - fd;
        result[2] = fd2 - fu;
        return result;
    }

    /**
     * @brief calculates and returns the distance a fulcrum needs to be to lift a certain waight mass with it being a certain length
     */
    ld static fulcrum_position(const ld massToLift,  const ld leverLength, const ld limitForce)
    {
        return (massToLift * constants::Ga * leverLength) / (limitForce + massToLift * constants::Ga);
    }

    /**
 * calculates the total force required to life a wheelbarrow
 * @param w is the weight of the wheelbarrow and load
 * @param ro is the the distance from cg(center of gravity to where the wheel touches the ground
 * @param ri is the distance from the cg to where you are holding the wheelbarrow
 * @returns force needed to lift wheelbarrow
 */
    ld static  force_to_lift_wheelbarrow(const ld w, const ld ro, const ld ri)
    {
        return w * constants::Ga * (ro / ri);
    }

    /**
     * @brief calculates the weight of the load in a wheelbarrow
     * @param Mb is the mass of the wheelbarrow
     * @param rToHandlesTo_cg is the lever arm from the lifting point on handles to the center of gravity(cg)
     * @param cg_toPivot is the lever arm from the pivot to the center of gravity(cg)
     * @param liftingForce is the force required to lift up the wheelbarrow, can be found by standing on a scale while holding
     * the wheelbarrow up and getting a reading in pounds and then converting
     * @returns the weight of a wheelbarrow load
     */
    ld static weight_load_of_wheelbarrow(const ld Mb, const ld rToHandlesTo_cg, const ld cg_toPivot, const ld liftingForce)
    {
        ld  a, b,  c;
        a = ((Mb * constants::Ga * cg_toPivot) / (rToHandlesTo_cg));
        b = ((constants::Ga * cg_toPivot) / rToHandlesTo_cg);
        c = (liftingForce - a) / b;

        return c;
    }



    /**
     * Returns the machanical advantage of a simple machine
     * MA = Fo/Fi = li/lo  ;where Fo = output force, Fi = input force, li = distance from input source to pivot
     * , lo = distance from output source to pivot.
     * @param lo is the the distance from cg to pivot, on a crank this is the radius of the crank
     * @param li is the distance from the cg to where the force is applied, on a crank this is the length from center
     * of radius to center of the lever for cranking
     * @returns the mechanical advantage of a simple machine
     */
    ld static mechanical_advantage(const ld li, const ld lo)
    {
        return li / lo;
    }

    /**
     * @brief calculates the net torque from vector components
     * @param m is the vector of components
     * @returns the net torque vector
     */
     vector<ld> static net_torque(const vector<vector<ld>> m) {
        vector<ld> net_torque = {0.0,0.0,0.0};
        for (ld i : m[0])
        {
            net_torque[0] += i;
        }
        for (ld i : m[1])
        {
            net_torque[1] += i;
        }
        for (ld i : m[2])
        {
            net_torque[2] += i;
        }
        return net_torque;
     }

    // destructor
    ~Torque() {}
};
#endif //PHYSICSFORMULA_TORQUE_H
