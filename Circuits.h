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
 * @lastEdit 11/12/2022
 */
#include <iostream>
#include <utility>
#include "ElectricCurrent.h"
#include "ElectricPotential.h"
#include "ResistorNode.h"
#include "CapacitorNode.h"

static int circuits_objectCount = 0;

//struct RCNode {
//    ResistorNode resistorNode;
//    CapacitorNode capacitorNode;
//
//    RCNode() {
//        resistorNode = ResistorNode();
//        capacitorNode = CapacitorNode();
//    }
//
//    RCNode(ResistorNode r, CapacitorNode c) {
//        resistorNode = r;
//        capacitorNode = c;
//    }
//
//    RCNode(std::vector<double> r, std::vector<double> c, double v, char t) {
//        resistorNode = ResistorNode(r, v, t);
//        capacitorNode = CapacitorNode(c, v, t);
//    }
//
//    void setVoltage(double v) {
//        resistorNode.setVoltage(v);
//        capacitorNode.setVoltage(v);
//    }
//
//    void setResistances(std::vector<double> r) {
//        resistorNode.setResistances(r);
//    }
//
//    void setCapacitances(std::vector<double> c) {
//        capacitorNode.setCapacitances(c);
//    }
//};


struct InductorNode {
    vector<double> inductances;
    char type; // 'p' for parallel, 's' for series
    double eI;

    InductorNode() {
        inductances = {};
        type = 'p';
        eI = 0.0;
    }
    InductorNode(vector<double> i, char t) {
        inductances = i;
        type = t;
        eI = calculateEquivalentInductance();
    }
    double calculateEquivalentInductance() {
        double sum = 0.0;
        if (type == 'p') {
            for (double inductance : inductances) {
                sum += 1.0 / inductance;
            }
            sum = 1.0 / sum;
        } else if (type == 's') {
            for (double inductance : inductances) {
                sum += inductance;
            }

        }
        return sum;
    }

    void print() {
        cout << "InductorNode: " << endl;
        cout << "inductances: ";
        for (double inductance : inductances) {
            cout << inductance << " ";
        }
        cout << endl;
        cout << "type: " << (type == 'p' ? "parallel" : "series") << endl;
        cout << "eI: " << eI << endl;
    }
};

struct Battery {
    double voltage;
    double current;
    double resistance;
    double power;

    Battery() {
        voltage = 0.0;
        current = 0.0;
        resistance = 0.0;
        power = 0.0;
    }
    Battery(double v, double c, double r, double p) {
        voltage = v;
        current = c;
        resistance = r;
        power = p;
    }

    void print() const {
        cout << "Battery: " << endl;
        cout << "voltage: " << voltage << endl;
        cout << "current: " << current << endl;
        cout << "resistance: " << resistance << endl;
        cout << "power: " << power << endl;
    }
};


struct CircuitNode {
    vector<CapacitorNode> capacitorNodes;
    vector<ResistorNode> resistorNodes;
    vector<InductorNode> inductorNodes;
    vector<Battery> powerNodes;

    CircuitNode() {
        capacitorNodes = {};
        resistorNodes = {};
        inductorNodes = {};
        powerNodes = {};
    }
    CircuitNode(vector<CapacitorNode> c, vector<ResistorNode> r, vector<InductorNode> i, vector<Battery> p) {
        capacitorNodes = c;
        resistorNodes = r;
        inductorNodes = i;
        powerNodes = p;
    }

    void print() {
        cout << "CircuitNode: " << endl;
        cout << "capacitorNodes: " << endl;
        for (CapacitorNode capacitorNode : capacitorNodes) {
            capacitorNode.print();
        }
        cout << "resistorNodes: " << endl;
        for (ResistorNode resistorNode : resistorNodes) {
            resistorNode.print();
        }
        cout << "inductorNodes: " << endl;
        for (InductorNode inductorNode : inductorNodes) {
            inductorNode.print();
        }
        cout << "powerNodes: " << endl;
        for (Battery powerNode : powerNodes) {
            //powerNode.print();
        }
    }
};




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
     * @brief Calculates the total capacitance_Qv of capacitors hooked up in parallel.
     *    ┌───┴───┐
     *    ┴       ┴      =>   ┴ c = c1 + c2 + ... + cn
     * C1 ┬       ┬ C2        ┬
     *    └───┬───┘
     * @param C  The array of capacitors.
     * @param print  Whether or not to print the results.
     * @return  The total capacitance_Qv (F).
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
     * @return  The total capacitance_Qv (F).
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
    static constexpr long double current_emfRloadr(
            long double emf, long double RLoad, long double r, bool print = true);

    /**
     * @brief Calculates the powers dissipated.
     * @param I  The current.
     * @param R  The resistance.
     * @param print  Whether or not to print the results.
     * @return  The power output in watts (W).
     */
    static constexpr long double powerDissipation_IR(
            long double I, long double R, bool print = true);

    /**
     * @breif Calculates the power dissipated in a resistor, when the current
     * is I and the voltage is V.
     * @param I  The current.
     * @param V  The voltage.
     * @param print  Whether or not to print the results.
     * @return  The power output in watts (W).
     */
    static constexpr long double powerDissipation_IV(
            long double I, long double V, bool print = true);

    /**
     * @brief Calculates the power dissipated in a resistor, when the battery
     * has an emf of E and the internal resistance is r and is connected to a
     * resistor with resistance R.
     * @param E  The electromotive force.
     * @param R  The resistance.
     * @param r  The internal resistance.
     */
    static long double powerDissipation_ErR(
            long double E, long double R, long double r, bool print = true);

    /**
     * @brief Calculates the total power dissipated by a series of resistors,
     * given a battery with an emf of E and an internal resistance of r.
     * @param E  The electromotive force.
     * @param R  The array of resistors.
     * @param r  The internal resistance.
     * @param print  Whether or not to print the results.
     * @return  The total power output in watts (W).
     */
    static long double powerDissipation_series(
            long double E, const vector<long double>& R, long double r, bool print = true);

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
     * @param C  The capacitance_Qv.
     * @param print  Whether or not to print the results.
     * @return  tau (Greek letter)
     */
    static constexpr long double timeConstant_RC(
            long double R, long double C, bool print = true);

    /**
     * @brief Calculates the resistance from the time constant and capacitance_Qv.
     * @param tau  The time constant.
     * @param C  The capacitance_Qv.
     * @param print  Whether or not to print the results.
     * @return  The resistance (Ohms).
     */
    static constexpr long double resistance_fromTimeConstant(
            long double tau, long double C, bool print = true);

    /**
     * @brief Calculates the capacitance_Qv from time constant and resistance.
     * @param tau  The time constant.
     * @param R  The resistance.
     * @param print  Whether or not to print the results.
     * @return  The capacitance_Qv (F).
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
    static long double voltageRCCircuitCharging(
            long double emf, long double t, long double R, long double C, bool print = true);

    /**
     * @brief Calculates the voltage across a capacitor as it discharges.
     * @param V_0  The initial voltage.
     * @param t  The time.
     * @param R  The resistance.
     * @param C The capacitance.
     */
    static long double voltageRCCircuitDischarging(
            long double V_0, long double t, long double R, long double C, bool print = true);

    /**
     * @brief Calculate the current in an RC circuit as it charges.
     * @param emf  The electromotive force.
     * @param t  The time.
     * @param R  The resistance.
     * @param C The capacitance.
     * @param print  Whether or not to print the results.
     * @return  The current (A).
     */
    static long double currentRCCircuitCharging(
            long double emf, long double t, long double R, long double C, bool print = true);

    /**
     * @brief Calculate the current in an RC circuit as it discharges.
     * @param V_0 The initial voltage.
     * @param t  The time.
     * @param R  The resistance.
     * @param C The capacitance.
     * @param print  Whether or not to print the results.
     * @return  The current (A).
     */
    static long double currentRCCircuitDischarging(
            long double V_0, long double t, long double R, long double C, bool print = true);

    /**
     * @brief Calculate the current (I_0) that flows through a resistor with R Ohms
     * resistance immediately after a switch is throw, when there is a capacitor in
     * series with the resistor and has a capacitance of C F and has an
     * initial charge of q.
     * @param R  The resistance.
     * @param C The capacitance.
     * @param q The initial charge.
     * @param print  Whether or not to print the results.
     * @return  The current (A).
     */
    static long double current_RCq(
            long double R, long double C, long double q, bool print = true);


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
     * @param C  The capacitance_Qv.
     * @param print  Whether or not to print the results.
     * @return  The resistance (Ohms).
     */
    static long double resistance_fromDCequations(
            long double t, long double VoverE, long double C, bool print = true);

    /**
     * @brief calculates using the exact exponential treatment, how much time is
     * required to discharge a C F capacitor through a R Ω resistor down to pOv%
     * of its original voltage.
     * @param C  The capacitance_Qv.
     * @param R  The resistance.
     * @param pOv  The percent of original voltage.
     * @param print  Whether or not to print the results.
     * @return  time in seconds
     */
    static long double time_fromDischargeEquation(
            long double C, long double R, long double pOv, bool print = true);

    /**
     * @brief A camera flash gets its energy from a C F capacitor and requires
     * V volts to fire. If the capacitor is charged by a emf-V source through
     * an resistor of R ohms, calculate how long the photographer must wait
     * between flashes. Assume the capacitor is fully discharged with each flash.
     * @param C  The capacitance.
     * @param V  The voltage.
     * @param emf  The electromotive force.
     * @param R  The resistance.
     * @param print  Whether or not to print the results.
     * @return  The time (s).
     */
    static long double time_fromCameraFlash(
            long double C, long double V, long double emf, long double R, bool print = true);

    /**
     * @brief If you wish to take a picture of a bullet traveling at v m/s, then
     * a very brief flash of light produced by an RC discharge through a flash
     * tube can limit blurring. Assuming d m of motion during one RC constant
     * is acceptable, and given that the flash is driven by a C F capacitor,
     * what is the resistance in the flash tube?
     * @param d  The distance in meters.
     * @param C  The capacitance_Qv.
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
     * @param C  The capacitance_Qv.
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
     * with the same dielectric so that the two capacitors have equal capacitance_Qv?
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
     * @brief Calculate the dielectric constant of a capacitor with a capacitance_Qv
     * of C F and a surface area of A m^2, and distance between plates of d m.
     * @param C the capacitance_Qv (F)
     * @param A the surface area (m^2)
     * @param d the distance between the plates (m)
     * @param print true to print the answer
     * @return the dielectric constant
     */
    static ld dielectricConstant(ld C, ld A, ld d, bool print = true);

    /**
     * @brief Calculate the charge stored on the positive plate of a capacitor
     * with a capacitance_Qv of C F and a voltage of V volts.
     * @param C the capacitance_Qv (F)
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
     * @return the capacitance_Qv (F) and charge (C)
     */
    static vector<ld> chargeToStoreEnergy(
            ld l, ld d, ld U, bool print = true);

    /**
     *
     * @brief Calculate the potential difference between the plates of a capacitor
     * with a capacitance_Qv of C F and a charge of Q C.
     * @param C the capacitance_Qv (F)
     * @param Q the charge (C)
     * @param print true to print the answer
     * @return the potential difference (V)
     */
    static ld potentialDifferenceBetweenPlates_CQ(
            ld C, ld Q, bool print = true);

    /**
     * @brief Calculate the potential difference between two plates of a capacitor
     * with an electric field of E V/m and a distance between the plates of d m.
     * @param E the electric field (V/m)
     * @param d the distance (m)
     * @param print true to print the answer
     * @return the potential difference (V)
     */
     static ld potentialDifferenceBetweenPlates_Ed(
             ld E, ld d, bool print = true);

    /**
     * @brief A capacitor of C F is hooked to a source with a voltage of V
     * volts. Calculate how much energy is stored whehn the capacitor is
     * is fully charged.
     * @param C the capacitance_Qv (F)
     * @param V the voltage (V)
     * @param print true to print the answer
     */
    static ld energyStoredInCapacitor_CV(ld C, ld V, bool print = true);

    /**
     * @brief calculate the energy stored in a capacitor with with a voltage
     * of V and a charge of Q.
     * @param V the voltage (V)
     * @param Q the charge (C)
     * @param print true to print the answer
     */
    static ld energyStoredInCapacitor_VQ(ld V, ld Q, bool print = true);

    /**
     * @brief Calculate the energy stored in a capacitor with a capacitance_Qv
     * of C and a charge of Q.
     * @param C the capacitance_Qv (F)
     * @param Q the charge (C)
     * @param print true to print the answer
     */
    static ld energyStoredInCapacitor_CQ(ld C, ld Q, bool print = true);

    /**
     * @brief Calculate the magnitude of the electric field E (V/m) between
     * the plates of a capacitor with a charge density of sigma C/m^2.
     * @param sigma the charge density (C/m^2)
     * @param print true to print the answer
     * @return the electric field (V/m)
     */
    static ld electricFieldBetweenPlates(ld sigma, bool print = true);

    /**
     * @brief Calculate the magnitude of the electric field E (V/m) between
     * the plates of a capacitor with a charge of Q C, and an area of A m^2.
     * @param Q the charge (C)
     * @param A the area (m^2)
     * @param print true to print the answer
     * @return the electric field (V/m)
     */
    static ld electricFieldBetweenPlates_QA(ld Q, ld A, bool print = true);

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
     * a) the capacitance_Qv of the capacitor.
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
     * @return the capacitance_Qv (F), electric field (V/m) and electric field (V/m)
     */
    static vector<ld> sphericalCapacitor(
            ld ra, ld rb, ld V, ld r1, ld r2, bool print = true);

    /**
     * @brief Calculate the voltage V (V) across a capacitor in series, when
     * the battery has a voltage of Vb (V).
     * @param Vb the battery voltage (V)
     * @param Capacitors the capacitances (F)
     * @param print true to print the answer
     * @return the voltages (V)
     */
    static vector<ld> voltageAcrossEachCapacitorInSeries(
            ld Vb, const vector<ld>& Capacitors, bool print = true);


    /**
     * @brief Calculate the Charge Q (C) on each capacitor in series, when
     * the battery has a voltage of Vb (V).
     * @param Vb the battery voltage (V)
     * @param Capacitors the capacitances (F)
     * @param print true to print the answer
     * @return the charges (C)
     */
    static vector<ld> chargeOnEachCapacitorInSeries(
            ld Vb, const vector<ld>& Capacitors, bool print = true);

    /**
     * @brief Calculate the equivalent capacitance_Qv Ceq (F) of a circuit of capacitors
     * that can be in series and in parallel. Use the isSeries flag to indicate
     * whether the final calulation is in series or in parallel.
     * @param series the capacitances in series (F)
     * @param parallel the capacitances in parallel (F)
     * @param isSeries true if the final calculation is in series
     * @param print true to print the answer
     * @return the equivalent capacitance_Qv (F)
     */
    static ld equivalentCapacitance(
            const vector<ld>& series, const vector<ld>& parallel,
            bool isSeries = true, bool print = true);

    /**
     * @brief The energy density in a uniform electric field is U_e J/m^3
     * Calculate the field strength.
     * @param U_e the energy density (J/m^3)
     * @param print true to print the answer
     * @return the field strength (V/m)
     */
    static ld fieldStrengthFromEnergyDensity(ld U_e, bool print = true);

    /**
     * @brief A medical defibrillator stores U J of energy in a C F
     * capacitor. Calculate the following:
     * a) The voltage across the capacitor?
     * b) If the capacitor discharges U_dis J of its stored energy in t s,
     *    calculate the power delivered during this time.
     *
     * @param U the energy stored (J)
     * @param C the capacitance_Qv (F)
     * @param U_dis the energy discharged (J)
     * @param t the time (s)
     * @param print true to print the answer
     * @return the voltage (V), power (W)
     */
    static vector<ld> medicalDefibrillator(
            ld U, ld C, ld U_dis, ld t, bool print = true);

    /**
     * @brief A capacitor consists of two long concentric metal cylinders.
     * Calculate its capacitance_Qv in terms of the dimensions shown in the figure
     * and constant ε0. Express your answer in terms of variables
     * L, a, b, and constant ϵ0.
     * @param L the length (m)
     * @param a the inner radius (m)
     * @param b the outer radius (m)
     * @param print true to print the answer
     * @return the capacitance_Qv (F)
     */
    static ld concentricCylinders(ld L, ld a, ld b, bool print = true);

    /**
     * @brief An unknown capacitor C is connected in series with a C1s F
     * capacitor, this pair is placed in parallel with a C1p F capacitor, and
     * the entire combination is put in series with a Cfs F capacitor. When a
     * potential difference of v V is applied across the open ends of this
     * network, the total energy stored in all the capacitors is U J . Find C.
     * @param C1s the capacitance_Qv of the first parallel capacitor (F)
     * @param C1p the capacitance_Qv of the second series capacitor (F)
     * @param Cfs the capacitance_Qv of the final series capacitor (F)
     * @param v the potential difference (V)
     * @param U the total energy stored (J)
     * @param print true to print the answer
     */
    static ld unknownCapacitor(
            ld C1p, ld C2s, ld Cfs, ld v, ld U, bool print = true);

    /**
     * @brief An ion channel in a cell membrane carries I A when it's open,
     * but it's open only y % of the time. Calculate what the average current
     * is in the channel and if the channel opens for t s, calculate how many
     * singly ionized atoms are transported through the channel.
     * @param I the current (A)
     * @param y the percentage open
     * @param t the time (s)
     * @param print true to print the answer
     * @return the average current (A), the number of ions transported
     */
    static vector<ld> ionChannel(ld I, ld y, ld t, bool print = true);
    /**
     * @brief A lightbulb with resistance  Rl is designed to operate at a
     * current of I A. To operate this lamp from a V-V battery, calculate the
     * resistance you need to put in series with it.
     * @param Rl the resistance of the lightbulb (Ω)
     * @param I the current (A)
     * @param V the voltage (V)
     * @param print true to print the answer
     * @return the resistance (Ω)
     */
    static ld seriesResistance(ld Rl, ld I, ld V, bool print = true);

    /**
     * @brief Your car has a V-V battery with internal resistance Rint ohms.
     * When the starter motor is cranking, it draws I A. Calculate the voltage
     * across the battery terminals while starting.
     * @param Rint the internal resistance (Ω)
     * @param I the current (A)
     * @param V the voltage (V)
     * @param print true to print the answer
     * @return the voltage (V)
     */
    static ld voltageAcrossBattery(ld Rint, ld I, ld V, bool print = true);

    /**
     * @brief When a switch is open, a voltmeter of the battery reads Vo volts.
     * When the switch is closed, the voltmeter reading drops to Vc
     * volts, and the ammeter A reads I A . Assume that the two meters are
     * ideal, so they do not affect the circuit. Calculate the resistance of
     * the battery and the resistance of R.
     * @param Vo the open voltage (V) (emf) (voltage across the battery)
     * @param Vc the closed voltage (V) (Vt) (terminal voltage)
     * @param I the current (A)
     * @param print true to print the answer
     * @return the emf (V)
     */
    static vector<long double> internalExternalResistances(
            ld Vopen, ld Vclosed, ld I, bool print = true);

    /**
     * @brief A V volts batter stores energy U J. Calculate how long it can
     * light a flashlight buld that draws I A.
     * @param V the voltage (V)
     * @param U the energy stored (J)
     * @param I the current (A)
     * @param units the units to use:
     *        "s" for seconds, "m" for minutes, "h" for hours, "d" for days
     * @param print true to print the answer
     * @return the time (s)
     */
    static ld batteryLife(ld V, ld U, ld I, char units, bool print = true);

    /**
     * @brief Consider the juncion of three wires as shown:
     *  W1  \   / W2
     *       \/
     *       |
     *       | W3
     *  The magnitudes of the current density for wire 1 and 2 are J1 A/m2
     *  and J2 A/m2, respectively, and the diameter of wires 1 and 2 are d1 m
     *  and d2 m, respectively. The current is flowing down W1 and up W2, and
     *  the direction of the current in W3 is unknown. Calculate the current
     *  I3 in W3 as well as calculate the magnitude of the current density in
     *  W3 given that it has a diameter of d3 m.
     *  @param J1 the current density of W1 (A/m2)
     *  @param J2 the current density of W2 (A/m2)
     *  @param d1 the diameter of W1 (m)
     *  @param d2 the diameter of W2 (m)
     *  @param d3 the diameter of W3 (m)
     *  @param print true to print the answer
     *  @return the current in W3 (A), the current density in W3 (A/m2)
     */
    static vector<ld> currentDensityFromWireJunction(
            ld J1, ld J2, ld d1, ld d2, ld d3, bool print = true);

    /**
     * @brief Calculate the current on am ammeter when a battery with a
     * voltage of emf V, having an internal resistance of r Ω, is connected
     * to a resistor with a resistance of R Ω.
     * @param emf the emf (V)
     * @param r the internal resistance (Ω)
     * @param R the resistance (Ω)
     * @param print true to print the answer
     * @return the current (A)
     */
    static ld ammeterCurrent(ld emf, ld r, ld R, bool print = true);

    /**
     * @brief Calculate the voltage across a voltmeter when a battery with a
     * voltage of emf V, having an internal resistance of r Ω, is connected
     * to a resistor with a resistance of R Ω.
     * @param emf the emf (V)
     * @param r the internal resistance (Ω)
     * @param R the resistance (Ω)
     * @param print true to print the answer
     */
    static ld voltmeterVoltage(ld emf, ld r, ld R, bool print = true);

    /**
     * @brief Calculate how much work is done by a voltage source to charge a
     * capacitor with a capacitance of C F using a voltage of V V.
     * @param C the capacitance (F)
     * @param V the voltage (V)
     * @param print true to print the answer
     * @return the work done (J)
     */
    static ld workDoneByVoltageSource(ld C, ld V, bool print = true);

    /**
     * @brief Calculate q(t) for a capacitor with a capacitance of C F and a
     * resistance of R Ω when a voltage source of V V is applied for a time
     * of t s.
     * @param C the capacitance (F)
     * @param R the resistance (Ω)
     * @param V the voltage (V)
     * @param t the time (s)
     * @param print true to print the answer
     */
    static ld chargeOnCapacitor_RCVt(ld C, ld R, ld V, ld t, bool print = true);

    /**
     * @brief Calculate I(t) for a capacitor with a capacitance of C F and a
     * resistance of R Ω when a voltage source of V V is applied for a time
     * of t s.
     * @param C the capacitance (F)
     * @param R the resistance (Ω)
     * @param V the voltage (V)
     * @param t the time (s)
     * @param print true to print the answer
     */
    static ld currentOnCapacitor_RCVt(ld C, ld R, ld V, ld t, bool print = true);

    /**
     * @brief Find the time t2 that it would take the charge of the capacitor
     * to reach N% of its maximum value given a resistance of  R Ω and
     * a capacitor of C F.
     * @param C the capacitance (F)
     * @param R the resistance (Ω)
     * @param N the percentage of the maximum charge
     * @param print true to print the answer
     * @return the time (s)
     */
    static ld timeToNPercentOfMaxCharge(
            ld C, ld R, double N, bool print = true);

    /**
     * @brief Let us now consider a different R-C circuit. This time, the
     * capacitor is initially charged (q(0)=q0), and there is no source of EMF
     * in the circuit. We will assume that the top plate of the capacitor
     * initially holds positive charge. For this circuit, Kirchhoff's loop rule
     * gives IR+q/C=0, or equivalently, IR=−q/C.
     * Calculate the current I(t) as a function of time for this circuit.
     * @param C the capacitance (F)
     * @param R the resistance (Ω)
     * @param q0 the initial charge (C)
     * @param t the time (s)
     * @param print true to print the answer
     * @return the current (A)
     */
    static ld currentOnCapacitor_RCq0t(
            ld C, ld R, ld q0, ld t, bool print = true);



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
        cout << "The sum of the capacitance_Qv's is " << 1.0/total << " Farads." << endl;
    return 1.0/total;
}

long double
Circuits::parallelCapacitance(const vector<long double> &C, bool print) {
    long double total = 0;
    for (long double c : C) {
        total += c;
    }
    if (print)
        cout << "The sum of the capacitance_Qv's is " << total << " Farads." << endl;
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

constexpr long double Circuits::current_emfRloadr(
        const long double emf, const long double RLoad, const long double r, bool print)
{
    auto I = emf/(RLoad+r);//amperes (I)
    if (print)
        cout << "The current is " << I << " Amps." << endl;
    return I;
}

constexpr long double Circuits::powerDissipation_IR(
        const long double I, const long double R, bool print)
{
    auto pow_dis = (I*I)*R;//Watts
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
        cout << "The capacitance_Qv is " << C << " Farads." << endl;
    return C;
}

inline long double Circuits::voltageRCCircuitCharging(
        const long double emf, const long double t, const long double R, const long double C, bool print)
{
    auto tau = R * C;
    auto toRaise = -t / tau;
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

ld Circuits::
potentialDifferenceBetweenPlates_CQ(ld C, ld Q, bool print) {
    auto V = Q / C;
    if (print) {
        std::cout << "V = " << V << std::endl;
    }
    return V;
}

ld Circuits::
potentialDifferenceBetweenPlates_Ed(ld E, ld d, bool print) {
    auto V = E * d;
    if (print) {
        std::cout << "V = " << V << " V" << std::endl;
    }
    return V;
}

ld Circuits::energyStoredInCapacitor_CV(ld C, ld V, bool print) {
    auto U = (C * V * V) / 2.0;
    if (print) {
        std::cout << "U = " << U << " J" << std::endl;
    }
    return U;
}

ld Circuits::energyStoredInCapacitor_VQ(ld V, ld Q, bool print) {
    auto U = (Q * V) / 2.0;
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
ld Circuits::electricFieldBetweenPlates_QA(ld Q, ld A, bool print) {
    auto e0 = constants::e0;
    auto E = Q / (e0 * A);
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

vector<ld> Circuits::voltageAcrossEachCapacitorInSeries(
        ld Vb, const vector<ld>& Capacitors, bool print) {
    // get the total capacitance_Qv which is found using 1/C = 1/C1 + 1/C2 + ...
    auto C = ld(0.0);
    for (auto C_i : Capacitors) {
        C += 1.0 / C_i;
    }
    C = 1.0 / C;
    // get the total charge
    auto Q = C * Vb;
    // get the voltage across each capacitor
    auto V = vector<ld>();
    for (auto C_i : Capacitors) {
        V.push_back(Q / C_i);
    }
    // print out the voltage across each capacitor, specifying the
    // capacitance_Qv to which it corresponds
    if (print) {
        for (int i = 0; i < Capacitors.size(); i++) {
            std::cout << "C" << i << " = " << Capacitors[i] << " F, ";
            std::cout << "V" << i + 1 << " = " << V[i] << " V" << std::endl;
        }
    }
    return V;
}

vector<ld>
Circuits::chargeOnEachCapacitorInSeries(ld Vb, const vector<ld> &Capacitors,
                                        bool print) {

    // get the total charges on each capacitor
    auto Q = vector<ld>();
    for (auto C_i : Capacitors) {
        Q.push_back(C_i * Vb);
    }
    // print out the charge on each capacitor, specifying the
    // capacitance_Qv to which it corresponds
    if (print) {
        for (int i = 0; i < Capacitors.size(); i++) {
            std::cout << "C" << i << " = " << Capacitors[i] << " F, ";
            std::cout << "Q" << i + 1 << " = " << Q[i] << " C" << std::endl;
        }
    }
    return Q;
}

ld Circuits::equivalentCapacitance(
        const vector<ld> &series, const vector<ld> &parallel,
        bool isSeries, bool print) {
    // variable for the total capacitance_Qv
    auto C_tot = ld(0.0);
    // get the total capacitance_Qv in series which is found using 1/C = 1/C1 + 1/C2 + ...
    auto C_series = ld(0.0);
    for (auto C_i : series) {
        C_series += 1.0 / C_i;
        C_tot += C_i;
    }
    C_series = 1.0 / C_series;
    // get the total capacitance_Qv in parallel which is found using C = C1 + C2 + ...
    auto C_parallel = ld(0.0);
    for (auto C_i : parallel) {
        C_parallel += C_i;
        C_tot += C_i;
    }
    // get the equivalent capacitance_Qv
    auto C = ld(0.0);
    if (isSeries) {
        C = 1.0 / (1.0 / C_series + 1.0 / C_parallel);
    } else {
        C = C_series + C_parallel;
    }
    if (print) {
        std::cout << "C = " << C << " F" << std::endl;
    }
    return C;
}

ld Circuits::fieldStrengthFromEnergyDensity(ld U_e, bool print) {
    auto E = sqrt((2.0 * U_e) / constants::e0);
    if (print) {
        std::cout << "E = " << E << " V/m" << std::endl;
    }
    return E;
}

vector<ld> Circuits::medicalDefibrillator(ld U, ld C, ld U_dis, ld t, bool print) {
    // get the charge across the capacitor, U = 1/2 C V^2 =? V = sqrt(2 U / C)
    auto V = sqrt(2.0 * U / C);
    // calculate the power of the defibrillator, P = k / t
    auto P =  U_dis / t;
    if (print) {
        std::cout << "V = " << V << " V" << std::endl;
        std::cout << "P = " << P << " W" << std::endl;
    }
    return {V, P};
}

ld Circuits::concentricCylinders(ld L, ld a, ld b, bool print) {
    auto e0 = constants::e0;
    auto pi = constants::PI;
    auto C = (2.0 * pi
            * e0 * L) / (log(b / a));
    if (print) {
        std::cout << "C = " << C << " F" << std::endl;
    }
    return C;
}

ld Circuits::unknownCapacitor(ld C1s, ld C1p, ld Cfs, ld v, ld U, bool print) {
    auto C_eq = 2.0 * U / (v * v);
    auto C_p = 1.0 / ((1.0/C_eq) - (1.0/Cfs));
    auto C_s = C_p - C1p;
    auto Cf = 1.0 / ((1.0/C_s) - (1.0/C1s));
    if (print) {
        std::cout << "Cf = " << Cf << " F" << std::endl;
    }
    return Cf;
}

vector<ld> Circuits::ionChannel(ld I, ld y, ld t, bool print) {
    // check if y is a percent or a fraction
    if (y > 1.0) {
        y /= 100.0;
    }
    auto C = y * I;
    auto q = I * t;
    auto ions = q / -constants::ELECTRON_CHARGE;
    if (print) {
        std::cout << "C = " << C << " F" << std::endl;
        std::cout << "ions = " << ions << std::endl;
    }
    return {C, ions};
}

ld Circuits::energyStoredInCapacitor_CQ(ld C, ld Q, bool print) {
    auto U = (Q * Q) / (2.0 * C);
    if (print) {
        std::cout << "U = " << U << " J" << std::endl;
    }
    return U;
}

ld Circuits::seriesResistance(ld Rl, ld I, ld V, bool print) {
    auto R = (V - (I * Rl)) / I;
    if (print) {
        std::cout << "R = " << R << " ohms" << std::endl;
    }
    return R;
}

ld Circuits::voltageAcrossBattery(ld Rint, ld I, ld V, bool print) {
    auto Vb = V - (I * Rint);
    if (print) {
        std::cout << "Vb = " << Vb << " V" << std::endl;
    }
    return Vb;
}

long double Circuits::currentRCCircuitCharging(long double emf, long double t,
                                               long double R, long double C,
                                               bool print) {
    auto I = (emf / R) * exp(-t / (R * C));
    if (print) {
        std::cout << "I = " << I << " A" << std::endl;
    }
    return I;
}

long double
Circuits::voltageRCCircuitDischarging(long double V_0, long double t,
                                      long double R, long double C,
                                      bool print) {
    auto V = V_0 * exp(-t / (R * C));
    if (print) {
        std::cout << "V = " << V << " V" << std::endl;
    }
    return V;
}

long double
Circuits::currentRCCircuitDischarging(long double V_0, long double t,
                                      long double R, long double C,
                                      bool print) {
    auto I = (V_0 / R) * exp(-t / (R * C));
    if (print) {
        std::cout << "I = " << I << " A" << std::endl;
    }
    return I;
}
long double
Circuits::time_fromCameraFlash(long double C, long double V, long double emf,
                               long double R, bool print) {
    auto t = -R * C * log(1.0 - (V / emf));
    if (print) {
        std::cout << "t = " << t << " s" << std::endl;
    }
    return t;
}

long double
Circuits::current_RCq(long double R, long double C, long double q, bool print) {
    auto I = q / (R * C);
    if (print) {
        std::cout << "I = " << I << " A" << std::endl;
    }
    return I;
}

vector<long double> Circuits::internalExternalResistances(
        ld Vopen, ld Vclosed, ld I, bool print) {
    auto r = (Vopen - Vclosed) / I;
    auto R = (Vopen / I) - r;
    if (print) {
        std::cout << "r = " << r << " ohms" << std::endl;
        std::cout << "R = " << R << " ohms" << std::endl;
    }
    return {r, R};
}

ld Circuits::batteryLife(ld V, ld U, ld I, char units, bool print) {
    auto W = V * I;
    auto t = U / W;
    switch (units) {
        case 's':
            break;
        case 'm':
            t /= 60.0;
            break;
        case 'h':
            t /= 3600.0;
            break;
        case 'd':
            t /= 86400.0;
            break;
        case 'y':
            t /= 31536000.0;
            break;
        default:
            std::cout << "Invalid units" << std::endl;
            break;
    }
    if (print) {
        std::cout << "t = " << t << " s" << std::endl;
    }
    return t;
}

vector<ld> Circuits::currentDensityFromWireJunction(
        ld J1, ld J2, ld d1, ld d2, ld d3, bool print) {
    auto I1 = J1 * circle_area_d(d1);
    auto I2 = J2 * circle_area_d(d2);
    auto I3 = I1 - I2;
    auto J3 = abs(I3 / circle_area_d(d3));
    if (print) {
        std::cout << "I3 = " << I3 << " A" << std::endl;
        std::cout << "J3 = " << J3 << " A/m^2" << std::endl;
    }
    return {I3, J3};
}

ld Circuits::ammeterCurrent(ld emf, ld r, ld R, bool print) {
    auto I = emf / (r + R);
    if (print) {
        std::cout << "I = " << I << " A" << std::endl;
    }
    return I;
}

ld Circuits::voltmeterVoltage(ld emf, ld r, ld R, bool print) {
    auto V = (R * emf) / (r + R) ;
    if (print) {
        std::cout << "V = " << V << " V" << std::endl;
    }
    return V;
}

constexpr long double
Circuits::powerDissipation_IV(long double I, long double V, bool print) {
    auto P = I * V;
    if (print) {
        std::cout << "P = " << P << " W" << std::endl;
    }
    return P;
}

long double
Circuits::powerDissipation_ErR(long double E, long double R, long double r,
                               bool print) {
    auto P = (E * E * R) / pow(r + R, 2);
    if (print) {
        std::cout << "P = " << P << " W" << std::endl;
    }
    return P;
}

long double
Circuits::powerDissipation_series(long double E, const vector<long double> &R,
                                  long double r, bool print) {
    auto P = (E * E * R.at(0)) / pow(r + R.at(0), 2);
    for (auto i = 1; i < R.size(); i++) {
        P += (E * E * R.at(i)) / pow(r + R.at(i), 2);
    }
    if (print) {
        std::cout << "P = " << P << " W" << std::endl;
    }
    return P;
}

ld Circuits::workDoneByVoltageSource(ld C, ld V, bool print) {
    auto W = C * V*V;
    if (print) {
        std::cout << "W = " << W << " J" << std::endl;
    }
    return W;
}

ld Circuits::chargeOnCapacitor_RCVt(ld C, ld R, ld V, ld t, bool print) {
    auto q = C * V * (1 - exp(-t / (R * C)));
    if (print) {
        std::cout << "q = " << q << " C" << std::endl;
    }
    return q;
}

ld Circuits::currentOnCapacitor_RCVt(ld C, ld R, ld V, ld t, bool print) {
    auto I = V / R * (exp(-t / (R * C)));
    if (print) {
        std::cout << "I = " << I << " A" << std::endl;
    }
    return I;
}

ld Circuits::timeToNPercentOfMaxCharge(
        ld C, ld R, double N, bool print) {
    auto t = abs(R * C * log(1.0 - (N / 100.0)));
    if (print) {
        std::cout << "t = " << t << " s" << std::endl;
    }
    return t;
}

ld Circuits::currentOnCapacitor_RCq0t(ld C, ld R, ld q0, ld t, bool print) {
    auto I = q0 / (R * C) * exp(-t / (R * C));
    if (print) {
        std::cout << "I = " << I << " A" << std::endl;
    }
    return I;
}
