//
// Created by Ryan.Zurrin001 on 12/15/2021.
//

#ifndef PHYSICSFORMULA_ELECTRICCHARGE_H
#define PHYSICSFORMULA_ELECTRICCHARGE_H
/**
 * @class ElectricCharge
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @date  12/31/2020
 * @version 12.13.2022
 */
#include <iostream>
#include <vector>
#include "UnitVector.h"
#include "Vector3D.h"
typedef long double ld;

static int electricCharge_objectCount = 0;


constexpr ld distanceBetweenPoints(
        const pair<ld, ld>& p1, const pair<ld, ld>& p2)
{
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) +
                (p1.second - p2.second) * (p1.second - p2.second));
}

constexpr ld directionOfForce(const pair<ld, ld>& p1, const pair<ld, ld>& p2)
{
    return atan2(p2.second - p1.second, p2.first - p1.first);
}

constexpr int signOfForce(const ld q1, const ld q2)
{
    return q1 * q2 > 0 ? 1 : -1;
}

static struct ScientificNotationUnits
{
    const ld YOTTA = 1e24; // 10^24
    const ld ZETTA = 1e21; // 10^21
    const ld EXA   = 1e18; // 10^18
    const ld PETA  = 1e15; // 10^15
    const ld TERA  = 1e12; // 10^12
    const ld GIGA  = 1e9;  // 10^9
    const ld MEGA  = 1e6;  // 10^6
    const ld KILO  = 1e3;  // 10^3
    const ld HECTO = 1e2;  // 10^2
    const ld DECA  = 1e1;  // 10^1
    const ld DECI  = 1e-1; // 10^-1
    const ld CENTI = 1e-2; // 10^-2
    const ld MILLA = 1e-3; // 10^-3
    const ld MICRO = 1e-6; // 10^-6
    const ld NANO  = 1e-9; // 10^-9
    const ld PICO  = 1e-12;// 10^-12
    const ld FEMTO = 1e-15;// 10^-15
    const ld ATTO  = 1e-18;// 10^-18
    const ld ZEPTO = 1e-21;// 10^-21
    const ld YOCTO = 1e-24;// 10^-24
} SU;

class ElectricCharge
{
public:
    ElectricCharge()
    {
        countIncrease();
    }

    explicit ElectricCharge(ld val)
    {
        countIncrease();
    }

    /**
     * @brief copy constructor
     */
    ElectricCharge(const ElectricCharge& t)
    {
        countIncrease();
    }

    /**
     * #brief move constructor
     */
    ElectricCharge(ElectricCharge&& t) noexcept
    {
        countIncrease();
    }

    /**
     * @brief copy assignment operator
     */
    ElectricCharge& operator=(const ElectricCharge& t)
    {
        if (this != &t)
        {
            countIncrease();
        }
        return *this;
    }

    static void show_objectCount()
    {
        std::cout << "\n electric charge object count: " <<
                  electricCharge_objectCount << std::endl;
    }

    static int get_objectCount() { return electricCharge_objectCount; }

    /**
     * @brief Creates mass from energy.
     * @param E The energy.
     * @param c The speed of light.
     * @param print if true, prints the result to the console.
     * @return mass
     */
    static constexpr ld massFromEnergy(ld E, ld c, bool print = true);

    /**
     * @brief Mass from energy.
     * @param M The electrons mass.
     * @param print if true, prints the result to the console.
     * @return mass of electrons
     */
    static constexpr ld massFromEnergy(ld M, bool print = true);

    /**
     * @brief Totals the electron mass.
     * @param Ne The total electrons.
     * @param print if true, prints the result to the console.
     * @return mass of electrons in kg
     */
    static constexpr ld totalElectronMass(ld Ne, bool print = true);

    /**
     * @brief Totals the proton mass.
     * @param Np The total protons.
     * @param print if true, prints the result to the console.
     * @return mass of protons in kg
     */
    static constexpr ld totalProtonMass(ld Np, bool print = true);

    /**
     * @brief Totals the mass.
     * @param Ne The total electrons.
     * @param Np The total protons.
     * @param print if true, prints the result to the console.
     * @return the total mass of protons and electrons
     */
    static constexpr ld totalMass(ld Ne, ld Np, bool print = true);

    /**
     * @brief Calculates the magnitude of force between two electrostatic forces
     * q1 and q2 using coulomb's law.
     * @param q1 The charge of first particle.
     * @param q2 The charge of second particle.
     * @param r The distance between the charges.
     * @param print if true, prints the result to the console.
     * @return magnitude of force between two electrostatic forces
     */
    static constexpr ld coulombsLaw(
            ld q1, ld q2, ld r, bool print = true);

    /**
     * @brief Calculates the magnitude of force between two electrostatic
     * forces q1 and q2 using coulomb's law.
     * @param q1  The charge of first particle.
     * @param xy1  The x and y coordinates of the first particle.
     * @param q2  The charge of second particle.
     * @param xy2  The x and y coordinates of the second particle.
     * @param multiplier  The multiplier for the distance between the charges.
     * @param print  if true, prints the result to the console.
     * @return  magnitude of force between two electrostatic forces
     */
    static constexpr ld coulombsLaw(
            ld q1, pair<ld, ld> xy1, ld q2, pair<ld, ld> xy2,
            int multiplier = 1, bool print = true);

    /**
     * @brief electric dipole moment is defined as the product of the charge q
     * and the separation d between the two charges making up the dipole.
     * @param q The charge.
     * @param d The separation.
     * @param print if true, prints the result to the console.
     * @return the electric dipole moment
     */
    static constexpr ld dipoleMoment(ld q, ld d, bool print = true);

    /**
     * @brief dipole field for |y|  >> a, on perpendicular bisector.
     * @param p The dipole moment.
     * @param y The y axis.
     * @param print if true, prints the result to the console.
     * @return the electric dipole field
     */
    static constexpr ld dipoleFieldPerpendicularBisector(
            ld p, ld y, bool print = true);

    /**
     * @brief dipole field for |x| >> a, on axis
     * @param p The dipole moment.
     * @param x The x axis.
     * @param print if true, prints the result to the console.
     * @return the electric dipole field
     */
    static constexpr ld dipoleFieldForXAxis(ld p, ld x, bool print = true);

    /**
     * @brief Calculates the charge of electrostatic force equal point charges.
     * @param q The q.
     * @param mass The mass.
     * @param r The r.
     * @param print if true, prints the result to the console.
     * @return the charge of electrostatic force equal point charges
     */
    static ld chargeOfElectrostaticForce_equalPointCharges(
            ld q, ld mass, ld r, bool print = true);

    /**
     * @brief Calculates the electric field E.
     * @param COULOMB The q.
     * @param r The r.
     * @param print if true, prints the result to the console.
     * @return the electric field e
     */
    static constexpr ld electricFieldForce(ld Q, ld r, bool print = true);

    /**
     * @brief calculates the force by an electric field and current
     * @param q The current.
     * @param E The electric field strength.
     * @param print if true, prints the result to the console.
     * @return the force by an electric field and current
     */
    static constexpr ld forceByElectricField(ld q, ld E, bool print = true);

    /**
     * A positive charge +NQ is located at the origin, and a negative charge
     * -Q is at x = a In which region of the axis is there a point where the
     * force on a test charge—and therefore the electric field—is zero?
     * @param Qp: number of positive charges
     * @param Qn: number of negative charges
     * @param a: distance between charges
     * @return: the distance from the origin where the electric field is zero
     */
    static ld electricFieldZero(ld Qp, ld Qn, ld a, bool print =
            false);

    /**
     * @brief Calculates the  electrons needed to form a charge of baseNumber to
     * the su power.
     * @param baseNumber The base number.
     * @param su The scientific notation multiple.
     * @param print if true, prints the result to the console.
     * @return number of electrons
     */
    static constexpr ld electrons(ld baseNumber, ld su, bool print = true);

    /**
     * @brief Calculates the number of electrons.
     * @param protons The protons.
     * @param netCharge The net charge.
     * @param print if true, prints the result to the console.
     * @return number of electrons
     */
    static ld netElectronCount(ld protons, ld netCharge, bool print = true);

    static constexpr ld totalElectrons(ld q, bool print = true);

    /**
     * @brief Calculates the coulomb.
     * @param baseNumber The base number.
     * @param su The su.
     * @param print if true, prints the result to the console.
     * @return the coulomb
     */
    static constexpr ld coulombs(ld baseNumber, ld su, bool print = true);

    /**
     * @brief Calculates the number of electrons less than protons.
     * @param netCharge The net charge.
     * @param print if true, prints the result to the console.
     * @return number of electrons
     */
    static ld howManyFewerElectronsThenProtons(ld netCharge, bool print = true);

    /**
     * @brief Calculates the fraction of protons to electrons.
     * @param protons The protons.
     * @param netCharge The net charge.
     * @param print if true, prints the result to the console.
     * @return fraction of protons to electrons
     */
    static ld fractionProtonsNoElectrons(ld protons, ld netCharge, bool print = true);

    /**
     * @brief Calculates the force change two point charges.
     * @param F The f.
     * @param factorChange The factor change.
     * @param print if true, prints the result to the console.
     * @return the force change two point charges
     */
    static constexpr ld forceChangeTwoPointCharges(ld F, ld factorChange, bool print = true);

    /**
     * @brief Calculates the electric field.
     * @param F The force.
     * @param q The charge.
     * @param print if true, prints the result to the console.
     * @return the electric field
     */
    static constexpr ld electricField(ld F, ld q, bool print = true);

    static ld electricFieldFromPointChargeDistribution(
            vector<ld> charges, vector<ld> r_vals, bool print = true);

    /**
     * @brief Calculates the electric field caused by point charges.
     * @param q The charge.
     * @param r The radius.
     * @param print if true, prints the result to the console.
     * @return the electric field
     */
    static constexpr ld electricFieldByPointCharge(ld q, ld r, bool print = true);

    /**
     * Two protons are d nm apart. Find the electric field at a point between
     * them, r1 nm from one of the protons. Then find the force on an electron
     * at this point.
     * @param d the distance between the two protons
     * @param r1 the distance from one of the protons
     * @return the force on an electron at this point
     */
    static ld forceOnElectron(ld d, ld r1, bool print = true);

    /**
     * @brief Calculates the magnitude of a point charge that creates a electric
     * field force of F,  at a distance of r meters.
     * @param E The force of the electric field in N/C.
     * @param r The distance it causes this force.
     * @param print if true, prints the result to the console.
     * @return magnitude of the point charge (C)
     */
    static constexpr ld magnitudePointCharge(ld E, ld r, bool print = true);

    /**
     * @brief Calculates the charge of a point particle having a force of F
     * acting on it with a electric field strength of E at its location.
     * @param F The force acting on a charge.
     * @param E The electric field strength.
     * @param print if true, prints the result to the console.
     * @return the charge of the point particle (C)
     */
    static constexpr ld charge(ld F, ld E, bool print = true);

    /**
     * @brief Calculates the electric flux (number of field lines per unit area)
     * over A meters^2 with electric field strength E. If the electric field
     * is hitting the surface at an angle that is not perpendicular to the
     * the surface, then the angle between the normal of the surface and the
     * electric field is theta.
     * @param E  the electric field strength
     * @param A  the area of the charge
     * @param theta  the angle between the electric field and the normal of
     * the surface in degrees.
     * @return
     */
    static constexpr ld electricFlux(ld E, ld A, ld theta, bool print = true);

    /**
     * @brief Calculates the electric flux (number of field lines per unit area)
     * @param E  the electric field strength Vector
     * @param A  The Unit area Vector
     * @param print  print the result
     * @return  the electric flux
     */
    static ld electricFlux(Vector3D E, Vector3D A, bool print = true);

    /**
     * @brief Calculates the electric flux (number of field lines per unit
     * area) of  a disc with radius R and electric field strength E with an
     * angle of theta between the normal of the disc and the electric field.
     * @param E  the electric field strength
     * @param R  the radius of the disc
     * @param theta  the angle between the electric field and the normal of
     * @param print  print the result
     * @return  the electric flux
     */
    static constexpr ld electricFluxDisc(ld E, ld R, ld theta, bool print = true);

    /**
     * @brief Calculates he static electric field generated by a distribution of
     * electric charges
     * @param q the charge over an area
     * @return the static electric field strength
     */
    static constexpr ld electricFluxSphere(ld q, bool print = true);

    /**
     * @brief Calculates the elextric flux of a charged sphere of radius r,
     * with and
     * @param E the electric field strength
     * @param r the radius of the sphere
     * @param print whether or not to print the result
     * @return the electric flux
     */
    static constexpr ld electricFluxSphere(ld E, ld r, bool print = true);

    /**
     * @brief Calculates the flux through a half cylinder of radius r and and
     * length l with an electric field strength of E.
     * @param E  the electric field strength
     * @param r  the radius of the cylinder
     * @param l  the length of the cylinder
     * @param print  whether or not to print the result
     * @return  the electric flux
     */
    static constexpr ld fluxThroughHalfCylinder(ld E, ld r, ld l, bool print =
            false);

    /**
     * @brief Calculates the electric field strength caused by a distribution of
     * electric charges over a spherical surface using Gauss's law.
     * @param Q the charge over an area
     * @param r the radius of the sphere
     * @return  the electric field strength
     */
    static constexpr ld fieldOutsideSphericalChargeDistribution(
            ld Q, ld r, bool print = true);

    /**
     * @brief Calculates the filed inside a uniformly charged sphere using
     * Gauss's law.
     * @param Qr the charge over an area
     * @param R the radius of the sphere
     * @param print whether or not to print the result
     * @return the electric field strength
     */
    static constexpr ld fieldInsideSphericalChargeDistribution(
            ld Qr, ld R, bool print = true);

    /**
     * @brief Calculates the electric field strength caused by a distribution
     * of electric charges over a spherical surface using Gauss's law.
     * @param Q the charge
     * @param A the area of the sphere
     * @return  the electric field strength
     */
    static constexpr ld gaussSphericalSymmetry(ld Q, ld A, bool print = true);

    /**
     * @brief Calculates the electric field of a distribution of electric
     * charges over a symmetric line of length infinity.
     * @param lambda line charge density
     * @param r  the radius of the line
     * @return  the electric field strength
     */
    static constexpr ld fieldOfALineCharge(ld lambda, ld r, bool print = true);

    /**
     * @brief Calculates the electric field of a distribution of electric charges
     * over a symmetric line of length l having a radius of r and a charge of q.
     * @param q the charge over an area
     * @param l the length of the line
     * @param r the radius of the line
     * @param print whether or not to print the result
     * @return the electric field strength
     */
    static constexpr ld fieldOfLineCharge(ld q, ld l, ld r, bool print = true);

    /**
     * @brief Calculates the line charge density (lambda) of a uniformly charged
     * line of length infinity.
     * @param q  the charge over an area
     * @param L  the length of the line
     * @param print  whether or not to print the result
     * @return  the line charge density
     */
    static constexpr ld linearChargeDensity(ld q, ld L, bool print = true);

    /**
     * @brief Calculate the surface charge density of a uniformly charged
     * sheet of charge Q and area A.
     * @param Q the charge
     * @param A  the area
     * @param print  true to print the answer
     * @return  the surface charge density
     */
    static constexpr ld surfaceChargeDensity(ld Q, ld A, bool print = true);

    /**
     * @brief Calculate the surface charge density of a uncharged spherical
     * conducting shell of radius r with a charge Q placed at the center.
     * @param Q  the charge
     * @param r  the radius
     * @param print  true to print the answer
     * @return  the surface charge density
     */
    static constexpr ld surfaceChargeDensitySphere(ld Q, ld r, bool print = true);

    /**
     * An electron close to a large, flat sheet of charge is repelled from the
     * sheet with a E force. Calculate the surface charge density of the sheet.
     * @param E the force
     * @param print true to print the answer
     * @return the surface charge density
     */
    static constexpr ld surfaceChargeDensity(ld E, bool print = true);

    /**
     * @brief Calculates the volume charge density of a uniformly charged sphere
     * of radius r and charge Q.
     * @param Q the charge
     * @param V the volume
     * @param print true to print the answer
     * @return the volume charge density
     */
    static constexpr ld volumeChargeDensity(ld Q, ld V, bool print = true);

    /**
     * @brief Calculates the volume charge density of a uniformly charged sphere
     * of radius r and charge Q.
     * @param Q the charge
     * @param r the radius
     * @param print true to print the answer
     * @return the volume charge density
     */
    static constexpr ld volumeChargeDensitySphere(ld Q, ld r, bool print = true);

    /**
     * @brief Calculates the volume charge density of a uniformly charged
     * cylinder of radius r and length l and charge Q.
     * @param Q the charge
     * @param r the radius
     * @param l the length
     * @param print true to print the answer
     * @return the volume charge density
     */
    static constexpr ld volumeChargeDensityCylinder(
            ld Q, ld r, ld l, bool print = true);

    /**
     * @brief Calculates the volume charge density of a
     */

    /**
     * @brief Separates the between point charges.
     * @param q1 point charge 1.
     * @param q2 point charge 2.
     * @param F The Force in Newtons.
     * @param print whether or not to print the result
     * @return the separation between the point charges (m)
     */
    static ld separationBetweenPointCharges(
            ld q1, ld q2, ld F, bool print = true);

    /**
     * @brief Hows the many electrons.
     * @param totalParticles The total particles.
     * @param netCharge The net charge.
     * @param print whether or not to print the result
     * @return the number of electrons
     */
    static constexpr ld howManyElectrons(ld totalParticles, ld netCharge, bool print = true);

    /**
     * @brief Minimums the charge to lift object.
     * @param r The radius.
     * @param charge The charge.
     * @param m The mass.
     * @param print whether or not to print the result
     * @return the minimum charge to lift the object
     */
    static ld minimumChargeToLiftObject(ld r, ld charge, ld m, bool print = true);

    /**
     * @brief A wrecking yard inventor wants to pick up cars by charging a ball
     * of radius r (d/2) by inducing an equal and opposite charge on the car.
     * If a car has a mass of m kg and the ball is to be able to lift it from
     * a distance of l meters away, What minimum charge must be used?
     * @param r The radius of bass.
     * @param l The length of initial lift .
     * @param m The mass.
     * @param print whether or not to print the result
     * @return the minimum charge needed in C
     */
    static ld minimumChargeToLiftCar(ld r, ld l, ld m, bool print = true);

    /**
     * @brief Calculates the net force on charge from other charges.
     * @param q0  the charge of the charge in question
     * @param q0Loc the location of the charge in question
     * @param charges  the charges
     * @param chargeLocs  the locations of the charges
     * @param print  whether or not to print the result
     * @return  the net force on the charge
     */
    static ld netForceOnChargeFromOtherCharges(ld q0, pair<ld, ld> q0Loc,
                                               vector<ld> charges,
                                               vector<pair<ld, ld>>
                                               chargeLocs,
                                               bool print = true);

    /**
     * @brief Superposition principle. Adding charges up.
     * @param Qref The refrence charge to find the total charge.
     * @param Qloc the pair of coordinates of the charge.
     * @param charges a vector of charges
     * @param locations a vector of pairs for each of the charges coordinates.
     * @param print whether or not to print the result
     * @return net charge vector
     */
    static vector<ld> superpositionPrinciple(
            ld Qref,
            pair<ld, ld> Qloc,
            const vector<ld>& charges,
            const vector<pair<ld, ld>>& locations,
            bool print = true);

    /**
     * @brief Distance between points.
     * @param q1 The q1.
     * @param q2 The q2.
     * @param F The f.
     * @param print whether or not to print the result
     * @return the distance between the points
     */
    static ld distanceBetweenPoints(ld q1, ld q2, ld F, bool print = true);

    /**
     * @brief Angles the vertical axis.
     * @param Fe The force of the electric field.
     * @param mass The mass.
     * @param print whether or not to print the result
     * @return the angle of the vertical axis
     */
    static ld angleVerticalAxis(ld Fe, ld mass, bool print = true);

    /**
     * @brief Two raindrops with equal masses of m are in a thunderhead r meters apart
     * when they each acquire charges of q1 and q2. Find their acceleration.
     * @param m The mass.
     * @param r The distance between particles.
     * @param q1 The charge on particle 1.
     * @param q2 The charge on particle 2.
     * @param print whether or not to print the result
     * @return acceleration in m/s^2
     */
    static constexpr ld accelerationOfParticles(ld m, ld r, ld q1, ld q2, bool print = true);

    /**
     * @brief Calculate the electric field strength near a conducting sphere with a
     * d diameter of d meters that has q_excess amount of excess charge on it.
     * @param d The diameter.
     * @param q_excess The excess charge.
     * @param print whether or not to print the result
     * @return Electric field strength
     */
    static constexpr ld electricFieldStrength(ld d, ld q_excess, bool print = true);

    /**
     * @brief A charged insulating ball of mass m hangs on a long string with a length
     * that don't matter, in a uniform horizontal electric field.
     * Given the charge on the ball is q Coulombs, find the strength of the field.
     * @param m The mass.
     * @param theta The angle theta.
     * @param q The charge of the mass.
     * @param print whether or not to print the result
     * @return the strength of the electric field
     */
    static ld electricFieldStrength(ld m, ld theta, ld q, bool print = true);

    /**
     * @brief four equal charges q lie on the corners of a square. A fifth charge COULOMB
     * is on a mass m directly above the center of the square, at a height
     * equal to the length d of one side of the square.
     * Determine the magnitude of q in terms of COULOMB , m , and d ,
     * if the Coulomb force is to equal the weight of m.
     * @param COULOMB The charge of the center point.
     * @param m The mass in center.
     * @param d The length of a side and height of the center.
     * @param print whether or not to print the result
     * @return the charge of the corner points
     */
    static ld magnitudeOfq_termsOf_Q_m_d(ld Q, ld m, ld d, bool print = true);

    /**
     * @brief Calculate the angular velocity Ω of an electron orbiting a proton in
     * the hydrogen atom, given the radius of the orbit is r meters.
     * You may assume that the proton is stationary and the centripetal
     * force is supplied by Coulomb attraction.
     * @param r The radius.
     * @param m The mass electron.
     * @param q The charge of electron.
     * @param print whether or not to print the result
     * @return angular velocity (rad/s)
     */
    static ld angularVelocityOfElectronOrbitingProton(ld r, ld m, ld q, bool print = true);

    /**
     * @brief Point charges of q1C and q2 C are placed l meters apart. Where can a
     * third charge be placed so that the net force on it is zero?
     * @param l The distance between the two particles.
     * @param q1 The charge of particle 1.
     * @param q2 The charge of particle 2.
     * @param print whether or not to print the result
     * @return the distance to place the third particle
     */
    static ld distanceToPlaceThirdChargeToMakeZero(ld l, ld q1, ld q2, bool print = true);

    /**
     * @brief Using the symmetry of the arrangement, determine the direction of the
     * force on q which is in the center of a square with four point charges of
     * equal charges of positive q1 and q2 in top corners and negative q3
     * and q4 in bottom corners, given that qa=qb=+qx4 C and qc=qd=−qx4 C.
     * Calculate the magnitude of the force on the charge q , given that the
     * square is l meters on a side and q=q1 C
     * @param qx4 The charge of the four corners.
     * @param lSide The length of a side.
     * @param q1 The charge in the center point.
     * @param theta the angle.
     * @param print whether or not to print the result
     * @return force on the point q
     */
    static ld magnitudeOfForceOn_q(ld qx4, ld lSide, ld q1, ld theta, bool print = true);

    /**
     * @brief Find the electric field at the location of qa in Figure 18.52 given
     * that qb=qc=qd=+qb C, q=−qm nC, and the square is l cm on a side.
     * @param qb The charge of 3 particles.
     * @param qm The charge on the middle particle.
     * @param l The length of a side.
     * @param print whether or not to print the result
     * @return the electric field force n N/C
     */
    static ld electricFieldAtLocation(ld qb, ld qm, ld l, bool print = true);

    /**
     * @brief Calculate the electric field at the center of the triangle.
     * @param qa The charge of the top point.
     * @param qb The charge of the left point.
     * @param qc The charge of the right point.
     * @param l The length of a side.
     * @param print whether or not to print the result
     * @return the electric field force n N/C
     */
    static std::vector<ld> electricFieldAtCenterTriangle(
            ld qa, ld qb, ld qc, ld l, bool print = true);

    /**
     * @brief A very long straight wire has charge per unit length lambda. At
     * what distance from the wire is the magnitude of the electric field
     * equal to Ef?
     * @param lambda the charge per unit length
     * @param Ef the electric field strength
     * @param print true to print the answer
     * @return the distance
     */
    static constexpr ld distanceFromWireElectricFieldMagnitude(
            ld lambda, ld Ef, bool print = true);

    /**
     * A (l) m length of power line carries a total charge of (q) C
     * distributed uniformly over its length. Find the magnitude of the
     * electric field at (r) m  from the axis of the power line, and not
     * near either end (staying away from the ends means you can approximate
     * the field as that of an infinitely long wire).
     * @param l the length of the power line
     * @param q the total charge
     * @param r the distance from the axis
     * @param print true to print the answer
     * @return the magnitude of the electric field
     */
    static constexpr ld magnitudeOfElectricFieldByWire(
            ld l, ld q, ld r, bool print = true);

    /**
     * @brief A rod l m long and r m in radius carries a Q C charge
     * distributed uniformly over its length. What is the approximate magnitude
     * of the electric field R m from the rod surface, not near either end?
     * @param l the length of the rod     *
     * @param Q the total charge
     * @param r the radius of the rod
     * @param R the distance from the rod surface
     * @param print true to print the answer
     * @return the magnitude of the electric field
     */
    static constexpr ld magnitudeOfElectricFieldByRod(
            ld l, ld Q, ld r, ld R, bool print = true);

    /**
     * @brief Find the magnitude of the electric field due to a charged ring of
     * radius a and total charge Q, at a point on the ring axis a distance a
     * from the ring's center.
     * @param a  the radius of the ring
     * @param Q  the total charge of the ring
     * @param print  true to print the answer
     * @return  the magnitude of the electric field
     */
    static ld electricFieldFromChargedRing(ld a, ld Q, bool print = true);

    /**
     * @brief Find the magnitude of the electric field at a point located at z
     * meters from the center of a charged ring of radius r having a charge Q.
     * @param r  the radius of the ring
     * @param z  the distance from the center of the ring
     * @param Q  the total charge of the ring
     * @param print  true to print the answer
     * @return  the magnitude of the electric field
     */
    static ld electricFieldAtPointFromChargedRing(
            ld r, ld z, ld Q, bool print = true);

    /**
     * A proton moving to the right at V m/s enters a region where a
     * E N/C electric field points to the left. How far will the proton get
     * before its speed reaches zero? Express your answer in meters.
     * @param V the initial speed
     * @param E the electric field
     * @param print true to print the answer
     * @return the distance
     */
    static ld distanceProtonGetsBeforeSpeedZero(ld V, ld E, bool print = true);

    /**
     * The charges are in a uniform electric field whose direction makes an
     * angle theta with the line connecting the charges. What is the
     * magnitude of this field if the torque exerted on the dipole has
     * magnitude t N⋅m  ?
     * @param t the torque
     * @param theta the angle
     * @param p dipole moment
     * @param print true to print the answer
     */
    static ld magnitudeOfElectricField(ld t, ld theta, ld p, bool print = true);

    /**
     * Three identical charges q form an equilateral triangle of side a,
     * with two charges on the x-axis and one on the positive y-axis.
     * Find an expression for the electric field at points on the  y -axis above
     * the uppermost charge.
     * @param q the charge
     * @param a the side length
     * @param y the y coordinate
     * @param print true to print the answer
     * @return the electric field
     */
    static ld electricFieldAtPointOnYAxis(ld q, ld a, ld y, bool print = true);

    /**
     * Four equal charges  Q  are at the corners of a square of side  a .
     * Find the magnitude of the force on each charge.
     * @param Q the charge
     * @param a the side length
     * @param print true to print the answer
     * @return the force
     */
    static ld forceOnEachChargeInSquare(ld Q, ld a, bool print = true);

    /**
     * @brief Calculate the Electric field strength inside a uniformly charged
     * slab of charge with a volume charge density of rho and thickness d.
     * @param rho  the volume charge density
     * @param x  the distance from the center plane of the slab
     * @param print  true to print the answer
     * @return  the electric field strength
     */
    static constexpr ld fieldInsideSlabWithVolumeChargeDensity(
            ld rho, ld x, bool print = true);

    /**
     * @brief Calculates the Electric field strength outside a slab at a
     * distance x from the center plane of the slab.
     * @param rho the volume charge density
     * @param d  the thickness of the slab
     * @param print true to print the answer
     * @return the electric field strength
     */
    static constexpr ld fieldOutsideSlabWithVolumeChargeDensity(
            ld rho, ld d, bool print = true);

    /**
     * brief What surface charge density on an infinite sheet will produce an
     * electric field of E N/C?
     * @param E the electric field
     * @param print true to print the answer
     * @return the surface charge density
     */
    static constexpr ld surfaceChargeDensityFromElectricField(ld E, bool print = true);

    /**
     * @brief Calculate the field charge of a sheet with a surface charge density
     * sigma
     * @param sigma the surface charge density
     * @param print true to print the answer
     * @return the field charge
     */
    static constexpr ld fieldChargeOfSheet(ld sigma, bool print = true);

    /**
     * A total charge of Q C is applied to a thin, square metal plate l m
     * on a side. Calculate the electric field strength near the plates sruface.
     * @param Q the total charge
     * @param l the side length
     * @param print true to print the answer
     * @return the electric field strength
     */
    static constexpr ld electricFieldStrengthNearPlate(
            ld Q, ld l, bool print = true);

    /**
     * @brief Calculate the electric field at the surface of a conductor with
     * surface charge density sigma.
     * @param sigma  the surface charge density
     * @param print  true to print the answer
     * @return  the electric field
     */
    static constexpr ld fieldAtConductorSurface(ld sigma, bool print = true);

    /**
     * @brief Calculate the charge between two point charges of equal
     * magnitude a distance r apart with a repulsive force of F.
     * @param F the force
     * @param r the distance
     * @param print true to print the answer
     * @return the charge
     */
    static ld chargeBetweenPointCharges(ld F, ld r, bool print = true);

    /**
     * @brief Two small spheres spaced r m apart have equal charge. Calculate
     * how many excess electrons must be present on each sphere if the
     * magnitude of the force of repulsion between them is F newtons.
     * @param r is the distance between the spheres in m
     * @param F is the force of repulsion in N
     * @param print prints the result
     * @return  the number of excess electrons
     */
    static ld excessElectrons(ld r, ld F, bool print = true);

    /**
     * @brief The molecule's mol has a dipole moment of p C⋅m. Calculate the
     * separation between the charges if the molecule is consists of two
     * electric charges of ±e.
     * @param p the dipole moment
     * @param print true to print the answer
     */
    static ld separationOfCharges(ld p, bool print = true);

    /**
     * @brief In his famous 1909 experiment that demonstrated quantization of
     * electric charge, R. A. Millikan suspended small oil drops in an
     * electric field. With a field strength of E N/C, calculate the mass
     * of the drop that can be suspended when the drop carries a net charge
     * of n elementary charges.
     * @param E the electric field strength
     * @param n the number of elementary charges
     * @param print true to print the answer
     * @return the mass of the drop
     */
    static ld massOfDropInElectricField(ld E, ld n, bool print = true);

    /**
     * @brief A q1 C charge and a q2 C charge are inside an uncharged
     * sphere. Calculate the the electric flux through the sphere?
     * @param q1 the first charge
     * @param q2 the second charge
     * @param print true to print the answer
     */
    static ld electricFluxThroughSphere(ld q1, ld q2, bool print = true);

    /**
     * @brief Calculate the electric field strength just outside the surface
     * of a conducting sphere carrying surface charge density sigma C/m2?
     * @param sigma the surface charge density
     * @param print true to print the answer
     * @return the electric field strength
     */
    static ld electricFieldStrengthOutsideSphere(ld sigma, bool print = true);

    /**
     * @brief A point charge with charge q1 C is held stationary at the origin.
     * A second point charge with charge q2 C moves from the point P1(x1, y1)
     * to the point P2(x2, y2).
     * Calculate how much work W is done by the electric force on the moving
     * point charge.
     * @param q1 the first charge
     * @param q2 the second charge
     * @param P1 the first point
     * @param P2 the second point
     * @param print true to print the answer
     * @return the work done
     */
    static ld workDoneByElectricForce(
            ld q1, ld q2, const Vector2D& P1, const Vector2D& P2, bool print = true);

    /**
     * @brief Calculate the force between two point charges q1 C and q2 C
     * that are separated by a distance r m.
     * @param q1  the first charge
     * @param q2  the second charge
     * @param r  the distance
     * @param print  true to print the answer
     * @return  the force
     */
    static ld forceBetweenPointCharges(ld q1, ld q2, long double r, bool print);

    /**
     * @brief The potential on the axis of a uniformly charged disk is V volts
     * at a point x m from the disk center. The electric field at the same
     * point is E V/m. The potential on the axis of the uniformly charged disk
     * with radius a is V(x)=(2kQ/a^2)*(√(x^2+a^2)−|x|).
     * Calculate the following:
     * (a) the disk radius.
     * (b) the charge on the disk.
     * @param V the potential
     * @param E the electric field
     * @param x the distance from the center
     * @param print true to print the answer
     * @return the disk radius and charge
     */
    static std::vector<ld> diskRadiusAndCharge(ld V, ld E, ld x, bool print = true);

    /**
     * @brief A solid sphere of radius R carries charge Q distributed uniformly
     * throughout its volume. Find the potential difference from the sphere's
     * surface to its center.
     * @param Q the charge
     * @param R the radius
     * @param print true to print the answer
     */
    static ld potentialDifferenceFromSphere(ld Q, ld R, bool print = true);

    /**
     * @brief Calculate the energy stored in the electric field due to a
     * spherical shell of charge Q C and radius R m.
     * @param Q the charge
     * @param R the radius
     * @param print true to print the answer
     * @return the energy
     */
    static ld energyStoredInElectricField(ld Q, ld R, bool print = true);

    /**
     * @brief The energy stored in the electric field of a spherical shell is
     * approximately E J. Assuming the spherical shell to have a charge
     * of Q C spread uniformly over its surface, estimate its radius to one
     * significant figure.
     * @param E the energy
     * @param Q the charge
     * @param print true to print the answer
     * @return the radius
     */
    static ld sphericalShellRadius(ld E, ld Q, bool print = true);



    ~ElectricCharge()
    {
        countDecrease();
    }

private:
    static void countIncrease() { electricCharge_objectCount += 1; }
    static void countDecrease() { electricCharge_objectCount -= 1; }


};
#endif //PHYSICSFORMULA_ELECTRICCHARGE_H

constexpr ld ElectricCharge::massFromEnergy(const ld E, const ld c, bool print)
{
    ld m = E / (c * c);
    if (print)
        std::cout << "m = " << m << " kg" << std::endl;
    return m;
}

constexpr ld ElectricCharge::massFromEnergy(const ld M, bool print)
{
    ld m = 2.0 * M;
    if (print)
        std::cout << "m = " << m << " kg" << std::endl;
    return m;
}

constexpr ld ElectricCharge::totalElectronMass(const ld Ne, bool print)
{
    ld m = Ne * constants::ELECTRON_MASS;
    if (print)
        std::cout << "m = " << m << " kg" << std::endl;
    return m;
}

constexpr ld ElectricCharge::totalProtonMass(const ld Np, bool print)
{
    ld m = Np * constants::PROTON_MASS;
    if (print)
        std::cout << "m = " << m << " kg" << std::endl;
    return m;
}

constexpr ld ElectricCharge::totalMass(const ld Ne, const ld Np, bool print)
{
    ld m = totalElectronMass(Ne, false) + totalProtonMass(Np, false);
    if (print)
        std::cout << "m = " << m << " kg" << std::endl;
    return m;
}

constexpr ld ElectricCharge::coulombsLaw(
        const ld q1, const ld q2, const ld r, bool print)
{
    auto F = (constants::K * q1 * q2) / (r * r);
    if (print)
        std::cout << "F = " << F << " N" << std::endl;
    return F;
}

constexpr ld ElectricCharge::coulombsLaw(
        ld q1, pair<ld, ld> xy1, ld q2, pair<ld, ld> xy2, int multiplier,
        bool print)
{
    // get the distance between the two points
    auto r = ::distanceBetweenPoints(xy1, xy2) * multiplier;
    auto F = coulombsLaw(q1, q2, r);
    // get the direction of the force
    auto theta = ::directionOfForce(xy1, xy2)*(180.0/M_PI);
    auto unitVector = UnitVector(xy1, xy2);
    if (print) {
        std::cout << "F = " << abs(F) << " N, " << unitVector.toString() <<
        " at angle " << theta << " degrees" << std::endl;
    }
    return F;
}

inline ld ElectricCharge::chargeOfElectrostaticForce_equalPointCharges(
        const ld q, const ld mass, const ld r, bool print)
{
    auto Q = r * (sqrt((mass * constants::Ga) / constants::K));
    if (print)
        std::cout << "q = " << Q << " C" << std::endl;
    return Q;
}

constexpr ld ElectricCharge::electricFieldForce(
        const ld Q, const ld r, bool print)
{
    auto E = (constants::K * Q) / (r * r);
    if (print)
        std::cout << "E = " << E << " N/C" << std::endl;
    return E;
}

constexpr ld ElectricCharge::forceByElectricField(
        const ld q, const ld E, bool print)
{
    auto F = q * E;
    if (print)
        std::cout << "F = " << F << " N" << std::endl;
    return F;
}

ld ElectricCharge::electricFieldZero(ld Qp, ld Qn, ld a, bool print) {
    auto k = constants::K;
    auto Q = constants::ELECTRON_CHARGE;
    auto qN = constants::PROTON_CHARGE * Qp;
    auto E0 = (a*sqrt(2.0))/(sqrt(2)-1);
    if (print)
        std::cout << "E0 = " << E0 << " N/C" << std::endl;
    return E0;
}


constexpr ld ElectricCharge::coulombs(
        const ld baseNumber, const ld su, bool print)
{
    auto C = baseNumber * su * constants::_e;
    if (print)
        std::cout << "C = " << C << " C" << std::endl;
    return C;
}

inline ld ElectricCharge::howManyFewerElectronsThenProtons(
        const ld netCharge, bool print)
{
    auto Ne = (netCharge / abs(constants::ELECTRON_CHARGE));
    if (print)
        std::cout << "Ne = " << Ne << std::endl;
    return Ne;
}

inline ld ElectricCharge::fractionProtonsNoElectrons(
        const ld protons, const ld netCharge, bool print)
{
    const ld temp = howManyFewerElectronsThenProtons(netCharge);
    auto Np = temp / protons;
    if (print)
        std::cout << "Np = " << Np << std::endl;
    return Np;
}

constexpr ld ElectricCharge::forceChangeTwoPointCharges(
        const ld F, const ld factorChange, bool print)
{
    auto F2 = F / (factorChange * factorChange);
    if (print)
        std::cout << "F2 = " << F2 << " N" << std::endl;
    return F2;
}

constexpr ld ElectricCharge::electricField(
        const ld F, const ld q, bool print)
{
    auto E = F / q;
    if (print)
        std::cout << "E = " << E << " N/C" << std::endl;
    return E;
}

ld ElectricCharge::electricFieldFromPointChargeDistribution(
        vector<ld> charges, vector<ld> r_vals, bool print)
{
    ld E = 0.0;
    for (int i = 0; i < charges.size(); i++) {
        E += electricField(charges[i], r_vals[i]);
    }
    return E;
}


constexpr ld ElectricCharge::electricFieldByPointCharge(
        ld q, ld r,  bool print) {
    auto E = (constants::K * q) / (r * r);
    if (print)
        std::cout << "E = " << E << " N/C" << std::endl;
    return E;
}

ld ElectricCharge::forceOnElectron(ld d, ld r1, bool print) {
    auto r2 = d - r1;
    auto e = constants::PROTON_CHARGE;
    auto k = constants::K;
    auto E = k*e*((1.0/(r1*r1)) - (1.0/(r2*r2)));
    cout << "E = " << E << " N/C" << endl;
    auto F = -e*E;
    if (print) {
        std::cout << "F = " << F << " N" << std::endl;
    }
    return F;


}

constexpr ld ElectricCharge::magnitudePointCharge(
        const ld E, const ld r, bool print)
{
    auto Q = ((r * r) * E) / constants::K;
    if (print)
        std::cout << "Q = " << Q << " C" << std::endl;
    return Q;
}

constexpr ld ElectricCharge::charge(const ld F, const ld E, bool print)
{
    auto q = F / E;
    if (print)
        std::cout << "q = " << q << " C" << std::endl;
    return q;
}

inline ld ElectricCharge::separationBetweenPointCharges(
        const ld q1, const ld q2, const ld F, bool print)
{
    auto r = sqrt((constants::K * (q1 * q2)) / F);
    if (print)
        std::cout << "r = " << r << " m" << std::endl;
    return r;
}

constexpr ld ElectricCharge::howManyElectrons(
        const ld totalParticles, const ld netCharge, bool print)
{
    const ld NeMinusNp = netCharge / constants::ELECTRON_CHARGE;
    const ld total     = totalParticles + NeMinusNp;
    const ld Ne        = total / 2.0;
    if (print)
        std::cout << "Ne = " << Ne << std::endl;
    return Ne;
}

inline ld ElectricCharge::minimumChargeToLiftObject(
        const ld r, const ld charge, const ld m, bool print)
{
    auto F = (m * constants::Ga * (r * r)) / (constants::K * charge);
    if (print)
        std::cout << "F = " << F << " N" << std::endl;
    return F;
}

inline ld ElectricCharge::minimumChargeToLiftCar(
        const ld r, const ld l, const ld m, bool print)
{
    auto F = (r + l) * sqrt((m * constants::Ga) / constants::K);
    if (print)
        std::cout << "F = " << F << " N" << std::endl;
    return F;
}

vector<ld> ElectricCharge::superpositionPrinciple(
        ld Qref,
        pair<ld, ld> Qloc,
        const vector<ld>& charges,
        const vector<pair<ld, ld>>& locations,
        bool print)
{

    // get the distance and direction of each force from the reference point
    // to all the other points
    vector<ld> distances;
    for (auto i = 0; i < charges.size(); i++) {
        auto r = ::distanceBetweenPoints(Qloc, locations[i]);
        distances.push_back(r);
    }
    vector<ld> directions;
    for (auto i = 0; i < charges.size(); i++) {
        auto theta = ::directionOfForce(Qloc, locations[i]);
        directions.push_back(theta);
    }
    // add the directions to get the ending direction of the force
    long double final_direction = 0.0;
    for (auto i = 0; i < charges.size(); i++) {
        final_direction += directions[i];
    }
    // get the total force
    ld total_force = 0.0;
    for (auto i = 0; i < charges.size(); i++) {
        total_force += charges[i] * electricField(charges[i], distances[i]);
    }

    if (print) {
        std::cout << "Total force = " << total_force << " N" << std::endl;
        std::cout << "final direction: " << final_direction * (180.0/M_PI) << std::endl;
    }

    return {total_force, final_direction};

}

inline ld ElectricCharge::distanceBetweenPoints(
        const ld q1, const ld q2, const ld F, bool print)
{
    auto r = sqrt((constants::K * (abs(q1) * abs(q2))) / F);
    if (print)
        std::cout << "r = " << r << " m" << std::endl;
    return r;
}

inline ld ElectricCharge::angleVerticalAxis(
        const ld Fe, const ld mass, bool print)
{
    auto theta = atan((Fe / (mass * constants::Ga))) * constants::DEGREE;
    if (print)
        std::cout << "theta = " << theta << " degrees" << std::endl;
    return theta;
}

constexpr ld ElectricCharge::accelerationOfParticles(
        const ld m, const ld r, const ld q1, const ld q2, bool print)
{
    auto a = (constants::K * (q1 * q2)) / (m * (r * r));
    if (print)
        std::cout << "a = " << a << " m/s^2" << std::endl;
    return a;
}

constexpr ld ElectricCharge::electricFieldStrength(const ld d, const ld q_excess, bool print)
{
    auto E =(4.0 * constants::K * q_excess) / (d * d);
    if (print)
        std::cout << "E = " << E << " N/C" << std::endl;
    return E;
}

inline ld ElectricCharge::electricFieldStrength(
        const ld m, const ld theta, const ld q, bool print)
{
    auto E = (m * constants::Ga * tan(theta * constants::RADIAN)) / q;
    if (print)
        std::cout << "E = " << E << " N/C" << std::endl;
    return E;
}

inline ld ElectricCharge::magnitudeOfq_termsOf_Q_m_d(
        const ld Q, const ld m, const ld d, bool print)
{
    auto q =(3.0 * sqrt(6.0) * (d * d) * m * constants::Ga) / (16.0 * constants::K * Q);
    if (print)
        std::cout << "q = " << q << " C" << std::endl;
    return q;
}

inline ld ElectricCharge::angularVelocityOfElectronOrbitingProton(
        const ld r, const ld m, const ld q, bool print)
{
    auto omega = q * sqrt((constants::K) / (m * r));
    if (print)
        std::cout << "omega = " << omega << " rad/s" << std::endl;
    return omega;
}

inline ld ElectricCharge::distanceToPlaceThirdChargeToMakeZero(
        const ld l, const ld q1, const ld q2, bool print)
{
    auto r = (l * sqrt(q2 / q1)) / (1.0 - sqrt(q2 / q1));
    if (print)
        std::cout << "r = " << r << " m" << std::endl;
    return r;
}

inline ld ElectricCharge::magnitudeOfForceOn_q(
        const ld qx4, const ld lSide, const ld q1, const ld theta = 45.0, bool print)
{
    auto F = ((8.0 * constants::K * qx4 * q1) / (lSide * lSide)) *
    sin(theta * constants::RADIAN);
    if (print)
        std::cout << "F = " << F << " N" << std::endl;
    return F;
}

inline ld ElectricCharge::electricFieldAtLocation(
        const ld qb, const ld qm, const ld l, bool print)
{
    auto E = (constants::K / (l * l)) * (sqrt(2) * qb + (qb / 2.0) - 2 * qm);
    if (print)
        std::cout << "E = " << E << " N/C" << std::endl;
    return E;
}

inline std::vector<ld> ElectricCharge::electricFieldAtCenterTriangle(
        const ld qa, const ld qb, const ld qc, const ld l, bool print)
{
    std::vector<ld> results = {0.0, 0.0};
    const ld sr_rthx   = 3.0 * sqrt(3);
    //cout << "3*srty3: " << sr_rthx << endl;
    const ld y = sr_rthx * constants::K;
    //cout << "ktimessqrt3: " << y << endl;
    const ld z = 2 * (l * l);
    //cout << "2timeslength: " << z << endl;
    const ld w = y / z;
    //cout << "topdividedbybottom: " << w << endl;
    const ld j = abs(qb) + abs(qc);
    //cout << "qb+qc: " << j  << endl;
    const ld Ex = w * j;
    //cout << "Ex: " << Ex << endl;
    const ld Ey = ((3.0 * constants::K) / (l * l)) * (-qa - abs((qb / 2)) + abs((qc / 2))
    );
    //cout << "Ey: " << Ey << endl;
    results[0] = sqrt((Ex * Ex) + (Ey * Ey));
    results[1] = atan((Ey / Ex)) * 180 / constants::PI;
    if (print) {
        std::cout << "E = " << results[0] << " N/C" << std::endl;
        std::cout << "theta = " << results[1] << " degrees" << std::endl;
    }
    return results;
}

constexpr ld ElectricCharge::electrons(
        const ld baseNumber, const ld su, bool print)
{
    auto electrons = (baseNumber * su) / constants::ELECTRON_CHARGE;
    if (print)
        std::cout << "electrons = " << electrons << std::endl;
    return electrons;
}

inline ld ElectricCharge::netElectronCount(
        const ld protons, const ld netCharge, bool print)
{
    auto electrons = protons + ((-abs(netCharge)) / constants::PROTON_CHARGE);
    if (print)
        std::cout << "electrons = " << electrons << std::endl;
    return electrons;
}

constexpr ld ElectricCharge::dipoleMoment(ld q, ld d, bool print) {
    auto mu = q * d;
    if (print)
        std::cout << "Dipole moment = " << mu << " Cm" << std::endl;
    return mu;
}

constexpr ld ElectricCharge::dipoleFieldPerpendicularBisector(
        ld p, ld y, bool print) {
    auto E = -(constants::K * p) / abs(y*y*y);
    if (print)
        std::cout << "E = " << E << " N/C" << std::endl;
    return E;
}

constexpr ld ElectricCharge::dipoleFieldForXAxis(ld p, ld x, bool print) {
    auto E = (2.0 * constants::K * p) / abs(x*x*x);
    if (print)
        std::cout << "E = " << E << " N/C" << std::endl;
    return E;
}

constexpr ld ElectricCharge::totalElectrons(ld q, bool print) {
    auto electrons = abs(q / constants::ELECTRON_CHARGE);
    if (print)
        std::cout << "electrons = " << electrons << std::endl;
    return electrons;
}

constexpr ld ElectricCharge::electricFlux(ld E, ld A, ld theta, bool print) {
    auto phi = E * A * cos(theta*constants::RADIAN);
    if (print)
        std::cout << "Electric flux = " << phi << " Nm/C" << std::endl;
    return phi;
}

constexpr ld ElectricCharge::electricFluxSphere(ld q, bool print) {
    auto phi = q / constants::_e0;
    if (print)
        std::cout << "Electric flux = " << phi << " Nm/C" << std::endl;
    return phi;
}

constexpr ld
ElectricCharge::fieldOutsideSphericalChargeDistribution(ld Q, ld r, bool print) {
    auto E = Q / (4.0 * constants::PI * (r * r) * constants::_e0);
    if (print) {
        std::cout << "Field outside spherical charge distribution = "
        << E << " N/C" << std::endl;
    }
    return E;
}

constexpr ld ElectricCharge::fieldOfALineCharge(ld lambda, ld r, bool print) {
    auto E = lambda / (2.0 * constants::PI * r * constants::_e0);
    if (print)
        std::cout << "Field of a line charge = " << E << " N/C" << std::endl;
    return E;
}

constexpr ld
ElectricCharge::electricFluxDisc(ld E, ld R, ld theta, bool print) {
    auto phi = E * constants::PI * (R*R) * cos(theta*constants::RADIAN);
    if (print)
        std::cout << "Electric flux = " << phi << " Nm/C" << std::endl;
    return phi;
}

constexpr ld
ElectricCharge::distanceFromWireElectricFieldMagnitude(ld lambda,
                                                       ld Ef,
                                                       bool print) {
    auto e0 = constants::_e0;
    auto r = lambda / (2.0 * constants::PI * e0 * Ef);
    if (print)
        std::cout << "Distance from wire = " << r << " m" << std::endl;
    return r;
}

ld ElectricCharge::electricFieldFromChargedRing(ld a, ld Q, bool print) {
    auto k = constants::K;

    auto E = (k * Q) / (2.0* sqrt(2.0) * a * a);
    if (print)
        std::cout << "Electric field = " << E << " V/m" << std::endl;
    return E;
}

ld ElectricCharge::electricFieldAtPointFromChargedRing(ld r, ld z, ld Q,
                                                    bool print) {
    auto k = constants::K;
    auto E = (k * Q) / pow(((r * r) + (z * z)), 3.0/2.0);
    if (print)
        std::cout << "Electric field = " << E << " V/m" << std::endl;
    return E;
}

ld ElectricCharge::netForceOnChargeFromOtherCharges(ld q0, pair<ld, ld> q0Loc,
                                                    vector<ld> charges,
                                                    vector<pair<ld, ld>> chargeLocs,
                                                    bool print) {
    auto k = constants::K;
    vector<ld> forces;
    for (int i = 0; i < charges.size(); i++) {
        auto q = charges[i];
        auto x = chargeLocs[i].first;
        auto y = chargeLocs[i].second;
        auto r = sqrt(pow((q0Loc.first - x), 2.0) + pow((q0Loc.second - y), 2.0));
        auto F = (k * q0 * q) / (r * r);
        forces.push_back(F);
    }
    auto netForce = accumulate(forces.begin(), forces.end(), 0.0);
    if (print) {
        std::cout << "Net force = " << netForce << " N" << std::endl;
    }
    return netForce;
}

ld ElectricCharge::distanceProtonGetsBeforeSpeedZero(ld V, ld E, bool print) {
    auto m = constants::PROTON_MASS;
    auto q = constants::PROTON_CHARGE;
    auto r = (m * (V * V)) / (2.0 * q * E);
    if (print)
        std::cout << "Distance = " << r << " m" << std::endl;
    return r;
}

ld ElectricCharge::magnitudeOfElectricField(ld t, ld theta, ld p, bool print) {
    auto E = t / (p * sin(theta*constants::RADIAN));
    if (print)
        std::cout << "Electric field = " << E << " N/C" << std::endl;
    return E;
}

constexpr ld
ElectricCharge::magnitudeOfElectricFieldByWire(ld l, ld q, ld r, bool print) {
    auto lamda = q / l;
    auto k = constants::K;
    auto E = (2.0 * k * lamda) / r;
    if (print)
        std::cout << "Electric field = " << E << " N/C" << std::endl;
    return E;
}

constexpr ld
ElectricCharge::magnitudeOfElectricFieldByRod(
        ld l, ld Q, ld r, ld R, bool print) {
    auto lambda = Q / l;
    auto d = R + r;
    auto k = constants::K;
    auto E = (2.0 * k * lambda) / d;
    if (print)
        std::cout << "Electric field = " << E << " N/C" << std::endl;
    return E;
}

ld ElectricCharge::electricFieldAtPointOnYAxis(ld q, ld a, ld y, bool print) {
    auto k = constants::K;
    auto E = (4.0 * k * q) / (pow((2.0 * y - a * sqrt(3.0)), 2.0) + (4.0 * y) /
            pow((4.0 * y * y + a * a), 3.0/2.0));
    if (print)
        std::cout << "Electric field = " << E << " N/C" << std::endl;
    return E;
}

ld ElectricCharge::forceOnEachChargeInSquare(ld Q, ld a, bool print) {
    auto k = constants::K;
    auto F = ((k * Q * Q) / (2.0 * a * a))*(2.0*sqrt(2.0) + 1.0);
    if (print)
        std::cout << "Force = " << F << " N" << std::endl;
    return F;
}

ld ElectricCharge::electricFlux(Vector3D E, Vector3D A, bool print) {
    auto phi = E.dot(A);
    if (print)
        std::cout << "Electric flux = " << phi << " Nm/C" << std::endl;
    return phi;
}

constexpr ld ElectricCharge::electricFluxSphere(ld E, ld r, bool print) {
    auto phi = 4.0 * constants::PI * E * r * r;
    if (print)
        std::cout << "Electric flux = " << phi << " Nm/C" << std::endl;
    return phi;
}

constexpr ld ElectricCharge::fieldInsideSphericalChargeDistribution(ld Qr, ld R,
                                                                    bool print) {
    auto epsilon0 = constants::_e0;
    auto E = (Qr / (4.0 * constants::PI * epsilon0 * (R * R * R)));
    if (print)
        std::cout << "Electric field = " << E << " N/C" << std::endl;
    return E;
}

constexpr ld ElectricCharge::linearChargeDensity(ld q, ld L, bool print) {
    auto lamda = q / L;
    if (print)
        std::cout << "Line charge density = " << lamda << " C/m" << std::endl;
    return lamda;
}

constexpr ld ElectricCharge::surfaceChargeDensity(ld Q, ld A, bool print) {
    auto sigma = Q / A;
    if (print)
        std::cout << "Surface charge density = " << sigma << " C/m^2" << std::endl;
    return sigma;
}

constexpr ld ElectricCharge::surfaceChargeDensity(ld E, bool print) {
    auto e = constants::ELECTRON_CHARGE;
    auto sigma = (E * 2.0 * constants::_e0) / e;
    if (print)
        std::cout << "Surface charge density = " << sigma << " C/m^2" << std::endl;
    return sigma;
}

constexpr ld ElectricCharge::volumeChargeDensity(ld Q, ld V, bool print) {
    auto rho = Q / V;
    if (print)
        std::cout << "Volume charge density = " << rho << " C/m^3" << std::endl;
    return rho;
}

constexpr ld ElectricCharge::volumeChargeDensitySphere(ld Q, ld r, bool print) {
    auto V = (4.0 * constants::PI * r * r * r) / 3.0;
    auto rho = Q / V;
    if (print)
        std::cout << "Volume charge density = " << rho << " C/m^3" << std::endl;
    return rho;
}
constexpr ld
ElectricCharge::volumeChargeDensityCylinder(ld Q, ld r, ld l, bool print) {
    auto V = constants::PI * r * r * l;
    auto rho = Q / V;
    if (print)
        std::cout << "Volume charge density = " << rho << " C/m^3" << std::endl;
    return rho;
}

constexpr ld
ElectricCharge::surfaceChargeDensityFromElectricField(ld E, bool print) {
    auto sigma = E * 2.0 * constants::_e0;
    if (print)
        std::cout << "Surface charge density = " << sigma << " C/m^2" << std::endl;
    return sigma;
}

constexpr ld ElectricCharge::fieldOfLineCharge(ld q, ld l, ld r, bool print) {
    auto epsilon0 = constants::_e0;
    auto E = (q / (2.0 * constants::PI * epsilon0 * r * l));
    if (print)
        std::cout << "Electric field = " << E << " N/C" << std::endl;
    return E;
}

constexpr ld ElectricCharge::fieldChargeOfSheet(ld sigma, bool print) {
    auto epsilon0 = constants::_e0;
    auto E = sigma / ( 2.0 * epsilon0);
    if (print)
        std::cout << "Electric field = " << E << " N/C" << std::endl;
    return E;
}

constexpr ld ElectricCharge::fieldAtConductorSurface(ld sigma, bool print) {
    auto epsilon0 = constants::_e0;
    auto E = sigma / epsilon0;
    if (print)
        std::cout << "Electric field = " << E << " N/C" << std::endl;
    return E;
}

constexpr ld ElectricCharge::gaussSphericalSymmetry(ld Q, ld A, bool print) {
    auto E = fieldInsideSphericalChargeDistribution(Q, A, false);
    if (print)
        std::cout << "Electric field = " << E << " N/C" << std::endl;
    return E;
}

constexpr ld
ElectricCharge::fluxThroughHalfCylinder(ld E, ld r, ld l, bool print) {
    auto A = 2.0 * r * l;
    auto phi = E * A;
    if (print) {
        std::cout << "Electric flux = " << phi << " Nm^2/C" <<
        std::endl;
    }
    return phi;
}

constexpr ld
ElectricCharge::electricFieldStrengthNearPlate(ld Q, ld l, bool print) {
    auto A = l * l;
    auto sigma = Q / A;
    auto E = fieldChargeOfSheet(sigma, false);
    if (print)
        std::cout << "Electric field = " << E << " N/C" << std::endl;
    return E;
}

constexpr ld
ElectricCharge::fieldInsideSlabWithVolumeChargeDensity(ld rho, ld x, bool print) {
    auto e0 = constants::_e0;
    auto E = (rho * x) / (e0);
    if (print)
        std::cout << "Electric field = " << E << " N/C" << std::endl;
    return E;
}

constexpr ld
ElectricCharge::fieldOutsideSlabWithVolumeChargeDensity(
        ld rho, ld d, bool print) {
    auto e0 = constants::_e0;
    auto E = (rho * d) / (2.0 * e0);
    if (print)
        std::cout << "Electric field = " << E << " N/C" << std::endl;
    return E;
}

constexpr ld
ElectricCharge::surfaceChargeDensitySphere(ld Q, ld r, bool print) {
    auto A = 4.0 * constants::PI * r * r;
    auto sigma = Q / A;
    if (print) {
        std::cout << "Surface charge density = " << sigma << " C/m^2" <<
        std::endl;
    }
    return sigma;
}

ld ElectricCharge::chargeBetweenPointCharges(ld F, ld r, bool print) {
    auto k = constants::K;
    auto q = sqrt((F * (r*r)) / k);
    if (print)
        std::cout << "Charge = " << q << " C" << std::endl;
    return q;
}

ld ElectricCharge::excessElectrons(ld r, ld F, bool print) {
    auto q = chargeBetweenPointCharges(F, r, false);
    cout << "q = " << q << endl;
    auto n = ceil(abs(q / constants::ELECTRON_CHARGE));
    if (print)
        std::cout << "Number of excess electrons = " << n << std::endl;
    return n;
}

ld ElectricCharge::separationOfCharges(ld p, bool print) {
    auto e = constants::_e;
    auto r = p / e;
    if (print)
        std::cout << "Separation = " << r << " m" << std::endl;
    return r;
}

ld ElectricCharge::massOfDropInElectricField(ld E, ld n, bool print) {
    auto m = (E * n * constants::_e) / constants::Ga;
    if (print)
        std::cout << "Mass = " << m << " kg" << std::endl;
    return m;
}

ld ElectricCharge::electricFluxThroughSphere(ld q1, ld q2, bool print) {
    auto e0 = constants::_e0;
    auto phi = (q1 + q2) / e0;
    if (print)
        std::cout << "Electric flux = " << phi << " Nm^2/C" << std::endl;
    return phi;
}

ld ElectricCharge::electricFieldStrengthOutsideSphere(ld sigma, bool print)
{
    auto e0 = constants::_e0;
    auto E = sigma / e0;
    if (print)
        std::cout << "Electric field = " << E << " N/C" << std::endl;
    return E;
}

ld ElectricCharge::workDoneByElectricForce(
        ld q1, ld q2, const Vector2D& P1, const Vector2D& P2, bool print)
{
    auto r1 = P1.getMag();
    auto r2 = P2.getMag();
    auto k = constants::K;
    auto W = (k * q1 * q2) * (1.0 / r1 - 1.0 / r2);
    if (print)
        std::cout << "Work done = " << W << " J" << std::endl;
    return W;
}

ld ElectricCharge::forceBetweenPointCharges(
        ld q1, ld q2, long double r, bool print) {
    auto k = constants::K;
    auto F = (k * q1 * q2) / (r * r);
    if (print)
        std::cout << "Force = " << F << " N" << std::endl;
    return F;
}

std::vector<ld>
ElectricCharge::diskRadiusAndCharge(ld V, ld E, ld x, bool print) {
    auto k = constants::K;
    auto a = sqrt(((V * V)/(E * E)) - (x * x));
    auto q = ((a * a) * V) / (2.0 * k * (sqrt(x * x + a * a) - abs(x)));

    if (print) {
        std::cout << "Radius = " << a << " m" << std::endl;
        std::cout << "Charge = " << q << " C" << std::endl;
    }
    return {a, q};
}

ld ElectricCharge::potentialDifferenceFromSphere(ld Q, ld R, bool print) {
    auto k = constants::K;
    auto V = - (k * Q) / (2.0 * R);
    if (print)
        std::cout << "Potential difference = " << V << " V" << std::endl;
    return V;
}

ld ElectricCharge::energyStoredInElectricField(ld Q, ld R, bool print) {
    auto k = constants::K;
    auto U = (k * Q * Q) / (2.0 * R);
    if (print)
        std::cout << "Energy stored = " << U << " J" << std::endl;
    return U;
}

ld ElectricCharge::sphericalShellRadius(ld E, ld Q, bool print) {
    auto k = constants::K;
    auto r = (k * Q * Q) / (2.0 * E);
    if (print)
        std::cout << "Radius = " << r << " m" << std::endl;
    return r;
}
