//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_ELECTROMAGNETICINDUCTION_H
#define PHYSICSFORMULA_ELECTROMAGNETICINDUCTION_H
/**
 * @class ElectroMagneticInduction
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @dateBuilt  3/21/2021
 * @lastEdit 3/21/2021
 */
#include <iostream>
#include "Magnetism.h"
#include <string>

static int emi_objectCount = 0;
typedef long double ld;

class ElectroMagneticInduction :
        public Magnetism
{

public:
    ElectroMagneticInduction()
    {
        _electroMagVar = 0.0;
        countIncrease();
    }

    explicit ElectroMagneticInduction(ld val)
    {
        _electroMagVar = val;
        countIncrease();
    }

    /**
     * @brief copy constructor
     */
    ElectroMagneticInduction(const ElectroMagneticInduction& t)
     : Magnetism(t) {
        _electroMagVar = t._electroMagVar;
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    ElectroMagneticInduction(ElectroMagneticInduction&& t) noexcept
    {
        _electroMagVar = t._electroMagVar;
        countIncrease();
    }
    /**
     * @brief copy assignment operator
     */
    ElectroMagneticInduction& operator=(ElectroMagneticInduction&& t)noexcept
    {
        if (this != &t)
        {
            _electroMagVar = t._electroMagVar;
            countIncrease();
        }
        return *this;
    }
    void setElectroMagVar(ld var) { _electroMagVar = var; }
    [[nodiscard]] ld getElectroMagVar()const { return _electroMagVar; }
    static void show_objectCount() { std::cout << "\n electromagnetic induction object count: "
                                               << emi_objectCount << std::endl; }
    static int get_objectCount() { return emi_objectCount; }

    /**
     * @brief Calculates the magnetic flux where B is the magnetic field strength(T)
     * over an area of A (m^2), at an angle theta with the perpendicular to
     * the area. Any change in the magnetic flux induces an emf. This process
     * is defined to be electromagnetic induction.
     * @param B The magnetic field strength(T).
     * @param A The area(m^2).
     * @param theta The angle theta default is at 0 degrees which
     * is equal to 1 making the equation flux = B*A.
     * @param print (default is true) if true prints the equation and result.
     * @return the magnetic flux (T*m^2)
     */
    static ld magneticFlux( ld B, ld A, ld theta = 0.0, bool print = true);

    /**
     * @brief A generator coil is rotated through a revolution from 0 to theta degrees,
     * in t seconds. Having N turns the coil has a radius of r (m) and is in a
     * uniform magnetic field of B. Calculate the average emf induced.
     * @param N The number of turns in coil.
     * @param r The radius of coil.
     * @param B The magnetic uniform field.
     * @param t The time it takes to rotate theta degrees.
     * @param thetaS The starting angle of rotation.
     * @param thetaF The finishing angle of rotation.
     * @param print (default is true) if true prints the equation and result.
     * @return emf average (V)
     */
    static ld emfFaradayFullEquation(
            ld N, ld r, ld B, ld t, ld thetaS, ld thetaF, bool print = true);

    /**
     * @brief Calculates the magnitude of an induced emf when a bar magnet  is thrust
     * into a coil with N loops having a radius of r (m) and the average value of
     * B cos(theta) that is given due to complexity as increasing from B1 to B2
     * over a period of t seconds.
     * @param N The number of loops.
     * @param r The radius.
     * @param B1 The starting magnetic field.
     * @param B2 The ending magnetic field.
     * @param t The time over which the increase of the
     * magnetic field takes place.
     * @param theta The angle theta.
     * @param print (default is true) if true prints the equation and result.
     * @return magnitude of emf (V)
     */
    static ld emfMagnitude_FaradayNoMinus(
            ld N, ld r, ld B1, ld B2, ld t, ld theta, bool print = true);

    /**
     * @brief Calculates the change in flux.
     * @param A the area = pi*r^2.
     * @param deltaB The delta b = B2 - B1.
     * @param theta The angle theta.
     * @return the change in flux (T*m^2)
     */
    static ld deltaFlux(ld A, ld deltaB, bool print = true);

    /**
     * @brief EMFs the induced in generator coil.
     * @param N The number of loop in coil.
     * @param l The length of the loop.
     * @param w The width of coil loop.
     * @param aW a angular velocity.
     * @param B The magnetic field strength.
     * @param t The time for a rotation.
     * @param print (default is true) if true prints the equation and result.
     * @return emf total from generator coil (V)
     */
    static ld emf_inducedInGeneratorCoil(
            ld N, ld l, ld w, ld aW, ld B, ld t, bool print = true);

    /**
     * @brief Calculates the peek emf.
     * @param N The number of turns in a coil.
     * @param A The area.
     * @param B The magnetic field strength.
     * @param aW The angular velocity.
     * @param print (default is true) if true prints the equation and result.
     * @return peek emf (V)
     */
    static ld emf_peek(ld N, ld A, ld B, ld aW, bool print = true);

    /**
     * @brief Calculates the peek emf.
     * @param N The number of turns in a coil.
     * @param r The radius of coil.
     * @param B The magnetic field strength.
     * @param rad The angle of rotation in radians.
     * @param t The time for a rotation.
     * @param print (default is true) if true prints the equation and result.
     * @return peek emf (V)
     */
    static ld emf_peek(ld N, ld r, ld B, ld rad, ld t, bool print = true);

    /**
     * @brief A N turn, r(m) radius coil rotates at an angular velocity of
     * aW rad/s in a B(T) field, starting with the normal of the plane
     * of the coil perpendicular to the field. Assume that the positive max
     * emf is reached first.
     * @param N The number of turns in coil.
     * @param r The radius or half of the diameter.
     * @param B The magnetic field strength.
     * @param aW a angular velocity.
     * @param print (default is true) if true prints the equation and result.
     * @return peek emf
     */
    static ld emfPeek_r(ld N, ld r, ld B, ld aW, bool print = true);

    /**
     * @brief Calculate the peak voltage of a generator that rotates its N-turn,
     * d m diameter coil rotating at rpm rpms in a B T field.
     * @param N The number of loops in coil.
     * @param d The diameter of coil.
     * @param B The magnetic filed strength.
     * @param rpm The RPMs.
     * @param print (default is true) if true prints the equation and result.
     * @return peek emf voltage
     */
    static ld emf_peekFromDiameterAndRPMs(
            ld N, ld d, ld B, ld rpm, bool print = true);

    /**
     * @brief Calculates the EMF induced by magnetic flux over t time having N turns
     * is considered Faraday's law of induction: Lenz's Law->(why there is a
     * minus sign.
     * @param N The amount of turns in coil.
     * @param f The flux.
     * @param t The time.
     * @param print (default is true) if true prints the equation and result.
     * @return emf = volts(V)
     */
    static ld emf_inducedByMagneticFlux(ld N, ld f, ld t, bool print = true);

    /**
     * @brief An MRI technician moves his hand from a region of very low magnetic field
     * strength into an MRI scanner’s magnetic field of B(T) with his fingers
     * pointing in the direction of the field. Calculate the average emf induced in
     * his wedding ring, given its diameter is d(m) and assuming it takes time
     * t(s) to move it into the field.
     * @param B The magnetic filed.
     * @param d The diameter.
     * @param t The time in seconds.
     * @param print (default is true) if true prints the equation and result.
     * @return average emf (V)
     */
    static ld emf_avgOnCoil(ld B, ld d, ld t, bool print = true);

    /**
     * @brief number of turns in a coil from EMF and time t over the flux;
     * @param t The time.
     * @param emf The EMF.
     * @param f The flux.
     * @param print (default is true) if true prints the equation and result.
     * @return turns in a coil
     */
    static ld n_turnsInCoilFromEMFEquation(ld t, ld emf, ld f, bool print = true);

    /**
     * @brief calculates the fluxes from EMF equation, with a time of t and N turns in
     * a coil
     * @param emf The EMF.
     * @param t The time.
     * @param N The number of turns in a coil.
     * @param print (default is true) if true prints the equation and result.
     * @return magnetic flux(T*m^2)
     */
    static ld flux_fromEMFEquation(ld emf, ld t, ld N, bool print = true);

    /**
     * @brief calculates the times from EMF equation with a flux and emf with N turns
     * of a coil.
     * @param N The number of turns of a coil
     * @param f The flux.
     * @param emf The EMF.
     * @param print (default is true) if true prints the equation and result.
     * @return time in seconds
     */
    static ld time_fromEMFEquation(ld N, ld f, ld emf, bool print = true);

    /**
     * @brief Calculates the motional  EMF.
     * @param B The magnetic field.
     * @param l The length of rod.
     * @param x The distance the rod moves.
     * @param t The time it moves over.
     * @param print (default is true) if true prints the equation and result.
     * @return emf from motion (V)
     */
    static ld motionalEMF(ld B, ld l, ld x, ld t, bool print = true);

    /**
     * @brief Calculates the motional EMF.
     * @param B The magnetic field.
     * @param l The length of rod.
     * @param v The velocity -> x/t .
     * @param print (default is true) if true prints the equation and result.
     * @return emf from motion(V)
     */
    static ld motionalEMF(ld B, ld l, ld v, bool print = true);

    /**
     * @brief calculates the length a magnetic rod must be when producing an emf of V.
     * @param V The EMF voltage (V).
     * @param B The magnetic field (B).
     * @param v The velocity (v).
     * @param print (default is true) if true prints the equation and result.
     * @return length of magnetic rod
     */
    static ld lengthOfRod_emfEq(ld V, ld B, ld v, bool print = true);

    /**
     * @brief Calculates the velocity of the motion of magnetic rod when a emf of V is
     * created with a magnetic field of B and having a rod of length l (m).
     * @param V The emf voltage (V).
     * @param B The magnetic field (T).
     * @param l The length of rod (m).
     * @param print (default is true) if true prints the equation and result.
     * @return velocity (m/s)
     */
    static ld velocityOfMotion_emfEq(ld V, ld B, ld l, bool print = true);

    /**
     * @brief Calculates the magnetic field from when a rod of length l moves at a
     * velocity of v causing a magnetic field strength of B.
     * @param V The emf voltage.
     * @param l The length of rod.
     * @param v The velocity.
     * @param print (default is true) if true prints the equation and result.
     * @return magnetic field strength (T)
     */
    static ld magneticFieldFrom_emfEq(ld V, ld l, ld v, bool print = true);

    /**
     * @brief Magnetics the field magnitude.
     * @param flux The flux.
     * @param Ard The Area, radius or diameter.
     * @param theta The theta, is at default value of 0.
     * @param mode The mode is used as a switch between what
     * information you use for the Ard argument: use 'r' for radius or 'd'
     * for diameter and if you are using the already calculated cross sectional
     * then leave out..
     * @param print (default is true) if true prints the equation and result.
     * @return magnetic field (T)
     */
    static ld magneticFieldMagnitude(ld flux, ld Ard, ld theta, ld mode, bool print = true);

    /**
     * @brief Calculates the voltage or number of loops in a transformer. Use a 0 as
     * placeholder in the unknowns method argument.
     * @param Vs The volts secondary(output).
     * @param Vp The volts primary(input).
     * @param Ns The number of loops secondary(output).
     * @param Np The number of loops primary(input).
     * @param mode The mode used to specify what you want to solve for,
     * "Vs" = volts secondary,
     * "vp" = volts primary,
     * "Ns" = number of loops secondary,
     * "Np" = number of loops primary.
     * example: transformerEquation(2.5,3.4,5,10,"Ns");
     * this would solve for the number of loops in the secondary transformer
     * @param print (default is true) if true prints the equation and result.
     * @return volts or loops depending on mode used
     */
    static ld transformerEquations_VN(ld Vs, ld Vp, ld Ns, ld Np, const std::string& mode, bool print = true);

    /**
     * @brief Calculates the voltage or current in a transformer. use a 0 as a place
     * holder in the unknown variables method argument.
     * @param Vs The volts secondary(output).
     * @param Vp The volts primary(input).
     * @param Is The current secondary(output).
     * @param Ip The current primary(input).
     * @param mode The mode used to specify what you want to solve for,
     * "Vs" = volts secondary,
     * "vp" = volts primary,
     * "Is" = current secondary,
     * "Ip" = current primary.
     * example: transformerEquation(2.5,3.4,5,10,"Is");
     * this would solve for the current in the secondary transformer
     * @param print (default is true) if true prints the equation and result.
     * @return volts or current depending on the mode picked
     */
    static ld transformerEquations_VI(ld Vs, ld Vp, ld Is, ld Ip, const std::string& mode, bool print = true);

    /**
     * @brief Calculates the current or number of loops in a transformer. use a 0 as a place
     * holder in the unknown variables method argument.
     * @param Is The current secondary(output).
     * @param Ip The current primary(input).
     * @param Ns The number of loops secondary(output).
     * @param Np The number of loops primary(input).
     * @param mode The mode used to specify what you want to solve for,
     * "Is" = current secondary,
     * "Ip" = current primary,
     * "Ns" = number of loops secondary,
     * "Np" = number of loops primary.
     * example: transformerEquation(2.5,3.4,5,10,"Is");
     * this would solve for the current in the secondary transformer
     * @param print (default is true) if true prints the equation and result.
     * @return current or number of loops depending on the mode picked
     */
    static ld transformerEquations_IN(ld Is, ld Ip, ld Ns, ld Np, const std::string& mode, bool print = true);

    /**
     * @brief Calculates the frequencies from a know angular velocity of aW.
     * @param aW a angular velocity.
     * @param print (default is true) if true prints the equation and result.
     * @return frequency (Hz
     */
    static ld frequency(ld aW, bool print = true);

    /**
     * @brief Calculates the period from the known frequency of f.
     * @param f The frequency.
     * @param print (default is true) if true prints the equation and result.
     * @return period (s)
     */
    static ld period(ld f, bool print = true);

    /**
     * @brief Calculates the maximum current in a circuit with a resistance
     * of R and emf of V.
     * @param emf The EMF.
     * @param R The resistance.
     * @param print (default is true) if true prints the equation and result.
     * @return current (A)
     */
    static ld maxCurrent(ld emf, ld R, bool print = true);

    /**
     * @brief Calculates the emf2 from the mutual inductance of M between two devices
     * where the current from device one is I and the time t over which the
     * current changes.
     * @param M The Mutual inductance.
     * @param I The current.
     * @param t The time.
     * @param print (default is true) if true prints the equation and result.
     * @return emf voltage
     */
    static ld emf_byMutualInductance(ld M, ld I, ld t, bool print = true);

    /**
     * @brief Calculates the mutual inductance.
     * @param emf The EMF.
     * @param I The current.
     * @param t The time.
     * @param print (default is true) if true prints the equation and result.
     * @return henry(H)
     */
    static ld mutualInductance(ld emf, ld I, ld t, bool print = true);

    /**
     * @brief calculates the EMF by self inductance. also the back emf calculated with
     * this methods equation
     * @param L The self inductance of the device.
     * @param I The current.
     * @param t The time.
     * @param print (default is true) if true prints the equation and result.
     * @return emf voltage
     */
    static ld inductorEMF(ld L, ld I, ld t, bool print = true);

    /**
     * @brief calculates the self inductance.
     * @param emf The EMF.
     * @param I The current.
     * @param t The time.
     * @param print (default is true) if true prints the equation and result.
     * @return inductance of inductor(H)
     */
    static ld selfInductance(ld emf, ld I, ld t, bool print = true);

    /**
     * @brief The current in an inductor is changing at deltaI A/s and the
     * inductor emf is emf V. Calculate the self inductance of the inductor.
     * @param emf The emf.
     * @param deltaI The change in current.
     * @param print (default is true) if true prints the equation and result.
     * @return inductance of inductor(H)
     */
    static ld selfInductance(ld emf, ld deltaI, bool print = true);

    /**
     * @brief calculates the self inductance.
     * @param N The number of loops.
     * @param phi The flux.
     * @param I The current.
     * @param print (default is true) if true prints the equation and result.
     * @return inductance(H)
     */
    static ld selfInductance_NBI(ld N, ld phi, ld I, bool print = true);

    /**
     * @brief calculates the self inductance.
     * @param phi The flux.
     * @param I The current.
     * @param print (default is true) if true prints the equation and result.
     * @return inductance(H)
     */
    static ld selfInductance_phiI(ld phi, ld I, bool print = true);


    /**
     *
     * @brief Calculates the self the inductance using the time constant and resistance
     * @param toa The time constant.
     * @param R The resistance.
     * @param print (default is true) if true prints the equation and result.
     * @return self inductance
     */
    static ld selfInductance_taoR(const ld toa, const ld R, bool print = true);

    /**
     * @brief Calculates the inductance of a solenoid.
     * @param N The number of turns in coil.
     * @param A the area, radius or diameter.
     * @param l The length of solenoid.
     * @param mode put a 'r' if use a radius or a 'd' if using the
     * diameter or a 'c' if using the circumference to calculate the area.
     * @param print (default is true) if true prints the equation and result.
     * @return self inductance of solenoid
     */
    static ld inductanceSolenoid_NAL(int N, ld A, ld l, char mode, bool print
    = true);

    /**
     * @brief Calculates the inductance from total energy of E stored in inductor
     * having a current of I.
     * @param E The energy of inductor.
     * @param I The current.
     * @param print (default is true) if true prints the equation and result.
     * @return the inductance (H)
     */
    static ld inductanceFromEnergyStored(ld E, ld I, bool print = true);

    /**
     * @brief Calculates the energy stored in an inductor.
     * @param L The inductance.
     * @param I The current.
     * @param print (default is true) if true prints the equation and result.
     * @return energy (J)
     */
    static ld energyStoredInInductor(ld L, ld I, bool print = true);

    /**
     * @brief Camera flashes charge a capacitor to high voltage by switching the
     * current through an inductor on and off rapidly. Calculate what time must
     * the a current of I through a inductance of L be switched on or off to
     * induce a emf.
     * @param I The current.
     * @param L The inductance.
     * @param emf The EMF.
     * @param print (default is true) if true prints the equation and result.
     * @return time to switch on off current through an inductor
     */
    static ld timeOnOffToInduceCurrent(const ld I, const ld L, const ld emf, bool print = true);

    /**
     * @brief Calculate  the current of a system with duel rails,
     * under the following conditions. The resistance between the rails is R,
     * the rails and the moving rod are identical in cross section A and have
     * the same resistivity ρ . The distance between the rails is l, and the
     * rod moves at constant speed v perpendicular to the uniform field B.
     * At time zero, the moving rod is next to the resistance R.
     * @param B The magnetic field.
     * @param l The length.
     * @param v The velocity.
     * @param A The area.
     * @param p The resistivity.
     * @param R The radius.
     * @param t The time.
     * @param print (default is true) if true prints the equation and result.
     * @return current
     */
    static ld currentSystemOnRails(
            ld B, ld l, ld v, ld A, ld p, ld R, ld t, bool print = true);

    /**
     * @brief Calculates the Characteristic time constant. (cTc)
     * @param L The inductance.
     * @param R The resistance.
     * @param print (default is true) if true prints the equation and result.
     * @return the time constant
     */
    static ld inductiveTimeConstant(ld L, ld R, bool print = true);

    /**
     * @brief Inductances the reactance (XL)
     * @param f The frequency.
     * @param L The inductance.
     * @param print (default is true) if true prints the equation and result.
     * @return inductive reactance (H)
     */
    static ld inductanceReactance_fL(ld f, ld L, bool print = true);

    /**
     * @brief calculates the Capacitive reactance (XC).
     * @param f The frequency.
     * @param C The capacitance_Qv.
     * @param print (default is true) if true prints the equation and result.
     * @return capacitive reactance (ohms)
     */
    static ld capacitiveReactance_fC(ld f, ld C, bool print = true);

    /**
     * @brief Calculates the capacitance_Qv from reactance and frequency
     * @param f The frequency in Hz.
     * @param _xc The capacitive reactance.
     * @param print (default is true) if true prints the equation and result.
     * @return farads
     */
    static ld capacitanceFromReactance(ld f, ld _xc, bool print = true);

    /**
     * @brief Calculates the current in an inductor of an RC circuit at specific
     * moments of time t with an initial current of Io and a characteristic time
     * constant of tao.
     * @param Io The initial current in inductor.
     * @param t The time in seconds.
     * @param tao The characteristic time constant.
     * @param print (default is true) if true prints the equation and result.
     * @return current at specified time when switched on (A)
     */
    static ld current_RLCircuit_switchON(ld Io, ld t, ld tao, bool print = true);

    /**
     * @brief Calculates the current of an inductor of an RC circuit switch off.
     * @param Io The current initially.
     * @param t The time in seconds.
     * @param tao The characteristic time  constant.
     * @param print (default is true) if true prints the equation and result.
     * @return current at specified time when switched off
     */
    static ld current_RICircuit_switchOFF(ld Io, ld t, ld tao, bool print = true);

    /**
     * @brief Calculate current in RL circuit.
     * @param emf The emf.
     * @param R The resistance.
     * @param L The inductance.
     * @param t The time.
     * @param print (default is true) if true prints the equation and result.
     * @return current in RL circuit
     */
    static ld current_RLCircuit(ld emf, ld R, ld L, ld t, bool print = true);

    /**
     * @brief Calculates I(t) in an RL circuit with decreasing current so
     * di/dt < 0.
     * @param emf The emf.
     * @param R The resistance.
     * @param L The inductance.
     * @param t The time.
     * @param print (default is true) if true prints the equation and result.
     * @return current in RL circuit
     */
    static ld current_RLCircuitDecreasingI(
            ld emf, ld R, ld L, ld t, bool print = true);

    /**
     * @brief Calculates the current through inductor.
     * @param Vrms The rms Voltage.
     * @param _xl The inductance reactance.
     * @param print (default is true) if true prints the equation and result.
     * @return current
     */
    static ld currentRMS_throughInductor(ld Vrms, ld _xl, bool print = true);

    /**
     * @brief Calculates the current through capacitor.
     * @param Vrms The Voltage RMS.
     * @param _xc The conductive reactance.
     * @param print (default is true) if true prints the equation and result.
     * @return current
     */
    static ld currentRMS_throughCapacitor(ld Vrms, ld _xc, bool print = true);

    /**
     * @brief Calculates the peeks the current in an AC circuit using the peek voltage
     * of Vo and its impedance of Z_.
     * @param Vo The peek voltage in circuit.
     * @param Z_ The impedance.
     * @param print (default is true) if true prints the equation and result.
     * @return The peek current -> Io = peek Amps
     */
    static ld peekCurrent_AC(ld Vo, ld Z, bool print = true);

    /**
     * @brief Calculates the RMS(root mean square) or average current in an AC circuit
     * using the rms Voltage and the circuits impedance of Z_.
     * @param Vrms The rms Voltage, average voltage.
     * @param Z_ The impedance in circuit.
     * @param print (default is true) if true prints the equation and result.
     * @return the average or rms current Irms -> (A)
     */
    static ld rmsCurrent_AC(ld Vrms, ld Z, bool print = true);

    /**
     * @brief Calculates the RMS(root mean square current or average current in a AC
     * series circuit.
     * @param Vrms The root mean square voltage or Vrms.
     * @param R The resistance.
     * @param _xl The inductive reactance.
     * @param _xc The conductive reactance.
     * @param print (default is true) if true prints the equation and result.
     * @return Irms or root mean square current, average current(A)
     */
    static ld rmsCurrent_AC(ld Vrms, ld R, ld _xl, ld _xc, bool print = true);

    /**
     * @brief Calculates the RMS(root mean square current or average current in a AC
     * series circuit.
     * @param Vrms The root mean square voltage or Vrms.
     * @param R The resistance.
     * @param L The inductance.
     * @param C The capacitance_Qv.
     * @param f The frequency.
     * @param print (default is true) if true prints the equation and result.
     * @return Irms or root mean square current, average current(A)
     */
    static ld rmsCurrent_AC(ld Vrms, ld R, ld L, ld C, ld f, bool print = true);

    /**
     * @brief Calculates the Impedance in a RLC series AC circuit. For circuits without
     * a resistor take R=0, for those without and inductor take _xl = 0, for
     * those without a capacitor take _xc = 0.
     * @param R The resistance.
     * @param _xl The inductive reactance.
     * @param _xc The capacitive reactance.
     * @param print (default is true) if true prints the equation and result.
     * @return the impedance on an AC circuit (Ohms)
     */
    static ld impedance(ld R, ld _xl, ld _xc, bool print = true);

    /**
     * @brief Calculates the impedance in a RLC series AS circuit.
     * @param R The resistance.
     * @param L The inductance.
     * @param C The capacitance_Qv.
     * @param f The frequency.
     * @param print (default is true) if true prints the equation and result.
     * @return the impedance on an AC circuit (Ohms)
     */
    static ld impedance(ld R, ld L, ld C, ld f, bool print = true);

    /**
     * @brief Calculates the resonant frequency in an RLC series AC circuit
     * @param L The inductance.
     * @param C The capacitance_Qv.
     * @param print (default is true) if true prints the equation and result.
     * @return resonant frequency (Hz)
     */
    static ld resonantFrequency(ld L, ld C, bool print = true);

    /**
     * @brief Calculates the power factor. cos(phi) = R/Z_.
     * @param R The resistance.
     * @param Z_ The impedance.
     * @param print (default is true) if true prints the equation and result.
     * @return power factor(unit-less)
     */
    static ld powerFactor(ld R, ld Z, bool print = true);

    /**
     * @brief Phases the angle.
     * @param pf The pf.
     * @param print (default is true) if true prints the equation and result.
     * @return phase angle
     */
    static ld phaseAngle(ld pf, bool print = true);

    /**
     * @brief Phases the angle.
     * @param R The resistance.
     * @param Z_ The impedance.
     * @param print (default is true) if true prints the equation and result.
     * @return phase angle
     */
    static ld phaseAngle(ld R, ld Z, bool print = true);

    /**
     * @brief Powers the average RLC.
     * @param Irms The average current .
     * @param Vrms The average voltage.
     * @param pf The power factor.
     * @param print (default is true) if true prints the equation and result.
     * @return power in an RLC series AC circuit
     */
    static ld powerAvgRLC(ld Irms, ld Vrms, ld pf, bool print = true);

    /**
     * @brief Calculates the peak emf  generated by a r(m) radius, N-turn
     * coil that is rotated one-fourth of a revolution in t(s), originally
     * having its plane perpendicular to a uniform B(T) magnetic field?
     * (This is 58 rev/s.)
     * @param r The radius.
     * @param N The number of turns in coil.
     * @param t The time in seconds.
     * @param B The magnetic field strength.
     * @param print (default is true) if true prints the equation and result.
     * @return peek emf
     */
    static ld emfPeek(ld r, ld N, ld t, ld B, bool print = true);

    /**
     * @brief A solenoid of circular cross section has radius R consists of
     * n turns per unit length, and carries current I. Find the magnetic flux
     * through each turn of the solenoid.
     * @param R The radius.
     * @param n The number of turns per unit length.
     * @param I The current.
     * @param print (default is true) if true prints the equation and result.
     * @return magnetic flux through each turn of the solenoid
     * @note The magnetic flux through a solenoid is given by the formula: \n
     * phi = BA = μ0*n*I*π*R^2
     */
    static ld magneticFluxSolenoidLoop(ld R, ld n, ld I, bool print = true);

    /**
     * @brief A long, straight wire carries current I. A rectangular wire loop
     * of dimensions l by w lies in a plane containing the wire, with its
     * closest edge a distance a from the wire and its dimension l parallel to
     * the wire. Find the magnetic flux through the loop.
     * @param I The current.
     * @param a The distance from the wire.
     * @param l The length of the loop.
     * @param w The width of the loop.
     * @param print (default is true) if true prints the equation and result.
     * @return magnetic flux through the loop
     * @note The magnetic flux through a rectangular loop in mField is given by
     * the formula: \n phi = BdA = (μ0*I*l/2π)*ln((a + w)/a)
     */
    static ld magneticFluxRectangularLoop(
            ld I, ld a, ld l, ld w, bool print = true);

    /**
     * @brief A wire loop of radius r m has resistance R. The plane of the
     * loop is perpendicular to a uniform magnetic field that’s increasing
     * at dB_dt T/s. Find the magnitude of the induced current in the loop.
     * @param r The radius.
     * @param R The resistance.
     * @param dB_dt The time.
     * @param print (default is true) if true prints the equation and result.
     * @return magnitude of the induced current in the loop
     */
    static ld inducedCurrentLoop(ld r, ld R, ld dB_dt, bool print = true);

    /**
     * @brief Two parallel conducting rails a distance l apart are connected
     * at one end by a resistance R. A conducting bar completes the circuit,
     * joining the two rails electrically but free to slide along them. The
     * whole circuit is perpendicular to a uniform magnetic field B. Find the
     * current when the bar is pulled to the right with constant speed v.
     * @param l The distance.
     * @param R The resistance.
     * @param v The speed.
     * @param B The magnetic field.
     * @param print (default is true) if true prints the equation and result.
     * @return current when the bar is pulled to the right with constant speed
     */
    static ld currentSlidingBar(ld l, ld R, ld v, ld B, bool print = true);

    /**
     * @brief Calculate the electric power dissipated in a square loop of
     * resistance R, with sides of length l, when the loop is placed in a
     * magnetic field B that is perpendicular to the plane of the loop and
     * is moving at a constant speed v.
     * @param l The length of the loop.
     * @param R The resistance.
     * @param v The speed.
     * @param B The magnetic field.
     * @param print (default is true) if true prints the equation and result.
     * @return electric power dissipated in a square loop
     * @note The electric power dissipated in a square loop given R, l, v, B
     * is: \n P = IE = (B^2*l^2*v^2) / R
     */
    static ld powerDissipatedSquareLoop(
              ld l, ld R, ld v, ld B, bool print = true);

    /**
     * @brief An electric generator consists of a n-turn circular coil with
     * a diameter of d m. It’s rotated at a frequency of f rev/s. Find the
     * magnetic field strength needed for a peak output voltage of V volts.
     * @param n The number of turns.
     * @param d The diameter.
     * @param f The frequency.
     * @param V The voltage.
     * @param print (default is true) if true prints the equation and result.
     * @return magnetic field strength needed for a peak output voltage
     */
    static ld magneticFieldStrengthGenerator(
                ld n, ld d, ld f, ld V, bool print = true);

    /**
     * @brief A large electromagnet used for lifting scrap iron has
     * self-inductance of L H. It’s connected to a constant V-volt power source;
     * the total resistance of the circuit is R. Calculate the time it takes
     * for the current to reach x% of its final value.
     * @param L The self-inductance.
     * @param R The resistance.
     * @param x The percentage.
     * @param print (default is true) if true prints the equation and result.
     * @return time it takes for the current to reach x% of its final value
     */
    static ld timeCurrentToReachXPercent(ld L, ld R, ld x, bool print = true);

    /**
     * @brief Calculate the rate at which an inductor stores energy when it
     * has a current of I A applied to the inductor of L H in time t s.
     * @param I The current.
     * @param L The self-inductance.
     * @param t The time.
     * @param print (default is true) if true prints the equation and result.
     * @return rate at which an inductor stores energy
     */
    static ld rateInductorStoresEnergy(ld I, ld L, ld t, bool print = true);

    /**
     * @brief Superconducting electromagnets like the solenoids in MRI scanners
     * store a lot of magnetic energy. Loss of coolant can be dangerous because
     * the current is suddenly left without its zero-resistance path and quickly
     * decays. The result is an explosive release of magnetic energy. A
     * particular MRI solenoid carries I A and has a L H inductance. When
     * it loses superconductivity, its resistance goes abruptly to R.
     * Calculate:
     * (a) the stored magnetic energy
     * (b) the rate of energy release at the instant superconductivity is lost.
     * @param I The current.
     * @param L The self-inductance.
     * @param R The resistance.
     * @param print (default is true) if true prints the equation and result.
     * @return stored magnetic energy and rate of energy release
     */
    static vector<ld> energyReleaseMRI(ld I, ld L, ld R, bool print = true);

    /**
     * @brief Calculate the magnetic energy stored in a solenoid of with a
     * length of l and a cross-sectional area of A m^2 with n turns and a
     * current of I A.
     * @param l The length.
     * @param A The cross-sectional area.
     * @param n The number of turns.
     * @param I The current.
     * @param print (default is true) if true prints the equation and result.
     * @return magnetic energy stored in a solenoid
     */
    static ld energyStoredSolenoid(ld l, ld A, ld n, ld I, bool print = true);

    /**
     * @brief Calculate the magnetic energy stored in a solenoid of with a
     * length of l and a cross-sectional area of A m^2 with a B T magnetic
     * field.
     * @param l The length.
     * @param A The cross-sectional area.
     * @param B The magnetic field.
     * @param print (default is true) if true prints the equation and result.
     * @return magnetic energy stored in a solenoid
     */
    static ld energyStoredSolenoid(ld l, ld A, ld B, bool print = true);

    /**
     * @brief Calculate the magnetic energy density per unit volume in a
     * magnetic field of B T.
     * @param B The magnetic field.
     * @param print (default is true) if true prints the equation and result.
     * @return magnetic energy density per unit volume
     */
    static ld energyDensityMagneticField(ld B, bool print = true);

    /**
     * @brief A long solenoid has circular cross section of radius R. The
     * solenoid current is increasing, and as a result so is the magnetic
     * field in the solenoid. The field strength as a function of time t is
     * given by B=bt where b is a constant. Find the induced electric field
     * outside the solenoid, a distance r from the axis.
     * @param R The radius.
     * @param b The constant.
     * @param r The distance.
     * @param print (default is true) if true prints the equation and result.
     * @return induced electric field outside the solenoid
     */
    static ld inducedElectricFieldSolenoid(
                ld R, ld b, ld r, bool print = true);

    /**
     * @breif In a physics laboratory experiment, a coil with n turns
     * enclosing an area of A m2 is rotated during the time interval of
     * t s from a position in which its plane is angle theta_i to Earth's
     * magnetic field to one in which its plane is angle theta_f to the field.
     * The magnitude of Earth's magnetic field at the lab location is B T.
     * Calculate the following:
     * (a) the magnitude of the magnetic flux (Φinitial) through the coil before
     *     it is rotated
     * (b) the magnitude of the magnetic flux (Φfinal) through the coil after
     *    it is rotated
     * (c) the magnitude of the average emf induced in the coil.
     * @param n The number of turns.
     * @param A The area.
     * @param t The time.
     * @param B The magnetic field.
     * @param theta_i The initial angle.
     * @param theta_f The final angle.
     * @param print (default is true) if true prints the equation and result.
     * @return the magnitude of the magnetic flux, the magnitude of the average
     */
    static vector<ld> magneticFluxAndAverageEmf(
                int n, ld A, ld t, ld B, ld theta_i = 0,
                ld theta_f = 90, bool print = true);

    /**
     * @brief What fraction of the maximum value will be reached by the current
     * t seconds after a switch is closed. Assume that resistance is R ohms
     * and induction is L henries.
     * @param L The self-inductance.
     * @param R The resistance.
     * @param t The time.
     * @param print (default is true) if true prints the equation and result.
     * @return fraction of the maximum value will be reached by the current
     */
    static ld fractionOfMaxValueReached(ld L, ld R, ld t, bool print = true);

    /**
     * @brief Shrinking Loop. A circular loop of flexible iron wire has an
     * initial circumference of C m , but its circumference is decreasing at a
     * constant rate of deltaC m/s due to a tangential pull on the wire. The
     * loop is in a constant uniform magnetic field of magnitude B T, which
     * is oriented perpendicular to the plane of the loop. Assume that you are
     * facing the loop and that the magnetic field points into the loop.
     * Calculate the magnitude of the emf E induced in the loop after exactly
     * time t s has passed since the circumference of the loop started to
     * decrease, and find the direction of the induced current in the loop
     * as viewed looking along the direction of the magnetic field.
     * @param C The circumference.
     * @param deltaC The change in circumference.
     * @param B The magnetic field.
     * @param t The time.
     * @param d is the direction of the B field.
     * @param print (default is true) if true prints the equation and result.
     * @return magnitude of the emf and direction of the induced current
     * in the loop
     */
    static vector<ld> emfAndInducedCurrent(
                ld C, ld deltaC, ld B, ld t, Direction d, bool print = true);

    /**
     * @brief Calculate the magnitude of the potential difference between the
     * ends of a rod of length l m in a uniform magnetic field of magnitude B
     * T, moving with a velocity v m/s.
     * @param l The length.
     * @param B The magnetic field.
     * @param v The velocity.
     * @param print (default is true) if true prints the equation and result.
     * @return magnitude of the potential difference
     */
    static ld potentialDifferenceAcrossRod(ld l, ld B, ld v, bool print = true);

    /**
     * @brief Calculate the magnitude of the potential difference between the
     * ends of a rod of length l m in a electric field of magnitude E V/m,
     * @param l The length.
     * @param E The electric field.
     * @param print (default is true) if true prints the equation and result.
     * @return magnitude of the potential difference
     */
    static ld potentialDifferenceAcrossRod(ld l, ld E, bool print = true);

    /**
     * @brief A circular wire loop d m in diameter has resistance R Ω and
     * lies in a horizontal plane. A uniform magnetic field points vertically
     * downward, and in t s it increases linearly from Bi T to Bf mT.
     * Calculate the following:
     * (a) the magnetic flux through the loop at the beginning.
     * (b) the magnetic flux through the loop at the end of the time interval.
     * (c) the loop current during this time.
     * @param d The diameter.
     * @param R The resistance.
     * @param Bi The initial magnetic field.
     * @param Bf The final magnetic field.
     * @param t The time.
     * @param print (default is true) if true prints the equation and result.
     * @return the magnetic flux through the loop at the beginning, the
     */
    static vector<ld> magneticFluxAndCurrent(
                ld d, ld R, ld Bi, ld Bf, ld t, bool print = true);

    /**
     * @brief A conducting loop of area A-m^2 and resistance R Ω lies at right
     * angles to a spatially uniform magnetic field. The loop carries an induced
     * current of I A. Calculate at what rate the magnetic field is changing.
     * @param A The area.
     * @param R The resistance.
     * @param I The current.
     * @param print (default is true) if true prints the equation and result.
     * @return the rate the magnetic field is changing
     */
    static ld rateOfChangeOfMagneticField(ld A, ld R, ld I, bool print = true);

    /**
     * @brief Calculate the magnetic field of a conducting loop of area A-m^2
     * and resistance R Ω, carrying an induced current of I A.
     * @param A The area.
     * @param R The resistance.
     * @param I The current.
     * @param print (default is true) if true prints the equation and result.
     * @return the rate the magnetic field is changing
     */
    static ld magneticField_IRA(ld I, ld R, ld A, bool print = true);

    /**
     * @brief The magnetic field inside a d-m diameter solenoid is increasing at
     * detlaB T/s. Calculate how many turns should a coil be wrapped around the
     * outside of the solenoid have so that the emf induced in the coil is
     * emf volts?
     * @param d The diameter.
     * @param deltaB The change in magnetic field.
     * @param emf The emf.
     * @param print (default is true) if true prints the equation and result.
     * @return the number of turns
     */
    static ld numberOfTurns(ld d, ld deltaB, ld emf, bool print = true);

    /**
     * brief A long solenoid with cross-sectional area A and length l is wound
     * with N1 turns of wire. A time-varying current I1 flows through this wire.
     * A shorter coil with N2 turns of wire surrounds it. Use μ0 for the
     * permeability of free space. Find the value M of the mutual inductance.
     * @param A The cross-sectional area.
     * @param l The length.
     * @param N1 The number of turns of wire in the solenoid.
     * @param I1 The current flowing through the solenoid.
     * @param N2 The number of turns of wire in the coil.
     * @param print (default is true) if true prints the equation and result.
     * @return the value of the mutual inductance
     */
    static ld mutualInductance(
                ld A, ld l, ld N1, ld I1, ld N2, bool print = true);

    /**
     * @brief A N-turn solenoid l m long and d m in diameter carries
     * I A. Calculate how much magnetic energy it contains (U).
     * @param N The number of turns.
     * @param l The length.
     * @param d The diameter.
     * @param I The current.
     * @param print (default is true) if true prints the equation and result.
     * @return the magnetic energy
     */
    static ld magneticEnergy(ld N, ld l, ld d, ld I, bool print = true);

    /**
     * @brief Calculate the EMF that is produced if a waffle iron that draws
     * I amperes and has an inductance of L Henries is and is suddenly
     * unplugged, so the current drops to essentially to zero in 0.015 seconds
     * @param I The current.
     * @param L The inductance.
     * @param t The time.
     * @param print (default is true) if true prints the equation and result.
     * @return the emf
     */
    static ld emf(ld I, ld L, ld t, bool print = true);

    /**
     * @brief A cylindrical iron rod of infinite length with cross-sectional
     * area A is oriented with its axis of symmetry coincident with the z axis
     * of a cylindrical coordinate system as shown in the figure. It has a
     * magnetic field inside that varies according to Bz(t)=B0+B1t.
     * Calculate the theta component Eθ(R,t) of the electric field at
     * distance R from the z axis, where R is larger than the radius of the rod.
     * @param A The cross-sectional area.
     * @param dB The change in magnetic field.
     * @param R The distance.
     * @param print (default is true) if true prints the equation and result.
     * @return the theta component of the electric field
     */
    static ld electricFieldTheta(ld A, ld dB, ld R, bool print = true);

    /**
     * @brief A N-turn solenoid is l m long and d m in diameter. The
     * solenoid current is increasing at dI A/s.
     * Calculate the following:
     * (a) the current in a d1-diameter wire loop with resistance R Ω lying
     * inside the solenoid and perpendicular to the solenoid axis.
     * (b) Repeat for a similarly oriented with a loop lying entirely outside
     * the solenoid,  with the same resistance R.
     * @param N The number of turns.
     * @param l The length.
     * @param d The diameter.
     * @param d1 The diameter of the first loop.
     * @param R The resistance of the first loop.
     * @param dI The change in current.
     * @param print (default is true) if true prints the equation and result.
     * @return the current in the first loop and the current in the second loop
     * respectively
     */
    static vector<ld> currentInLoops(
                ld N, ld l, ld d, ld d1, ld R, ld dI, bool print = true);

    /**
     * @brief two horizontal rails in a uniform magnetic field B T are
     * connected by a wire with resistance R Ω at one end and a vertical
     * sliding rod moving with a velocity of v m/s, separated by a
     * length of l m between the horizontal rails.
     * Calculate the following:
     * (a) the current in the resistor
     * (b) the magnetic force on the rod
     * (c) the power dissipated in the resistor
     * (d) the rate of mechanical work done by the agent pulling the rod
     * @param B The magnetic field.
     * @param R The resistance.
     * @param v The velocity.
     * @param l The length.
     * @param print (default is true) if true prints the equation and result.
     * @return the current in the resistor, the magnetic force on the rod,
     * the power dissipated in the resistor, and the rate of mechanical work
     * done by the agent pulling the rod respectively
     */
    static vector<ld> slidingRod(
                ld B, ld R, ld v, ld l, bool print = true);
    /**
     * @brief Calculate the force on a sliding bar in a uniform magnetic field
     * B T, with a current I A flowing through it, and a length of l m.
     * @param I  The current.
     * @param l  The length.
     * @param B  The magnetic field.
     * @param print  (default is true) if true prints the equation and result.
     * @return  the force
     */
    static ld magneticForceSlidingBar(ld I, ld l, ld B, bool print = true);

    /**
     * @brief Calculate the work done on a sliding bar being pulled by a
     * force of F N at a constant velocity of v m/s.
     * @param f The force.
     * @param v The velocity.
     * @param print  (default is true) if true prints the equation and result.
     * @return  the work done
     */
    static ld workDoneSlidingBar(ld f, ld v, bool print = true);

    /**
     * @brief Given a RL circuit with a resistor of R Ω and ε0 = emf V and a
     * switch S. When the switch is closed, the current through the inductor
     * rises to I A in t s.
     * Calculate the following:
     * (a) the inductance of the inductor
     * (b) the time constant of the circuit
     * (c) the current in the circuit after many time constants have passed
     * @param R The resistance.
     * @param V The emf.
     * @param I The current.
     * @param t The time.
     * @param print  (default is true) if true prints the equation and result.
     * @return  the inductance, the time constant, and the current respectively
     * after many time constants have passed
     */
    static vector<ld> inductorRLCircuit(
                ld R, ld V, ld I, ld t, bool print = true);

    /**
     * @brief Calculate the time constant of a circuit at time t when the
     * current is I A, and the maximum current is I0 A.
     * @param t  The time.
     * @param I The current.
     * @param I0  The maximum current.
     * @param print  (default is true) if true prints the equation and result.
     * @return  the time constant
     */
    static ld timeConstant(ld t, ld I, ld I0, bool print = true);



    ~ElectroMagneticInduction()
    {
        countDecrease();
    }

private:
    static void countIncrease() { emi_objectCount += 1; }
    static void countDecrease() { emi_objectCount -= 1; }
    ld _electroMagVar;



};
#endif //PHYSICSFORMULA_ELECTROMAGNETICINDUCTION_H

//=============================================================================
//in-line class Implementation

inline ld ElectroMagneticInduction::magneticFlux(
        const ld B, const ld A, const ld theta, bool print)
{
    auto phi = B * A * cos(theta * constants::RADIAN);//T*m^2 = Wb
    if (print)
        std::cout << "Magnetic Flux = " << phi << " Wb" << std::endl;
    return phi;
}

inline ld ElectroMagneticInduction::emfFaradayFullEquation(
        const ld N, const ld r, const ld B, const ld t, const ld thetaS,
        const ld thetaF, bool print)
{
    const ld area = constants::PI * (r * r);
    const ld deltaTheta = cos(thetaF * constants::RADIAN) -
            cos(thetaS * constants::RADIAN);
    const ld flux = area * B * deltaTheta;
    auto var =  -N * (flux / t);
    if (print)
        std::cout << "EMF = " << var << " Volts" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::emfMagnitude_FaradayNoMinus(
        const ld N, const ld r, const ld B1, const ld B2, const ld t,
        const ld theta, bool print)
{
    const ld area = constants::PI * (r * r);
    const ld deltaB = abs(B2 - B1);
    const ld deltaFlux = area * deltaB * cos(theta*constants::RADIAN);

    auto var = N * (deltaFlux / t);//V
    if (print)
        std::cout << "EMF = " << var << " Volts" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::deltaFlux(
        const ld A, const ld deltaB, bool print)
{
    auto var = A * deltaB;
    if (print)
        std::cout << "Delta Flux = " << var << " Wb" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::emf_inducedInGeneratorCoil(
        const ld N, const ld l, const ld w, const ld aW, const ld B,
        const ld t, bool print)
{
    const ld area = l * w;
    auto var = N * area * B * aW * sin((aW * t) * constants::RADIAN);//V
    if (print)
        std::cout << "EMF = " << var << " Volts" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::emf_peek(
        const ld N, const ld A, const ld B, const ld aW, bool print)
{
    auto var = N * A * B * aW;//V
    if (print)
        std::cout << "EMF = " << var << " Volts" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::emf_peek(
        const ld N, const ld r, const ld B, const ld rad, const ld t,
        bool print)
{
    const ld area = constants::PI * (r * r);
    const ld aW = rad / t;
    auto var = N * area * B * aW;//V
    if (print)
        std::cout << "EMF = " << var << " Volts" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::emfPeek_r(
        const ld N, const ld r, const ld B, const ld aW, bool print)
{
    auto var = N * constants::PI * (r * r) * B * aW;
    if (print)
        std::cout << "EMF = " << var << " Volts" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::emf_peekFromDiameterAndRPMs(
        const ld N, const ld d, const ld B, const ld rpm, bool print)
{
    const ld aW = (rpm * 2.0 * constants::PI) / 60.0;//angular velocity
    const ld A = (constants::PI * (d * d)) / 4;//cross-sectional
    auto var = N * A * B * aW;//V
    if (print)
        std::cout << "EMF = " << var << " Volts" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::emf_inducedByMagneticFlux(
        const ld N, const ld f, const ld t, bool print)
{
    auto var = -N * (f / t);//V
    if (print)
        std::cout << "EMF = " << var << " Volts" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::emf_avgOnCoil(
        const ld B, const ld d, const ld t, bool print)
{
    auto var = (constants::PI * B * (d * d)) / (4.0 * t);//V
    if (print)
        std::cout << "EMF = " << var << " Volts" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::n_turnsInCoilFromEMFEquation(
        const ld t, const ld emf, const ld f, bool print)
{
    auto var = (t / f) * emf;//turns in coil
    if (print)
        std::cout << "N = " << var << " turns" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::flux_fromEMFEquation(
        const ld emf, const ld t, const ld N, bool print)
{
    auto var = -(t * emf) / N;//T*m^2
    if (print)
        std::cout << "Flux = " << var << " Wb" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::time_fromEMFEquation(
        const ld N, const ld f, const ld emf, bool print)
{
    auto var = N * (f / emf);//seconds
    if (print)
        std::cout << "Time = " << var << " seconds" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::motionalEMF(
        const ld B, const ld l, const ld x, const ld t, bool print)
{
    auto var = B * ((l * x) / t);//V
    if (print)
        std::cout << "EMF = " << var << " Volts" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::motionalEMF(
        const ld B, const ld l, const ld v, bool print)
{
    auto var = B * l * v;//V
    if (print)
        std::cout << "EMF = " << var << " Volts" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::lengthOfRod_emfEq(
        const ld V, const ld B, const ld v, bool print)
{
    auto var = V / (B * v);//m
    if (print)
        std::cout << "Length = " << var << " meters" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::velocityOfMotion_emfEq(
        const ld V, const ld B, const ld l, bool print)
{
    auto var = V / (B * l);// m/s
    if (print)
        std::cout << "Velocity = " << var << " meters per second" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::magneticFieldFrom_emfEq(
        const ld V, const ld l, const ld v, bool print)
{
    auto var = V / (l * v);//T
    if (print)
        std::cout << "Magnetic Field = " << var << " Tesla" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::magneticFieldMagnitude(
        const ld flux, const ld Ard, const ld theta = 0, const ld mode = 'A',
        bool print)
{
    ld area;
    ld var;
    if (mode == 'a' || mode == 'A')
    {
        var = flux/(Ard*cos(theta*constants::RADIAN));//(T)
    }
    else if (mode == 'r' || mode == 'R')
    {
        area = constants::PI * (Ard * Ard);
        var = flux/(area*cos(theta*constants::RADIAN));//(T)
    }
    else
    {
        area = constants::PI * ((Ard * Ard) / 4.0);
        var = flux/(area*cos(theta*constants::RADIAN));//(T)
    }
    if (print)
        std::cout << "Magnetic Field = " << var << " Tesla" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::transformerEquations_VN(
        const ld Vs, const ld Vp, const ld Ns, const ld Np,
        const std::string& mode, bool print)
{
    ld var;
    if (mode == "Vs" || mode == "vs" || mode == "VS" || mode == "vS")
    {
        var = (Ns / Np) * Vp;//voltage secondary
    }
    else if (mode == "Vp" || mode == "vp" || mode == "VP" || mode == "vP")
    {
        var = (Np / Ns) * Vs;//voltage primary
    }
    else if (mode == "Ns" || mode == "ns" || mode == "NS" || mode == "nS")
    {
        var = (Vs / Vp) * Np;//number of loops secondary
    }
    else if (mode == "Np" || mode == "np" || mode == "NP" || mode == "nP")
    {
        var = (Vp / Vs) * Ns;//number of loops primary
    }
    else
        var = -111111111111;//error
    if (print) {
        if (var == -111111111111)
            std::cout << "Error: Invalid mode" << std::endl;
        else
            std::cout << "Value = " << var << std::endl;
    }
    return var;
}

inline ld ElectroMagneticInduction::transformerEquations_VI(
        const ld Vs, const ld Vp, const ld Is, const ld Ip,
        const std::string& mode, bool print)
{
    ld var;
    if (mode == "Vs" || mode == "vs" || mode == "VS" || mode == "vS")
    {
        var = (Ip / Is) * Vp;//voltage secondary
    }
    else if (mode == "Vp" || mode == "vp" || mode == "VP" || mode == "vP")
    {
        var = (Is / Ip) * Vs;//voltage primary
    }
    else if (mode == "Is" || mode == "is" || mode == "IS" || mode == "iS")
    {
        var = (Vp / Vs) * Ip;//current secondary
    }
    else if (mode == "Ip" || mode == "ip" || mode == "IP" || mode == "iP")
    {
        var = (Vs / Vp) * Is;//current primary
    }
    else
        var = -111111111111;//error
    if (print) {
        if (var == -111111111111)
            std::cout << "Error: Invalid mode" << std::endl;
        else
            std::cout << "Value = " << var << std::endl;
    }
    return var;
}

inline ld ElectroMagneticInduction::transformerEquations_IN(
        const ld Is, const ld Ip, const ld Ns, const ld Np,
        const std::string& mode, bool print)
{
    ld var;
    if (mode == "Is" || mode == "is" || mode == "IS" || mode == "iS")
    {
        var = (Np / Ns) * Ip;//current secondary
    }
    else if (mode == "Ip" || mode == "ip" || mode == "IP" || mode == "iP")
    {
        var = (Ns / Np) * Is;//current primary
    }
    else if (mode == "Ns" || mode == "ns" || mode == "NS" || mode == "nS")
    {
        var = (Ip / Is) * Np;//number of loops secondary
    }
    else if (mode == "Np" || mode == "np" || mode == "NP" || mode == "nP")
    {
        var = (Is / Ip) * Ns;//number of loops primary
    }
    else
        var = -111111111111;//error
    if (print) {
        if (var == -111111111111)
            std::cout << "Error: Invalid mode" << std::endl;
        else
            std::cout << "Value = " << var << std::endl;
    }
    return var;
}

inline ld ElectroMagneticInduction::frequency(const ld aW, bool print)
{
    auto var = aW/(2.0 * constants::PI);//Hz
    if (print)
        std::cout << "Frequency = " << var << " Hertz" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::period(const ld f, bool print)
{
    auto var = 1 / f;//s
    if (print)
        std::cout << "Period = " << var << " seconds" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::maxCurrent(
        ld emf, ld R, bool print)
{
    auto var = emf/R;//A
    if (print)
        std::cout << "Current in coil = " << var << " Ampere" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::emf_byMutualInductance(
        const ld M, const ld I, const ld t, bool print)
{
    auto emf = -M * (I / t);//V
    if (print)
        std::cout << "EMF = " << emf << " Volt" << std::endl;
    return emf;
}

inline ld ElectroMagneticInduction::mutualInductance(
        const ld emf, const ld I, const ld t, bool print)
{
    auto var = -emf * (t / I);//henry(H) = (V*s)/A = Ohm*s
    if (print)
        std::cout << "Mutual Inductance = " << var << " Henry" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::inductorEMF(
        const ld L, const ld I, const ld t, bool print)
{
    auto var = -L * (I / t);//V
    if (print)
        std::cout << "EMF = " << var << " Volt" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::selfInductance(
        const ld emf, const ld I, const ld t, bool print)
{
    auto L = -emf * (t / I);//henry(H)= (V*s)/A = Ohm*s
    if (print)
        std::cout << "Self Inductance = " << L << " Henry" << std::endl;
    return L;
}

inline ld ElectroMagneticInduction::selfInductance_NBI(
        const ld N, const ld phi, const ld I, bool print)
{
    auto L = N * (phi / I);//(H)
    if (print)
        std::cout << "Self Inductance = " << L << " Henry" << std::endl;
    return L;
}


inline ld ElectroMagneticInduction::selfInductance_phiI(
        ld phi, ld I, bool print)
{
    auto L = phi / I;//(H)
    if (print)
        std::cout << "Self Inductance = " << L << " Henry" << std::endl;
    return L;
}

inline ld ElectroMagneticInduction::selfInductance_taoR(
        const ld toa, const ld R, bool print)
{
    auto var = toa * R;//H
    if (print)
        std::cout << "Self Inductance = " << var << " Henry" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::inductanceSolenoid_NAL(
        int N, ld A, ld l, char mode = 'a', bool print)
{
    ld area;
    ld var;
    if (mode == 'a' || mode == 'A')
    {
        var = (constants::mu0 * (N * N) * A) / l;//(H)
    }
    else if	(mode == 'r' || mode == 'R')
    {
        area = circle_area_r(A);
        var = (constants::mu0 * (N * N) * area) / l;//(H)
    }
    else if (mode == 'c' || mode == 'C')
    {
        area = circle_area_c(A);
        var = (constants::mu0 * (N * N) * area) / (2.0 * l);//(H)
    }
    else
    {
        area = circle_area_d(A);
        var = (constants::mu0 * (N * N) * area) / l;//(H)
    }
    if (print)
        std::cout << "Inductance = " << var << " Henry" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::inductanceFromEnergyStored(
        const ld E, const ld I, bool print)
{
    auto var = (2.0 * E) / (I * I);//H = Ohm *s
    if (print)
        std::cout << "Inductance = " << var << " Henry" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::energyStoredInInductor(
        const ld L, const ld I, bool print)
{
    auto var = (1.0 / 2.0) * L * (I * I);//J
    if (print)
        std::cout << "Energy = " << var << " Joule" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::timeOnOffToInduceCurrent(
        const ld I, const ld L, const ld emf, bool print)
{
    auto var = L * (I / emf);//seconds
    if (print)
        std::cout << "Time = " << var << " seconds" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::currentSystemOnRails(
        const ld B, const ld l, const ld v, const ld A, const ld p, const ld R,
        const ld t, bool print)
{
    auto var = (B * l * v * A) / (p * (2.0 * v * t + l) + R*A);//A
    if (print)
        std::cout << "Current = " << var << " Ampere" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::inductiveTimeConstant(
        ld L, ld R, bool print)
{
    auto var = L/R;//s
    if (print)
        std::cout << "Time Constant = " << var << " seconds" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::inductanceReactance_fL(
        ld f, ld L, bool print)
{
    auto var = 2.0 * constants::PI * f * L;
    if (print)
        std::cout << "Reactance = " << var << " Ohm" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::capacitiveReactance_fC(
        ld f, ld C, bool print)
{
    auto var = 1.0 / (2.0 * constants::PI * f * C);//ohms
    if (print)
        std::cout << "Reactance = " << var << " Ohm" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::capacitanceFromReactance(
        const ld f, const ld _xc, bool print)
{
    auto var = 1.0 / (2.0 * constants::PI * f * _xc);//F
    if (print)
        std::cout << "Capacitance = " << var << " Farad" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::current_RLCircuit_switchON(
        const ld Io, const ld t, const ld tao, bool print)
{
    auto var = Io * (1.0 - exp(-t / tao));//A
    if (print)
        std::cout << "Current = " << var << " Ampere" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::current_RICircuit_switchOFF(
        const ld Io, const ld t, const ld tao, bool print)
{
    auto var = Io * exp(-t / tao);//A
    if (print)
        std::cout << "Current = " << var << " Ampere" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::currentRMS_throughInductor(
        const ld Vrms, const ld _xl, bool print)
{
    auto var = Vrms / _xl;//A
    if (print)
        std::cout << "Current = " << var << " Ampere" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::currentRMS_throughCapacitor(
        const ld Vrms, const ld _xc, bool print)
{
    auto var = Vrms / _xc;//A
    if (print)
        std::cout << "Current = " << var << " Ampere" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::peekCurrent_AC(
        const ld Vo, const ld Z, bool print)
{
    auto var = Vo / Z;//A
    if (print)
        std::cout << "Current = " << var << " Ampere" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::rmsCurrent_AC(
        const ld Vrms, const ld Z, bool print)
{
    auto var = Vrms / Z;//A
    if (print)
        std::cout << "Current = " << var << " Ampere" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::rmsCurrent_AC(
        const ld Vrms, const ld R, const ld _xl, const ld _xc, bool print)
{
    const ld imp = impedance(R, _xl, _xc);
    auto var = Vrms/imp;
    if (print)
        std::cout << "Current = " << var << " Ampere" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::rmsCurrent_AC(
        const ld Vrms, const ld R, const ld L, const ld C, const ld f,
        bool print)
{
    const ld XL = inductanceReactance_fL(f, L);
    const ld XC = capacitiveReactance_fC(f, C);
    const ld Z = sqrt((R * R) + pow((XL - XC), 2));
    auto var = Vrms / Z;
    if (print)
        std::cout << "Current = " << var << " Ampere" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::impedance(
        const ld R, const ld _xl, const ld _xc, bool print)
{
    auto var = sqrt((R * R) + pow((_xl - _xc), 2));//Ohms
    if (print)
        std::cout << "Impedance = " << var << " Ohm" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::impedance(
        const ld R, const ld L, const ld C, const ld f, bool print)
{
    const ld XL = inductanceReactance_fL(f, L);
    const ld XC = capacitiveReactance_fC(f, C);
    auto var = sqrt((R * R) + pow((XL - XC), 2));
    if (print)
        std::cout << "Impedance = " << var << " Ohm" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::resonantFrequency(
        const ld L, const ld C, bool print)
{
    auto var = 1.0 / (20 * constants::PI * sqrt(L * C));//Hz
    if (print)
        std::cout << "Resonant Frequency = " << var << " Hz" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::powerFactor(
        const ld R, const ld Z, bool print)
{
    auto var = R / Z;
    if (print)
        std::cout << "Power Factor = " << var << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::phaseAngle(
        const ld pf, bool print)
{
    auto var = acos(pf);
    if (print)
        std::cout << "Phase Angle = " << var << " Radians" << std::endl;
    return var;

}

inline ld ElectroMagneticInduction::phaseAngle(
        const ld R, const ld Z, bool print)
{
    const ld pf = powerFactor(R, Z);
    auto var = acos(pf);
    if (print)
        std::cout << "Phase Angle = " << var << " Radians" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::powerAvgRLC(
        const ld Irms, const ld Vrms, const ld pf, bool print)
{
    auto var = Irms * Vrms * pf;//Watts
    if (print)
        std::cout << "Power = " << var << " Watts" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::emfPeek(
        const ld r, const ld N, const ld t, const ld B, bool print)
{
    //peek emf (Vo)
    auto var = ((constants::PI * constants::PI) * N * (r * r) * B) / (2.0 * t);
    if (print)
        std::cout << "EMF = " << var << " Volts" << std::endl;
    return var;
}

inline ld ElectroMagneticInduction::magneticFluxSolenoidLoop(
        ld R, ld n, ld I, bool print)
{
    auto mu0 = constants::mu0;
    auto pi = constants::PI;
    auto phi = mu0*n*I*pi*(R*R);
    if (print)
        std::cout << "Magnetic Flux = " << phi << " Webers" << std::endl;
    return phi;
}

inline ld ElectroMagneticInduction::magneticFluxRectangularLoop(
        ld I, ld a, ld l, ld w, bool print)
{
    auto mu0 = constants::mu0;
    auto pi = constants::PI;
    auto phi = ((mu0*I*l)/(2.0*pi)) * std::log((a+w)/a);
    if (print)
        std::cout << "Magnetic Flux = " << phi << " Webers" << std::endl;
    return phi;
}

inline ld ElectroMagneticInduction::inducedCurrentLoop(
        ld r, ld R, ld dB_dt, bool print)
{
    auto mu0 = constants::mu0;
    auto pi = constants::PI;
    auto emf = pi * (r * r) * dB_dt;
    auto I = emf / R;
    if (print)
        std::cout << "Induced Current = " << I << " Ampere" << std::endl;
    return I;
}

inline ld ElectroMagneticInduction::currentSlidingBar(
        ld l, ld R, ld v, ld B, bool print)
{
    auto I = (B*l*v) / R;
    if (print)
        std::cout << "Current = " << I << " Ampere" << std::endl;
    return I;
}

inline ld ElectroMagneticInduction::powerDissipatedSquareLoop(
        ld l, ld R, ld v, ld B, bool print)
{
    auto P = (B*B*l*l*v*v) / R;
    if (print)
        std::cout << "Power = " << P << " Watts" << std::endl;
    return P;
}

inline ld ElectroMagneticInduction::magneticFieldStrengthGenerator(
        ld n, ld d, ld f, ld V,  bool print)
{
    auto pi = constants::PI;
    auto r = d/2.0;
    auto B = V / (2.0*(pi*pi)*(r*r)*n*f);
    if (print)
        std::cout << "Magnetic Field Strength = " << B << " Tesla" << std::endl;
    return B;
}

inline ld ElectroMagneticInduction::current_RLCircuit(
        ld emf, ld R, ld L, ld t,  bool print)
{
    auto I = (emf / R) * (1 - exp(-R * t / L));
    if (print)
        std::cout << "Current = " << I << " Ampere" << std::endl;
    return I;
}

inline ld ElectroMagneticInduction::timeCurrentToReachXPercent(
        ld L, ld R, ld x, bool print)
{
    auto t = -(L / R)*log(1.0 - (x / 100.0));
    if (print)
        std::cout << "Time = " << t << " Seconds" << std::endl;
    return t;
}

inline ld ElectroMagneticInduction::rateInductorStoresEnergy(
        ld I, ld L, ld t, bool print)
{
    auto P = (L*I) * (I / t);
    if (print)
        std::cout << "Power = " << P << " Watts" << std::endl;
    return P;
}

inline vector<ld> ElectroMagneticInduction::energyReleaseMRI(
        ld I, ld L, ld R, bool print)
{
    auto U = energyStoredInInductor(I, L, false);
    auto P = Magnetism::electricalPower_IR(I, R, false);
    if (print) {
        std::cout << "Energy Stored = " << U << " Joules" << std::endl;
        std::cout << "Power = " << P << " Watts" << std::endl;
    }
    return {U, P};
}

inline ld ElectroMagneticInduction::energyStoredSolenoid(
        ld l, ld A, ld n, ld I, bool print)
{
    auto mu0 = constants::mu0;
    auto U = (1.0 / 2.0 * mu0)*pow(mu0 * n * I, 2.0) * l * A;
    if (print)
        std::cout << "Energy Stored = " << U << " Joules" << std::endl;
    return U;
}

inline ld ElectroMagneticInduction::energyStoredSolenoid(
        ld l, ld A, ld B, bool print)
{
    auto mu0 = constants::mu0;
    auto U = ((B*B)/(2.0*mu0)) * l * A;
    if (print)
        std::cout << "Energy Stored = " << U << " Joules" << std::endl;
    return U;
}

inline ld ElectroMagneticInduction::energyDensityMagneticField(
        ld B, bool print)
{
    auto mu0 = constants::mu0;
    auto U = (B*B) / (2.0*mu0);
    if (print)
        std::cout << "Energy Density = " << U << " Joules/m^3" << std::endl;
    return U;
}

inline ld ElectroMagneticInduction::inducedElectricFieldSolenoid(
        ld R, ld b, ld r, bool print)
{
    auto E = (R*R*b) / (2.0*r);
    if (print)
        std::cout << "Induced Electric Field = " << E << " Volts/m" << std::endl;
    return E;
}

inline vector<ld> ElectroMagneticInduction::magneticFluxAndAverageEmf(
        int n, ld A, ld t, ld B, ld theta_i, ld theta_f, bool print)
{
    // threshold to check if results can be considered 0, because cos(90) = 0
    // but in c++ ends up never being 0 and need it to be 0
    double threshold = .000000001;
    // calculate the initial magnetic flux
    auto phi0 = A * B * cos(theta_i * constants::RADIAN);
    // calculate the final magnetic flux after rotating the coil in time t
    auto phi = A * B * cos(theta_f * constants::RADIAN);
    // check the threshold to see if the results can be considered 0
    if (abs(phi0) < threshold)
        phi0 = 0;
    if (abs(phi) < threshold)
        phi = 0;
    // calculate the average emf
    auto emf = -n * ((phi - phi0) / t);
    if (print) {
        std::cout << "Initial Magnetic Flux = " << phi0 << " Webers" << std::endl;
        std::cout << "Final Magnetic Flux = " << phi << " Webers" << std::endl;
        std::cout << "Average EMF = " << emf << " Volts" << std::endl;
    }
    return {phi0, phi, emf};
}

inline ld ElectroMagneticInduction::fractionOfMaxValueReached(
        ld L, ld R, ld t, bool print)
{
    auto x = 100.0 * (1.0 - exp(-R * t / L));
    if (print)
        std::cout << "Fraction of Max Value Reached = " << x << "%" << std::endl;
    return x;
}

inline ld ElectroMagneticInduction::current_RLCircuitDecreasingI(
        ld emf, ld R, ld L, ld t, bool print)
{
    auto I = (emf / R) * (exp(-R * t / L));
    if (print)
        std::cout << "Current = " << I << " Ampere" << std::endl;
    return I;
}

inline vector<ld> ElectroMagneticInduction::emfAndInducedCurrent(
        ld C, ld deltaC, ld B, ld t, Direction d, bool print)
{
    string dir;
    auto C_f = C - t*deltaC;
    auto emf = (B * (C_f/(2.0 * constants::PI)))*deltaC;
    auto I_dir = (d == Direction::U) ? -1 : 1;
    auto I = I_dir * (emf / C_f);
    if (I_dir == -1)
        dir = "clockwise";
    else
        dir = "counter-clockwise";
    if (print) {
        std::cout << "EMF = " << emf << " Volts" << std::endl;
        std::cout << "Induced Current = " << dir << " direction" << std::endl;
        std::cout << "Induced Current = " << I << " Ampere" << std::endl;
    }
    return {emf, I};
}

inline ld ElectroMagneticInduction::potentialDifferenceAcrossRod(
        ld l, ld B, ld v, bool print)
{
    auto V = v * B * l;
    if (print)
        std::cout << "Potential Difference = " << V << " Volts" << std::endl;
    return V;
}

inline ld ElectroMagneticInduction::potentialDifferenceAcrossRod(
        ld l, ld E, bool print)
{
    auto V = E * l;
    if (print)
        std::cout << "Potential Difference = " << V << " Volts" << std::endl;
    return V;
}

inline vector<ld> ElectroMagneticInduction::magneticFluxAndCurrent(
        ld d, ld R, ld Bi, ld Bf, ld t, bool print)
{
    auto pi = constants::PI;
    auto phi_i = Bi * circle_area_d(d) * cos(0.0);
    auto phi_f = Bf * circle_area_d(d) * cos(0.0);
    auto emf = (phi_f - phi_i) / t;
    auto I = emf / R;
    if (print) {
        std::cout << "Initial Magnetic Flux = " << phi_i << " Webers" << std::endl;
        std::cout << "Final Magnetic Flux = " << phi_f << " Webers" << std::endl;
        std::cout << "EMF = " << emf << " Volts" << std::endl;
        std::cout << "Current = " << I << " Ampere" << std::endl;
    }
    return {phi_i, phi_f, emf, I};
}

inline ld ElectroMagneticInduction::rateOfChangeOfMagneticField(
        ld A, ld R, ld I, bool print)
{
    auto dB = (R * I) / A;
    if (print)
        std::cout << "Rate of Change of Magnetic Field = " << dB << " Tesla/s" << std::endl;
    return dB;
}

inline ld ElectroMagneticInduction::magneticField_IRA(
        ld I, ld R, ld A, bool print)
{
    auto B = (I * R) / A;
    if (print)
        std::cout << "Magnetic Field = " << B << " Tesla" << std::endl;
    return B;
}

inline ld ElectroMagneticInduction::numberOfTurns(
        ld d, ld deltaB, ld emf, bool print)
{
    auto A = circle_area_d(d);
    auto n = round((ld)emf / (A * deltaB));
    if (print)
        std::cout << "Number of Turns = " << n << std::endl;
    return (ld)n;
}

inline ld ElectroMagneticInduction::selfInductance(
        ld emf, ld deltaI, bool print)
{
    auto L = (emf / deltaI);
    if (print)
        std::cout << "Self Inductance = " << L << " Henry" << std::endl;
    return L;
}

inline ld ElectroMagneticInduction::mutualInductance(
        ld A, ld l, ld N1, ld I1, ld N2, bool print)
{
    auto mu0 = constants::mu0;
    auto M = (mu0 * N1 * N2 * A) / l;
    if (print)
        std::cout << "Mutual Inductance = " << M << " Henry" << std::endl;
    return M;
}

inline ld ElectroMagneticInduction::magneticEnergy(
        ld N, ld l, ld d, ld I, bool print)
{
    auto mu0 = constants::mu0;
    auto A = circle_area_d(d);
    auto U = (1.0/2.0) * ((mu0 * (N * N) * A) / l) * (I * I);
    if (print)
    std::cout << "Magnetic Energy = " << U << " Joules" << std::endl;
    return U;
}

inline ld ElectroMagneticInduction::emf(
        ld I, ld L, ld t, bool print)
{
    auto emf = I * L * (1.0 / t);
    if (print)
        std::cout << "EMF = " << emf << " Volts" << std::endl;
    return emf;
}

inline ld ElectroMagneticInduction::electricFieldTheta(
        ld A, ld dB, ld R, bool print)
{
    auto E = (A * dB) / (R * 2.0 * constants::PI);
    if (print)
        std::cout << "Electric Field = " << E << " Newton/Coulomb" << std::endl;
    return E;
}

inline vector<ld> ElectroMagneticInduction::currentInLoops(
        ld N, ld l, ld d, ld d1, ld R, ld dI, bool print)
{
    auto mu0 = constants::mu0;
    auto pi = constants::PI;
    auto A1 = circle_area_d(d1);
    auto E_ind1 = mu0 * (N / l) * A1 * dI;
    auto I1 = E_ind1 / R;
    auto A2 = circle_area_d(d);
    auto E_ind2 = mu0 * (N / l) * A2 * dI;
    auto I2 = E_ind2 / R;
    if (print) {
        std::cout << "EMF Induced in Loop 1 = " << E_ind1 << " Newton/Coulomb" << std::endl;
        std::cout << "Current in Loop 1 = " << I1 << " Ampere" << std::endl;
        std::cout << "EMF Induced in Loop 2 = " << E_ind2 << " Newton/Coulomb" << std::endl;
        std::cout << "Current in Loop 2 = " << I2 << " Ampere" << std::endl;
    }
    return {I1, I2};
}

inline vector<ld> ElectroMagneticInduction::slidingRod(
        ld B, ld R, ld v, ld l, bool print)
{
    // part a find current in resistor
    auto I = currentSlidingBar(l, R, v, B, false);
    // part b find the magnetic force on the bar
    auto F = magneticForceSlidingBar(I, l, B, false);
    // part c find the power dissipated in the resistor
    auto P = electricalPower_IR(I, R, false);
    // part d find the work done by the agent pulling the bar
    auto W = workDoneSlidingBar(F, v, false);
    if (print) {
        std::cout << "Current in Resistor = " << I << " Ampere" << std::endl;
        std::cout << "Magnetic Force on Bar = " << F << " Newton" << std::endl;
        std::cout << "Power Dissipated in Resistor = " << P << " Watts" << std::endl;
        std::cout << "Work Done by Agent = " << W << " Watts" << std::endl;
    }
    return {I, F, P, W};
}

inline ld ElectroMagneticInduction::magneticForceSlidingBar(
        ld I, ld l, ld B, bool print)
{
    auto F = I * l * B;
    if (print)
        std::cout << "Magnetic Force = " << F << " Newton" << std::endl;
    return F;
}

inline ld ElectroMagneticInduction::workDoneSlidingBar(
        ld f, ld v, bool print)
{
    auto W = f * v;
    if (print)
        std::cout << "Work Done = " << W << " Joules" << std::endl;
    return W;
}

inline vector<ld> ElectroMagneticInduction::inductorRLCircuit(
        ld R, ld V, ld I, ld t, bool print)
{
    // part a find the inductance of the inductor
    auto I0 = maxCurrent(V, R, false);
    auto t1 = timeConstant(t, I, I0, false);
    auto L = selfInductance_taoR(t1, R, false);
    // part b find the time constant of the circuit
    auto t2 = inductiveTimeConstant(L, R, false);
    // part c find the current in the circuit at many time constants
    auto I1 = I0;
    if (print) {
        std::cout << "Inductance = " << L << " Henry" << std::endl;
        std::cout << "Time Constant = " << t2 << " Seconds" << std::endl;
        std::cout << "Current at (t = infinity) = " << I1 << " Ampere" <<
        std::endl;
    }
    return {L, t2, I1};
}

inline ld ElectroMagneticInduction::timeConstant(
        ld t, ld I, ld I0, bool print)
{
    auto tao = - t / log((I0 - I) / I0);
    if (print)
        std::cout << "Time Constant = " << tao << " Seconds" << std::endl;
    return tao;
}
