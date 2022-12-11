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
#include "Vector3D.h"
#include <iostream>




static int electricalPotential_objectCount = 0;

struct POINT_CHARGE_2D
{
    double q;
    Vector3D position;
    POINT_CHARGE_2D(double q, const Vector3D& p) : q(q), position(p) {}
};

struct POINT_CHARGE_3D
{
    double q;
    Vector3D position;
    POINT_CHARGE_3D(double q, const Vector3D& p) : q(q), position(p) {}
};
typedef POINT_CHARGE_2D pc2d;
typedef POINT_CHARGE_3D pc3d;
//constexpr auto _LIGHTSPEED_ = 2.99792458e8;
//multiply joules by this to convert to electron Volts


static struct DielectricConstants
{
    DielectricConstants(){}
    const struct VACUUM {
        const ld constant = 1.00000;
        const ld breakdown_field = 0.0;
    }vacuum;
    const struct AIR {
        const ld constant = 1.00059;
        const ld breakdown_field = 3.0e6; //3.0e6
    }air;
    const struct BAKELITE {
        const ld constant = 4.9;
        const ld breakdown_field = 24*pow(10,6); //24e6
    }bakelite;
    const struct FUSED_QUARTZ {
        const ld constant = 3.78;
        const ld breakdown_field = 8e6; //8e6
    }fused_quartz;
    const struct NEOPRENE_RUBBER {
        const ld constant = 6.7;
        const ld breakdown_field = 12*pow(10,6); //12e6
    }neoprene_rubber;
    const struct NYLON {
        const ld constant = 3.4;
        const ld breakdown_field = 14*pow(10,6); //14e6
    }nylon;
    const struct PAPER {
        const ld constant = 3.7;
        const ld breakdown_field = 16*pow(10,6); //16e6
    }paper;
    const struct POLYSTYRENE {
        const ld constant = 2.56;
        const ld breakdown_field = 24*pow(10,6); //24e6
    }polystyrene;
    const struct PYREX_GLASS {
        const ld constant = 5.6;
        const ld breakdown_field = 14*pow(10,6); //14e6
    }pyrex_glass;
    const struct SILICON_OIL {
        const ld constant = 2.5;
        const ld breakdown_field = 15*pow(10,6); //15e6
    }silicon_oil;
    const struct STRONTIUM_TITANATE {
        const ld constant = 233;
        const ld breakdown_field = 8*pow(10,6); //8e6
    }strontium_titanate;
    const struct TEFLON {
        const ld constant = 2.1;
        const ld breakdown_field = 60*pow(10,6); //60e6
    }teflon;
    const struct WATER {
        const ld constant = 80;
        const ld breakdown_field = 3.5*pow(10,6); //3.5e6
    }water;

}dielectrics;


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

    /**
     * @brief This is the electrical potential energy per unit change
     * @param PE  The potential energy.
     * @param q  The charge that can be moved.
     * @param print  print the result to the console
     * @return  the electrical potential, volts(V)
     */
    static ld electricalPotential_V(ld PE, ld q, bool print = true);

    /**
     * @brief Calculates the potential energy of a charge
     * @param q The charge.
     * @param volts The voltage.
     * @param print print the result to the console
     * @return the potential difference (PE)
     */
    static ld potentialEnergy_qV(ld q, ld volts, bool print = true);

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

    /**
     * @brief Calculates the total charge moved in Coulombs
     * @param PE The Potential difference.
     * @param volts The electrical potential.
     * @param print print the result to the console
     * @return the charge(q) in Coulombs(C) moved
     */
    static ld chargeMoved(ld PE, ld volts, bool print = true);

    /**
     * @brief Calculate much charge must be transferred between the initially
     * uncharged plates of the capacitor with side lengths of s m and a
     * distance apart of d m, in order to store Eu J of energy, as well
     * calculate the resulting potential difference between the plates.
     * @param Eu the energy stored in the capacitor
     * @param s the side length of the capacitor
     * @param d the distance between the plates
     * @param print if true, prints the results to the console
     * @return the charge moved
     */
    static vector<ld> chargeMoved(ld Eu, ld s, ld d, bool print = true);

    /**
     * @brief Calculates the numbers of electrons that pass through a charge per
     * second.
     * @param chargeMoved The charge moved(q).
     * @param print print the result to the console
     * @return number of electrons(Ne)
     */
    static ld electronsPerSecond(ld chargeMoved, bool print = true);

    /**
     * @brief Calculates the energy in electron volts(eV)
     * @param volts The volts.
     * @param print print the result to the console
     * @return the energy in electron volts(eV)
     */
    static ld electronVolts_eV(ld volts, bool print = true);

    /**
     * @brief Converts to electron volts from known j
     * @param j The j.
     * @param print print the result to the console
     * @return the energy in electron volts(eV)
     */
    static ld electronVoltsFromJoules(ld j, bool print = true);

    /**
     * @brief Calculates the final speed of a particle with a mass of m, a charge
     * of q and a potential difference of volts.
     * @param q The charge.
     * @param volts The electrical potential.
     * @param m The mass.
     * @param print print the result to the console
     * @return velocity (m/s)
     */
    static ld velocityFinal(ld q, ld volts, ld m, bool print = true);


    /**
     * @brief Calculates the final speed of a particle with a mass of m, a charge
     * of q and a potential difference of V.
     * @param KE The Kinetic Energy (J).
     * @param m The mass.
     * @param print print the result to the console
     * @return velocity (m/s)
     */
    static ld velocityFinal(ld KE,  ld m, bool print = true);

    /**
     * @brief Calculates the voltages between two points for a uniform electric
     * field only
     * @param E The max electric field strength.
     * @param d The distance of separation.
     * @param print print the result to the console
     * @return maximum voltage (V)
     */
    static ld voltageBetween2points_Vab(ld E, ld d, bool print = true);

    /**
     * @brief Calculates the Electric field strength between two points/plates
     * for a uniform electric field only
     * @param volts The potential difference or volts.
     * @param d The distance between points.
     * @param print print the result to the console
     * @return magnitude of electric field(N/C)(volts/m)
     */
    static ld electricFieldMagnitude(ld volts, ld d, bool print = true);

    /**
     * @brief Calculates the electric field. which ius said to be the gradient fo
     * the electric potential.
     * @param volts The volts.
     * @param s The distance the change in volts occurs.
     * @param print print the result to the console
     * @return electric field
     */
    static ld electricField(ld volts, ld s, bool print = true);

    /**
     * @brief Calculates the volts from electric field.
     * @param E The electric field strength.
     * @param s The distance over which the change in potential takes place.
     * @param print print the result to the console
     * @return volts
     */
    static ld voltsFromElectricFieldGradient(ld E, ld s, bool print = true);

    /**
     * @brief Calculates the distances over which the change in volts occurs.
     * @param volts The change in volts.
     * @param E The Electric field strength.
     * @param print print the result to the console
     * @return distance(m)
     */
    static ld distanceOverChangeInVolts_s(ld volts, ld E, bool print = true);

    /**
     * @brief How far from a COULOMB charged point charge will the potential be
     * volts volts?
     * @param Q The charge (C).
     * @param volts The volts.
     * @param print print the result to the console
     * @return distance (meters)
     */
    static ld distancePointChargeToEqualVoltsOf(ld Q, ld volts, bool print = true);

    /**
     * @brief Calculates the voltage between two points for a point charge
     * @param Q The point charge.
     * @param r The distance.
     * @param print print the result to the console
     * @return voltage
     */
    static ld electricPotential_pointCharge(ld Q, ld r, bool print = true);

    /**
     * @brief Calculates the excesses charge.
     * @param r The radius.
     * @param volts The voltage.
     * @param print print the result to the console
     * @return charge in Coulombs(C)
     */
    static ld excessCharge(ld r, ld volts, bool print = true);

    /**
     * @brief Calculates the voltage needed to obtain a certain energy.
     * @param m The mass.
     * @param volts The volts.
     * @param q The charge.
     * @param numProtons number of protons in atom of consideration
     * @param print print the result to the console
     * @return voltage (V)
     */
    static ld voltageNeededToObtainEnergy(ld m, ld volts, ld q, ld numProtons, bool print = true);

    /**
     * @brief ions with a charge iof q are accelerated from rest through a
     * voltage of volts. At what temperature will the average kinetic energy of
     * gas molecules be the same as that given these ions?
     * @param q The charge.
     * @param volts The voltage.
     * @param print print the result to the console
     * @return temperature in Kelvin(k)
     */
    static ld temperatureAvgKineticEnergyGasMolecule(ld volts, ld q, bool print = true);

    /**
     * @brief The temperature of ion particles is T degrees Celsius. Through what
     * voltage must a charged ion be accelerated to have the same energy as the
     * average kinetic energy of ions at this temperature?
     * @param T The temperature in degrees Celsius.
     * @param q The charge.
     * @param print print the result to the console
     * @return voltage (V)
     */
    static ld voltageIonsMoveThroughToReachSameTemperature(ld T, ld q, bool print = true);

    /**
     * @brief Capacitance of a capacitor. units of C/volts or A^2s^2/kg*m^2
     * @param Q The charge.
     * @param volts The volts.
     * @param print print the result to the console
     * @return the capacitance_Qv (C/volts)
     */
    static ld capacitance_Qv(ld Q, ld volts, bool print = true);

    /**
     * @brief Calculate the capacitance of a capacitor that stores E joules of
     * energy when the potential difference between its plates is V volts.
     * @param E The energy.
     * @param V The volts.
     * @param print print the result to the console
     * @return capacitance (C)
     */
    static ld capacitance_Ev(ld E, ld V, bool print = true);

    /**
     * @brief You’re given three capacitors C1, C2, C3:  Calculate
     * (a) the maximum,
     * (b) the minimum,
     * and (c) two intermediate capacitances you could achieve using
     * combinations of all three capacitors.
     * @param C1 The capacitance of the first capacitor.
     * @param C2 The capacitance of the second capacitor.
     * @param C3 The capacitance of the third capacitor.
     * @param print print the result to the console
     * @return the maximum, the minimum, and two intermediate capacitances
     */
    static std::vector<ld> maxMinAndIntermediateCapacitances(ld C1, ld C2, ld C3, bool print = true);

    /**
     * @brief Calculates the charge stored in a capacitor.
     * @param C The capacitance_Qv.
     * @param volts The volts.
     * @param print print the result to the console
     * @return the charge (COULOMB)
     */
    static ld chargeStoredInCapacitor(ld C, ld volts, bool print = true);

    /**
     * @brief Calculates the voltage applied to a C (F) capacitor when it holds
     * COULOMB (C) of charge.
     * @param Q The charge.
     * @param C The capacitance_Qv.
     * @param print print the result to the console
     * @return volts (V)
     */
    static ld voltageAcrossCapacitor(ld Q, ld C, bool print = true);

    /**
     * @brief Calculates the capacitance_Qv of a parallel plate capacitor
     * @param A The area.
     * @param d The distance between plates.
     * @param print print the result to the console
     * @return the capacitance_Qv C in farads
     */
    static ld capacitanceParallelPlate(ld A, ld d, bool print = true);

    static ld capacitanceRoundParallelPlate(ld R, ld d, bool print = true);

    /**
     * @brief Calculates the capacitance_Qv of a parallel plate capacitor with a
     * dielectric
     * @param d_k The dielectric constant.
     * @param A The area of the capacitor.
     * @param d The distance between plates.
     * @param print print the result to the console
     * @return the capacitance_Qv C in farads
     */
    static ld capacitanceParallelPlateDielectric(ld d_k, ld A, ld d, bool print = true);

    /**
     * @brief Calculates the dielectric constant.
     * @param E0 The electric field in a vacuum.
     * @param E The electric field of the dielectric.
     * @param print print the result to the console
     * @return the dielectric constant
     */
    static ld dielectricConstant(ld E0, ld E, bool print = true);

    /**
     * @brief Calculates the energy stored in a capacitor.
     * @param COULOMB The charge.
     * @param volts The volts.
     * @param print print the result to the console
     * @return energy stored in capacitor
     */
    static ld capacitorEnergy_Ecap_QV(ld Q, ld volts, bool print = true);

    /**
     * @brief Calculates the energy stored in a capacitor.
     * @param C The capacitance_Qv.
     * @param volts The volts.
     * @param print print the result to the console
     * @return energy stored in capacitor
     */
    static ld capacitorEnergy_Ecap_CV(ld C, ld volts, bool print = true);

    /**
     * @brief Calculates the energy stored in a capacitor.
     * @param COULOMB The charge.
     * @param C The capacitance_Qv.
     * @param print print the result to the console
     * @return energy stored in capacitor
     */
    static ld capacitorEnergy_Ecap_QC(ld Q, ld C, bool print = true);

    /**
     * @brief Calculates the potential across a capacitor.
     * @param C The capacitance_Qv.
     * @param Ecap The energy stored in the capacitor.
     * @param print print the result to the console
     * @return the potential across the capacitor
     */
    static ld potentialAcross_Ecap_CE(ld C, ld Ecap, bool print = true);

    /**
     * Calculate the area the parallel plates of a capacitor of capacitance_Qv C
     * must have if they are separated by a distance of d.
     * @param C the capacitance_Qv
     * @param d  the distance
     * @return  the area of the parallel plates of a capacitor (m^2)
     */
    static ld capacitorPlateArea(ld C, ld d, bool print = true);

    /**
     * @brief A parallel-plate capacitor with d m plate spacing has +/- Q C on
     * its plates when charged to V volts. Calculate the plates area.
     * @param Q the charge
     * @param V the voltage
     * @param d the distance between the plates
     * @return the area of the plates
     */
    static ld capacitorPlateArea_QVd(ld Q, ld V, ld d, bool print = true);

    /**
     * @brief Calculate the area the parallel plates of a capacitor with a
     * capacitance_Qv of C must have if it is separated by d meters of a dielectric,
     * which has a dielectric constant of k.
     * @param C the capacitance_Qv
     * @param d the distance of separation
     * @param k the dielectric constant
     * @return the area of the parallel plates of a capacitor (m^2)
     */
    static ld capacitorPlateAreaDielectric(ld C, ld d, ld k, bool print = true);

    /**
     * @brief Calculate the maximum voltage that can be applied to a capacitor
     * with a dielectric strength of dStrength and a distance between plates of d.
     * @param dStrength the dielectric strength
     * @param d the distance between the plates
     * @return the maximum voltage that can be applied
     */
    static ld vMaxOnCapacitor(ld dStrength, ld d, bool print = true);

    /**
     * @brief Calculate the maximum charge that can be stored in a capacitor
     * with a capacitance_Qv of C and a maximum voltage of vMax.
     * @param C the capacitance_Qv
     * @param vMax the maximum voltage
     * @return the maximum charge that can be stored in a capacitor (C)
     */
    static ld maxChargeCanBeStoredCapacitor(ld C, ld vMax, bool print = true);

    /**
     * @brief Calculates the Volume the of dielectric material.
     * @param A the area
     * @param d the distance
     * @return the volume of the dielectric material
     */
    static ld volumeOfDielectricMaterial(ld A, ld d, bool print = true);

    /**
     * @brief Calculates the Electric field strength between two plates.
     * @param KE the kinetic energy
     * @param q the charge
     * @param d the distance
     * @return the Electric field strength (V/m)
     */
    static ld electricFieldStrengthBetween2plates(ld KE, ld q, ld d, bool print = true);

    /**
     * @brief Calculates the potential near the surface of a sphere.
     * @param d the diameter of the sphere
     * @param q the charge
     * @return the potential near the surface of a sphere (V)
     */
    static ld potentialNearSurfaceOfSphere(ld d, ld q, bool print = true);

    /**
     * @brief An electrostatic paint sprayer has a metal sphere of diameter d
     * and a potential of volts volts that repels paint droplets onto a grounded
     * object.  What charge is on the sphere?
     * @param d the diameter
     * @param volts the volts
     * @return the charge (C)
     */
    static ld chargeOnSphere(ld d, ld volts, bool print = true);

    /**
     * @brief What charge must a 0.100-mg point with a potential of volts have to arrive at an object
     * with a speed of velocity m/s?
     * @param m the mass in kg
     * @param velocity the velocity
     * @param volts the voltage
     * @return the charge (C)
     */
    static ld chargeOnPointToArriveWithSpeed(ld m, ld velocity, ld volts, bool print = true);

    /**
     * @brief A prankster applies a voltage of volts to an capacitor of C farad and then tosses it
     * to an unsuspecting victim. The victim's finger is burned by the discharge
     * of the capacitor through m g of flesh. What is the temperature increase
     * of the flesh? Is it reasonable to assume no phase change?
     * @param volts the voltage
     * @param C the capacitance_Qv
     * @param m the mass
     * @param _c the specific heat
     * @return the temperature increase of the flesh
     */
    static ld temperatureChangeFromCapacitanceBurn(ld volts, ld C, ld m, ld _c , bool print = true);

    /**
     * @brief Calculates the kinetic energy of a positive charge.
     * @param q the positive charge
     * @param Vab the change in volts
     * @return the kinetic energy (J)
     */
    static ld kineticEnergyFinalToMovePositiveCharge(ld q, ld Vab, bool print = true);

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
     * @brief Calculate the work done to move a charge q C from a one point
     * with a potential of U1 V to a point with a potential of U2 V.
     * @param q  the charge (C)
     * @param U1  the potential at point 1 (V)
     * @param U2 the potential at point 2 (V)
     * @param print  true to print the answer
     * @return  the work done (J)
     */
    static ld workDoneMovingCharge(ld q, ld U1, ld U2, bool print = true);

    /**
     * @brief An uncharged capacitor has parallel plates s m on a side, spaced
     * d m apart. Calculate how much work is required to transfer Qa C from one
     * plate to the other and How much work is required to transfer an
     * additional Qb C.
     * @param s the side length of the capacitor (m)
     * @param d the distance between the plates (m)
     * @param Qa the charge on the capacitor (C)
     * @param Qb the additional charge to be added (C)
     * @param print true to print the answer
     * @return the work done (J)
     */
     static vector<ld> workToTransferCharge(ld s, ld d, ld Qa, ld Qb, bool print = true);

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

    /**
     * @brief Calculates the work done to assemble a configuration of charges
     * @tparam POINTCHARGE  the type of point charge
     * @param charges  the charges
     * @param print  true to print the answer
     * @return  the work done (J)
     */
    template<class POINTCHARGE>
    static ld workToAssembleChargeConfiguration(vector<POINTCHARGE> charges, bool print = true);

    /**
     * @brief Dielectric breakdown of air occurs at fields of E_break V/m.
     * Calculate the maximum potential (measured from infinity) for the sphere
     * of radius r m before dielectric breakdown occurs at the sphere's
     * surface.
     * @param r the radius of the sphere (m)
     * @param E_break the electric field strength at which dielectric breakdown
     * occurs (V/m)
     * @param print true to print the answer
     * @return the maximum potential (V)
     */
    static ld dielectricBreakdown(ld r, ld E_break, bool print = true);

    /**
     * @brief Dielectric breakdown of air occurs at fields of E_break V/m.
     * Calculate the charge on the sphere of radius r m before dielectric
     * breakdown occurs at the sphere's
     * surface.
     * @param r the radius of the sphere (m)
     * @param E_break the electric field strength at which dielectric breakdown
     * occurs (V/m)
     * @param print true to print the answer
     * @return the maximum potential (V)
     */
    static ld dielectricBreakdownCharge(ld r, ld E_break, bool print = true);

    /**
     * @brief Three equal charges q form an equilateral triangle of side a.
     * Find the potential, relative to infinity, at the center of the triangle.
     * @param q the charge (C)
     * @param a the side length (m)
     * @param print true to print the answer
     * @return the potential (V)
     */
    static ld potentialAtCenterOfEquilateralTriangle(ld q, ld a, bool print = true);

    /**
     * @brief Two identical charges q lie on the x axis at +/- a, at a height
     * of y above the x axis. Calculate the potential at all points in the
     * x-y plane.
     * @param q the charge (C)
     * @param a the distance from each side of the origin (m)
     * @param y the height above the x axis (m)
     * @param print true to print the answer
     * @return the potential (V)
     */
    static ld potentialAtAllPointsInXYP(ld q, ld a, ld y, bool print = true);

    /**
     * @brief An infinitely long line of charge has a linear charge density of
     * lambda C/m . A proton is at distance r m from the line has a mass of m kg
     * and is moving directly toward the line with speed v m/s. Calculate how
     * close the charge gets to the line of charge.
     * @param lambda the linear charge density (C/m)
     * @param r the distance from the line (m)
     * @param v the speed of the charge (m/s)
     * @param print true to print the answer
     * @return the distance from the line (m)
     */
    static ld distanceFromLineOfCharge(
            ld lambda, ld r, ld v, bool print = true);

    /**
     * @brief Calcualte the electric energy density of inside a capacitor
     * with an electric field of E V/m.
     * @param E the electric field strength (V/m)
     * @param print true to print the answer
     * @return the electric energy density (J/m^3)
     */
    static ld electricEnergyDensity(ld E, bool print = true);

    /**
     * @brief Typical electric fields in thunderstorms average around 10^5 V/m.
     * Consider a cylindrical thundercloud with height h m and diameter d m,
     * and assume a uniform electric field of E Find the electric energy
     * contained in this cloud.
     * @param h the height of the cloud (m)
     * @param d the diameter of the cloud (m)
     * @param E the electric field strength (V/m)
     * @param print true to print the answer
     */
    static ld electricEnergyInThundercloud(ld h, ld d, ld E, bool print = true);

    /**
     * @brief A sphere of radius Ri carries charge Q distributed uniformly over
     * its  surface. How much work does it take to compress the sphere to a smaller
     * radius of Rf?
     * @param Q the charge (C)
     * @param Ri the initial radius (m)
     * @param Rf the final radius (m)
     * @param print true to print the answer
     * @return the work done (J)
     */
    static ld workToCompressSphere(ld Q, ld Ri, ld Rf, bool print = true);

    /**
     * @brief Calculate the potential difference at point p from a distribution
     * of point charges.
     * @tparam POINTCHARGE
     * @param charges  the charges
     * @param p  the point
     * @param print  true to print the answer
     * @return  the potential difference (V)
     */
    template<typename POINTCHARGE>
    static ld potentialDueToChargeDistribution(
            vector<POINTCHARGE> charges,  const Vector2D& p, bool print = true);

    /**
     * @brief You measure an electrostatic energy density of uE J/m3 at a
     * distance of d m from a point charge. At dx m from the charge, calculate
     * the energy density.
     * @param uE the energy density (J/m^3)
     * @param d the distance from the charge (m)
     * @param dx the distance from the charge (m)
     * @param print true to print the answer
     * @return the energy density (J/m^3)
     */
    static ld energyDensityAtDistanceFromCharge(
            ld uE, ld d, ld dx, bool print = true);

    /**
     * @brief A cubical region of side L has one corner at the origin and the
     * opposite corner at x = y = z = L. It contains an electric field whose
     * magnitude increases with y: E(y) = E0 y/L. Calculate the
     * electrostatic energy contained in this region.
     * @param L the side length (m)
     * @param E0 the electric field strength at y = 0 (V/m)
     * @param print true to print the answer
     * @return the electrostatic energy (J)
     */
    static ld electrostaticEnergyInCubicalRegion(ld L, ld E0, bool print = true);

    /**
     * @brief Calculate the total electrostatic energy of a system consisting
     * of four point charges located at the corners of a square of side a.
     * Three of them carry charge +Q, while the fourth carries –Q/2.
     * @param a the side length (m)
     * @param Q the charge (C)
     * @param print true to print the answer
     * @return the electrostatic energy (J)
     */
    static ld electrostaticEnergyOfSquare(ld a, ld Q, bool print = true);

    /**
     * @brief Calculate the voltages compare across two wires both of length
     * L and diameter d, carrying the same current I. One wire has a
     * resistivity of rho1 and the other has a resistivity of rho2.
     * @param rho1 the resistivity of wire 1 (ohm-m)
     * @param rho2 the resistivity of wire 2 (ohm-m)
     * @param print true to print the answer
     * @return the voltage difference (V)
     */
    static ld voltageCompareAcross2Wires(ld rho1, ld rho2, bool print = true);

    /**
     * @brief Calculate the relationship between the diameters of two wires
     * that have the same resistance and length. One wire has a resistivity
     * of rho1 and the other has a resistivity of rho2.
     * @param rho1 the resistivity of wire 1 (ohm-m)
     * @param rho2 the resistivity of wire 2 (ohm-m)
     * @param print true to print the answer
     * @return the relationship between the diameters
     */
    static ld relationshipBetweenDiametersOf2Wires(
             ld rho1, ld rho2, bool print = true);

    /**
     * @brief A car battery stores about U J of energy. If this energy were
     * used to create a uniform E V/m electric field, what volume would it
     * occupy?
     * @param U the energy stored (J)
     * @param E the electric field strength (V/m)
     * @param print true to print the answer
     * @return the volume (m^3)
     */
    static ld volumeOfUniformElectricField(ld U, ld E, bool print = true);



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


inline ld ElectricPotential::electricalPotential_V(const ld PE, const ld q, bool print)
{
    auto var =  PE/q;
    if (print)
        std::cout << "V = " << var << " V" << std::endl;
    return var;
}

inline ld ElectricPotential::potentialEnergy_qV(
        const ld q, const ld volts, bool print)
{
    ld PE = q*volts;
    if (print)
        std::cout << "PE = " << PE << " J" << std::endl;
    return PE;
}

inline ld ElectricPotential::chargeMoved(const ld PE, const ld volts, bool print)
{
    auto var = PE / volts;
    if (print)
        std::cout << "q = " << var << " C" << std::endl;
    return var;
}

inline ld ElectricPotential::electronsPerSecond(const ld chargeMoved, bool print)
{
    auto var = chargeMoved/constants::ELECTRON_CHARGE;
    if (print)
        std::cout << "n = " << var << " electrons/s" << std::endl;
    return var;
}

inline ld ElectricPotential::electronVolts_eV(const ld volts, bool print)
{
    auto var = constants::eV * volts;
    if (print)
        std::cout << "eV = " << var << " eV" << std::endl;
    return var;
}

inline ld ElectricPotential::electronVoltsFromJoules(const ld j, bool print)
{
    auto var = j / constants::PROTON_CHARGE;
    if (print)
        std::cout << "eV = " << var << " eV" << std::endl;
    return var;
}

inline ld ElectricPotential::velocityFinal(const ld q, const ld volts, const ld m, bool print)
{
    auto var = sqrt((2.0 * q * volts) / m);
    if (print)
        std::cout << "v = " << var << " m/s" << std::endl;
    return var;
}

inline ld ElectricPotential::velocityFinal(const ld KE, const ld m, bool print)
{
    auto var = sqrt((2.0 * KE) / m);
    if (print)
        std::cout << "v = " << var << " m/s" << std::endl;
    return var;
}

inline ld ElectricPotential::voltageBetween2points_Vab(const ld E, const ld d, bool print)
{
    auto var = E * d;
    if (print)
        std::cout << "Vab = " << var << " V" << std::endl;
    return var;
}

inline ld ElectricPotential::electricFieldMagnitude(const ld volts, const ld d, bool print)
{
    auto var = volts / d;
    if (print)
        std::cout << "E = " << var << " V/m" << std::endl;
    return var;
}

inline ld ElectricPotential::electricField(
        const ld volts, const ld s, bool print)
{
    ld E = (volts / s);
    if (print)
        std::cout << "E = " << E << " V/m" << std::endl;
    return E;
}

inline ld ElectricPotential::voltsFromElectricFieldGradient(const ld E, const ld s, bool print)
{
    auto var = -E * s;
    if (print)
        std::cout << "V = " << var << " V" << std::endl;
    return var;
}

inline ld ElectricPotential::distanceOverChangeInVolts_s(const ld volts, const ld E, bool print)
{
    auto var = volts / E;
    if (print)
        std::cout << "s = " << var << " m" << std::endl;
    return var;
}

inline ld ElectricPotential::distancePointChargeToEqualVoltsOf(const ld Q,
                                                               const ld volts, bool print)
{
    auto var = (constants::K*Q) / volts;
    if (print)
        std::cout << "s = " << var << " m" << std::endl;
    return var;
}

inline ld ElectricPotential::electricPotential_pointCharge(const ld Q, const ld r, bool print)
{
    auto var = (constants::K * Q) / r;
    if (print)
        std::cout << "V = " << var << " V" << std::endl;
    return var;
}

inline ld ElectricPotential::excessCharge(const ld r, const ld volts, bool print)
{
    auto var = (r * volts) / constants::K;
    if (print)
        std::cout << "Q = " << var << " C" << std::endl;
    return var;
}

inline ld ElectricPotential::voltageNeededToObtainEnergy(const ld m,
                                                         const ld volts,
                                                         const ld q,
                                                         const ld numProtons, bool print)
{
    auto var = -(m * (volts * volts)) / (2.0 * (numProtons * q));
    if (print)
        std::cout << "V = " << var << " V" << std::endl;
    return var;
}

inline ld ElectricPotential::temperatureAvgKineticEnergyGasMolecule(
        const ld volts,
        const ld q = constants::PROTON_CHARGE, bool print)
{

    auto var = (2 * q * volts) / (3.0 * constants::STEFAN_BOLTZMANN);
    if (print)
        std::cout << "T = " << var << " K" << std::endl;
    return var;
}

inline ld ElectricPotential::voltageIonsMoveThroughToReachSameTemperature(
        const ld T, const ld q = constants::PROTON_CHARGE, bool print)
{
    auto var = (3.0/2.0)*((constants::STEFAN_BOLTZMANN * T) / q);
    if (print)
        std::cout << "V = " << var << " V" << std::endl;
    return var;
}


inline ld ElectricPotential::capacitance_Qv(ld Q, ld volts, bool print)
{
    auto var = Q / volts;
    if (print)
        std::cout << "C = " << var << " F" << std::endl;
    return var;
}

inline ld ElectricPotential::chargeStoredInCapacitor(ld C, ld volts, bool print)
{
    auto var = C * volts;
    if (print)
        std::cout << "Q = " << var << " C" << std::endl;
    return var;

}

inline ld ElectricPotential::voltageAcrossCapacitor(ld Q, ld C, bool print)
{
    auto var = Q/C;
    if (print)
        std::cout << "V = " << var << " V" << std::endl;
    return var;
}

inline ld ElectricPotential::capacitanceParallelPlate(
        const ld A, const ld d, bool print)
{
    auto C = constants::_e0 * (A / d);
    if (print)
        std::cout << "C = " << C << " F" << std::endl;
    return C;
}


inline ld ElectricPotential::capacitanceParallelPlateDielectric(const ld d_k, const ld A, const ld d, bool print)
{
    auto var = d_k * (constants::_e0 * A / d);
    if (print)
        std::cout << "C = " << var << " F" << std::endl;
    return var;
}

inline ld ElectricPotential::dielectricConstant(const ld E0, const ld E, bool print)
{
    auto var = E0/E;
    if (print)
        std::cout << "d_k = " << var << std::endl;
    return var;
}

inline ld ElectricPotential::capacitorEnergy_Ecap_QV(const ld Q, const ld volts, bool print)
{
    auto var = (Q * volts) / 2.0;
    if (print)
        std::cout << "E_cap = " << var << " J" << std::endl;
    return var;
}

inline ld ElectricPotential::capacitorEnergy_Ecap_CV(const ld C, const ld volts, bool print)
{
    auto var = (C*(volts * volts)) / 2.0;
    if (print)
        std::cout << "E_cap = " << var << " J" << std::endl;
    return var;
}

inline ld ElectricPotential::capacitorEnergy_Ecap_QC(const ld Q, const ld C, bool print)
{
    auto var = (Q*Q)/(2.0*C);
    if (print)
        std::cout << "E_cap = " << var << " J" << std::endl;
    return var;
}

inline ld ElectricPotential::potentialAcross_Ecap_CE(const ld C, const ld Ecap, bool print)
{
    auto var = sqrt((Ecap * 2.0) / C);
    if (print)
        std::cout << "V = " << var << " V" << std::endl;
    return var;
}


inline ld ElectricPotential::capacitorPlateArea(const ld C, const ld d, bool print)
{
    auto var = C * d / (constants::_e0);
    if (print)
        std::cout << "A = " << var << " m^2" << std::endl;
    return var;
}

inline ld ElectricPotential::capacitorPlateAreaDielectric(const ld C,
                                                          const ld d,
                                                          const ld k, bool print)
{
    auto var = (d * C) / (k * constants::_e0);
    if (print)
        std::cout << "A = " << var << " m^2" << std::endl;
    return var;
}

inline ld ElectricPotential::vMaxOnCapacitor(const ld dStrength, const ld d, bool print)
{
    auto var = dStrength * d;
    if (print)
        std::cout << "V_max = " << var << " V" << std::endl;
    return var;
}


inline ld ElectricPotential::maxChargeCanBeStoredCapacitor(const ld C,
                                                           const ld vMax, bool print)
{
    auto var = C * vMax;
    if (print)
        std::cout << "Q_max = " << var << " C" << std::endl;
    return var;
}

inline ld ElectricPotential::volumeOfDielectricMaterial(const ld A, const ld d, bool print)
{
    auto var = A * d;
    if (print)
        std::cout << "V = " << var << " m^3" << std::endl;
    return var;
}

inline ld ElectricPotential::electricFieldStrengthBetween2plates(
        const ld KE,
        const ld q,
        const ld d, bool print)
{
    auto var = KE/(q*d);
    if (print)
        std::cout << "E = " << var << " V/m" << std::endl;
    return var;
}

inline ld ElectricPotential::potentialNearSurfaceOfSphere(const ld d, const ld q, bool print)
{
    auto var = (2.0*constants::K * q)/d;
    if (print)
        std::cout << "V = " << var << " V" << std::endl;
    return var;
}

inline ld ElectricPotential::chargeOnSphere(const ld d, const ld volts, bool print)
{
    auto var = (d * volts) / (2.0 * constants::K);
    if (print)
        std::cout << "Q = " << var << " C" << std::endl;
    return var;
}

inline ld ElectricPotential::chargeOnPointToArriveWithSpeed(const ld m,
                                                            const ld velocity,
                                                            const ld volts, bool print)
{
    auto var = (m*(velocity * velocity)) / (2.0 * volts);
    if (print)
        std::cout << "Q = " << var << " C" << std::endl;
    return var;
}

inline ld ElectricPotential::temperatureChangeFromCapacitanceBurn(
        const ld volts,
        const ld C,
        const ld m,
        const ld _c_ = SHC.humanBodyAverageSolid.J_kgC, bool print)
{
    auto var = (C*(volts * volts)) / (2.0 * m * _c_);
    if (print)
        std::cout << "delta_T = " << var << " C" << std::endl;
    return var;
}

inline ld ElectricPotential::kineticEnergyFinalToMovePositiveCharge(
        const ld q, const ld Vab, bool print)
{
    auto var = -q * Vab;
    if (print)
        std::cout << "KE = " << var << " J" << std::endl;
    return var;
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

ld ElectricPotential::workDoneMovingCharge(ld q, ld U1, ld U2, bool print) {
    // check if any of the points are at infinity and if they are, set them to 0
    if (U1 == std::numeric_limits<ld>::infinity() || U1 == INFINITY) {
        U1 = 0;
        cout << "U1 is at infinity, setting to 0" << endl;
    }
    if (U2 == std::numeric_limits<ld>::infinity() || U2 == INFINITY) {
        U2 = 0;
        cout << "U2 is at infinity, setting to 0" << endl;
    }
    auto W = q * (U1 - U2);
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

template<class POINTCHARGE>
ld ElectricPotential::workToAssembleChargeConfiguration(
        vector<POINTCHARGE> charges, bool print) {
    static_assert(std::is_same<POINTCHARGE, pc2d>::value ||
                  std::is_same<POINTCHARGE, pc3d>::value,
                  "POINTCHARGE must be either pc2d or pc3d");
    // check if the charges are in 2d or 3d
    bool is2d = true;
    for (auto &charge : charges) {
        if (charge.position.getZ() != 0) {
            is2d = false;
            break;
        }
    }
    // calculate the work which is k*Q1*Q2/r
    ld work = 0;
    for (int i = 0; i < charges.size(); i++) {
        for (int j = i + 1; j < charges.size(); j++) {
            ld r = 0;
            if (is2d) {
                r = sqrt(pow(charges[i].position.getX() -
                        charges[j].position.getX(), 2) +
                         pow(charges[i].position.getY() -
                         charges[j].position.getY(), 2));
            } else {
                r = sqrt(pow(charges[i].position.getX() -
                        charges[j].position.getX(), 2) +
                         pow(charges[i].position.getY() -
                         charges[j].position.getY(), 2) +
                         pow(charges[i].position.getZ() -
                         charges[j].position.getZ(), 2));
            }
            work += constants::K * charges[i].q * charges[j].q / r;
        }
    }
    if (print) {
        std::cout << "W = " << work << " J" << std::endl;
    }
    return work;
}

ld ElectricPotential::dielectricBreakdown(ld r, ld E_break, bool print) {
    ld V_break = E_break * r;
    if (print) {
        std::cout << "V_break = " << V_break << " V" << std::endl;
    }
    return V_break;
}

ld ElectricPotential::dielectricBreakdownCharge(ld r, ld E_break, bool print) {
    auto k = constants::K;
    ld charge = (E_break * r * r) / k;
    if (print) {
        std::cout << "Charge on sphere = " << charge << " C" << std::endl;
    }
    return charge;
}

ld ElectricPotential::potentialAtCenterOfEquilateralTriangle(
        ld q, ld a, bool print) {
    auto k = constants::K;
    auto V = (k*3.0* sqrt(3) * q)/a;
    if (print) {
        std::cout << "V = " << V << " V" << std::endl;
    }
    return V;
}

ld ElectricPotential::potentialAtAllPointsInXYP(ld q, ld a, ld y, bool print) {
    auto k = constants::K;
    auto Va = (k * q) / (sqrt(pow(a, 2) + pow(y, 2)));
    auto Vb = (k * q) / (sqrt(pow(a, 2) + pow(y - a, 2)));
    auto Vtotal = Va + Vb;
    if (print) {
        std::cout << "Vtotal = " << Vtotal << " V" << std::endl;
    }
    return Vtotal;
}

ld
ElectricPotential::distanceFromLineOfCharge(
        ld lambda, ld r, ld v, bool print) {
    auto m = constants::PROTON_MASS;
    auto q = constants::PROTON_CHARGE;
    auto KE = 0.5 * m * pow(v, 2);
    auto e0 = constants::_e0;
    auto pi_ = constants::PI;
    auto lnR2R1 = (KE * 2.0 * pi_ * e0) / (lambda * q);
    auto r2 = r / exp(lnR2R1);
    if (print) {
        std::cout << "r2 = " << r2 << " m" << std::endl;
    }
    return r2;
}

ld ElectricPotential::capacitanceRoundParallelPlate(ld R, ld d, bool print) {
    auto e0 = constants::_e0;
    auto pi_ = constants::PI;
    auto C = (2.0 * e0 * pi_ * R * R) / d;
    if (print) {
        std::cout << "C = " << C << " F" << std::endl;
    }
    return C;
}

ld ElectricPotential::electricEnergyDensity(ld E, bool print) {
    auto e0 = constants::_e0;
    auto U = 0.5 * e0 * E * E;
    if (print) {
        std::cout << "U = " << U << " J/m^3" << std::endl;
    }
    return U;
}

ld
ElectricPotential::electricEnergyInThundercloud(ld h, ld d, ld E, bool print) {
    auto e0 = constants::_e0;
    auto pi = constants::PI;
    auto U_e = electricEnergyDensity(E, false);
    // a cylindric cloud has volume pi * r^2 * h
    auto V = pi * pow(d/2.0, 2) * h;
    // multiple energy density by volume to get total energy stored
    auto U = U_e * V;
    if (print) {
        std::cout << "U = " << U << " J" << std::endl;
    }
    return U;
}

ld ElectricPotential::workToCompressSphere(ld Q, ld Ri, ld Rf, bool print) {
    auto k = constants::K;
    auto W = k * Q * Q * (1.0 / Rf - 1.0 / Ri);
    if (print) {
        std::cout << "W = " << W << " J" << std::endl;
    }
    return W;
}

template<typename POINTCHARGE>
ld ElectricPotential::potentialDueToChargeDistribution(
        vector<POINTCHARGE> charges, const Vector2D& p, bool print) {
    auto k = constants::K;
    ld V = 0;
    for (auto charge : charges) {
        ld r = sqrt(pow(charge.position.getX() - p.getX(), 2) +
                    pow(charge.position.getY() - p.getY(), 2));
        V += k * charge.q / r;
    }
    if (print) {
        std::cout << "V = " << V << " V" << std::endl;
    }
    return V;
}

ld ElectricPotential::energyDensityAtDistanceFromCharge(
        ld uE, ld d, ld dx, bool print) {
    auto pi = constants::PI;
    auto e0 = constants::_e0;
    auto U = (uE*uE)/(32.0*(pi*pi)*e0*pow(dx, 4));
    if (print) {
        std::cout << "U = " << U << " J/m^3" << std::endl;
    }
    return U;
}

ld
ElectricPotential::electrostaticEnergyInCubicalRegion(ld L, ld E0, bool print) {
    auto e0 = constants::_e0;
    auto U = (e0 * E0 * E0 * L * L * L) / 6.0;
    if (print) {
        std::cout << "U = " << U << " J" << std::endl;
    }
    return U;
}

ld ElectricPotential::electrostaticEnergyOfSquare(ld a, ld Q, bool print) {
    auto k = constants::K;
    auto U = ((k * Q * Q) / a) *(1.0 + (sqrt(2.0) / 4.0));
    if (print) {
        std::cout << "U = " << U << " J" << std::endl;
    }
    return U;
}

ld ElectricPotential::voltageCompareAcross2Wires(ld rho1, ld rho2, bool print) {
    auto V = rho2 / rho1;
    if (print) {
        std::cout << "V = " << V << " V" << std::endl;
    }
    return V;
}

ld ElectricPotential::relationshipBetweenDiametersOf2Wires(ld rho1, ld rho2,
                                                           bool print) {
    auto d2 = sqrt(rho2 / rho1);
    if (print) {
        std::cout << "d2 = " << d2 << " m" << std::endl;
    }
    return d2;
}

vector<ld>
ElectricPotential::workToTransferCharge(ld s, ld d, ld Qa, ld Qb, bool print) {
    auto e0 = constants::_e0;
    auto w_a = (Qa * Qa * d) / (2.0 * e0 * s*s);
    auto w_b = (((Qb+Qa) * (Qb+Qa) * d) / (2.0 * e0 * s*s)) - w_a;
    if (print) {
        std::cout << "w_a = " << w_a << " J" << std::endl;
        std::cout << "w_b = " << w_b << " J" << std::endl;
    }
    return {w_a, w_b};
}

vector<ld> ElectricPotential::chargeMoved(ld Eu, ld s, ld d, bool print) {
    auto e0 = constants::_e0;
    auto Q = sqrt((2.0 * e0 * s * s * Eu) / d);
    auto V = (2.0 * Eu) / Q;
    if (print) {
        std::cout << "Q = " << Q << " C" << std::endl;
    }
    return {Q, V};
}

ld ElectricPotential::capacitorPlateArea_QVd(ld Q, ld V, ld d, bool print) {
    auto e0 = constants::_e0;
    auto A = (Q * d) / (e0 * V);
    if (print) {
        std::cout << "A = " << A << " m^2" << std::endl;
    }
    return A;
}

ld ElectricPotential::capacitance_Ev(ld E, ld V, bool print) {
    auto C = (2.0 * E) / (V * V);
    if (print) {
        std::cout << "C = " << C << " F" << std::endl;
    }
    return C;
}

std::vector<ld>
ElectricPotential::maxMinAndIntermediateCapacitances(ld C1, ld C2, ld C3,
                                                     bool print) {
    auto cmin = 1.0 / (1.0 / C1 + 1.0 / C2 + 1.0 / C3);
    auto cmax = C1 + C2 + C3;
    // find the intermediate capacitance by using combinations of series and parallel
    auto cint = (C1 * C2) / (C1 + C2) + C3;
    auto cint2 = (C1 * C3) / (C1 + C3) + C2;
    auto cint3 = (C2 * C3) / (C2 + C3) + C1;
    auto cTemp1 = C2 + C3;
    auto cint4 = (C1 * cTemp1) / (C1 + cTemp1);
    auto cTemp2 = C1 + C3;
    auto cint5 = (C2 * cTemp2) / (C2 + cTemp2);
    auto cTemp3 = C1 + C2;
    auto cint6 = (C3 * cTemp3) / (C3 + cTemp3);
    if (print) {
        std::cout << "cmin = " << cmin << " F" << std::endl;
        std::cout << "cmax = " << cmax << " F" << std::endl;
        std::cout << "cint = " << cint << " F" << std::endl;
        std::cout << "cint2 = " << cint2 << " F" << std::endl;
        std::cout << "cint3 = " << cint3 << " F" << std::endl;
        std::cout << "cint4 = " << cint4 << " F" << std::endl;
        std::cout << "cint5 = " << cint5 << " F" << std::endl;
        std::cout << "cint6 = " << cint6 << " F" << std::endl;
    }
    return {cmin, cmax, cint, cint2, cint3, cint4, cint5, cint6};
}

ld ElectricPotential::volumeOfUniformElectricField(ld U, ld E, bool print) {
    auto e0 = constants::_e0;
    auto V = (2.0 * U) / (e0 * (E * E));
    if (print) {
        std::cout << "V = " << V << " m^3" << std::endl;
    }
    return V;
}
