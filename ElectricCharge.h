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
#include "Vector2D.h"
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
    typedef ScientificNotationUnits snu;
    ScientificNotationUnits()
    {
        refVal = 0.0;
    }
    ScientificNotationUnits(ld v)
    {
        refVal = v;
    }
    ~ScientificNotationUnits() = default;
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
    friend snu operator+(const snu &r, const snu &l)
    {	return  l.refVal + r.refVal;	}
    snu operator+(ld rhs)const
    {	return this->refVal + rhs;	}
    friend snu operator-(const snu &r, const snu &l)
    {	return  l.refVal - r.refVal;	}
    snu operator-(ld rhs)const
    {	return this->refVal - rhs;	}
    friend snu operator*(const snu &r, const snu &l)
    {	return  l.refVal * r.refVal;	}
    snu operator*(ld rhs)const
    {	return this->refVal * rhs;	}
    friend snu operator/(const snu &r, const snu &l)
    {	return  l.refVal / r.refVal;	}
    snu operator/(ld rhs)const
    {	return this->refVal / rhs;	}

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
    /// <param name="q1">The q1.</param>
    /// <param name="q2">The q2.</param>
    /// <param name="r">The r.</param>
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
    static constexpr ld dipoleMoment(ld q, ld d);

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
    static constexpr ld electricFieldForce(ld Q, ld r);

    /// <summary>
    /// calculates the force by an electric field and current
    /// </summary>
    /// <param name="q">The current.</param>
    /// <param name="E">The electric field strength.</param>
    /// <returns></returns>
    static constexpr ld forceByElectricField(ld q, ld E);

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
    static constexpr ld electricFieldByPointCharge(ld q, ld r);

    /// <summary>
    /// Calculates the magnitude of a point charge that creates a electric field
    /// force of F,  at a distance of r meters.
    /// </summary>
    /// <param name="E">The force of the electric field in N/C.</param>
    /// <param name="r">The distance it causes this force.</param>
    /// <returns>magnitude of the point charge (C)</returns>
    static constexpr ld magnitudePointCharge(ld E, ld r);

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
     * Calculates the electric flux over a sphere of radius r with electric
     * field E. If the electric field is hitting the surface at an angle that
     * is not perpendicular to the the surface, then the angle between the
     * normal of the surface and the electric field is theta.
     * @param E the electric field strength
     * @param r the radius of the sphere
     * @param theta the angle between the electric field line and the normal
     * of the surface of the sphere in degrees.
     * @param print
     * @return
     */
    static constexpr ld electricFluxSphere(ld E, ld r, ld theta, bool print = false);

    /**
     * Calculates he static electric field generated by a distribution of
     * electric charges
     * @param q the charge over an area
     * @return the static electric field strength
     */
    static constexpr ld gaussLaw(ld q);

    /**
     * Calculates the electric field strength caused by a distribution of
     * electric charges over a spherical surface.
     * @param Q the charge over an area
     * @param r the radius of the sphere
     * @return  the electric field strength
     */
    static constexpr ld fieldOutsideSphericalChargeDistribution(ld Q, ld r, bool print = false);

    /**
     * Calculates the electric field of a distribution of electric charges over a
     * symmetric line of length infinity.
     * @param lambda carrying charge density in coulombs per meter
     * @param r  the radius of the line
     * @return  the electric field strength
     */
    static constexpr ld fieldOfALineCharge(ld lambda, ld r, bool print = false);


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
    static std::vector<ld> electricFieldAtCenterTriangle(ld qa, ld qb, ld qc, ld l);

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
        const ld Q, const ld r)
{
    return (constants::K * Q) / (r * r);
}

constexpr ld ElectricCharge::forceByElectricField(
        const ld q, const ld E)
{
    return q * E;
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


constexpr ld ElectricCharge::electricFieldByPointCharge(ld q, ld r) {
    return (constants::K * q) / (r * r);
}

constexpr ld ElectricCharge::magnitudePointCharge(
        const ld E, const ld r)
{
    return ((r * r) * E) / constants::K;
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
    // get the distance and direction of each force from the reference point
    // to all the other points
//    vector<ld> forces;
//    for (auto i = 0; i < charges.size(); i++) {
//        auto F = coulombsLaw(Qref, Qloc, charges[i], locations[i], 1, print);
//        forces.push_back(F);
//    }
//    // get all the direction vectors
//    vector<UnitVector> directionVectors;
//    for (auto i = 0; i < forces.size(); i++) {
//        directionVectors.emplace_back(UnitVector(locations[i], Qloc));
//    }
//    // get the total force
//    ld totalForce = 0.0;
//    for (auto i = 0; i < forces.size(); i++) {
//        totalForce += forces[i];
//    }
//    // get the total direction vector
//    UnitVector totalDirectionVector;
//    for (auto i = 0; i < forces.size(); i++) {
//        totalDirectionVector += directionVectors[i];
//    }
//    // get the total direction vector
//    totalDirectionVector.normalize();
//    // add the total force and direction vector to the return vector
//    vector<ld> returnVector;
//    returnVector.push_back(totalForce);
//    returnVector.push_back(totalDirectionVector.getX());
//    returnVector.push_back(totalDirectionVector.getY());
//
//    if (print) {
//        std::cout << "Total force = " << totalForce << " N" << std::endl;
//        std::cout << "Total direction vector = " << totalDirectionVector.toString() << std::endl;
//        totalDirectionVector.print();
//    }
//
//    return returnVector;

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

constexpr ld ElectricCharge::dipoleMoment(ld q, ld d) {
    return q * d;
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

constexpr ld
ElectricCharge::electricFluxSphere(ld E, ld r, ld theta, bool print) {
    auto area = 4 * constants::PI * r * r;
    auto phi = E * area * sin(theta*constants::RADIAN);
    if (print) {
        std::cout << "Electric flux = " << phi << " Nm^2/C" << std::endl;
    }
    return phi;
}

constexpr ld ElectricCharge::gaussLaw(ld q) {
    return q/constants::e0;
}

constexpr ld
ElectricCharge::fieldOutsideSphericalChargeDistribution(ld Q, ld r, bool print) {
    auto E = Q / (4.0 * constants::PI * r * r * constants::e0);
    if (print) {
        std::cout << "Field outside spherical charge distribution = " << E << " V/m" << std::endl;
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
