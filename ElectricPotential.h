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
#include "Heat.h"
#include <iostream>




static int electricalPotential_objectCount = 0;



//constexpr auto _LIGHTSPEED_ = 2.99792458e8;
//multiply joules by this to convert to electron Volts


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

    ElectricPotential()
    {
        _electricPotentialVal = 0.0;
        countIncrease();
    }

    explicit ElectricPotential(ld val)
    {
        _electricPotentialVal = 0.0;
        countIncrease();
    }

    /**
     * @brief copy constructor
     */
    ElectricPotential(const ElectricPotential& t)
    {
        _electricPotentialVal = t._electricPotentialVal;
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    ElectricPotential(ElectricPotential&& t) noexcept
    {
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
    static ld electricalPotential_V(ld PE, ld q);

    /// <summary>
    /// Potentials the difference.
    /// </summary>
    /// <param name="q">The charge.</param>
    /// <param name="volts">The voltage.</param>
    /// <returns>the potential difference (PE)</returns>
    static ld potentialDifference_PE(ld q, ld volts, bool print = true);

    /**
     * @brief It takes W J to move a q C charge from point A to point B.
     * What's the potential difference ΔV_AB
     * @param W The work done.
     * @param q  The charge.
     * @param print The print.
     * @return ld
     */
    static ld potentialDifference_V(ld W, ld q, bool print = true);



    /**
     * @brief Calculates the potential difference between two points moving
     * across an electric field strength of E at an angle theta to the field.
     * @param E the electric field strength
     * @param r the distance between the two points
     * @param theta the angle between the electric field and the distance between
     * @param print if true, prints the results to the console
     * @return the potential difference
     */
    static ld potentialDifference(ld E, ld r, ld theta, bool print = true);

    /// <summary>
    /// calculates the total charge moved in Coulombs
    /// </summary>
    /// <param name="PE">The Potential difference.</param>
    /// <param name="volts">The electrical potential.</param>
    /// <returns>the charge(q) in Coulombs(C) moved</returns>
    static ld chargeMoved_q(ld PE, ld volts);

    /// <summary>
    /// Calculates the numbers of electrons that pass through a charge per
    /// second.
    /// </summary>
    /// <param name="chargeMoved">The charge moved(q).</param>
    /// <returns>number of electrons(Ne)</returns>
    static ld electronsPerSecond(ld chargeMoved);

    /// <summary>
    /// 1 eV = (1.60e-19 C)(1V)= (1.60e-19 C)(1 J/C)joule per Coulomb
    /// </summary>
    /// <param name="volts">The Volts.</param>
    /// <returns></returns>
    static ld electronVolts_eV(ld volts);

    /// <summary>
    /// Converts to electron volts from known j
    /// </summary>
    /// <param name="j">The j.</param>
    /// <returns>electron volts (eV)</returns>
    static ld electronVoltsFromJoules(ld j);

    /// <summary>
    /// Calculates the final speed of a particle with a mass of m, a charge
    /// of q and a potential difference of volts.
    /// </summary>
    /// <param name="q">The charge.</param>
    /// <param name="volts">The electrical potential.</param>
    /// <param name="m">The mass.</param>
    /// <returns>velocity (m/s)</returns>
    static ld velocityFinal(ld q, ld volts, ld m);

    /// <summary>
    /// Calculates the final speed of a particle with a mass of m, a charge
    /// of q and a potential difference of V.
    /// </summary>
    /// <param name="KE">The Kinetic Energy (J).</param>
    /// <param name="m">The mass.</param>
    /// <returns>velocity (m/s)</returns>
    static ld velocityFinal(ld KE,  ld m);

    /// <summary>
    /// Calculates the voltages between two points for a uniform electric field only
    /// </summary>
    /// <param name="E">The max electric field strength.</param>
    /// <param name="d">The distance of separation.</param>
    /// <returns>maximum voltage (V)</returns>
    static ld voltageBetween2points_Vab(ld E, ld d);

    /// <summary>
    /// Calculates the Electric field strength between two points/plates for
    /// a uniform electric field only
    /// </summary>
    /// <param name="volts">The potential difference or volts.</param>
    /// <param name="d">The distance between points.</param>
    /// <returns>magnitude of electric field(N/C)(volts/m)</returns>
    static ld electricFieldMagnitude(ld volts, ld d);

    /// <summary>
    /// Calculates the electric field. which ius said to be the gradient fo the
    /// electric potential.
    /// </summary>
    /// <param name="volts">The volts.</param>
    /// <param name="s">The distance the change in volts occurs.</param>
    /// <returns>electric field</returns>
    static ld electricField(ld volts, ld s);

    /// <summary>
    /// Calculates the volts from electric field.
    /// </summary>
    /// <param name="E">The electric field strength.</param>
    /// <param name="s">The distance over which the change in potential takes
    /// place.</param>
    /// <returns></returns>
    static ld voltsFromElectricFieldGradient(ld E, ld s);

    /// <summary>
    /// Calculates the distances over which the change in volts occurs.
    /// </summary>
    /// <param name="volts">The change in volts.</param>
    /// <param name="E">The Electric field strength.</param>
    /// <returns>distance(m)</returns>
    static ld distanceOverChangeInVolts_s(ld volts, ld E);

    /// <summary>
    /// How far from a COULOMB charged point charge will the potential be volts volts?
    /// </summary>
    /// <param name="COULOMB">The charge (C).</param>
    /// <param name="volts">The volts.</param>
    /// <returns>distance (meters)</returns>
    static ld distancePointChargeToEqualVoltsOf(ld Q, ld volts);

    /// <summary>
    /// Electrics the potential point charge.
    /// </summary>
    /// <param name="COULOMB">The point charge.</param>
    /// <param name="r">The distance.</param>
    /// <returns>voltage</returns>
    static ld electricPotential_pointCharge(ld Q, ld r);

    /// <summary>
    /// calculates the excesses charge.
    /// </summary>
    /// <param name="r">The radius.</param>
    /// <param name="volts">The voltage.</param>
    /// <returns>charge in Coulombs(C)</returns>
    static ld excessCharge(ld r, ld volts);

    /// <summary>
    /// Calculates the voltage needed to obtain a certain energy.
    /// </summary>
    /// <param name="m">The m.</param>
    /// <param name="volts">The volts.</param>
    /// <param name="q">The q.</param>
    /// <param name="numProtons">number of protons in atom of consideration</param>
    /// <returns>voltage (V)</returns>
    static ld voltageNeededToObtainEnergy(ld m, ld volts, ld q, ld numProtons);

    /// <summary>
    /// ions with a charge iof q are accelerated from rest through a voltage
    /// of volts. At what temperature will the average kinetic energy of gas
    /// molecules be the same as that given these ions?
    /// </summary>
    /// <param name="q">The charge.</param>
    /// <param name="volts">The voltage.</param>
    /// <returns>temperature in Kelvin(k)</returns>
    static ld temperatureAvgKineticEnergyGasMolecule(ld volts, ld q);

    /// <summary>
    /// The temperature of ion particles is T degrees Celsius. Through what voltage
    /// must a charged ion be accelerated to have the same energy as the average
    /// kinetic energy of ions at this temperature?
    /// </summary>
    /// <param name="T">The t.</param>
    /// <param name="q">The q.</param>
    /// <returns>voltage (V)</returns>
    static ld voltageIonsMoveThroughToReachSameTemperature(ld T, ld q);

    /// <summary>
    /// Capacitance of a capacitor. units of C/volts or A^2s^2/kg*m^2
    /// </summary>
    /// <param name="COULOMB">The charge.</param>
    /// <param name="volts">The volts.</param>
    /// <returns>the capacitance (C/volts)</returns>
    static ld capacitance(ld Q, ld volts);

    /// <summary>
    /// Calculates the charge stored in a capacitor.
    /// </summary>
    /// <param name="C">The Capacitance.</param>
    /// <param name="volts">The volts.</param>
    /// <returns>the charge (COULOMB)</returns>
    static ld capacitanceCharge(ld C, ld volts);

    /// <summary>
    /// Calculates the voltage applied to a C (F) capacitor when it holds
    /// COULOMB (C) of charge.
    /// </summary>
    /// <param name="COULOMB">The charge.</param>
    /// <param name="C">The capacitance.</param>
    /// <returns>volts (V)</returns>
    static ld capacitanceVolts(ld Q, ld C);

    /// <summary>
    /// Calculates the capacitance of a parallel plate capacitor
    /// </summary>
    /// <param name="A">the area.</param>
    /// <param name="d">The distance between plates.</param>
    /// <returns>the capacitance C in farads</returns>
    static ld capacitanceParallelPlate(ld A, ld d);

    /// <summary>
    /// Calculates the capacitance of a parallel plate capacitor with a
    /// dielectric
    /// </summary>
    /// <param name="d_k">The dielectric constant.</param>
    /// <param name="A"> The area of the capacitor.</param>
    /// <param name="d">The distance between plates.</param>
    /// <returns>the capacitance C in farads</returns>
    static ld capacitanceParallelPlateDielectric(ld d_k, ld A, ld d);

    /// <summary>
    /// the dielectric constant is generally defined to be the ratio of the
    /// electric field in a vacuum to that in the dielectric material, and is
    /// intimately related to the polarize-ability of the material.
    /// </summary>
    /// <param name="E0">The electric field in a vacuum.</param>
    /// <param name="E">The electric field of the dielectric.</param>
    /// <returns>dielectric constant</returns>
    static ld dielectricConstant(ld E0, ld E);

    /// <summary>
    /// calculates the energy stored in a capacitor
    /// Ecap = (COULOMB*volts)/2.
    /// </summary>
    /// <param name="COULOMB">The charge.</param>
    /// <param name="volts">The volts.</param>
    /// <returns>Energy stored in capacitor</returns>
    static ld capacitorEnergy_Ecap_QV(ld Q, ld volts);

    /// <summary>
    /// calculates the energy stored in a capacitor
    /// Ecap = (C * volts^2)/2.0.
    /// </summary>
    /// <param name="C">The capacitance.</param>
    /// <param name="volts">The volts.</param>
    /// <returns>Energy stored in capacitor</returns>
    static ld capacitorEnergy_Ecap_CV(ld C, ld volts);

    /// <summary>
    /// calculates the energy stored in a capacitor
    /// Ecap = COULOMB^2/2*C.
    /// </summary>
    /// <param name="COULOMB">The charge.</param>
    /// <param name="C">The capacitance.</param>
    /// <returns>Energy stored in capacitor</returns>
    static ld capacitorEnergy_Ecap_QC(ld Q, ld C);

    /// <summary>
    /// Potentials the across ecap ce.
    /// </summary>
    /// <param name="C">The c.</param>
    /// <param name="Ecap">The ecap.</param>
    /// <returns></returns>
    static ld potentialAcross_Ecap_CE(ld C, ld Ecap);

    /// <summary>
    ///  Calculate the area the parallel plates of a capacitor of capacitance C

    ///  must have if they are separated by a distance of d.
    /// </summary>
    /// <param name="C">The capacitance.</param>
    /// <param name="d">The distance.</param>
    /// <returns>the area of the parallel plates of a capacitor (m^2)</returns>
    static ld capacitorPlateArea(ld C, ld d);

    /// <summary>
    ///  Calculate the area the parallel plates of a capacitor with a capacitance
    ///  of C must have if it is separated by d meters of a dielectric, which
    ///  has a dielectric constant of k.
    /// </summary>
    /// <param name="C">The capacitance.</param>
    /// <param name="d">The distance of separation .</param>
    /// <param name="k">The dielectric constant.</param>
    /// <returns>the area of the parallel plates of a capacitor (m^2)</returns>
    static ld capacitorPlateAreaDielectric(ld C, ld d, ld k);

    /// <summary>
    /// vs the maximum on capacitor.
    /// </summary>
    /// <param name="dStrength">The dielectric strength.</param>
    /// <param name="d">The distance between plates.</param>
    /// <returns>max voltage that can be applied</returns>
    static ld vMaxOnCapacitor(ld dStrength, ld d);

    /// <summary>
    /// Maximums the charge can be stored capacitor.
    /// </summary>
    /// <param name="C">The capacitance.</param>
    /// <param name="vMax">The max voltage.</param>
    /// <returns>max charge that can be stored in a capacitor (C)</returns>
    static ld maxChargeCanBeStoredCapacitor(ld C, ld vMax);

    /// <summary>
    /// Calculates the Volume the of dielectric material.
    /// </summary>
    /// <param name="A">area.</param>
    /// <param name="d">The distance.</param>
    /// <returns></returns>
    static ld volumeOfDielectricMaterial(ld A, ld d);

    /// <summary>
    /// Electrics the field strength between2plates.
    /// </summary>
    /// <param name="KE">The kinetic energy.</param>
    /// <param name="q">The charge.</param>
    /// <param name="d">The distance.</param>
    /// <returns>Electric field strength(V/m)</returns>
    static ld electricFieldStrengthBetween2plates(ld KE, ld q, ld d);

    /// <summary>
    /// A  plastic sphere of diameter d is used in a static electricity
    /// demonstration, has a uniformly distributed charge of q on its
    /// surface. What is the potential near its surface?
    /// </summary>
    /// <param name="d">The diameter of sphere.</param>
    /// <param name="q">The charge.</param>
    /// <returns>volts</returns>
    static ld potentialNearSurfaceOfSphere(ld d, ld q);

    /// <summary>
    /// An electrostatic paint sprayer has a metal sphere of diameter d and
    /// a potential of volts volts that repels paint droplets onto a grounded
    /// object.  What charge is on the sphere?
    /// </summary>
    /// <param name="d">The diameter.</param>
    /// <param name="volts">The volts.</param>
    /// <returns>the charge (C)</returns>
    static ld chargeOnSphere(ld d, ld volts);

    /// <summary>
    /// What charge must a 0.100-mg point with a potential of volts have to arrive at an object
    /// with a speed of velocity m/s?
    /// </summary>
    /// <param name="m">The mass in kg.</param>
    /// <param name="velocity">The velocity.</param>
    /// <param name="volts">The voltage.</param>
    /// <returns>charge (C)</returns>
    static ld chargeOnPointToArriveWithSpeed(ld m, ld velocity, ld volts);

    /// <summary>
    /// A prankster applies a voltage of volts to an capacitor of C farad and then tosses it
    /// to an unsuspecting victim. The victim's finger is burned by the discharge
    /// of the capacitor through m g of flesh. What is the temperature increase
    /// of the flesh? Is it reasonable to assume no phase change?
    /// </summary>
    /// <param name="volts">The voltage.</param>
    /// <param name="C">The capacitance.</param>
    /// <param name="m">The mass.</param>
    /// <param name="_c">The specific heat.</param>
    /// <returns></returns>
    static ld temperatureChangeFromCapacitanceBurn(ld volts, ld C, ld m, ld _c );

    /// <summary>
    /// Potential energy used to move positive charge.
    /// </summary>
    /// <param name="q">The positive charge.</param>
    /// <param name="Vab">The change in volts.</param>
    /// <returns>KE (J)</returns>
    static ld kineticEnergyFinalToMovePositiveCharge(ld q, ld Vab);

    /**
     * @brief What is the work done by the electric force to move a Q C
     * charge from point A with an electric potential of EPA to point B with an
     * electric potential of EPB?
     * @param Q the charge (C)
     * @param EPA the electric potential at point A (V)
     * @param EPB the electric potential at point B (V)
     * @param print true to print the answer
     * @return the work done (J)
     */
    static ld workDoneByElectricForce(ld Q, ld EPA, ld EPB, bool print = true);

    /**
     * @brief Calculate the change in KE of a charge Q C as it moves from point A
     * with a electric potential of Va to point B with an electric potential of Vb.
     * @param Q the charge (C)
     * @param Va the electric potential at point A (V)
     * @param Vb the electric potential at point B (V)
     * @param print true to print the answer
     * @return the change in KE (J)
     */
    static ld changeInKEOfCharge(ld Q, ld Va, ld Vb, bool print = true);

    /**
     * @brief A particle with charge Q C is placed on the x axis in a region
     * where the electric potential due to other charges increases in the +x
     * direction but does not change in the y or z direction. The particle,
     * initially at rest, is acted upon only by the electric force and moves
     * from point a to point b along the x axis, increasing its kinetic energy
     * by KE J . In what direction and through what potential difference Vb−Va
     * does the particle move?
     * NOTE:
     * In general, if no forces other than the electric force act on a
     * positively charged particle, the particle always moves toward a point at
     * lower potential
     * @param Q the charge (C)
     * @param KE the change in KE (J)
     * @param print true to print the answer
     * @return the change in potential (V)
     */
    static ld changeInPotentialOfMovingCharge(ld Q, ld KE, bool print = true);

    /**
     * @brief the electric force of a particle of charge q in an electric field
     * of strength E is given by F = qE.
     * @param q the charge (C)
     * @param E the electric field strength (V/m)
     * @param print true to print the answer
     * @return the electric force (N)
     */
    static ld electricForce(ld q, ld E, bool print = true);

    /**
     * @brief Calculate the work it take to move a q C charge against a U V
     * potential difference.
     * @param q the charge (C)
     * @param U the potential difference (V)
     * @param print true to print the answer
     * @return the work done (J)
     */
    static ld workDoneToMoveCharge(ld q, ld U, bool print = true);

    /**
     * @brief Calculates the magnitude of the potential difference between two
     * points located r m apart in a uniform Ef N/C electric field, if a
     * line between the points is at angle theta to the electric field
     * (default is parallel to the field).
     * @param r the distance between the points (m)
     * @param Ef the electric field strength (N/C)
     * @param theta the angle between the line and the electric field (rad)
     * @param print true to print the answer
     * @return the potential difference (V)
     */
    static ld potentialDifferenceBetweenTwoPoints(
            ld r, ld Ef, ld theta = 0, bool print = true);



    void setElectricPotentialVal(ld val)
    {
        _electricPotentialVal = val;
    }

    ~ElectricPotential()
    {
        countDecrease();
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

inline ld ElectricPotential::potentialDifference_PE(
        const ld q, const ld volts, bool print)
{
    ld PE = q*volts;
    if (print)
        std::cout << "PE = " << PE << " J" << std::endl;
    return PE;
}

inline ld ElectricPotential::chargeMoved_q(const ld PE, const ld volts)
{
    return PE / volts;
}

inline ld ElectricPotential::electronsPerSecond(const ld chargeMoved)
{
    return chargeMoved/constants::ELECTRON_CHARGE;
}

inline ld ElectricPotential::electronVolts_eV(const ld volts)
{
    return constants::eV * volts;
}

inline ld ElectricPotential::electronVoltsFromJoules(const ld j)
{
    return j / constants::PROTON_CHARGE;
}

inline ld ElectricPotential::velocityFinal(const ld q, const ld volts, const ld m)
{
    return sqrt((2.0 * q * volts) / m);
}

inline ld ElectricPotential::velocityFinal(const ld KE, const ld m)
{
    return sqrt((2.0 * KE) / m);
}

inline ld ElectricPotential::voltageBetween2points_Vab(const ld E, const ld d)
{
    return E * d;
}

inline ld ElectricPotential::electricFieldMagnitude(const ld volts, const ld d)
{
    return volts / d;
}

inline ld ElectricPotential::electricField(const ld volts, const ld s)
{
    return -(volts / s);
}

inline ld ElectricPotential::voltsFromElectricFieldGradient(const ld E, const ld s)
{
    return -E * s;
}

inline ld ElectricPotential::distanceOverChangeInVolts_s(const ld volts, const ld E)
{
    return volts / E;
}

inline ld ElectricPotential::distancePointChargeToEqualVoltsOf(const ld Q,
                                                               const ld volts)
{
    return (constants::K*Q) / volts;
}

inline ld ElectricPotential::electricPotential_pointCharge(const ld Q, const ld r)
{
    return (constants::K * Q) / r;
}

inline ld ElectricPotential::excessCharge(const ld r, const ld volts)
{
    return (r * volts) / constants::K;
}

inline ld ElectricPotential::voltageNeededToObtainEnergy(const ld m,
                                                         const ld volts,
                                                         const ld q,
                                                         const ld numProtons)
{
    return -(m * (volts * volts)) / (2.0 * (numProtons * q));
}

inline ld ElectricPotential::temperatureAvgKineticEnergyGasMolecule(
        const ld volts,
        const ld q = constants::PROTON_CHARGE)
{

    return (2 * q * volts) / (3.0 * constants::STEFAN_BOLTZMANN);
}

inline ld ElectricPotential::voltageIonsMoveThroughToReachSameTemperature(
        const ld T, const ld q = constants::PROTON_CHARGE)
{
    return (3.0/2.0)*((constants::STEFAN_BOLTZMANN * T) / q);
}


inline ld ElectricPotential::capacitance(const ld Q, const ld volts)
{
    return Q / volts;
}

inline ld ElectricPotential::capacitanceCharge(const ld C, const ld volts)
{
    return C * volts;
}

inline ld ElectricPotential::capacitanceVolts(const ld Q, const ld C)
{
    return Q/C;
}

inline ld ElectricPotential::capacitanceParallelPlate(const ld A, const ld d)
{
    return constants::e0 * (A / d);
}


inline ld ElectricPotential::capacitanceParallelPlateDielectric(const ld d_k, const ld A, const ld d)
{
    return d_k * constants::e0 * (A / d);
}

inline ld ElectricPotential::dielectricConstant(const ld E0, const ld E)
{
    return E0/E;
}

inline ld ElectricPotential::capacitorEnergy_Ecap_QV(const ld Q, const ld volts)
{
    return (Q * volts) / 2.0;
}

inline ld ElectricPotential::capacitorEnergy_Ecap_CV(const ld C, const ld volts)
{
    return (C*(volts * volts)) / 2.0;
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
    return C * d / (constants::e0);
}

inline ld ElectricPotential::capacitorPlateAreaDielectric(const ld C,
                                                          const ld d,
                                                          const ld k)
{
    return (d * C) / (k * constants::e0);
}

inline ld ElectricPotential::vMaxOnCapacitor(const ld dStrength, const ld d)
{
    return dStrength * d;
}


inline ld ElectricPotential::maxChargeCanBeStoredCapacitor(const ld C,
                                                           const ld vMax)
{
    return C * vMax;
}

inline ld ElectricPotential::volumeOfDielectricMaterial(const ld A, const ld d)
{
    return A * d;
}

inline ld ElectricPotential::electricFieldStrengthBetween2plates(
        const ld KE,
        const ld q,
        const ld d)
{
    return KE/(q*d);
}

inline ld ElectricPotential::potentialNearSurfaceOfSphere(const ld d, const ld q)
{
    return (2.0*constants::K * q)/d;
}

inline ld ElectricPotential::chargeOnSphere(const ld d, const ld volts)
{
    return (d * volts) / (2.0 * constants::K);
}

inline ld ElectricPotential::chargeOnPointToArriveWithSpeed(const ld m,
                                                            const ld velocity,
                                                            const ld volts)
{
    return (m*(velocity * velocity)) / (2.0 * volts);
}

inline ld ElectricPotential::temperatureChangeFromCapacitanceBurn(
        const ld volts,
        const ld C,
        const ld m,
        const ld _c_ = SHC.humanBodyAverageSolid.J_kgC)
{
    return (C*(volts * volts)) / (2.0 * m * _c_);
}

inline ld ElectricPotential::kineticEnergyFinalToMovePositiveCharge(
        const ld q, const ld Vab)
{
    return -q * Vab;
}

ld ElectricPotential::potentialDifference(ld E, ld r, ld theta, bool print) {
    ld V = E * r * cos(theta);
    if (print) {
        std::cout << "V = " << V << " V" << std::endl;
    }
    return V;
}

ld
ElectricPotential::workDoneByElectricForce(ld Q, ld EPA, ld EPB, bool print) {
    ld W = Q * (EPA - EPB);
    if (print) {
        std::cout << "W = " << W << " J" << std::endl;
    }
    return W;
}

ld ElectricPotential::changeInKEOfCharge(ld Q, ld Va, ld Vb, bool print) {
    ld deltaKE = Q * abs(Vb - Va);
    if (print) {
        std::cout << "deltaKE = " << deltaKE << " J" << std::endl;
    }
    return deltaKE;
}

ld ElectricPotential::changeInPotentialOfMovingCharge(ld Q, ld KE, bool print) {
    ld deltaV = - (KE / Q);
    if (print) {
        std::cout << "deltaV = " << deltaV << " V" << std::endl;
    }
    return deltaV;
}

ld ElectricPotential::electricForce(ld q, ld E, bool print) {
    ld F = q * E;
    if (print) {
        std::cout << "F = " << F << " N" << std::endl;
    }
    return F;
}

ld ElectricPotential::workDoneToMoveCharge(ld q, ld U, bool print) {
    ld W = q * U;
    if (print) {
        std::cout << "W = " << W << " J" << std::endl;
    }
    return W;
}

ld ElectricPotential::potentialDifference_V(ld W, ld q, bool print) {
    ld V = W / q;
    if (print) {
        std::cout << "V = " << V << " V" << std::endl;
    }
    return V;
}

ld ElectricPotential::potentialDifferenceBetweenTwoPoints(
        ld r, ld Ef, ld theta, bool print) {
    ld V = Ef * r * cos(theta);
    if (print) {
        std::cout << "V = " << V << " V" << std::endl;
    }
    return V;
}

