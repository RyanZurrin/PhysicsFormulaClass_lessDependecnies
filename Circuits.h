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

    Circuits()
    {
        _circuitVal = 0.0;
        countIncrease();
    }
    explicit Circuits(long double val)
    {
        _circuitVal = val;
        countIncrease();
    }

    /**
     * @brief copy constructor
     */
    Circuits(const Circuits& c)
     : ElectricCurrent(c) {
        _circuitVal = 0.0;
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    Circuits(Circuits&& c) noexcept
    {
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
            _circuitVal = c._circuitVal;
            countIncrease();
        }
        return *this;
    }

    static void show_objectCount() { std::cout << "\n circuits object count: "
                                               << circuits_objectCount << std::endl; }
    static int get_objectCount() { return circuits_objectCount; }

    constexpr void setCircuitVal(long double val) { _circuitVal = val; }



    /**
     * @brief Calculates the total resistance of a series of resistors.
     * @param R  The array of resistors.
     * @param print Whether to print the results.
     * @return  The total resistance in ohms.
     */
    static long double seriesResistance(const vector<long double>& R,
                                                  bool print);


    /**
     * @brief Calculates the total resistance of resistors hooked up in parallel.
     * @param R  The array of resistors.
     * @param print  Whether or not to print the results.
     * @return  The total resistance in ohms.
     */
    static long double parallelResistance(const vector<long
            double>& R,
                                                    bool print);


    /**
     * @brief Calculates the total capacitor of a series of capacitors.
     * @param C  The array of capacitors.
     * @param print  Whether or not to print the results.
     * @return  The total capacitance (F).
     */
    static long double seriesCapacitance(const vector<long double>& C,
                                                   bool print);

    /**
     * @brief Calculates the total capacitance of capacitors hooked up in parallel.
     * @param C  The array of capacitors.
     * @param print  Whether or not to print the results.
     * @return  The total capacitance (F).
     */
    static long double parallelCapacitance(const vector<long double>& C,
                                                     bool print);

    /// <summary>
    /// Calculates the terminal  voltage.
    /// </summary>
    /// <param name="emf">The electromotive force.</param>
    /// <param name="r">The internal resistance.</param>
    /// <param name="I">The Charge.</param>
    /// <returns>Voltage</returns>
    static constexpr long double terminalVoltage(long double emf, long double r, long double I);


    /// <summary>
    /// Calculates the Current of a  ohms law.
    /// </summary>
    /// <param name="emf">The EMF.</param>
    /// <param name="RLoad">The resistance load of all resistors connected.</param>
    /// <param name="r">The internal resistance.</param>
    /// <returns>current I in amperes</returns>
    static constexpr long double current_OhmsLaw(long double emf, long double RLoad, long double r);

    /// <summary>
    /// Calculates the powers dissipated
    /// </summary>
    /// <param name="I">The current.</param>
    /// <param name="Rload">The Resistance load.</param>
    /// <returns>power output in watts (W)S</returns>
    static constexpr long double powerDissipation(long double I, long double R);

    /// <summary>
    /// add the total emfs for a series connection. where emf is the electromagnetic force
    /// </summary>
    /// <param name="emf1">The emf1.</param>
    /// <param name="emf2">The emf2.</param>
    /// <param name="emf3">The emf3.</param>
    /// <param name="emf4">The emf4.</param>
    /// <returns>net emf</returns>
    static constexpr long double emfsParallelConnection_added(long double emf1, long double emf2, long double emf3, long double emf4);

    /// <summary>
    /// add the total emfs for a series connection. where emf is the electromagnetic force
    /// </summary>
    /// <param name="emf1">The emf1.</param>
    /// <param name="emf2">The emf2.</param>
    /// <param name="emf3">The emf3.</param>
    /// <param name="emf4">The emf4.</param>
    /// <returns></returns>
    static constexpr long double emfsSeriesConnection_subtracted(long double emf1, long double emf2, long double emf3, long double emf4);

    /// <summary>
    /// calculates the internals resistance.
    /// </summary>
    /// <param name="Vt">The terminal voltage.</param>
    /// <param name="E">The emf.</param>
    /// <param name="I">The current.</param>
    /// <returns>the internal resistance (r)</returns>
    static constexpr long double internalResistance(long double Vt, long double E, long double I);

    /// <summary>
    /// calculates the RC time constant of a circuit containing a resistor and a
    /// capacitor.
    /// </summary>
    /// <param name="R">The resistance.</param>
    /// <param name="C">The capacitance.</param>
    /// <returns>tau(Greek letter)</returns>
    static constexpr long double timeConstant_RC(long double R, long double C);

    /// <summary>
    /// calculates the resistances from time constant and capacitance.
    /// </summary>
    /// <param name="tau">The tau(time constant).</param>
    /// <param name="C">The capacitance.</param>
    /// <returns>the resistance Ohms</returns>
    static constexpr long double resistance_fromTimeConstant(long double tau, long double C);

    /// <summary>
    /// calculates the capacitance from time constant and resistance.
    /// </summary>
    /// <param name="tau">The tau.</param>
    /// <param name="R">The resistance.</param>
    /// <returns></returns>
    static constexpr long double capacitance_fromTimeConstant(long double tau, long double R);

    /// <summary>
    /// Voltages the vs time charging capacitor.
    /// </summary>
    /// <param name="emf">The EMF.</param>
    /// <param name="t">The time.</param>
    /// <param name="R">The resistance.</param>
    /// <param name="C">The capacitance.</param>
    /// <returns></returns>
    static long double voltageVsTimeChargingCapacitor(long double emf, long double t, long double R, long double C);

    /// <summary>
    /// calculates the Frequency from cycles and seconds.
    /// </summary>
    /// <param name="cycles">The cycles.</param>
    /// <param name="seconds">The seconds.</param>
    /// <returns>frequency</returns>
    static constexpr long double frequency(long double cycles, long double seconds);

    /// <summary>
    /// Frequencies the specified period.
    /// </summary>
    /// <param name="period">The period.</param>
    /// <returns></returns>
    static constexpr long double frequency(long double period);

    /// <summary>
    /// calculates the periods from the specified f.
    /// </summary>
    /// <param name="f">The f.</param>
    /// <returns>period</returns>
    static constexpr long double period(long double f);

    /// <summary>
    /// Resistances from DC equations.
    /// </summary>
    /// <param name="t">The time.</param>
    /// <param name="VoverE">The V/E .</param>
    /// <param name="C">The capacitance.</param>
    /// <returns></returns>
    static long double resistance_fromDCequations(long double t, long double VoverE, long double C);

    /// <summary>
    /// calculates using the exact exponential treatment, how much time is required to
    /// discharge a C F capacitor through a R Ω resistor down to pOv% of
    /// its original voltage.
    /// </summary>
    /// <param name="C">The capacitance.</param>
    /// <param name="R">The resistance.</param>
    /// <param name="pOv">The percent of original voltage.</param>
    /// <returns>time in seconds</returns>
    static long double time_fromDischargeEquation(long double C, long double R, long double pOv);

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
    static constexpr long double resistance_fromDistanceVelocity(long double d, long double C, long double v);

    /// <summary>
    /// A flashing lamp in a Christmas earring is based on an RC discharge of a
    /// capacitor through its resistance. The effective duration of the flash
    /// is t s, during which it produces an average 0.500 W from an average
    /// 3.00 V. calculates the energy it dissipates?
    /// </summary>
    /// <param name="P">The power.</param>
    /// <param name="t">The time.</param>
    /// <returns>energy in joules</returns>
    static constexpr long double energyUsed(long double P, long double t);

    /// A flashing lamp in a Christmas earring is based on an RC discharge of a
    /// capacitor through its resistance. The effective duration of the flash
    /// is t s, during which it produces an average 0.500 W from an average
    /// 3.00 V. calculates the charge that moves through the lamp.
    /// <param name="P">The power.</param>
    /// <param name="V">The volts.</param>
    /// <param name="t">The time.</param>
    /// <returns>coulombs</returns>
    static constexpr long double charge_fromPowerVoltsTime(long double P, long double V, long double t);

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
    static constexpr long double temperatureIncreaseOfResistor(long double C, long double V, long double mass, long double c);

    /// <summary>
    /// EMFs the specified r.
    /// </summary>
    /// <param name="r">The r.</param>
    /// <param name="R_load">The r load.</param>
    /// <param name="I">The i.</param>
    /// <returns></returns>
    static constexpr long double emf(long double r, long double R_load, long double I);



    ~Circuits()
    {
        countDecrease();
    }

private:
    static void countIncrease() { circuits_objectCount += 1; }
    static void countDecrease() { circuits_objectCount -= 1; }
    long double _circuitVal;

};
#endif //PHYSICSFORMULA_CIRCUITS_H

long double Circuits::seriesResistance(const vector<long double> &R,
                                                 bool print = false) {
    long double sum = 0;
    for (long double r : R) {
        sum += r;
    }
    if (print)
        cout << "The sum of the resistances is " << sum << " Ohms." << endl;
    return sum;
}

long double
Circuits::parallelResistance(const vector<long double> &R, bool print) {
    long double sum = 0;
    for (long double r : R) {
        sum += 1 / r;
    }
    if (print)
        cout << "The sum of the resistances is " << 1 / sum << " Ohms." << endl;
    return 1 / sum;
}

long double
Circuits::seriesCapacitance(const vector<long double> &C, bool print) {
    long double total = 0;
    for (long double c : C) {
        total += 1.0 / c;
    }
    if (print)
        cout << "The sum of the capacitance's is " << 1.0/total << " Farads." << endl;
    return 1.0/total;
}

long double
Circuits::parallelCapacitance(const vector<long double> &C, bool print) {
    long double total = 0;
    for (long double c : C) {
        total += c;
    }
    if (print)
        cout << "The sum of the capacitance's is " << total << " Farads." << endl;
    return total;
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





