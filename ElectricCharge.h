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

#include "Vector2D.h"
typedef long double ld;

/// <summary>
/// The meters light travels in one light year
/// </summary>
constexpr auto METERS_1LY = 9460730472580800;

//pi = 3.14159265359
constexpr auto _pi_ = 3.14159265359;
/// <summary>
/// Vacuum permittivity, commonly denoted ε0 (pronounced as "epsilon nought"
/// or "epsilon zero") is the value of the absolute dielectric permittivity
/// of classical vacuum.
/// </summary>
constexpr auto _e0_ = 8.854187819013e-12; // 8.8542e-12
/// <summary>
/// Coulombs constant 8.988 * pow(10.0, 9)Nm^2)/C^2
/// </summary>
constexpr auto _k_ = 8.9875517923e9; //8.988 * pow(10.0, 9)Nm^2)/C^2
constexpr auto _K_ = 1.0 / (4.0 * _pi_ * _e0_);
/// <summary>
/// The electron = -1.6 * 10^-19 C
/// </summary>
constexpr auto _ELECTRON_CHARGE_ = -(1.602176634e-19); //-1.6e-19

/// <summary>
/// The proton = 1.6 * 10^-19C
/// </summary>
constexpr auto _PROTON_CHARGE_ = 1.602176634e-19; // 1.6e-19
constexpr auto _COULOMB_       = 1.0 / (_ELECTRON_CHARGE_);

constexpr auto _ELECTRON_MASS_ = 9.1093837015e-31;  //9.11e-31
constexpr auto _PROTON_MASS_   = 1.67262e-27; //1.673e-27

constexpr auto _PLANKS_J_ = 6.62607004e-34;
constexpr auto _PLANKS_EM_ = 4.14e-15;
constexpr auto _PLANKS_C_ = _PLANKS_EM_ * 2.99792e8;

static int electricCharge_objectCount = 0;

static struct ScientificNotationUnits
{
    typedef ScientificNotationUnits snu;
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
    ScientificNotationUnits()
    {
        refVal = 0.0;
    }
    ScientificNotationUnits(ld v)
    {
        refVal = v;
    }
    ~ScientificNotationUnits() = default;
} SU;


class ElectricCharge
{
public:
    ElectricCharge* _electricChargePtr;

    ElectricCharge()
    {
        _electricChargePtr = nullptr;
        _electricChargeVal = 0.0;
        countIncrease();
    }

    ElectricCharge(ld val)
    {
        _electricChargePtr = nullptr;
        _electricChargeVal = 0.0;
        countIncrease();
    }

    /**
     * @brief copy constructor
     */
    ElectricCharge(const ElectricCharge& t)
    {
        _electricChargePtr = t._electricChargePtr;
        _electricChargeVal = t._electricChargeVal;
        countIncrease();
    }

    /**
     * #brief move constructor
     */
    ElectricCharge(ElectricCharge&& t) noexcept
    {
        _electricChargePtr = t._electricChargePtr;
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
            _electricChargePtr = t._electricChargePtr;
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
    /// Calculates the magnitude between two electrostatic forces q1 and q2
    /// </summary>
    /// <param name="q1">The q1.</param>
    /// <param name="q2">The q2.</param>
    /// <param name="r">The r.</param>
    /// <returns></returns>
    static constexpr ld electrostaticForce(ld q1, ld q2, ld r);

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
    /// <param name="Q">The q.</param>
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
    static constexpr ld charge(const ld F, const ld E);



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
    static constexpr ld minimumChargeToLiftObject(ld r, ld charge, ld m);

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
    /// <param name="f1">The f1.</param>
    /// <param name="f2">The f2.</param>
    /// <param name="f3">The f3.</param>
    /// <param name="f4">The f4.</param>
    /// <param name="f5">The f5.</param>
    /// <param name="f6">The f6.</param>
    /// <returns>net charge</returns>
    static constexpr ld superpositionPrinciple
            (ld f1, ld f2, ld f3, ld f4, ld f5, ld f6);

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
    /// four equal charges q lie on the corners of a square. A fifth charge Q
    /// is on a mass m directly above the center of the square, at a height
    /// equal to the length d of one side of the square.
    /// Determine the magnitude of q in terms of Q , m , and d ,
    /// if the Coulomb force is to equal the weight of m.
    /// </summary>
    /// <param name="Q">The charge of the center point.</param>
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
        delete _electricChargePtr;
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
    return Ne * _ELECTRON_MASS_;
}

constexpr ld ElectricCharge::totalProtonMass(const ld Np)
{
    return Np * _PROTON_MASS_;
}

constexpr ld ElectricCharge::totalMass(const ld Ne, const ld Np)
{
    return totalElectronMass(Ne) + totalProtonMass(Np);
}

constexpr ld ElectricCharge::electrostaticForce(
        const ld q1, const ld q2, const ld r
)
{
    return (_k_ * q1 * q2) / (r * r);
}

inline ld ElectricCharge::chargeOfElectrostaticForce_equalPointCharges(
        const ld q, const ld mass, const ld r
)
{
    return r * (sqrt((mass * _Ga_) / _k_));
}

constexpr ld ElectricCharge::electricFieldForce(
        const ld Q, const ld r
)
{
    return (_k_ * Q) / (r * r);
}

constexpr ld ElectricCharge::forceByElectricField(
        const ld q, const ld E
)
{
    return q * E;
}

constexpr ld ElectricCharge::coulombs(
        const ld baseNumber, const ld su
)
{
    return baseNumber * su * _PROTON_CHARGE_;
}

inline ld ElectricCharge::howManyFewerElectronsThenProtons(
        const ld netCharge
)
{
    return netCharge / abs(_ELECTRON_CHARGE_);
}

inline ld ElectricCharge::fractionProtonsNoElectrons(
        const ld protons, const ld netCharge
)
{
    const ld temp = howManyFewerElectronsThenProtons(netCharge);
    return temp / protons;
}

constexpr ld ElectricCharge::forceChangeTwoPointCharges(
        const ld F, const ld factorChange
)
{
    return F / (factorChange * factorChange);
}

constexpr ld ElectricCharge::electricField(
        const ld F, const ld q
)
{
    return F / q;
}

constexpr ld ElectricCharge::magnitudePointCharge(
        const ld E, const ld r
)
{
    return ((r * r) * E) / _k_;
}

constexpr ld ElectricCharge::charge(const ld F, const ld E)
{
    return F / E;
}

inline ld ElectricCharge::separationBetweenPointCharges(
        const ld q1, const ld q2, const ld F
)
{
    return sqrt((_k_ * (q1 * q2)) / F);
}

constexpr ld ElectricCharge::howManyElectrons(
        const ld totalParticles, const ld netCharge
)
{
    const ld NeMinusNp = netCharge / _ELECTRON_CHARGE_;
    const ld total     = totalParticles + NeMinusNp;
    const ld Ne        = total / 2.0;

    return Ne;
}

constexpr ld ElectricCharge::minimumChargeToLiftObject(
        const ld r, const ld charge, const ld m
)
{
    return (m * _Ga_ * (r * r)) / (_k_ * charge);
}

inline ld ElectricCharge::minimumChargeToLiftCar(
        const ld r, const ld l, const ld m
)
{
    return (r + l) * sqrt((m * _Ga_) / _k_);
}

constexpr ld ElectricCharge::superpositionPrinciple(
        const ld f1 = 0, const ld f2 = 0, const ld f3 = 0, const ld f4 = 0,
        const ld f5 = 0, const ld f6 = 0
)
{
    return f1 + f2 + f3 + f4 + f5 + f6;
}

inline ld ElectricCharge::distanceBetweenPoints(
        const ld q1, const ld q2, const ld F
)
{
    return sqrt((_k_ * abs(q1) * abs(q2)) / F);
}

inline ld ElectricCharge::angleVerticalAxis(
        const ld Fe, const ld mass
)
{
    return atan((Fe / (mass * _Ga_))) * DEGREE;
}

constexpr ld ElectricCharge::accelerationOfParticles(
        const ld m, const ld r, const ld q1, const ld q2
)
{
    return (_k_ * (q1 * q2)) / (m * (r * r));
}

constexpr ld ElectricCharge::electricFieldStrength(const ld d, const ld q_excess)
{
    return (4.0 * _k_ * q_excess) / (d * d);
}

inline ld ElectricCharge::electricFieldStrength(
        const ld m, const ld theta, const ld q
)
{
    return (m * _Ga_ * tan(theta * RADIAN)) / q;
}

inline ld ElectricCharge::magnitudeOfq_termsOf_Q_m_d(
        const ld Q, const ld m, const ld d
)
{
    return (3.0 * sqrt(6.0) * (d * d) * m * _Ga_) / (16.0 * _k_ * Q);
}

inline ld ElectricCharge::angularVelocityOfElectronOrbitingProton(
        const ld r, const ld m, const ld q
)
{
    return q * sqrt((_k_) / (m * r));
}

inline ld ElectricCharge::distanceToPlaceThirdChargeToMakeZero(
        const ld l, const ld q1, const ld q2
)
{
    return (l * sqrt(q2 / q1)) / (1.0 - sqrt(q2 / q1));
}

inline ld ElectricCharge::magnitudeOfForceOn_q(
        const ld qx4, const ld lSide, const ld q1, const ld theta = 45.0
)
{
    return ((8.0 * _k_ * qx4 * q1) / (lSide * lSide)) * sin(theta * RADIAN);
}

inline ld ElectricCharge::electricFieldAtLocation(
        const ld qb, const ld qm, const ld l
)
{
    return (_k_ / (l * l)) * (sqrt(2) * qb + (qb / 2.0) - 2 * qm);
}

inline std::vector<ld> ElectricCharge::electricFieldAtCenterTriangle(
        const ld qa, const ld qb, const ld qc, const ld l
)
{
    std::vector<ld> results = {0.0, 0.0};
    const ld sr_rthx   = 3.0 * sqrt(3);
    //cout << "3*srty3: " << sr_rthx << endl;
    const ld y = sr_rthx * _k_;
    //cout << "ktimessqrt3: " << y << endl;
    const ld z = 2 * (l * l);
    //cout << "2timeslength: " << z << endl;
    const ld w = y / z;
    //cout << "topdividedbybottom: " << w << endl;
    const ld j = abs(qb) + abs(qc);
    //cout << "qb+qc: " << j  << endl;
    const ld Ex = w * j;
    //cout << "Ex: " << Ex << endl;
    const ld Ey = ((3.0 * _k_) / (l * l)) * (-qa - abs((qb / 2)) + abs((qc / 2))
    );
    //cout << "Ey: " << Ey << endl;
    results[0] = sqrt((Ex * Ex) + (Ey * Ey));
    results[1] = atan((Ey / Ex)) * 180 / _pi_;

    return results;
}

constexpr ld ElectricCharge::electrons(
        const ld baseNumber, const ld su
)
{
    return (baseNumber * su) / _ELECTRON_CHARGE_;
}

inline ld ElectricCharge::netElectronCount(
        const ld protons, const ld netCharge
)
{
    return protons + ((-abs(netCharge)) / _PROTON_CHARGE_);
}
