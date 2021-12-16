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
using namespace std;

/**
 * @brief Global Constant _K_ is the Boltzmann constant
 * .0000000000000000000000138 J/K
 */
constexpr auto _BOLTZMANN_K_ = 1.38e-23;//1.38e-23

constexpr auto _ATOMIC_MASS_UNIT_ = 1.66e-27; //1.6605e-27 (u)

/**
 * @brief Global Constant _Na_ is  Avogadro's number and is used to express
 * units in moles, abb(mol) and is equal to 6.02e23 mol^-1
 */
constexpr auto _AVOGADRO_ = 6.02e23;//6.02*10^23

static struct TemperatureConversions
{
    static ld  celsius_to_fahrenheit(const ld c) { return (9.0 / 5.0) * c + 32.0; }
    static ld  fahrenheit_to_celsius(const ld f) { return (5.0 / 9.0) * (f - 32.0); }
    static ld  celsius_to_kelvin(const ld c) { return c + 273.15; }
    static ld  kelvin_to_celsius(const ld k) { return k - 273.15; }
    static ld  fahrenheit_to_kelvin(const ld f) { return (5.0 / 9.0) * (f - 32) + 273.15; }
    static ld  kelvin_to_fahrenheit(const ld k) { return (9.0 / 5.0) * (k - 273.15) + 32.0; }
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
    const std::vector<ld> aluminum_S = { 25 * pow(10, -6), 75 * pow(10, -6) };
    const std::vector<ld> brass_S = { 19 * pow(10, -6), 56 * pow(10, -6) };
    const std::vector<ld> copper_S = { 17 * pow(10, -6), 51 * pow(10, -6) };
    const std::vector<ld> gold_S = { 14 * pow(10, -6), 42 * pow(10, -6) };
    const std::vector<ld> iron_or_steel_S = { 12 * pow(10, -6), 35 * pow(10, -6) };
    const std::vector<ld> invar_nickel_iron_allow_S = { 0.9 * pow(10, -6), 2.7 * pow(10, -6) };
    const std::vector<ld> lead_S = { 29 * pow(10, -6), 87 * pow(10, -6) };
    const std::vector<ld> silver_S = { 18 * pow(10, -6), 54 * pow(10, -6) };
    const std::vector<ld> glass_ordinary_S = { 9 * pow(10, -6), 27 * pow(10, -6) };
    const std::vector<ld> glass_pyrex_S = { 3 * pow(10, -6), 9 * pow(10, -6) };
    const std::vector<ld> quartz_S = { 0.4 * pow(10, -6), 1 * pow(10, -6) };
    const std::vector<ld> concrete_brick_S = { 12 * pow(10, -6), 36 * pow(10, -6) }; //average
    const std::vector<ld> marble_S = { 7 * pow(10, -6), 2.1 * pow(10, -6) }; //average
    const ld ether_L = 1650 * pow(10, -6);
    const ld ethyl_alcohol = 1100 * pow(10, -6);
    const ld petrol = 950 * pow(10, -6);
    const ld glycerin = 500 * pow(10, -6);
    const ld mercury = 180 * pow(10, -6);
    const ld water = 210 * pow(10, -6);
    const ld air_and_most_gases_at_atmospheric_pressure = 3400 * pow(10, -6);

}a;

/**
 * @brief Global constant _R_ is the universal gas constant struct which has _R_
 * in different units for use in different kinds of problems all represented
 * as unit/mol * K
 */
const struct UniversalGasConstant
{
    const ld joules = 8.31; //8.31 J/mol * K
    const ld cal = 1.99; // 1.99 cal/mol * k
    const ld L_atm = .0821; // .0821 L * atm/mol * K
}R;


static int temperature_objectCount = 0;

class Temperature
{
private:

    static void countIncrease() { temperature_objectCount += 1; }
    static void countDecrease() { temperature_objectCount -= 1; }
public:
    Temperature* _tempPtr;
    /**
     * @brief no argument constructor
     */
    Temperature()
    {
        _tempPtr = nullptr;
        T._celsius = 0.0;
        T._fahrenheit = 0.0;
        T._kelvin = 0.0;
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
        _mode = t._mode;
        _tempPtr = t._tempPtr;
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
            _mode = t._mode;
            _tempPtr = t._tempPtr;
            countIncrease();
        }
        return *this;
    }

    /**
     * #brief move constructor
     */
    Temperature(Temperature&& t) noexcept : _tempPtr(nullptr), _mode(t._mode)
    {
        T._fahrenheit = t.T._fahrenheit;
        T._celsius = t.T._celsius;
        T._kelvin = t.T._kelvin;
    }

    static void show_temperature_objectCount() { std::cout << "\ntemperature object count: " << temperature_objectCount << std::endl; }
    static int get_temperature_objectCount() { return temperature_objectCount; }

    struct Temp
    {
        ld _celsius;
        ld _fahrenheit;
        ld _kelvin;

        ld getFahrenheit()const { return _fahrenheit; }
        ld getCelsius()const { return _celsius; }
        ld getKelvin()const { return _kelvin; }
        void showFahrenheit()const { std::cout << "F: " << getFahrenheit() << std::endl; }
        void showCelsius()const { std::cout << "C: " << getCelsius() << std::endl; }
        void showKelvin()const { std::cout << "K: " << getKelvin() << std::endl; }
        void showAllTemps()const
        {
            showFahrenheit();
            showCelsius();
            showKelvin();
        }

        /**
         * @brief method to set the fahrenheit instance variable. will update other
         * instance variables to reflect.
         * @param f is the temp in fahrenheit
         */
        void set_fahrenheit(const ld f)
        {
            _fahrenheit = f;
            _celsius = tempConverter.fahrenheit_to_celsius(_fahrenheit);
            _kelvin = tempConverter.fahrenheit_to_kelvin(_fahrenheit);
        }
        /**
        * @brief method to set the celsius instance variable. will update other
        * instance variables to reflect.
        * @param c is the temp in celsius
        */
        void set_celsius(const ld c)
        {
            _celsius = c;
            _fahrenheit = tempConverter.celsius_to_fahrenheit(_celsius);
            _kelvin = tempConverter.celsius_to_kelvin(_celsius);
        }
        /**
        * @brief method to set the kelvin instance variable. will update other
        * instance variables to reflect.
        * @param k is the temp in kelvin
        */
        void set_kelvin(const ld k)
        {
            _kelvin = k;
            _celsius = tempConverter.kelvin_to_celsius(_kelvin);
            _fahrenheit = tempConverter.kelvin_to_fahrenheit(_kelvin);
        }
    }T;


    /**
     * @brief char variable when set will change the default of the constructor arguments being
     * passed in
     * 'c' = celsius
     * 'f' = fahrenheit
     * 'k' = kelvin
     */
    char _mode;

    /**
     * @brief method to set the mode to either f or fahrenheit, c for celsius or k for kelvin
     * @param mode is a char of the mode either 'f','c','k'. be sure to include single quotes
     * if its a literal being passed
     */
    void set_mode(char mode)
    {
        if(mode == 'c' || mode == 'f' || mode == 'k')
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
        T._fahrenheit = f;
        T._celsius =  tempConverter.fahrenheit_to_celsius(T._fahrenheit);
        T._kelvin = tempConverter.fahrenheit_to_kelvin(T._fahrenheit);
    }
    /**
 * @brief method to set the celsius instance variable. will update other
 * instance variables to reflect.
 * @param c is the temp in celsius
 */
    void set_celsius(const ld c)
    {
        T._celsius = c;
        T._fahrenheit = tempConverter.celsius_to_fahrenheit(T._celsius);
        T._kelvin = tempConverter.celsius_to_kelvin(T._celsius);
    }
    /**
    * @brief method to set the kelvin instance variable. will update other
    * instance variables to reflect.
    * @param k is the temp in kelvin
    */
    void set_kelvin(const ld k)
    {
        T._kelvin = k;
        T._celsius = tempConverter.kelvin_to_celsius(T._kelvin);
        T._fahrenheit = tempConverter.kelvin_to_fahrenheit(T._kelvin);
    }
    ld getFahrenheit()const { return T._fahrenheit; }
    ld getCelsius()const { return T._celsius; }
    ld getKelvin()const { return T._kelvin; }
    void showFahrenheit()const { std::cout << "F: " << getFahrenheit() << std::endl; }
    void showCelsius()const { std::cout << "C: " << getCelsius() << std::endl; }
    void showKelvin()const { std::cout << "K: " << getKelvin() << std::endl; }
    void showAllTemps()const
    {
        showFahrenheit();
        showCelsius();
        showKelvin();
    }



    /**
     * @brief converts from molecules to moles
     * @param N is the number of molecules
     * @returns the   mole^-1
     */
    ld static convert_to_mol(const ld N)
    {
        return N / _AVOGADRO_;
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
     * @brief calculate the gas pressure in a tank
     * @param F is the total change in volume calculated previously
     * @param A is the total volume of tank
     * @param B is the bulk modulus
     * @returns the gas pressure in Pa
     */
    static ld gasPressure(const ld F, const ld A, const ld B)
    {
        return ((F / A)-1) * B;
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
        return (N * _BOLTZMANN_K_ * T) / V;
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
        return (P * V)/(_BOLTZMANN_K_ * T);
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
    static ld numberMoles_idealGasLaw(const ld P, const ld V, const ld T, const ld _R = R.joules)
    {
        return (P * V) / (_R * T);
    }

    /**
     * @brief calculates the KE of a cloud or gas of N molecules
     * @param T is the absolute temperature in kelvin
     * @returns Thermal energy, molecular interpretation of temperature
     */
    static ld translationalKineticEnergy_molecules(const ld T)
    {
        return (3.0 / 2.0)* _BOLTZMANN_K_* T;
    }

    /**
     * @brief calculates the average speed of molecules at a certain temperature
     * @param m is the mass of a single molecule
     * @param T Temp K
     */
    static ld speedAverage_rms(const ld m, const ld T)
    {
        return sqrt((3.0 * _BOLTZMANN_K_ * T) / m);
    }

    /**
     * @brief calculates the temperature in kelvin a molecule would need to be to reach a certain velocity
     * @param m is the mass of a molecule
     * @param v is the velocity in question
     * @returns the temp in kelvin needed for a molecule to reach a velocity
     */
    static ld temperatureOfMoleculeAtVelocity(const ld m, const ld v)
    {
        return (m * (v * v)) / (3.0 * _BOLTZMANN_K_);
    }

    /**
     * @brief calculates the density of vapor
     */
    static ld vaporDensity(const ld p, const ld m, const ld T, const ld _R = R.joules)
    {
        return (p * m) / (_R * T);
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
        return finishTemp - startTemp;
    }

    ~Temperature()
    {
        delete _tempPtr;
    }
};

#endif

#endif //PHYSICSFORMULA_TEMPERATURE_H
