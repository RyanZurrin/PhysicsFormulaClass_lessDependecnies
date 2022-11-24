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
#include "ElectricCharge.h"
static int magnetism_objectCount = 0;

class Magnetism :
        public ElectricCurrent, public ElectricCharge
{
public:
    Magnetism()
    {
        _magnetismVar = 0.0;
        countIncrease();
    }

    explicit Magnetism(ld var)
    {
        _magnetismVar = 0.0;
        countIncrease();
    }


    /**
     * @brief copy constructor
     */
    Magnetism(const Magnetism& t)
     : ElectricCurrent(t), ElectricCharge(t) {
        _magnetismVar = t._magnetismVar;
        countIncrease();
    }

    /**
     * #brief move constructor
     */
    Magnetism(Magnetism&& t) noexcept
    {
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
            _magnetismVar = t._magnetismVar;
            countIncrease();
        }
        return *this;
    }
    void setMagnetismVar(ld var) { _magnetismVar = var; }
    [[nodiscard]] ld getMagVar() const { return _magnetismVar; }
    static void show_objectCount() { std::cout << "\n magnetism object count: "
                                               << magnetism_objectCount << std::endl; }
    static int get_objectCount() { return magnetism_objectCount; }

    /**
     * @brief Calculates the magnetic force (Lorentz force) on a charge q moving at
     * a speed v in a magnetic field of strength B where theta is the angle
     * between the directions of v and B.
     * @param q The charge in Coulombs.
     * @param v The speed in m/s.
     * @param B The magnetic field strength.
     * @param theta The angle theta between the directions
     * @param print bool to print or not (default true)
     * @return the magnetic force in newtons
     */
    static ld magneticForce(ld q, ld v, ld B, ld theta, bool print = true);

    /**
     * @brief Calculates the electromagnetic force on a charge q moving at a speed v
     * in a magnetic field of strength with an electric field of strength E where
     * theta is the angle between the directions of v and B.
     * @param q The charge in Coulombs.
     * @param v The speed in m/s.
     * @param B The magnetic field strength.
     * @param E The electric field strength.
     * @param theta The angle theta between the directions
     * @param print bool to print or not (default true)
     * @return the electromagnetic force in newtons
     */
    static ld electroMagneticForce(ld q, ld v, ld B, ld E, ld theta, bool print = true);

    /**
     * @brief Calculates the magnetic force at a maximum angle of sin(90) which is 1.
     * @param q The q.
     * @param B The b.
     * @param v The v.
     * @param print bool to print or not (default true)
     * @return magnetic force (N)
     */
    static ld magneticForceMax(ld q, ld B, ld v, bool print = true);

    /**
     * @brief Calculates the charge of a particle moving at right angles to the
     * magnetic field of B Tesla's with a speed of v m/s while experiencing a
     * magnetic force of F newtons.
     * force of F Newtons.
     * @param F The force.
     * @param v The velocity.
     * @param B The magnetic field strength.
     * @param print bool to print or not (default true)
     * @return charge (C)
     */
    static ld chargeOfParticle(ld F, ld v, ld B, bool print = true);

    /**
     * @brief A charged particle moving through a magnetic field at an angles theta1 to
     * the field with a speed of v1 m/s experiences a magnetic force of
     * F1 N. Determine the magnetic force on an identical particle when
     * it travels through the same magnetic field with a speed of v2 m/s at
     * an angle of theta2 relative to the magnetic field.
     * @param v1 The velocity of particle 1.
     * @param v2 The velocity of particle 2.
     * @param F1 The force on particle 1.
     * @param theta1 The angle theta of particle 1.
     * @param theta2 The angle theta of particle 2.
     * @param print bool to print or not (default true)
     * @return force on particle 2
     */
    static ld magneticForceOnIdenticalParticle(ld v1, ld v2, ld F1, ld theta1, ld theta2, bool print = true);

    /**
     * @brief calculates the magnetic the field strength.
     * B = F/(q*v*sin(theta*RADIAN))
     * @param F The magnetic force (N).
     * @param q The charge (C).
     * @param v The speed (m/s).
     * @param theta The angle theta.
     * @param print bool to print or not (default true)
     * @return Tesla(T)
     */
    static ld magneticFieldStrength(ld F, ld q, ld v, ld theta, bool print = true);

    /**
     * @brief Calculates the magnetic field strength from the centripetal motion of a
     * particle moving on a curvature of radius of r with a of mass m at a speed
     * of v with a charge of q .
     * @param m The mass.
     * @param v The speed.
     * @param q The charge.
     * @param r The radius.
     * @param print bool to print or not (default true)
     * @return Tesla's (T)
     */
    static ld magneticFieldStrength_Fc(ld m, ld v, ld q, ld r, bool print = true);

    /**
     * @brief Calculates the Magnetic field strength of a straight current carrying wire.
     * @param I The current.
     * @param r The shortest distance to the wire.
     * @param print bool to print or not (default true)
     * @return magnitude of magnetic field strength
     */
    static ld magneticFieldStrength_straightCurrentCarryingWire(ld I, ld r, bool print = true);

    /**
     * @brief Calculates the magnetic field strength center circular loop(s).
     * @param I The current.
     * @param R The radius of loop.
     * @param N The number of loops, default is 1.
     * @param print bool to print or not (default true)
     * @return magnetic field strength (T)
     */
    static ld magneticFieldStrengthCenterCircularLoop(ld I, ld R, ld N, bool print = true);

    /**
     * @brief Calculates the magnetic field strength inside solenoid.
     * @param n The number of loops per unit length n = N/l.
     * @param I The current.
     * @param print bool to print or not (default true)
     * @return magnetic field strength inside a solenoid
     */
    static ld magneticFieldStrengthInsideSolenoid(ld n, ld I, bool print = true);

    /**
     * @brief Calculates the magnetic field strength inside solenoid.
     * @param N The Number of loops.
     * @param l The length.
     * @param I The current.
     * @param print bool to print or not (default true)
     * @return magnetic field strength (T)
     */
    static ld magneticFieldStrengthInsideSolenoid(ld N, ld l, ld I, bool print = true);

    /**
     * @brief Frustrated by the small Hall voltage obtained in blood flow measurements,
     * a medical physicist decides to increase the applied magnetic field strength
     * to get a E(hall voltage) output for blood moving at v m/s in a d m-diameter
     * vessel. Calculate the magnetic field strength needed.
     * @param E The hall voltage.
     * @param d The diameter of vessel.
     * @param v The speed.
     * @param print bool to print or not (default true)
     * @return the magnetic field strength
     */
    static ld magneticFieldStrengthHallVoltage(ld E, ld d, ld v, bool print = true);

    /**
     * @brief Loops per unit length.
     * @param N The number of loops.
     * @param l The length.
     * @param print bool to print or not (default true)
     * @return loops per unit length
     */
    static ld loopsPerUnitLength(ld N, ld l, bool print = true);

    /**
     * @brief calculates the centripetal force.
     * @param m The mass.
     * @param v The velocity.
     * @param r The radius.
     * @param print bool to print or not (default true)
     * @return centripetal force
     */
    static ld centripetalForce(ld m, ld v, ld r, bool print = true);

    /**
     * @brief calculates the radius of the curvature of the path of a charged particle
     * with a charge of q and a mass of m moving at a speed of v perpendicular
     * to a magnetic field of strength B
     * @param m The mass.
     * @param v The velocity.
     * @param q The charge.
     * @param B The magnetic field strength.
     * @param theta The angle theta, defaulted at 90.
     * @param print bool to print or not (default true)
     * @return radius in meters
     */
    static ld radiusCurvatureOfPath(ld m, ld v, ld q, ld B, ld theta, bool print = true);

    /**
     * @brief If a single circular loop of wire carries a current of I A and produces
     * a magnetic field at its center with a magnitude of B T, determine
     * the radius of the loop.
     * @param I The current.
     * @param B The magnetic field strength.
     * @param print bool to print or not (default true)
     * @return radius of loop (m)
     */
    static ld radiusLoopOfCurrentCarryingWire(ld I, ld B, bool print = true);

    /**
     * @brief The wire carrying I1 A to the motor of a commuter train feels an
     * attractive force per unit length of Fl N/m due to a parallel
     * wire carrying I2 A to a headlight. Calculate how far apart the two wires
     * are.
     * @param I1 The current first wire.
     * @param I2 The current second wire.
     * @param Fl The force per unit length.
     * @param print bool to print or not (default true)
     * @return distance between wires (m)
     */
    static ld distanceBetween2wires(ld I1, ld I2, ld Fl, bool print = true);

    /**
     * @brief Two power lines run parallel for a distance of l m and are separated
     * by a distance of r m. If the current in each of the two lines is I1 A and
     * I2 A and if they run in opposite directions, determine the magnitude
     * of the force each wire exerts on the other.
     * @param I1 The current wire 1.
     * @param I2 The current wire 2.
     * @param l The length of wires.
     * @param r The distance between the wires.
     * @param print bool to print or not (default true)
     * @return magnitude of force
     */
    static ld forceMagnitude2wires(ld I1, ld I2, ld l, ld r, bool print = true);

    /**
     * @brief Calculates the mass of a charged particle of charge q moving in a
     * curvature of radius r at a speed of v in a magnetic field strength of B
     * @param r The radius.
     * @param q The charge.
     * @param B The magnetic field strength.
     * @param v The velocity.
     * @param print bool to print or not (default true)
     * @return mass of particle in kg
     */
    static ld massOfChargedParticle(ld r, ld q, ld B, ld v, bool print = true);

    /**
     * @brief Calculates the velocity of a charged particle moving on a curvature of
     * radius r with a charge of q in a magnetic field strength of B having a
     * mass of m.
     * @param r The radius.
     * @param q The charge.
     * @param B The magnetic field strength.
     * @param m The mass.
     * @param print bool to print or not (default true)
     * @return the speed of particle (m/s)
     */
    static ld velocityOfChargedParticle(ld r, ld q, ld B, ld m, bool print = true);

    /**
     * @brief Calculates the Hall effect voltage (where B,v, and l are mutually
     * perpendicular) across a conductor of width l, through which charges move
     * at a speed of v through a uniform electric field.
     * @param B The electric field strength.
     * @param l The width.
     * @param v The speed.
     * @param print bool to print or not (default true)
     * @return the hall emf (V)
     */
    static ld hallEMF(ld B, ld l, ld v, bool print = true);

    /**
     * @brief Calculates the force on wire.
     * @param n The number of charge carriers.
     * @param q The charge of each carrier.
     * @param A the cross sectional area.
     * @param vD The drift velocity.
     * @param l The length of wire.
     * @param B The uniform magnetic field strength.
     * @param theta The angle theta between vD and B.
     * @param print bool to print or not (default true)
     * @return force in newtons
     */
    static ld forceOnWire(ld n, ld q, ld A, ld vD, ld l, ld B, ld theta, bool print = true);

    /**
     * @brief Calculates the force on a wire.
     * @param I The current(nqAvD).
     * @param l The length of wire.
     * @param B The magnetic field strength.
     * @param theta The angle theta.
     * @param print bool to print or not (default true)
     * @return force in newtons
     */
    static ld forceOnWire(ld I, ld l, ld B, ld theta, bool print = true);

    /**
     * @brief Calculates the force per unit length between two parallel wires.
     * @param I1 The current 1.
     * @param I2 The current 2.
     * @param r The distance of separation.
     * @param print bool to print or not (default true)
     * @return N/m
     */
    static ld forcePerUnitLengthBetween2ParallelWires(ld I1, ld I2, ld r, bool print = true);

    /**
     * @brief Two long straight current-carrying wires run parallel to each other.
     * The current in one of the wires is I1 A, their separation is r (m)
     * and they repel each other with a force per unit length of Fl N/m.
     * @param I1 The known current.
     * @param r The distance between wires.
     * @param Fl The force per unit length.
     * @param print bool to print or not (default true)
     * @return unknown current in wire 2 (A)
     */
    static ld currentFromWire2ParallelRunning(ld I1, ld r, ld Fl, bool print = true);

    /**
     * @brief Calculates the torque on a current carrying loop of uniform magnetic
     * field. Valid for a loop of any shape. The loop carries a current of I,
     * and has N turns each of area A, and the perpendicular to the loop makes
     * an angle theta with the magnetic field B.
     * @param N The number of loops.
     * @param I The current (A).
     * @param A The area (m^2).
     * @param B The magnetic field strength (T).
     * @param theta The angle between the loop and the magnetic
     * field.
     * @param print bool to print or not (default true)
     * @return torque (N*m)
     */
    static ld torqueOnCurrentCarryingLoop_umf(ld N, ld I, ld A, ld B, ld theta, bool print = true);

    /**
     * @brief Calculates the maximum torque on a current carrying loop of uniform magnetic
     * field. Valid for a loop of any shape. The loop carries a current of I,
     * and has N turns each of area A, with a uniform magnetic field B. The
     * angle of sin at max torque is 90 degrees which sin(90) = 1 so sin is removed
     * from this equation.
     * @param N The number of loops.
     * @param I The current (A).
     * @param A The area (m^2).
     * @param B The uniform magnetic field strength (T).
     * @param print bool to print or not (default true)
     * @return torque (N*m)
     */
    static ld torqueMaxOnCurrentCarryingLoop_umf(ld N, ld I, ld A, ld B, bool print = true);

    /**
     * @brief Calculates the current in a current carrying loop using known torque when
     * at maximum with a N number of loops each with an area of A and a uniform
     * magnetic field strength of B.
     * @param tMax The torque maximum.
     * @param N The number of loops.
     * @param A The area.
     * @param B The magnetic filed strength.
     * @param print bool to print or not (default true)
     * @return current in loops (A)
     */
    static ld currentFromTorqueMax(ld tMax, ld N, ld A, ld B, bool print = true);

    /**
     * @brief Calculates the current in a long straight wire that would produce a
     * magnetic field of B at a distance of r (m) from the wire
     * @param r The shortest distance to the wire.
     * @param B The magnetic field strength.
     * @param print bool to print or not (default true)
     * @return current (A)
     */
    static ld currentInLongStraightWire(ld r, ld B, bool print = true);

    /**
     * @brief You have designed and constructed a solenoid to produce a magnetic field
     * equal in magnitude to B. If your solenoid
     * has n turns and is l cm long, determine the current you must use in
     * order to obtain a magnetic field of the desired magnitude.
     * @param B The desired magnetic field strength.
     * @param n The number of turns on the solenoid.
     * @param l The length of the solenoid.
     * @param print bool to print or not (default true)
     * @return the current needed (I)
     */
    static ld currentSolenoid(ld B, ld n, ld l, bool print = true);

    /**
     * @brief Calculate the angle the velocity of the electron
     * makes with the magnetic field if an electron moving at v m/s
     * in a B (T) magnetic field experiences a magnetic force of F N.
     * @param v The velocity.
     * @param B The electric field strength.
     * @param F The force.
     * @param q The charge, default is elementary charge of electron.
     * @param print bool to print or not (default true)
     * @return angle theta
     */
    static ld angleThetaOfElectronToMagneticField(ld v, ld B, ld F, ld q, bool print = true);

    /**
     * @brief A velocity selector in a mass spectrometer uses a B(T) magnetic field.
     * Calculate what electric field strength is needed to select a
     * speed of v m/s.
     * @param v The velocity selected on the spectrometer.
     * @param B The magnetic field strength.
     * @param theta The angle theta, default at sin(90) = 1.
     * @param print bool to print or not (default true)
     * @return electric field strength newton/coulombs (N/C)
     */
    static ld electricFieldStrength_vB(ld v, ld B, ld theta, bool print = true);

    /**
     * @brief A mass spectrometer separates ions according to their ratio of
     * charge to mass. Such devices are widely used in science and engineering
     * to analyze unknown mixtures and to separate isotopes of chemical elements.
     * Figure 26.7 shows ions of charge  and mass  first being accelerated from
     * rest through a potential difference  and then entering a region of uniform
     * magnetic field  pointing out of the page. Only the magnetic force acts on
     * the ions in this region, so they undergo circular motion and, after half
     * an orbit, land on a detector. Find an expression for the horizontal distance
     * from the entrance slit to the point where an ion lands on the detector.
     * @param q The charge of the ion.
     * @param m The mass of the ion.
     * @param V The potential difference.
     * @param B The magnetic field strength.
     * @param print bool to print or not (default true)
     * @return distance (m)
     */
    static ld distanceIonLandsOnDetector(ld q, ld m, ld V, ld B, bool print = true);

    /**
     * @brief Calculate the cyclotron frequency of a particle with charge q and mass m
     * in a magnetic field B.
     * @param q The charge of the particle.
     * @param m The mass of the particle.
     * @param B The magnetic field strength.
     * @param print bool to print or not (default true)
     * @return frequency (Hz)
     */
    static ld cyclotronFrequency(ld q, ld m, ld B, bool print = true);

    /**
     * @brief Calculate the period of a particles circular orbit in a magnetic field B.
     * @param q The charge of the particle.
     * @param m The mass of the particle.
     * @param B The magnetic field strength.
     * @param print bool to print or not (default true)
     * @return period (s)
     */
    static ld periodOfCircularOrbit(ld q, ld m, ld B, bool print = true);

    /**
     * @brief Calculate the magnetic force on a current carrying wire in a
     * magnetic field B, where theta is the angle between the current and the
     * magnetic field.
     * @param I The current.
     * @param B The magnetic field strength.
     * @param l The length of current path.
     * @param theta The angle between the current and the magnetic field.
     * Default is sin(90) = 1.
     * @param print bool to print or not (default true)
     * @return force (N)
     */
    static ld magneticForceOnCurrentCarryingWire(
            ld I, ld B, ld l, ld theta = 90.0, bool print = true);

    /**
     * @brief Calculate the charge using the biot-savart law.
     * @param I The current.
     * @param l The length of current path.
     * @param r The distance from the current path to the point of interest.
     * @param theta The angle between the current and the magnetic field.
     * Default is sin(90) = 1.
     * @param print bool to print or not (default true)
     */
    static ld biotSavartLaw(ld I, ld l, ld r, ld theta = 90.0, bool print = true);

    /**
     * @brief Calculating the magnetic field at P due to an infinite straight
     * wire carrying current  along the axis.
     * @param I The current.
     * @param r The distance from the current path to the point of interest.
     * @param print bool to print or not (default true)
     */
    static ld magneticFieldStraightWire(ld I, ld r, bool print = true);

    /**
     * @brief Calculate the magnetic force between two parallel wires.
     * @param I1 The current in wire 1.
     * @param I2 The current in wire 2.
     * @param d The distance between the wires.
     * @param l The length of the wires.
     * @param print bool to print or not (default true)
     * @return force (N)
     */
    static ld magneticForceBetweenTwoParallelWires(
            ld I1, ld I2, ld d, ld l, bool print = true);

    /**
     * @brief Use Ampere's law for steady currents to calculate the magnetic field
     * @param I The current.
     * @param print bool to print or not (default true)
     * @return magnetic field (T)
     */
    static ld amperesLaw(ld I, bool print = true);



    ~Magnetism()
    {
        countDecrease();
    }


private:
    static void countIncrease() { magnetism_objectCount += 1; }
    static void countDecrease() { magnetism_objectCount -= 1; }
    ld _magnetismVar;


};
#endif //PHYSICSFORMULA_MAGNETISM_H

inline ld Magnetism::magneticForce(const ld q, const ld v, const ld B, const ld theta, bool print)
{
    auto Fb = q*v*B*sin(theta*constants::RADIAN);//Newtons
    if (print)
        std::cout << "Magnetic force: " << Fb << " N" << std::endl;
    return Fb;
}

inline ld Magnetism::magneticForceMax(const ld q, const ld B, const ld v, bool print)
{
    auto Fb_max = q * v * B;//N
    if (print)
        std::cout << "Magnetic force max: " << Fb_max << " N" << std::endl;
    return Fb_max;
}

inline ld Magnetism::chargeOfParticle(const ld F, const ld v, const ld B, bool print)
{
    auto Q = F / (v * B);//(C)
    if (print)
        std::cout << "Charge of particle: " << Q << " C" << std::endl;
    return Q;
}

inline ld Magnetism::magneticForceOnIdenticalParticle(const ld v1, const ld v2, const ld F1, const ld theta1, const ld theta2, bool print)
{
    auto Fbb =  (F1 * v2 * sin(theta2 * constants::RADIAN)) /
            (v1 * sin(theta1 * constants::RADIAN));//F2 (N)
    if (print)
        std::cout << "Magnetic force on identical particle: " << Fbb << " N" << std::endl;
    return Fbb;
}

inline ld Magnetism::magneticFieldStrength(const ld F, const ld q, const ld v, const ld theta, bool print)
{
    //Tesla(T) = 1N/C*m/s = 1N/A*m a newton amp meter
    auto B = F/(q*v*sin(theta*constants::RADIAN));
    if (print)
        std::cout << "Magnetic field strength: " << B << " T" << std::endl;
    return B;
}

inline ld Magnetism::magneticFieldStrength_Fc(const ld m, const ld v, const ld q, const ld r, bool print)
{
    auto Fc = (m * v) / (q * r);//(T)
    if (print)
        std::cout << "Magnetic field strength: " << Fc << " T" << std::endl;
    return Fc;
}

inline ld Magnetism::magneticFieldStrength_straightCurrentCarryingWire(const ld I, const ld r, bool print)
{
    auto Bccw = (constants::mu0 * I) / (2.0 * constants::PI * r);//(T)
    if (print)
        std::cout << "Magnetic field strength: " << Bccw << " T" << std::endl;
    return Bccw;
}

inline ld Magnetism::magneticFieldStrengthCenterCircularLoop(const ld I, const ld R, const ld N = 1.0, bool print)
{
    auto B = (N * constants::mu0 * I) / (2.0 * R);//(T)
    if (print)
        std::cout << "Magnetic field strength: " << B << " T" << std::endl;
    return B;
}

inline ld Magnetism::magneticFieldStrengthInsideSolenoid(const ld n, const ld I, bool print)
{
    auto B = constants::mu0 * n * I;//(T)
    if (print)
        std::cout << "Magnetic field strength: " << B << " T" << std::endl;
    return B;
}

inline ld Magnetism::magneticFieldStrengthInsideSolenoid(const ld N, const ld l, const ld I, bool print)
{
    auto B = constants::mu0 * (N / l) * I;//T
    if (print)
        std::cout << "Magnetic field strength: " << B << " T" << std::endl;
    return B;
}

inline ld Magnetism::magneticFieldStrengthHallVoltage(const ld E, const ld d, const ld v, bool print)
{
    auto B = E / (d * v);//T
    if (print)
        std::cout << "Magnetic field strength: " << B << " T" << std::endl;
    return B;
}

inline ld Magnetism::loopsPerUnitLength(const ld N, const ld l, bool print)
{
    auto loops = N / l;
    if (print)
        std::cout << "Loops per unit length: " << loops << std::endl;
    return loops;
}

inline ld Magnetism::centripetalForce(const ld m, const ld v, const ld r, bool print)
{
    auto Fc =  (m * (v * v)) / r;
    if (print)
        std::cout << "Centripetal force: " << Fc << " N" << std::endl;
    return Fc;
}

inline ld Magnetism::radiusCurvatureOfPath(const ld m,
                                           const ld v,
                                           const ld q,
                                           const ld B,
                                           const ld theta = 90, bool print)
{
    auto r_curve = (m * v) / (q * B * sin(theta*constants::RADIAN));//meters
    if (print)
        std::cout << "Radius of curvature of path: " << r_curve << " m" << std::endl;
    return r_curve;
}

inline ld Magnetism::radiusLoopOfCurrentCarryingWire(const ld I, const ld B, bool print)
{
    auto r_loop = (constants::mu0 * I) / (2.0 * B);//m
    if (print) {
        std::cout << "Radius of loop of current carrying wire: " << r_loop <<
                  " m" << std::endl;
    }
    return r_loop;
}

inline ld Magnetism::distanceBetween2wires(const ld I1, const ld I2, const ld Fl, bool print)
{
    auto d = (constants::mu0 * I1 * I2) / (2.0 * constants::PI * Fl);//m
    if (print)
        std::cout << "Distance between 2 wires: " << d << " m" << std::endl;
    return d;
}

inline ld Magnetism::forceMagnitude2wires(const ld I1,
                                          const ld I2,
                                          const ld l,
                                          const ld r, bool print)
{
    auto Fmag = (constants::mu0 * I1 * I2 * l) / (2.0 * constants::PI * r);//N
    if (print)
        std::cout << "Force magnitude between 2 wires: " << Fmag << " N" << std::endl;
    return Fmag;
}

inline ld Magnetism::massOfChargedParticle(const ld r,
                                           const ld q,
                                           const ld B,
                                           const ld v, bool print)
{
    auto mass = (r * q * B) / v;//kg
    if (print)
        std::cout << "Mass of charged particle: " << mass << " kg" << std::endl;
    return mass;
}

inline ld Magnetism::velocityOfChargedParticle(const ld r,
                                               const ld q,
                                               const ld B,
                                               const ld m, bool print)
{
    auto v = (r * q * B) / m; //m/s
    if (print)
        std::cout << "Velocity of charged particle: " << v << " m/s" << std::endl;
    return v;
}

inline ld Magnetism::hallEMF(const ld B, const ld l, const ld v, bool print)
{
    auto H_emf = B * l * v;//(V)
    if (print)
        std::cout << "Hall EMF: " << H_emf << " V" << std::endl;
    return H_emf;
}

inline ld Magnetism::forceOnWire(const ld n,
                                 const ld q,
                                 const ld A,
                                 const ld vD,
                                 const ld l,
                                 const ld B,
                                 const ld theta, bool print)
{
    auto F = (n*q*A*vD)*l*B*sin(theta*constants::RADIAN);//n
    if (print)
        std::cout << "Force on wire: " << F << " N" << std::endl;
    return F;
}

inline ld Magnetism::forceOnWire(
        const ld I, const ld l, const ld B, const ld theta, bool print)
{
    auto F_wire = I * l * B * sin(theta * constants::RADIAN);//N
    if (print)
        std::cout << "Force on wire: " << F_wire << " N" << std::endl;
    return F_wire;
}

inline ld Magnetism::forcePerUnitLengthBetween2ParallelWires(
        const ld I1, const ld I2, const ld r, bool print)
{
    auto F = (constants::mu0 * I1 * I2) / (2.0 * constants::PI * r);
    if (print)
        std::cout << "Force per unit length between 2 parallel wires: " << F << " N/m" << std::endl;
    return F;
}

inline ld Magnetism::currentFromWire2ParallelRunning(const ld I1,
                                                     const ld r,
                                                     const ld Fl, bool print)
{
    auto I = ((2.0 * constants::PI * r) / (constants::mu0 * I1)) * Fl;//A
    if (print)
        std::cout << "Current from wire 2 parallel running: " << I << " A" << std::endl;
    return I;
}

inline ld Magnetism::torqueOnCurrentCarryingLoop_umf(const ld N,
                                                     const ld I,
                                                     const ld A,
                                                     const ld B,
                                                     const ld theta, bool print)
{
    auto tao = N*I*A*B*sin(theta*constants::RADIAN);//N*m = newton meters
    if (print)
        std::cout << "Torque on current carrying loop: " << tao << " N*m" << std::endl;
    return tao;
}

inline ld Magnetism::torqueMaxOnCurrentCarryingLoop_umf(const ld N,
                                                        const ld I,
                                                        const ld A,
                                                        const ld B, bool print)
{
    auto tao = N*I*(A*A)*B;//N*m = newton meter
    if (print)
        std::cout << "Torque max on current carrying loop: " << tao << " N*m" << std::endl;
    return tao;
}

inline ld Magnetism::currentFromTorqueMax(const ld tMax,
                                          const ld N,
                                          const ld A,
                                          const ld B, bool print)
{
    auto tao = tMax / (N * A * B);//(A)
    if (print)
        std::cout << "Current from torque max: " << tao << " A" << std::endl;
    return tao;
}

inline ld Magnetism::currentInLongStraightWire(const ld r, const ld B, bool print)
{
    auto I = (2.0 * constants::PI * r * B) / constants::mu0;//(A)
    if (print)
        std::cout << "Current in long straight wire: " << I << " A" << std::endl;
    return I;
}

inline ld Magnetism::currentSolenoid(const ld B, const ld n, const ld l, bool print)
{
    auto I_sol =  B / (constants::mu0 * (n / l));// A
    if (print)
        std::cout << "Current in solenoid: " << I_sol << " A" << std::endl;
    return I_sol;
}

inline ld Magnetism::angleThetaOfElectronToMagneticField(const ld v, const ld
B, const ld F, const ld q = constants::ELECTRON_CHARGE, bool print)
{
    auto theta = asin(F / (-q * v * B))*constants::DEGREE;//angle theta
    if (print)
        std::cout << "Angle theta of electron to magnetic field: " << theta << " degrees" << std::endl;
    return theta;
}

inline ld Magnetism::electricFieldStrength_vB(const ld v,
                                              const ld B,
                                              const ld theta = 90, bool print)
{
    auto E = v * B * sin(theta*constants::RADIAN);//N/C
    if (print)
        std::cout << "Electric field strength: " << E << " N/C" << std::endl;
    return E;
}

inline ld
Magnetism::electroMagneticForce(ld q, ld v, ld B, ld E, ld theta, bool print) {
    auto F = q * v * B * sin(theta * constants::RADIAN) + q * E;//N
    if (print)
        std::cout << "Electro magnetic force: " << F << " N" << std::endl;
    return F;
}

inline ld Magnetism::distanceIonLandsOnDetector(
        ld q, ld m, ld V, ld B, bool print) {
    auto d = (2.0 / B) * sqrt((2.0 * m * V) / q); //m
    if (print)
        std::cout << "Distance ion lands on detector: " << d << " m" << std::endl;
    return d;
}

inline ld Magnetism::cyclotronFrequency(ld q, ld m, ld B, bool print) {
    auto f = (q * B) / (2.0 * constants::PI * m);//Hz
    if (print)
        std::cout << "Cyclotron frequency: " << f << " Hz" << std::endl;
    return f;
}

inline ld Magnetism::periodOfCircularOrbit(ld q, ld m, ld B, bool print) {
    auto T = (2.0 * constants::PI) / cyclotronFrequency(q, m, B, false);//s
    if (print)
        std::cout << "Period of circular orbit: " << T << " s" << std::endl;
    return T;
}

inline ld Magnetism::magneticForceOnCurrentCarryingWire(
        ld I, ld B, ld l, ld theta, bool print) {
    auto F = (I * B * l * sin(theta * constants::RADIAN));//N
    if (print)
        std::cout << "Magnetic force on current: " << F << " N" << std::endl;
    return F;
}

ld Magnetism::biotSavartLaw(ld I, ld l, ld r, ld theta, bool print) {
    auto mu0 = constants::mu0;
    auto pi = constants::PI;
    auto mu_4pi = mu0 / (4.0 * pi);
    auto dB = mu_4pi * (I * l * sin(theta * constants::RADIAN)) / (r * r);//T
    if (print)
        std::cout << "Biot savart law: " << dB << " T" << std::endl;
    return dB;
}

ld Magnetism::magneticForceBetweenTwoParallelWires(ld I1, ld I2, ld d, ld l,
                                                   bool print) {
    auto mu0 = constants::mu0;
    auto pi = constants::PI;
    auto F2 = mu0 * (I1 * I2 * l) / (2.0 * d);//N
    if (print)
        std::cout << "Magnetic force between two parallel wires: " << F2 << " N" << std::endl;
    return F2;
}

ld Magnetism::magneticFieldStraightWire(ld I, ld r, bool print) {
    auto mu0 = constants::mu0;
    auto pi = constants::PI;
    auto B = (mu0 * I) / (2.0 * pi * r);//T
    if (print)
        std::cout << "Magnetic field straight wire: " << B << " T" << std::endl;
    return B;
}

ld Magnetism::amperesLaw(ld I, bool print) {
    auto B = I * constants::mu0;//T
    if (print)
        std::cout <<  "Amperes law: " << B << " T" << std::endl;
    return B;
}
