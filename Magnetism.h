//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_MAGNETISM_H
#define PHYSICSFORMULA_MAGNETISM_H
/**
 * @class Magnetism
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @dateBuilt  3/18/2021
 * @lastEdit 3/21/2021
 */
#include "ElectricCurrent.h"
#define _PI 3.14159265358979323846
static int magnetism_objectCount = 0;
constexpr auto _GAUSS_ = 1.0e-4; //Tesla's
constexpr auto _µo_ = 4.0 * _π_* 1.0e-7;//permeability of free space


class Magnetism :
        public ElectricCurrent, public ElectricCharge
{
public:
    Magnetism* _magnetismPtr;

    Magnetism()
    {
        _magnetismPtr= nullptr;
        _magnetismVar = 0.0;
        countIncrease();
    }

    Magnetism(ld var)
    {
        _magnetismPtr= nullptr;
        _magnetismVar = 0.0;
        countIncrease();
    }


    /**
     * @brief copy constructor
     */
    Magnetism(const Magnetism& t)
    {
        _magnetismPtr = t._magnetismPtr;
        _magnetismVar = t._magnetismVar;
        countIncrease();
    }

    /**
     * #brief move constructor
     */
    Magnetism(Magnetism&& t) noexcept
    {
        _magnetismPtr = t._magnetismPtr;
        _magnetismVar = t._magnetismVar;
        countIncrease();
    }
    /**
     * @brief copy assignment operator
     */
    Magnetism& operator=(const Magnetism& t)
    {
        if (this != &t)
        {
            _magnetismPtr = t._magnetismPtr;
            _magnetismVar = t._magnetismVar;
            countIncrease();
        }
        return *this;
    }
    void setMagnetismVar(ld var) { _magnetismVar = var; }
    ld getMagVar() const { return _magnetismVar; }
    static void show_objectCount() { std::cout << "\n magnetism object count: "
                                               << magnetism_objectCount << std::endl; }
    static int get_objectCount() { return magnetism_objectCount; }

    /// <summary>
    /// Calculates the magnetic force (Lorentz force) on a charge q moving at
    /// a speed v in a magnetic field of strength B where theta is the angle
    /// between the directions of v and B.
    /// </summary>
    /// <param name="q">The charge in Coulombs.</param>
    /// <param name="v">The speed in m/s.</param>
    /// <param name="B">The magnetic field strength.</param>
    /// <param name="theta">The angle theta between the directions
    /// of v and B.</param>
    /// <returns>the magnetic force in newtons</returns>
    static ld magneticForce(const ld q, const ld v, const ld B, const ld theta);

    /// <summary>
    /// Calculates the magnetic force at a maximum angle of sin(90) which is 1.
    /// </summary>
    /// <param name="q">The q.</param>
    /// <param name="B">The b.</param>
    /// <param name="v">The v.</param>
    /// <returns>magnetic force (N)</returns>
    static ld magneticForceMax(const ld q, const ld B, const ld v);

    /// <summary>
    /// Calculates the charge of a particle moving at right angles to the
    /// magnetic field of B Tesla's with a speed of v m/s while experiencing a
    /// magnetic force of F newtons.
    /// force of F Newtons.
    /// </summary>
    /// <param name="F">The force.</param>
    /// <param name="v">The velocity.</param>
    /// <param name="B">The magnetic field strength.</param>
    /// <returns>charge (C)</returns>
    static ld chargeOfParticle(const ld F, const ld v, const ld B);

    /// <summary>
    /// A charged particle moving through a magnetic field at an angles theta1 to
    /// the field with a speed of v1 m/s experiences a magnetic force of
    /// F1 N. Determine the magnetic force on an identical particle when
    /// it travels through the same magnetic field with a speed of v2 m/s at
    /// an angle of theta2 relative to the magnetic field.
    /// </summary>
    /// <param name="v1">The velocity of particle 1.</param>
    /// <param name="v2">The velocity of particle 2.</param>
    /// <param name="F1">The force on particle 1.</param>
    /// <param name="theta1">The angle theta of particle 1.</param>
    /// <param name="theta2">The angle theta of particle 2.</param>
    /// <returns>force on particle 2</returns>
    static ld magneticForceOnIdenticalParticle(const ld v1, const ld v2, const ld F1, const ld theta1, const ld theta2);

    /// <summary>
    /// calculates the magnetic the field strength.\n
    /// B = F/(q*v*sin(theta*RADIAN))
    /// </summary>
    /// <param name="F">The magnetic force (N).</param>
    /// <param name="q">The charge (C).</param>
    /// <param name="v">The speed (m/s).</param>
    /// <param name="theta">The angle theta.</param>
    /// <returns>Tesla(T)</returns>
    static ld magneticFieldStrength(const ld F, const ld q, const ld v, const ld theta);

    /// <summary>
    /// Calculates the magnetic field strength from the centripetal motion of a
    /// particle moving on a curvature of radius of r with a of mass m at a speed
    /// of v with a charge of q .
    /// </summary>
    /// <param name="m">The mass.</param>
    /// <param name="v">The speed.</param>
    /// <param name="q">The charge.</param>
    /// <param name="r">The radius.</param>
    /// <returns>Tesla's (T)</returns>
    static ld magneticFieldStrength_Fc(const ld m, const ld v, const ld q, const ld r);

    /// <summary>
    /// Calculates the Magnetic field strength of a straight current carrying wire.
    /// </summary>
    /// <param name="I">The current.</param>
    /// <param name="r">The shortest distance to the wire.</param>
    /// <returns>magnitude of magnetic field strength</returns>
    static ld magneticFieldStrength_straightCurrentCarryingWire(const ld I, const ld r);

    /// <summary>
    /// Calculates the magnetic field strength center circular loop(s).
    /// </summary>
    /// <param name="I">The current.</param>
    /// <param name="R">The radius of loop.</param>
    /// <param name="N">The number of loops, default is 1.</param>
    /// <returns>magnetic field strength (T)</returns>
    static ld magneticFieldStrengthCenterCircularLoop(const ld I, const ld R, const ld N);

    /// <summary>
    /// Calculates the magnetic field strength inside solenoid.
    /// </summary>
    /// <param name="n">The number of loops per unit length n = N/l.</param>
    /// <param name="I">The current.</param>
    /// <returns>magnetic field strength inside a solenoid</returns>
    static ld magneticFieldStrengthInsideSolenoid(const ld n, const ld I);

    /// <summary>
    /// Calculates the magnetic field strength inside solenoid.
    /// </summary>
    /// <param name="N">The Number of loops.</param>
    /// <param name="l">The length.</param>
    /// <param name="I">The current.</param>
    /// <returns>magnetic field strength (T)</returns>
    static ld magneticFieldStrengthInsideSolenoid(const ld N, const ld l, const ld I);

    /// <summary>
    /// Frustrated by the small Hall voltage obtained in blood flow measurements,
    /// a medical physicist decides to increase the applied magnetic field strength
    /// to get a E(hall voltage) output for blood moving at v m/s in a d m-diameter
    /// vessel. Calculate the magnetic field strength needed.
    /// </summary>
    /// <param name="E">The hall voltage.</param>
    /// <param name="d">The diameter of vessel.</param>
    /// <param name="v">The speed.</param>
    /// <returns>the magnetic field strength</returns>
    static ld magneticFieldStrengthHallVoltage(const ld E, const ld d, const ld v);

    /// <summary>
    /// Loops per unit length.
    /// </summary>
    /// <param name="N">The number of loops.</param>
    /// <param name="l">The length.</param>
    /// <returns></returns>
    static ld loopsPerUnitLength(const ld N, const ld l);

    /// <summary>
    /// calculates the centripetal force.
    /// </summary>
    /// <param name="m">The mass.</param>
    /// <param name="v">The velocity.</param>
    /// <param name="r">The radius.</param>
    /// <returns>centripetal force</returns>
    static ld centripetalForce(const ld m, const ld v, const ld r);

    /// <summary>
    /// calculates the radius of the curvature of the path of a charged particle
    /// with a charge of q and a mass of m moving at a speed of v perpendicular
    /// to a magnetic field of strength B
    /// </summary>
    /// <param name="m">The mass.</param>
    /// <param name="v">The velocity.</param>
    /// <param name="q">The charge.</param>
    /// <param name="B">The magnetic field strength.</param>
    /// <param name="theta">The angle theta, defaulted at 90.</param>
    /// <returns>radius in meters</returns>
    static ld radiusCurvatureOfPath(const ld m, const ld v, const ld q, const ld B, const ld theta);

    /// <summary>
    /// If a single circular loop of wire carries a current of I A and produces
    /// a magnetic field at its center with a magnitude of B T, determine
    /// the radius of the loop.
    /// </summary>
    /// <param name="I">The current.</param>
    /// <param name="B">The magnetic field strength.</param>
    /// <returns>radius of loop (m)</returns>
    static ld radiusLoopOfCurrentCarryingWire(const ld I, const ld B);

    /// <summary>
    /// The wire carrying I1 A to the motor of a commuter train feels an
    /// attractive force per unit length of Fl N/m due to a parallel
    /// wire carrying I2 A to a headlight. Calculate how far apart the two wires
    /// are.
    /// </summary>
    /// <param name="I1">The current first wire.</param>
    /// <param name="I2">The current second wire.</param>
    /// <param name="Fl">The force per unit length.</param>
    /// <returns>distance between wires (m)</returns>
    static ld distanceBetween2wires(const ld I1, const ld I2, const ld Fl);

    /// <summary>
    /// Two power lines run parallel for a distance of l m and are separated
    /// by a distance of r m. If the current in each of the two lines is I1 A and
    /// I2 A and if they run in opposite directions, determine the magnitude
    /// of the force each wire exerts on the other.
    /// </summary>
    /// <param name="I1">The current wire 1.</param>
    /// <param name="I2">The current wire 2.</param>
    /// <param name="l">The length of wires.</param>
    /// <param name="r">The distance between the wires.</param>
    /// <returns>magnitude of force</returns>
    static ld forceMagnitude2wires(const ld I1, const ld I2, const ld l, const ld r);

    /// <summary>
    /// Calculates the mass of a charged particle of charge q moving in a
    /// curvature of radius r at a speed of v in a magnetic field strength of B
    /// </summary>
    /// <param name="r">The radius.</param>
    /// <param name="q">The charge.</param>
    /// <param name="B">The magnetic field strength.</param>
    /// <param name="v">The velocity.</param>
    /// <returns>mass of particle in kg</returns>
    static ld massOfChargedParticle(const ld r, const ld q, const ld B, const ld v);

    /// <summary>
    /// Calculates the velocity of a charged particle moving on a curvature of
    /// radius r with a charge of q in a magnetic field strength of B having a
    /// mass of m.
    /// </summary>
    /// <param name="r">The radius.</param>
    /// <param name="q">The charge.</param>
    /// <param name="B">The magnetic field strength.</param>
    /// <param name="m">The mass.</param>
    /// <returns>the speed of particle (m/s)</returns>
    static ld velocityOfChargedParticle(const ld r, const ld q, const ld B, const ld m);

    /// <summary>
    /// Calculates the Hall effect voltage (where B,v, and l are mutually
    /// perpendicular) across a conductor of width l, through which charges move
    /// at a speed of v through a uniform electric field.
    /// </summary>
    /// <param name="B">The electric field strength.</param>
    /// <param name="l">The width.</param>
    /// <param name="v">The speed.</param>
    /// <returns>the hall emf (V)</returns>
    static ld hallEMF(const ld B, const ld l, const ld v);

    /// <summary>
    /// Calculates the force on wire.
    /// </summary>
    /// <param name="n">The number of charge carriers.</param>
    /// <param name="q">The charge of each carrier.</param>
    /// <param name="A">the cross sectional area.</param>
    /// <param name="vD">The drift velocity.</param>
    /// <param name="l">The length of wire.</param>
    /// <param name="B">The uniform magnetic field strength.</param>
    /// <param name="theta">The angle theta between vD and B.</param>
    /// <returns>force in newtons</returns>
    static ld forceOnWire(const ld n, const ld q, const ld A, const ld vD, const ld l, const ld B, const ld theta);

    /// <summary>
    /// Calculates the force on a wire.
    /// </summary>
    /// <param name="I">The current(nqAvD).</param>
    /// <param name="l">The length of wire.</param>
    /// <param name="B">The magnetic field strength.</param>
    /// <param name="theta">The angle theta.</param>
    /// <returns>force in newtons</returns>
    static ld forceOnWire(const ld I, const ld l, const ld B, const ld theta);

    /// <summary>
    /// Calculates the force per unit length between two parallel wires.
    /// </summary>
    /// <param name="I1">The current 1.</param>
    /// <param name="I2">The current 2.</param>
    /// <param name="r">The distance of separation.</param>
    /// <returns>N/m</returns>
    static ld forcePerUnitLengthBetween2ParallelWires(const ld I1, const ld I2, const ld r);

    /// <summary>
    /// Two long straight current-carrying wires run parallel to each other.
    /// The current in one of the wires is I1 A, their separation is r (m)
    /// and they repel each other with a force per unit length of Fl N/m.
    /// </summary>
    /// <param name="I1">The known current.</param>
    /// <param name="r">The distance between wires.</param>
    /// <param name="Fl">The force per unit length.</param>
    /// <returns>unknown current in wire 2 (A)</returns>
    static ld currentFromWire2ParallelRunning(const ld I1, const ld r, const ld Fl);

    /// <summary>
    /// Calculates the torque on a current carrying loop of uniform magnetic
    /// field. Valid for a loop of any shape. The loop carries a current of I,
    /// and has N turns each of area A, and the perpendicular to the loop makes
    /// an angle theta with the magnetic field B.
    /// </summary>
    /// <param name="N">The number of loops.</param>
    /// <param name="I">The current (A).</param>
    /// <param name="A">The area (m^2).</param>
    /// <param name="B">The magnetic field strength (T).</param>
    /// <param name="theta">The angle between the loop and the magnetic
    /// field.</param>
    /// <returns>torque (N*m)</returns>
    static ld torqueOnCurrentCarryingLoop_umf(const ld N, const ld I, const ld A, const ld B, const ld theta);

    /// <summary>
    /// Calculates the maximum torque on a current carrying loop of uniform magnetic
    /// field. Valid for a loop of any shape. The loop carries a current of I,
    /// and has N turns each of area A, with a uniform magnetic field B. The
    /// angle of sin at max torque is 90 degrees which sin(90) = 1 so sin is removed
    /// from this equation.
    /// </summary>
    /// <param name="N">The number of loops.</param>
    /// <param name="I">The current (A).</param>
    /// <param name="A">The area (m^2).</param>
    /// <param name="B">The uniform magnetic field strength (T).</param>
    /// <returns>torque (N*m)</returns>
    static ld torqueMaxOnCurrentCarryingLoop_umf(const ld N, const ld I, const ld A, const ld B);

    /// <summary>
    /// Calculates the current in a current carrying loop using known torque when
    /// at maximum with a N number of loops each with an area of A and a uniform
    /// magnetic field strength of B.
    /// </summary>
    /// <param name="tMax">The torque maximum.</param>
    /// <param name="N">The number of loops.</param>
    /// <param name="A">The area.</param>
    /// <param name="B">The magnetic filed strength.</param>
    /// <returns>current in loops (A)</returns>
    static ld currentFromTorqueMax(const ld tMax, const ld N, const ld A, const ld B);

    /// <summary>
    /// Calculates the current in a long straight wire that would produce a
    /// magnetic field of B at a distance of r (m) from the wire
    /// </summary>
    /// <param name="r">The shortest distance to the wire.</param>
    /// <param name="B">The magnetic field strength.</param>
    /// <returns>current (A)</returns>
    static ld currentInLongStraightWire(const ld r, const ld B);

    /// <summary>
    /// You have designed and constructed a solenoid to produce a magnetic field
    /// equal in magnitude to B. If your solenoid
    /// has n turns and is l cm long, determine the current you must use in
    /// order to obtain a magnetic field of the desired magnitude.
    /// </summary>
    /// <param name="B">The desired magnetic field strength.</param>
    /// <param name="n">The number of turns on the solenoid.</param>
    /// <param name="l">The length of the solenoid.</param>
    /// <returns>the current needed (I)</returns>
    static ld currentSolenoid(const ld B, const ld n, const ld l);

    /// <summary>
    /// Calculate the angle the velocity of the electron
    /// makes with the magnetic field if an electron moving at v m/s
    /// in a B (T) magnetic field experiences a magnetic force of F N.
    /// </summary>
    /// <param name="v">The velocity.</param>
    /// <param name="B">The electric field strength.</param>
    /// <param name="F">The force.</param>
    /// <param name="q">The charge, default is elementary charge of electron.</param>
    /// <returns>angle theta</returns>
    static ld angleThetaOfElectronToMagneticField(const ld v, const ld B, const ld F, const ld q);

    /// <summary>
    /// A velocity selector in a mass spectrometer uses a B(T) magnetic field.
    /// Calculate what electric field strength is needed to select a
    /// speed of v m/s.
    /// </summary>
    /// <param name="v">The velocity selected on the spectrometer.</param>
    /// <param name="B">The magnetic field strength.</param>
    /// <param name="theta">The angle theta, default at sin(90) = 1.</param>
    /// <returns>electric field strength newton/coulombs (N/C)</returns>
    static ld electricFieldStrength_vB(const ld v, const ld B, const ld theta);





    ~Magnetism()
    {
        delete _magnetismPtr;
    }


private:
    static void countIncrease() { magnetism_objectCount += 1; }
    static void countDecrease() { magnetism_objectCount -= 1; }
    ld _magnetismVar;


};
#endif //PHYSICSFORMULA_MAGNETISM_H

inline ld Magnetism::magneticForce(const ld q, const ld v, const ld B, const ld theta)
{
    return q*v*B*sin(theta*RADIAN);//Newtons
}

inline ld Magnetism::magneticForceMax(const ld q, const ld B, const ld v)
{
    return q * v * B;//N
}

inline ld Magnetism::chargeOfParticle(const ld F, const ld v, const ld B)
{
    return F / (v * B);//(C)
}

inline ld Magnetism::magneticForceOnIdenticalParticle(const ld v1, const ld v2, const ld F1, const ld theta1, const ld theta2)
{
    return (F1 * v2 * sin(theta2 * RADIAN)) / (v1 * sin(theta1 * RADIAN));//F2 (N)
}

inline ld Magnetism::magneticFieldStrength(const ld F, const ld q, const ld v, const ld theta)
{
    return F/(q*v*sin(theta*RADIAN));//Tesla(T) = 1N/C*m/s = 1N/A*m a newton amp meter
}

inline ld Magnetism::magneticFieldStrength_Fc(const ld m, const ld v, const ld q, const ld r)
{
    return (m * v) / (q * r);//(T)
}

inline ld Magnetism::magneticFieldStrength_straightCurrentCarryingWire(const ld I, const ld r)
{
    return (_µo_*I)/(2.0*_PI*r);//(T)
}

inline ld Magnetism::magneticFieldStrengthCenterCircularLoop(const ld I, const ld R, const ld N = 1.0)
{
    return (N * _µo_ * I) / (2.0 * R);//(T)
}

inline ld Magnetism::magneticFieldStrengthInsideSolenoid(const ld n, const ld I)
{
    return _µo_ * n * I;//(T)
}

inline ld Magnetism::magneticFieldStrengthInsideSolenoid(const ld N, const ld l, const ld I)
{
    return _µo_*(N/l) * I;//T
}

inline ld Magnetism::magneticFieldStrengthHallVoltage(const ld E, const ld d, const ld v)
{
    return E / (d * v);//T
}

inline ld Magnetism::loopsPerUnitLength(const ld N, const ld l)
{
    return N / l;
}

inline ld Magnetism::centripetalForce(const ld m, const ld v, const ld r)
{
    return (m * (v * v)) / r;
}

inline ld Magnetism::radiusCurvatureOfPath(const ld m, const ld v, const ld q, const ld B, const ld theta = 90)
{
    return (m * v) / (q * B * sin(theta*RADIAN));//meters
}

inline ld Magnetism::radiusLoopOfCurrentCarryingWire(const ld I, const ld B)
{
    return (_µo_ * I) / (2.0 * B);//m
}

inline ld Magnetism::distanceBetween2wires(const ld I1, const ld I2, const ld Fl)
{
    return (_µo_ * I1 * I2) / (2.0 * _PI * Fl);//m
}

inline ld Magnetism::forceMagnitude2wires(const ld I1, const ld I2, const ld l, const ld r)
{
    return (_µo_ * I1 * I2 * l) / (2.0 * _PI * r);//N
}

inline ld Magnetism::massOfChargedParticle(const ld r, const ld q, const ld B, const ld v)
{
    return (r * q * B) / v;//kg
}

inline ld Magnetism::velocityOfChargedParticle(const ld r, const ld q, const ld B, const ld m)
{
    return (r * q * B) / m; //m/s
}

inline ld Magnetism::hallEMF(const ld B, const ld l, const ld v)
{
    return B * l * v;//(V)
}

inline ld Magnetism::forceOnWire(const ld n, const ld q, const ld A, const ld vD, const ld l, const ld B, const ld theta)
{
    return (n*q*A*vD)*l*B*sin(theta*RADIAN);//n
}

inline ld Magnetism::forceOnWire(const ld I, const ld l, const ld B, const ld theta)
{
    return I * l * B * sin(theta * RADIAN);//N
}

inline ld Magnetism::forcePerUnitLengthBetween2ParallelWires(const ld I1, const ld I2, const ld r)
{
    return (_µo_*I1*I2)/(2.0*_PI*r);
}

inline ld Magnetism::currentFromWire2ParallelRunning(const ld I1, const ld r, const ld Fl)
{
    return ((2.0 * _PI * r) / (_µo_ * I1)) * Fl;//A
}

inline ld Magnetism::torqueOnCurrentCarryingLoop_umf(const ld N, const ld I, const ld A, const ld B, const ld theta)
{
    return N*I*A*B*sin(theta*RADIAN);//N*m = newton meters
}

inline ld Magnetism::torqueMaxOnCurrentCarryingLoop_umf(const ld N, const ld I, const ld A, const ld B)
{
    return N*I*(A*A)*B;//N*m = newton meter
}

inline ld Magnetism::currentFromTorqueMax(const ld tMax, const ld N, const ld A, const ld B)
{
    return tMax / (N * A * B);//(A)
}

inline ld Magnetism::currentInLongStraightWire(const ld r, const ld B)
{
    return (2.0 * _PI * r * B) / _µo_;//(A)
}

inline ld Magnetism::currentSolenoid(const ld B, const ld n, const ld l)
{
    return B / (_µo_ * (n / l));// A
}

inline ld Magnetism::angleThetaOfElectronToMagneticField(const ld v, const ld B, const ld F, const ld q = _ELECTRON_CHARGE_)
{
    return asin(F / (-q * v * B))*DEGREE;//angle theta
}

inline ld Magnetism::electricFieldStrength_vB(const ld v, const ld B, const ld theta = 90)
{
    return v * B * sin(theta*RADIAN);//N/C
}
