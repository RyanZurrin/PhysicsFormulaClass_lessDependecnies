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

static struct Resistivities
{
    Resistivities() {}
    const struct MetallicConductors {
        const long double SILVER = 1.59e-8; //1.59e-8 conductor, OHm*m
        const long double COPPER = 1.68e-8; //1.72e-8 conductor, OHm*m
        const long double GOLD  = 2.24e-8; //2.44e-8 conductor, OHm*m
        const long double ALUMINUM = 2.65e-8; //conductor, OHm*m
        const long double TUNGSTEN = 5.6e-8; //conductor, OHm*m
        const long double IRON = 9.71e-8; //conductor, OHm*m
        const long double MERCUARY = 9.84e-7; //conductor, OHm*m
        const long double PLATINUM = 10.6e-8; //conductor, OHm*m
        const long double STEEL = 20.0e-8; //conductor, OHm*m
        const long double LEAD = 22.0e-8; //conductor, OHm*m
        const long double MANGANIN = 44.0e-8; //conductor, OHm*m
        const long double CONSTANTAN = 49.0e-8; //conductor, OHm*m
        const long double NICHROME = 100.0e-8; //conductor, OHm*m
    }metallicConductors;

    const static struct IonicSolutions {
        const long double L_MOLAR_CuSO4 = 3.9e-4; //OHm*m
        const long double L_MOLAR_HCI = 1.7e-2; //OHm*m
        const long double L_MOLAR_NaCl = 1.4e-4; //OHm*m
        const long double H20 = 2.6e-5; //OHm*m
        const long double BLOOD_HUMAN = 0.70; //OHm*m
        const long double SEA_WATER = 0.22; //OHm*m
    }ionicSolutions;

    const static struct Semiconductors {
        const long double GERMANIUM = 0.5; //OHm*m
        const long double SILICON = 3.0e3; //OHm*m
        const long double DIAMOND = 1.0e4; //OHm*m
    } semiconductors;

    const static struct Insulators {
        const long double CERAMICS = 1e12; //OHm*m
        const long double GLASS = 1e12; //OHm*m
        const long double POLYETHYLENE = 1e16; //OHm*m
        const long double POLYPROPYLENE = 1e16; //OHm*m
        const long double RUBBER = 1e15; //OHm*m
        const long double WOOD = 1e11; //OHm*m
        const long double QUARTZ = 7.5e17; //OHm*m
    }insulators;


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
    long double WOOD = pow(10, 9); // 10^X_ conductor, OHm*m
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
    const long double GOLD = 3.4 * pow(10, -3); //3.4e-3 1/C
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
    const long double SILICONE = -70 * pow(10, -3); //-70e-3 1/C

}tempCoefResistivity;

static struct AWGWireSizesByGauge
{
    const long double AWG0000 = 11.6840e-3;// 11.6840mm diameter
//    const struct AWG0000 {
//        const long double d_inches = 0.460;
//        const long double d_mm = 11.6840;
//        const long double d_m = 0.0116840;
//        const long double cross_section_mm = 107;
//        const long double cross_section_m = 0.000107;
//        const long double ohms_per_km = 0.16072;
//        const long double max_amps_chassis = 380;
//    }awg0000;
    const long double AWG000 = 10.4038e-3;// 10.4038mm diameter
    const long double AWG00 = 9.2659e-3;// 9.2659mm diameter
    const long double AWG0 = 8.2525e-3;// 8.2525mm diameter
    const long double AWG1 = 7.3482e-3;// 7.3482mm diameter
    const long double AWG2 = 6.5430e-3;// 6.5430mm diameter
    const long double AWG3 = 5.8268e-3;// 5.8268mm diameter
    const long double AWG4 = 5.1892e-3;// 5.1892mm diameter
    const long double AWG5 = 4.6203e-3;// 4.6203mm diameter
    const long double AWG6 = 4.1148e-3;// 4.1148mm diameter
    const long double AWG7 = 3.6652e-3;// 3.6652mm diameter
    const long double AWG8 = 3.2639e-3;// 3.2639mm diameter
    const long double AWG9 = 2.9058e-3;// 2.9058mm diameter
    const long double AWG10 = 2.5883e-3;// 2.5883mm diameter
    const long double AWG11 = 2.3038e-3;// 2.3038mm diameter
    const long double AWG12 = 2.0523e-3;// 2.0523mm diameter
    const long double AWG13 = 1.8288e-3;// 1.8288mm diameter
    const long double AWG14 = 1.6281e-3;// 1.6281mm diameter
    const long double AWG15 = 1.4503e-3;// 1.4503mm diameter
    const long double AWG16 = 1.2903e-3;// 1.2903mm diameter
    const long double AWG17 = 1.1506e-3;// 1.1506mm diameter
    const long double AWG18 = 1.0236e-3;// 1.0236mm diameter
    const long double AWG19 = 0.9119e-3;// 0.9119mm diameter
    const long double AWG20 = 0.8128e-3;// 0.8128mm diameter
    const long double AWG21 = 0.7239e-3;// 0.7239mm diameter
    const long double AWG22 = 0.6400e-3;// 0.6452mm diameter
    const long double AWG23 = 0.5740e-3;// 0.5740mm diameter
    const long double AWG24 = 0.5105e-3;// 0.5105mm diameter
    const long double AWG25 = 0.4547e-3;// 0.4547mm diameter
    const long double AWG26 = 0.4039e-3;// 0.4050mm diameter
    const long double AWG27 = 0.3607e-3;// 0.3580mm diameter
    const long double AWG28 = 0.3200e-3;// 0.3200mm diameter
    const long double AWG29 = 0.2870e-3;// 0.2860mm diameter
    const long double AWG30 = 0.2540e-3;// 0.2550mm diameter
    const long double AWG31 = 0.2261e-3;// 0.2270mm diameter
    const long double AWG32 = 0.2032e-3;// 0.2020mm diameter

    /**
     * @brief Returns the diameter of the wire in meters for the given gauge.
     * @warning For the 0000, 000, and 00 gauges, use a 1 in front of the zero's,
     * e.g. 0000 = 10000, \n
     * 000 = 1000, \n
     * 00 = 100.
     * @param gauge  The gauge of the wire.
     * @return The diameter of the wire in meters.
     */
    [[nodiscard]] long double convertGauge2Diameter(int gauge) const
    {
        switch (gauge)
        {
            case 10000: return AWG0000;
            case 1000: return AWG000;
            case 100: return AWG00;
            case 0: return AWG0;
            case 1: return AWG1;
            case 2: return AWG2;
            case 3: return AWG3;
            case 4: return AWG4;
            case 5: return AWG5;
            case 6: return AWG6;
            case 7: return AWG7;
            case 8: return AWG8;
            case 9: return AWG9;
            case 10: return AWG10;
            case 11: return AWG11;
            case 12: return AWG12;
            case 13: return AWG13;
            case 14: return AWG14;
            case 15: return AWG15;
            case 16: return AWG16;
            case 17: return AWG17;
            case 18: return AWG18;
            case 19: return AWG19;
            case 20: return AWG20;
            case 21: return AWG21;
            case 22: return AWG22;
            case 23: return AWG23;
            case 24: return AWG24;
            case 25: return AWG25;
            case 26: return AWG26;
            case 27: return AWG27;
            case 28: return AWG28;
            case 29: return AWG29;
            case 30: return AWG30;
            case 31: return AWG31;
            case 32: return AWG32;
            default: return 0;
        }
    }
}AWG;


//static object counter for ElectricCurrent class
static int electricCurrent_objectCount = 0;


class ElectricCurrent
{
public:

    ElectricCurrent()
    {
        _electricCurrentVal = 0.0;
        countIncrease();
        //cout << "in electricCurrent count: " << electricCurrent_objectCount << endl;
    }

    explicit ElectricCurrent(long double val)
    {
        _electricCurrentVal = 0.0;
        countIncrease();

    }

    /**
     * @brief copy constructor
     */
    ElectricCurrent(const ElectricCurrent& t)
    {
        _electricCurrentVal = t._electricCurrentVal;
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    ElectricCurrent(ElectricCurrent&& t) noexcept
    {
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
            _electricCurrentVal = t._electricCurrentVal;
            countIncrease();
        }
        return *this;
    }

    static void show_objectCount() { std::cout << "\n electric current object count: " << electricCurrent_objectCount << std::endl; }
    static int get_objectCount() { return electricCurrent_objectCount; }

    /**
     * @brief calculates the area of circle using the radius.
     * @param r  radius
     * @param print  print to console
     * @return  area(m^2)
     */
    static long double circle_area_r(long double r, bool print = false);

    /**
     * @brief calculates the area of a sphere using the radius.
     * @param r  radius
     * @param print  print to console
     * @return  area(m^2)
     */
    static long double sphere_area_r(long double r, bool print = false);

    /**
     * @brief calculates the area of a circle from the diameter
     * @param d  diameter
     * @param print  print to console
     * @return  area(m^2)
     */
    static long double circle_area_d(long double d, bool print = false);

    /**
     * @brief calculates the area of a sphere from the diameter
     * @param d  diameter
     * @param print  print to console
     * @return  area(m^2)
     */
    static long double sphere_area_d(long double d, bool print = false);

    /**
     * @brief calculates the area of a circle from the circumference
     * @param c  circumference
     * @param print  print to console
     * @return  area(m^2)
     */
    static long double circle_area_c(long double c, bool print = false);

    /**
     * @brief calculates the area of a sphere from the circumference
     * @param c  circumference
     * @param print  print to console
     * @return  area(m^2)
     */
    static long double sphere_area_c(long double c, bool print = false);

    /**
     * @brief calculates the area of a circle from the gauge
     * @param gauge  gauge
     * @param print  print to console
     * @return  area(m^2)
     */
    static long double circle_area_gauge(int gauge, bool print = false);

    /**
     * @brief calculates the area of a square from the length of one side
     * @param side  length of one side
     * @param print  print to console
     * @return  area(m^2)
     */
    static long double square_area(long double side, bool print = false);

    /**
     * @brief calculates the area of a rectangle from the length of one side
     * and the width of the other side
     * @param l  length of one side
     * @param w  width of the other side
     * @param print  print to console
     * @return  area(m^2)
     */
    static long double rectangle_area(long double l, long double w, bool print = false);

    /**
     * @brief calculates the electric current (I) defined as the rate at which charge
     * (COULOMB) flows through a given time (t).
     * @param Q  charge (COULOMB)
     * @param t  time (s)
     * @param print  print to console
     * @return  the electric current SI unit of ampere (A)
     */
    static long double electricCurrent(long double Q, long double t, bool print = true);

    /**
     * @brief calculates the time it takes charge COULOMB to flow through a current of I amperes
     * @param Q  charge (COULOMB)
     * @param I  current (A)
     * @param print  print to console
     * @return  time in seconds
     */
    static long double timeItTakesChargeToFlow(long double Q, long double I, bool print = true);

    /**
     * @brief calculates the Electrics  charge COULOMB
     * @param I  current (A)
     * @param t  time in seconds
     * @param print  print to console
     * @return  the charge in coulombs
     */
    static long double electricCharge(long double I, long double t, bool print = true);

    /**
     * @brief calculates the current (I) using the number of free charges(n) per unit
     * volume (Ax) where the charge per n is given by q and t is the unit time.
     * I = (q * n * Ax) / t;
     * @param q  the charge
     * @param n  the number of free charges
     * @param Ax  the volume of segment Ax is the area * distance
     * @param t  the unit time the charge is moved over
     * @param print  print to console
     * @return  the current
     */
    static long double current_qnAx_t(long double q,
                                      long double n,
                                      long double Ax,
                                      long double t, bool print = true);

    /**
     * @brief calculates the current (I) using the number of free charges(n) per unit
     * volume(A) each carrying a charge of q with a drift velocity of vd.
     * @param n  the number of free charges
     * @param q  the charge on each
     * @param A  the area
     * @param vd  the drift velocity
     * @param print  print to console
     * @return  the current
     */
    static long double current_nqAvd(long double n,
                                     long double q,
                                     long double A,
                                     long double vd, bool print = true);

    /**
     * @brief calculates the current using ohms law of voltage over resistances.
     * @param V  the voltage
     * @param R  the resistance
     * @param print  print to console
     * @return  the current in Amperes
     */
    static long double current_ohms(long double V, long double R, bool print = true);

    /**
     * @brief calculates the voltage using ohms law.
     * @param I  the current
     * @param R  the resistance
     * @param print  print to console
     * @return  the voltage in volts
     */
    static long double voltage_ohms(long double I, long double R, bool print = true);

    /**
     * @brief calculates the resistance using ohms law.
     * @param I  the current
     * @param V  the voltage
     * @param print  print to console
     * @return  the resistance in ohms
     */
    static long double resistance_ohms(long double I, long double V, bool print = true);

    /**
     * @brief calculates the current from rearranging the power equations
     * @param P  the power in watts
     * @param R  the resistance
     * @param print  print to console
     * @return  the current in amperes(I)
     */
    static long double current_PR(long double P, long double R, bool print = true);

    /**
     * @brief calculates the current from power and volts
     * @param P  the power in watts
     * @param V  the volts
     * @param print  print to console
     * @return
     */
    static long double current_PV(long double P, long double V, bool print = true);

    /**
     * @brief calculates the current from the voltage, diameter, resistivity
     * and length of a wire.
     * @param V  the voltage
     * @param d the diameter
     * @param rho  the resistivity
     * @param L  the length of the wire
     * @param print  print to console
     * @return  the current in amperes
     */
    static long double current_VdRhoL(
            long double V, long double d, long double rho, long double L, bool print = true);

    /**
     * @brief calculates the resistances of an ohmic conducting material
     * @param V  the volts
     * @param I  the current (A)
     * @param print  print to console
     * @return  the resistance
     */
    static long double resistance_ohmic(long double V, long double I, bool print = true);

    /**
     * @brief calculates the resistance of resistor with a resistivity of p and a
     * length of l with a area of A(pir^2, in a circular resistor).
     * @param p  the resistivity
     * @param l  the length
     * @param A  the cross sectional area
     * @param print  print to console
     * @return  the resistance
     */
    static long double resistanceUsingResistivity(long double p,
                                                  long double l,
                                                  long double A, bool print = true);

    /**
     * @brief calculate the resistance of a simple cylindrical resistor with wires
     * connected to the ends, such as the carbon composition resistors that are
     * used on electronic circuit boards. Imagine that the resistor is made by
     * squirting material whose conductivity is σ into a cylindrical mold with
     * length L and cross-sectional area A as shown in. Assume that this material
     * satisfies Ohm's law.
     * @param sigma  the conductivity
     * @param L  the length
     * @param A  the cross sectional area
     * @param print  print to console
     * @return  the resistance
     */
    static long double resistanceUsingConductivity(long double sigma,
                                                   long double L,
                                                   long double A, bool print = true);

    /**
     * @brief calculates the resistance of a piece of wire with a length of l,
     * having a diameter of d and a resistivity of p, which depends on the
     * material its made from. copper is a p = 1.72e-8 Ohms/m
     * @param p  the resistivity
     * @param l  the length
     * @param d  the diameter
     * @param print  print to console
     * @return  the resistance in Ohms
     */
    static long double resistanceUsingResistivityWire(long double p,
                                                      long double l,
                                                      long double d, bool print = true);

    /// <summary>
    /// calculates the cross sectional areas the of a resistor.
    /// </summary>
    /// <param name="p">The resistivity.</param>
    /// <param name="R">The Resistance.</param>
    /// <param name="l">The length.</param>
    /// <returns>area of resistor (m^2)</returns>
    /**
     * @brief calculates the cross sectional areas the of a resistor.
     * @param p  the resistivity
     * @param R  the Resistance
     * @param l  the length
     * @param print  print to console
     * @return  area of resistor (m^2)
     */
    static long double areaOfResistor(long double p,
                                      long double R,
                                      long double l, bool print = true);

    /**
     * @brief calculates the length of a resistor.
     * @param A  the cross sectional area
     * @param R  The resistance
     * @param p  The resistivity
     * @param print  print to console
     * @return  the length of resistor (m)
     */
    static long double lengthOfResistor(long double A,
                                        long double R,
                                        long double p, bool print = true);

    /**
     * @brief calculates the Lengths of filament.
     * @param d  the diameter
     * @param R  the resistance
     * @param p  the resistivity
     * @param print  print to console
     * @return  the length of filament (m)
     */
    static long double lengthOfFilament(long double d,
                                        long double R,
                                        long double p, bool print = true);

    /**
     * @brief As part of a class project you are given m g of copper and asked
     * to fabricate a wire with uniform cross-section. You use up m kg of the
     * copper and make a wire with a resistance of R Ω. The resistivity
     * of copper is p Ω · m and its density is pd kg/m^3
     * calculates the Lengths of filament.
     * @param m  the mass
     * @param R  the resistance
     * @param p  the resistivity
     * @param pd  the density
     * @param print  print to console
     * @return  the length of filament (m)
     */
    static long double lengthOfWireMade(long double m,
                                        long double R,
                                        long double p,
                                        long double pd, bool print = true);

    /**
     * @brief calculates the resistivity of a resistor.
     * @param R  The resistance
     * @param A  area
     * @param l  The length
     * @param print  print to console
     * @return  the resistivity
     */
    static long double resistivityOfResistor(long double R,
                                             long double A,
                                             long double l, bool print = true);

    /**
     * @brief Of what material is a wire made, if it is a length of (l)m long with a
     * (d)m diameter and has a resistance of R ohms at 20.0∘C
     * @param l  The length
     * @param d  The diameter
     * @param R  The resistance
     * @param print  print to console
     * @return  Ohm m
     */
    static long double resistivity(long double l,
                                   long double d,
                                   long double R, bool print = true);

    /**
     * @brief A d m-diameter rod carries a I A current when the electric
     * field in the rod is E V/m. Calculate the resistivity of the rod.
     * @param d  The diameter
     * @param I  The current
     * @param E  The electric field
     * @param print  print to console
     * @return  Ohm m
     */
    static long double resistivity_dIE(long double d,
                                   long double I,
                                   long double E, bool print = true);

    /**
     * @brief calculates the voltages drop across a resistor.
     * @param I  The current (Amperes)
     * @param R  The resistance
     * @param print  print to console
     * @return  The voltage
     */
    static long double voltageDropAcrossResistor(long double I, long double R, bool print = true);

    /**
     * @brief Calculates the drifts the velocity (V_d) of a common wire.
     * @param q  the charge
     * @param diameter  the diameter
     * @param I  the current (Amperes)
     * @param p  the density per kg/m^3
     * @param mass  the atomic mass
     * @param print  print to console
     * @return  drift velocity m/s
     */
    static long double driftVelocity_commonWire(long double q,
                                                long double diameter,
                                                long double I,
                                                long double p,
                                                long double mass, bool print = true);

    /**
     * @brief Drifts the velocity common wire n.
     * @param n  The number of electrons per cubic meter (density of
     *           conduction electrons)
     * @param q  The charge
     * @param diameter  The diameter
     * @param I  The current
     * @param print  print to console
     * @return  drift velocity m/s
     */
    static long double driftVelocity_commonWire_n(long double n,
                                                  long double q,
                                                  long double diameter,
                                                  long double I, bool print = true);

    /**
     * @brief Calculates the crosses sectional area
     * @param p  The resistivity
     * @param l  The length
     * @param R  The resistance
     * @param print  print to console
     * @return  cross sectional area (m^2)
     */
    static long double crossSectionalArea(long double p,
                                          long double l,
                                          long double R, bool print = true);

    /**
     * @brief Calculates the change in resistances from the effects of a
     * change in temperature.
     * @param R0  The initial colong double resistance
     * @param tCoR  The temperature coefficients of resistivity.
     * @param tempChange  The change in the temperature.
     * @param print  print to console
     * @return  the new resistance in Ohms
     */
    static long double resistanceChangeFromTemperature(long double R0,
                                                       long double tCoR,
                                                       long double tempChange, bool print = true);

    /**
     * @brief calculates the electrical power from current and volts
     * @param I  The current
     * @param V  The volts
     * @param print  print to console
     * @return  energy from electrical(W)
     */
    static long double electricalPower_IV(long double I, long double V, bool print = true);

    /**
     * @brief calculates the electrical power from volts and resistance
     * @param V  The volts
     * @param R  The resistance
     * @param print  print to console
     * @return  energy from electrical (W)
     */
    static long double electricalPower_VR(long double V, long double R, bool print = true);

    /**
     * @brief Some makes of olong doubleer cars have 6.00-V electrical systems. (a) What is
     * the hot resistance of a 30.0-W headlight in such a car?
     * @param P  The power.
     * @param V  The volts.
     * @param print  print to console
     * @return  resistance
     */
    static long double resistanceFromPowerAndVolts(long double P, long double V, bool print = true);

    /**
     * @brief Calculates the resistance from power and current.
     * @param P  The power.
     * @param I  The current.
     * @param print  print to console
     * @return  resistance
     */
    static long double resistanceFromPowerAndCurrent(long double P, long double I, bool print = true);

    /**
     * @brief calculates the electrical power from current and resistance
     * @param I  The current.
     * @param R  The resistance.
     * @param print  print to console
     * @return  energy from electrical (W)
     */
    static long double electricalPower_IR(long double I, long double R, bool print = true);

    /**
     * @brief A charge of (COULOMB) C of charge passes through a pocket calculator’s solar
     * cells in t seconds. What is the power output, given the calculator’s
     * voltage output is a voltage of V.
     * @param COULOMB  The charge.
     * @param t  The time.
     * @param V  The voltage.
     * @param print  print to console
     * @return  the watts
     */
    static long double powerOutputOverTime(long double Q, long double t, long double V, bool print = true);

    /**
     * @brief Calculates the total electrons  that pass through a charge.
     * @param COULOMB  The charge in coulombs.
     * @param print  print to console
     * @return  Ne, number of electrons
     */
    static long double electronsThatPassThroughACharge(long double Q, bool print = true);

    /**
     * @brief If a large cyclotron directs a beam of freeProtons nuclei onto a target
     * with a beam current of I Amperes. Calculate How many nuclei per second
     * this is.
     * @param I  The current.
     * @param freeProtons  The number of free protons.
     * @param print  print to console
     * @return  nuclei/second
     */
    static long double nucleiPerSecond(long double I, long double freeProtons, bool print = true);

    /**
     * @brief Calculates the ratio of the resistivity of wire1 to that of wire2, if they have
     * the same resistance per unit length (as they might in householong double wiring)
     * @param p1  The the bigger resistivity.
     * @param p2  The smaller resistivity.
     * @param print  print to console
     * @return  the ratio meaning the size of the smaller resistivity value will
     * to by this value bigger
     */
    static long double ratioOfDiametersInWires(long double p1, long double p2, bool print = true);

    /**
     * @brief Calculates the current flows through a diameter of (d) rod with a
     * resistivity of (p) that is a length of (l)m long, when (V) voltage is
     * applied to it? (Such a rod may be used to make nuclear- particle
     * detectors, for example.)
     * @param V  The applied voltage.
     * @param p  The resistivity.
     * @param d  The diameter.
     * @param l  The length.
     * @param print  print to console
     * @return  the Amperes
     */
    static long double currentFlowThroughOfMaterial(long double V,
                                                    long double p,
                                                    long double d,
                                                    long double l, bool print = true);

    /**
     * @brief A resistor made of Nichrome wire is used in an application where its
     * resistance cannot change more than 1.00% from its value at 20.0∘C .
     * Over what temperature range can it be used?
     * @param tempCoEffOfResistivity  The temperature coefficient of resistivity.
     * @param maxChangePercent  The maximum change percent.
     * @param print  print to console
     * @return  temperature
     */
    static long double maximumTempchange(long double tempCoEffOfResistivity,
                                         long double maxChangePercent, bool print = true);

    /**
     * @brief With a 1200-W toaster, how much electrical energy is needed to make a
     * slice of toast (cooking time = 1 minute)? At 9.0 cents/kW⋅h, how much does this cost?
     * @param P  The power inWatts.
     * @param t  The time in seconds.
     * @param ratePerKwh  The rate per KWH.
     * @param print  print to console
     * @return  total cost to use electricity
     */
    static long double costOfElectricityUsed_kWh(long double P,
                                                 long double t,
                                                 long double ratePerKwh, bool print = true);

    /**
     * @brief An olong double light bulb draws only 50.0 W, rather than its original 60.0 W,
     * due to evaporative thinning of its filament. By what factor is its
     * diameter reduced, assuming uniform thinning along its length? Neglect
     * any effects caused by temperature differences.
     * @param Pi  The starting wattage.
     * @param Pf  The final wattage.
     * @param print  print to console
     * @return  factor which diameter decreases
     */
    static long double factorDiameterReduced(long double Pi, long double Pf, bool print = true);

    /**
     * @brief Calculates the total time.
     * @param COULOMB  The charge.
     * @param P  The power.
     * @param print  print to console
     * @return  time
     */
    static long double timeTotal(long double Q, long double P, bool print = true);

    /**
     * @brief Calculates the total time.
     * @param COULOMB  The charge.
     * @param I  The current.
     * @param V  The volts.
     * @param print  print to console
     * @return  time
     */
    static long double timeTotal(long double Q, long double I, long double V, bool print = true);

    /**
     * @brief Calculates the total time.
     * @param m1  The mass of tissue.
     * @param c  The specific heat of water(sub new substance value).
     * @param Ti  The initial temperature.
     * @param Tf  The temperature to raise to.
     * @param m2  The mass of water to boil.
     * @param Lv  The latent heat of vaporization .
     * @param I  The current.
     * @param V  The volts.
     * @param print  print to console
     * @return  time
     */
    static long double timeToRaiseTemperature(long double m1,
                                              long double c,
                                              long double Ti,
                                              long double Tf,
                                              long double m2,
                                              long double Lv,
                                              long double I,
                                              long double V, bool print = true);

    /**
     * @brief Calculates the cost of heating a hot tub containing 1500 kg of water from
     * 10.0∘C to 40.0∘C , assuming 75.0% efficiency to account for heat
     * transfer to the surroundings? The cost of electricity is 9 cents/kW ⋅h .
     * @param m  The mass of the water.
     * @param c  The specific heat.
     * @param Ti  The initial temp.
     * @param Tf  The final temp.
     * @param eff  The eff.
     * @param rate  The rate.
     * @param print  print to console
     * @return  cost in cents
     */
    static long double costToHeatHotTub(long double m,
                                        long double c,
                                        long double Ti,
                                        long double Tf,
                                        long double eff,
                                        long double rate, bool print = true);

    /**
     * @brief Calculates the RMS current.
     * @param Io  The peek current.
     * @param print  print to console
     * @return  rms current
     */
    static long double rmsCurrent(long double Io, bool print = true);

    /**
     * @brief Calculates the peek current.
     * @param Irms  The rms current.
     * @param print  print to console
     * @return  peek current
     */
    static long double peekCurrent(long double Irms, bool print = true);

    /**
     * @brief Calculate the steady current of a charge of Q coulombs flowing
     * through a time of t seconds.
     * @param Q The charge in coulombs.
     * @param t The time in seconds.
     * @param print If true, print the result.
     * @return The current in amperes.
     */
    static long double steadyCurrent(
            long double Q, long double t, bool print = true);

    /**
     * @brief Calculate the instantaneous current of a charge with a maximum
     * current of I_max amperes, with an angular frequency of w radians per
     * second, at a time of t seconds.
     * @param I_max The maximum current in amperes.
     * @param w The angular frequency in radians per second.
     * @param t The time in seconds.
     * @param print If true, print the result.
     * @return The current in amperes.
     */
    static long double instantaneousCurrent(
            long double I_max, long double w, long double t, bool print = true);

    /**
     * @brief Calculates the RMS voltage.
     * @param Vo  The peek voltage.
     * @param print  print to console
     * @return  voltage
     */
    static long double rmsVoltage(long double Vo, bool print = true);

    /**
     * @brief Calculates the peek voltage.
     * @param Vrms  The rms voltage.
     * @param print  print to console
     * @return  peek voltage
     */
    static long double peekVoltage(long double Vrms, bool print = true);

    /**
     * @brief What is the peak power consumption of a Vrms AC microwave oven
     * that draws Irms A?
     * @param Vrms  The rms voltage.
     * @param Irms  The rms current.
     * @param print  print to console
     * @return  peak power
     */
    static long double peekPower(long double Vrms, long double Irms, bool print = true);

    /**
     * @brief Calculates the voltage at a given time.
     * @param Vo  The peek voltage.
     * @param f  The frequency in hertz.
     * @param t  The time we are looking to find the voltage at.
     * @param print  print to console
     * @return  voltage
     */
    static long double voltageAC(long double Vo, long double f, long double t, bool print = true);

    /**
     * @brief Calculates the current at a given time.
     * @param Io  The peek current (Io = Vo/R).
     * @param f  The frequency in hertz.
     * @param t  The time we are looking to find the current at.
     * @param print  print to console
     * @return  amperes
     */
    static long double currentAC(long double Io, long double f, long double t, bool print = true);

    /**
     * @brief Calculates the temperature coefficient of resistivity.
     * @param R  The resistance.
     * @param R_o  The resistance at 0 degrees.
     * @param T_i  The initial temp.
     * @param T_f  The final temp.
     * @param print  print to console
     * @return  temp coeff of resistivity
     */
    static long double tempCoeffOfResistivity(long double R,
                                              long double R_o,
                                              long double T_i,
                                              long double T_f, bool print = true);

    /**
     * @brief Currents aren’t always confined to wires. Currents in Earth, in
     * chemical solutions, in your body, and in ionized gases flow in ill-defined
     * paths, and their magnitude and direction may vary with position. We
     * characterize such diffuse currents in terms of current density,
     * a vector whose direction at each point is that of the local current and
     * whose magnitude is the current per unit area.
     * Dividing by area and using the drift velocity vector instead of speed
     * gives the current density: J = n q v_drift
     * @param n  The number of particles.
     * @param q  The charge of the particle.
     * @param v  The drift velocity.
     * @param print  print to console
     * @return  current density
     */
    static long double currentDensity_nqv(long double n, long double q, long double v, bool print = true);

    /**
     * @brief Calculates the current density.
     * @param p  The current.
     * @param E  The area.
     * @param print  print to console
     * @return  current density
     */
    static long double currentDensity_IA(long double I, long double A, bool
    print = true);

    /**
     * @brief Calculates the current density of a wire with a resistivity of
     * ρ and and electric field of E mV/m.
     * @param I the resistivity of the wire
     * @param A the electric field of the wire
     * @param print print to console
     * @return current density
     */
    static long double currentDensity_pE(long double p, long double E, bool print = true);


    /**
     * A d m-diameter wire with a resistivity of p, carries I A to a household
     * appliance.
     * Calculate the magnitude of the electric field in the wire.
     * @param I  The current.
     * @param p  The resistivity.
     * @param d  The diameter.
     * @param print  print to console
     * @return  electric field
     */
    static long double electricFieldInWire(
            long double I, long double p, long double d, bool print = true);

    /**
     * @brief A metallic wire has a diameter of d m. When the current in the
     * wire is I A, the drift velocity is V_d m/s. Calculate the density of
     * the free electrons in the wire.
     * @param I  The current.
     * @param V_d  The drift velocity.
     * @param d  The diameter.
     * @param print  print to console
     * @return  electron density
     */
    static long double electronDensity(
            long double I, long double V_d, long double d, bool print = true);

    /**
     * A wire carries a current of I A. Calculate how many electrons pass
     * through the wire in t seconds.
     * @param I The current.
     * @param t The time.
     * @param print If true, print the result.
     * @return The number of electrons.
     */
    static long double electronsPassed(long double I, long double t, bool print = true);

    /**
     * @brief A piece of wire made from metal A joins a piece of wire metal B
     * whose diameter is x times that of the wire A. The same current flows in
     * both wires. The density of conduction electrons for wire A is nA and the
     * density of conduction electrons for wire B is nB. Calculate the ratio of
     * the drift velocities of the electrons in the two wires and compare the
     * current densities in the two wires.
     * @param nA  The electron density of wire A.
     * @param nB  The electron density of wire B.
     * @param x  The ratio of the diameters of wire B to wire A.
     * @param print  print to console
     * @return  drift velocity ratio and current density ratio
     */
    static long double electronDriftVelocityRatio(
            long double nA, long double nB, long double x, bool print = true);

    /**
     * @brief A potential difference of V (V) is imposed across a l m length
     * of g gauge wire. As a result, a I A current flows in the wire.
     * Calculate the resistivity of the wire.
     * @param V  The potential difference.
     * @param I  The current.
     * @param l  The length.
     * @param g  The gauge.
     * @param print  print to console
     * @return  resistivity
     */
    static long double resistivity(long double V, long double I, long double l,
                                   int g, bool print = true);


    void setElectricCurrentVal(long double val) { _electricCurrentVal = val; }

    ~ElectricCurrent()
    {
        countDecrease();
    }

private:
    long double _electricCurrentVal;
    static void countIncrease() { electricCurrent_objectCount += 1; }
    static void countDecrease() { electricCurrent_objectCount -= 1; }

};

inline long double ElectricCurrent::circle_area_r(const long double r, bool print)
{
    auto val =  constants::PI * (r*r);//m^2
    if (print)
    {
        std::cout << "Area of a circle with radius " << r << " is " << val << " m^2" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::circle_area_d(const long double d, bool print)
{
    auto val =  constants::PI*((d*d)/4);//m^2
    if (print)
    {
        std::cout << "Area of a circle with diameter " << d << " is " << val << " m^2" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::electricCurrent(const long double Q, const long double t, bool print)
{
    auto val =  Q / t;//Amperes(I)
    if (print)
    {
        std::cout << "The electric current is " << val << " Amperes(I)" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::timeItTakesChargeToFlow(const long double Q, const long double I, bool print)
{
    auto val =  Q / I;//seconds(s)
    if (print)
    {
        std::cout << "The time it takes for the charge to flow is " << val << " seconds(s)" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::electricCharge(const long double I, const long double t, bool print)
{
    auto val =  I * t;//Coulombs(C)
    if (print)
    {
        std::cout << "The electric charge is " << val << " Coulombs(C)" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::current_qnAx_t(const long double q,
                                          const long double n,
                                          const long double Ax,
                                          const long double t, bool print)
{
    auto val =  (q * n * Ax) / t;//Amperes or Coulombs/second
    if (print)
    {
        std::cout << "The current is " << val << " Amperes or Coulombs/second" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::current_nqAvd(const long double n,
                                         const long double q,
                                         const long double A,
                                         const long double vd, bool print)
{
    auto val =  n * q * A * vd;//Amperes or C/s
    if (print)
    {
        std::cout << "The current is " << val << " Amperes or C/s" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::current_ohms(const long double V, const long double R, bool print)
{
    auto val =  V / R;//Amperes(I)
    if (print)
    {
        std::cout << "The current is " << val << " Amperes(I)" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::current_PR(const long double P, const long double R, bool print)
{
    auto val =  sqrt(P/R);//Amperes(I)
    if (print)
    {
        std::cout << "The current is " << val << " Amperes(I)" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::current_PV(const long double P, const long double V, bool print)
{
    auto val =  P/V;//Amperes
    if (print)
    {
        std::cout << "The current is " << val << " Amperes" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::resistance_ohmic(const long double V, const long double I, bool print)
{
    auto val =  V / I;//Ohms
    if (print)
    {
        std::cout << "The resistance is " << val << " Ohms" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::resistanceUsingResistivity(
        const long double p, const long double l, const long double A, bool print)
{
    auto val =  p*(l  / A);//Ohms
    if (print)
    {
        std::cout << "The resistance is " << val << " Ohms" << std::endl;
    }
    return val;
}


inline long double ElectricCurrent::resistanceUsingResistivityWire(
        const long double p, const long double l, const long double d, bool print)
{
    auto A = circle_area_d(d);
    auto r =  (p * l) / A;//Ohms
    if (print)
    {
        std::cout << "The resistance is " << r << " Ohms" << std::endl;
    }
    return r;
}

inline long double ElectricCurrent::areaOfResistor(
        const long double p, const long double R, const long double l, bool print)
{
    auto val =  p * (l / R);//m^2
    if (print)
    {
        std::cout << "The area of the resistor is " << val << " m^2" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::lengthOfResistor(
        const long double A, const long double R, const long double p, bool print)
{
    auto val =  (A * R) / p;//m
    if (print)
    {
        std::cout << "The length of the resistor is " << val << " m" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::lengthOfFilament(
        const long double d, const long double R, const long double p, bool print)
{
    auto val =  (constants::PI*(d*d)*R)/(4.0*p);//meters
    if (print)
    {
        std::cout << "The length of the filament is " << val << " meters" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::lengthOfWireMade(
        const long double m, const long double R, const long double p,
        const long double pd, bool print)
{
    auto val =  sqrt((m*R)/(pd*p));//m
    if (print)
    {
        std::cout << "The length of the wire is " << val << " m" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::resistivityOfResistor(
        const long double R, const long double A, const long double l, bool print)
{
    auto val =  (A * R) / l;//Ohms/m
    if (print)
    {
        std::cout << "The resistivity of the resistor is " << val << " Ohms/m" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::resistivity(const long double l, const long double d, const long double R, bool print)
{
    auto val =  (constants::PI*(d*d)*R)/(4.0*l);//Ohms meters
    if (print)
    {
        std::cout << "The resistivity is " << val << " Ohms meters" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::voltageDropAcrossResistor(const long double I, const long double R, bool print)
{
    auto val =  I * R;//volts
    if (print)
    {
        std::cout << "The voltage drop across the resistor is " << val << " volts" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::driftVelocity_commonWire(const long double q,
                                                    const long double diameter,
                                                    const long double I,
                                                    const long double p,
                                                    const long double mass, bool print)
{
    const long double n = (constants::AVOGADRO * 1000.0 * p) / (mass);
    auto val =  I / (n * q * (constants::PI*pow(diameter/2.0,2)));
    if (print)
    {
        std::cout << "The drift velocity is " << val << " m/s" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::driftVelocity_commonWire_n(const long double n,
                                                      const long double q,
                                                      const long double diameter,
                                                      const long double I, bool print)
{
    auto val =  I / (n * q * (constants::PI * pow(diameter / 2, 2)));
    if (print)
    {
        std::cout << "The drift velocity is " << val << " m/s" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::crossSectionalArea(const long double p, const long double l, const long double R, bool print)
{
    auto val =  (p * l) / R;
    if (print)
    {
        std::cout << "The cross sectional area is " << val << " m^2" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::resistanceChangeFromTemperature(const long double R0,
                                                           const long double tCoR,
                                                           const long double tempChange, bool print)
{
    auto val =  R0 * (1.0 + tCoR * tempChange);
    if (print)
    {
        std::cout << "The resistance change is " << val << " Ohms" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::electricalPower_IV(const long double I, const long double V, bool print)
{
    auto P =  I * V;//Watts
    if (print)
    {
        std::cout << "The electrical power is " << P << " Watts" << std::endl;
    }
    return P;
}

inline long double ElectricCurrent::electricalPower_VR(const long double V, const long double R, bool print)
{
    auto val =  (V * V) / R;//Watts
    if (print)
    {
        std::cout << "The electrical power is " << val << " Watts" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::resistanceFromPowerAndVolts(const long double P, const long double V, bool print)
{
    auto val =  (V*V)/P;//Ohms
    if (print)
    {
        std::cout << "The resistance is " << val << " Ohms" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::resistanceFromPowerAndCurrent(const long double P, const long double I, bool print)
{
    auto val =  P/(I*I);//Ohms
    if (print)
    {
        std::cout << "The resistance is " << val << " Ohms" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::electricalPower_IR(const long double I, const long double R, bool print)
{
    auto val =  (I * I) * R;//Watts
    if (print)
    {
        std::cout << "The electrical power is " << val << " Watts" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::powerOutputOverTime(const long double Q, const long double t, const long double V, bool print)
{
    auto val =  (Q/t)*V;//watts
    if (print)
    {
        std::cout << "The power output is " << val << " Watts" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::electronsThatPassThroughACharge(const long double Q, bool print)
{
    auto val =  Q / constants::PROTON_CHARGE;
    if (print)
    {
        std::cout << "The number of electrons that pass through a charge is " << val << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::nucleiPerSecond(const long double I, const long double freeProtons, bool print)
{
    auto val =  I / (freeProtons * constants::PROTON_CHARGE);
    if (print)
    {
        std::cout << "The number of nuclei per second is " << val << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::ratioOfDiametersInWires(const long double p1, const long double p2, bool print)
{
    auto val =  sqrt(p1/p2);
    if (print)
    {
        std::cout << "The ratio of diameters is " << val << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::currentFlowThroughOfMaterial(const long double V,
                                                        const long double p,
                                                        const long double d,
                                                        const long double l, bool print)
{
    auto val =  (V*constants::PI*(d*d))/(4.0*p*l);//Amperes(I)
    if (print)
    {
        std::cout << "The current flow through the material is " << val << " Amperes" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::maximumTempchange(
        const long double tempCoEffOfResistivity,
        const long double maxChangePercent, bool print)
{
    auto val =  (maxChangePercent/100)/tempCoEffOfResistivity;
    if (print)
    {
        std::cout << "The maximum temperature change is " << val << " degrees Celsius" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::costOfElectricityUsed_kWh(const long double P,
                                                     const long double t,
                                                     const long double ratePerKwh, bool print)
{
    const long double joules = P * t;
    auto val =  (joules * ratePerKwh)/(1000.0*3600);
    if (print)
    {
        std::cout << "The cost of electricity used is " << val << " dollars" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::factorDiameterReduced(const long double Pi, const long double Pf, bool print)
{
    auto val =  sqrt(Pf / Pi);
    if (print)
    {
        std::cout << "The factor of diameter reduced is " << val << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::timeTotal(const long double Q, const long double P, bool print)
{
    auto val =  Q / P;//seconds
    if (print)
    {
        std::cout << "The time total is " << val << " seconds" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::timeTotal(const long double Q, const long double I, const long double V, bool print)
{
    auto val =  Q/(I*V);
    if (print)
    {
        std::cout << "The time total is " << val << " seconds" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::timeToRaiseTemperature(const long double m1,
                                                  const long double c,
                                                  const long double Ti,
                                                  const long double Tf,
                                                  const long double m2,
                                                  const long double Lv,
                                                  const long double I,
                                                  const long double V, bool print)
{
    auto val =  (m1*c*(Tf-Ti)+ m2*Lv)/(I*V);//time(s)
    if (print)
    {
        std::cout << "The time to raise the temperature is " << val << " seconds" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::costToHeatHotTub(const long double m,
                                            const long double c,
                                            const long double Ti,
                                            const long double Tf,
                                            const long double eff,
                                            const long double rate, bool print)
{
    auto val =  ((m*c*(Tf-Ti))/eff)*(rate/(1000.0*3600));
    if (print)
    {
        std::cout << "The cost to heat the hot tub is " << val << " dollars" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::rmsCurrent(const long double Io, bool print)
{
    auto val =  Io/sqrt(2);
    if (print)
    {
        std::cout << "The RMS current is " << val << " Amperes" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::peekCurrent(const long double Irms, bool print)
{
    auto val =  sqrt(2) * Irms;
    if (print)
    {
        std::cout << "The peek current is " << val << " Amperes" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::rmsVoltage(const long double Vo, bool print)
{
    auto val =  Vo / sqrt(2);
    if (print)
    {
        std::cout << "The RMS voltage is " << val << " Volts" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::peekVoltage(const long double Vrms, bool print)
{
    auto val =  sqrt(2)*Vrms;
    if (print)
    {
        std::cout << "The peek voltage is " << val << " Volts" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::peekPower(const long double Vrms, const long double Irms, bool print)
{
    auto val =  2.0*(Vrms*Irms);
    if (print)
    {
        std::cout << "The peek power is " << val << " Watts" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::voltageAC(const long double Vo, const long double f, const long double t, bool print)
{
    auto val =  Vo * sin(2*constants::PI)*f*t;// volts
    if (print)
    {
        std::cout << "The voltage AC is " << val << " Volts" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::currentAC(const long double Io, const long double f, const long double t, bool print)
{
    auto val =  Io * sin(2 * constants::PI) * f * t;//amperes
    if (print)
    {
        std::cout << "The current AC is " << val << " Amperes" << std::endl;
    }
    return val;
}

inline long double ElectricCurrent::tempCoeffOfResistivity(const long double R,
                                                  const long double R_o,
                                                  const long double T_i,
                                                  const long double T_f, bool print)
{
    auto val =  ((R / R_o) - 1.0) / (T_f - T_i);
    if (print)
    {
        std::cout << "The temperature coefficient of resistivity is " << val << " degrees Celsius^-1" << std::endl;
    }
    return val;
}

long double
ElectricCurrent::steadyCurrent(long double Q, long double t, bool print) {
    long double I = Q / t;
    if (print) {
        std::cout << "I = " << I << " A" << std::endl;
    }
    return I;
}

long double
ElectricCurrent::instantaneousCurrent(long double I_max, long double w,
                                      long double t, bool print) {
    long double I = I_max * sin(w * t);
    if (print) {
        std::cout << "I = " << I << " A" << std::endl;
    }
    return I;
}

long double
ElectricCurrent::currentDensity_nqv(long double n, long double q, long double v,
                                    bool print) {
    long double J = n * q * v;
    if (print) {
        std::cout << "J = " << J << " A" << std::endl;
    }
    return J;
}

long double
ElectricCurrent::currentDensity_IA(long double I, long double A, bool print) {
    long double J = I / A;
    if (print) {
        std::cout << "J = " << J << " A" << std::endl;
    }
    return J;
}

long double
ElectricCurrent::currentDensity_pE(long double p, long double E, bool print) {
    long double J = E / p;
    if (print) {
        std::cout << "J = " << J << " A" << std::endl;
    }
    return J;
}

long double ElectricCurrent::electricFieldInWire(long double I, long double p,
                                                 long double d, bool print) {
    long double E = (I * p) / (constants::PI * d * d);
    if (print) {
        std::cout << "E = " << E << " V/m" << std::endl;
    }
    return E;
}

long double
ElectricCurrent::voltage_ohms(long double I, long double R, bool print) {
    long double V = I * R;
    if (print) {
        std::cout << "V = " << V << " V" << std::endl;
    }
    return V;
}

long double
ElectricCurrent::resistance_ohms(long double I, long double V, bool print) {
    long double R = V / I;
    if (print) {
        std::cout << "R = " << R << " Ohms" << std::endl;
    }
    return R;
}

long double
ElectricCurrent::electronDensity(long double I, long double V_d, long double d,
                                 bool print) {
    auto A = circle_area_d(d, false);
    auto e = -constants::ELECTRON_CHARGE;
    auto n = I / (e * V_d * A);
    if (print) {
        std::cout << "n = " << n << " m^-3" << std::endl;
    }
    return n;
}

long double
ElectricCurrent::resistanceUsingConductivity(long double sigma, long double L,
                                             long double A, bool print) {
    long double R = L / (sigma * A);
    if (print) {
        std::cout << "R = " << R << " Ohms" << std::endl;
    }
    return R;
}

long double
ElectricCurrent::electronsPassed(long double I, long double t, bool print) {
    auto e = -constants::ELECTRON_CHARGE;
    auto q = I * t;
    auto n = q / e;
    if (print) {
        std::cout << "n = " << n << " electrons" << std::endl;
    }
    return n;
}

long double
ElectricCurrent::resistivity_dIE(long double d, long double I, long double E,
                                 bool print) {
    auto A = circle_area_d(d, false);
    auto R = (E * A) / I;
    if (print) {
        std::cout << "R = " << R << " Ohms" << std::endl;
    }
    return R;
}

long double
ElectricCurrent::electronDriftVelocityRatio(long double nA, long double nB,
                                            long double x, bool print) {
    auto ratio = (nB * x * x) / (nA);
    auto pi = constants::PI;
    auto J_J = pow((x * pi)/2, 2) / pow((pi/2.0), 2);
    if (print) {
        std::cout << "ratio = " << ratio << std::endl;
        std::cout << "J/J = " << J_J << std::endl;
    }
    return ratio;
}

long double
ElectricCurrent::resistivity(
        long double V, long double I, long double l, int g, bool print) {
    auto R = V / I;
    auto d = AWG.convertGauge2Diameter(g);
    auto A = circle_area_d(d, false);
    auto rho = R * (A / l);
    if (print) {
        std::cout << "rho = " << rho << " Ohm-m" << std::endl;
    }
    return rho;
}

long double
ElectricCurrent::current_VdRhoL(long double V, long double d, long double rho,
                                long double L, bool print) {
    auto A = circle_area_d(d, false);
    auto I = (V * A) / (rho * L);
    if (print) {
        std::cout << "I = " << I << " A" << std::endl;
    }
    return I;
}

long double ElectricCurrent::sphere_area_r(long double r, bool print) {
    auto A = 4 * constants::PI * r * r;
    if (print) {
        std::cout << "A = " << A << " m^2" << std::endl;
    }
    return A;
}

long double ElectricCurrent::sphere_area_d(long double d, bool print) {
    auto r = d / 2.0;
    auto A = 4 * constants::PI * r * r;
    if (print) {
        std::cout << "A = " << A << " m^2" << std::endl;
    }
    return A;
}

long double ElectricCurrent::circle_area_c(long double c, bool print) {
    auto A = constants::PI * c * c;
    if (print) {
        std::cout << "A = " << A << " m^2" << std::endl;
    }
    return A;
}

long double ElectricCurrent::sphere_area_c(long double c, bool print) {
    auto A = 4 * constants::PI * c * c;
    if (print) {
        std::cout << "A = " << A << " m^2" << std::endl;
    }
    return A;
}

long double ElectricCurrent::circle_area_gauge(int gauge, bool print) {
    auto d = AWG.convertGauge2Diameter(gauge);
    auto A = circle_area_d(d, false);
    if (print) {
        std::cout << "A = " << A << " m^2" << std::endl;
    }
    return A;
}

long double ElectricCurrent::square_area(long double side, bool print) {
    auto A = side * side;
    if (print) {
        std::cout << "A = " << A << " m^2" << std::endl;
    }
    return A;
}

long double
ElectricCurrent::rectangle_area(long double l, long double w, bool print) {
    auto A = l * w;
    if (print) {
        std::cout << "A = " << A << " m^2" << std::endl;
    }
    return A;
}


#endif //PHYSICSFORMULA_ELECTRICCURRENT_H
