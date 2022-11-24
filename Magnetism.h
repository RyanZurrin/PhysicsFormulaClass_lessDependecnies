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

// create an enum for all the different directions used in the right hand rule
enum class Direction
{
    N,
    S,
    E,
    W,
    I,
    O
};
typedef Direction dir;
// convert direction enum to string
static string dirToString(Direction dir)
{
    switch (dir)
    {
        case dir::N:
            return "North";
        case dir::S:
            return "South";
        case dir::E:
            return "East";
        case dir::W:
            return "West";
        case dir::I:
            return "Into Page";
        case dir::O:
            return "Out of Page";
        default:
            return "Invalid Direction";
    }
}

static struct RHR
{
    RHR() {}

    vector<Direction> FORCE = {
            dir::N, dir::N, dir::N, dir::N,
            dir::S, dir::S, dir::S, dir::S,
            dir::E, dir::E, dir::E, dir::E,
            dir::W, dir::W, dir::W, dir::W,
            dir::I, dir::I, dir::I, dir::I,
            dir::O, dir::O, dir::O, dir::O
    };
    vector<Direction> VELOCITY = {
            dir::E, dir::W, dir::I, dir::O,
            dir::E, dir::W, dir::I, dir::O,
            dir::N, dir::S, dir::I, dir::O,
            dir::N, dir::S, dir::I, dir::O,
            dir::N, dir::S, dir::E, dir::W,
            dir::N, dir::S, dir::E, dir::W
    };
    vector<Direction> B_FIELD = {
            dir::I, dir::O, dir::W, dir::E,
            dir::O, dir::I, dir::E, dir::W,
            dir::O, dir::I, dir::N, dir::S,
            dir::I, dir::O, dir::S, dir::N,
            dir::E, dir::W, dir::S, dir::N,
            dir::W, dir::E, dir::N, dir::S
    };

    // given force and velocity get the direction of the B field
    basic_string<char> findBFieldDirection(Direction force, Direction velocity)
    {
        for (int i = 0; i < FORCE.size(); ++i)
        {
            if (FORCE[i] == force && VELOCITY[i] == velocity)
            {
                // return the direction of the B field as a string
                return dirToString(B_FIELD[i]);
            }
        }
        return "Invalid Direction";
    }
    // given force and B field get the direction of the velocity
    basic_string<char> findVelocityDirection(Direction force, Direction BField)
    {
        for (int i = 0; i < FORCE.size(); ++i)
        {
            if (FORCE[i] == force && B_FIELD[i] == BField)
            {
                return dirToString(VELOCITY[i]);
            }
        }
        return "Invalid Direction";
    }
    // given velocity and B field get the direction of the force
    basic_string<char>  findForceDirection(Direction velocity, Direction BField)
    {
        for (int i = 0; i < VELOCITY.size(); ++i)
        {
            if (VELOCITY[i] == velocity && B_FIELD[i] == BField)
            {
                return dirToString(FORCE[i]);
            }
        }
        return "Invalid Direction";
    }

}rhr;

static struct LHR
{
    LHR() {}

    vector<Direction> FORCE = {
            dir::N, dir::N, dir::N, dir::N,
            dir::S, dir::S, dir::S, dir::S,
            dir::E, dir::E, dir::E, dir::E,
            dir::W, dir::W, dir::W, dir::W,
            dir::I, dir::I, dir::I, dir::I,
            dir::O, dir::O, dir::O, dir::O
    };
    vector<Direction> VELOCITY = {
            dir::E, dir::W, dir::I, dir::O,
            dir::E, dir::W, dir::I, dir::O,
            dir::N, dir::S, dir::I, dir::O,
            dir::N, dir::S, dir::I, dir::O,
            dir::N, dir::S, dir::E, dir::W,
            dir::N, dir::S, dir::E, dir::W
    };
    vector<Direction> B_FIELD = {
            dir::O, dir::I, dir::E, dir::W,
            dir::I, dir::O, dir::W, dir::E,
            dir::I, dir::O, dir::S, dir::N,
            dir::O, dir::I, dir::N, dir::S,
            dir::W, dir::E, dir::N, dir::S,
            dir::E, dir::W, dir::S, dir::N
    };

    // given force and velocity get the direction of the B field
    basic_string<char> findBFieldDirection(Direction force, Direction velocity)
    {
        for (int i = 0; i < FORCE.size(); ++i)
        {
            if (FORCE[i] == force && VELOCITY[i] == velocity)
            {
                // return the direction of the B field as a string
                return dirToString(B_FIELD[i]);
            }
        }
        return "Invalid Direction";
    }
    // given force and B field get the direction of the velocity
    basic_string<char> findVelocityDirection(Direction force, Direction BField)
    {
        for (int i = 0; i < FORCE.size(); ++i)
        {
            if (FORCE[i] == force && B_FIELD[i] == BField)
            {
                return dirToString(VELOCITY[i]);
            }
        }
        return "Invalid Direction";
    }
    // given velocity and B field get the direction of the force
    basic_string<char>  findForceDirection(Direction velocity, Direction BField)
    {
        for (int i = 0; i < VELOCITY.size(); ++i)
        {
            if (VELOCITY[i] == velocity && B_FIELD[i] == BField)
            {
                return dirToString(FORCE[i]);
            }
        }
        return "Invalid Direction";
    }

}lhr;




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
     * @brief Calculates the m force (Lorentz force) on a charge q moving at
     * a speed v in a m field of strength B where theta is the angle
     * between the directions of v and B.
     * @param q The charge in Coulombs.
     * @param v The speed in m/s.
     * @param B The m field strength.
     * @param theta The angle theta between the directions
     * @param print bool to print or not (default true)
     * @return the m force in newtons
     */
    static ld mForce(ld q, ld v, ld B, ld theta, bool print = true);

    /**
     * @brief Calculates the electrom force on a charge q moving at a speed v
     * in a m field of strength with an electric field of strength E where
     * theta is the angle between the directions of v and B.
     * @param q The charge in Coulombs.
     * @param v The speed in m/s.
     * @param B The m field strength.
     * @param E The electric field strength.
     * @param theta The angle theta between the directions
     * @param print bool to print or not (default true)
     * @return the electrom force in newtons
     */
    static ld electromForce(ld q, ld v, ld B, ld E, ld theta, bool print = true);

    /**
     * @brief Calculates the m force at a maximum angle of sin(90) which is 1.
     * @param q The q.
     * @param B The b.
     * @param v The v.
     * @param print bool to print or not (default true)
     * @return m force (N)
     */
    static ld mForceMax(ld q, ld B, ld v, bool print = true);

    /**
     * @brief Calculates the charge of a particle moving at right angles to the
     * m field of B Tesla's with a speed of v m/s while experiencing a
     * m force of F newtons.
     * force of F Newtons.
     * @param F The force.
     * @param v The velocity.
     * @param B The m field strength.
     * @param print bool to print or not (default true)
     * @return charge (C)
     */
    static ld chargeOfParticle(ld F, ld v, ld B, bool print = true);

    /**
     * @brief A charged particle moving through a m field at an angles theta1 to
     * the field with a speed of v1 m/s experiences a m force of
     * F1 N. Determine the m force on an identical particle when
     * it travels through the same m field with a speed of v2 m/s at
     * an angle of theta2 relative to the m field.
     * @param v1 The velocity of particle 1.
     * @param v2 The velocity of particle 2.
     * @param F1 The force on particle 1.
     * @param theta1 The angle theta of particle 1.
     * @param theta2 The angle theta of particle 2.
     * @param print bool to print or not (default true)
     * @return force on particle 2
     */
    static ld mForceOnIdenticalParticle(ld v1, ld v2, ld F1, ld theta1, ld theta2, bool print = true);

    /**
     * @brief calculates the m the field strength.
     * B = F/(q*v*sin(theta*RADIAN))
     * @param F The m force (N).
     * @param q The charge (C).
     * @param v The speed (m/s).
     * @param theta The angle theta.
     * @param print bool to print or not (default true)
     * @return Tesla(T)
     */
    static ld mFieldStrength(ld F, ld q, ld v, ld theta, bool print = true);

    /**
     * @brief Calculates the m field strength from the centripetal motion of a
     * particle moving on a curvature of radius of r with a of mass m at a speed
     * of v with a charge of q .
     * @param m The mass.
     * @param v The speed.
     * @param q The charge.
     * @param r The radius.
     * @param print bool to print or not (default true)
     * @return Tesla's (T)
     */
    static ld mFieldStrength_Fc(ld m, ld v, ld q, ld r, bool print = true);

    /**
     * @brief Calculates the m field strength of a straight current carrying wire.
     * @param I The current.
     * @param r The shortest distance to the wire.
     * @param print bool to print or not (default true)
     * @return magnitude of m field strength
     */
    static ld mFieldStrength_straightCurrentCarryingWire(ld I, ld r, bool print = true);

    /**
     * @brief Calculates the m field strength center circular loop(s).
     * @param I The current.
     * @param R The radius of loop.
     * @param N The number of loops, default is 1.
     * @param print bool to print or not (default true)
     * @return m field strength (T)
     */
    static ld mFieldStrengthCenterCircularLoop(ld I, ld R, ld N, bool print = true);

    /**
     * @brief Calculates the m field strength inside solenoid.
     * @param n The number of loops per unit length n = N/l.
     * @param I The current.
     * @param print bool to print or not (default true)
     * @return m field strength inside a solenoid
     */
    static ld mField_solenoid(ld n, ld I, bool print = true);

    /**
     * @brief Calculates the m field strength inside solenoid.
     * @param N The Number of loops.
     * @param l The length.
     * @param I The current.
     * @param print bool to print or not (default true)
     * @return m field strength (T)
     */
    static ld mField_solenoid(ld N, ld l, ld I, bool print = true);

    /**
     * @brief Calculate the turns per unit length of a solenoid from the wire
     * diameter.
     * @param d The diameter of the wire.
     * @param print bool to print or not (default true)
     */
    static ld turnsPerUnitLength(ld d, bool print = true);

    /**
     * @brief The solenoid used in an MRI scanner is l m long and d m in
     * diameter. It’s wound from superconducting wire d_sc m in diameter, with
     * adjacent turns separated by an insulating layer of negligible thickness.
     * Find the current that will produce a B T m field inside the
     * solenoid.
     * @param d The diameter of the superconducting wire.
     * @param B The m field strength.
     * @param print bool to print or not (default true)
     */
    static ld currentInSolenoid(ld d, ld B, bool print = true);

    /**
     * @brief Frustrated by the small Hall voltage obtained in blood flow measurements,
     * a medical physicist decides to increase the applied m field strength
     * to get a E(hall voltage) output for blood moving at v m/s in a d m-diameter
     * vessel. Calculate the m field strength needed.
     * @param E The hall voltage.
     * @param d The diameter of vessel.
     * @param v The speed.
     * @param print bool to print or not (default true)
     * @return the m field strength
     */
    static ld mFieldStrengthHallVoltage(ld E, ld d, ld v, bool print = true);

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
     * to a m field of strength B
     * @param m The mass.
     * @param v The velocity.
     * @param q The charge.
     * @param B The m field strength.
     * @param theta The angle theta, defaulted at 90.
     * @param print bool to print or not (default true)
     * @return radius in meters
     */
    static ld radiusCurvatureOfPath(ld m, ld v, ld q, ld B, ld theta, bool print = true);

    /**
     * @brief If a single circular loop of wire carries a current of I A and produces
     * a m field at its center with a magnitude of B T, determine
     * the radius of the loop.
     * @param I The current.
     * @param B The m field strength.
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
     * curvature of radius r at a speed of v in a m field strength of B
     * @param r The radius.
     * @param q The charge.
     * @param B The m field strength.
     * @param v The velocity.
     * @param print bool to print or not (default true)
     * @return mass of particle in kg
     */
    static ld massOfChargedParticle(ld r, ld q, ld B, ld v, bool print = true);

    /**
     * @brief Calculates the velocity of a charged particle moving on a curvature of
     * radius r with a charge of q in a m field strength of B having a
     * mass of m.
     * @param r The radius.
     * @param q The charge.
     * @param B The m field strength.
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
     * @param B The uniform m field strength.
     * @param theta The angle theta between vD and B.
     * @param print bool to print or not (default true)
     * @return force in newtons
     */
    static ld forceOnWire(ld n, ld q, ld A, ld vD, ld l, ld B, ld theta, bool print = true);

    /**
     * @brief Calculates the force on a wire.
     * @param I The current(nqAvD).
     * @param l The length of wire.
     * @param B The m field strength.
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
     * @brief Calculates the torque on a current carrying loop of uniform m
     * field. Valid for a loop of any shape. The loop carries a current of I,
     * and has N turns each of area A, and the perpendicular to the loop makes
     * an angle theta with the m field B.
     * @param N The number of loops.
     * @param I The current (A).
     * @param A The area (m^2).
     * @param B The m field strength (T).
     * @param theta The angle between the loop and the m
     * field.
     * @param print bool to print or not (default true)
     * @return torque (N*m)
     */
    static ld torqueOnCurrentCarryingLoop_umf(ld N, ld I, ld A, ld B, ld theta, bool print = true);

    /**
     * @brief Calculates the maximum torque on a current carrying loop of uniform m
     * field. Valid for a loop of any shape. The loop carries a current of I,
     * and has N turns each of area A, with a uniform m field B. The
     * angle of sin at max torque is 90 degrees which sin(90) = 1 so sin is removed
     * from this equation.
     * @param N The number of loops.
     * @param I The current (A).
     * @param A The area (m^2).
     * @param B The uniform m field strength (T).
     * @param print bool to print or not (default true)
     * @return torque (N*m)
     */
    static ld torqueMaxOnCurrentCarryingLoop_umf(ld N, ld I, ld A, ld B, bool print = true);

    /**
     * @brief Calculates the current in a current carrying loop using known torque when
     * at maximum with a N number of loops each with an area of A and a uniform
     * m field strength of B.
     * @param tMax The torque maximum.
     * @param N The number of loops.
     * @param A The area.
     * @param B The m filed strength.
     * @param print bool to print or not (default true)
     * @return current in loops (A)
     */
    static ld currentFromTorqueMax(ld tMax, ld N, ld A, ld B, bool print = true);

    /**
     * @brief Calculates the current in a long straight wire that would produce a
     * m field of B at a distance of r (m) from the wire
     * @param r The shortest distance to the wire.
     * @param B The m field strength.
     * @param print bool to print or not (default true)
     * @return current (A)
     */
    static ld currentInLongStraightWire(ld r, ld B, bool print = true);

    /**
     * @brief You have designed and constructed a solenoid to produce a m field
     * equal in magnitude to B. If your solenoid
     * has n turns and is l cm long, determine the current you must use in
     * order to obtain a m field of the desired magnitude.
     * @param B The desired m field strength.
     * @param n The number of turns on the solenoid.
     * @param l The length of the solenoid.
     * @param print bool to print or not (default true)
     * @return the current needed (I)
     */
    static ld currentSolenoid(ld B, ld n, ld l, bool print = true);

    /**
     * @brief Calculate the angle the velocity of the electron
     * makes with the m field if an electron moving at v m/s
     * in a B (T) m field experiences a m force of F N.
     * @param v The velocity.
     * @param B The electric field strength.
     * @param F The force.
     * @param q The charge, default is elementary charge of electron.
     * @param print bool to print or not (default true)
     * @return angle theta
     */
    static ld angleThetaOfElectronTomField(ld v, ld B, ld F, ld q, bool print = true);

    /**
     * @brief A velocity selector in a mass spectrometer uses a B(T) m field.
     * Calculate what electric field strength is needed to select a
     * speed of v m/s.
     * @param v The velocity selected on the spectrometer.
     * @param B The m field strength.
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
     * m field  pointing out of the page. Only the m force acts on
     * the ions in this region, so they undergo circular motion and, after half
     * an orbit, land on a detector. Find an expression for the horizontal distance
     * from the entrance slit to the point where an ion lands on the detector.
     * @param q The charge of the ion.
     * @param m The mass of the ion.
     * @param V The potential difference.
     * @param B The m field strength.
     * @param print bool to print or not (default true)
     * @return distance (m)
     */
    static ld distanceIonLandsOnDetector(ld q, ld m, ld V, ld B, bool print = true);

    /**
     * @brief Calculate the cyclotron frequency of a particle with charge q and mass m
     * in a m field B.
     * @param q The charge of the particle.
     * @param m The mass of the particle.
     * @param B The m field strength.
     * @param print bool to print or not (default true)
     * @return frequency (Hz)
     */
    static ld cyclotronFrequency(ld q, ld m, ld B, bool print = true);

    /**
     * @brief Calculate the period of a particles circular orbit in a m field B.
     * @param q The charge of the particle.
     * @param m The mass of the particle.
     * @param B The m field strength.
     * @param print bool to print or not (default true)
     * @return period (s)
     */
    static ld periodOfCircularOrbit(ld q, ld m, ld B, bool print = true);

    /**
     * @brief Calculate the m force on a current carrying wire in a
     * m field B, where theta is the angle between the current and the
     * m field.
     * @param I The current.
     * @param B The m field strength.
     * @param l The length of current path.
     * @param theta The angle between the current and the m field.
     * Default is sin(90) = 1.
     * @param print bool to print or not (default true)
     * @return force (N)
     */
    static ld mForceOnCurrentCarryingWire(
            ld I, ld B, ld l, ld theta = 90.0, bool print = true);

    /**
     * @brief Calculate the charge using the biot-savart law.
     * @param I The current.
     * @param l The length of current path.
     * @param r The distance from the current path to the point of interest.
     * @param theta The angle between the current and the m field.
     * Default is sin(90) = 1.
     * @param print bool to print or not (default true)
     */
    static ld biotSavartLaw(ld I, ld l, ld r, ld theta = 90.0, bool print = true);

    /**
     * @brief Calculating the m field at P due to an infinite straight
     * wire carrying current  along the axis.
     * @param I The current.
     * @param r The distance from the current path to the point of interest.
     * @param print bool to print or not (default true)
     */
    static ld mFieldStraightWire(ld I, ld r, bool print = true);

    /**
     * @brief Calculate the m force between two parallel wires.
     * @param I1 The current in wire 1.
     * @param I2 The current in wire 2.
     * @param d The distance between the wires.
     * @param l The length of the wires.
     * @param print bool to print or not (default true)
     * @return force (N)
     */
    static ld mForceBetweenTwoParallelWires(
            ld I1, ld I2, ld d, ld l, bool print = true);

    /**
     * @brief Use Ampere's law for steady currents to calculate the m field
     * @param I The current.
     * @param print bool to print or not (default true)
     * @return m field (T)
     */
    static ld amperesLaw(ld I, bool print = true);

    /**
     * @brief Ampère’s Law: Solar Currents The long dimension of a rectangular
     * loop is l m, and the m field strength near the loop has a
     * constant magnitude of B T. Estimate the total current encircled by
     * the rectangle.
     * @param l The length of the rectangle.
     * @param B The m field strength.
     * @param print bool to print or not (default true)
     * @return current (A)
     */
    static ld amperesLawSolarCurrents(ld l, ld B, bool print = true);

    /**
     * @brief Calculate the field outside andy current distribution with line
     * symmetry.
     * @param I The current.
     * @param r The distance from the current path to the point of interest.
     * @param print bool to print or not (default true)
     * @return m field (T)
     */
    static ld mField_lineCurrent_outside(ld I, ld r, bool print = true);

    /**
     * @brief Calculate the m field inside a uniform current
     * distribution with line symmetry.
     * @param I The current.
     * @param r The distance from the current path to the point of interest.
     * @param R The radius of the current distribution.
     * @param print bool to print or not (default true)
     * @return m field (T)
     */
    static ld mField_lineCurrent_inside(ld I, ld r, ld R, bool print = true);

    /**
     * @brief Calculate the m field of an infinite width current sheet
     * @param I The current.
     * @param l The length of the current sheet.
     * @param print bool to print or not (default true)
     */
    static ld mField_sheet(ld I, ld l, bool print = true);

    /**
     * @brief Calculate the m dipole moment of a current loop.
     * @param I The current.
     * @param A The area of the current loop.
     * @param print bool to print or not (default true)
     * @return m dipole moment (A m^2)
     */
    static ld mDipoleMoment_loop(ld I, ld A, bool print = true);

    /**
     * @brief find direction of Force using RHR given direction of velocity
     * and the B field
     * @param v Direction of velocity
     * @param B Direction of B field
     * @param positive bool, true if positive, false if negative (default true)
     * @param print bool to print or not (default true)
     * @return direction of force
     */
     static basic_string<char>  findDirectionOfForce(
             Direction v, Direction B, bool positive = true, bool print = true);

    /**
     * @brief find the direction of velocity using RHR given direction of force
     * and the B field
     * @param F Direction of force
     * @param B Direction of B field
     * @param positive bool, true if positive, false if negative (default true)
     * @param print bool to print or not (default true)
     * @return direction of velocity
     */
     static basic_string<char>  findDirectionOfVelocity(
             Direction F, Direction B, bool positive = true, bool print = true);

     /**
      * @brief find the direction of B field using RHR given direction of force
      * and the velocity
      * @param F Direction of force
      * @param v Direction of velocity
      * @param positive bool, true if positive, false if negative (default true)
      * @param print bool to print or not (default true)
      * @return direction of B field
      */
     static basic_string<char>  findDirectionOfBField(
             Direction F, Direction v, bool positive = true, bool print = true);

     /**
      * @brief find the direction of the magnetic field at a point relative
      * to the direction of the current
      * @param I Direction of current
      * @param P Direction of point relative to current
      * @param print bool to print or not (default true)
      * @return direction of B field
      */
//        static basic_string<char>  findDirectionOfBFieldCurrentLoop(Direction I, Direction P, bool print = true);


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

inline ld Magnetism::mForce(const ld q, const ld v, const ld B, const ld theta, bool print)
{
    auto Fb = q*v*B*sin(theta*constants::RADIAN);//Newtons
    if (print)
        std::cout << "m force: " << Fb << " N" << std::endl;
    return Fb;
}

inline ld Magnetism::mForceMax(const ld q, const ld B, const ld v, bool print)
{
    auto Fb_max = q * v * B;//N
    if (print)
        std::cout << "m force max: " << Fb_max << " N" << std::endl;
    return Fb_max;
}

inline ld Magnetism::chargeOfParticle(const ld F, const ld v, const ld B, bool print)
{
    auto Q = F / (v * B);//(C)
    if (print)
        std::cout << "Charge of particle: " << Q << " C" << std::endl;
    return Q;
}

inline ld Magnetism::mForceOnIdenticalParticle(const ld v1, const ld v2, const ld F1, const ld theta1, const ld theta2, bool print)
{
    auto Fbb =  (F1 * v2 * sin(theta2 * constants::RADIAN)) /
            (v1 * sin(theta1 * constants::RADIAN));//F2 (N)
    if (print)
        std::cout << "m force on identical particle: " << Fbb << " N" << std::endl;
    return Fbb;
}

inline ld Magnetism::mFieldStrength(const ld F, const ld q, const ld v, const ld theta, bool print)
{
    //Tesla(T) = 1N/C*m/s = 1N/A*m a newton amp meter
    auto B = F/(q*v*sin(theta*constants::RADIAN));
    if (print)
        std::cout << "m field strength: " << B << " T" << std::endl;
    return B;
}

inline ld Magnetism::mFieldStrength_Fc(const ld m, const ld v, const ld q, const ld r, bool print)
{
    auto Fc = (m * v) / (q * r);//(T)
    if (print)
        std::cout << "m field strength: " << Fc << " T" << std::endl;
    return Fc;
}

inline ld Magnetism::mFieldStrength_straightCurrentCarryingWire(const ld I, const ld r, bool print)
{
    auto Bccw = (constants::mu0 * I) / (2.0 * constants::PI * r);//(T)
    if (print)
        std::cout << "m field strength: " << Bccw << " T" << std::endl;
    return Bccw;
}

inline ld Magnetism::mFieldStrengthCenterCircularLoop(const ld I, const ld R, const ld N = 1.0, bool print)
{
    auto B = (N * constants::mu0 * I) / (2.0 * R);//(T)
    if (print)
        std::cout << "m field strength: " << B << " T" << std::endl;
    return B;
}

inline ld Magnetism::mField_solenoid(ld n, ld I, bool print)
{
    auto B = constants::mu0 * n * I;//(T)
    if (print)
        std::cout << "m field strength: " << B << " T" << std::endl;
    return B;
}

inline ld Magnetism::mField_solenoid(ld N, ld l, ld I, bool print)
{
    auto B = constants::mu0 * (N / l) * I;//T
    if (print)
        std::cout << "m field strength: " << B << " T" << std::endl;
    return B;
}

inline ld Magnetism::mFieldStrengthHallVoltage(const ld E, const ld d, const ld v, bool print)
{
    auto B = E / (d * v);//T
    if (print)
        std::cout << "m field strength: " << B << " T" << std::endl;
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

inline ld Magnetism::angleThetaOfElectronTomField(const ld v, const ld
B, const ld F, const ld q = constants::ELECTRON_CHARGE, bool print)
{
    auto theta = asin(F / (-q * v * B))*constants::DEGREE;//angle theta
    if (print)
        std::cout << "Angle theta of electron to m field: " << theta << " degrees" << std::endl;
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
Magnetism::electromForce(ld q, ld v, ld B, ld E, ld theta, bool print) {
    auto F = q * v * B * sin(theta * constants::RADIAN) + q * E;//N
    if (print)
        std::cout << "Electro m force: " << F << " N" << std::endl;
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

inline ld Magnetism::mForceOnCurrentCarryingWire(
        ld I, ld B, ld l, ld theta, bool print) {
    auto F = (I * B * l * sin(theta * constants::RADIAN));//N
    if (print)
        std::cout << "m force on current: " << F << " N" << std::endl;
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

ld Magnetism::mForceBetweenTwoParallelWires(ld I1, ld I2, ld d, ld l,
                                                   bool print) {
    auto mu0 = constants::mu0;
    auto pi = constants::PI;
    auto F2 = mu0 * (I1 * I2 * l) / (2.0 * d);//N
    if (print)
        std::cout << "m force between two parallel wires: " << F2 << " N" << std::endl;
    return F2;
}

ld Magnetism::mFieldStraightWire(ld I, ld r, bool print) {
    auto mu0 = constants::mu0;
    auto pi = constants::PI;
    auto B = (mu0 * I) / (2.0 * pi * r);//T
    if (print)
        std::cout << "m field straight wire: " << B << " T" << std::endl;
    return B;
}

ld Magnetism::amperesLaw(ld I, bool print) {
    auto B = I * constants::mu0;//T
    if (print)
        std::cout <<  "Amperes law: " << B << " T" << std::endl;
    return B;
}

ld Magnetism::amperesLawSolarCurrents(ld l, ld B, bool print) {
    auto I = (2.0 * l * B) / constants::mu0;//A
    if (print)
        std::cout << "Amperes law solar currents: " << I << " A" << std::endl;
    return I;
}

ld Magnetism::mField_lineCurrent_outside(ld I, ld r, bool print) {
    auto B = (constants::mu0 * I) / (2.0 * constants::PI * r);//T
    if (print)
        std::cout << "m field outside line symmetry: " << B << " T" << std::endl;
    return B;
}

ld Magnetism::mField_lineCurrent_inside(ld I, ld r, ld R, bool print) {
    auto B = (constants::mu0 * I * r) / (2.0 * constants::PI * R * R);//T
    if (print)
        std::cout << "m field inside line symmetry: " << B << " T" << std::endl;
    return B;
}

ld Magnetism::mField_sheet(ld I, ld l, bool print) {
    auto J = I / l;//A/m^2
    auto B = (1.0 / 2.0) * constants::mu0 * J;//T
    if (print)
        std::cout << "m field infinite width current sheet: " << B << " T" << std::endl;
    return B;
}

ld Magnetism::turnsPerUnitLength(ld d, bool print) {
    auto N = 1.0 / d;//turns/m
    if (print)
        std::cout << "Turns per unit length: " << N << " turns/m" << std::endl;
    return N;
}

ld Magnetism::currentInSolenoid(ld d, ld B, bool print) {
    auto N = turnsPerUnitLength(d, false);
    auto I = (B) / (constants::mu0 * N);//A
    if (print)
        std::cout << "Current in solenoid: " << I << " A" << std::endl;
    return I;
}

ld Magnetism::mDipoleMoment_loop(ld I, ld A, bool print) {
    auto mu = I * A;//A*m^2
    if (print)
        std::cout << "m dipole moment loop: " << mu << " A*m^2" << std::endl;
    return mu;
}

basic_string<char>
Magnetism::findDirectionOfForce(
        Direction v, Direction B, bool positive, bool print) {
    basic_string<char> direction;
    if (positive) {
        // use RHR to find direction of force
        direction = rhr.findForceDirection(v, B);
    } else {
        // use LHR to find direction of force
        direction = lhr.findForceDirection(v, B);
    }
    if (print)
        std::cout << "Direction of force: " << direction << std::endl;
    return direction;
}

basic_string<char>
Magnetism::findDirectionOfVelocity(
        Direction F, Direction B, bool positive, bool print) {
    basic_string<char> direction;
    if (positive) {
        // use RHR to find direction of velocity
        direction = rhr.findVelocityDirection(F, B);
    } else {
        // use LHR to find direction of velocity
        direction = lhr.findVelocityDirection(F, B);
    }
    if (print)
        std::cout << "Direction of velocity: " << direction << std::endl;
    return direction;
}

basic_string<char>
Magnetism::findDirectionOfBField(
        Direction F, Direction v, bool positive, bool print) {
    basic_string<char> direction;
    if (positive) {
        // use RHR to find direction of B field
        direction = rhr.findBFieldDirection(F, v);
    } else {
        // use LHR to find direction of B field
        direction = lhr.findBFieldDirection(F, v);
    }
    if (print)
        std::cout << "Direction of B field: " << direction << std::endl;
    return direction;
}
