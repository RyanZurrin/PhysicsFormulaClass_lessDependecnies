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
#include "ElectricPotential.h"

static int circuits_objectCount = 0;

class Circuits:
        public ElectricCurrent, public ElectricPotential
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
     : ElectricCurrent(c) , ElectricPotential(c) {
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
    static long double seriesResistance(
            const vector<long double>& R, bool print);


    /**
     * @brief Calculates the total resistance of resistors hooked up in parallel.
     * @param R  The array of resistors.
     * @param print  Whether or not to print the results.
     * @return  The total resistance in ohms.
     */
    static long double parallelResistance(
            const vector<long double>& R, bool print);


    /**
     * @brief Calculates the total capacitance of capacitors hooked up in parallel.
     *    ┌───┴───┐
     *    ┴       ┴      =>   ┴ c = c1 + c2 + ... + cn
     * C1 ┬       ┬ C2        ┬
     *    └───┬───┘
     * @param C  The array of capacitors.
     * @param print  Whether or not to print the results.
     * @return  The total capacitance (F).
     */
    static long double parallelCapacitance(
            const vector<long double>& C, bool print);

    /**
     * @brief Calculates the total capacitor of a series of capacitors.
     *    ┴
     * C1 ┬
     *    ┴    =>   ┴ c = 1 / (1/c1 + 1/c2 + ... + 1/cn)
     * C2 ┬         ┬
     *
     * @param C  The array of capacitors.
     * @param print  Whether or not to print the results.
     * @return  The total capacitance (F).
     */
    static long double seriesCapacitance(
            const vector<long double>& C, bool print);

    /**
     * @brief Calculates the terminal voltage.
     * @param emf  The electromotive force.
     * @param r  The internal resistance.
     * @param I  The charge.
     * @param print  Whether or not to print the results.
     * @return  The voltage.
     */
    static constexpr long double terminalVoltage(
            long double emf, long double r, long double I, bool print = true);

    /**
     * @brief Calculates the current of a circuit using Ohm's law.
     * @param emf  The electromotive force.
     * @param RLoad  The resistance load of all resistors connected.
     * @param r  The internal resistance.
     * @param print  Whether or not to print the results.
     * @return  The current (A).
     */
    static constexpr long double current_OhmsLaw(
            long double emf, long double RLoad, long double r, bool print = true);

    /**
     * @brief Calculates the powers dissipated.
     * @param I  The current.
     * @param R  The resistance.
     * @param print  Whether or not to print the results.
     * @return  The power output in watts (W).
     */
    static constexpr long double powerDissipation(
            long double I, long double R, bool print = true);

    /**
     * @brief adds the total emfs for a series connection. where emf is the
     * electromagnetic force
     * @param emfs The emfs.
     * @param print  Whether or not to print the results.
     * @return  net emf
     */
    static long double emfsParallelConnection_added(
            const vector<ld>& emfs,  bool print = true);

    /**
     * @brief subtracts the total emfs for a series connection. where emf is the
     * electromagnetic force
     * @param emfs  The emfs.
     * @param print  Whether or not to print the results.
     * @return  net emf
     */
    static long double emfsSeriesConnection_subtracted(
           vector<ld> emfs, bool print = true);

    /**
     * @brief Calculates the internal resistance.
     * @param Vt  The terminal voltage.
     * @param E  The emf.
     * @param I  The current.
     * @param print  Whether or not to print the results.
     * @return  The internal resistance (r).
     */
    static constexpr long double internalResistance(
            long double Vt, long double E, long double I, bool print = true);

    /**
     * @brief Calculates the RC time constant of a circuit containing a resistor
     * and a capacitor.
     * @param R  The resistance.
     * @param C  The capacitance.
     * @param print  Whether or not to print the results.
     * @return  tau (Greek letter)
     */
    static constexpr long double timeConstant_RC(
            long double R, long double C, bool print = true);

    /**
     * @brief Calculates the resistance from the time constant and capacitance.
     * @param tau  The time constant.
     * @param C  The capacitance.
     * @param print  Whether or not to print the results.
     * @return  The resistance (Ohms).
     */
    static constexpr long double resistance_fromTimeConstant(
            long double tau, long double C, bool print = true);

    /**
     * @brief Calculates the capacitance from time constant and resistance.
     * @param tau  The time constant.
     * @param R  The resistance.
     * @param print  Whether or not to print the results.
     * @return  The capacitance (F).
     */
    static constexpr long double capacitance_fromTimeConstant(
            long double tau, long double R, bool print = true);

    /**
     * @brief Calculates the voltage across a capacitor as it charges.
     * @param emf  The electromotive force.
     * @param t  The time.
     * @param R  The resistance.
     * @param C  The capacitance.
     * @param print  Whether or not to print the results.
     * @return  The voltage (V).
     */
    static long double voltageVsTimeChargingCapacitor(
            long double emf, long double t, long double R, long double C, bool print = true);

    /**
     * @brief Calculates the frequency from cycles and seconds.
     * @param cycles  The cycles.
     * @param seconds  The seconds.
     * @param print  Whether or not to print the results.
     * @return  The frequency (Hz).
     */
    static constexpr long double frequency(
            long double cycles, long double seconds, bool print = true);

    /**
     * @brief Calculates the frequency from the period.
     * @param period  The period.
     * @param print  Whether or not to print the results.
     * @return  The frequency (Hz).
     */
    static constexpr long double frequency(long double period, bool print = true);

    /**
     * @brief Calculates the period from the frequency.
     * @param f  The frequency.
     * @param print  Whether or not to print the results.
     * @return  The period (s).
     */
    static constexpr long double period(long double f, bool print = true);

    /**
     * @brief Calculates the resistance from DC equations.
     * @param t  The time.
     * @param VoverE  The V/E .
     * @param C  The capacitance.
     * @param print  Whether or not to print the results.
     * @return  The resistance (Ohms).
     */
    static long double resistance_fromDCequations(
            long double t, long double VoverE, long double C, bool print = true);

    /**
     * @brief calculates using the exact exponential treatment, how much time is
     * required to discharge a C F capacitor through a R Ω resistor down to pOv%
     * of its original voltage.
     * @param C  The capacitance.
     * @param R  The resistance.
     * @param pOv  The percent of original voltage.
     * @param print  Whether or not to print the results.
     * @return  time in seconds
     */
    static long double time_fromDischargeEquation(
            long double C, long double R, long double pOv, bool print = true);

    /**
     * @brief If you wish to take a picture of a bullet traveling at v m/s, then
     * a very brief flash of light produced by an RC discharge through a flash
     * tube can limit blurring. Assuming d m of motion during one RC constant
     * is acceptable, and given that the flash is driven by a C F capacitor,
     * what is the resistance in the flash tube?
     * @param d  The distance in meters.
     * @param C  The capacitance.
     * @param v  The velocity.
     * @param print  Whether or not to print the results.
     * @return  resistance in Ohms
     */
    static constexpr long double resistance_fromDistanceVelocity(
            long double d, long double C, long double v, bool print = true);

    /**
     * @brief A flashing lamp in a Christmas earring is based on an RC discharge
     * of a capacitor through its resistance. The effective duration of the flash
     * is t s, during which it produces an average 0.500 W from an average 3.00 V.
     * calculates the energy it dissipates?
     * @param P  The power.
     * @param t  The time.
     * @param print  Whether or not to print the results.
     * @return  energy in joules
     */
    static constexpr long double energyUsed(long double P, long double t, bool print = true);

    /**
     * @brief A flashing lamp in a Christmas earring is based on an RC discharge
     * of a capacitor through its resistance. The effective duration of the flash
     * is t s, during which it produces an average 0.500 W from an average 3.00 V.
     * calculates the charge that moves through the lamp.
     * @param P  The power.
     * @param V  The volts.
     * @param t  The time.
     * @param print  Whether or not to print the results.
     * @return  coulombs
     */
    static constexpr long double charge_fromPowerVoltsTime(
            long double P, long double V, long double t, bool print = true);

    /**
     * @brief A C F capacitor charged to V is discharged through a resistor.
     * Calculate the temperature increase of the resistor, given that its of a mass
     * in kg and its specific heat is c kJ/kg⋅C∘, noting that most of the thermal
     * energy is retained in the short time of the discharge.
     * @param C  The capacitance.
     * @param V  The volts.
     * @param mass  The mass.
     * @param c  The specific heat.
     * @param print  The print.
     * @return  temp in C
     */
    static constexpr long double temperatureIncreaseOfResistor(
            long double C, long double V, long double mass, long double c, bool print = true);

    /// <summary>
    /// EMFs the specified r.
    /// </summary>
    /// <param name="r">The r.</param>
    /// <param name="R_load">The r load.</param>
    /// <param name="I">The i.</param>
    /// <returns></returns>
    static constexpr long double emf(
            long double r, long double R_load, long double I, bool print = true);

    /**
     * @brief Two oppositely charged but otherwise identical conducting plates
     * of area A square meters are separated by a dielectric d meters thick,
     * with a dielectric constant of K. The resultant electric field in the
     * dielectric is E volts per meter. Calculate the results of the following:
     * A) The magnitude of the charge per unit area σ on the conducting plate
     *    is in units C/m^2.
     * B) The magnitude of the charge per unit area σ1 on the surfaces of the
     *    dielectric is in units C/m^2.
     * C) The total electric-field energy U stored in the capacitor is in units J.
     *
     * @param A area of the plates
     * @param d thickness of the dielectric
     * @param K dielectric constant
     * @param E electric field
     * @param print print the results
     * @return std::tuple<long double, long double, long double>
     *        (σ, σ1, U)
     */
    static std::tuple<long double, long double, long double>
            conductingPlatesChargeData(
            long double A, long double d, long double k, long double E, bool
            print = true);

    /**
     * @brief Consider two parallel-plate capacitors identical in shape, one
     * is aligned so that the plates are horizontal, and the other
     * with the plates vertical. The horizontal capacitor is filled  halfway
     * with a material that has an arbitrary dielectric constant K.
     * What fraction f of the area of the vertical capacitor should be filled
     * with the same dielectric so that the two capacitors have equal capacitance?
     * Express your answer in terms of K.
     * @param A area of the horizontal capacitor
     * @param d thickness of the dielectric
     * @param K dielectric constant
     * @param print print the results
     * @return long double f
     */
    static long double fractionOfArea(
            long double A, long double d, long double k, bool print = true);

    /**
     * @brief Calculate the dielectric constant of a capacitor with a capacitance
     * of C F and a surface area of A m^2, and distance between plates of d m.
     * @param C the capacitance (F)
     * @param A the surface area (m^2)
     * @param d the distance between the plates (m)
     * @param print true to print the answer
     * @return the dielectric constant
     */
    static ld dielectricConstant(ld C, ld A, ld d, bool print = true);

    /**
     * @brief Calculate the charge stored on the positive plate of a capacitor
     * with a capacitance of C F and a voltage of V volts.
     * @param C the capacitance (F)
     * @param V the voltage (V)
     * @param print true to print the answer
     * @return the charge (C)
     */
    static ld chargeOnPositivePlate(ld C, ld V, bool print = true);

    /**
     * @brief Calculate the electric potential V(h) inside the capacitor as a
     * function of height h. Take the potential at the bottom plate to be zero,
     * and the electric field to be uniform inside the capacitor with a strength
     * of E V/m.
     * @param E the electric field strength (V/m)
     * @param h the height (m)
     * @param print true to print the answer
     * @return the electric potential (V)
     */
    static ld electricPotential(ld E, ld h, bool print = true);

    /**
     * @brief An electron of charge −qe (where qe is a positive
     * quantity) is placed within the electric field at height h0, between the
     * plates of a capacitor. Calculate the electon's potential energy U(h0),
     * neglecting gravitational potential energy. Take the Electric field to be
     * uniform inside the capacitor with a strength of E V/m.
     * @param E the electric field strength (V/m)
     * @param h0 the height (m)
     * @param qe the charge (C)
     * @param print true to print the answer
     */
    static ld electronPotentialEnergy(ld E, ld h0, ld qe, bool print = true);

    /**
     * @brief An electron of mass m and charge −qe (where qe is a positive
     * quantity) is placed within the electric field at height h0.
     * The electron, having been held at height h0, is now released from rest.
     * Calculate its speed v (i.e., |v⃗ |) when it reaches the top plate (height h1).
     * Take the Electric field to be uniform inside the capacitor with a strength
     * of E V/m.
     * @param E the electric field strength (V/m)
     * @param h0 the height (m)
     * @param h1 the height (m)
     * @param m the mass (kg)
     * @param qe the charge (C)
     * @param print true to print the answer
     */
    static ld electronSpeed(ld E, ld h0, ld h1, ld m, ld qe, bool print = true);

    /**
     * @brief An uncharged capacitor has parallel plates l m on a side,
     * spaced d m apart. Calculate how much charge must be transferred
     * between the initially uncharged plates in order to store U J of energy?
     * @param l the length (m)
     * @param d the distance (m)
     * @param U the energy (J)
     * @param print true to print the answer
     * @return the capacitance (F) and charge (C)
     */
    static vector<ld> chargeToStoreEnergy(
            ld l, ld d, ld U, bool print = true);

    /**
     *
     * @brief Calculate the potential difference between the plates of a capacitor
     * with a capacitance of C F and a charge of Q C.
     * @param C the capacitance (F)
     * @param Q the charge (C)
     * @param print true to print the answer
     * @return the potential difference (V)
     */
    static ld potentialDifferenceBetweenPlates(ld C, ld Q, bool print = true);

    /**
     * @brief Calculate the potential difference between two plates of a capacitor
     * with an electric field of E V/m and a distance between the plates of d m.
     * @param E the electric field (V/m)
     * @param d the distance (m)
     * @param print true to print the answer
     * @return the potential difference (V)
     */
     static ld potentialDiffBetweenPlatesFromEField(
             ld E, ld d, bool print = true);

    /**
     * @brief A capacitor of C F is hooked to a source with a voltage of V
     * volts. Calculate how much energy is stored whehn the capacitor is
     * is fully charged.
     * @param C the capacitance (F)
     * @param V the voltage (V)
     * @param print true to print the answer
     */
    static ld energyStoredInCapacitor(ld C, ld V, bool print = true);

    /**
     * @brief Calculate the magnitude of the electric field E (V/m) between
     * the plates of a capacitor with a charge density of sigma C/m^2.
     * @param sigma the charge density (C/m^2)
     * @param print true to print the answer
     * @return the electric field (V/m)
     */
    static ld electricFieldBetweenPlates(ld sigma, bool print = true);

    /**
     * @brief Calculate the magnitude of the force on a N ion with between the
     * plates of a capacitor with an electric field of E V/m.
     * @param E the electric field (V/m)
     * @param N the charge (C)
     * @param print true to print the answer
     * @return the force (N)
     */
    static ld forceOnIon(ld E, ld N, bool print = true);

    /**
     * @breif if released from the top plate of a capacitor, what would the
     * kinetic energy of a charge of Q C be, giving a potential difference of V V?
     * @param Q the charge (C)
     * @param V the potential difference (V)
     * @param print true to print the answer
     * @return the kinetic energy (J)
     */
    static ld kineticEnergyOfChargeBetweenPlates(ld Q, ld V, bool print = true);

    /**
     * @brief A spherical capacitor is formed from two concentric spherical
     * conducting shells separated by vacuum. The inner sphere has a radius
     * of ra m , and the outer sphere has a radius of rb m . A potential
     * difference of V Volts is applied to the capacitor.
     * Calculate the following:
     * a) the capacitance of the capacitor.
     * b) the magnitude E1 of the electric field E⃗  at
     *    radius r1 m , just outside the inner sphere.
     *    (Note: E⃗  is the electric field vector.)
     * c) the magnitude of E⃗  at r2 m , just inside the outer sphere.
     * @param ra the inner radius (m)
     * @param rb the outer radius (m)
     * @param V the potential difference (V)
     * @param r1 the radius outside the inner sphere (m)
     * @param r2 the radius just inside the outer sphere(m)
     * @param print true to print the answer
     * @return the capacitance (F), electric field (V/m) and electric field (V/m)
     */
    static vector<ld> sphericalCapacitor(
            ld ra, ld rb, ld V, ld r1, ld r2, bool print = true);


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

constexpr long double Circuits::terminalVoltage(
        const long double emf, const long double r, const long double I, bool print)
{
    auto V = emf - I*r;// V
    if (print)
        cout << "The terminal voltage is " << V << " Volts." << endl;
    return V;
}

constexpr long double Circuits::current_OhmsLaw(
        const long double emf, const long double RLoad, const long double r, bool print)
{
    auto I = emf/(RLoad+r);//amperes (I)
    if (print)
        cout << "The current is " << I << " Amps." << endl;
    return I;
}

constexpr long double Circuits::powerDissipation(
        const long double I, const long double Rload, bool print)
{
    auto pow_dis = (I*I)*Rload;//Watts
    if (print)
        cout << "The power dissipation is " << pow_dis << " Watts." << endl;
    return pow_dis;
}

long double Circuits::emfsParallelConnection_added(
        const vector<ld>& emfs, bool print)
{
    long double sum = 0;
    for (long double emf : emfs) {
        sum += emf;
    }
    if (print)
        cout << "The sum of the emfs is " << sum << " Volts." << endl;
    return sum;
}

long double Circuits::emfsSeriesConnection_subtracted(
        vector<ld> emfs, bool print)
{
    long double sum = 0;
    for (long double emf : emfs) {
        sum -= emf;
    }
    if (print)
        cout << "The sum of the emfs is " << sum << " Volts." << endl;
    return sum;
}

constexpr long double Circuits::internalResistance(
        const long double Vt, const long double E, const long double I, bool print)
{
    auto R = (Vt - E)/I;//Ohms
    if (print)
        cout << "The internal resistance is " << R << " Ohms." << endl;
    return R;
}

constexpr long double Circuits::timeConstant_RC(
        const long double R, const long double C, bool print)
{
    auto t = R*C;//seconds
    if (print)
        cout << "The time constant is " << t << " seconds." << endl;
    return t;
}

constexpr long double Circuits::resistance_fromTimeConstant(
        const long double tau, const long double C, bool print)
{
    auto R = tau/C;//Ohms
    if (print)
        cout << "The resistance is " << R << " Ohms." << endl;
    return R;
}

constexpr long double Circuits::capacitance_fromTimeConstant(
        const long double tau, const long double R, bool print)
{
    auto C = tau/R;//Farads
    if (print)
        cout << "The capacitance is " << C << " Farads." << endl;
    return C;
}

inline long double Circuits::voltageVsTimeChargingCapacitor(
        const long double emf, const long double t, const long double R, const long double C, bool print)
{
    const double tau = R * C;
    const double toRaise = -t / tau;
    auto VtC = emf*(1.0 - exp(toRaise));
    if (print)
        cout << "The voltage is " << VtC << " Volts." << endl;
    return VtC;
}

constexpr long double Circuits::frequency(
        const long double cycles, const long double seconds, bool print)
{
    auto f = cycles/seconds;
    if (print)
        cout << "The frequency is " << f << " Hertz." << endl;
    return f;
}

constexpr long double Circuits::frequency(
        const long double period, bool print)
{
    auto f = 1.0 / period;
    if (print)
        cout << "The frequency is " << f << " Hertz." << endl;
    return f;
}

constexpr long double Circuits::period(
        const long double f, bool print)
{
    auto P = 1.0 / f;//period t
    if (print)
        cout << "The period is " << P << " seconds." << endl;
    return P;
}

inline long double Circuits::resistance_fromDCequations(
        const long double t, const long double VoverE, const long double C, bool print)
{
    auto R = (-t/(log(1-VoverE)*C));//ohms
    if (print)
        cout << "The resistance is " << R << " Ohms." << endl;
    return R;
}

inline long double Circuits::time_fromDischargeEquation(
        const long double C, const long double R, const long double pOv, bool print)
{
    auto t = -R*C*log(pOv/100.0);//seconds
    if (print)
        cout << "The time is " << t << " seconds." << endl;
    return t;
}

constexpr long double Circuits::resistance_fromDistanceVelocity(
        const long double d, const long double C, const long double v, bool print)
{
    auto R = d / (C * v);//Ohms
    if (print)
        cout << "The resistance is " << R << " Ohms." << endl;
    return R;
}

constexpr long double Circuits::energyUsed(
        const long double P, const long double t, bool print)
{
    auto eng_used = P*t;//joules
    if (print)
        cout << "The energy used is " << eng_used << " Joules." << endl;
    return eng_used;
}

constexpr long double Circuits::charge_fromPowerVoltsTime(
        const long double P, const long double V, const long double t, bool print)
{
    auto q = (P/V)*t;//C
    if (print)
        cout << "The charge is " << q << " Coulombs." << endl;
    return q;
}

constexpr long double Circuits::temperatureIncreaseOfResistor(
        const long double C, const long double V, const long double mass, const long double c, bool print)
{
    auto temp_increase =  (C*(V*V))/(2.0*mass*c);//temperature in C
    if (print)
        cout << "The temperature increase is " << temp_increase << " degrees Celsius." << endl;
    return temp_increase;
}

constexpr long double Circuits::emf(
        const long double r, const long double R_load, const long double I, bool print)
{
    auto emv = I * (r + R_load);
    if (print)
        cout << "The emf is " << emv << " Volts." << endl;
    return emv;
}

std::tuple<long double, long double, long double>
Circuits::conductingPlatesChargeData(
        long double A, long double d, long double k, long double E, bool
        print) {
    auto e0 = constants::e0;
    auto sigma_1 = k*e0*E;
    auto sigma_2 = sigma_1 * (1.0 - (1.0/k));
    auto U = (1.0/2.0)*k*e0*(E*E)*A*d;
if (print) {
        cout << "The charge per unit area sigma on the conducting plate is " <<
        sigma_1 << " C/m^2." << endl;
        cout << "The charge per unit area sigma' on the surfaces of the "
                "dielectric is " << sigma_2 << " C/m^2." << endl;
        cout << "The total electric-field energy U stored in the capacitor is "
        << U << " J." << endl;
    }
    return std::make_tuple(sigma_1, sigma_2, U);

}

long double Circuits::fractionOfArea(
        long double A, long double d, long double k, bool print) {
    auto f = 1.0/(k + 1.0);
    if (print) {
        cout << "The fraction of the area of the conducting plate that is "
                "covered by the dielectric is " << f << "." << endl;
    }
    return f;
}

ld Circuits::dielectricConstant(ld C, ld A, ld d, bool print) {
    auto e0 = constants::e0;
    auto epsilon = (C * d) / (e0 * A);
    if (print) {
        std::cout << "epsilon = " << epsilon << std::endl;
    }
    return epsilon;
}

ld Circuits::chargeOnPositivePlate(ld C, ld V, bool print) {
    auto q = C * V;
    if (print) {
        std::cout << "q = " << q << std::endl;
    }
    return q;
}

ld Circuits::electricPotential(ld E, ld h, bool print) {
    auto V = E * h;
    if (print) {
        std::cout << "V = " << V << std::endl;
    }
    return V;
}

ld Circuits::electronPotentialEnergy(ld E, ld h0, ld qe, bool print) {
    auto U = - (E * h0 * qe);
    if (print) {
        std::cout << "U = " << U << std::endl;
    }
    return U;
}

ld Circuits::electronSpeed(ld E, ld h0, ld h1, ld m, ld qe, bool print) {
    auto v = sqrt(2 * qe * E * (h1 - h0)) / m;
    if (print) {
        std::cout << "v = " << v << std::endl;
    }
    return v;
}

std::vector<ld> Circuits::chargeToStoreEnergy(
        ld l, ld d, ld U, bool print) {
    auto e0 = constants::e0;
    auto A = l * l;
    auto Cap = (e0 * A)/d;
    auto Q = sqrt(U * 2.0 * Cap);
    if (print) {
        std::cout << "Cap = " << Cap << std::endl;
        std::cout << "Q = " << Q << std::endl;
    }
    return {Cap, Q};
    return {Cap, Q};
}

ld Circuits::potentialDifferenceBetweenPlates(ld C, ld Q, bool print) {
    auto V = Q / C;
    if (print) {
        std::cout << "V = " << V << std::endl;
    }
    return V;
}

ld Circuits::energyStoredInCapacitor(ld C, ld V, bool print) {
    auto U = (C * V * V) / 2.0;
    if (print) {
        std::cout << "U = " << U << " J" << std::endl;
    }
    return U;
}

ld Circuits::electricFieldBetweenPlates(ld sigma, bool print) {
    auto e0 = constants::e0;
    auto E = sigma / e0;
    if (print) {
        std::cout << "E = " << E << " V/m" << std::endl;
    }
    return E;
}

ld Circuits::forceOnIon(ld E, ld N, bool print) {
    // F = qE where q is the charge of the ion N
    auto F = N * E;
    if (print) {
        std::cout << "F = " << F << " N" << std::endl;
    }
    return F;
}

ld Circuits::potentialDiffBetweenPlatesFromEField(ld E, ld d, bool print) {
    auto V = E * d;
    if (print) {
        std::cout << "V = " << V << " V" << std::endl;
    }
    return V;
}

ld Circuits::kineticEnergyOfChargeBetweenPlates(ld Q, ld V, bool print) {
    // K = U => K = qV
    auto K = Q * V;
    if (print) {
        std::cout << "K = " << K << " J" << std::endl;
    }
    return K;
}

vector<ld>
Circuits::sphericalCapacitor(ld ra, ld rb, ld V, ld r1, ld r2, bool print) {
    auto e0 = constants::e0;
    auto pi = constants::PI;
    auto C = (4.0 * pi * e0 * ra * rb) / (rb - ra);
    auto Q = C * V;
    auto E1 = Q / (4.0 * pi * e0 * r1 * r1);
    auto E2 = Q / (4.0 * pi * e0 * r2 * r2);
    if (print) {
        std::cout << "C = " << C << " F" << std::endl;
        std::cout << "Q = " << Q << " C" << std::endl;
        std::cout << "E1 = " << E1 << " V/m" << std::endl;
        std::cout << "E2 = " << E2 << " V/m" << std::endl;
    }
    return {C, Q, E1, E2};
}



