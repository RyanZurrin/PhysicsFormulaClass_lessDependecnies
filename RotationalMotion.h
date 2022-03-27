#ifndef PHYSICSFORMULA_ROTATIONALMOTION_H
#define PHYSICSFORMULA_ROTATIONALMOTION_H
/**
 * @class RotationalMotion
 * @details  class to add to the Physics class to help with solving complex physics problems
 * @author Ryan Zurrin
 * @date  11/15/2020
 */
#include "UniformCircularMotion.h"

static int rotationalMotion_objectCount = 0;

class RotationalMotion : UniformCircularMotion
{
public:
    RotationalMotion* _rotational_motionPtr;
    /**
     * @brief a structure filled with methods for finding the rotational inertia's of some commonly shaped objects
     */
    static struct RotationalInertia
    {
        /**
         * @brief calculates the moment of Inertia for a hoop about a cylinder axis
         * @param M is the mass
         * @param R is the radius
         * @returns moment of inertia
         */
        template<typename T>
        static auto hoop_aboutCylinderAxis(const T M, const T R)
        {
            return M * (R * R);
        }
        template<typename T>
        static auto hoop_aboutAnyDiameter(const T M, const T R)
        {
            return (M * (R * R)) / 2.0;
        }
        template<typename T>
        static auto solidCylinderOrDisk_aboutCylinderAxis(const T M, const T R)
        {
            return (M * (R * R)) / 2.0;
        }
        template<typename T>
        static auto thinRod_aboutAxisThroughCenterToLength(const T M, const T l)
        {
            return (M * (l * l)) / 12.0;
        }
        template<typename T>
        static auto solidSphere_aboutAnyDiameter(const T M, const T R)
        {
            return (2.0 * M * (R * R)) / 5.0;
        }
        template<typename T>
        static auto annularCylinderRing_aboutCylinderAxis(const T M, const T R1, const T R2)
        {
            return (M / 2.0)* ((R1 * R1) + (R2 * R2));
        }
        template<typename T>
        static auto solidCylinder_aboutCentralDiameter(const T M, const T R, const T l)
        {
            return ((M * (R * R)) / 4.0) + ((M * (l * l)) / 12.0);
        }
        template<typename T>
        static auto thinRod_aboutAxisThroughOneEndToLength(const T M, const T l)
        {
            return (M * (l * l)) / 3.0;
        }
        template<typename T>
        static auto thinSphericalShell_aboutAnyDiameter(const T M, const T R)
        {
            return (2 * M * (R * R)) / 3;
        }
        template<typename T>
        static auto slab_aboutAxisThroughCenter(const T M, const T sideA, const T sideB)
        {
            return (M * ((sideA * sideA) + (sideB * sideB)) / 12.0);
        }
    }inertia;

    RotationalMotion()
    {
        _rotational_motionPtr = nullptr;
        _angular_acceleration_ = 0.0;
        _linear_acceleration_ = 0.0;
        countIncrease();
    }
    RotationalMotion(ld rpm, ld time)
    {
        _rotational_motionPtr = nullptr;
        setAngularVelocityW_(revMin_to_radSec(rpm));
        _angular_acceleration_ = getAngularVelocityW() / time;
        _linear_acceleration_ = rpm / time;
        countIncrease();
    }

    void set_angular_acceleration(const ld ac) { _angular_acceleration_ = ac; }
    void set_linear_acceleration(const ld ac) { _linear_acceleration_= ac; }
    ld get_angular_acceleration()const { return _angular_acceleration_; }
    ld get_linear_acceleration()const { return _linear_acceleration_; }
    void show_angular_acceleration()const { cout << "angular acceleration: " << _angular_acceleration_ << endl; }
    void show_linear_acceleration()const { cout << "linear acceleration: " <<_linear_acceleration_ << endl; }

    /**
     * @brief calculates the angular acceleration
     * @param w is the know angular velocity or torque
     * @param rt is the radius or the time, if using torque use inertia(I) here Not r ro t
     * @returns the angular acceleration
     */
    ld static angularAcceleration(const ld w, const ld rt)
    {
        return w / rt;
    }

    /**
     * @brief calculate the angular acceleration using using net torque and the Inertia T/I
     *
     */
    ld static angularAcceleration(const ld F, const ld r, const ld I)
    {
        return (F*r)/ I;
    }

    /**
     * @brief calculates the angular acceleration using the transformed kinematics equation wf^2=wi^2+2*a*rad
     * @param wi initial angular velocity
     * @param wf final angular velocity
     * @param rad total rotation in rad usually being multiplied by PI
     * @returns the angular velocity rad/s^2
     */
    ld static angularAcceleration_K(const ld wi, const ld wf, const ld rad)
    {
        return ((wf * wf) - (wi * wi)) / (2 * (rad));
    }

    /**
     * @brief calculates the angular acceleration of a spinning grind wheel with applied frictional coefficient
     * @param mass is in kg
     * @param r is the radius
     * @param Force is the force being applied
     * @param fC is the frictional Coefficient of the material being pressed to the wheel
     * @returns the angular acceleration (2 * fC * Force) / (mass * r)
     */
    ld static angularAcceleration_K(const ld mass, const ld r, const ld Force, const ld fC)
    {
        return ((2 * fC * Force) / (mass * r));
    }

    /**
     * @brief calculates the angular acceleration using net torque and the rotational inertia of an object
     * @param netTorque is the torque force
     * @param I can be calculated with the inertia methods structure if not given
     * @returns the angular acceleration
     */
    ld static angularAcceleration_usingTorque_andInertia(const ld netTorque, const ld I)
    {
        return netTorque / I;
    }

    /**
     * @brief calculates the angular acceleration using the kinematics formula vf^2 = vi^2 + 2*a*t
     * reworked as wf^2 = wi^2 + 2 * a * rotationTheta = w = (2*a*rotationTheta)^.5
     * @param angularAcceleration is the alpha
     * @param radians is the angle rotating in radians
     * @return angular velocity
     */
    ld static angularVelocity_kinematicsFormula(const ld angularAcceleration, const ld radians)
    {
        return pow(2 * angularAcceleration * radians, .5);
    }

    /**
     * @brief calculates the angular velocity using the definition of angular momentum L=Iw so w=L/I
     * @param Lv is the momentum of an object if L/I or the velocity if v/r v=tangential velocity(linear)
     * @param Ir is the inertia of an object if L/I or the radius if v/r  r= radius
     * @return angular velocity rad/s
     */
    ld static angularVelocity(const ld Lv, const ld Ir)
    {
        return Lv / Ir;
    }

    /**
     * @brief calculates the final angular velocity
     * @param Aa is the angular acceleration
     * @param seconds is the amount of seconds that pass
     * @param wi is the initial angular velocity, default is at 0
     * @returns the final angular velocity
     */
    ld static angularVelocity_final(const ld Aa, const ld seconds, const ld wi = 0.0)
    {
        return wi + Aa * seconds;
    }
    /**
     * @brief calculates the linear acceleration
     * @param lv is the known linear velocity
     * @param tr is the time or radius, works with both
     * @returns linear acceleration(tangential acceleration)
     */
    ld static linearAcceleration(const ld lv, const ld tr)
    {
        return lv / tr;
    }

    /**
     * @brief calculates the angular momentum using radius, Force, and time
     * @param r is the radius
     * @param F is the force
     * @param t is the time
     * @returns momentum in kgm^2/s
     */
    ld static angularMomentum(const ld r, const ld F, const ld t)
    {
        return r * F * t;
    }

    /**
     * @brief calculate the angular momentum of a object
     * @param _I is the moment of inertia of the object
     * @param w is the angular velocity
     * @returns the the angular momentum kgm^2/s
     */
    ld static angularMomentum(const ld _I, const ld w)
    {
        return _I * w;
    }

    /**
     * @brief calculates the linear acceleration which is (la = deltaV/deltaT, deltaV = rw, so la = r*deltaW/deltaT, a = deltaW/deltaT, so la = ra)
     * @param r is the radius
     * @param a is the angular acceleration
     * @returns the tangential acceleration(linear acceleration)
     */
    ld static tangentialAcceleration(const ld r, const ld a)
    {
        return r * a;
    }

    /**
     * @brief calculates the tangential velocity
     * @param w is the angular velocity
     * @param r is the radius
     * @returns tangential velocity m/s
     */
    ld static tangentialVelocity(const ld w, const ld r)
    {
        return w * r;
    }

    /**
     * @brief calculates the angular displacement using the adapted kinematics formula wf^2 =wi^2 + 2*a*t
     * @param wi initial angular velocity
     * @param wf final angular velocity
     * @param Aa angular acceleration
     * @param mode "rad" or "rev", radians or revolutions
     * @returns the total displacement in rad must divide
     */
    ld static theta_from_kinematics(const ld wi, const ld wf, const ld Aa, const string mode = "rev")
    {
        if(mode == "rad")
        {
            return ((wf * wf) - (wi * wi)) / (2 * (Aa));
        }
        return ((wf * wf) - (wi * wi)) / (2 * (Aa))/(2*_PI_);

    }


    /**
     * @brief calculates the time to stop from known angular velocities
     */
    ld static timeToStopSpinning(const ld startAngVelocity, const ld stoppingAngularAcceleration)
    {
        return -startAngVelocity / stoppingAngularAcceleration;
    }

    /**
     * @brief Sums inertia's of a system to return the total inertia
     */
    ld static inertiaSUM(const ld i1 = 0.0, const ld i2 = 0.0, const ld i3 = 0.0,const ld i4 = 0.0,
                         const ld i5 = 0.0, const ld i6 = 0.0, const ld i7 = 0.0, const ld i8 = 0.0,
                         const ld i9 = 0.0, const ld i10 = 0.0, const ld i11 = 0.0, const ld i12 = 0.0)
    {
        return i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9 + i10 + i11 + i12;
    }


    /**
     * @brief calculate the net Work done in rotation
     * @param netTorque is the total sum of all the torques acting in a system
     * @param rad is the total distance of rotation expressed in rad
     * @returns net work causing rotation
     */
    ld static netWork(const ld netTorque, const ld rad)
    {
        return netTorque * rad;
    }

    /**
     * @brief calculates the net torque
     * @param L is the change in angular momentum
     * @param t is the time it takes
     * @returns the net torque
     */
    ld static netTorque(const ld L, const ld t)
    {
        return L / t;
    }

    /**
     * @brief calculates the net torque using the radius and Force and angle
     * @param r is the radius
     * @param F is the force being applied in Newtons
     * @param angleTheta is the angle the force is applied, default is at 90 degrees
     * @return the net torque Nm
     */
    ld static netTorque(const ld r, const ld F, const ld angleTheta = 90)
    {
        return r * F * sin(angleTheta * RADIAN);
    }

    /**
     * @brief calculates the work-energy-theorem for rotational motion only'
     * @param iRi initial Rotational Inertia
     * @param iAv initial Angular Velocity
     * @param fRi final Rotational Inertia
     * @param fAv final Angular Velocity
     * @returns the net Work
     */
    ld static work_energy_theorem_for_rotation(const ld iRi, const ld iAv, const ld fRi, const ld fAv)
    {
        return (.5 * fRi * (fAv * fAv)) - (.5 * iRi * (iAv * iAv));
    }

    /**
     * @brief calculates the rotational kinetic energy for an object what a moment of inertia _I and an angualr velocity w
     * @param _I is the moment of inertia
     * @param w is the angular velocity
     * @returns the rotational kinetic energy
     */
    ld static kinetic_energy_for_rotation(const ld _I, const ld w)
    {
        return (.5 * _I * (w * w));
    }

    /**
     * @brief finds the max height of a helicptor of mass m a known KE
     */
    ld static maxHeight(const ld KE, const ld mass)
    {
        return ((KE) / (mass * _Ga_));
    }

    /**
     * @brief calculates the speed of a cylinder rolling down an incline
     */
    ld static speedOfRollingCylinder(const ld height)
    {
        return pow(((4.0 * _Ga_ * height) / 3.0), .5);
    }
    /**
     * @brief calculates the distance something moves from the radius and the radians
     * @param radius is the radius of thing moving
     * @param radians is the total rotation in radians
     * @returns the distance traveled.
     */
    ld static distance(const ld radius, const ld radians)
    {
        return radius * radians;
    }

    /**
     * @brief calculates the distance traveled using the tangential velocity
     * @param w is the angular velocity
     * @param r is the radius in m
     * @param seconds is the time in seconds
     * @returns the distance traveled
     */
    ld static distance(const ld w, const ld r, const ld seconds)
    {
        return w * r * seconds;
    }

    /**
     * @brief calculates the rotational torque which is the rotational analog of newtons law of F = ma
     * @param m is the mass
     * @param r is the radius
     * @param aa is the angular acceleration
     * @returns torque of rotation
     */
    ld static rotationalTorque(const ld m, const ld r, const ld aa)
    {
        return m * (r * r) * aa;
    }

    /**
     * @brief calculates the angular velocity of a spinning ice skater
     * @param exA_inertia is the inertia of the skater with arms extended
     * @param exA_angularVelocity is the rate of the skaters spinning in rev/s
     * @param clA_inertia is the inertia of the skater with closed arms
     * @returns the angular velocity of the skater with closed arms
     */
    ld static angularVelocitySpinningSkater(const ld exA_inertia, const ld exA_angularVelocity, const ld clA_inertia)
    {
        return (exA_inertia / clA_inertia) * exA_angularVelocity;
    }

    /**
     * @brief calculates the amount of revolutions it takes to stop spinning
     */
    ld static revolutionsToStop(const ld a, const ld wi, const ld wf =0.0)
    {
        return (((wf * wf) - (wi * wi)) / (2 * a)) / (2 * _PI_);
    }

    /**
     * @brief calculates the force needed to be applied on a chain to get a bike wheel of a certain mass to
     * a certain acceleration.
     * @param tangentialResistiveForce is the resistive force applied against the force of the chain
     * @param mass is the mass of the wheel in kg
     * @param rOuter is the outer radius of wheel which is half of the diameter if that is what is given and it
     * must be converted to m and not cm
     * @param rInner is the radius of the the chain sprocket must be converted to m as well
     * @param angAccel is the angular acceleration in question, we are looking for the force on the chain to
     * reach this angular acceleration
     * @returns the force on the chain in N (newtons)
     */
    ld static forceOnChainToReachAngularAcceleration(const ld tangentialResistiveForce, const ld mass, const ld rOuter, const ld rInner, const ld angAccel )
    {
        ld I = mass * (rOuter * rOuter);
        ld Ti = rOuter * tangentialResistiveForce;
        return (I * angAccel + Ti) / rInner;
    }

    /**
     * @brief calculates the system of answers for two point particles of mass m1 and m2 situated at the ends of a uniform rod of mass mRod that is capable
     * of rotating about an axis through its center and perpendicular to its length.
     * @param mRod is the mass of the rod
     * @param lRod is the length of the rod
     * @param m1 is the mass of point particle 1
     * @param m2 is the mass of point particle 2
     * @param w is the angular speed the rod rotates at
     * @returns the vector with
     * <total moment of inertia for system, KE of system in J, if rod mass negligible new Inertia of system, new KE of system if rods mass negligible>
     */
    vector<ld> static inertiaAndKEofRotatingPointParticlesOnRod(const ld mRod, const ld lRod, const ld m1, const ld m2, const ld w)
    {
        vector<ld> results = { 0.0,0.0,0.0,0.0 };
        results[0] = (mRod * (lRod * lRod)) / (12) + (m1 * (lRod / 2.0)) + (m2 * (lRod / 2.0));
        results[1] = .5 * results[0] * (w * w);
        results[2] = (m1 * (lRod / 2.0)) + (m2 * (lRod / 2.0));
        results[3] = .5 * results[2] * (w * w);

        return results;
    }


    ~RotationalMotion()
    {
        delete _rotational_motionPtr;
        countDecrease();
    }

private:
    ld _angular_acceleration_;
    ld _linear_acceleration_;
    static void countIncrease() { rotationalMotion_objectCount += 1; }
    static void countDecrease() { rotationalMotion_objectCount -= 1; }

};
#endif //PHYSICSFORMULA_ROTATIONALMOTION_H
