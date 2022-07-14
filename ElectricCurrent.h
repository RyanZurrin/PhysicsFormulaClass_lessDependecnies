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
#include "Constants.h"


#include <iostream>

//#include "Circuits.h"

[[maybe_unused]] static struct Resistivities
{
    const long double SILVER = 1.59 * pow(10, -8); //1.59e-8 conductor, OHm*m
    const long double COPPER = 1.72 * pow(10, -8); //1.72e-8 conductor, OHm*m
    const long double GOLD  = 2.44 * pow(10, -8); //2.44e-8 conductor, OHm*m
    const long double ALUMINUM = 2.65 * pow(10, -8); //conductor, OHm*m
    const long double TUNGSTEN = 5.6 * pow(10, -8); //conductor, OHm*m
    const long double IRON = 9.71 * pow(10, -8); //conductor, OHm*m
    const long double PLATINUM = 10.6 * pow(10, -8); //conductor, OHm*m
    const long double STEEL = 20.0 * pow(10, -8); //conductor, OHm*m
    const long double LEAD = 22.0 * pow(10, -8); //conductor, OHm*m
    const long double MANGANIN = 44.0 * pow(10, -8); //conductor, OHm*m
    const long double CONSTANTAN = 49.0 * pow(10, -8); //conductor, OHm*m
    const long double MERCURY = 96.0 * pow(10, -8); //conductor, OHm*m
    const long double NICHROME = 100.0 * pow(10, -8); //conductor, OHm*m

    const long double CARBON_PURE = 3.5 * pow(10, 5); //semiconductor, OHm*m
    /// <summary>
    /// The CARBON variable can be between 3.5 and 60 * 10^5 OHm*m. there is a
    /// setCARBON method you can use to adjust its value. Its not checked so if you
    /// put in a invalid number its on you, your calculation will be wrong. In the
    /// argument only pass the first part, example 18.7. not 18.7*10^5. that gets added
    /// automatically.
    /// </summary>
    long double CARBON = 10 * pow(10, 5); //semiconductor, OHm*m
    /// <summary>
    /// Sets the carbon variable.
    /// </summary>
    /// <param name="value">The value passed shoulong double be between 3.5 and 60.</param>
    void setCARBON(long double value) { CARBON = value * pow(10, 5); }

    const long double GERMANIUM_PURE = 600.0 * pow(10, -3); //semiconductor, OHm*m
    /// <summary>
    /// The GERMANIUM variable can be between 1 and 600 * 10^5 OHm*m. there is a
    /// setGERMANIUM method you can use to adjust its value. Its not checked so if you
    /// put in a invalid number its on you, your calculation will be wrong. In the
    /// argument only pass the first part, example 18.7. not 18.7*10^-3. that gets added
    /// automatically.
    /// </summary>
    long double GERMANIUM = 300 * pow(10, -3); //semiconductor, OHm*m
    /// <summary>
    /// Sets the GERMANIUM variable.
    /// </summary>
    /// <param name="value">The value passed shoulong double be between 1 and 600.</param>
    void setGERMANIUM(long double value) { GERMANIUM = value * pow(10, -3); }

    const long double SILICON_PURE = 2300; //2300semiconductor, OHm*m
    /// <summary>
    /// The SILICON variable can be between .1 and 2300 OHm*m. there is a
    /// setSILICON method you can use to adjust its value. Its not checked so if you
    /// put in a invalid number its on you, your calculation will be wrong.
    /// </summary>
    long double SILICON = .1; // .1 - 2300 semiconductor, OHm*m
    /// <summary>
    /// Sets the Silicon variable.
    /// </summary>
    /// <param name="value">The value passed shoulong double be between .1 and 2299.</param>
    void setSILICON(long double value) { SILICON = value * pow(10, -3); }

    const long double AMBER = 5.0 * pow(10, 14); // insulator, OHm*m

    /// <summary>
    /// The GLASS variable can be between 10^9 and 10^14 OHm*m. there is a
    /// setGLASS method you can use to adjust its value. Its not checked so if you
    /// put in a invalid number its on you, your calculation will be wrong.
    /// </summary>
    long double GLASS = pow(10,9); //semiconductor, OHm*m
    /// <summary>
    /// Sets the GLASS variable.
    /// </summary>
    /// <param name="value">The value passed shoulong double be between 10^9 - 10^14.</param>
    void setGLASS(long double value) { GLASS = pow(10, value); }

    /// <summary>
    /// The WOOD variable can be between 10^8 and 10^11 OHm*m. there is a
    /// setWOOD method you can use to adjust its value of the power. Its not checked so if you
    /// put in a invalid number its on you, your calculation will be wrong.
    /// </summary>
    long double WOOD = pow(10, 9); // 10^X conductor, OHm*m
    /// <summary>
    /// Sets the GLASS variable.
    /// </summary>
    /// <param name="value">The value passed shoulong double be between 10^9 - 10^14.</param>
    void setWOOD(long double X) { GLASS = pow(10, X); }


}resistivity;


static struct TemperatureCoefficientsOfResistivity
{
    const long double SILVER = 3.8 * pow(10, -3); //3.8e-3 1/C
    const long double COPPER = 3.9 * pow(10, -3); //3.9e-3 1/C
    const long double GOlong = 3.4 * pow(10, -3); //3.4e-3 1/C
    const long double ALUMINUM = 3.9 * pow(10, -3); //3.9e-3 1/C
    const long double TUNGSTEN = 4.5 * pow(10, -3); //4.5e-3 1/C
    const long double IRON = 5.0 * pow(10, -3); //5.0e-3 1/C
    const long double PLATINUM = 3.93 * pow(10, -3); //3.93e-3 1/C
    const long double LEAD = 3.9 * pow(10, -3); //3.9e-3 1/C
    const long double MANGANIN = .000 * pow(10, -3); //.0000e-3 1/C
    const long double CONSTANTAN = 0.002 * pow(10, -3); //.002e-3 1/C
    const long double MERCURY = .89 * pow(10, -3); //.89e-3 1/C
    const long double NICHROME = .4 * pow(10, -3); //.4e-3 1/C
    const long double CARBON = -.5 * pow(10, -3); //-.5e-3 1/C
    const long double GERMANIUM = -50 * pow(10, -3); //-50e-3 1/C
    const long double SILCONE = -70 * pow(10, -3); //-70e-3 1/C

}tempCoefResistivity;

static struct AWGWireSizesByGauge
{
    const long double AWG0000 = 11.6840*pow(10, -3);// 11.6840mm diameter
    const long double AWG000 = 10.4038*pow(10, -3);// 10.4038mm diameter
    const long double AWG00 = 9.2659*pow(10, -3);// 9.2659mm diameter
    const long double AWG0 = 8.2525*pow(10, -3);// 8.2525mm diameter
    const long double AWG1 = 7.3482*pow(10, -3);// 7.3482mm diameter
    const long double AWG2 = 6.5430*pow(10, -3);// 6.5430mm diameter
    const long double AWG3 = 5.8268*pow(10, -3);// 5.8268mm diameter
    const long double AWG4 = 5.1892*pow(10, -3);// 5.1892mm diameter
    const long double AWG5 = 4.6203*pow(10, -3);// 4.6203mm diameter
    const long double AWG6 = 4.1148*pow(10, -3);// 4.1148mm diameter
    const long double AWG7 = 3.6652*pow(10, -3);// 3.6652mm diameter
    const long double AWG8 = 3.2639*pow(10, -3);// 3.2639mm diameter
    const long double AWG9 = 2.9058*pow(10, -3);// 2.9058mm diameter
    const long double AWG10 = 2.5883*pow(10, -3);// 2.5883mm diameter
    const long double AWG11 = 2.3038*pow(10, -3);// 2.3038mm diameter
    const long double AWG12 = 2.0523*pow(10, -3);// 2.0523mm diameter
    const long double AWG13 = 1.8288*pow(10, -3);// 1.8288mm diameter
    const long double AWG14 = 1.6281*pow(10, -3);// 1.6281mm diameter
    const long double AWG15 = 1.4503*pow(10, -3);// 1.4503mm diameter
    const long double AWG16 = 1.2903*pow(10, -3);// 1.2903mm diameter
    const long double AWG17 = 1.1506*pow(10, -3);// 1.1506mm diameter
    const long double AWG18 = 1.0236*pow(10, -3);// 1.0236mm diameter
    const long double AWG19 = 0.9119*pow(10, -3);// 0.9119mm diameter
    const long double AWG20 = 0.8128*pow(10, -3);// 0.8128mm diameter
    const long double AWG21 = 0.7239*pow(10, -3);// 0.7239mm diameter
    const long double AWG22 = 0.6452*pow(10, -3);// 0.6452mm diameter
    const long double AWG23 = 0.5740*pow(10, -3);// 0.5740mm diameter
    const long double AWG24 = 0.5105*pow(10, -3);// 0.5105mm diameter
    const long double AWG25 = 0.4547*pow(10, -3);// 0.4547mm diameter
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

    ElectricCurrent(long double val)
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
    static long double area_r(const long double r);

    /// <summary>
    /// Calculates the area from the diameter
    /// </summary>
    /// <param name="d">The diameter.</param>
    /// <returns>area(m^2)</returns>
    static long double area_d(const long double d);

    /// <summary>
    /// calculates the electric current (I) defined as the rate at which charge
    /// (COULOMB) flows through a given time (t).
    /// </summary>
    /// <param name="COULOMB">The change in current.</param>
    /// <param name="t">The time over which current passes through.</param>
    /// <returns>the electric current SI unit of ampere (A)</returns>
    static long double electricCurrent(const long double Q, const long double t);

    /// <summary>
    /// Times it takes charge COULOMB to flow through a current of I amperes
    /// </summary>
    /// <param name="COULOMB">The charge.</param>
    /// <param name="I">The current.</param>
    /// <returns>time in seconds</returns>
    static long double timeItTakesChargeToFlow(const long double Q, const long double I);

    /// <summary>
    /// Calculates the Electrics  charge COULOMB
    /// </summary>
    /// <param name="I">The current.</param>
    /// <param name="t">The time in seconds.</param>
    /// <returns>the charge in coulombs</returns>
    static long double electricCharge(const long double I, const long double t);

    /// <summary>
    /// Calculates the current (I) using the number of free charges(n) per unit
    /// volume (Ax) where the charge per n is given by q and t is the unit time.
    /// I = (q * n * Ax) / t;
    /// </summary>
    /// <param name="q">The charge.</param>
    /// <param name="n">The number of free charges.</param>
    /// <param name="Ax">The volume of segment Ax is the area * distance
    /// where for a circle woulong double be pi*r^2 * x where x is the length.</param>
    /// <param name="t">The unit time the charge is moved over.</param>
    /// <returns>The current</returns>
    static long double current_qnAx_t(const long double q, const long double n, const long double Ax, const long double t);

    /// <summary>
    /// Calculates the current (I) using the number of free charges(n) per unit
    /// volume(A) each carrying a charge of q with a drift velocity of vd.
    /// </summary>
    /// <param name="n">The number of free charges.</param>
    /// <param name="q">The charge on each.</param>
    /// <param name="A">the area.</param>
    /// <param name="vd">The drift velocity.</param>
    /// <returns>the current</returns>
    static long double current_nqAvd(const long double n, const long double q, const long double A, const long double vd);

    /// <summary>
    /// Calculates the currents using ohms law of voltage over resistances.
    /// </summary>
    /// <param name="V">The voltage.</param>
    /// <param name="R">The resistance.</param>
    /// <returns>current in Amperes</returns>
    static long double current_ohms(const long double V, const long double R);

    /// <summary>
    /// Calculates the current from rearranging the power equations
    /// </summary>
    /// <param name="P">The power in watts.</param>
    /// <param name="R">The resistance.</param>
    /// <returns>the current in amperes(I)</returns>
    static long double current_fromPowerEq(const long double P, const long double R);

    /// <summary>
    /// Calculates the currents from power and volts.
    /// </summary>
    /// <param name="P">The power in watts.</param>
    /// <param name="V">The volts.</param>
    /// <returns></returns>
    static long double current_fromPowerAndVolts(const long double P, const long double V);

    /// <summary>
    /// calculates the resistances of an ohmic conducting material
    /// </summary>
    /// <param name="V">The volts.</param>
    /// <param name="I">The current (A).</param>
    /// <returns>(V/A)one volt per Ampere</returns>
    static long double resistance_ohmic(const long double V, const long double I);

    /// <summary>
    /// Calculates the resistance of resistor with a resistivity of p and a
    /// length of l with a area of A(pir^2, in a circular resistor).
    /// </summary>
    /// <param name="p">The resistivity.</param>
    /// <param name="l">The length.</param>
    /// <param name="A">The cross sectional area.</param>
    /// <returns>Resistance Ohms</returns>
    static long double resistanceUsingResistivity(const long double p, const long double l, const long double A);

    /// <summary>
    /// calculates the resistance of a piece of wire with a length of l,
    /// having a diameter of d and a resistivity of p, which depends on the
    /// material its made from. copper is a p = 1.72e-8 Ohms/m
    /// </summary>
    /// <param name="p">The resistivity.</param>
    /// <param name="l">The length.</param>
    /// <param name="d">The diameter.</param>
    /// <returns>the resistance in Ohms</returns>
    static long double resistanceUsingResistivityWire(const long double p, const long double l, const long double d);

    /// <summary>
    /// calculates the cross sectional areas the of a resistor.
    /// </summary>
    /// <param name="p">The resistivity.</param>
    /// <param name="R">The Resistance.</param>
    /// <param name="l">The length.</param>
    /// <returns>area of resistor (m^2)</returns>
    static long double areaOfResistor(const long double p, const long double R, const long double l);

    /// <summary>
    /// Calculates the length of a resistor.
    /// </summary>
    /// <param name="A">the cross sectional area.</param>
    /// <param name="R">The resistance.</param>
    /// <param name="p">The resistivity.</param>
    /// <returns>the length of resistor (m)</returns>
    static long double lengthOfResistor(const long double A, const long double R, const long double p);


    /// <summary>
    /// Calculates the Lengths of filament.
    /// </summary>
    /// <param name="d">The diameter.</param>
    /// <param name="R">The resistance.</param>
    /// <param name="p">The resistivity.</param>
    /// <returns></returns>
    static long double lengthOfFilament(const long double d, const long double R, const long double p);

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
    static long double lengthOfWireMade(const long double m, const long double R, const long double p, const long double pd);

    /// <summary>
    /// Calculates the resistivity of a resistor.
    /// </summary>
    /// <param name="R">The resistance.</param>
    /// <param name="A">area.</param>
    /// <param name="l">The length.</param>
    /// <returns></returns>
    static long double resistivityOfResistor(const long double R, const long double A, const long double l);

    /// <summary>
    /// Of what material is a wire made, if it is a length of (l)m long with a
    ///(d)m diameter and has a resistance of R ohms at 20.0∘C
    /// </summary>
    /// <param name="l">The length.</param>
    /// <param name="d">The diameter.</param>
    /// <param name="R">The resistance.</param>
    /// <returns>Ohm m</returns>
    static long double resistivity(const long double l, const long double d, const long double R);

    /// <summary>
    /// Calculates the voltages drop across a resistor.
    /// </summary>
    /// <param name="I">The current (Amperes).</param>
    /// <param name="R">The resistance.</param>
    /// <returns>The voltage</returns>
    static long double voltageDropAcrossResistor(const long double I, const long double R);

    /// <summary>
    /// Calculates the drifts the velocity (V_d) of a common wire.
    /// </summary>
    /// <param name="q">The charge.</param>
    /// <param name="diameter">The diameter.</param>
    /// <param name="I">The current (Amperes).</param>
    /// <param name="p">The density per kg/m^3.</param>
    /// <param name="mass">The atomic mass.</param>
    /// <returns>drift velocity m/s</returns>
    static long double driftVelocity_commonWire(const long double q,
                                       const long double diameter,
                                       const long double I,
                                       const long double p,
                                       const long double mass);

    /// <summary>
    /// Drifts the velocity common wire n.
    /// </summary>
    /// <param name="n">The number of electrons per cubic meter.</param>
    /// <param name="q">The charge.</param>
    /// <param name="diameter">The diameter.</param>
    /// <param name="I">The current.</param>
    /// <returns>drift velocity m/s</returns>
    static long double driftVelocity_commonWire_n(const long double n,
                                         const long double q,
                                         const long double diameter,
                                         const long double I);

    /// <summary>
    /// Calculates the crosses sectional area
    /// </summary>
    /// <param name="p">The resistivity.</param>
    /// <param name="l">The length.</param>
    /// <param name="R">The resistance.</param>
    /// <returns>cross sectional area (m^2)</returns>
    static long double crossSectionalArea(const long double p, const long double l, const long double R);

    /// <summary>
    /// Calculates the change in resistances from the effects of a
    /// change in temperature.
    /// </summary>
    /// <param name="R0">The initial colong double resistance</param>
    /// <param name="tCoR">The temperature coefficients of resistivity.</param>
    /// <param name="tempChange">The change in the temperature.</param>
    /// <returns>the new resistance in Ohms</returns>
    static long double resistanceChangeFromTemperature(const long double R0,
                                              const long double tCoR,
                                              const long double tempChange);



    /// <summary>
    /// calculates the electrical power from current and volts
    /// </summary>
    /// <param name="I">The current.</param>
    /// <param name="V">The volts.</param>
    /// <returns>energy from electrical(W)</returns>
    static long double electricalPowerAndEnergy_IV(const long double I, const long double V);

    /// <summary>
    /// calculates the electrical power from volts and resistance
    /// </summary>
    /// <param name="V">The volts.</param>
    /// <param name="R">The resistance.</param>
    /// <returns>energy from electrical (W)</returns>
    static long double electricalPowerAndEnergy_V2R(const long double V, const long double R);

    /// <summary>
    /// Some makes of olong doubleer cars have 6.00-V electrical systems. (a) What is
    /// the hot resistance of a 30.0-W headlight in such a car?
    /// </summary>
    /// <param name="P">The power.</param>
    /// <param name="V">The volts.</param>
    /// <returns>resistance</returns>
    static long double resistanceFromPowerAndVolts(const long double P, const long double V);

    /// <summary>
    /// Calculates the resistance from power and current.
    /// </summary>
    /// <param name="P">The power.</param>
    /// <param name="I">The current.</param>
    /// <returns>Ohms</returns>
    static long double resistanceFromPowerAndCurrent(const long double P, const long double I);

    /// <summary>
    /// calculates the electrical power from current and resistance
    /// </summary>
    /// <param name="I">The current.</param>
    /// <param name="R">The resistance.</param>
    /// <returns>energy from electrical (W)</returns>
    static long double electricalPowerAndEnergy_I2R(const long double I, const long double R);

    /// <summary>
    /// A charge of (COULOMB) C of charge passes through a pocket calculator’s solar
    /// cells in t seconds. What is the power output, given the calculator’s
    /// voltage output is a voltage of V.
    /// </summary>
    /// <param name="COULOMB">The charge.</param>
    /// <param name="t">The time.</param>
    /// <param name="V">The voltage.</param>
    /// <returns>the watts</returns>
    static long double powerOutputOverTime(const long double Q, const long double t, const long double V);

    /// <summary>
    /// Calculates the total electrons  that pass through a charge.
    /// </summary>
    /// <param name="COULOMB">The charge in coulombs.</param>
    /// <returns>Ne, number of electrons</returns>
    static long double electronsThatPassThroughACharge(const long double Q);

    /// <summary>
    /// If a large cyclotron directs a beam of freeProtons nuclei onto a target
    /// with a beam current of I Amperes. Calculate How many nuclei per second
    /// this is.
    /// </summary>
    /// <param name="I">The current.</param>
    /// <param name="freeProtons">The number of free protons.</param>
    /// <returns>nuclei/second</returns>
    static long double nucleiPerSecond(const long double I, const long double freeProtons);

    /// <summary>
    /// Calculates the ratio of the resistivity of wire1 to that of wire2, if they have
    /// the same resistance per unit length (as they might in householong double wiring)
    /// </summary>
    /// <param name="p1">The the bigger resistivity.</param>
    /// <param name="p2">The smaller resistivity.</param>
    /// <returns>the ratio meaning the size of the smaller resistivity value will
    /// to by this value bigger</returns>
    static long double ratioOfDiametersInWires(const long double p1, const long double p2);

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
    static long double currentFlowThroughOfMaterial(const long double V,
                                           const long double p,
                                           const long double d,
                                           const long double l);

    /// <summary>
    /// A resistor made of Nichrome wire is used in an application where its
    /// resistance cannot change more than 1.00% from its value at 20.0∘C .
    /// Over what temperature range can it be used?
    /// </summary>
    /// <param name="tempCoEffOfResistivity">The temperature coefficient of resistivity.</param>
    /// <param name="maxChangePercent">The maximum change percent.</param>
    /// <returns>temperature</returns>
    static long double maximumTempchange(const long double tempCoEffOfResistivity,
                                const long double maxChangePercent);

    /// <summary>
    /// With a 1200-W toaster, how much electrical energy is needed to make a
    /// slice of toast (cooking time = 1 minute)? At 9.0 cents/kW⋅h, how much does this cost?.
    /// </summary>
    /// <param name="P">The power inWatts.</param>
    /// <param name="t">The time in seconds.</param>
    /// <param name="ratePerKwh">The rate per KWH.</param>
    /// <returns>total cost to use electricity</returns>
    static long double costOfElectricityUsed_kWh(const long double P, const long double t, const long double ratePerKwh);

    /// <summary>
    /// An olong double light bulb draws only 50.0 W, rather than its original 60.0 W,
    /// due to evaporative thinning of its filament. By what factor is its
    /// diameter reduced, assuming uniform thinning along its length? Neglect
    /// any effects caused by temperature differences.
    /// </summary>
    /// <param name="Pi">The starting wattage.</param>
    /// <param name="Pf">The final wattage.</param>
    /// <returns>factor which diameter decreases</returns>
    static long double factorDiameterReduced(const long double Pi, const long double Pf);

    /// <summary>
    /// Calculates the total time.
    /// </summary>
    /// <param name="COULOMB">The charge.</param>
    /// <param name="P">The power.</param>
    /// <returns>time</returns>
    static long double timeTotal(const long double Q, const long double P);

    /// <summary>
    /// Times the total.
    /// </summary>
    /// <param name="COULOMB">The charge .</param>
    /// <param name="I">The current.</param>
    /// <param name="V">The volts.</param>
    /// <returns>time</returns>
    static long double timeTotal(const long double Q, const long double I, const long double V);

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
    static long double timeToRaiseTemperature(const long double m1,
                                     const long double c,
                                     const long double Ti,
                                     const long double Tf,
                                     const long double m2,
                                     const long double Lv,
                                     const long double I,
                                     const long double V);

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
    static long double costToHeatHotTub(const long double m,
                               const long double c,
                               const long double Ti,
                               const long double Tf,
                               const long double eff,
                               const long double rate);

    /// <summary>
    /// RMSs the current.
    /// </summary>
    /// <param name="Io">The peek current.</param>
    /// <returns>rms current</returns>
    static long double rmsCurrent(const long double Io);

    /// <summary>
    /// Peeks the current.
    /// </summary>
    /// <param name="Irms">The rms current.</param>
    /// <returns></returns>
    static long double peekCurrent(const long double Irms);

    /// <summary>
    /// RMSs the voltage.
    /// </summary>
    /// <param name="Vo">The peek voltage.</param>
    /// <returns>voltage</returns>
    static long double rmsVoltage(const long double Vo);

    /// <summary>
    /// Peeks the voltage.
    /// </summary>
    /// <param name="Vrms">The VRMS.</param>
    /// <returns>peek volage</returns>
    static long double peekVoltage(const long double Vrms);

    /// <summary>
    /// What is the peak power consumption of a Vrms AC microwave oven
    /// that draws Irms A?
    /// </summary>
    /// <param name="Vrms">The VRMS.</param>
    /// <param name="Irms">The irms.</param>
    /// <returns></returns>
    static long double peekPower(const long double Vrms, const long double Irms);

    /// <summary>
    /// Voltages the ac.
    /// </summary>
    /// <param name="Vo">The peek voltage.</param>
    /// <param name="f">The frequency in hertz.</param>
    /// <param name="t">The time we are looking to find the voltage at.</param>
    /// <returns>voltage</returns>
    static long double voltageAC(const long double Vo, const long double f, const long double t);

    /// <summary>
    /// Currents the ac.
    /// </summary>
    /// <param name="Io">The is the peek current (Io = Vo/R).</param>
    /// <param name="f">The frequency in hertz.</param>
    /// <param name="t">The time we are looking to find the current at.</param>
    /// <returns>amperes</returns>
    static long double currentAC(const long double Io, const long double f, const long double t);

    /// <summary>
    /// Temporaries the coeff of resistivity.
    /// </summary>
    /// <param name="R">The r.</param>
    /// <param name="R_o">The r o.</param>
    /// <param name="T_i">The t i.</param>
    /// <param name="T_f">The t f.</param>
    /// <returns></returns>
    static long double tempCoeffOfResistivity(const long double R,
                                     const long double R_o,
                                     const long double T_i,
                                     const long double T_f);

    void setElectricCurrentVal(long double val) { _electricCurrentVal = val; }

    ~ElectricCurrent()
    {
        delete _electricCurrentPtr;
    }

private:
    long double _electricCurrentVal;
    static void countIncrease() { electricCurrent_objectCount += 1; }
    static void countDecrease() { electricCurrent_objectCount -= 1; }

};

inline long double ElectricCurrent::area_r(const long double r)
{
    return constants::PI * (r*r);//m^2
}

inline long double ElectricCurrent::area_d(const long double d)
{
    return constants::PI*((d*d)/4);//m^2
}

inline long double ElectricCurrent::electricCurrent(const long double Q, const long double t)
{
    return Q / t;//Amperes(I)
}

inline long double ElectricCurrent::timeItTakesChargeToFlow(const long double Q, const long double I)
{
    return Q / I;//seconds(s)
}

inline long double ElectricCurrent::electricCharge(const long double I, const long double t)
{
    return I * t;//Coulombs(C)
}

inline long double ElectricCurrent::current_qnAx_t(const long double q,
                                          const long double n,
                                          const long double Ax,
                                          const long double t)
{
    return (q * n * Ax) / t;//Amperes or Coulombs/second
}

inline long double ElectricCurrent::current_nqAvd(const long double n,
                                         const long double q,
                                         const long double A,
                                         const long double vd)
{
    return n * q * A * vd;//Amperes or C/s
}

inline long double ElectricCurrent::current_ohms(const long double V, const long double R)
{
    return V / R;//Amperes(I)
}

inline long double ElectricCurrent::current_fromPowerEq(const long double P, const long double R)
{
    return sqrt(P/R);//Amperes(I)
}

inline long double ElectricCurrent::current_fromPowerAndVolts(const long double P, const long double V)
{
    return P/V;//Amperes
}

inline long double ElectricCurrent::resistance_ohmic(const long double V, const long double I)
{
    return V / I;//Ohms
}

inline long double ElectricCurrent::resistanceUsingResistivity(const long double p,
                                                      const long double l,
                                                      const long double A)
{
    return p*(l  / A);//Ohms
}


inline long double ElectricCurrent::resistanceUsingResistivityWire(const long double p,
                                                          const long double l,
                                                          const long double d)
{
    return p * l * (4.0 / (constants::PI * (d * d)));//Ohms
}

inline long double ElectricCurrent::areaOfResistor(const long double p, const long double R, const long double l)
{
    return p * (l / R);//m^2
}

inline long double ElectricCurrent::lengthOfResistor(const long double A, const long double R, const long double p)
{
    return (A * R) / p;//m
}

inline long double ElectricCurrent::lengthOfFilament(const long double d, const long double R, const long double p)
{
    return (constants::PI*(d*d)*R)/(4.0*p);//meters
}

inline long double ElectricCurrent::lengthOfWireMade(const long double m,
                                            const long double R,
                                            const long double p,
                                            const long double pd)
{
    return sqrt((m*R)/(pd*p));//m
}

inline long double ElectricCurrent::resistivityOfResistor(const long double R,
                                                 const long double A,
                                                 const long double l)
{
    return (A * R) / l;//Ohms/m
}

inline long double ElectricCurrent::resistivity(const long double l, const long double d, const long double R)
{
    return (constants::PI*(d*d)*R)/(4.0*l);//Ohms meters
}

inline long double ElectricCurrent::voltageDropAcrossResistor(const long double I, const long double R)
{
    return I * R;//volts
}

inline long double ElectricCurrent::driftVelocity_commonWire(const long double q,
                                                    const long double diameter,
                                                    const long double I,
                                                    const long double p,
                                                    const long double mass)
{
    const long double n = (constants::AVOGADRO * 1000.0 * p) / (mass);
    return I / (n * q * (constants::PI*pow(diameter/2.0,2)));
}

inline long double ElectricCurrent::driftVelocity_commonWire_n(const long double n,
                                                      const long double q,
                                                      const long double diameter,
                                                      const long double I)
{
    return I / (n * q * (constants::PI * pow(diameter / 2, 2)));
}

inline long double ElectricCurrent::crossSectionalArea(const long double p, const long double l, const long double R)
{
    return (p * l) / R;
}

inline long double ElectricCurrent::resistanceChangeFromTemperature(const long double R0,
                                                           const long double tCoR,
                                                           const long double tempChange)
{
    return R0 * (1.0 + tCoR * tempChange);
}

inline long double ElectricCurrent::electricalPowerAndEnergy_IV(const long double I, const long double V)
{
    return I * V;//Watts
}

inline long double ElectricCurrent::electricalPowerAndEnergy_V2R(const long double V, const long double R)
{
    return (V * V) / R;//Watts
}

inline long double ElectricCurrent::resistanceFromPowerAndVolts(const long double P, const long double V)
{
    return (V*V)/P;//Ohms
}

inline long double ElectricCurrent::resistanceFromPowerAndCurrent(const long double P, const long double I)
{
    return P/(I*I);//Ohms
}

inline long double ElectricCurrent::electricalPowerAndEnergy_I2R(const long double I, const long double R)
{
    return (I * I) * R;//Watts
}

inline long double ElectricCurrent::powerOutputOverTime(const long double Q, const long double t, const long double V)
{
    return (Q/t)*V;//watts
}

inline long double ElectricCurrent::electronsThatPassThroughACharge(const long double Q)
{
    return Q / constants::PROTON_CHARGE;
}

inline long double ElectricCurrent::nucleiPerSecond(const long double I, const long double freeProtons)
{
    return I / (freeProtons * constants::PROTON_CHARGE);
}

inline long double ElectricCurrent::ratioOfDiametersInWires(const long double p1, const long double p2)
{
    return sqrt(p1/p2);
}

inline long double ElectricCurrent::currentFlowThroughOfMaterial(const long double V,
                                                        const long double p,
                                                        const long double d,
                                                        const long double l)
{
    return (V*constants::PI*(d*d))/(4.0*p*l);//Amperes(I)
}

inline long double ElectricCurrent::maximumTempchange(
        const long double tempCoEffOfResistivity,
        const long double maxChangePercent)
{
    return (maxChangePercent/100)/tempCoEffOfResistivity;
}

inline long double ElectricCurrent::costOfElectricityUsed_kWh(const long double P,
                                                     const long double t,
                                                     const long double ratePerKwh)
{
    const long double joules = P * t;

    return (joules * ratePerKwh)/(1000.0*3600);
}

inline long double ElectricCurrent::factorDiameterReduced(const long double Pi, const long double Pf)
{
    return sqrt(Pf / Pi);
}

inline long double ElectricCurrent::timeTotal(const long double Q, const long double P)
{
    return Q / P;//seconds
}

inline long double ElectricCurrent::timeTotal(const long double Q, const long double I, const long double V)
{
    return Q/(I*V);
}

inline long double ElectricCurrent::timeToRaiseTemperature(const long double m1,
                                                  const long double c,
                                                  const long double Ti,
                                                  const long double Tf,
                                                  const long double m2,
                                                  const long double Lv,
                                                  const long double I,
                                                  const long double V)
{
    return (m1*c*(Tf-Ti)+ m2*Lv)/(I*V);//time(s)
}

inline long double ElectricCurrent::costToHeatHotTub(const long double m,
                                            const long double c,
                                            const long double Ti,
                                            const long double Tf,
                                            const long double eff,
                                            const long double rate)
{
    return ((m*c*(Tf-Ti))/eff)*(rate/(1000.0*3600));
}

inline long double ElectricCurrent::rmsCurrent(const long double Io)
{
    return Io/sqrt(2);
}

inline long double ElectricCurrent::peekCurrent(const long double Irms)
{
    return sqrt(2) * Irms;
}

inline long double ElectricCurrent::rmsVoltage(const long double Vo)
{
    return Vo / sqrt(2);
}

inline long double ElectricCurrent::peekVoltage(const long double Vrms)
{
    return sqrt(2)*Vrms;
}

inline long double ElectricCurrent::peekPower(const long double Vrms, const long double Irms)
{
    return 2.0*(Vrms*Irms);
}

inline long double ElectricCurrent::voltageAC(const long double Vo, const long double f, const long double t)
{
    return Vo * sin(2*constants::PI)*f*t;// volts
}

inline long double ElectricCurrent::currentAC(const long double Io, const long double f, const long double t)
{
    return Io * sin(2 * constants::PI) * f * t;//amperes
}

inline long double ElectricCurrent::tempCoeffOfResistivity(const long double R,
                                                  const long double R_o,
                                                  const long double T_i,
                                                  const long double T_f)
{
    return ((R / R_o) - 1.0) / (T_f - T_i);
}

#endif //PHYSICSFORMULA_ELECTRICCURRENT_H
