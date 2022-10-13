//
// Created by Ryan.Zurrin001 on 12/15/2021.
//

#ifndef PHYSICSFORMULA_ELECTRICCHARGE_H
#define PHYSICSFORMULA_ELECTRICCHARGE_H
/**
 * @class ElectricCharge
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @dateBuilt  12/31/2020
 * @lastEdit 2/8/2021
 */
#include <iostream>
#include <vector>
#include "UnitVector.h"
#include "Vector3D.h"
typedef long double ld;

static int electricCharge_objectCount = 0;


constexpr ld distanceBetweenPoints(const pair<ld, ld>& p1, const pair<ld, ld>&
        p2)
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
    ld refVal;
    const ld YOTTA = pow(10, 24);  //10^24
    const ld ZETTA = pow(10, 21);  //10^21
    const ld EXA   = pow(10, 18);  //10^18
    const ld PETA  = pow(10, 15);  //10^15
    const ld TERA  = pow(10, 12);  //10^12
    const ld GIGA  = pow(10, 9);   //10^9
    const ld MEGA  = pow(10, 6);   //10^6
    const ld KILO  = pow(10, 3);   //10^3
    const ld HECTO = pow(10, 2);   //10^2
    const ld DECA  = pow(10, 1);   //10^1
    const ld DECI  = pow(10, -1);  //10^-1
    const ld CENTI = pow(10, -2);  //10^-2
    const ld MILLA = pow(10, -3);  //10^-3
    const ld MICRO = pow(10, -6);  //10^-6
    const ld NANO  = pow(10, -9);  //10^-9
    const ld PICO  = pow(10, -12); //10^-12
    const ld FEMTO = pow(10, -15); //10^-15
    const ld ATTO  = pow(10, -18); //10^-18
    const ld ZEPTO = pow(10, -21); //10^-21
    const ld YOCTO = pow(10, -24); //10^-24

} SU;



class ElectricCharge
{
public:
    ElectricCharge()
    {
        _electricChargeVal = 0.0;
        countIncrease();
    }

    explicit ElectricCharge(ld val)
    {
        _electricChargeVal = 0.0;
        countIncrease();
    }

    /**
     * @brief copy constructor
     */
    ElectricCharge(const ElectricCharge& t)
    {
        _electricChargeVal = t._electricChargeVal;
        countIncrease();
    }

    /**
     * #brief move constructor
     */
    ElectricCharge(ElectricCharge&& t) noexcept
    {
        _electricChargeVal = t._electricChargeVal;
        countIncrease();
    }

    /**
     * @brief copy assignment operator
     */
    ElectricCharge& operator=(const ElectricCharge& t)
    {
        if (this != &t)
        {
            _electricChargeVal = t._electricChargeVal;
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

    /// <summary>
    /// Crates mass from energy.
    /// </summary>
    /// <param name="E">The energy.</param>
    /// <param name="c">The c.</param>
    /// <returns>energy</returns>
    static constexpr ld massFromEnergy(ld E, ld c);
    /// <summary>
    /// Masses from energy.
    /// </summary>
    /// <param name="M">The electrons mass.</param>
    /// <returns>energy</returns>
    static constexpr ld massFromEnergy(ld M);

    /// <summary>
    /// Totals the electron mass.
    /// </summary>
    /// <param name="Ne">The total electrons.</param>
    /// <returns>mass of electrons in kg</returns>
    static constexpr ld totalElectronMass(ld Ne);

    /// <summary>
    /// Totals the proton mass.
    /// </summary>
    /// <param name="Np">The total protons.</param>
    /// <returns>mass of protons in kg</returns>
    static constexpr ld totalProtonMass(ld Np);

    /// <summary>
    /// Totals the mass.
    /// </summary>
    /// <param name="Ne">The total electrons.</param>
    /// <param name="Np">The total protons.</param>
    /// <returns>the total mass of protons and electrons</returns>
    static constexpr ld totalMass(ld Ne, ld Np);

    /// <summary>
    /// Calculates the magnitude of force between two electrostatic forces
    /// q1 and q2 using coulomb's law.
    /// </summary>
    /// <param name="q1">The charge of first particle.</param>
    /// <param name="q2">The charge of second particle.</param>
    /// <param name="r">The distance between the charges.</param>
    /// <returns></returns>
    static constexpr ld coulombsLaw(ld q1, ld q2, ld r,
                                    bool print = false);


    static constexpr ld coulombsLaw(ld q1, pair<ld, ld> xy1, ld q2, pair<ld, ld> xy2,
                                    int multiplier = 1, bool print = false);
    /// <summary>
    /// electric dipole moment is defined as the product of the charge q and
    // the separation d between the two charges making up the dipole.
    /// </summary>
    /// <param name="q">The charge.</param>
    /// <param name="d">The separation.</param>
    /// <returns>the electric dipole moment</returns>
    static constexpr ld dipoleMoment(ld q, ld d, bool print = false);

    /// <summary>
    /// dipole field for |y|  >> a, on perpendicular bisector.
    /// </summary>
    /// <param name="p">The dipole moment.</param>
    /// <param name="y">The y axis.</param>
    /// <returns>the electric dipole field</returns>
    static constexpr ld dipoleFieldPerpendicularBisector(ld p, ld y);

    /// <summary>
    /// dipole field for |x| >> a, on axis
    /// </summary>
    /// <param name="p">The dipole moment.</param>
    /// <param name="x">The x axis.</param>
    static constexpr ld dipoleFieldForXaxis(ld p, ld x);


    /// <summary>
    /// Charges the of electrostatic force equal point charges.
    /// </summary>
    /// <param name="q">The q.</param>
    /// <param name="mass">The mass.</param>
    /// <param name="r">The r.</param>
    /// <returns></returns>
    static ld chargeOfElectrostaticForce_equalPointCharges(ld q, ld mass, ld r);

    /// <summary>
    /// Electrics the field e.
    /// </summary>
    /// <param name="COULOMB">The q.</param>
    /// <param name="r">The r.</param>
    /// <returns></returns>
    static constexpr ld electricFieldForce(ld Q, ld r, bool print = false);

    /// <summary>
    /// calculates the force by an electric field and current
    /// </summary>
    /// <param name="q">The current.</param>
    /// <param name="E">The electric field strength.</param>
    /// <returns></returns>
    static constexpr ld forceByElectricField(ld q, ld E, bool print = false);

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

    /// <summary>
    ///  Calculates the  electrons needed to form a charge of baseNumber to the
    ///  su power.
    /// </summary>
    /// <param name="baseNumber">The base number.</param>
    /// <param name="su">The scientific notation multiple.</param>
    /// <returns>number of electrons</returns>
    static constexpr ld electrons(ld baseNumber, ld su);

    /// <summary>
    /// Electrons the count.
    /// </summary>
    /// <param name="protons">The protons.</param>
    /// <param name="netCharge">The net charge.</param>
    /// <returns></returns>
    static ld netElectronCount(ld protons, ld netCharge);

    static constexpr ld totalElectrons(ld q);

    /// <summary>
    /// Coulombs the specified base number.
    /// </summary>
    /// <param name="baseNumber">The base number.</param>
    /// <param name="su">The su.</param>
    /// <returns></returns>
    static constexpr ld coulombs(ld baseNumber, ld su);

    /// <summary>
    /// Hows the many fewer electrons then protons.
    /// </summary>
    /// <param name="netCharge">The net charge.</param>
    /// <returns></returns>
    static ld howManyFewerElectronsThenProtons(ld netCharge);

    /// <summary>
    /// Fractions the protons no electrons.
    /// </summary>
    /// <param name="protons">The protons.</param>
    /// <param name="netCharge">The net charge.</param>
    /// <returns></returns>
    static ld fractionProtonsNoElectrons(ld protons, ld netCharge);

    /// <summary>
    /// Forces the change two point charges.
    /// </summary>
    /// <param name="F">The f.</param>
    /// <param name="factorChange">The factor change.</param>
    /// <returns></returns>
    static constexpr ld forceChangeTwoPointCharges(ld F, ld factorChange);

    /// <summary>
    /// Electrics the field.
    /// </summary>
    /// <param name="F">The force.</param>
    /// <param name="q">The charge.</param>
    /// <returns></returns>
    static constexpr ld electricField(ld F, ld q);

    static ld electricFieldFromPointChargeDistribution(
            vector<ld> charges, vector<ld> r_vals);

    /// <summary>
    /// Electric field caused by point charges.
    /// </summary>
    /// <param name="q">The charge.</param>
    /// <param name="r">The r.</param>
    static constexpr ld electricFieldByPointCharge(ld q, ld r, bool print = false);

    /**
     * Two protons are d nm apart. Find the electric field at a point between
     * them, r1 nm from one of the protons. Then find the force on an electron
     * at this point.
     * @param d the distance between the two protons
     * @param r1 the distance from one of the protons
     * @return the force on an electron at this point
     */
    static ld forceOnElectron(ld d, ld r1, bool print = false);

    /// <summary>
    /// Calculates the magnitude of a point charge that creates a electric field
    /// force of F,  at a distance of r meters.
    /// </summary>
    /// <param name="E">The force of the electric field in N/C.</param>
    /// <param name="r">The distance it causes this force.</param>
    /// <returns>magnitude of the point charge (C)</returns>
    static constexpr ld magnitudePointCharge(ld E, ld r, bool print = false);

    /// <summary>
    /// Calculates the charge of a point particle having a force of F acting on
    /// it with a electric field strength of E at its location.
    /// </summary>
    /// <param name="F">The force acting on a charge.</param>
    /// <param name="E">The electric field strength.</param>
    /// <returns></returns>
    static constexpr ld charge(ld F, ld E);

    /**
     * Calculates the electric flux (number of field lines per unit area)
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
    static constexpr ld electricFlux(ld E, ld A, ld theta, bool print = false);

    /**
     * Calculates the electric flux (number of field lines per unit area)
     * @param E  the electric field strength Vector
     * @param A  The Unit area Vector
     * @param print  print the result
     * @return  the electric flux
     */
    static ld electricFlux(Vector3D E, Vector3D A, bool print = false);

    static constexpr ld electricFluxDisc(ld E, ld R, ld theta, bool print = false);

    /**
     * Calculates he static electric field generated by a distribution of
     * electric charges
     * @param q the charge over an area
     * @return the static electric field strength
     */
    static constexpr ld electricFluxSphere(ld q);

    /**
     * @brief Calculates the elextric flux of a charged sphere of radius r,
     * with and
     * @param E the electric field strength
     * @param r the radius of the sphere
     * @param print whether or not to print the result
     * @return the electric flux
     */
    static constexpr ld electricFluxSphere(ld E, ld r, bool print = false);

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
     * Calculates the electric field strength caused by a distribution of
     * electric charges over a spherical surface using Gauss's law.
     * @param Q the charge over an area
     * @param r the radius of the sphere
     * @return  the electric field strength
     */
    static constexpr ld fieldOutsideSphericalChargeDistribution(
            ld Q, ld r, bool print = false);

    /**
     * @brief Calculates the filed inside a uniformly charged sphere using
     * Gauss's law.
     * @param Qr the charge over an area
     * @param R the radius of the sphere
     * @param print whether or not to print the result
     * @return the electric field strength
     */
    static constexpr ld fieldInsideSphericalChargeDistribution(
            ld Qr, ld R, bool print = false);

    static constexpr ld gaussSphericalSymmetry(ld Q, ld A, bool print = false);

    /**
     * Calculates the electric field of a distribution of electric charges over a
     * symmetric line of length infinity.
     * @param lambda line charge density
     * @param r  the radius of the line
     * @return  the electric field strength
     */
    static constexpr ld fieldOfALineCharge(ld lambda, ld r, bool print = false);

    /**
     * @brief Calculates the electric field of a distribution of electric charges
     * over a symmetric line of length l having a radius of r and a charge of q.
     * @param q the charge over an area
     * @param l the length of the line
     * @param r the radius of the line
     * @param print whether or not to print the result
     * @return the electric field strength
     */
    static constexpr ld fieldOfLineCharge(ld q, ld l, ld r, bool print = false);

    /**
     * @brief Calculates the line charge density (lambda) of a uniformly charged
     * line of length infinity.
     * @param q  the charge over an area
     * @param L  the length of the line
     * @param print  whether or not to print the result
     * @return  the line charge density
     */
    static constexpr ld lineChargeDensity(ld q, ld L, bool print = false);


    /// <summary>
    /// Separations the between point charges.
    /// </summary>
    /// <param name="q1">point charge 1.</param>
    /// <param name="q2">point charge 2.</param>
    /// <param name="F">The Force in Newtons.</param>
    /// <returns></returns>
    static ld separationBetweenPointCharges(ld q1, ld q2, ld F);

    /// <summary>
    /// Hows the many electrons.
    /// </summary>
    /// <param name="totalParticles">The total particles.</param>
    /// <param name="netCharge">The net charge.</param>
    /// <returns></returns>
    static constexpr ld howManyElectrons(ld totalParticles, ld netCharge);

    /// <summary>
    /// Minimums the charge to lift object.
    /// </summary>
    /// <param name="r">The radius.</param>
    /// <param name="charge">The charge.</param>
    /// <param name="m">The mass.</param>
    /// <returns></returns>
    static ld minimumChargeToLiftObject(ld r, ld charge, ld m);

    /// <summary>
    /// A wrecking yard inventor wants to pick up cars by charging a ball
    /// of radius r (d/2) by inducing an equal and opposite charge on the car.
    /// If a car has a mass of m kg and the ball is to be able to lift it from
    /// a distance of l meters away, What minimum charge must be used?
    /// </summary>
    /// <param name="r">The radius of bass.</param>
    /// <param name="l">The length of initial lift .</param>
    /// <param name="m">The mass.</param>
    /// <returns>the minimum charge needed in C</returns>
    static ld minimumChargeToLiftCar(ld r, ld l, ld m);

    static ld netForceOnChargeFromOtherCharges(ld q0, pair<ld, ld> q0Loc,
                                               vector<ld> charges,
                                               vector<pair<ld, ld>>
                                               chargeLocs,
                                               bool print = false);

    /// <summary>
    /// Superposition principle. Adding charges up.
    /// </summary>
    /// <param name="Qref">The refrence charge to find the total charge.</param>
    /// <param name="Qloc"> the pair of coordinates of the charge.</param>
    /// <param name="charges">a vector of charges</param>
    /// <param name="locations">a vector of pairs for each of the charges coordinates.</param>
    /// <returns>net charge vector</returns>
    static vector<ld> superpositionPrinciple(
            ld Qref,
            pair<ld, ld> Qloc,
            const vector<ld>& charges,
            const vector<pair<ld, ld>>& locations,
            bool print = false);

    /// <summary>
    /// Distance between points.
    /// </summary>
    /// <param name="q1">The q1.</param>
    /// <param name="q2">The q2.</param>
    /// <param name="F">The f.</param>
    /// <returns></returns>
    static ld distanceBetweenPoints(ld q1, ld q2, ld F);

    /// <summary>
    /// Angles the vertical axis.
    /// </summary>
    /// <param name="Fe">The force of the electric field.</param>
    /// <param name="mass">The mass.</param>
    /// <returns></returns>
    static ld angleVerticalAxis(ld Fe, ld mass);

    /// <summary>
    /// Two raindrops with equal masses of m are in a thunderhead r meters apart
    /// when they each acquire charges of q1 and q2. Find their acceleration.
    /// </summary>
    /// <param name="m">The mass.</param>
    /// <param name="r">The distance between particles.</param>
    /// <param name="q1">The charge on particle 1.</param>
    /// <param name="q2">The charge on particle 2.</param>
    /// <returns>acceleration in m/s^2</returns>
    static constexpr ld accelerationOfParticles(ld m, ld r, ld q1, ld q2);

    /// <summary>
    /// Calculate the electric field strength near a conducting sphere with a
    /// d diameter of d meters that has q_excess amount of excess charge on it.
    /// </summary>
    /// <param name="d">The diameter.</param>
    /// <param name="q_excess">The excess charge.</param>
    /// <returns>Electric field strength</returns>
    static constexpr ld electricFieldStrength(ld d, ld q_excess);

    /// <summary>
    /// A charged insulating ball of mass m hangs on a long string with a length
    /// that don't matter, in a uniform horizontal electric field.
    /// Given the charge on the ball is q Coulombs, find the strength of the field.
    /// </summary>
    /// <param name="m">The mass.</param>
    /// <param name="theta">The angle theta.</param>
    /// <param name="q">The charge of the mass.</param>
    /// <returns>the strength of the electric field</returns>
    static ld electricFieldStrength(ld m, ld theta, ld q);

    /// <summary>
    /// four equal charges q lie on the corners of a square. A fifth charge COULOMB
    /// is on a mass m directly above the center of the square, at a height
    /// equal to the length d of one side of the square.
    /// Determine the magnitude of q in terms of COULOMB , m , and d ,
    /// if the Coulomb force is to equal the weight of m.
    /// </summary>
    /// <param name="COULOMB">The charge of the center point.</param>
    /// <param name="m">The mass in center.</param>
    /// <param name="d">The length of a side and height of the center.</param>
    /// <returns>the charge of the corner points </returns>
    static ld magnitudeOfq_termsOf_Q_m_d(ld Q, ld m, ld d);

    /// <summary>
    /// Calculate the angular velocity Ω of an electron orbiting a proton in
    /// the hydrogen atom, given the radius of the orbit is r meters.
    /// You may assume that the proton is stationary and the centripetal
    /// force is supplied by Coulomb attraction.
    /// </summary>
    /// <param name="r">The radius.</param>
    /// <param name="m">The mass electron.</param>
    /// <param name="q">The charge of electron.</param>
    /// <returns>angular velocity (rad/s)</returns>
    static ld angularVelocityOfElectronOrbitingProton(ld r, ld m, ld q);

    /// <summary>
    /// Point charges of q1C and q2 C are placed l meters apart. Where can a
    /// third charge be placed so that the net force on it is zero?
    /// </summary>
    /// <param name="l">The distance between the two particles.</param>
    /// <param name="q1">The charge of particle 1.</param>
    /// <param name="q2">The charge of particle 2.</param>
    /// <returns>the distance to place the third particle</returns>
    static ld distanceToPlaceThirdChargeToMakeZero(ld l, ld q1, ld q2);

    /// <summary>
    /// Using the symmetry of the arrangement, determine the direction of the
    /// force on q which is in the center of a square with four point charges of
    /// equal charges of positive q1 and q2 in top corners and negative q3
    /// and q4 in bottom corners, given that qa=qb=+qx4 C and qc=qd=−qx4 C.
    /// Calculate the magnitude of the force on the charge q , given that the
    /// square is l meters on a side and q=q1 C
    /// </summary>
    /// <param name="qx4">The charge of the four corners.</param>
    /// <param name="lSide">The length of a side.</param>
    /// <param name="q1">The charge in the center point.</param>
    /// <param name="theta">the angle.</param>
    /// <returns>force on the point q</returns>
    static ld magnitudeOfForceOn_q(ld qx4, ld lSide, ld q1, ld theta);

    /// <summary>
    /// Find the electric field at the location of qa in Figure 18.52 given
    /// that qb=qc=qd=+qb C, q=−qm nC, and the square is l cm on a side.
    /// </summary>
    /// <param name="qb">The charge of 3 particles.</param>
    /// <param name="qm">The charge on the middle particle.</param>
    /// <param name="l">The length of a side.</param>
    /// <returns>the electric field force n N/C</returns>
    static ld electricFieldAtLocation(ld qb, ld qm, ld l);

    /// <summary>
    /// Electrics the field at center triangle.
    /// </summary>
    /// <param name="qa">The qa.</param>
    /// <param name="qb">The qb.</param>
    /// <param name="qc">The qc.</param>
    /// <param name="l">The l.</param>
    /// <returns></returns>
    static std::vector<ld> electricFieldAtCenterTriangle(
            ld qa, ld qb, ld qc, ld l);

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
            ld lambda, ld Ef, bool print = false);

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
            ld l, ld q, ld r, bool print = false);

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
            ld l, ld Q, ld r, ld R, bool print = false);

    /**
     * @brief Find the magnitude of the electric field due to a charged ring of
     * radius a and total charge Q, at a point on the ring axis a distance a
     * from the ring's center.
     * @param a  the radius of the ring
     * @param Q  the total charge of the ring
     * @param print  true to print the answer
     * @return  the magnitude of the electric field
     */
    static ld electricFieldFromChargedRing(ld a, ld Q, bool print = false);

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
            ld r, ld z, ld Q, bool print = false);

    /**
     * A proton moving to the right at V m/s enters a region where a
     * E N/C electric field points to the left. How far will the proton get
     * before its speed reaches zero? Express your answer in meters.
     * @param V the initial speed
     * @param E the electric field
     * @param print true to print the answer
     * @return the distance
     */
    static ld distanceProtonGetsBeforeSpeedZero(ld V, ld E, bool print = false);

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
    static ld magnitudeOfElectricField(ld t, ld theta, ld p, bool print = false);

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
    static ld electricFieldAtPointOnYAxis(ld q, ld a, ld y, bool print = false);

    /**
     * Four equal charges  Q  are at the corners of a square of side  a .
     * Find the magnitude of the force on each charge.
     * @param Q the charge
     * @param a the side length
     * @param print true to print the answer
     * @return the force
     */
    static ld forceOnEachChargeInSquare(ld Q, ld a, bool print = false);

    /**
     * @brief Calculate the surface charge density of a uniformly charged
     * sheet of charge Q and area A.
     * @param Q the charge
     * @param A  the area
     * @param print  true to print the answer
     * @return  the surface charge density
     */
    static constexpr ld surfaceChargeDensity(ld Q, ld A, bool print = false);

    /**
     * An electron close to a large, flat sheet of charge is repelled from the
     * sheet with a E force. Calculate the surface charge density of the sheet.
     * @param E the force
     * @param print true to print the answer
     * @return the surface charge density
     */
    static constexpr ld surfaceChargeDensity(ld E, bool print = false);

    /**
     * brief What surface charge density on an infinite sheet will produce an
     * electric field of E N/C?
     * @param E the electric field
     * @param print true to print the answer
     * @return the surface charge density
     */
    static constexpr ld surfaceChargeDensityFromElectricField(ld E, bool print = false);

    /**
     * @brief Calculate the field charge of a sheet with a surface charge density
     * sigma
     * @param sigma the surface charge density
     * @param print true to print the answer
     * @return the field charge
     */
    static constexpr ld fieldChargeOfSheet(ld sigma, bool print = false);

    /**
     * A total charge of Q C is applied to a thin, square metal plate l m
     * on a side. Calculate the electric field strength near the plates sruface.
     * @param Q the total charge
     * @param l the side length
     * @param print true to print the answer
     * @return the electric field strength
     */
    static constexpr ld electricFieldStrengthNearPlate(
            ld Q, ld l, bool print = false);

    /**
     * @brief Calculate the electric field at the surface of a conductor with
     * surface charge density sigma.
     * @param sigma  the surface charge density
     * @param print  true to print the answer
     * @return  the electric field
     */
    static constexpr ld fieldAtConductorSurface(ld sigma, bool print = false);

    void setElectricChargeVal(ld val) { _electricChargeVal = val; }


    ~ElectricCharge()
    {
        countDecrease();
    }

private:
    static void countIncrease() { electricCharge_objectCount += 1; }
    static void countDecrease() { electricCharge_objectCount -= 1; }
    ld _electricChargeVal;
};
#endif //PHYSICSFORMULA_ELECTRICCHARGE_H

constexpr ld ElectricCharge::massFromEnergy(const ld E, const ld c)
{
    return E / (c * c);
}

constexpr ld ElectricCharge::massFromEnergy(const ld M)
{
    return 2.0 * M;
}

constexpr ld ElectricCharge::totalElectronMass(const ld Ne)
{
    return Ne * constants::ELECTRON_MASS;
}

constexpr ld ElectricCharge::totalProtonMass(const ld Np)
{
    return Np * constants::PROTON_MASS;
}

constexpr ld ElectricCharge::totalMass(const ld Ne, const ld Np)
{
    return totalElectronMass(Ne) + totalProtonMass(Np);
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
        ld q1,
        pair<ld, ld> xy1,
        ld q2, pair<ld, ld> xy2,
        int multiplier,
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
        const ld q, const ld mass, const ld r
)
{
    return r * (sqrt((mass * constants::Ga) / constants::K));
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
        const ld baseNumber, const ld su)
{
    return baseNumber * su * constants::PROTON_CHARGE;
}

inline ld ElectricCharge::howManyFewerElectronsThenProtons(
        const ld netCharge)
{
    return netCharge / abs(constants::ELECTRON_CHARGE);
}

inline ld ElectricCharge::fractionProtonsNoElectrons(
        const ld protons, const ld netCharge)
{
    const ld temp = howManyFewerElectronsThenProtons(netCharge);
    return temp / protons;
}

constexpr ld ElectricCharge::forceChangeTwoPointCharges(
        const ld F, const ld factorChange)
{
    return F / (factorChange * factorChange);
}

constexpr ld ElectricCharge::electricField(
        const ld F, const ld q)
{
    return F / q;
}

ld ElectricCharge::electricFieldFromPointChargeDistribution(
        vector<ld> charges, vector<ld> r_vals)
{
    ld E = 0.0;
    for (int i = 0; i < charges.size(); i++) {
        E += electricField(charges[i], r_vals[i]);
    }
    return E;
}


constexpr ld ElectricCharge::electricFieldByPointCharge(ld q,
                                                        ld r,
                                                        bool print) {
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

constexpr ld ElectricCharge::charge(const ld F, const ld E)
{
    return F / E;
}

inline ld ElectricCharge::separationBetweenPointCharges(
        const ld q1, const ld q2, const ld F)
{
    return sqrt((constants::K * (q1 * q2)) / F);
}

constexpr ld ElectricCharge::howManyElectrons(
        const ld totalParticles, const ld netCharge)
{
    const ld NeMinusNp = netCharge / constants::ELECTRON_CHARGE;
    const ld total     = totalParticles + NeMinusNp;
    const ld Ne        = total / 2.0;

    return Ne;
}

inline ld ElectricCharge::minimumChargeToLiftObject(
        const ld r, const ld charge, const ld m)
{
    return (m * constants::Ga * (r * r)) / (constants::K * charge);
}

inline ld ElectricCharge::minimumChargeToLiftCar(
        const ld r, const ld l, const ld m)
{
    return (r + l) * sqrt((m * constants::Ga) / constants::K);
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
        const ld q1, const ld q2, const ld F)
{
    return sqrt((constants::K * abs(q1) * abs(q2)) / F);
}

inline ld ElectricCharge::angleVerticalAxis(
        const ld Fe, const ld mass)
{
    return atan((Fe / (mass * constants::Ga))) * constants::DEGREE;
}

constexpr ld ElectricCharge::accelerationOfParticles(
        const ld m, const ld r, const ld q1, const ld q2)
{
    return (constants::K * (q1 * q2)) / (m * (r * r));
}

constexpr ld ElectricCharge::electricFieldStrength(const ld d, const ld q_excess)
{
    return (4.0 * constants::K * q_excess) / (d * d);
}

inline ld ElectricCharge::electricFieldStrength(
        const ld m, const ld theta, const ld q)
{
    return (m * constants::Ga * tan(theta * constants::RADIAN)) / q;
}

inline ld ElectricCharge::magnitudeOfq_termsOf_Q_m_d(
        const ld Q, const ld m, const ld d)
{
    return (3.0 * sqrt(6.0) * (d * d) * m * constants::Ga) / (16.0 * constants::K * Q);
}

inline ld ElectricCharge::angularVelocityOfElectronOrbitingProton(
        const ld r, const ld m, const ld q)
{
    return q * sqrt((constants::K) / (m * r));
}

inline ld ElectricCharge::distanceToPlaceThirdChargeToMakeZero(
        const ld l, const ld q1, const ld q2)
{
    return (l * sqrt(q2 / q1)) / (1.0 - sqrt(q2 / q1));
}

inline ld ElectricCharge::magnitudeOfForceOn_q(
        const ld qx4, const ld lSide, const ld q1, const ld theta = 45.0)
{
    return ((8.0 * constants::K * qx4 * q1) / (lSide * lSide)) *
    sin(theta * constants::RADIAN);
}

inline ld ElectricCharge::electricFieldAtLocation(
        const ld qb, const ld qm, const ld l)
{
    return (constants::K / (l * l)) * (sqrt(2) * qb + (qb / 2.0) - 2 * qm);
}

inline std::vector<ld> ElectricCharge::electricFieldAtCenterTriangle(
        const ld qa, const ld qb, const ld qc, const ld l)
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

    return results;
}

constexpr ld ElectricCharge::electrons(
        const ld baseNumber, const ld su)
{
    return (baseNumber * su) / constants::ELECTRON_CHARGE;
}

inline ld ElectricCharge::netElectronCount(
        const ld protons, const ld netCharge)
{
    return protons + ((-abs(netCharge)) / constants::PROTON_CHARGE);
}

constexpr ld ElectricCharge::dipoleMoment(ld q, ld d, bool print) {
    auto mu = q * d;
    if (print) {
        std::cout << "Dipole moment = " << mu << " Cm" << std::endl;
    }
    return mu;
}

constexpr ld ElectricCharge::dipoleFieldPerpendicularBisector(ld p, ld y) {
    return -(constants::K * p) / abs(y*y*y);
}

constexpr ld ElectricCharge::dipoleFieldForXaxis(ld p, ld x) {
    return (2*constants::K*p) / (abs(x*x*x));
}

constexpr ld ElectricCharge::totalElectrons(ld q) {
    return abs(q / constants::ELECTRON_CHARGE);
}

constexpr ld ElectricCharge::electricFlux(ld E, ld A, ld theta, bool print) {
    auto phi = E * A * cos(theta*constants::RADIAN);
    if (print) {
        std::cout << "Electric flux = " << phi << " Nm/C" << std::endl;
    }
    return phi;
}


constexpr ld ElectricCharge::electricFluxSphere(ld q) {
    return q/constants::e0;
}

constexpr ld
ElectricCharge::fieldOutsideSphericalChargeDistribution(ld Q, ld r, bool print) {
    auto E = Q / (4.0 * constants::PI * (r * r) * constants::e0);
    if (print) {
        std::cout << "Field outside spherical charge distribution = "
        << E << " N/C" << std::endl;
    }
    return E;
}

constexpr ld ElectricCharge::fieldOfALineCharge(ld lambda, ld r, bool print) {
    auto E = lambda / (2.0 * constants::PI * r * constants::e0);
    if (print) {
        std::cout << "Field of a line charge = " << E << " V/m" << std::endl;
    }
    return E;
}

constexpr ld
ElectricCharge::electricFluxDisc(ld E, ld R, ld theta, bool print) {
    auto phi = E * constants::PI * (R*R) * cos(theta*constants::RADIAN);
    if (print) {
        std::cout << "Electric flux = " << phi << " Nm/C" << std::endl;
    }
    return phi;
}

constexpr ld
ElectricCharge::distanceFromWireElectricFieldMagnitude(ld lambda,
                                                       ld Ef,
                                                       bool print) {
    auto e0 = constants::e0;
    auto r = lambda / (2.0 * constants::PI * e0 * Ef);
    if (print) {
        std::cout << "Distance from wire = " << r << " m" << std::endl;
    }
    return r;
}

ld ElectricCharge::electricFieldFromChargedRing(ld a, ld Q, bool print) {
    auto k = constants::K;

    auto E = (k * Q) / (2.0* sqrt(2.0) * a * a);
    if (print) {
        std::cout << "Electric field = " << E << " V/m" << std::endl;
    }
    return E;
}

ld ElectricCharge::electricFieldAtPointFromChargedRing(ld r, ld z, ld Q,
                                                    bool print) {
    auto k = constants::K;
    auto E = (k * Q) / pow(((r * r) + (z * z)), 3.0/2.0);
    if (print) {
        std::cout << "Electric field = " << E << " V/m" << std::endl;
    }
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
    if (print) {
        std::cout << "Distance = " << r << " m" << std::endl;
    }
    return r;
}

ld ElectricCharge::magnitudeOfElectricField(ld t, ld theta, ld p, bool print) {
    auto E = t / (p * sin(theta*constants::RADIAN));
    if (print) {
        std::cout << "Electric field = " << E << " N/C" << std::endl;
    }
    return E;
}

constexpr ld
ElectricCharge::magnitudeOfElectricFieldByWire(ld l, ld q, ld r, bool print) {
    auto lamda = q / l;
    auto k = constants::K;
    auto E = (2.0 * k * lamda) / r;
    if (print) {
        std::cout << "Electric field = " << E << " N/C" << std::endl;
    }
    return E;
}

constexpr ld
ElectricCharge::magnitudeOfElectricFieldByRod(
        ld l, ld Q, ld r, ld R, bool print) {
    auto lambda = Q / l;
    auto d = R + r;
    auto k = constants::K;
    auto E = (2.0 * k * lambda) / d;
    if (print) {
        std::cout << "Electric field = " << E << " N/C" << std::endl;
    }
    return E;
}

ld ElectricCharge::electricFieldAtPointOnYAxis(ld q, ld a, ld y, bool print) {
    auto k = constants::K;
    auto E = (4.0 * k * q) / (pow((2.0 * y - a * sqrt(3.0)), 2.0) + (4.0 * y) / pow((4.0 * y * y + a * a), 3.0/2.0));
    if (print) {
        std::cout << "Electric field = " << E << " N/C" << std::endl;
    }
    return E;
}

ld ElectricCharge::forceOnEachChargeInSquare(ld Q, ld a, bool print) {
    auto k = constants::K;
    auto F = ((k * Q * Q) / (2.0 * a * a))*(2.0*sqrt(2.0) + 1.0);
    if (print) {
        std::cout << "Force = " << F << " N" << std::endl;
    }
    return F;
}

ld ElectricCharge::electricFlux(Vector3D E, Vector3D A, bool print) {
    auto phi = E.dot_product(A);
    if (print) {
        std::cout << "Electric flux = " << phi << " Nm/C" << std::endl;
    }
    return phi;
}

constexpr ld ElectricCharge::electricFluxSphere(ld E, ld r, bool print) {
    auto phi = 4.0 * constants::PI * E * r * r;
    if (print) {
        std::cout << "Electric flux = " << phi << " Nm/C" << std::endl;
    }
    return phi;
}

constexpr ld ElectricCharge::fieldInsideSphericalChargeDistribution(ld Qr, ld R,
                                                                    bool print) {
    auto epsilon0 = constants::e0;
    auto E = (Qr / (4.0 * constants::PI * epsilon0 * (R * R * R)));
    if (print) {
        std::cout << "Electric field = " << E << " N/C" << std::endl;
    }
    return E;
}

constexpr ld ElectricCharge::lineChargeDensity(ld q, ld L, bool print) {
    auto lamda = q / L;
    if (print) {
        std::cout << "Line charge density = " << lamda << " C/m" << std::endl;
    }
    return lamda;
}

constexpr ld ElectricCharge::surfaceChargeDensity(ld Q, ld A, bool print) {
    auto sigma = Q / A;
    if (print) {
        std::cout << "Surface charge density = " << sigma << " C/m^2" << std::endl;
    }
    return sigma;
}

constexpr ld ElectricCharge::surfaceChargeDensity(ld E, bool print) {
    auto e = constants::ELECTRON_CHARGE;
    auto sigma = (E * 2.0 * constants::e0) / e;
    if (print) {
        std::cout << "Surface charge density = " << sigma << " C/m^2" << std::endl;
    }
    return sigma;
}

constexpr ld
ElectricCharge::surfaceChargeDensityFromElectricField(ld E, bool print) {
    auto sigma = E * 2.0 * constants::e0;
    if (print) {
        std::cout << "Surface charge density = " << sigma << " C/m^2" << std::endl;
    }
    return sigma;
}

constexpr ld ElectricCharge::fieldOfLineCharge(ld q, ld l, ld r, bool print) {
    auto epsilon0 = constants::e0;
    auto E = (q / (2.0 * constants::PI * epsilon0 * r * l));
    if (print) {
        std::cout << "Electric field = " << E << " N/C" << std::endl;
    }
    return E;
}

constexpr ld ElectricCharge::fieldChargeOfSheet(ld sigma, bool print) {
    auto epsilon0 = constants::e0;
    auto E = sigma / ( 2.0 * epsilon0);
    if (print) {
        std::cout << "Electric field = " << E << " N/C" << std::endl;
    }
    return E;
}

constexpr ld ElectricCharge::fieldAtConductorSurface(ld sigma, bool print) {
    auto epsilon0 = constants::e0;
    auto E = sigma / epsilon0;
    if (print) {
        std::cout << "Electric field = " << E << " N/C" << std::endl;
    }
    return E;
}

constexpr ld ElectricCharge::gaussSphericalSymmetry(ld Q, ld A, bool print) {
    auto E = fieldInsideSphericalChargeDistribution(Q, A, false);
    if (print) {
        std::cout << "Electric field = " << E << " N/C" << std::endl;
    }
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
    if (print) {
        std::cout << "Electric field = " << E << " N/C" << std::endl;
    }
    return E;
}



