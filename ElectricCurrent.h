//
// Created by Ryan.Zurrin001 on 12/15/2021.
//

#ifndef PHYSICSFORMULA_ELECTRICCURRENT_H
#define PHYSICSFORMULA_ELECTRICCURRENT_H
#pragma once
/**
 * @class ElectricCurrent
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @dateBuilt  12/31/2020
 * @lastEdit 12/31/2020
 */
#include "ElectricPotential.h"


#include <iostream>

//#include "Circuits.h"

[[maybe_unused]] static struct Resistivities
{
    const ld SILVER = 1.59 * pow(10, -8); //1.59e-8 conductor, OHm*m
    const ld COPPER = 1.72 * pow(10, -8); //1.72e-8 conductor, OHm*m
    const ld GOLD = 2.44 * pow(10, -8); //2.44e-8 conductor, OHm*m
    const ld ALUMINUM = 2.65 * pow(10, -8); //conductor, OHm*m
    const ld TUNGSTEN = 5.6 * pow(10, -8); //conductor, OHm*m
    const ld IRON = 9.71 * pow(10, -8); //conductor, OHm*m
    const ld PLATINUM = 10.6 * pow(10, -8); //conductor, OHm*m
    const ld STEEL = 20.0 * pow(10, -8); //conductor, OHm*m
    const ld LEAD = 22.0 * pow(10, -8); //conductor, OHm*m
    const ld MANGANIN = 44.0 * pow(10, -8); //conductor, OHm*m
    const ld CONSTANTAN = 49.0 * pow(10, -8); //conductor, OHm*m
    const ld MERCURY = 96.0 * pow(10, -8); //conductor, OHm*m
    const ld NICHROME = 100.0 * pow(10, -8); //conductor, OHm*m

    const ld CARBON_PURE = 3.5 * pow(10, 5); //semiconductor, OHm*m
    /// <summary>
    /// The CARBON variable can be between 3.5 and 60 * 10^5 OHm*m. there is a
    /// setCARBON method you can use to adjust its value. Its not checked so if you
    /// put in a invalid number its on you, your calculation will be wrong. In the
    /// argument only pass the first part, example 18.7. not 18.7*10^5. that gets added
    /// automatically.
    /// </summary>
    ld CARBON = 10 * pow(10, 5); //semiconductor, OHm*m
    /// <summary>
    /// Sets the carbon variable.
    /// </summary>
    /// <param name="value">The value passed should be between 3.5 and 60.</param>
    void setCARBON(ld value) { CARBON = value * pow(10, 5); }

    const ld GERMANIUM_PURE = 600.0 * pow(10, -3); //semiconductor, OHm*m
    /// <summary>
    /// The GERMANIUM variable can be between 1 and 600 * 10^5 OHm*m. there is a
    /// setGERMANIUM method you can use to adjust its value. Its not checked so if you
    /// put in a invalid number its on you, your calculation will be wrong. In the
    /// argument only pass the first part, example 18.7. not 18.7*10^-3. that gets added
    /// automatically.
    /// </summary>
    ld GERMANIUM = 300 * pow(10, -3); //semiconductor, OHm*m
    /// <summary>
    /// Sets the GERMANIUM variable.
    /// </summary>
    /// <param name="value">The value passed should be between 1 and 600.</param>
    void setGERMANIUM(ld value) { GERMANIUM = value * pow(10, -3); }

    const ld SILICON_PURE = 2300; //2300semiconductor, OHm*m
    /// <summary>
    /// The SILICON variable can be between .1 and 2300 OHm*m. there is a
    /// setSILICON method you can use to adjust its value. Its not checked so if you
    /// put in a invalid number its on you, your calculation will be wrong.
    /// </summary>
    ld SILICON = .1; // .1 - 2300 semiconductor, OHm*m
    /// <summary>
    /// Sets the Silicon variable.
    /// </summary>
    /// <param name="value">The value passed should be between .1 and 2299.</param>
    void setSILICON(ld value) { SILICON = value * pow(10, -3); }

    const ld AMBER = 5.0 * pow(10, 14); // insulator, OHm*m

    /// <summary>
    /// The GLASS variable can be between 10^9 and 10^14 OHm*m. there is a
    /// setGLASS method you can use to adjust its value. Its not checked so if you
    /// put in a invalid number its on you, your calculation will be wrong.
    /// </summary>
    ld GLASS = pow(10,9); //semiconductor, OHm*m
    /// <summary>
    /// Sets the GLASS variable.
    /// </summary>
    /// <param name="value">The value passed should be between 10^9 - 10^14.</param>
    void setGLASS(ld value) { GLASS = pow(10, value); }

    /// <summary>
    /// The WOOD variable can be between 10^8 and 10^11 OHm*m. there is a
    /// setWOOD method you can use to adjust its value of the power. Its not checked so if you
    /// put in a invalid number its on you, your calculation will be wrong.
    /// </summary>
    ld WOOD = pow(10, 9); // 10^X conductor, OHm*m
    /// <summary>
    /// Sets the GLASS variable.
    /// </summary>
    /// <param name="value">The value passed should be between 10^9 - 10^14.</param>
    void setWOOD(ld X) { GLASS = pow(10, X); }


}resistivity;


static struct TemperatureCoefficientsOfResistivity
{
    const ld SILVER = 3.8 * pow(10, -3); //3.8e-3 1/C
    const ld COPPER = 3.9 * pow(10, -3); //3.9e-3 1/C
    const ld GOLD = 3.4 * pow(10, -3); //3.4e-3 1/C
    const ld ALUMINUM = 3.9 * pow(10, -3); //3.9e-3 1/C
    const ld TUNGSTEN = 4.5 * pow(10, -3); //4.5e-3 1/C
    const ld IRON = 5.0 * pow(10, -3); //5.0e-3 1/C
    const ld PLATINUM = 3.93 * pow(10, -3); //3.93e-3 1/C
    const ld LEAD = 3.9 * pow(10, -3); //3.9e-3 1/C
    const ld MANGANIN = .000 * pow(10, -3); //.0000e-3 1/C
    const ld CONSTANTAN = 0.002 * pow(10, -3); //.002e-3 1/C
    const ld MERCURY = .89 * pow(10, -3); //.89e-3 1/C
    const ld NICHROME = .4 * pow(10, -3); //.4e-3 1/C
    const ld CARBON = -.5 * pow(10, -3); //-.5e-3 1/C
    const ld GERMANIUM = -50 * pow(10, -3); //-50e-3 1/C
    const ld SILCONE = -70 * pow(10, -3); //-70e-3 1/C

}tempCoefResistivity;

static struct AWGWireSizesByGauge
{
    const ld AWG0000 = 11.6840*pow(10, -3);// 11.6840mm diameter
    const ld AWG000 = 10.4038*pow(10, -3);// 10.4038mm diameter
    const ld AWG00 = 9.2659*pow(10, -3);// 9.2659mm diameter
    const ld AWG0 = 8.2525*pow(10, -3);// 8.2525mm diameter
    const ld AWG1 = 7.3482*pow(10, -3);// 7.3482mm diameter
    const ld AWG2 = 6.5430*pow(10, -3);// 6.5430mm diameter
    const ld AWG3 = 5.8268*pow(10, -3);// 5.8268mm diameter
    const ld AWG4 = 5.1892*pow(10, -3);// 5.1892mm diameter
    const ld AWG5 = 4.6203*pow(10, -3);// 4.6203mm diameter
    const ld AWG6 = 4.1148*pow(10, -3);// 4.1148mm diameter
    const ld AWG7 = 3.6652*pow(10, -3);// 3.6652mm diameter
    const ld AWG8 = 3.2639*pow(10, -3);// 3.2639mm diameter
    const ld AWG9 = 2.9058*pow(10, -3);// 2.9058mm diameter
    const ld AWG10 = 2.5883*pow(10, -3);// 2.5883mm diameter
    const ld AWG11 = 2.3038*pow(10, -3);// 2.3038mm diameter
    const ld AWG12 = 2.0523*pow(10, -3);// 2.0523mm diameter
    const ld AWG13 = 1.8288*pow(10, -3);// 1.8288mm diameter
    const ld AWG14 = 1.6281*pow(10, -3);// 1.6281mm diameter
    const ld AWG15 = 1.4503*pow(10, -3);// 1.4503mm diameter
    const ld AWG16 = 1.2903*pow(10, -3);// 1.2903mm diameter
    const ld AWG17 = 1.1506*pow(10, -3);// 1.1506mm diameter
    const ld AWG18 = 1.0236*pow(10, -3);// 1.0236mm diameter
    const ld AWG19 = 0.9119*pow(10, -3);// 0.9119mm diameter
    const ld AWG20 = 0.8128*pow(10, -3);// 0.8128mm diameter
    const ld AWG21 = 0.7239*pow(10, -3);// 0.7239mm diameter
    const ld AWG22 = 0.6452*pow(10, -3);// 0.6452mm diameter
    const ld AWG23 = 0.5740*pow(10, -3);// 0.5740mm diameter
    const ld AWG24 = 0.5105*pow(10, -3);// 0.5105mm diameter
    const ld AWG25 = 0.4547*pow(10, -3);// 0.4547mm diameter
}AWG;

//static object counter for ElectricCurrent class
static int electricCurrent_objectCount = 0;


class ElectricCurrent
{
public:
    ElectricCurrent* _electricCurrentPtr;


    ElectricCurrent()
    {
        _electricCurrentPtr = nullptr;
        _electricCurrentVal = 0.0;
        countIncrease();
        //cout << "in electicCurrent count: " << electricCurrent_objectCount << endl;
    }

    ElectricCurrent(ld val)
    {
        _electricCurrentPtr = nullptr;
        _electricCurrentVal = 0.0;
        countIncrease();

    }

    /**
     * @brief copy constructor
     */
    ElectricCurrent(const ElectricCurrent& t)
    {
        _electricCurrentPtr = t._electricCurrentPtr;
        _electricCurrentVal = t._electricCurrentVal;
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    ElectricCurrent(ElectricCurrent&& t) noexcept
    {
        _electricCurrentPtr = t._electricCurrentPtr;
        _electricCurrentVal = t._electricCurrentVal;
        countIncrease();
    }
    /**
     * @brief copy assignment operator
     */
    ElectricCurrent& operator=(const ElectricCurrent& t)
    {
        if (this != &t)
        {
            _electricCurrentPtr = t._electricCurrentPtr;
            _electricCurrentVal = t._electricCurrentVal;
            countIncrease();
        }
        return *this;
    }

    static void show_objectCount() { std::cout << "\n electric current object count: " << electricCurrent_objectCount << std::endl; }
    static int get_objectCount() { return electricCurrent_objectCount; }


    /// <summary>
    /// calculates the area using the radius.
    /// </summary>
    /// <param name="r">The radius.</param>
    /// <returns>area(m^2)</returns>
    static ld area_r(const ld r);

    /// <summary>
    /// Calculates the area from the diameter
    /// </summary>
    /// <param name="d">The diameter.</param>
    /// <returns>area(m^2)</returns>
    static ld area_d(const ld d);

    /// <summary>
    /// calculates the electric current (I) defined as the rate at which charge
    /// (Q) flows through a given time (t).
    /// </summary>
    /// <param name="Q">The change in current.</param>
    /// <param name="t">The time over which current passes through.</param>
    /// <returns>the electric current SI unit of ampere (A)</returns>
    static ld electricCurrent(const ld Q, const ld t);

    /// <summary>
    /// Times it takes charge Q to flow through a current of I amperes
    /// </summary>
    /// <param name="Q">The charge.</param>
    /// <param name="I">The current.</param>
    /// <returns>time in seconds</returns>
    static ld timeItTakesChargeToFlow(const ld Q, const ld I);

    /// <summary>
    /// Calculates the Electrics  charge Q
    /// </summary>
    /// <param name="I">The current.</param>
    /// <param name="t">The time in seconds.</param>
    /// <returns>the charge in coulombs</returns>
    static ld electricCharge(const ld I, const ld t);

    /// <summary>
    /// Calculates the current (I) using the number of free charges(n) per unit
    /// volume (Ax) where the charge per n is given by q and t is the unit time.
    /// I = (q * n * Ax) / t;
    /// </summary>
    /// <param name="q">The charge.</param>
    /// <param name="n">The number of free charges.</param>
    /// <param name="Ax">The volume of segment Ax is the area * distance
    /// where for a circle would be pi*r^2 * x where x is the length.</param>
    /// <param name="t">The unit time the charge is moved over.</param>
    /// <returns>The current</returns>
    static ld current_qnAx_t(const ld q, const ld n, const ld Ax, const ld t);

    /// <summary>
    /// Calculates the current (I) using the number of free charges(n) per unit
    /// volume(A) each carrying a charge of q with a drift velocity of vd.
    /// </summary>
    /// <param name="n">The number of free charges.</param>
    /// <param name="q">The charge on each.</param>
    /// <param name="A">the area.</param>
    /// <param name="vd">The drift velocity.</param>
    /// <returns>the current</returns>
    static ld current_nqAvd(const ld n, const ld q, const ld A, const ld vd);

    /// <summary>
    /// Calculates the currents using ohms law of voltage over resistances.
    /// </summary>
    /// <param name="V">The voltage.</param>
    /// <param name="R">The resistance.</param>
    /// <returns>current in Amperes</returns>
    static ld current_ohms(const ld V, const ld R);

    /// <summary>
    /// Calculates the current from rearranging the power equations
    /// </summary>
    /// <param name="P">The power in watts.</param>
    /// <param name="R">The resistance.</param>
    /// <returns>the current in amperes(I)</returns>
    static ld current_fromPowerEq(const ld P, const ld R);

    /// <summary>
    /// Calculates the currents from power and volts.
    /// </summary>
    /// <param name="P">The power in watts.</param>
    /// <param name="V">The volts.</param>
    /// <returns></returns>
    static ld current_fromPowerAndVolts(const ld P, const ld V);

    /// <summary>
    /// calculates the resistances of an ohmic conducting material
    /// </summary>
    /// <param name="V">The volts.</param>
    /// <param name="I">The current (A).</param>
    /// <returns>(V/A)one volt per Ampere</returns>
    static ld resistance_ohmic(const ld V, const ld I);

    /// <summary>
    /// Calculates the resistance of resistor with a resistivity of p and a
    /// length of l with a area of A(pir^2, in a circular resistor).
    /// </summary>
    /// <param name="p">The resistivity.</param>
    /// <param name="l">The length.</param>
    /// <param name="A">The cross sectional area.</param>
    /// <returns>Resistance Ohms</returns>
    static ld resistanceUsingResistivity(const ld p, const ld l, const ld A);

    /// <summary>
    /// calculates the resistance of a piece of wire with a length of l,
    /// having a diameter of d and a resistivity of p, which depends on the
    /// material its made from. copper is a p = 1.72e-8 Ohms/m
    /// </summary>
    /// <param name="p">The resistivity.</param>
    /// <param name="l">The length.</param>
    /// <param name="d">The diameter.</param>
    /// <returns>the resistance in Ohms</returns>
    static ld resistanceUsingResistivityWire(const ld p, const ld l, const ld d);

    /// <summary>
    /// calculates the cross sectional areas the of a resistor.
    /// </summary>
    /// <param name="p">The resistivity.</param>
    /// <param name="R">The Resistance.</param>
    /// <param name="l">The length.</param>
    /// <returns>area of resistor (m^2)</returns>
    static ld areaOfResistor(const ld p, const ld R, const ld l);

    /// <summary>
    /// Calculates the length of a resistor.
    /// </summary>
    /// <param name="A">the cross sectional area.</param>
    /// <param name="R">The resistance.</param>
    /// <param name="p">The resistivity.</param>
    /// <returns>the length of resistor (m)</returns>
    static ld lengthOfResistor(const ld A, const ld R, const ld p);


    /// <summary>
    /// Calculates the Lengths of filament.
    /// </summary>
    /// <param name="d">The diameter.</param>
    /// <param name="R">The resistance.</param>
    /// <param name="p">The resistivity.</param>
    /// <returns></returns>
    static ld lengthOfFilament(const ld d, const ld R, const ld p);

    /// <summary>
    /// As part of a class project you are given m g of copper and asked
    /// to fabricate a wire with uniform cross-section. You use up 95% of the
    /// copper and make a wire with a resistance of 0.800 Ω. The resistivity
    /// of copper is 1.72 10-8 Ω · m and its density is 8.92 103 kg/m3
    /// </summary>
    /// <param name="m">The mass.</param>
    /// <param name="R">The resistance.</param>
    /// <param name="p">The resistivity.</param>
    /// <param name="pd">The density.</param>
    /// <returns>length of wire</returns>
    static ld lengthOfWireMade(const ld m, const ld R, const ld p, const ld pd);

    /// <summary>
    /// Calculates the resistivity of a resistor.
    /// </summary>
    /// <param name="R">The resistance.</param>
    /// <param name="A">area.</param>
    /// <param name="l">The length.</param>
    /// <returns></returns>
    static ld resistivityOfResistor(const ld R, const ld A, const ld l);

    /// <summary>
    /// Of what material is a wire made, if it is a length of (l)m long with a
    ///(d)m diameter and has a resistance of R ohms at 20.0∘C
    /// </summary>
    /// <param name="l">The length.</param>
    /// <param name="d">The diameter.</param>
    /// <param name="R">The resistance.</param>
    /// <returns>Ohm m</returns>
    static ld resistivity(const ld l, const ld d, const ld R);

    /// <summary>
    /// Calculates the voltages drop across a resistor.
    /// </summary>
    /// <param name="I">The current (Amperes).</param>
    /// <param name="R">The resistance.</param>
    /// <returns>The voltage</returns>
    static ld voltageDropAcrossResistor(const ld I, const ld R);

    /// <summary>
    /// Calculates the drifts the velocity (V_d) of a common wire.
    /// </summary>
    /// <param name="q">The charge.</param>
    /// <param name="diameter">The diameter.</param>
    /// <param name="I">The current (Amperes).</param>
    /// <param name="p">The density per kg/m^3.</param>
    /// <param name="mass">The atomic mass.</param>
    /// <returns>drift velocity m/s</returns>
    static ld driftVelocity_commonWire(const ld q, const ld diameter, const ld I, const ld p, const ld mass);

    /// <summary>
    /// Drifts the velocity common wire n.
    /// </summary>
    /// <param name="n">The number of electrons per cubic meter.</param>
    /// <param name="q">The charge.</param>
    /// <param name="diameter">The diameter.</param>
    /// <param name="I">The current.</param>
    /// <returns>drift velocity m/s</returns>
    static ld driftVelocity_commonWire_n(const ld n, const ld q, const ld diameter, const ld I);

    /// <summary>
    /// Calculates the crosses sectional area
    /// </summary>
    /// <param name="p">The resistivity.</param>
    /// <param name="l">The length.</param>
    /// <param name="R">The resistance.</param>
    /// <returns>cross sectional area (m^2)</returns>
    static ld crossSectionalArea(const ld p, const ld l, const ld R);

    /// <summary>
    /// Calculates the change in resistances from the effects of a
    /// change in temperature.
    /// </summary>
    /// <param name="R0">The initial cold resistance</param>
    /// <param name="tCoR">The temperature coefficients of resistivity.</param>
    /// <param name="tempChange">The change in the temperature.</param>
    /// <returns>the new resistance in Ohms</returns>
    static ld resistanceChangeFromTemperature(const ld R0, const ld tCoR, const ld tempChange);



    /// <summary>
    /// calculates the electrical power from current and volts
    /// </summary>
    /// <param name="I">The current.</param>
    /// <param name="V">The volts.</param>
    /// <returns>energy from electrical(W)</returns>
    static ld electricalPowerAndEnergy_IV(const ld I, const ld V);

    /// <summary>
    /// calculates the electrical power from volts and resistance
    /// </summary>
    /// <param name="V">The volts.</param>
    /// <param name="R">The resistance.</param>
    /// <returns>energy from electrical (W)</returns>
    static ld electricalPowerAndEnergy_V2R(const ld V, const ld R);

    /// <summary>
    /// Some makes of older cars have 6.00-V electrical systems. (a) What is
    /// the hot resistance of a 30.0-W headlight in such a car?
    /// </summary>
    /// <param name="P">The power.</param>
    /// <param name="V">The volts.</param>
    /// <returns>resistance</returns>
    static ld resistanceFromPowerAndVolts(const ld P, const ld V);

    /// <summary>
    /// Calculates the resistance from power and current.
    /// </summary>
    /// <param name="P">The power.</param>
    /// <param name="I">The current.</param>
    /// <returns>Ohms</returns>
    static ld resistanceFromPowerAndCurrent(const ld P, const ld I);

    /// <summary>
    /// calculates the electrical power from current and resistance
    /// </summary>
    /// <param name="I">The current.</param>
    /// <param name="R">The resistance.</param>
    /// <returns>energy from electrical (W)</returns>
    static ld electricalPowerAndEnergy_I2R(const ld I, const ld R);

    /// <summary>
    /// A charge of (Q) C of charge passes through a pocket calculator’s solar
    /// cells in t seconds. What is the power output, given the calculator’s
    /// voltage output is a voltage of V.
    /// </summary>
    /// <param name="Q">The charge.</param>
    /// <param name="t">The time.</param>
    /// <param name="V">The voltage.</param>
    /// <returns>the watts</returns>
    static ld powerOutputOverTime(const ld Q, const ld t, const ld V);

    /// <summary>
    /// Calculates the total electrons  that pass through a charge.
    /// </summary>
    /// <param name="Q">The charge in coulombs.</param>
    /// <returns>Ne, number of electrons</returns>
    static ld electronsThatPassThroughACharge(const ld Q);

    /// <summary>
    /// If a large cyclotron directs a beam of freeProtons nuclei onto a target
    /// with a beam current of I Amperes. Calculate How many nuclei per second
    /// this is.
    /// </summary>
    /// <param name="I">The current.</param>
    /// <param name="freeProtons">The number of free protons.</param>
    /// <returns>nuclei/second</returns>
    static ld nucleiPerSecond(const ld I, const ld freeProtons);

    /// <summary>
    /// Calculates the ratio of the resistivity of wire1 to that of wire2, if they have
    /// the same resistance per unit length (as they might in household wiring)
    /// </summary>
    /// <param name="p1">The the bigger resistivity.</param>
    /// <param name="p2">The smaller resistivity.</param>
    /// <returns>the ratio meaning the size of the smaller resistivity value will
    /// to by this value bigger</returns>
    static ld ratioOfDiametersInWires(const ld p1, const ld p2);

    /// <summary>
    /// Calculates the current flows through a diameter of (d) rod with a
    /// resistivity of (p) that is a length of (l)m long, when (V) voltage is
    /// applied to it? (Such a rod may be used to make nuclear- particle
    /// detectors, for example.)
    /// </summary>
    /// <param name="V">The applied voltage.</param>
    /// <param name="p">The resistivity.</param>
    /// <param name="d">The diameter.</param>
    /// <param name="l">The length.</param>
    /// <returns>the Amperes</returns>
    static ld currentFlowThroughOfMaterial(const ld V, const ld p, const ld d, const ld l);

    /// <summary>
    /// A resistor made of Nichrome wire is used in an application where its
    /// resistance cannot change more than 1.00% from its value at 20.0∘C .
    /// Over what temperature range can it be used?
    /// </summary>
    /// <param name="tempCoEffOfResistivity">The temperature coefficient of resistivity.</param>
    /// <param name="maxChangePercent">The maximum change percent.</param>
    /// <returns>temperature</returns>
    static ld maximumTempchange(const ld tempCoEffOfResistivity, const ld maxChangePercent);

    /// <summary>
    /// With a 1200-W toaster, how much electrical energy is needed to make a
    /// slice of toast (cooking time = 1 minute)? At 9.0 cents/kW⋅h, how much does this cost?.
    /// </summary>
    /// <param name="P">The power inWatts.</param>
    /// <param name="t">The time in seconds.</param>
    /// <param name="ratePerKwh">The rate per KWH.</param>
    /// <returns>total cost to use electricity</returns>
    static ld costOfElectricityUsed_kWh(const ld P, const ld t, const ld ratePerKwh);

    /// <summary>
    /// An old light bulb draws only 50.0 W, rather than its original 60.0 W,
    /// due to evaporative thinning of its filament. By what factor is its
    /// diameter reduced, assuming uniform thinning along its length? Neglect
    /// any effects caused by temperature differences.
    /// </summary>
    /// <param name="Pi">The starting wattage.</param>
    /// <param name="Pf">The final wattage.</param>
    /// <returns>factor which diameter decreases</returns>
    static ld factorDiameterReduced(const ld Pi, const ld Pf);

    /// <summary>
    /// Calculates the total time.
    /// </summary>
    /// <param name="Q">The charge.</param>
    /// <param name="P">The power.</param>
    /// <returns>time</returns>
    static ld timeTotal(const ld Q, const ld P);

    /// <summary>
    /// Times the total.
    /// </summary>
    /// <param name="Q">The charge .</param>
    /// <param name="I">The current.</param>
    /// <param name="V">The volts.</param>
    /// <returns>time</returns>
    static ld timeTotal(const ld Q, const ld I, const ld V);

    /// <summary>
    /// How much time is needed for a surgical cauterizer to raise the
    /// temperature of m1 g of tissue from 37.0∘C to 100∘C and then boil
    /// away 0.500 g of water, if it puts out 2.00 mA at 15.0 kV? Ignore heat
    /// transfer to the surroundings.
    /// </summary>
    /// <param name="m1">The mass of tissue.</param>
    /// <param name="c">The specific heat of water(sub new substance value).</param>
    /// <param name="Ti">The initial temperature.</param>
    /// <param name="Tf">The temperature to raise to.</param>
    /// <param name="m2">The mass of water to boil.</param>
    /// <param name="Lv">The latent heat of vaporization .</param>
    /// <param name="I">The current.</param>
    /// <param name="V">The volts.</param>
    /// <returns>time in seconds</returns>
    static ld timeToRaiseTemperature(const ld m1, const ld c, const ld Ti, const ld Tf, const ld m2, const ld Lv, const ld I, const ld V);

    /// <summary>
    /// What is the cost of heating a hot tub containing 1500 kg of water from
    /// 10.0∘C to 40.0∘C , assuming 75.0% efficiency to account for heat
    /// transfer to the surroundings? The cost of electricity is 9 cents/kW ⋅h .
    /// </summary>
    /// <param name="m">The mass of the water.</param>
    /// <param name="c">The specific heat.</param>
    /// <param name="Ti">The initial temp.</param>
    /// <param name="Tf">The final temp.</param>
    /// <param name="eff">The eff.</param>
    /// <param name="rate">The rate.</param>
    /// <returns>cost in cents</returns>
    static ld costToHeatHotTub(const ld m, const ld c, const ld Ti, const ld Tf, const ld eff, const ld rate);

    /// <summary>
    /// RMSs the current.
    /// </summary>
    /// <param name="Io">The peek current.</param>
    /// <returns>rms current</returns>
    static ld rmsCurrent(const ld Io);

    /// <summary>
    /// Peeks the current.
    /// </summary>
    /// <param name="Irms">The rms current.</param>
    /// <returns></returns>
    static ld peekCurrent(const ld Irms);

    /// <summary>
    /// RMSs the voltage.
    /// </summary>
    /// <param name="Vo">The peek voltage.</param>
    /// <returns>voltage</returns>
    static ld rmsVoltage(const ld Vo);

    /// <summary>
    /// Peeks the voltage.
    /// </summary>
    /// <param name="Vrms">The VRMS.</param>
    /// <returns>peek volage</returns>
    static ld peekVoltage(const ld Vrms);

    /// <summary>
    /// What is the peak power consumption of a Vrms AC microwave oven
    /// that draws Irms A?
    /// </summary>
    /// <param name="Vrms">The VRMS.</param>
    /// <param name="Irms">The irms.</param>
    /// <returns></returns>
    static ld peekPower(const ld Vrms, const ld Irms);

    /// <summary>
    /// Voltages the ac.
    /// </summary>
    /// <param name="Vo">The peek voltage.</param>
    /// <param name="f">The frequency in hertz.</param>
    /// <param name="t">The time we are looking to find the voltage at.</param>
    /// <returns>voltage</returns>
    static ld voltageAC(const ld Vo, const ld f, const ld t);

    /// <summary>
    /// Currents the ac.
    /// </summary>
    /// <param name="Io">The is the peek current (Io = Vo/R).</param>
    /// <param name="f">The frequency in hertz.</param>
    /// <param name="t">The time we are looking to find the current at.</param>
    /// <returns>amperes</returns>
    static ld currentAC(const ld Io, const ld f, const ld t);

    /// <summary>
    /// Temporaries the coeff of resistivity.
    /// </summary>
    /// <param name="R">The r.</param>
    /// <param name="R_o">The r o.</param>
    /// <param name="T_i">The t i.</param>
    /// <param name="T_f">The t f.</param>
    /// <returns></returns>
    static ld tempCoeffOfResistivity(const ld R, const ld R_o, const ld T_i, const ld T_f);

    void setElectricCurrentVal(ld val) { _electricCurrentVal = val; }

    ~ElectricCurrent()
    {
        delete _electricCurrentPtr;
    }

private:
    ld _electricCurrentVal;
    static void countIncrease() { electricCurrent_objectCount += 1; }
    static void countDecrease() { electricCurrent_objectCount -= 1; }

};

inline ld ElectricCurrent::area_r(const ld r)
{
    return _PI_ * (r*r);//m^2
}

inline ld ElectricCurrent::area_d(const ld d)
{
    return _PI_*((d*d)/4);//m^2
}

inline ld ElectricCurrent::electricCurrent(const ld Q, const ld t)
{
    return Q / t;//Amperes(I)
}

inline ld ElectricCurrent::timeItTakesChargeToFlow(const ld Q, const ld I)
{
    return Q / I;//seconds(s)
}

inline ld ElectricCurrent::electricCharge(const ld I, const ld t)
{
    return I * t;//Coulombs(C)
}

inline ld ElectricCurrent::current_qnAx_t(const ld q, const ld n, const ld Ax, const ld t)
{
    return (q * n * Ax) / t;//Amperes or Coulombs/second
}

inline ld ElectricCurrent::current_nqAvd(const ld n, const ld q, const ld A, const ld vd)
{
    return n * q * A * vd;//Amperes or C/s
}

inline ld ElectricCurrent::current_ohms(const ld V, const ld R)
{
    return V / R;//Amperes(I)
}

inline ld ElectricCurrent::current_fromPowerEq(const ld P, const ld R)
{
    return sqrt(P/R);//Amperes(I)
}

inline ld ElectricCurrent::current_fromPowerAndVolts(const ld P, const ld V)
{
    return P/V;//Amperes
}

inline ld ElectricCurrent::resistance_ohmic(const ld V, const ld I)
{
    return V / I;//Ohms
}

inline ld ElectricCurrent::resistanceUsingResistivity(const ld p, const ld l, const ld A)
{
    return p*(l  / A);//Ohms
}


inline ld ElectricCurrent::resistanceUsingResistivityWire(const ld p, const ld l, const ld d)
{
    return p * l * (4.0 / (_PI_ * (d * d)));//Ohms
}

inline ld ElectricCurrent::areaOfResistor(const ld p, const ld R, const ld l)
{
    return p * (l / R);//m^2
}

inline ld ElectricCurrent::lengthOfResistor(const ld A, const ld R, const ld p)
{
    return (A * R) / p;//m
}

inline ld ElectricCurrent::lengthOfFilament(const ld d, const ld R, const ld p)
{
    return (_PI_*(d*d)*R)/(4.0*p);//meters
}

inline ld ElectricCurrent::lengthOfWireMade(const ld m, const ld R, const ld p, const ld pd)
{
    return sqrt((m*R)/(pd*p));//m
}

inline ld ElectricCurrent::resistivityOfResistor(const ld R, const ld A, const ld l)
{
    return (A * R) / l;//Ohms/m
}

inline ld ElectricCurrent::resistivity(const ld l, const ld d, const ld R)
{
    return (_PI_*(d*d)*R)/(4.0*l);//Ohms meters
}

inline ld ElectricCurrent::voltageDropAcrossResistor(const ld I, const ld R)
{
    return I * R;//volts
}

inline ld ElectricCurrent::driftVelocity_commonWire(const ld q, const ld diameter, const ld I, const ld p, const ld mass)
{
    const ld n = (_AVOGADRO_ * 1000.0 * p) / (mass);
    return I / (n * q * (_PI_*pow(diameter/2.0,2)));
}

inline ld ElectricCurrent::driftVelocity_commonWire_n(const ld n, const ld q, const ld diameter, const ld I)
{
    return I / (n * q * (_PI_ * pow(diameter / 2, 2)));
}

inline ld ElectricCurrent::crossSectionalArea(const ld p, const ld l, const ld R)
{
    return (p * l) / R;
}

inline ld ElectricCurrent::resistanceChangeFromTemperature(const ld R0, const ld tCoR, const ld tempChange)
{
    return R0 * (1.0 + tCoR * tempChange);
}

inline ld ElectricCurrent::electricalPowerAndEnergy_IV(const ld I, const ld V)
{
    return I * V;//Watts
}

inline ld ElectricCurrent::electricalPowerAndEnergy_V2R(const ld V, const ld R)
{
    return (V * V) / R;//Watts
}

inline ld ElectricCurrent::resistanceFromPowerAndVolts(const ld P, const ld V)
{
    return (V*V)/P;//Ohms
}

inline ld ElectricCurrent::resistanceFromPowerAndCurrent(const ld P, const ld I)
{
    return P/(I*I);//Ohms
}

inline ld ElectricCurrent::electricalPowerAndEnergy_I2R(const ld I, const ld R)
{
    return (I * I) * R;//Watts
}

inline ld ElectricCurrent::powerOutputOverTime(const ld Q, const ld t, const ld V)
{
    return (Q/t)*V;//watts
}

inline ld ElectricCurrent::electronsThatPassThroughACharge(const ld Q)
{
    return Q / _PROTON_CHARGE_;
}

inline ld ElectricCurrent::nucleiPerSecond(const ld I, const ld freeProtons)
{
    return I / (freeProtons * _PROTON_CHARGE_);
}

inline ld ElectricCurrent::ratioOfDiametersInWires(const ld p1, const ld p2)
{
    return sqrt(p1/p2);
}

inline ld ElectricCurrent::currentFlowThroughOfMaterial(const ld V, const ld p, const ld d, const ld l)
{
    return (V*_PI_*(d*d))/(4.0*p*l);//Amperes(I)
}

inline ld ElectricCurrent::maximumTempchange(const ld tempCoEffOfResistivity, const ld maxChangePercent)
{
    return (maxChangePercent/100)/tempCoEffOfResistivity;
}

inline ld ElectricCurrent::costOfElectricityUsed_kWh(const ld P, const ld t, const ld ratePerKwh)
{
    const ld joules = P * t;

    return (joules * ratePerKwh)/(1000.0*3600);
}

inline ld ElectricCurrent::factorDiameterReduced(const ld Pi, const ld Pf)
{
    return sqrt(Pf / Pi);
}

inline ld ElectricCurrent::timeTotal(const ld Q, const ld P)
{
    return Q / P;//seconds
}

inline ld ElectricCurrent::timeTotal(const ld Q, const ld I, const ld V)
{
    return Q/(I*V);
}

inline ld ElectricCurrent::timeToRaiseTemperature(const ld m1, const ld c, const ld Ti, const ld Tf, const ld m2, const ld Lv, const ld I, const ld V)
{
    return (m1*c*(Tf-Ti)+ m2*Lv)/(I*V);//time(s)
}

inline ld ElectricCurrent::costToHeatHotTub(const ld m, const ld c, const ld Ti, const ld Tf, const ld eff, const ld rate)
{
    return ((m*c*(Tf-Ti))/eff)*(rate/(1000.0*3600));
}

inline ld ElectricCurrent::rmsCurrent(const ld Io)
{
    return Io/sqrt(2);
}

inline ld ElectricCurrent::peekCurrent(const ld Irms)
{
    return sqrt(2) * Irms;
}

inline ld ElectricCurrent::rmsVoltage(const ld Vo)
{
    return Vo / sqrt(2);
}

inline ld ElectricCurrent::peekVoltage(const ld Vrms)
{
    return sqrt(2)*Vrms;
}

inline ld ElectricCurrent::peekPower(const ld Vrms, const ld Irms)
{
    return 2.0*(Vrms*Irms);
}

inline ld ElectricCurrent::voltageAC(const ld Vo, const ld f, const ld t)
{
    return Vo * sin(2*_PI_)*f*t;// volts
}

inline ld ElectricCurrent::currentAC(const ld Io, const ld f, const ld t)
{
    return Io * sin(2 * _PI_) * f * t;//amperes
}

inline ld ElectricCurrent::tempCoeffOfResistivity(const ld R, const ld R_o, const ld T_i, const ld T_f)
{
    return ((R / R_o) - 1.0) / (T_f - T_i);
}

#endif //PHYSICSFORMULA_ELECTRICCURRENT_H
