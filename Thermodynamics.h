//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_THERMODYNAMICS_H
#define PHYSICSFORMULA_THERMODYNAMICS_H
/**
 * @class Thermodynamics
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @date   12/6/2020
 */
constexpr auto _ATM_TO_PASCAL_MULTIPLIER_ = 101325;
static int thermodynamics_objectCount = 0;

double static kiloJoulesToCalories(const double kJ)
{
    return (kJ * 1000.0) / 4186.0;
}
static double Eff(const double W, const double Qh)
{
    return W / Qh;
}

#include "Heat.h"
#include "Energy.h"

class Thermodynamics :
        public Energy, public Heat
{
private:
    static void countIncrease() { thermodynamics_objectCount += 1; }
    static void countDecrease() { thermodynamics_objectCount -= 1; }
public:
    Thermodynamics* _thermodynamicPtr;

    /**
     * @brief  no argument constructor
     */
    Thermodynamics()
    {
        set_celsius(0.0);
        _thermodynamicPtr = nullptr;
    }//end no argument constructor
    /**
     * @brief copy constructor
     */
    Thermodynamics(const Thermodynamics& t)
            : Heat(t)
    {

        T._celsius = t.T._celsius;
        T._fahrenheit = t.T._fahrenheit;
        T._kelvin = t.T._kelvin;
        _mode = t._mode;
        _tempPtr = t._tempPtr;

        _thermodynamicPtr = t._thermodynamicPtr;
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    Thermodynamics(Thermodynamics&& t) noexcept
    {
        T._fahrenheit = t.T._fahrenheit;
        T._celsius = t.T._celsius;
        T._kelvin = t.T._kelvin;
        this->_thermodynamicPtr = t._thermodynamicPtr;
        countIncrease();
    }
    /**
     * @brief copy assignment operator
     */
    Thermodynamics& operator=(const Thermodynamics& t)
    {
        if (this != &t)
        {
            T._celsius = t.T._celsius;
            T._fahrenheit = t.T._fahrenheit;
            T._kelvin = t.T._kelvin;
            _mode = t._mode;
            _tempPtr = t._tempPtr;
            countIncrease();
        }
        return *this;
    }

    static void show_thermodynamics_objectCount() { std::cout << "\nthermodynamic object count: " << thermodynamics_objectCount << std::endl; }
    static int get_thermodynamics_objectCount() { return thermodynamics_objectCount; }

    /**
     * @brief first law of thermodynamics  delta_U = Q - W
     * @param Q is the sum of all heat transfer into and out of the system
     * @param W is the sum of all work done on or by the system
     * @returns delta U, is the change in internal energy U of the system
     */
    static ld changeOfInternalEnergy(const ld Q, const ld W)
    {
        return Q - W;
    }

    /**
     * @brief first law of thermodynamics  delta_U = Q - W
     * @param Q_in is the sum of all heat transfer into a system
     * @param Q_out is the sum of all heat transfer out of a system
     * @param W is the sum of all work done by the system
     * @returns delta U, is the change in internal energy U of the system
     */
    static ld changeOfInternalEnergy(const ld Q_in, const ld Q_out, const ld W)
    {
        return Q_in - Q_out - W;
    }

    /**
     * @brief calculates the energy loss to environment
     */
    static ld energyLossToEnvironment(const ld Qin, const ld eff)
    {
        return Qin * (1.0 - (eff / 100));
    }

    /**
     * @brief calculates work done by a cyclical process system W = Qh - Qc
     * @param Qh heat transfer out of hot reservoirs
     * @param Qc heat transfer to the environment
     * @returns  work
     */
    static ld work_by_cyclical_system(const ld Qh, const ld Qc)
    {
        return  Qh - Qc;
    }

    /**
     * @brief calculates the work done using carnot efficiency and
     * @param cEff carnot efficiency Eff=1-Tc/Th
     * @param Qh heat transfer to source
     * @returns work in Joules
     */
    static ld work(const ld cEff, const ld Qh)
    {
        return cEff * Qh;
    }

    /**
     * @brief calculates a system of answers for the work done on a object, the total heat transfer
     * done in process and the increase of the internal energy
     * @param mass kg mass of object
     * @param Ti initial temp c
     * @param Tf final temp c
     * @param c specific heat of substance
     * @param density kg/m^3
     * @param coefLinExp coefficient of linear expansion
     * @param Patm atmospheric pressures in atmospheres(atm)s, default value of 1.0 atm(leave blank if no change needed)
     * @returns a vector with the Work done by object [0],
     * heat energy transferred during process[1], increase of internal energy of system[2]
     *
     */
    static vector<ld> systemOfAnswers_workDone_heatTransfer_internalChange(const ld mass, const ld Ti, const ld Tf, const ld c, const ld density, const ld coefLinExp, const ld Patm = 1.0)
    {

        const ld v0 = mass / density;
        const ld changeV = 3.0 * coefLinExp * v0 * (Tf - Ti);
        const ld W = Patm * _ATM_TO_PASCAL_MULTIPLIER_ * changeV; // a
        const ld Q = heatTransfer_Q(mass, c, Tf - Ti);
        const ld U = Q - W;
        vector<ld> results = { W, Q, U };
        return results;
    }

    /**
     * @brief calculates the food energy used in doing kJ worth of work at a certain eff%
     * @param W total work in kJ
     * @param eff efficiency of work done
     * @returns calories used
     */
    static ld caloriesUsed(const ld W, const ld eff)
    {
        return kiloJoulesToCalories(W / (eff / 100));
    }


    /**
     * @brief using first law of thermodynamics  Q = delta_U + W
     * @param delta_U is te change of internal energy while doing work
     * @param W is the sum of all work done on or by the system
     * @returns delta U, is the change in internal energy U of the system
     */
    static ld heatTransferToSystem(const ld delta_U, const ld W)
    {
        return delta_U + W;
    }

    /**
     * @brief calculates the heat transfer to an environment when the efficiency and work is known
     * @param W work done
     * @param eff efficiency rating
     * @returns the total heat transfer to environment, usually as heat loss
     */
    static ld heatTransferToEnvironment(const ld W, const ld eff)
    {
        return ((1.0 / (eff/100.0)) - 1.0) * W;
    }

    /**
     * @brief calculates the amount fuel something needed to do something N = Qh / Qf, Qh = Qc + W
     * @param Qc is the heatTransfer to the cold reservoir
     * @param W is the work done on a system
     * @param Qf is the total heat transfer produced by the fuel used, varies and is usually given or can be looked up
     * in tables
     * @returns the total resources needed
     */
    static ld resourcesNeededToDoWork(const ld Qc, const ld W, const ld Qf)
    {
        return (Qc + W) / Qf;
    }

    /**
     * @brief calculates the average metobolic rate in watts from metabolized food energy
     * over a period of time in seconds
     * @param kJFoodEnergy energy from food intake
     * @param timeHours hours of work done
     * @return watts
     */
    static ld metabolicRate(const ld kJFoodEnergy, const ld timeHours)
    {
        return  (kJFoodEnergy * pow(10, 3)) / (timeHours * 3600.0);
    }

    /**
     * @brief calculates how long the energy will last in a consumed food while
     * doing steady work in watts at an eff %
     * @param var either calories(default) or kiloJoules. must use a mode of 'k' if using kJ
     * @param watts work rate of person
     * @param eff efficiency rate
     * @param mode is 'c' for Calorie mode, use 'k' for kiloJoules input instead
     * @param timeSetting 'm' for minutes 's' of seconds and 'h' for hours 'd' for days
     * @returns how long energy from calories will last
     */
    static ld energyDuration(const ld var, const ld watts, const ld eff, const char mode = 'c', const char timeSetting = 'm')
    {
        if (mode == 'c')
        {
            if (timeSetting == 's')
            {
                return ((var * 4.184) * 1000.0 * (eff / 100.0)) / watts;
            }
            if (timeSetting == 'h')
            {
                return (((var * 4.184) * 1000.0 * (eff / 100.0)) / watts) / 3600.0;
            }
            if (timeSetting == 'm')
            {
                return (((var * 4.184) * 1000.0 * (eff / 100.0)) / watts) / 60.0;
            }
            if (timeSetting == 'd')
            {
                return (((var * 4.184) * 1000.0 * (eff / 100.0)) / watts) / 86400.0;
            }
        }

        if (timeSetting == 's')
        {
            return (var * 1000.0 * (eff / 100.0)) / watts;
        }
        if (timeSetting == 'h')
        {
            return ((var * 1000.0 * (eff / 100.0)) / watts) / 3600.0;
        }
        if (timeSetting == 'm')
        {
            return ((var * 1000.0 * (eff / 100.0)) / watts) / 60.0;
        }
        if (timeSetting == 'd')
        {
            return ((var * 1000.0 * (eff / 100.0)) / watts) / 86400.0;
        }
        return (var * 1000.0 * (eff / 100.0)) / watts;
    }

    /**
     * @brief calculates the carnot efficiency of a process
     * @param Tc absolute temp of cold reservoirs
     * @param Th absolute temp of hot reservoirs
     * @returns Carnot Efficiency
     */
    static ld carnotEfficiency(const ld Tc, const ld Th)
    {
        return 1.0 - (Tc / Th);
    }

    /**
     * @brief calculates the energy efficiency rating of a system (EER)
     * @param Qc amount of heat transfer from a cold environment in BTU's(British thermal units)
     * @param t1 time in hours
     * @param W work input in Joules
     * @param t2 time in seconds
     * @returns the EEF of a product such as a AC or Refrigerator
     */
    static ld energyEfficiencyRating(const ld Qc,const ld t1,  const ld W, const ld t2)
    {
        return (Qc / t1) / (W / t2);
    }

    /**
     * @brief calculates the change in entropy for a reversible process {(S)rev}
     * (S)rev = Q/T
     * @param Q is the heat transfer necessary to change forms of an object
     * @param T is the temperature it takes in kelvin to change an objects forms
     * @returns entropy
     */
    static ld entropy_ChangeIn(const ld Q, const ld T)
    {
        return Q / T;
    }

    /**
     * @brief  calculates the difference of internal pressure if it was at zero gauge pressure
     * @param atmP atm or pascals for pressure
     * @param v liters default use 'm' for meters cubed as a volume
     * @param mode default 'l' for liters 'm' is meters cubed as a volume measurement
     * @returns the difference the internal energy would need to be
     */
    static ld differenceOfGaugePressureToZeroGaugePressure(const ld atmP, const ld v, const char mode = 'l')
    {
        if (mode == 'l')
        {
            const double U2 = 1.5 * (101325.0) * (v / 1000.0);
            cout << "u2: " << U2 << endl;
            const double U1 = ((1.0 + atmP) / (1.0)) * U2;
            cout << "u1: " << U1 << endl;
            return U1 - U2;
        }
        else {
            const double U2 = 1.5 * (101325.0) * (v);
            cout << "u2: " << U2 << endl;
            const double U1 = ((atmP) / (101325.0)) * U2;
            return U1 - U2;
        }
    }

    /**
     * @brief calculates the hot reservoir of a carnot engine
     * @param eff efficiency %
     * @param coldResTempCelsius
     * @returns the temp in celsius of the Hot Reservoir
     */
    static ld carnotEngineHotReservoir(const ld eff, const ld coldResTempCelsius)
    {
        return tempConverter.kelvin_to_celsius(tempConverter.celsius_to_kelvin(coldResTempCelsius) / (1.0 - (eff/100.0)));
    }

    /**
     * @brief calculates the coefficient of performance
     */
    static ld coefficientOfPerformance(const ld Tc, const ld Th)
    {
        return tempConverter.celsius_to_kelvin(1);
    }

    /**
     * @brief calculates the cold reservoir of a carnot engine
     * @param eff efficiency %
     * @param hotResTempCelsius
     * @returns the temp in celsius of the Hot Reservoir
     */
    static ld carnotEngineColdReservoir(const ld eff, const ld hotResTempCelsius)
    {
        return tempConverter.kelvin_to_celsius((1.0 - (eff / 100.0))*tempConverter.celsius_to_kelvin(hotResTempCelsius));
    }

    /**
     * @brief calculates the chance in volume with a constant pressure is maintained
     * @param kPa pressure in kilo pascals
     * @param Qin total work ii
     */
    static ld changeInVolumeConstantPressure(const ld kPa, const ld Qin, const ld Qchange)
    {
        return (Qin - Qchange) / kPa;
    }

    /**
     * @brief monoatomic ideal gas internal energy change
     */
    static ld monoatomicInternalEnergyChange(const ld Vi, const ld Vf, const ld pressureConstant)
    {
        return (pressureConstant * (Vf - Vi)) / (ATOMIC_MASS_UNIT_ - 1);
    }
    /**
     * @brief calculates the work done during an isobaric process
     * @param gP gauge pressure supplied
     * @param A cross sectional area of piston head A = pi*radius^2
     * @param d is the distance it travels
     * @returns work in J
     */
    static ld work_isobaricProcessOnPiston(const ld gP, const ld A, const ld d)
    {
        return gP * A * d;
    }

    /**
     * @brief destructor
     */
    ~Thermodynamics()
    {
        delete _thermodynamicPtr;
    }//end destructor
};
#endif //PHYSICSFORMULA_THERMODYNAMICS_H
