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


    /// <summary>
    /// Calculates the magnetic flux where B is the magnetic field strength(T)
    /// over an area of A (m^2), at an angle theta with the perpendicular to
    /// the area. Any change in the magnetic flux induces an emf. This process
    /// is defined to be electromagnetic induction.
    /// </summary>
    /// <param name="B">The magnetic field strength(T).</param>
    /// <param name="A">The area(m^2).</param>
    /// <param name="theta">The angle theta default is at 0 degrees which
    /// is equal to 1 making the equation flux = B*A.</param>
    /// <returns>the magnetic flux (T*m^2)</returns>
    static ld magneticFlux( ld B, ld A, ld theta);

    /// <summary>
    /// A generator coil is rotated through a revolution from 0 to theta degrees,
    /// in t seconds. Having N turns the coil has a radius of r (m) and is in a
    /// uniform magnetic field of B. Calculate the average emf induced.
    /// </summary>
    /// <param name="N">The number of turns in coil.</param>
    /// <param name="r">The radius of coil.</param>
    /// <param name="B">The magnetic uniform field.</param>
    /// <param name="t">The time it takes to rotate theta degrees.</param>
    /// <param name="thetaS">The starting angle of rotation.</param>
    /// <param name="thetaF">The finishing angle of rotation.</param>
    /// <returns>emf average (V)</returns>
    static ld emfFaradyFullEquation(ld N, ld r, ld B, ld t, ld thetaS, ld thetaF);

    /// <summary>
    /// Calculates the magnitude of an induced emf when a bar magnet  is thrust
    /// into a coil with N loops having a radius of r (m) and the average value of
    /// B cos(theta) that is given due to complexity as increasing from B1 to B2
    /// over a period of t seconds.
    /// </summary>
    /// <param name="N">The number of loops.</param>
    /// <param name="r">The radius.</param>
    /// <param name="B1">The starting magnetic field.</param>
    /// <param name="B2">The ending magnetic field.</param>
    /// <param name="t">The time over which the increase of the
    /// magnetic field takes place.</param>
    /// <returns>magnitude of emf (V)</returns>
    static ld emfMagnitude_FaradayNoMinus(ld N, ld r, ld B1, ld B2, ld t, ld theta);

    /// <summary>
    /// Calculates the change in flux.
    /// </summary>
    /// <param name="A">the area = pi*r^2.</param>
    /// <param name="deltaB">The delta b = .</param>
    /// <returns></returns>
    static ld deltaFlux(ld A, ld deltaB);

    /// <summary>
    /// EMFs the induced in generator coil.
    /// </summary>
    /// <param name="N">The number of loop in coil.</param>
    /// <param name="l">The length of the loop.</param>
    /// <param name="w">The width of coil loop.</param>
    /// <param name="aW">a angular velocity.</param>
    /// <param name="B">The magnetic field strength.</param>
    /// <param name="t">The time for a rotation.</param>
    /// <returns>emf total from generator coil (V)</returns>
    static ld emf_inducedInGeneratorCoil(ld N, ld l, ld w, ld aW, ld B, ld t);

    /// <summary>
    /// Calculates the peek emf.
    /// </summary>
    /// <param name="N">The number of turns in a coil.</param>
    /// <param name="A">The area.</param>
    /// <param name="B">The magnetic field strength.</param>
    /// <param name="aW">The angular velocity.</param>
    /// <returns>peek emf (V)</returns>
    static ld emf_peek(ld N, ld A, ld B, ld aW);

    /// <summary>
    /// Calculates the peek emf.
    /// </summary>
    /// <param name="N">The number of turns in a coil.</param>
    /// <param name="r">The radius of coil.</param>
    /// <param name="B">The magnetic field strength.</param>
    /// <param name="rad">The angle of rotation in radians.</param>
    /// <param name="t">The time for a rotation.</param>
    /// <returns>peek emf (V)</returns>
    static ld emf_peek(ld N, ld r, ld B, ld rad, ld t);

    /// <summary>
    /// A N turn, r(m) radius coil rotates at an angular velocity of
    /// aW rad/s in a B(T) field, starting with the normal of the plane
    /// of the coil perpendicular to the field. Assume that the positive max
    /// emf is reached first.
    /// </summary>
    /// <param name="N">The number of turns in coil.</param>
    /// <param name="r">The radius or half of the diameter.</param>
    /// <param name="B">The magnetic field strength.</param>
    /// <param name="aW">a angular velocity.</param>
    /// <returns>peek emf</returns>
    static ld emfPeek_r(ld N, ld r, ld B, ld aW);

    /// <summary>
    /// Calculate the peak voltage of a generator that rotates its N-turn,
    /// d m diameter coil rotating at rpm rpms in a B T field.
    /// </summary>
    /// <param name="N">The number of loops in coil.</param>
    /// <param name="d">The diameter of coil.</param>
    /// <param name="B">The magnetic filed strength.</param>
    /// <param name="rpm">The RPMs.</param>
    /// <returns>peek emf voltage</returns>
    static ld emf_peekFromDiameterAndRPMs(ld N, ld d, ld B, ld rpm);

    /// <summary>
    /// Calculates the EMF induced by magnetic flux over t time having N turns
    /// is considered Faraday's law of induction: Lenz's Law->(why there is a
    /// minus sign.
    /// </summary>
    /// <param name="N">The amount of turns in coil.</param>
    /// <param name="f">The flux.</param>
    /// <param name="t">The time.</param>
    /// <returns>emf = volts(V)</returns>
    static ld emf_inducedByMagneticFlux(ld N, ld f, ld t);

    /// <summary>
    /// An MRI technician moves his hand from a region of very low magnetic field
    /// strength into an MRI scanner’s magnetic field of B(T) with his fingers
    /// pointing in the direction of the field. Calculate the average emf induced in
    /// his wedding ring, given its diameter is d(m) and assuming it takes time
    /// t(s) to move it into the field.
    /// </summary>
    /// <param name="B">The magnetic filed.</param>
    /// <param name="d">The diameter.</param>
    /// <param name="t">The time in seconds.</param>
    /// <returns>average emf (V)</returns>
    static ld emf_avgOnCoil(ld B, ld d, ld t);

    /// <summary>
    /// number of turns in a coil from EMF and time t over the flux;
    /// </summary>
    /// <param name="t">The time.</param>
    /// <param name="emf">The EMF.</param>
    /// <param name="f">The flux.</param>
    /// <returns>turns in a coil</returns>
    static ld n_turnsInCoilFromEMFEquation(ld t, ld emf, ld f);

    /// <summary>
    /// calculates the fluxes from EMF equation, with a time of t and N turns in
    /// a coil
    /// </summary>
    /// <param name="emf">The EMF.</param>
    /// <param name="t">The time.</param>
    /// <param name="N">The number of turns in a coil.</param>
    /// <returns>magnetic flux(T*m^2)</returns>
    static ld flux_fromEMFEquation(ld emf, ld t, ld N);

    /// <summary>
    /// calculates the times from EMF equation with a flux and emf with N turns
    /// of a coil.
    /// </summary>
    /// <param name="N">The number of turns of a coil</param>
    /// <param name="f">The flux.</param>
    /// <param name="emf">The EMF.</param>
    /// <returns>time in seconds</returns>
    static ld time_fromEMFEquation(ld N, ld f, ld emf);

    /// <summary>
    /// Calculates the motional  EMF.
    /// </summary>
    /// <param name="B">The magnetic field.</param>
    /// <param name="l">The length of rod.</param>
    /// <param name="x">The distance the rod moves.</param>
    /// <param name="t">The time it moves over.</param>
    /// <returns>emf from motion (V)</returns>
    static ld motionalEMF(ld B, ld l, ld x, ld t);

    /// <summary>
    /// Calculates the motional EMF.
    /// </summary>
    /// <param name="B">The magnetic field.</param>
    /// <param name="l">The length of rod.</param>
    /// <param name="v">The velocity -> x/t .</param>
    /// <returns>emf from motion(V)</returns>
    static ld motionalEMF(ld B, ld l, ld v);

    /// <summary>
    /// calculates the length a magnetic rod must be when producing an emf of V.
    /// </summary>
    /// <param name="V">The EMF voltage (V).</param>
    /// <param name="B">The magnetic field (B).</param>
    /// <param name="v">The velocity (v).</param>
    /// <returns>length of magnetic rod</returns>
    static ld lengthOfRod_emfEq(ld V, ld B, ld v);

    /// <summary>
    /// Calculates the velocity of the motion of magnetic rod when a emf of V is
    /// created with a magnetic field of B and having a rod of length l (m).
    /// </summary>
    /// <param name="V">The emf voltage (V).</param>
    /// <param name="B">The magnetic field (T).</param>
    /// <param name="l">The length of rod (m).</param>
    /// <returns>velocity (m/s)</returns>
    static ld velocityOfMotion_emfEq(ld V, ld B, ld l);

    /// <summary>
    /// Calculates the magnetic field from when a rod of length l moves at a
    /// velocity of v causing a magnetic field strength of B.
    /// </summary>
    /// <param name="V">The emf voltage.</param>
    /// <param name="l">The length of rod.</param>
    /// <param name="v">The velocity.</param>
    /// <returns>magnetic field strength (T)</returns>
    static ld magneticFieldFrom_emfEq(ld V, ld l, ld v);

    /// <summary>
    /// Magnetics the field magnitude.
    /// </summary>
    /// <param name="flux">The flux.</param>
    /// <param name="Ard">The Area, radius or diameter.</param>
    /// <param name="theta">The theta, is at default value of 0.</param>
    /// <param name="mode">The mode is used as a switch between what
    /// information you use for the Ard argument: use 'r' for radius or 'd'
    /// for diameter and if you are using the already calculated cross sectional
    /// then leave out..</param>
    /// <returns>magnetic field (T)</returns>
    static ld magneticFieldMagnitude(ld flux, ld Ard, ld theta, ld mode);

    /// <summary>
    /// Calculates the voltage or number of loops in a transformer. Use a 0 as
    /// placeholder in the unknowns method argument.
    /// </summary>
    /// <param name="Vs">The volts secondary(output).</param>
    /// <param name="Vp">The volts primary(input).</param>
    /// <param name="Ns">The number of loops secondary(output).</param>
    /// <param name="Np">The number of loops primary(input).</param>
    /// <param name="mode">The mode used to specify what you want to solve for,\n
    /// "Vs" = volts secondary,\n
    /// "vp" = volts primary,\n
    /// "Ns" = number of loops secondary,\n
    /// "Np" = number of loops primary.\n
    /// example: transformerEquation(2.5,3.4,5,10,"Ns");\n
    /// this would solve for the number of loops in the secondary transformer</param>
    /// <returns>volts or loops depending on mode used</returns>
    static ld transformerEquations_VN(ld Vs, ld Vp, ld Ns, ld Np, std::string mode);

    /// <summary>
    /// Calculates the voltage or current in a transformer. use a 0 as a place
    /// holder in the unknown variables method argument.
    /// </summary>
    /// <param name="Vs">The volts secondary(output).</param>
    /// <param name="Vp">The volts primary(input).</param>
    /// <param name="Is">The current secondary(output).</param>
    /// <param name="Ip">The current primary(input).</param>
    /// <param name="mode">The mode used to specify what you want to solve for,\n
    /// "Vs" = volts secondary,\n
    /// "vp" = volts primary,\n
    /// "Is" = current secondary,\n
    /// "Ip" = current primary.\n
    /// example: transformerEquation(2.5,3.4,5,10,"Is");\n
    /// this would solve for the current in the secondary transformer</param>
    /// <returns>volts or current depending on the mode picked</returns>
    static ld transformerEquations_VI(ld Vs, ld Vp, ld Is, ld Ip, std::string mode);

    /// <summary>
    /// Calculates the current or number of loops in a transformer. use a 0 as a place
    /// holder in the unknown variables method argument.
    /// </summary>
    /// <param name="Is">The current secondary(output).</param>
    /// <param name="Ip">The current primary(input).</param>
    /// <param name="Ns">The number of loops secondary(output).</param>
    /// <param name="Np">The number of loops primary(input).</param>
    /// <param name="mode">The mode used to specify what you want to solve for,\n
    /// "Is" = current secondary,\n
    /// "Ip" = current primary,\n
    /// "Ns" = number of loops secondary,\n
    /// "Np" = number of loops primary.\n
    /// example: transformerEquation(2.5,3.4,5,10,"Is");\n
    /// this would solve for the current in the secondary transformer</param>
    /// <returns>current or number of loops depending on the mode picked</returns>
    static ld transformerEquations_IN(ld Is, ld Ip, ld Ns, ld Np, std::string mode);

    /// <summary>
    /// Calculates the frequencies from a know angular velocity of aW.
    /// </summary>
    /// <param name="aW">a angular velocity.</param>
    /// <returns>frequency (Hz</returns>
    static ld frequency(ld aW);

    /// <summary>
    /// Calculates the period from the known frequency of f.
    /// </summary>
    /// <param name="f">The frequency.</param>
    /// <returns></returns>
    static ld period(ld f);

    /// <summary>
    /// Calculates the current in the coil.
    /// </summary>
    /// <param name="emf">The EMF.</param>
    /// <param name="R">The resistance.</param>
    /// <returns>current (A)</returns>
    static ld currentInCoil(ld emf, ld R);

    /// <summary>
    /// Calculates the emf2 from the mutual inductance of M between two devices
    /// where the current from device one is I and the time t over which the
    /// current changes.
    /// </summary>
    /// <param name="M">The Mutual inductance.</param>
    /// <param name="I">The current.</param>
    /// <param name="t">The time.</param>
    /// <returns>emf voltage</returns>
    static ld emf_byMutualInductance(ld M, ld I, ld t);


    /// <summary>
    /// Calculates the mutual inductance.
    /// </summary>
    /// <param name="emf">The EMF.</param>
    /// <param name="I">The current.</param>
    /// <param name="t">The time.</param>
    /// <returns>henry(H)</returns>
    static ld mutualInductance(ld emf, ld I, ld t);

    /// <summary>
    /// calculates the EMF by self inductance. also the back emf calculated with
    /// this methods equation
    /// </summary>
    /// <param name="L">The self inductance of the device.</param>
    /// <param name="I">The current.</param>
    /// <param name="t">The time.</param>
    /// <returns>emf voltage</returns>
    static ld emf_bySelfInductance(ld L, ld I, ld t);

    /// <summary>
    /// calculates the self inductance.
    /// </summary>
    /// <param name="emf">The EMF.</param>
    /// <param name="I">The current.</param>
    /// <param name="t">The time.</param>
    /// <returns>inductance of inductor(H)</returns>
    static ld selfInductance(ld emf, ld I, ld t);

    /// <summary>
    /// calculates the self inductance.
    /// </summary>
    /// <param name="N">The number of loops.</param>
    /// <param name="B">The flux.</param>
    /// <param name="I">The current.</param>s
    /// <returns>inductance(H)</returns>
    static ld selfInductance_N(ld N, ld B, ld I);

    /// <summary>
    /// Calculates the self the inductance using the time constant and resistance
    /// </summary>
    /// <param name="toa">The time constant.</param>
    /// <param name="R">The resistance.</param>
    /// <returns>self inductance</returns>
    static ld selfInductance_timeConstant(ld toa, ld R);

    /// <summary>
    /// Calculates the inductance of a solenoid.
    /// </summary>
    /// <param name="N">The number of turns in coil.</param>
    /// <param name="Ard">the area, radius or diameter.</param>
    /// <param name="l">The length of solenoid.</param>
    /// <param name="mode">put a 'r' if use a radius or a 'd' if using the
    /// diameter in the Ard argument.</param>
    /// <returns>inductance(H)</returns>
    static ld inductanceSolenoid_L(ld N, ld A, ld l, char mode);

    /// <summary>
    /// Calculates the inductance from total energy of E stored in inductor
    /// having a current of I.
    /// </summary>
    /// <param name="E">The energy of inductor.</param>
    /// <param name="I">The current.</param>
    /// <returns>the inductance (H)</returns>
    static ld inductanceFromEnergyStored(ld E, ld I);

    /// <summary>
    /// Calculates the energy stored in an inductor.
    /// </summary>
    /// <param name="L">The inductance.</param>
    /// <param name="I">The current.</param>
    /// <returns>energy (J)</returns>
    static ld energyStoredInInductor(ld L, ld I);

    /// <summary>
    /// Camera flashes charge a capacitor to high voltage by switching the
    /// current through an inductor on and off rapidly. Calculate what time must
    /// the a current of I through a inductance of L be switched on or off to
    /// induce a emf.
    /// </summary>
    /// <param name="I">The current.</param>
    /// <param name="L">The inductance.</param>
    /// <param name="emf">The EMF.</param>
    /// <returns>time to switch on off current through an inductor</returns>
    static ld timeOnOffToinduceCurrent(ld I, ld L, ld emf);

    /// <summary>
    /// Calculate  the current of a system with duel rails,
    /// under the following conditions. The resistance between the rails is R,
    /// the rails and the moving rod are identical in cross section A and have
    /// the same resistivity ρ . The distance between the rails is l, and the
    /// rod moves at constant speed v perpendicular to the uniform field B.
    /// At time zero, the moving rod is next to the resistance R.
    /// </summary>
    /// <param name="B">The magnetic field.</param>
    /// <param name="l">The length.</param>
    /// <param name="v">The velocity.</param>
    /// <param name="A">The area.</param>
    /// <param name="p">The resistivity.</param>
    /// <param name="R">The radius.</param>
    /// <param name="t">The time.</param>
    /// <returns>current</returns>
    static ld currentSystemOnRails(ld B, ld l, ld v, ld A, ld p, ld R, ld t);

    /// <summary>
    /// Calculates the Characteristic time constant. (cTc)
    /// </summary>
    /// <param name="L">The inductance.</param>
    /// <param name="R">The resistance.</param>
    /// <returns>the time constant</returns>
    static ld characteristicTimeConstant(ld L, ld R);

    /// <summary>
    /// Inductances the reactance (XL)
    /// </summary>
    /// <param name="f">The frequency.</param>
    /// <param name="L">The inductance.</param>
    /// <returns>inductive reactance (H)</returns>
    static ld inductance_reactance_XL(ld f, ld L);

    /// <summary>
    /// calculates the Capacitive reactance (XC).
    /// </summary>
    /// <param name="f">The frequency.</param>
    /// <param name="C">The capacitance.</param>
    /// <returns>capacitive reactance (ohms)</returns>
    static ld capacitive_reactance_XC(ld f, ld C);

    /// <summary>
    /// Calculates the capacitance from reactance and frequency
    /// </summary>
    /// <param name="f">The frequency in Hz.</param>
    /// <param name="_xc">The capacitive reactance.</param>
    /// <returns>farads</returns>
    static ld capacitanceFromReactance(ld f, ld _xc);

    /// <summary>
    /// Calculates the current in an inductor of an RC circuit at specific moments
    /// of time t with an initial current of Io and a characteristic time constant of cTc.
    /// </summary>
    /// <param name="Io">The initial current in inductor.</param>
    /// <param name="t">The time in seconds.</param>
    /// <param name="cTc">The characteristic time constant.</param>
    /// <returns>current at specified time when switched on (A)</returns>
    static ld current_RLCircuit_switchON(ld Io, ld t, ld cTc);

    /// <summary>
    /// Calculates the current of an inductor of an RC circuit switch off.
    /// </summary>
    /// <param name="Io">The current initially.</param>
    /// <param name="t">The time in seconds.</param>
    /// <param name="cTc">The characteristic time  constant.</param>
    /// <returns>current at specified time when switched off </returns>
    static ld current_RICircuit_switchOFF(ld Io, ld t, ld cTc);

    /// <summary>
    /// Calculates the current through inductor.
    /// </summary>
    /// <param name="Vrms">The rms Voltage.</param>
    /// <param name="_xl">The inductance reactance.</param>
    /// <returns>current</returns>
    static ld currentRMS_throughInductor(ld Vrms, ld _xl);

    /// <summary>
    /// Calculates the current through capacitor.
    /// </summary>
    /// <param name="Vrms">The Voltage RMS.</param>
    /// <param name="_xc">The conductive reactance.</param>
    /// <returns>current</returns>
    static ld currentRMS_throughCapacitor(ld Vrms, ld _xc);

    /// <summary>
    /// Calculates the peeks the current in an AC circuit using the peek voltage
    /// of Vo and its impedance of Z_.
    /// </summary>
    /// <param name="Vo">The peek voltage in circuit.</param>
    /// <param name="Z_">The impedance.</param>
    /// <returns>The peek current -> Io = peek Amps</returns>
    static ld peekCurrent_AC(ld Vo, ld Z);

    /// <summary>
    /// Calculates the RMS(root mean square) or average current in an AC circuit
    /// using the rms Voltage and the circuits impedance of Z_.
    /// </summary>
    /// <param name="Vrms">The rms Voltage, average voltage.</param>
    /// <param name="Z_">The impedance in circuit.</param>
    /// <returns>the average or rms current Irms -> (A)</returns>
    static ld rmsCurrent_AC(ld Vrms, ld Z);

    /// <summary>
    /// Calculates the RMS(root mean square current or average current in a AC
    /// series circuit.
    /// </summary>
    /// <param name="Vrms">The root mean square voltage or Vrms.</param>
    /// <param name="R">The resistance.</param>
    /// <param name="_xl">The inductive reactance.</param>
    /// <param name="_xc">The conductive reactance.</param>
    /// <returns>Irms or root mean square current, average current(A)</returns>
    static ld rmsCurrent_AC(ld Vrms, ld R, ld _xl, ld _xc);

    /// <summary>
    /// Calculates the RMS(root mean square current or average current in a AC
    /// series circuit.
    /// </summary>
    /// <param name="Vrms">The root mean square voltage or Vrms.</param>
    /// <param name="R">The resistance.</param>
    /// <param name="L">The inductance.</param>
    /// <param name="C">The capacitance.</param>
    /// <param name="f">The frequency.</param>
    /// <returns>Irms or root mean square current, average current(A)</returns>
    static ld rmsCurrent_AC(ld Vrms, ld R, ld L, ld C, ld f);

    /// <summary>
    /// Calculates the Impedance in a RLC series AC circuit. For circuits without
    /// a resistor take R=0, for those without and inductor take _xl = 0, for
    /// those without a capacitor take _xc = 0.
    /// </summary>
    /// <param name="R">The resistance.</param>
    /// <param name="_xl">The inductive reactance.</param>
    /// <param name="_xc">The capacitive reactance.</param>
    /// <returns>the impedance on an AC circuit (Ohms)</returns>
    static ld impedance(ld R, ld _xl, ld _xc);

    /// <summary>
    /// Calculates the impedance in a RLC series AS circuit.
    /// </summary>
    /// <param name="R">The resistance.</param>
    /// <param name="L">The inductance.</param>
    /// <param name="C">The capacitance.</param>
    /// <param name="f">The frequency.</param>
    /// <returns>the impedance on an AC circuit (Ohms)</returns>
    static ld impedance(ld R, ld L, ld C, ld f);

    /// <summary>
    /// Calculates the resonant frequency in an RLC series AC circuit
    /// </summary>
    /// <param name="L">The inductance.</param>
    /// <param name="C">The capacitance.</param>
    /// <returns>resonant frequency (Hz)</returns>
    static ld resonantFrequency(ld L, ld C);

    /// <summary>
    /// Calculates the power factor. cos(phi) = R/Z_.
    /// </summary>
    /// <param name="R">The resistance.</param>
    /// <param name="Z_">The impedance.</param>
    /// <returns>power factor(unit-less)</returns>
    static ld powerFactor(ld R, ld Z);

    /// <summary>
    /// Phases the angle.
    /// </summary>
    /// <param name="pf">The pf.</param>
    /// <returns>phase angle</returns>
    static ld phaseAngle(ld pf);

    /// <summary>
    /// Phases the angle.
    /// </summary>
    /// <param name="R">The resistance.</param>
    /// <param name="Z_">The impedance.</param>
    /// <returns>phase angle</returns>
    static ld phaseAngle(ld R, ld Z);

    /// <summary>
    /// Powers the average RLC.
    /// </summary>
    /// <param name="Irms">The average current .</param>
    /// <param name="Vrms">The average voltage.</param>
    /// <param name="pf">The power factor.</param>
    /// <returns>power in an RLC series AC circuit</returns>
    static ld powerAvgRLC(ld Irms, ld Vrms, ld pf);

    /// <summary>
    /// Calculates the peak emf  generated by a r(m) radius, N-turn
    /// coil that is rotated one-fourth of a revolution in t(s), originally
    /// having its plane perpendicular to a uniform B(T) magnetic field?
    /// (This is 58 rev/s.)
    /// </summary>
    /// <param name="r">The radius.</param>
    /// <param name="N">The number of turns in coil.</param>
    /// <param name="t">The time in seconds.</param>
    /// <param name="B">The magnetic field strength.</param>
    /// <returns>peek emf</returns>
    static ld emfPeek(ld r, ld N, ld t, ld B);


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

inline ld ElectroMagneticInduction::magneticFlux(const ld B, const ld A, const ld theta = 0)
{
    return B * A * cos(theta * constants::RADIAN);//T*m^2 = Tesla meters squared
}

inline ld ElectroMagneticInduction::emfFaradyFullEquation(const ld N, const ld r, const ld B, const ld t, const ld thetaS, const ld thetaF)
{
    const ld area = constants::PI * (r * r);
    const ld deltaTheta = cos(thetaF * constants::RADIAN) - cos(thetaS * constants::RADIAN);
    const ld flux = area * B * deltaTheta;
    return  -N * (flux / t);
}

inline ld ElectroMagneticInduction::emfMagnitude_FaradayNoMinus(const ld N, const ld r, const ld B1, const ld B2, const ld t, const ld theta)
{
    const ld area = constants::PI * (r * r);
    const ld deltaB = abs(B2 - B1);
    const ld deltaFlux = area * deltaB * cos(theta*constants::RADIAN);

    return N * (deltaFlux / t);//V
}

inline ld ElectroMagneticInduction::deltaFlux(const ld A, const ld deltaB)
{

    return A * deltaB;
}

inline ld ElectroMagneticInduction::emf_inducedInGeneratorCoil(const ld N, const ld l, const ld w, const ld aW, const ld B, const ld t)
{
    const ld area = l * w;

    return N * area * B * aW * sin((aW * t) * constants::RADIAN);//V
}

inline ld ElectroMagneticInduction::emf_peek(const ld N, const ld A, const ld B, const ld aW)
{
    return N * A * B * aW;//V
}

inline ld ElectroMagneticInduction::emf_peek(const ld N, const ld r, const ld B, const ld rad, const ld t)
{
    const ld area = constants::PI * (r * r);
    const ld aW = rad / t;
    return N * area * B * aW;//V
}

inline ld ElectroMagneticInduction::emfPeek_r(const ld N, const ld r, const ld B, const ld aW)
{
    return N * constants::PI * (r * r) * B * aW;
}

inline ld ElectroMagneticInduction::emf_peekFromDiameterAndRPMs(const ld N, const ld d, const ld B, const ld rpm)
{
    const ld aW = (rpm * 2.0 * constants::PI) / 60.0;//angular velocity
    const ld A = (constants::PI * (d * d)) / 4;//cross-sectional
    return N * A * B * aW;//V
}

inline ld ElectroMagneticInduction::emf_inducedByMagneticFlux(const ld N, const ld f, const ld t)
{
    return -N * (f / t);//V
}

inline ld ElectroMagneticInduction::emf_avgOnCoil(const ld B, const ld d, const ld t)
{
    return (constants::PI * B * (d * d)) / (4.0 * t);//V
}

inline ld ElectroMagneticInduction::n_turnsInCoilFromEMFEquation(const ld t, const ld emf, const ld f)
{
    return (t / f) * emf;//turns in coil
}

inline ld ElectroMagneticInduction::flux_fromEMFEquation(const ld emf, const ld t, const ld N)
{
    return -(t * emf) / N;//T*m^2
}

inline ld ElectroMagneticInduction::time_fromEMFEquation(const ld N, const ld f, const ld emf)
{
    return N * (f / emf);//seconds
}

inline ld ElectroMagneticInduction::motionalEMF(const ld B, const ld l, const ld x, const ld t)
{
    return B * ((l * x) / t);//V
}

inline ld ElectroMagneticInduction::motionalEMF(const ld B, const ld l, const ld v)
{
    return B * l * v;//V
}

inline ld ElectroMagneticInduction::lengthOfRod_emfEq(const ld V, const ld B, const ld v)
{
    return V / (B * v);//m
}

inline ld ElectroMagneticInduction::velocityOfMotion_emfEq(const ld V, const ld B, const ld l)
{
    return V / (B * l);// m/s
}

inline ld ElectroMagneticInduction::magneticFieldFrom_emfEq(const ld V, const ld l, const ld v)
{
    return V / (l * v);//T
}

inline ld ElectroMagneticInduction::magneticFieldMagnitude(const ld flux, const ld Ard, const ld theta = 0, const ld mode = 'A')
{
    ld area;
    if (mode == 'a' || mode == 'A')
    {
        return flux/(Ard*cos(theta*constants::RADIAN));//(T)
    }
    else if (mode == 'r' || mode == 'R')
    {
        area = constants::PI * (Ard * Ard);
        return flux/(area*cos(theta*constants::RADIAN));//(T)
    }
    else
    {
        area = constants::PI * ((Ard * Ard) / 4.0);
        return flux/(area*cos(theta*constants::RADIAN));//(T)
    }
}

inline ld ElectroMagneticInduction::transformerEquations_VN(const ld Vs, const ld Vp, const ld Ns, const ld Np, std::string mode)
{
    if (mode == "Vs" || mode == "vs" || mode == "VS" || mode == "vS")
    {
        return (Ns / Np) * Vp;//voltage secondary
    }
    else if (mode == "Vp" || mode == "vp" || mode == "VP" || mode == "vP")
    {
        return (Np / Ns) * Vs;//voltage primary
    }
    else if (mode == "Ns" || mode == "ns" || mode == "NS" || mode == "nS")
    {
        return (Vs / Vp) * Np;//number of loops secondary
    }
    else if (mode == "Np" || mode == "np" || mode == "NP" || mode == "nP")
    {
        return (Vp / Vs) * Ns;//number of loops primary
    }
    else
        return -111111111111;//error

}

inline ld ElectroMagneticInduction::transformerEquations_VI(const ld Vs, const ld Vp, const ld Is, const ld Ip, std::string mode)
{
    if (mode == "Vs" || mode == "vs" || mode == "VS" || mode == "vS")
    {
        return (Ip / Is) * Vp;//voltage secondary
    }
    else if (mode == "Vp" || mode == "vp" || mode == "VP" || mode == "vP")
    {
        return (Is / Ip) * Vs;//voltage primary
    }
    else if (mode == "Is" || mode == "is" || mode == "IS" || mode == "iS")
    {
        return (Vp / Vs) * Ip;//current secondary
    }
    else if (mode == "Ip" || mode == "ip" || mode == "IP" || mode == "iP")
    {
        return (Vs / Vp) * Is;//current primary
    }
    else
        return -111111111111;//error
}

inline ld ElectroMagneticInduction::transformerEquations_IN(const ld Is, const ld Ip, const ld Ns, const ld Np, std::string mode)
{
    if (mode == "Is" || mode == "is" || mode == "IS" || mode == "iS")
    {
        return (Np / Ns) * Ip;//current secondary
    }
    else if (mode == "Ip" || mode == "ip" || mode == "IP" || mode == "iP")
    {
        return (Ns / Np) * Is;//current primary
    }
    else if (mode == "Ns" || mode == "ns" || mode == "NS" || mode == "nS")
    {
        return (Ip / Is) * Np;//number of loops secondary
    }
    else if (mode == "Np" || mode == "np" || mode == "NP" || mode == "nP")
    {
        return (Ns / Np) * Is;//number of loops primary
    }
    else
        return -111111111111;//error
}

inline ld ElectroMagneticInduction::frequency(const ld aW)
{
    return aW/(2.0 * constants::PI);//Hz
}

inline ld ElectroMagneticInduction::period(const ld f)
{
    return 1 / f;//s
}

inline ld ElectroMagneticInduction::currentInCoil(const ld emf, const ld R)
{
    return emf/R;//A
}

inline ld ElectroMagneticInduction::emf_byMutualInductance(const ld M, const ld I, const ld t)
{
    return -M * (I / t);//V
}

inline ld ElectroMagneticInduction::mutualInductance(const ld emf, const ld I, const ld t)
{
    return -emf * (t / I);//henry(H) = (V*s)/A = Ohm*s
}

inline ld ElectroMagneticInduction::emf_bySelfInductance(const ld L, const ld I, const ld t)
{
    return -L * (I / t);//V
}

inline ld ElectroMagneticInduction::selfInductance(const ld emf, const ld I, const ld t)
{
    return -emf * (t / I);//henry(H)= (V*s)/A = Ohm*s
}

inline ld ElectroMagneticInduction::selfInductance_N(const ld N, const ld B, const ld I)
{
    return N * (B / I);//(H)
}

inline ld ElectroMagneticInduction::selfInductance_timeConstant(const ld toa, const ld R)
{
    return toa * R;//H
}

inline ld ElectroMagneticInduction::inductanceSolenoid_L(const ld N, const ld Ard, const ld l, char mode = 'a')
{
    ld area;
    if (mode == 'a' || mode == 'A')
    {
        return (constants::mu0 * (N * N) * Ard) / l;//(H)
    }
    else if	(mode == 'r' || mode == 'R')
    {
        area = constants::PI * (Ard * Ard);
        return (constants::mu0 * (N * N) * area) / l;//(H)
    }
    else
    {
        area = constants::PI * ((Ard * Ard) / 4.0);
        return (constants::mu0 * (N * N) * area) / l;//(H)
    }
}

inline ld ElectroMagneticInduction::inductanceFromEnergyStored(const ld E, const ld I)
{
    return (2.0 * E) / (I * I);//H = Ohm *s
}

inline ld ElectroMagneticInduction::energyStoredInInductor(const ld L, const ld I)
{
    return (1.0 / 2.0) * L * (I * I);//J
}

inline ld ElectroMagneticInduction::timeOnOffToinduceCurrent(const ld I, const ld L, const ld emf)
{
    return L * (I / emf);//seconds
}

inline ld ElectroMagneticInduction::currentSystemOnRails(const ld B, const ld l, const ld v, const ld A, const ld p, const ld R, const ld t)
{
    return (B * l * v * A) / (p * (2.0 * v * t + l) + R*A);//A
}

inline ld ElectroMagneticInduction::characteristicTimeConstant(const ld L, const ld R)
{
    return L/R;//s
}

inline ld ElectroMagneticInduction::inductance_reactance_XL(const ld f, const ld L)
{
    return 2.0 * constants::PI * f * L;
}

inline ld ElectroMagneticInduction::capacitive_reactance_XC(const ld f, const ld C)
{
    return 1.0 / (2.0 * constants::PI * f * C);//ohms
}

inline ld ElectroMagneticInduction::capacitanceFromReactance(const ld f, const ld _xc)
{
    return 1.0 / (2.0 * constants::PI * f * _xc);//F
}

inline ld ElectroMagneticInduction::current_RLCircuit_switchON(const ld Io, const ld t, const ld cTc)
{
    return Io * (1.0 - exp(-t / cTc));//A
}

inline ld ElectroMagneticInduction::current_RICircuit_switchOFF(const ld Io, const ld t, const ld cTc)
{
    return Io * exp(-t / cTc);//A
}

inline ld ElectroMagneticInduction::currentRMS_throughInductor(const ld Vrms, const ld _xl)
{
    return Vrms / _xl;//A
}

inline ld ElectroMagneticInduction::currentRMS_throughCapacitor(const ld Vrms, const ld _xc)
{
    return Vrms / _xc;//A
}

inline ld ElectroMagneticInduction::peekCurrent_AC(const ld Vo, const ld Z)
{
    return Vo / Z;//A
}

inline ld ElectroMagneticInduction::rmsCurrent_AC(const ld Vrms, const ld Z)
{
    return Vrms / Z;//A
}

inline ld ElectroMagneticInduction::rmsCurrent_AC(const ld Vrms, const ld R, const ld _xl, const ld _xc)
{
    const ld imp = impedance(R, _xl, _xc);
    return Vrms/imp;
}

inline ld ElectroMagneticInduction::rmsCurrent_AC(const ld Vrms, const ld R, const ld L, const ld C, const ld f)
{
    const ld XL = inductance_reactance_XL(f, L);
    const ld XC = capacitive_reactance_XC(f, C);
    const ld Z = sqrt((R * R) + pow((XL - XC), 2));
    return Vrms / Z;
}

inline ld ElectroMagneticInduction::impedance(const ld R, const ld _xl, const ld _xc)
{
    return sqrt((R * R) + pow((_xl - _xc), 2));//Ohms
}

inline ld ElectroMagneticInduction::impedance(const ld R, const ld L, const ld C, const ld f)
{
    const ld XL = inductance_reactance_XL(f, L);
    const ld XC = capacitive_reactance_XC(f, C);
    return sqrt((R * R) + pow((XL - XC), 2));
}

inline ld ElectroMagneticInduction::resonantFrequency(const ld L, const ld C)
{
    return 1.0 / (20 * constants::PI * sqrt(L * C));//Hz
}

inline ld ElectroMagneticInduction::powerFactor(const ld R, const ld Z)
{
    return R / Z;
}

inline ld ElectroMagneticInduction::phaseAngle(const ld pf)
{
    return acos(pf);
}

inline ld ElectroMagneticInduction::phaseAngle(const ld R, const ld Z)
{
    const ld pf = powerFactor(R, Z);
    return acos(pf);
}

inline ld ElectroMagneticInduction::powerAvgRLC(const ld Irms, const ld Vrms, const ld pf)
{
    return Irms * Vrms * pf;//Watts
}

inline ld ElectroMagneticInduction::emfPeek(const ld r, const ld N, const ld t, const ld B)
{
    return ((constants::PI * constants::PI) * N * (r * r) * B) / (2.0 * t);//peek emf (Vo)
}


