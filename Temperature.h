//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_TEMPERATURE_H
#define PHYSICSFORMULA_TEMPERATURE_H
/**
 * @class Temperature
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @date   11/23/2020
 ____________________________________________________________________________*/
#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include <iostream>
#include "Constants.h"
using namespace std;

///**
// * @brief Global Constant _K_ is the Boltzmann constant
// * .0000000000000000000000138 J/K
// */
//constexpr auto BOLTZMANN_K_ = 1.38e-23;//1.38e-23

//[[maybe_unused]] constexpr auto ATOMIC_MASS_UNIT_ = 1.66e-27; //1.6605e-27 (u)

/**
 * @brief Global Constant _Na_ is  Avogadro's number and is used to express
 * units in moles, abb(mol) and is equal to 6.02e23 mol^-1
 */
//constexpr auto AVOGADRO_ = 6.02e23;//6.02*10^23

static struct TemperatureConversions
{
    static ld  celsius_to_fahrenheit(const ld c) { return (9.0 / 5.0) * c + 32.0; }
    static ld  fahrenheit_to_celsius(const ld f) { return (5.0 / 9.0) * (f - 32.0); }
    static ld  celsius_to_kelvin(const ld c) { return c + 273.15; }
    static ld  kelvin_to_celsius(const ld k) { return k - 273.15; }
    static ld  fahrenheit_to_kelvin(const ld f) { return (5.0 / 9.0) * (f - 32) + 273.15; }
    static ld  kelvin_to_fahrenheit(const ld k) { return (9.0 / 5.0) * (k - 273.15) + 32.0; }
    static ld  celsius_to_rankine(const ld c) { return c + 273.15; }
    static ld  rankine_to_celsius(const ld r) { return r - 273.15; }
    static ld  fahrenheit_to_rankine(const ld f) { return (5.0 / 9.0) * (f - 32) + 491.67; }
    static ld  rankine_to_fahrenheit(const ld r) { return (9.0 / 5.0) * (r - 491.67) + 32.0; }
    static ld  kelvin_to_rankine(const ld k) { return k * 1.8; }
    static ld  rankine_to_kelvin(const ld r) { return r / 1.8; }
}tempConverter;

/**
	 * @brief structure of thermal expansion coefficients, each is a std::vector  of two
	 * and is followed by a capitol letter of either a S for solid a L for liquid or
	 * a G for gases, only solids have std::vectors with two values the others are ld's here is an example:
	 * aluminum_S[0] = coefficient of linear expansion // holds the value 25*10^-6
	 * aluminum_S[1] = coefficient of volume expansion //holds the value 75*10^-6
	 * of ether_L = coefficient of volume expansion // holds the value of 1650*10^-6
	 */
static struct ThermalExpansionCoefficients
{
    ThermalExpansionCoefficients() {}
    const struct ALUMINUM_SOLID {
        const ld linear = 25e-6;
        const ld volume = 75e-6;
    } aluminum_S;
    const struct BRASS_SOLID {
        const ld linear = 19e-6;
        const ld volume = 56e-6;
    } brass_S;
    const struct COPPER_SOLID {
        const ld linear = 17e-6;
        const ld volume = 51e-6;
    } copper_S;
    const struct GOLD_SOLID {
        const ld linear = 14e-6;
        const ld volume = 42e-6;
    } gold_S;
    const struct IRON_OR_STEEL_SOLID {
        const ld linear = 12e-6;
        const ld volume = 35e-6;
    } iron_or_steel_S;
    const struct INVAR_NICKEL_IRON_ALLOW_SOLID {
        const ld linear = 0.9e-6;
        const ld volume = 2.7e-6;
    } invar_nickel_iron_allow_S;
    const struct LEAD_SOLID {
        const ld linear = 29e-6;
        const ld volume = 87e-6;
    } lead_S;
    const struct SILVER_SOLID {
        const ld linear = 18e-6;
        const ld volume = 54e-6;
    } silver_S;
    const struct GLASS_ORDINARY_SOLID {
        const ld linear = 9e-6;
        const ld volume = 27e-6;
    } glass_ordinary_S;
    const struct GLASS_PYREX_SOLID {
        const ld linear = 3e-6;
        const ld volume = 9e-6;
    } glass_pyrex_S;
    const struct QUARTZ_SOLID {
        const ld linear = 0.4e-6;
        const ld volume = 1e-6;
    } quartz_S;
    const struct CONCRETE_BRICK_SOLID {
        const ld linear = 12e-6;
        const ld volume = 36e-6;
    } concrete_brick_S;
    const struct MARBLE_SOLID {
        const ld linear = 7e-6;
        const ld volume = 2.1e-6;
    } marble_S;
    const struct ETHER_LIQUID {
        const ld volume = 1650e-6;
    } ether_L;
    const struct ETHYL_ALCOHOL {
        const ld volume = 1100e-6;
    } ethyl_alcohol;
    const struct PETROL {
        const ld volume = 950e-6;
    } petrol;
    const struct GLCERIN {
        const ld volume = 500e-6;
    } glycerin;
    const struct MERCURY {
        const ld volume = 180e-6;
    } mercury;
    const struct WATER {
        const ld volume = 210e-6;
    } water;
    const struct AIR_AND_MOST_GASES_AT_ATMOSPHERIC_PRESSURE {
        const ld volume = 3400e-6;
    } air_and_most_gases_at_atmospheric_pressure;

}TEC;




static int temperature_objectCount = 0;

class Temperature
{
private:

    static void countIncrease() { temperature_objectCount += 1; }
    static void countDecrease() { temperature_objectCount -= 1; }
public:
    /**
     * @brief no argument constructor
     */
    Temperature()
    {
        T._celsius = 0.0;
        T._fahrenheit = 0.0;
        T._kelvin = 0.0;
        T._rankine = 0.0;
        _mode = 'f';
        countIncrease();
    }
    /**
     * @brief copy constructor
     */
    Temperature(const Temperature& t)
    {
        T._celsius = t.T._celsius;
        T._fahrenheit = t.T._fahrenheit;
        T._kelvin = t.T._kelvin;
        T._rankine = t.T._rankine;
        _mode = t._mode;
        countIncrease();
    }
    /**
     * @brief copy assignment operator
     */
    Temperature& operator=(const Temperature& t)
    {
        if (this != &t)
        {
            T._celsius = t.T._celsius;
            T._fahrenheit = t.T._fahrenheit;
            T._kelvin = t.T._kelvin;
            T._rankine = t.T._rankine;
            _mode = t._mode;
            countIncrease();
        }
        return *this;
    }

    /**
     * #brief move constructor
     */
    Temperature(Temperature&& t) noexcept : _mode(t._mode)
    {
        T._fahrenheit = t.T._fahrenheit;
        T._celsius = t.T._celsius;
        T._kelvin = t.T._kelvin;
        T._rankine = t.T._rankine;
        countIncrease();
    }

    static void show_temperature_objectCount() { std::cout << "\ntemperature object count: " << temperature_objectCount << std::endl; }
    static int get_temperature_objectCount() { return temperature_objectCount; }

    struct Temp
    {
        ld _celsius;
        ld _fahrenheit;
        ld _kelvin;
        ld _rankine;
        string _mode;

        Temp()
        {
            _celsius = 0.0;
            _fahrenheit = 0.0;
            _kelvin = 0.0;
            _rankine = 0.0;
        }

        Temp(ld temp, string& mode)
        {
            // turn mode all lowercase
            std::transform(mode.begin(), mode.end(), mode.begin(), ::tolower);
            if (mode == "c" || "celsius"  )
            {
                _celsius = temp;
                _fahrenheit = temp * 9 / 5 + 32;
                _kelvin = temp + 273.15;
            }
            else if (mode == "f" || "fahrenheit")
            {
                _fahrenheit = temp;
                _celsius = (temp - 32) * 5 / 9;
                _kelvin = (_celsius + 273.15) * 5 / 9;
            }
            else if (mode == "k" || "kelvin")
            {
                _kelvin = temp;
                _celsius = temp - 273.15;
                _fahrenheit = _celsius * 9 / 5 + 32;
            }
            else if (mode == "r"|| "rankine")
            {
                _rankine = temp;
                _celsius = (temp - 491.67) * 5 / 9;
                _fahrenheit = temp - 459.67;
                _kelvin = temp * 5 / 9;
            }
            else
            {
                std::cout << "invalid mode" << std::endl;
            }
        }

        /**
         * @brief method to set the fahrenheit instance variable. will update other
         * instance variables to reflect.
         * @param f is the temp in fahrenheit
         */
        void set_fahrenheit(const ld f)
        {
            _fahrenheit = f;
            _celsius = TemperatureConversions::fahrenheit_to_celsius(_fahrenheit);
            _kelvin = TemperatureConversions::fahrenheit_to_kelvin(_fahrenheit);
            _rankine = TemperatureConversions::fahrenheit_to_rankine(_fahrenheit);
        }
        /**
        * @brief method to set the celsius instance variable. will update other
        * instance variables to reflect.
        * @param c is the temp in celsius
        */
        void set_celsius(const ld c)
        {
            _celsius = c;
            _fahrenheit = TemperatureConversions::celsius_to_fahrenheit(_celsius);
            _kelvin = TemperatureConversions::celsius_to_kelvin(_celsius);
            _rankine = TemperatureConversions::celsius_to_rankine(_celsius);
        }
        /**
        * @brief method to set the kelvin instance variable. will update other
        * instance variables to reflect.
        * @param k is the temp in kelvin
        */
        void set_kelvin(const ld k)
        {
            _kelvin = k;
            _celsius = TemperatureConversions::kelvin_to_celsius(_kelvin);
            _fahrenheit = TemperatureConversions::kelvin_to_fahrenheit(_kelvin);
            _rankine = TemperatureConversions::kelvin_to_rankine(_kelvin);
        }

        /**
         * @brief method to set the rankine instance variable. will update other
         * instance variables to reflect.
         * @param r is the temp in rankine
         */
        void set_rankine(const ld r)
        {
            _rankine = r;
            _celsius = TemperatureConversions::rankine_to_celsius(_rankine);
            _fahrenheit = TemperatureConversions::rankine_to_fahrenheit(_rankine);
            _kelvin = TemperatureConversions::rankine_to_kelvin(_rankine);
        }
    }T;


    /**
     * @brief char variable when set will change the default of the constructor arguments being
     * passed in
     * 'c' = celsius
     * 'f' = fahrenheit
     * 'k' = kelvin
     * 'r' = rankine
     */
    char _mode;

    /**
     * @brief method to set the mode to either f or fahrenheit, c for celsius or k for kelvin
     * @param mode is a char of the mode either 'f','c','k', 'r'. be sure to
     * include single quotes
     * if its a literal being passed
     */
    void set_mode(char mode)
    {
        if(mode == 'c' || mode == 'f' || mode == 'k' || mode == 'r')
        {
            _mode = mode;
        }
        else
        {
            do
            {
                std::cout << "You entered a wrong mode please re-enter a single c, f, or k\n>>";
                std::cin >> mode;
            }
            while (mode != 'c' && mode != 'f' && mode != 'k');
        }

    }
    /**
     * @brief method to set the fahrenheit instance variable. will update other
     * instance variables to reflect.
     * @param f is the temp in fahrenheit
     */
    void set_fahrenheit(const ld f)
    {
        T.set_fahrenheit(f);
    }
    /**
 * @brief method to set the celsius instance variable. will update other
 * instance variables to reflect.
 * @param c is the temp in celsius
 */
    void set_celsius(const ld c)
    {
        T.set_celsius(c);
    }
    /**
    * @brief method to set the kelvin instance variable. will update other
    * instance variables to reflect.
    * @param k is the temp in kelvin
    */
    void set_kelvin(const ld k)
    {
        T.set_kelvin(k);
    }
    /**
     * @brief method to set the rankine instance variable. will update other
     * instance variables to reflect.
     * @param r is the temp in rankine
     */
    void set_rankine(const ld r)
    {
        T.set_rankine(r);
    }

    [[nodiscard]] ld getFahrenheit()const { return T._fahrenheit; }
    [[nodiscard]] ld getCelsius()const { return T._celsius; }
    [[nodiscard]] ld getKelvin()const { return T._kelvin; }
    [[nodiscard]] ld getRankine()const { return T._rankine; }

    void showFahrenheit()const { std::cout << "F: " << getFahrenheit() << std::endl; }
    void showCelsius()const { std::cout << "C: " << getCelsius() << std::endl; }
    void showKelvin()const { std::cout << "K: " << getKelvin() << std::endl; }
    void showRankine()const { std::cout << "R: " << getRankine() << std::endl; }
    void showAllTemps()const

    {
        showFahrenheit();
        showCelsius();
        showKelvin();
        showRankine();
    }



    /**
     * @brief converts from molecules to moles
     * @param N is the number of molecules
     * @returns the   mole^-1
     */
    ld static convert_to_mol(const ld N)
    {
        return N / constants::AVOGADRO;
    }

    /**
     * @brief calculates the linear thermal expansion of a object made of certain materials which, distance
     * we use the expansion coefficients with
     * @param a is the coefficient of 'linear expansion'
     * @param L is the length and the change of the thermal expansion is proportional to its length
     * @param tempChange is the change in temperature
     * @returns the total expansion in meters
     */
    static ld thermalExpansionLinear1D(const ld a, const ld L, const ld tempChange)
    {
        return a * L * tempChange;
    }

    /**
     * @brief calculates the thermal expansion in 2 dimensions, area
     * @param a is the coefficient of 'linear expansion'
     * @param areaChange is the change in the area
     * @param tempChange is the change in temperature
     * @returns the total thermal expansion of in area
     */
    static ld thermalExpansionArea2D(const ld a, const ld areaChange, const ld tempChange)
    {
        return a * areaChange * tempChange;
    }

    /**
     * @brief calculates the thermal expansion in 2 dimensions, area
     * @param av is the coefficient of 'volume expansion'
     * @param vChange is the change in the volume
     * @param tempChange is the change in temperature
     * @returns the total thermal expansion of a volume
     */
    static ld thermalExpansionVolume3D(const ld av, const ld vChange, const ld tempChange)
    {
        return av * vChange * tempChange;
    }

    /**
     * @brief calculates the final temperature needed for an object to reach a certain expansion as
     * described by the reworked linear thermal equation Tf = ((lRf -lRi)/(a * lRi)) + Ti.
     * @param a is the coefficient of 'linear expansion'
     * @param lRi is the initial length or radius of object at an initial temp
     * @param lRf is the final length or radius caused from thermal expansion
     * @param Ti is the initial temperature
     * @returns final temperature needed for a object to expand a certain amount
     */
    static ld tempFinalFromThermalExpansionLinear1D(const ld a, const ld lRi, const ld lRf, const ld Ti)
    {
        return ((lRf-lRi)/(a*lRi))+Ti;
    }

    /**
     * @brief coefficient of volume expansion
     * @param V_i is the initial volume of the object
     * @param V_f is the final volume of the object
     * @param Ti is the initial temperature of the object
     * @param Tf is the final temperature of the object
     * @returns the coefficient of volume expansion
     */
    static ld coefficientVolumeExpansion(const ld V_i,
                                         const ld V_f,
                                         const ld Ti,
                                         const ld Tf,
                                         bool print = false)
    {
        auto V_change = V_f - V_i;
        auto T_change = Tf - Ti;
        auto coeff_v_exp = (V_change / V_i) / (T_change);
        if (print)
            std::cout << "Coefficient of volume expansion: " << coeff_v_exp << std::endl;
        return coeff_v_exp;
    }
    /**
     * @brief A glass flask whose volume is 1000 cm3 at a temperature of 0.600
     * ∘C is completely filled with mercury at the same temperature. When the
     * flask and mercury are warmed together to a temperature of 52.0 ∘C ,
     * a volume of 8.10 cm3 of mercury overflows the flask
     * @param V_i  is the initial volume of the object
     * @param V_f  is the final volume of the object
     * @param Ti  is the initial temperature of the object
     * @param Tf  is the final temperature of the object
     * @param beta  is the coefficient of volume expansion of material in flask
     * @param print  is a boolean to print the result
     * @return  the coefficient of volume expansion
     */
    static ld coefficientVolumeExpansion(const ld V_i,
                                         const ld V_f,
                                         const ld Ti,
                                         const ld Tf,
                                         const ld beta,
                                         bool print = false)
    {
        auto V_change = V_f - V_i;
        auto T_change = Tf - Ti;
        auto coeff_v_exp = beta - (V_change / (V_i * T_change));
        if (print)
            std::cout << "Coefficient of volume expansion: " << coeff_v_exp << std::endl;
        return coeff_v_exp;
    }

    /**
     * @brief coefficient of linear expansion
     * @param L_i is the initial length of the object
     * @param L_f is the final length of the object
     * @param Ti is the initial temperature of the object
     * @param Tf is the final temperature of the object
     * @returns the coefficient of linear expansion
     */
    static ld coefficientLinearExpansion(const ld L_i,
                                         const ld L_f,
                                         const ld Ti,
                                         const ld Tf,
                                         bool print = false)
    {
        auto L_change = L_f - L_i;
        auto T_change = Tf - Ti;
        auto coeff_l_exp = (L_change / L_i) / (T_change);
        if (print)
            std::cout << "Coefficient of linear expansion: " << coeff_l_exp << std::endl;
        return coeff_l_exp;
    }

    static ld changeOfLengthFromLinearExpansion(const ld alpha,
                                                const ld Li,
                                                const ld Ti,
                                                const ld Tf,
                                                bool print = false)
    {
        auto T_change = Tf - Ti;
        auto L_change = alpha * Li * T_change;
        if (print)
            std::cout << "Change of length: " << L_change << std::endl;
        return L_change;
    }

    /**
     * @brief calculate the gas pressure in a tank
     * @param F is the total change in volume calculated previously
     * @param A is the total volume of tank
     * @param B is the bulk modulus
     * @returns the gas pressure in Pa
     */
    static ld gasPressure(const ld F, const ld A, const ld B, bool print = false)
    {
        ld P = ((F / A)-1) * B;
        if(print)
        {
            std::cout << "The gas pressure is: " << P << " Pa\n";
        }
        return P;
    }


    /**
     * @brief calculates pressure change due to temperature change in a system using the
     * ideal gas law PV=NkT which is algebraically reworked to solve for the final pressure
     * in the equation: Pf = Pi*(Tf/Ti)
     * @param Pi is the initial pressure in the system
     * @param Ti is the initial temp in kelvins
     * @param Tf is the final temp in kelvins
     * @returns the change in pressure due to temp
     */
    static ld pressureChangeFromTemperatureChange(const ld Pi, const ld Tf, const ld Ti)
    {
        return Pi * (Tf / Ti);
    }

    /**
     * @brief ideal gas law PV = NkT where reworked to solve for P
     * which is the absolute pressure of a gas: P = (NkT)/V, k = Boltzmann constant
     * @param V is the volume it occupies
     * @param N is the number of atoms and molecules in the gas
     * @param T is the absolute Temperature
     * @returns the absolute pressure
     */
    static ld absolutePressure_idealGasLaw(const ld V, const ld N, const ld T)
    {
        return (N * constants::STEFAN_BOLTZMANN * T) / V;
    }
    /**
     * @brief ideal gas law PV = NkT where reworked to solve for N
     * which is the number of atoms and molecules in the gas N = (PV)/(kT)
     * k = boltzmann constant
     * @param P is the absolute pressure of a gas
     * @param V is the volume it occupies
     * @param T is the absolute Temperature in kelvins
     * @returns the absolute pressure
     */
    static ld numberMolecules_idealGasLaw(const ld P, const ld V, const ld T)
    {
        return (P * V)/(constants::STEFAN_BOLTZMANN * T);
    }

    /**
     * @brief ideal gas law PV = nRT where reworked to solve for n
     * which is the number of atoms and moles in the gas n = (PV)/(RT)
     * R = Universal gas law constant set to default in joules
     * @param P is the absolute pressure of a gas
     * @param V is the volume it occupies
     * @param T is the absolute Temperature in kelvins
     * @param _R is the universal gas law constant default in J
     * @returns the absolute pressure
     */
    static ld numberMoles_idealGasLaw(const ld P,
                                      const ld V,
                                      const ld T,
                                      const ld _R = constants::R.joules)
    {
        return (P * V) / (_R * T);
    }

    /**
     * @brief ideal gas law PV = nRT where reworked to solve for V
     * which is the volume of a gas V = (nRT)/P
     * R = Universal gas law constant set to default in joules
     * @param n is the number of moles in the gas
     * @param P is the absolute pressure of a gas
     * @param T is the absolute Temperature in kelvins
     * @returns the volume of a gas
     */
    static ld volume_idealGasLaw(const ld n, const ld P, const ld T, bool print = false)
    {
        ld V = (n * constants::R.joules * T) / P;
        if(print)
            std::cout << "The volume of the gas is: " << V << " m^3\n";
        return V;
    }

    /**
     *  @brief calculates the temperature of a gas using the ideal gas law
     * @param n  is the number of moles in the gas
     * @param P  is the absolute pressure of a gas
     * @param V  is the volume of the gas
     * @param print  is a boolean to print the result
     * @return  the temperature of the gas
     */
    static ld temp_idelGasLaw(const ld n, const ld P, const ld V, bool print = false)
    {
        ld T = (P * V) / (n * constants::R.joules);
        if(print)
            std::cout << "The temperature of the gas is: " << T << " K\n";
        return T;
    }

    /**
     * @brief calculates the KE of a cloud or gas of N molecules
     * @param T is the absolute temperature in kelvin
     * @returns Thermal energy, molecular interpretation of temperature
     */
    static ld averageMolecularKineticEnergy(const ld T)
    {
        return (3.0 / 2.0) * constants::BOLTZMANN * T;
    }

    /**
     * @brief calculates the thermal speed of molecules at a certain temperature
     * @param m is the mass of a single molecule
     * @param T Temp K
     */
    static ld thermalSpeed(const ld m, const ld T)
    {
        return sqrt((3.0 * constants::BOLTZMANN * T) / m);
    }

    /**
     * @brief calculates the speed of a molecule wit specified energy
     * @param m is the mass of a single molecule
     * @param n is the number of atoms in the molecule
     * @param k is the molecular kinetic energy
     * @returns the speed of the molecule
     */
    static ld moleculeSpeed(const ld m,
                            const ld n,
                            const ld k,
                            bool print = false)
    {
        auto total_mass = m * n * constants::ATOMIC_MASS_UNIT;
        auto speed = sqrt((k * 2) / total_mass);
        if(print)
            std::cout << "The speed of the molecule is: " << speed << " m/s\n";
        return speed;
    }

    /**
     * @brief calculates the temperature in kelvin a molecule would need to be to reach a certain velocity
     * @param m is the mass of a molecule
     * @param v is the velocity in question
     * @returns the temp in kelvin needed for a molecule to reach a velocity
     */
    static ld temperatureOfMoleculeAtVelocity(const ld m, const ld v)
    {
        return (m * (v * v)) / (3.0 * constants::STEFAN_BOLTZMANN);
    }

    /**
     * @brief calculates the density of vapor
     */
    static ld vaporDensity(const ld p,
                           const ld m,
                           const ld T,
                           const ld R = constants::R.joules)
    {
        return (p * m) / (R * T);
    }

    /**
     * @calculates the humidity or dew point
     * @param vD is the calculated vapor density
     * @param svD is the saturation vapor density level
     * @returns humidity level as %
     */
    static ld humidityLevel(const ld vD, const ld svD)
    {
        return (vD / svD) * 100.0;
    }

    /**
     * @brief calculates the change in temperature
     */
    static ld temperatureChange(const ld startTemp, const ld finishTemp)
    {
        return abs(finishTemp - startTemp);
    }

    /**
     * @brief with w kg of water at a temp of t_i C. How many units of ice
     * at 0 C would be needed to cool the water to t_f C?
     * @param m_w is the amount of water in kg
     * @param t_i is the initial temp in C
     * @param t_f is the final temp in C
     *
     * @returns the amount of ice needed to cool the water to t_f C
     */
    static ld iceNeeded(const ld m_w, const ld t_water, const ld t_ice,
                        const ld t_final,  bool print = false)
    {
        auto c_w = SHC.waterLiquid.J_kgC;
        auto c_i = SHC.ice.J_kgC;
        auto lf = LF.water.J_kg;
        auto tfi = t_final - t_ice;
        auto tfw = t_final - t_water;
        auto ice = abs((m_w * c_w * tfw) / (c_i * tfi + lf));
        if(print)
            std::cout << "The amount of ice needed is: " << ice << " kg\n";
        return ice;
    }

    /**
     * @brief calculates the amount of ice in kg needed to cool a certain amount of water
     * @param m_w  is the mass of water in kg
     * @param c_w  is the specific heat of water in J/kgC
     * @param t_i  is the initial temp of the water in C
     * @param t_f  is the final temp of the water in C
     * @param c_i  is the specific heat of ice in J/kgC
     * @param t_i_i  is the initial temp of the ice in C
     * @param hf_water  is the heat of fusion of water in J/kg
     * @param print  is a boolean to print the result
     * @return  the amount of ice in kg needed to cool the water
     */
    static ld iceNeeded(const ld m_w,
                        const ld c_w,
                        const ld t_i,
                        const ld t_f,
                        const ld c_i,
                        const ld t_i_i,
                        const ld hf_water,
                        bool print = false)
    {
        auto mass_ice = (m_w * c_w * (t_i - t_f)) / (c_i * abs(t_i_i) +
                hf_water + c_w * t_f);
        if (print)
        {
            std::cout << "mass_ice = " << mass_ice << " kg" << std::endl;
        }
        return mass_ice;
    }

    /**
     * @brief calculates the root mean square speed of a gas
     * @param m  is the molecular mass of the gas molecule in u
     * @param T  is the temperature of the gas in K
     * @return  the root mean square speed of the gas
     */
    static ld rootMeanSquareSpeed(const ld m,
                                  const ld T,
                                  bool print = false)
    {
        // convert the mass to kg
        auto mass =  m / 1000.0;
        auto r = constants::R.joules;
        auto rms = sqrt((3.0 * r * T) / mass);
        if (print)
        {
            std::cout << "rms = " << rms << " m/s" << std::endl;
        }
        return rms;
    }

    ~Temperature()
    {
        countDecrease();
    }
};

#endif

#endif //PHYSICSFORMULA_TEMPERATURE_H
