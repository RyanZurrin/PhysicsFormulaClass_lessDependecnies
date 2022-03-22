//
// Created by Ryan.Zurrin001 on 12/15/2021.
//

#ifndef PHYSICSFORMULA_CIRCUITS_H
#define PHYSICSFORMULA_CIRCUITS_H
/**
 * @class Circuits
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @dateBuilt  3/3/2021
 * @lastEdit 3/3/2021
 */
#include <iostream>
#include "ElectricCurrent.h"

static int circuits_objectCount = 0;

class Circuits:
        public ElectricCurrent
{

public:
    Circuits* _circuitPtr;


    Circuits()
    {
        _circuitPtr = nullptr;
        _circuitVal = 0.0;
        countIncrease();
    }
    Circuits(long double val)
    {
        _circuitPtr = nullptr;
        _circuitVal = val;
        countIncrease();
    }

    /**
     * @brief copy constructor
     */
    Circuits(const Circuits& c)
    {
        _circuitPtr = c._circuitPtr;
        _circuitVal = 0.0;
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    Circuits(Circuits&& c) noexcept
    {
        _circuitPtr = c._circuitPtr;
        _circuitVal = c._circuitVal;
        countIncrease();
    }
    /**
     * @brief copy assignment operator
     */
    Circuits& operator=(const Circuits& c)
    {
        if (this != &c)
        {
            _circuitPtr = c._circuitPtr;
            _circuitVal = c._circuitVal;
            countIncrease();
        }
        return *this;
    }

    static void show_objectCount() { std::cout << "\n circuits object count: "
                                               << circuits_objectCount << std::endl; }
    static int get_objectCount() { return circuits_objectCount; }

    constexpr void setCircuitVal(long double val) { _circuitVal = val; }


    /// <summary>
    /// Calculates the total resistance of a Series of   resistors.
    /// </summary>
    /// <param name="R1">The resistor 1.</param>
    /// <param name="R2">The resistor 2.</param>
    /// <param name="R3">The resistor 3.</param>
    /// <param name="R4">The resistor 4.</param>
    /// <param name="R5">The resistor 5.</param>
    /// <param name="R6">The resistor 6.</param>
    /// <param name="R7">The resistor 7.</param>
    /// <param name="R8">The resistor 8.</param>
    /// <param name="R9">The resistor 9.</param>
    /// <param name="R10">The resistor 10.</param>
    /// <returns>resistance in ohms</returns>
    static constexpr long double seriesResistance(const long double R1, const long double R2, const long double R3, const long double R4,
                                                  const long double R5, const long double R6, const long double R7, const long double R8, const long double R9, const long double R10);

    /// <summary>
    /// Calculates the total resistance of resistors hooked up in parallel.
    /// </summary>
    /// <param name="R1">The resistor 1.</param>
    /// <param name="R2">The resistor 2.</param>
    /// <param name="R3">The resistor 3.</param>
    /// <param name="R4">The resistor 4.</param>
    /// <param name="R5">The resistor 5.</param>
    /// <param name="R6">The resistor 6.</param>
    /// <param name="R7">The resistor 7.</param>
    /// <param name="R8">The resistor 8.</param>
    /// <param name="R9">The resistor 9.</param>
    /// <param name="R10">The resistor 10.</param>
    /// <returns>resistance in ohms</returns>
    static constexpr long double parallelResistance(const long double R1, const long double R2, const long double R3, const long double R4,
                                                    const long double R5, const long double R6, const long double R7, const long double R8, const long double R9, const long double R10);

    /// <summary>
    /// Calculates the total capacitor of a Series of   capacitors.
    /// </summary>
    /// <param name="C1">The capacitor 1.</param>
    /// <param name="C2">The capacitor 2.</param>
    /// <param name="C3">The capacitor 3.</param>
    /// <param name="C4">The capacitor 4.</param>
    /// <param name="C5">The capacitor 5.</param>
    /// <param name="C6">The capacitor 6.</param>
    /// <param name="C7">The capacitor 7.</param>
    /// <param name="C8">The capacitor 8.</param>
    /// <param name="C9">The capacitor 9.</param>
    /// <param name="C10">The capacitor 10.</param>
    /// <returns>capacitance (F)</returns>
    static constexpr long double seriesCapacitance(const long double C1, const long double C2, const long double C3, const long double C4,
                                                   const long double C5, const long double C6, const long double C7, const long double C8, const long double C9, const long double C10);

    /// <summary>
    /// Calculates the total resistance of resistors hooked up in parallel.
    /// </summary>
    /// <param name="C1">The capacitor 1.</param>
    /// <param name="C2">The capacitor 2.</param>
    /// <param name="C3">The capacitor 3.</param>
    /// <param name="C4">The capacitor 4.</param>
    /// <param name="C5">The capacitor 5.</param>
    /// <param name="C6">The capacitor 6.</param>
    /// <param name="C7">The capacitor 7.</param>
    /// <param name="C8">The capacitor 8.</param>
    /// <param name="C9">The capacitor 9.</param>
    /// <param name="C10">The capacitor 10.</param>
    /// <returns>capacitance (F)</returns>
    static constexpr long double parallelCapacitance(const long double C1, const long double C2, const long double C3, const long double C4,
                                                     const long double C5, const long double C6, const long double C7, const long double C8, const long double C9, const long double C10);


    /// <summary>
    /// Calculates the terminal  voltage.
    /// </summary>
    /// <param name="emf">The electromotive force.</param>
    /// <param name="r">The internal resistance.</param>
    /// <param name="I">The Charge.</param>
    /// <returns>Voltage</returns>
    static constexpr long double terminalVoltage(const long double emf, const long double r, const long double I);


    /// <summary>
    /// Calculates the Current of a  ohms law.
    /// </summary>
    /// <param name="emf">The EMF.</param>
    /// <param name="RLoad">The resistance load of all resistors connected.</param>
    /// <param name="r">The internal resistance.</param>
    /// <returns>current I in amperes</returns>
    static constexpr long double current_OhmsLaw(const long double emf, const long double RLoad, const long double r);

    /// <summary>
    /// Calculates the powers dissipated
    /// </summary>
    /// <param name="I">The current.</param>
    /// <param name="Rload">The Resistance load.</param>
    /// <returns>power output in watts (W)S</returns>
    static constexpr long double powerDissipation(const long double I, const long double R);

    /// <summary>
    /// add the total emfs for a series connection. where emf is the electromagnetic force
    /// </summary>
    /// <param name="emf1">The emf1.</param>
    /// <param name="emf2">The emf2.</param>
    /// <param name="emf3">The emf3.</param>
    /// <param name="emf4">The emf4.</param>
    /// <returns>net emf</returns>
    static constexpr long double emfsParallelConnection_added(const long double emf1, const long double emf2, const long double emf3, const long double emf4);

    /// <summary>
    /// add the total emfs for a series connection. where emf is the electromagnetic force
    /// </summary>
    /// <param name="emf1">The emf1.</param>
    /// <param name="emf2">The emf2.</param>
    /// <param name="emf3">The emf3.</param>
    /// <param name="emf4">The emf4.</param>
    /// <returns></returns>
    static constexpr long double emfsSeriesConnection_subtracted(const long double emf1, const long double emf2, const long double emf3, const long double emf4);

    /// <summary>
    /// calculates the internals resistance.
    /// </summary>
    /// <param name="Vt">The terminal voltage.</param>
    /// <param name="E">The emf.</param>
    /// <param name="I">The current.</param>
    /// <returns>the internal resistance (r)</returns>
    static constexpr long double internalResistance(const long double Vt, const long double E, const long double I);

    /// <summary>
    /// calculates the RC time constant of a circuit containing a resistor and a
    /// capacitor.
    /// </summary>
    /// <param name="R">The resistance.</param>
    /// <param name="C">The capacitance.</param>
    /// <returns>tau(Greek letter)</returns>
    static constexpr long double timeConstant_RC(const long double R, const long double C);

    /// <summary>
    /// calculates the resistances from time constant and capacitance.
    /// </summary>
    /// <param name="tau">The tau(time constant).</param>
    /// <param name="C">The capacitance.</param>
    /// <returns>the resistance Ohms</returns>
    static constexpr long double resistance_fromTimeConstant(const long double tau, const long double C);

    /// <summary>
    /// calculates the capacitance from time constant and resistance.
    /// </summary>
    /// <param name="tau">The tau.</param>
    /// <param name="R">The resistance.</param>
    /// <returns></returns>
    static constexpr long double capacitance_fromTimeConstant(const long double tau, const long double R);

    /// <summary>
    /// Voltages the vs time charging capacitor.
    /// </summary>
    /// <param name="emf">The EMF.</param>
    /// <param name="t">The time.</param>
    /// <param name="R">The resistance.</param>
    /// <param name="C">The capacitance.</param>
    /// <returns></returns>
    static long double voltageVsTimeChargingCapacitor(const long double emf, const long double t, const long double R, const long double C);

    /// <summary>
    /// calculates the Frequency from cycles and seconds.
    /// </summary>
    /// <param name="cycles">The cycles.</param>
    /// <param name="seconds">The seconds.</param>
    /// <returns>frequency</returns>
    static constexpr long double frequency(const long double cycles, const long double seconds);

    /// <summary>
    /// Frequencies the specified period.
    /// </summary>
    /// <param name="period">The period.</param>
    /// <returns></returns>
    static constexpr long double frequency(const long double period);

    /// <summary>
    /// calculates the periods from the specified f.
    /// </summary>
    /// <param name="f">The f.</param>
    /// <returns>period</returns>
    static constexpr long double period(const long double f);


    /// <summary>
    /// Resistances from DC equations.
    /// </summary>
    /// <param name="t">The time.</param>
    /// <param name="VoverE">The V/E .</param>
    /// <param name="C">The capacitance.</param>
    /// <returns></returns>
    static long double resistance_fromDCequations(const long double t, const long double VoverE, const long double C);

    /// <summary>
    /// calculates using the exact exponential treatment, how much time is required to
    /// discharge a C F capacitor through a R Ω resistor down to pOv% of
    /// its original voltage.
    /// </summary>
    /// <param name="C">The capacitance.</param>
    /// <param name="R">The resistance.</param>
    /// <param name="pOv">The percent of original voltage.</param>
    /// <returns>time in seconds</returns>
    static long double time_fromDischargeEquation(const long double C, const long double R, const long double pOv);

    /// <summary>
    /// If you wish to take a picture of a bullet traveling at v m/s, then a
    /// very brief flash of light produced by an RC discharge through a flash
    /// tube can limit blurring. Assuming d m of motion during one RC constant
    /// is acceptable, and given that the flash is driven by a C F capacitor,
    /// what is the resistance in the flash tube?
    /// </summary>
    /// <param name="d">The distance in meters.</param>
    /// <param name="C">The capacitance.</param>
    /// <param name="v">The velocity.</param>
    /// <returns>resistance in Ohms</returns>
    static constexpr long double resistance_fromDistanceVelocity(const long double d, const long double C, const long double v);

    /// <summary>
    /// A flashing lamp in a Christmas earring is based on an RC discharge of a
    /// capacitor through its resistance. The effective duration of the flash
    /// is t s, during which it produces an average 0.500 W from an average
    /// 3.00 V. calculates the energy it dissipates?
    /// </summary>
    /// <param name="P">The power.</param>
    /// <param name="t">The time.</param>
    /// <returns>energy in joules</returns>
    static constexpr long double energyUsed(const long double P, const long double t);

    /// A flashing lamp in a Christmas earring is based on an RC discharge of a
    /// capacitor through its resistance. The effective duration of the flash
    /// is t s, during which it produces an average 0.500 W from an average
    /// 3.00 V. calculates the charge that moves through the lamp.
    /// <param name="P">The power.</param>
    /// <param name="V">The volts.</param>
    /// <param name="t">The time.</param>
    /// <returns>coulombs</returns>
    static constexpr long double charge_fromPowerVoltsTime(const long double P, const long double V, const long double t);

    /// <summary>
    /// A C F capacitor charged to V is discharged through a resistor.
    /// Calculate the temperature increase of the resistor, given that its of a mass
    /// in kg and its specific heat is c kJ/kg⋅C∘, noting that most of the thermal
    /// energy is retained in the short time of the discharge.
    /// </summary>
    /// <param name="C">The capacitance.</param>
    /// <param name="V">The volts.</param>
    /// <param name="mass">The mass.</param>
    /// <param name="c">The specific heat.</param>
    /// <returns>temp in C</returns>
    static constexpr long double temperatureIncreaseOfResistor(const long double C, const long double V, const long double mass, const long double c);

    /// <summary>
    /// EMFs the specified r.
    /// </summary>
    /// <param name="r">The r.</param>
    /// <param name="R_load">The r load.</param>
    /// <param name="I">The i.</param>
    /// <returns></returns>
    static constexpr long double emf(const long double r, const long double R_load, const long double I);



    ~Circuits()
    {
        delete _circuitPtr;
    }

private:
    static void countIncrease() { circuits_objectCount += 1; }
    static void countDecrease() { circuits_objectCount -= 1; }
    long double _circuitVal;

};
#endif //PHYSICSFORMULA_CIRCUITS_H

constexpr long double Circuits::seriesResistance(const long double R1 = 0, const long double R2 = 0, const long double R3 = 0,
                                                 const long double R4 = 0, const long double R5 = 0, const long double R6 = 0, const long double R7 = 0, const long double R8 = 0,
                                                 const long double R9 = 0, const long double R10 = 0)
{

    return R1 + R2 + R3 + R4 + R5 + R6 + R7 + R8 + R9 + R10;//Ohms
}

constexpr long double Circuits::parallelResistance(const long double R1 = 0, const long double R2 = 0, const long double R3 = 0,
                                                   const long double R4 = 0, const long double R5 = 0, const long double R6 = 0, const long double R7 = 0, const long double R8 = 0,
                                                   const long double R9 = 0, const long double R10 = 0)
{
    long double total = 0;
    if (R1>0)
    {
        total += 1 / R1;
    }
    if (R2>0)
    {
        total += 1 / R2;
    }
    if (R3 > 0)
    {
        total += 1 / R3;
    }
    if (R4 > 0)
    {
        total += 1 / R4;
    }
    if (R5 > 0)
    {
        total += 1 / R5;
    }
    if (R6 > 0)
    {
        total += 1 / R6;
    }
    if (R7 > 0)
    {
        total += 1 / R7;
    }
    if (R8 > 0)
    {
        total += 1 / R8;
    }
    if (R9 > 0)
    {
        total += 1 / R9;
    }
    if (R10 > 0)
    {
        total += 1 / R10;
    }
    return 1/total;
}

constexpr long double Circuits::seriesCapacitance(const long double C1, const long double C2, const long double C3, const long double C4, const long double C5, const long double C6, const long double C7, const long double C8, const long double C9, const long double C10)
{
    long double total = 0;
    if (C1>0)
    {
        total += 1 / C1;
    }
    if (C2>0)
    {
        total += 1 / C2;
    }
    if (C3 > 0)
    {
        total += 1 / C3;
    }
    if (C4 > 0)
    {
        total += 1 / C4;
    }
    if (C5 > 0)
    {
        total += 1 / C5;
    }
    if (C6 > 0)
    {
        total += 1 / C6;
    }
    if (C7 > 0)
    {
        total += 1 / C7;
    }
    if (C8 > 0)
    {
        total += 1 / C8;
    }
    if (C9 > 0)
    {
        total += 1 / C9;
    }
    if (C10 > 0)
    {
        total += 1 / C10;
    }
    return 1/total;


}

constexpr long double Circuits::parallelCapacitance(const long double C1, const long double C2, const long double C3, const long double C4, const long double C5, const long double C6, const long double C7, const long double C8, const long double C9, const long double C10)
{
    return  C1 + C2 + C3 + C4 + C5 + C6 + C7 + C8 + C9 + C10;//Ohms

}

constexpr long double Circuits::terminalVoltage(const long double emf, const long double r, const long double I)
{
    return emf - I*r;// V
}

constexpr long double Circuits::current_OhmsLaw(const long double emf, const long double RLoad, const long double r)
{
    return emf/(RLoad+r);//amperes (I)
}

constexpr long double Circuits::powerDissipation(const long double I, const long double Rload)
{
    return (I*I)*Rload;//Watts
}

constexpr long double Circuits::emfsParallelConnection_added(const long double emf1=0, const long double emf2=0, const long double emf3=0, const long double emf4=0)
{
    return emf1 + emf2 + emf3 + emf4;
}

constexpr long double Circuits::emfsSeriesConnection_subtracted(const long double emf1=0, const long double emf2=0, const long double emf3=0, const long double emf4=0)
{
    return emf1 - emf2 - emf3 - emf4;
}

constexpr long double Circuits::internalResistance(const long double Vt, const long double E, const long double I)
{
    return (Vt - E)/I;//Ohms
}

constexpr long double Circuits::timeConstant_RC(const long double R, const long double C)
{
    return R*C;//seconds
}

constexpr long double Circuits::resistance_fromTimeConstant(const long double tau, const long double C)
{
    return tau/C;//Ohms
}

constexpr long double Circuits::capacitance_fromTimeConstant(const long double tau, const long double R)
{
    return tau/R;//Farads
}

inline long double Circuits::voltageVsTimeChargingCapacitor(const long double emf, const long double t, const long double R, const long double C)
{
    const double tau = R * C;
    const double toRaise = -t / tau;
    return emf*(1.0 - exp(toRaise));
}

constexpr long double Circuits::frequency(const long double cycles, const long double seconds)
{
    return cycles/seconds;
}

constexpr long double Circuits::frequency(const long double period)
{
    return 1 / period;
}

constexpr long double Circuits::period(const long double f)
{
    return 1 / f;//period t
}

inline long double Circuits::resistance_fromDCequations(const long double t, const long double VoverE, const long double C)
{
    return (-t/(log(1-VoverE)*C));//ohms
}

inline long double Circuits::time_fromDischargeEquation(const long double C, const long double R, const long double pOv)
{
    return -R*C*log(pOv/100.0);//seconds
}

constexpr long double Circuits::resistance_fromDistanceVelocity(const long double d, const long double C, const long double v)
{
    return d / (C * v);//Ohms
}

constexpr long double Circuits::energyUsed(const long double P, const long double t)
{
    return P*t;//joules
}

constexpr long double Circuits::charge_fromPowerVoltsTime(const long double P, const long double V, const long double t)
{
    return (P/V)*t;//C
}

constexpr long double Circuits::temperatureIncreaseOfResistor(const long double C, const long double V, const long double mass, const long double c)
{
    return (C*(V*V))/(2.0*mass*c);//temperature in C
}

constexpr long double Circuits::emf(const long double r, const long double R_load, const long double I)
{
    return I * (r + R_load);
}
