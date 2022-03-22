//
// Created by Ryan.Zurrin001 on 12/15/2021.
//

#ifndef PHYSICSFORMULA_ELECTRICPOTENTIAL_H
#define PHYSICSFORMULA_ELECTRICPOTENTIAL_H
/**
 * @class ElectricPotential
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @dateBuilt  12/31/2020
 * @lastEdit 12/31/2020
 */
//#include "ElectricCharge.h"
#include "Heat.h"
#include <iostream>




static int electricalPotential_objectCount = 0;

constexpr auto _eV_ = 1.602e-19;

//constexpr auto _LIGHTSPEED_ = 2.99792458e8;
//multiply joules by this to convert to electron Volts
constexpr auto _JOULES2eV_ = 1.0 / _eV_;

static struct DielectricConstants
{
    const ld vacuum = 1.00000; //1.00000
    const ld Air = 1.00059; //1.00059
    const ld Bakelite = 4.9; //4.9
    const ld fused_quartz = 3.78; //3.78
    const ld neoprene_rubber = 6.7; //6.7
    const ld nylon = 3.4; //3.4
    const ld paper = 3.7; //3.7
    const ld polystyrene = 2.56; //2.56
    const ld pyrex_glass = 55.6; //5.6
    const ld silicon_oil = 2.5; //2.5
    const ld strontium_titanate = 233; //233
    const ld teflon = 2.1; //2.1
    const ld water = 80; //80

}dielectric_constants;

static struct DielectricStrength
{
    const ld Air = 3.0*pow(10,6); //3.0e6
    const ld Bakelite =  24*pow(10,6); //24e6
    const ld fused_quartz =  8*pow(10,6); //8e6
    const ld neoprene_rubber =  12*pow(10,6); //12e6
    const ld nylon =  14*pow(10,6); //14e6
    const ld paper =  16*pow(10,6); //16e6
    const ld polystyrene =  24*pow(10,6); //24e6
    const ld pyrex_glass =  14*pow(10,6); //14e6
    const ld silicon_oil =  15*pow(10,6); //15e6
    const ld strontium_titanate =  8*pow(10,6); //8e6
    const ld teflon =  60*pow(10,6); //60e6

}dielectric_strength;




class ElectricPotential
{
public:
    ElectricPotential* _electricalPotentialPtr;

    ElectricPotential()
    {
        _electricalPotentialPtr = nullptr;
        _electricPotentialVal = 0.0;
        countIncrease();
    }

    ElectricPotential(ld val)
    {
        _electricalPotentialPtr = nullptr;
        _electricPotentialVal = 0.0;
        countIncrease();
    }

    /**
     * @brief copy constructor
     */
    ElectricPotential(const ElectricPotential& t)
    {
        _electricalPotentialPtr = t._electricalPotentialPtr;
        _electricPotentialVal = t._electricPotentialVal;
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    ElectricPotential(ElectricPotential&& t) noexcept
    {
        _electricalPotentialPtr = t._electricalPotentialPtr;
        _electricPotentialVal = t._electricPotentialVal;
        countIncrease();
    }
    /**
     * @brief copy assignment operator
     */
    ElectricPotential& operator=(const ElectricPotential& t)
    {
        if (this != &t)
        {
            _electricalPotentialPtr = t._electricalPotentialPtr;
            _electricPotentialVal = t._electricPotentialVal;
            countIncrease();
        }
        return *this;
    }

    static void show_objectCount() { std::cout
                << "\n electrical potential object count: "
                << electricalPotential_objectCount << std::endl; }
    static int get_objectCount() { return electricalPotential_objectCount; }

    /// <summary>
    /// This is the electrical potential energy per unit change
    /// </summary>
    /// <param name="PE">The potential energy.</param>
    /// <param name="q">The charge that can be moved.</param>
    /// <returns>the electrical potential, volts(V)</returns>
    static ld electricalPotential_V(const ld PE, const ld q);

    /// <summary>
    /// Potentials the difference.
    /// </summary>
    /// <param name="q">The charge.</param>
    /// <param name="V">The voltage.</param>
    /// <returns>the potential difference (PE)</returns>
    static ld potentialDifference_PE(const ld q, const ld V);

    /// <summary>
    /// calculates the total charge moved in Coulombs
    /// </summary>
    /// <param name="PE">The Potential difference.</param>
    /// <param name="V">The electrical potential.</param>
    /// <returns>the charge(q) in Coulombs(C) moved</returns>
    static ld chargeMoved_q(const ld PE, const ld V);

    /// <summary>
    /// Calculates the numbers of electrons that pass through a charge per
    /// second.
    /// </summary>
    /// <param name="chargeMoved">The charge moved(q).</param>
    /// <returns>number of electrons(Ne)</returns>
    static ld electronsPerSecond(const ld chargeMoved);

    /// <summary>
    /// 1 eV = (1.60e-19 C)(1V)= (1.60e-19 C)(1 J/C)joule per Coulomb
    /// </summary>
    /// <param name="V">The Volts.</param>
    /// <returns></returns>
    static ld electronVolts_eV(const ld V);

    /// <summary>
    /// Converts to electron volts from known joules
    /// </summary>
    /// <param name="joules">The joules.</param>
    /// <returns>electron volts (eV)</returns>
    static ld electronVoltsFromJoules(const ld joules);

    /// <summary>
    /// Calculates the final speed of a particle with a mass of m, a charge
    /// of q and a potential difference of V.
    /// </summary>
    /// <param name="q">The charge.</param>
    /// <param name="V">The electrical potential.</param>
    /// <param name="m">The mass.</param>
    /// <returns>velocity (m/s)</returns>
    static ld velocityFinal(const ld q, const ld V, const ld m);

    /// <summary>
    /// Calculates the final speed of a particle with a mass of m, a charge
    /// of q and a potential difference of V.
    /// </summary>
    /// <param name="KE">The Kinetic Energy (J).</param>
    /// <param name="m">The mass.</param>
    /// <returns>velocity (m/s)</returns>
    static ld velocityFinal(const ld KE,  const ld m);

    /// <summary>
    /// Calculates the voltages between two points for a uniform electric field only
    /// </summary>
    /// <param name="E">The max electric field strength.</param>
    /// <param name="d">The distance of separation.</param>
    /// <returns>maximum voltage (V)</returns>
    static ld voltageBetween2points_Vab(const ld E, const ld d);

    /// <summary>
    /// Calculates the Electric field strength between two points/plates for
    /// a uniform electric field only
    /// </summary>
    /// <param name="V">The potential difference or volts.</param>
    /// <param name="d">The distance between points.</param>
    /// <returns>magnitude of electric field(N/C)(V/m)</returns>
    static ld electricFieldMagnitude(const ld V, const ld d);

    /// <summary>
    /// Calculates the electric field. which ius said to be the gradient fo the
    /// electric potential.
    /// </summary>
    /// <param name="V">The volts.</param>
    /// <param name="s">The distance the change in volts occurs.</param>
    /// <returns>electric field</returns>
    static ld electricField(const ld V, const ld s);

    /// <summary>
    /// Calculates the volts from electric field.
    /// </summary>
    /// <param name="E">The electric field strength.</param>
    /// <param name="s">The distance over which the change in potential takes
    /// place.</param>
    /// <returns></returns>
    static ld voltsFromElectricFieldGradient(const ld E, const ld s);

    /// <summary>
    /// Calculates the distances over which the change in volts occurs.
    /// </summary>
    /// <param name="V">The change in volts.</param>
    /// <param name="E">The Electric field strength.</param>
    /// <returns>distance(m)</returns>
    static ld distanceOverChangeInVolts_s(const ld V, const ld E);

    /// <summary>
    /// How far from a Q charged point charge will the potential be V volts?
    /// </summary>
    /// <param name="Q">The charge (C).</param>
    /// <param name="V">The volts.</param>
    /// <returns>distance (meters)</returns>
    static ld distancePointChargeToEqualVoltsOf(const ld Q, const ld V);

    /// <summary>
    /// Electrics the potential point charge.
    /// </summary>
    /// <param name="Q">The point charge.</param>
    /// <param name="r">The distance.</param>
    /// <returns>voltage</returns>
    static ld electricPotential_pointCharge(const ld Q, const ld r);

    /// <summary>
    /// calculates the excesses charge.
    /// </summary>
    /// <param name="r">The radius.</param>
    /// <param name="V">The voltage.</param>
    /// <returns>charge in Coulombs(C)</returns>
    static ld excessCharge(const ld r, const ld V);

    /// <summary>
    /// Calculates the voltage needed to obtain a certain energy.
    /// </summary>
    /// <param name="m">The m.</param>
    /// <param name="v">The v.</param>
    /// <param name="q">The q.</param>
    /// <param name="numProtons">number of protons in atom of consideration</param>
    /// <returns>voltage (V)</returns>
    static ld voltageNeededToObtainEnergy(const ld m, const ld v, const ld q, const ld numProtons);

    /// <summary>
    /// ions with a charge iof q are accelerated from rest through a voltage
    /// of V. At what temperature will the average kinetic energy of gas
    /// molecules be the same as that given these ions?
    /// </summary>
    /// <param name="q">The charge.</param>
    /// <param name="V">The voltage.</param>
    /// <returns>temperature in Kelvin(k)</returns>
    static ld temperatureAvgKineticEnergyGasMolecule(const ld V, const ld q);

    /// <summary>
    /// The temperature of ion particles is T degrees Celsius. Through what voltage
    /// must a charged ion be accelerated to have the same energy as the average
    /// kinetic energy of ions at this temperature?
    /// </summary>
    /// <param name="T">The t.</param>
    /// <param name="q">The q.</param>
    /// <returns>voltage (V)</returns>
    static ld voltageIonsMoveThroughToReachSameTemperature(const ld T, const ld q);

    //static ld massToRaisFromTemp1ToTemp2(const ld)


    /// <summary>
    /// Capacitance of a capacitor. units of C/V or A^2s^2/kg*m^2
    /// </summary>
    /// <param name="Q">The charge.</param>
    /// <param name="V">The volts.</param>
    /// <returns>the capacitance (C/V)</returns>
    static ld capacitance(const ld Q, const ld V);

    /// <summary>
    /// Calculates the charge stored in a capacitor.
    /// </summary>
    /// <param name="C">The Capacitance.</param>
    /// <param name="V">The volts.</param>
    /// <returns>the charge (Q)</returns>
    static ld capacitanceCharge(const ld C, const ld V);

    /// <summary>
    /// Calculates the voltage applied to a C (F) capacitor when it holds
    /// Q (C) of charge.
    /// </summary>
    /// <param name="Q">The charge.</param>
    /// <param name="C">The capacitance.</param>
    /// <returns>volts (V)</returns>
    static ld capacitanceVolts(const ld Q, const ld C);

    /// <summary>
    /// Calculates the capacitance of a parallel plate capacitor
    /// </summary>
    /// <param name="A">the area.</param>
    /// <param name="d">The distance between plates.</param>
    /// <returns>the capacitance C in farads</returns>
    static ld capacitanceParallelPlate(const ld A, const ld d);

    /// <summary>
    /// Calculates the capacitance of a parallel plate capacitor with a
    /// dielectric
    /// </summary>
    /// <param name="d_k">The dielectric constant.</param>
    /// <param name="A"> The area of the capacitor.</param>
    /// <param name="d">The distance between plates.</param>
    /// <returns>the capacitance C in farads</returns>
    static ld capacitanceParallelPlateDielectric(const ld d_k, const ld A, const ld d);

    /// <summary>
    /// the dielectric constant is generally defined to be the ratio of the
    /// electric field in a vacuum to that in the dielectric material, and is
    /// intimately related to the polarize-ability of the material.
    /// </summary>
    /// <param name="E0">The electric field in a vacuum.</param>
    /// <param name="E">The electric field of the dielectric.</param>
    /// <returns>dielectric constant</returns>
    static ld dielectricConstant(const ld E0, const ld E);

    /// <summary>
    /// calculates the energy stored in a capacitor
    /// Ecap = (Q*V)/2.
    /// </summary>
    /// <param name="Q">The charge.</param>
    /// <param name="V">The volts.</param>
    /// <returns>Energy stored in capacitor</returns>
    static ld capacitorEnergy_Ecap_QV(const ld Q, const ld V);

    /// <summary>
    /// calculates the energy stored in a capacitor
    /// Ecap = (C * V^2)/2.0.
    /// </summary>
    /// <param name="C">The capacitance.</param>
    /// <param name="V">The volts.</param>
    /// <returns>Energy stored in capacitor</returns>
    static ld capacitorEnergy_Ecap_CV(const ld C, const ld V);

    /// <summary>
    /// calculates the energy stored in a capacitor
    /// Ecap = Q^2/2*C.
    /// </summary>
    /// <param name="Q">The charge.</param>
    /// <param name="C">The capacitance.</param>
    /// <returns>Energy stored in capacitor</returns>
    static ld capacitorEnergy_Ecap_QC(const ld Q, const ld C);

    /// <summary>
    /// Potentials the across ecap ce.
    /// </summary>
    /// <param name="C">The c.</param>
    /// <param name="Ecap">The ecap.</param>
    /// <returns></returns>
    static ld potentialAcross_Ecap_CE(const ld C, const ld Ecap);

    /// <summary>
    ///  Calculate the area the parallel plates of a capacitor of capacitance C

    ///  must have if they are separated by a distance of d.
    /// </summary>
    /// <param name="C">The capacitance.</param>
    /// <param name="d">The distance.</param>
    /// <returns>the area of the parallel plates of a capacitor (m^2)</returns>
    static ld capacitorPlateArea(const ld C, const ld d);

    /// <summary>
    ///  Calculate the area the parallel plates of a capacitor with a capacitance
    ///  of C must have if it is separated by d meters of a dielectric, which
    ///  has a dielectric constant of k.
    /// </summary>
    /// <param name="C">The capacitance.</param>
    /// <param name="d">The distance of separation .</param>
    /// <param name="k">The dielectric constant.</param>
    /// <returns>the area of the parallel plates of a capacitor (m^2)</returns>
    static ld capacitorPlateAreaDielectric(const ld C, const ld d, const ld k);

    /// <summary>
    /// vs the maximum on capacitor.
    /// </summary>
    /// <param name="dStrength">The dielectric strength.</param>
    /// <param name="d">The distance between plates.</param>
    /// <returns>max voltage that can be applied</returns>
    static ld vMaxOnCapacitor(const ld dStrength, const ld d);

    /// <summary>
    /// Maximums the charge can be stored capacitor.
    /// </summary>
    /// <param name="C">The capacitance.</param>
    /// <param name="vMax">The max voltage.</param>
    /// <returns>max charge that can be stored in a capacitor (C)</returns>
    static ld maxChargeCanBeStoredCapacitor(const ld C, const ld vMax);

    /// <summary>
    /// Calculates the Volume the of dielectric material.
    /// </summary>
    /// <param name="A">area.</param>
    /// <param name="d">The distance.</param>
    /// <returns></returns>
    static ld volumeOfDielectricMaterial(const ld A, const ld d);

    /// <summary>
    /// Electrics the field strength between2plates.
    /// </summary>
    /// <param name="KE">The kinetic energy.</param>
    /// <param name="q">The charge.</param>
    /// <param name="d">The distance.</param>
    /// <returns>Electric field strength(V/m)</returns>
    static ld electricFieldStrengthBetween2plates(const ld KE, const ld q, const ld d);

    /// <summary>
    /// A  plastic sphere of diameter d is used in a static electricity
    /// demonstration, has a uniformly distributed charge of q on its
    /// surface. What is the potential near its surface?
    /// </summary>
    /// <param name="d">The diameter of sphere.</param>
    /// <param name="q">The charge.</param>
    /// <returns>volts</returns>
    static ld potentialNearSurfaceOfSphere(const ld d, const ld q);

    /// <summary>
    /// An electrostatic paint sprayer has a metal sphere of diameter d and
    /// a potential of V volts that repels paint droplets onto a grounded
    /// object.  What charge is on the sphere?
    /// </summary>
    /// <param name="d">The diameter.</param>
    /// <param name="V">The volts.</param>
    /// <returns>the charge (C)</returns>
    static ld chargeOnSphere(const ld d, const ld V);

    /// <summary>
    /// What charge must a 0.100-mg point with a potential of V have to arrive at an object
    /// with a speed of v m/s?
    /// </summary>
    /// <param name="m">The mass in kg.</param>
    /// <param name="v">The velocity.</param>
    /// <param name="V">The voltage.</param>
    /// <returns>charge (C)</returns>
    static ld chargeOnPointToArriveWithSpeed(const ld m, const ld v, const ld V);

    /// <summary>
    /// A prankster applies a voltage of V to an capacitor of C farad and then tosses it
    /// to an unsuspecting victim. The victim's finger is burned by the discharge
    /// of the capacitor through m g of flesh. What is the temperature increase
    /// of the flesh? Is it reasonable to assume no phase change?
    /// </summary>
    /// <param name="V">The voltage.</param>
    /// <param name="C">The capacitance.</param>
    /// <param name="m">The mass.</param>
    /// <param name="_c">The specific heat.</param>
    /// <returns></returns>
    static ld temperatureChangeFromCapacitanceBurn(const ld V, const ld C, const ld m, const ld _c );

    /// <summary>
    /// Potential energy used to move positive charge.
    /// </summary>
    /// <param name="q">The positive charge.</param>
    /// <param name="Vab">The change in volts.</param>
    /// <returns>KE (J)</returns>
    static ld kineticEnergyFinalToMovePositiveCharge(const ld q, const ld Vab);



    void setElectricPotentialVal(ld val)
    {
        _electricPotentialVal = val;
    }

    ~ElectricPotential()
    {
        delete _electricalPotentialPtr;
    }

private:
    static void countIncrease() { electricalPotential_objectCount += 1; }
    static void countDecrease() { electricalPotential_objectCount -= 1; }
    ld _electricPotentialVal;

};

#endif //PHYSICSFORMULA_ELECTRICPOTENTIAL_H


inline ld ElectricPotential::electricalPotential_V(const ld PE, const ld q)
{
    return PE/q;
}

inline ld ElectricPotential::potentialDifference_PE(const ld q, const ld V)
{
    return q*V;
}

inline ld ElectricPotential::chargeMoved_q(const ld PE, const ld V)
{
    return PE / V;
}

inline ld ElectricPotential::electronsPerSecond(const ld chargeMoved)
{
    return chargeMoved/_ELECTRON_CHARGE_;
}

inline ld ElectricPotential::electronVolts_eV(const ld V)
{
    return _eV_ * V;
}

inline ld ElectricPotential::electronVoltsFromJoules(const ld joules)
{
    return joules/_PROTON_CHARGE_;
}

inline ld ElectricPotential::velocityFinal(const ld q, const ld V, const ld m)
{
    return sqrt((2.0 * q * V) / m);
}

inline ld ElectricPotential::velocityFinal(const ld KE, const ld m)
{
    return sqrt((2.0 * KE) / m);
}

inline ld ElectricPotential::voltageBetween2points_Vab(const ld E, const ld d)
{
    return E * d;
}

inline ld ElectricPotential::electricFieldMagnitude(const ld V, const ld d)
{
    return V / d;
}

inline ld ElectricPotential::electricField(const ld V, const ld s)
{
    return -(V / s);
}

inline ld ElectricPotential::voltsFromElectricFieldGradient(const ld E, const ld s)
{
    return -E * s;
}

inline ld ElectricPotential::distanceOverChangeInVolts_s(const ld V, const ld E)
{
    return V / E;
}

inline ld ElectricPotential::distancePointChargeToEqualVoltsOf(const ld Q, const ld V)
{
    return (_k_*Q)/V;
}

inline ld ElectricPotential::electricPotential_pointCharge(const ld Q, const ld r)
{
    return (_k_ * Q) / r;
}

inline ld ElectricPotential::excessCharge(const ld r, const ld V)
{
    return (r * V) / _k_;
}

inline ld ElectricPotential::voltageNeededToObtainEnergy(const ld m, const ld v, const ld q, const ld numProtons)
{
    return -(m * (v*v)) / (2.0 * (numProtons*q));
}

inline ld ElectricPotential::temperatureAvgKineticEnergyGasMolecule(const ld V, const ld q = _PROTON_CHARGE_)
{

    return (2* q* V)/(3.0 * BOLTZMANN_K_);
}

inline ld ElectricPotential::voltageIonsMoveThroughToReachSameTemperature(const ld T, const ld q = _PROTON_CHARGE_)
{
    return (3/2)*((BOLTZMANN_K_*T)/q);
}


inline ld ElectricPotential::capacitance(const ld Q, const ld V)
{
    return Q/V;
}

inline ld ElectricPotential::capacitanceCharge(const ld C, const ld V)
{
    return C * V;
}

inline ld ElectricPotential::capacitanceVolts(const ld Q, const ld C)
{
    return Q/C;
}

inline ld ElectricPotential::capacitanceParallelPlate(const ld A, const ld d)
{
    return _e0_ * (A / d);
}


inline ld ElectricPotential::capacitanceParallelPlateDielectric(const ld d_k, const ld A, const ld d)
{
    return d_k * _e0_ * (A / d);
}

inline ld ElectricPotential::dielectricConstant(const ld E0, const ld E)
{
    return E0/E;
}

inline ld ElectricPotential::capacitorEnergy_Ecap_QV(const ld Q, const ld V)
{
    return (Q * V) / 2.0;
}

inline ld ElectricPotential::capacitorEnergy_Ecap_CV(const ld C, const ld V)
{
    return (C*(V*V))/2.0;
}

inline ld ElectricPotential::capacitorEnergy_Ecap_QC(const ld Q, const ld C)
{
    return (Q*Q)/(2.0*C);
}

inline ld ElectricPotential::potentialAcross_Ecap_CE(const ld C, const ld Ecap)
{
    return sqrt((Ecap * 2.0) / C);
}


inline ld ElectricPotential::capacitorPlateArea(const ld C, const ld d)
{
    return C * d / (_e0_);
}

inline ld ElectricPotential::capacitorPlateAreaDielectric(const ld C, const ld d, const ld k)
{
    return (d * C) / (k * _e0_);
}

inline ld ElectricPotential::vMaxOnCapacitor(const ld dStrength, const ld d)
{
    return dStrength * d;
}


inline ld ElectricPotential::maxChargeCanBeStoredCapacitor(const ld C, const ld vMax)
{
    return C * vMax;
}

inline ld ElectricPotential::volumeOfDielectricMaterial(const ld A, const ld d)
{
    return A * d;
}

inline ld ElectricPotential::electricFieldStrengthBetween2plates(const ld KE, const ld q, const ld d)
{
    return KE/(q*d);
}

inline ld ElectricPotential::potentialNearSurfaceOfSphere(const ld d, const ld q)
{
    return (2.0*_k_*q)/d;
}

inline ld ElectricPotential::chargeOnSphere(const ld d, const ld V)
{
    return (d*V)/(2.0*_k_);
}

inline ld ElectricPotential::chargeOnPointToArriveWithSpeed(const ld m, const ld v, const ld V)
{
    return (m*(v*v))/(2.0*V);
}

inline ld ElectricPotential::temperatureChangeFromCapacitanceBurn(const ld V, const ld C, const ld m, const ld _c_ = _c.human_body_average_S[0])
{
    return (C*(V*V))/(2.0*m*_c_);
}

inline ld ElectricPotential::kineticEnergyFinalToMovePositiveCharge(const ld q, const ld Vab)
{
    return -q * Vab;
}

