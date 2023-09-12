//
// Created by ryanz on 5/6/2022.
//

#ifndef PHYSICSFORMULA_CONSTANTS_H
#define PHYSICSFORMULA_CONSTANTS_H

using namespace std;

namespace constants {

    constexpr auto EARTH_RADIUS = 6.371e6;
    constexpr auto EARTH_MASS = 5.972e24;
    constexpr auto MOON_RADIUS = 1737.1e3;
    constexpr auto MOON_MASS = 7.34767309e22;
    constexpr auto SUN_RADIUS = 6.963e8;
    constexpr auto SUN_MASS = 1.989e30;
    // speed of light in a vacuum is 299792458 m/s
    constexpr auto LIGHT_SPEED = 2.99792458e8;//2.9979*10^8


    //pi = 3.14159265359
    constexpr auto PI = 3.14159265359;

    constexpr auto AVOGADRO = 6.02214076e23;

    /// <summary>
    /// Vacuum permittivity, commonly denoted ε0 (pronounced as "epsilon nought"
    /// or "epsilon zero") is the value of the absolute dielectric permittivity
    /// of classical vacuum.
    /// </summary>
    constexpr auto _e0 = 8.854187819013e-12; // 8.8542e-12
    /**
     * Vacuum permeability, commonly denoted μ0 (pronounced as "mu nought" or
     * "mu zero") is the value of the absolute permeability of classical vacuum.
     */
    constexpr auto _mu0 = 4.0 * PI * 1.0e-7;//permeability of free space

    /**
     * The elementary charge (symbol: e) is the electric charge carried by a
     * single proton or a single electron. It is denoted by the symbol e.
     */
    constexpr auto _e = 1.602176634e-19; // 1.6022e-19

    /// <summary>
    /// the Rydberg constant is expressed for either hydrogen as R_H or at the limit
    /// of infinite nuclear mass as R_∞. In either case, the constant is used to
    /// express the limiting value of the highest wave number (inverse wavelength)
    /// of any photon that can be emitted from an atom, or, alternatively,
    /// the wave number of the lowest-energy photon capable of ionizing an atom from
    /// its ground state. The hydrogen spectral series can be expressed simply in
    /// terms of the Rydberg constant for hydrogen R_H and the Rydberg formula.
    /// </summary>
    constexpr auto RYDBERG = 10973731.568527;//1/m

    /// <summary>
    /// The Bohr radius is a physical constant, equal to the most probable distance
    /// between the nucleus and the electron in a hydrogen atom in its ground state.
    /// It is named after Niels Bohr, due to its role in the Bohr model of an atom.
    /// Its value is 5.29177210903×10⁻¹¹
    /// </summary>
    constexpr auto BOHR_RADIUS = 5.29177210903e-11;

    /// <summary>
    /// The electron = -1.6 * 10^-19 C
    /// </summary>
    constexpr auto ELECTRON_CHARGE = -(1.602176634e-19); //-1.6e-19
    /// <summary>
    /// The electron mass = 9.10938291 * 10^-31 kg
    /// </summary>
    constexpr auto ELECTRON_MASS = 9.1093837015e-31;  //9.11e-31
    /// <summary>
    /// The proton mass = 1.672621777 * 10^-27 kg
    /// </summary>
    constexpr auto PROTON_MASS   = 1.67262e-27; //1.673e-27
    /// <summary>
    /// The proton = 1.6 * 10^-19C
    /// </summary>
    constexpr auto PROTON_CHARGE = 1.602176634e-19; // 1.6e-19
    /// <summary>
    /// Coulombs constant 8.988 * pow(10.0, 9)Nm^2)/C^2
    /// </summary>
    constexpr auto COULOMB = 1.0 / (ELECTRON_CHARGE);
    /// <summary>
    /// The proportionality constant.
    /// </summary>
    constexpr auto K = 1.0 / (4.0 * PI * _e0);

    constexpr auto PLANKS_J = 6.62607004e-34;
    constexpr auto PLANKS_EM = 4.14e-15;
    constexpr auto PLANKS_C = PLANKS_EM * 2.99792e8;
    constexpr struct PLANKS_CONSTANT {
        long double Joules_Hz = 6.62607015e-34;
        long double Joules_s = 1.054571817e-34;
        long double eV_Hz = 4.135667696e-15;
        long double eV_s_hc = 6.582119569e-16;
        long double J_m = 1.98644586e-25;
        long double J_m2 = 3.16152677e-26;
        long double eV_m = 1.23984198e-6;
        long double eV_m2 = 1.973269804e-7;
    } PLANKS;

    constexpr auto A_B = (PLANKS_J*PLANKS_J)/(4.0*(PI*PI)*ELECTRON_MASS*
            K*(PROTON_CHARGE*PROTON_CHARGE));
    /// <summary>
    /// After performing an uncertainty analysis, it was found that the electron
    /// charge to mass ratio is most accurately reported as 1.71×10¹¹ ± 5.9×10^9 C/kg
    /// </summary>
    constexpr auto Q2M_E = ELECTRON_CHARGE/ELECTRON_MASS;
    /// <summary>
    /// The Proton Charge to Mass ratio is 95788335.8 C/kg.
    /// </summary>
    constexpr auto Q2M_P = PROTON_CHARGE/PROTON_MASS;
    /***
     * @ the Stefan Boltzmann constant is often represented as sigma in the
     * Stefan Boltzmann->(σ) law of radiation equation
     */
    constexpr auto STEFAN_BOLTZMANN = 5.67e-8;

    /**
     * The Boltzmann constant is the ratio of the energy of a system to the
     * amount of heat energy required to raise the system to temperature T.
     */
    constexpr auto BOLTZMANN = 1.38064852e-23;


    /**
     * @brief Global constant _R_ is the universal gas constant struct which has _R_
     * in different units for use in different kinds of problems all represented
     * as unit/mol * K
     */
    const struct UniversalGasConstant
    {
        const long double joules = 8.314; //8.31 J/mol * K
        const long double cal = 1.99; // 1.99 cal/mol * k
        const long double L_atm = .08206; // .0821 L * atm/mol * K
        const long double atm = 101.3; // 101.3 atm/mol * K
        const long double mmHg = 760; // 760 mmHg/mol * K
    }R;

    constexpr auto DEGREE = 180.0/PI;
    constexpr auto RADIAN = PI/180.0;
    constexpr auto eV = 1.602e-19;
    constexpr auto JOULES2eV = 1.0 / eV;
    constexpr auto ATM_TO_PASCAL_MULTIPLIER = 101325;
    constexpr auto GAUSS = 1.0e-4; //Tesla's


    /// <summary>
    /// The meters light travels in one light year
    /// </summary>
    constexpr auto METERS_1LY = 9460730472580800;

    constexpr auto ATOMIC_MASS_UNIT = 1.66053886e-27; //kg
    constexpr auto AMU = ATOMIC_MASS_UNIT;

    constexpr auto MOLAR_MASS_UNIT = .999999999e-3; //kg/mol

    constexpr auto FARADAY = 96485.33212; //Coulombs/mol

    constexpr auto MOLAR_PLANCK = 3.9903127128934314e-10; //J/Hz*mol



    constexpr auto G = 6.67408e-11;
    long double _g = 9.80665; // acceleration due to gravity at sea level
    long double Ga = 9.81;
    void set_Ga(long double g) { Ga = g; }
}

/// <summary>
/// structure filled with conversion methods
/// </summary>
static struct Conversions
{
    struct SpecificHeatConverter
    {
        template<typename T>
        static auto joulesKgC_to_kCalKgC(const T j)
        {
            return j * .000238845896627;
        }
        template<typename T>
        static auto kCalKgC_to_joulesKgC_IT(const T kCal)
        {
            return kCal * 4186.8;
        }
        template<typename T>
        static auto kJoulesMolC_to_kCalMolC(const T kJ)
        {
            return kJ * .239005736137;
        }
        template<typename T>
        static auto kCalMolC_to_kJoulesMolC(const T kCal)
        {
            return kCal * 4.184;
        }
        // method to go from kj/mol to joules/kg
        template<typename T>
        static auto kJoulesMolC_to_joulesKgC(const T kJ, const T m)
        {
            return kJ * m * .239005736137;
        }
    }heat;

    struct VolumeConverter
    {
        template<typename T>
        static auto liters_to_cubicMeters(const T l)
        {
            return l * .001;
        }
        template<typename T>
        static auto cubicMeters_to_liters(const T m3)
        {
            return m3 * 1000;
        }
        template<typename T>
        static auto cubicCentimeters_to_cubicMeters(const T cm3)
        {
            return cm3 * .000001;
        }
        template<typename T>
        static auto cubicMeters_to_cubicCentimeters(const T m3)
        {
            return m3 * 1000000;
        }
        template<typename T>
        static auto cubicCentimeters_to_liters(const T cm3)
        {
            return cm3 * .001;
        }
        template<typename T>
        static auto liters_to_cubicCentimeters(const T l)
        {
            return l * 1000;
        }
        template<typename T>
        static auto cubicMilliliters_to_cubicMeters(const T ml)
        {
            return ml * .000000001;
        }

    }volume;

    struct SpeedConverter
    {
        template<typename T>
        static auto metersPerSecond_to_kilometersPerHour(const T mps)
        {
            return mps * 3.6;
        }
        template<typename T>
        static auto kilometersPerHour_to_metersPerSecond(const T kph)
        {
            return kph * .27777777777778;
        }
        template<typename T>
        static auto metersPerSecond_to_milesPerHour(const T mps)
        {
            return mps * 2.2369362920544;
        }
        template<typename T>
        static auto milesPerHour_to_metersPerSecond(const T mph)
        {
            return mph * .44704;
        }
        template<typename T>
        static auto kilometersPerHour_to_milesPerHour(const T kph)
        {
            return kph * .62137119223733;
        }
        template<typename T>
        static auto milesPerHour_to_kilometersPerHour(const T mph)
        {
            return mph * 1.609344;
        }
        template<typename T>
        static auto kilometersPerSecond_to_kilometersPerHour(
                const T kms)
        {
            return kms * 3600.0;
        }
        template<typename T>
        static auto kilometersPerHour_to_kilometersPerSecond(
                const T kmh)
        {
            return kmh / 3600.0;
        }
        template<typename T>
        static auto milesPerHour_to_milesPerSecond(const T mph)
        {
            return mph / 2.237;
        }
        template<typename T>
        static auto milesPerSecond_to_milesPerHour(const T mps)
        {
            return mps * 2.237;
        }
    }speed;

    struct TimeConverter {

        template<typename T>
        static auto millisecond_to_seconds(const T ms)
        {
            return ms / 1000;
        }

        template<typename T>
        static auto seconds_to_millisecond(const T s)
        {
            return s * 1000;
        }

        template<typename T>
        static auto seconds_to_minutes(const T s) {
            return s / 60.0;
        }

        template<typename T>
        static auto minutes_to_seconds(const T m) {
            return m * 60.0;
        }

        template<typename T>
        static auto seconds_to_hours(const T s) {
            return s / 3600.0;
        }

        template<typename T>
        static auto hours_to_seconds(const T h) {
            return h * 3600.0;
        }

        template<typename T>
        static auto minutes_to_hours(const T m) {
            return m / 60.0;
        }

        template<typename T>
        static auto hours_to_minutes(const T h) {
            return h * 60.0;
        }

        template<typename T>
        static auto seconds_to_days(const T s) {
            return s / 86400.0;
        }

        template<typename T>
        static auto days_to_seconds(const T d) {
            return d * 86400.0;
        }

        template<typename T>
        static auto minutes_to_days(const T m) {
            return m / 1440.0;
        }

        template<typename T>
        static auto days_to_minutes(const T d) {
            return d * 1440.0;
        }

        template<typename T>
        static auto hours_to_days(const T h) {
            return h / 24.0;
        }

        template<typename T>
        static auto days_to_hours(const T d) {
            return d * 24.0;
        }

        template<typename T>
        static auto seconds_to_weeks(const T s) {
            return s / 604800.0;
        }

        template<typename T>
        static auto weeks_to_seconds(const T w) {
            return w * 604800.0;
        }

        template<typename T>
        static auto minutes_to_weeks(const T m) {
            return m / 10080.0;
        }

        template<typename T>
        static auto weeks_to_minutes(const T w) {
            return w * 10080.0;
        }

        template<typename T>
        static auto hours_to_weeks(const T h) {
            return h / 168.0;
        }

        template<typename T>
        static auto weeks_to_hours(const T w) {
            return w * 168.0;
        }

        template<typename T>
        static auto days_to_weeks(const T d) {
            return d / 7.0;
        }

        template<typename T>
        static auto weeks_to_days(const T w) {
            return w * 7.0;
        }

        template<typename T>
        static auto seconds_to_months(const T s) {
            return s / 2628000.0;
        }

        template<typename T>
        static auto months_to_seconds(const T m) {
            return m * 2628000.0;
        }

        template<typename T>
        static auto minutes_to_months(const T m) {
            return m / 43800.0;
        }

        template<typename T>
        static auto months_to_minutes(const T m) {
            return m * 43800.0;
        }

        template<typename T>
        static auto hours_to_months(const T h) {
            return h / 730.0;
        }

        template<typename T>
        static auto months_to_hours(const T m) {
            return m * 730.0;
        }

        template<typename T>
        static auto days_to_months(const T d) {
            return d / 30.0;
        }

        template<typename T>
        static auto months_to_days(const T m) {
            return m * 30.0;
        }

        template<typename T>
        static auto weeks_to_months(const T w) {
            return w / 4.0;
        }

        template<typename T>
        static auto months_to_weeks(const T m) {
            return m * 4.0;
        }

        template<typename T>
        static auto seconds_to_years(const T s) {
            return s / 31536000.0;
        }

        template<typename T>
        static auto years_to_seconds(const T y) {
            return y * 31536000.0;
        }

        template<typename T>
        static auto minutes_to_years(const T m) {
            return m / 525600.0;
        }

        template<typename T>
        static auto years_to_minutes(const T y) {
            return y * 525600.0;
        }

        template<typename T>
        static auto hours_to_years(const T h) {
            return h / 8760.0;
        }

        template<typename T>
        static auto years_to_hours(const T y) {
            return y * 8760.0;
        }

        template<typename T>
        static auto days_to_years(const T d) {
            return d / 365.0;
        }

        template<typename T>
        static auto years_to_days(const T y) {
            return y * 365.0;
        }

        template<typename T>
        static auto weeks_to_years(const T w) {
            return w / 52.0;
        }

        template<typename T>
        static auto years_to_weeks(const T y) {
            return y * 52.0;
        }

        template<typename T>
        static auto months_to_years(const T m) {
            return m / 12.0;
        }

        template<typename T>
        static auto years_to_months(const T y) {
            return y * 12.0;
        }

        template<typename T>
        static auto seconds_to_decades(const T s) {
            return s / 315360000.0;
        }

        template<typename T>
        static auto decades_to_seconds(const T d) {
            return d * 315360000.0;
        }

        template<typename T>
        static auto minutes_to_decades(const T m) {
            return m / 5256000.0;
        }

        template<typename T>
        static auto decades_to_minutes(const T d) {
            return d * 5256000.0;
        }

        template<typename T>
        static auto hours_to_decades(const T h) {
            return h / 87600.0;
        }

        template<typename T>
        static auto decades_to_hours(const T d) {
            return d * 87600.0;
        }

        template<typename T>
        static auto days_to_decades(const T d) {
            return d / 3650.0;
        }

        template<typename T>
        static auto decades_to_days(const T d) {
            return d * 3650.0;
        }

    }time;

    template<typename T>
    static auto atomicMass_to_kilograms(const T u)
    {
        return u * 1.66053904E-27;
    }

    template<typename T>
    static auto kiloJoules_to_calories(const T kJ)
    {
        return (kJ * 1000.0) / 4186.0;
    }
    template<typename T>
    static auto revolutionsFromRadians(const T radTotal)
    {
        //cout << "revolutions: " << radTotal / (2.0 * constants::PI) << endl;
        return radTotal / (2.0 * constants::PI);
    }

    /**
     * @brief Returns the revolutions in radians per second which is the
     * angular velocity as well
     * @param revMin revolutions per minute
     * @returns revolutions in radians per second
     */
    template<typename T>
    static auto revolutions_min_to_radians_second(const T revMin)
    {
        return (revMin * 2.0 * constants::PI) / 60;
    }

    /**
     * @brief Returns the conversion from revolutions per radian second to
     * revolutions per minute
     * @param radSec is the rotation speed in radians per second
     * @returns the revolutions per minute
     */
    template<typename T>
    static auto radians_second_to_revolutions_minute(const T radSec)
    {
        return (radSec * 60.0) / (2.0 * constants::PI);
    }

    /**
     *  @brief Returns the ratio of the value to gravity
     *  @param unit can be whatever you are dividing by gravity acceleration
     *  @returns the gravity ratio
     */
    template<typename T>
    static auto gravity_ratio(const T unit)
    {
        return unit / constants::Ga;
    }

    template<typename T>
    static auto miles_to_meters(const T miles)
    {
        return miles * 1609.0;
    }
    /**
     * @brief Returns the conversion from feet to meters
     * @param feet to be converted
     * @returns meters
     */
    template<typename T>
    static auto feet_to_meters(const T feet)
    {
        return feet / 3.281;
    }
    /**
     * @brief Returns the conversion from inches to meters
     * @param inches to be converted
     * @returns meters
     */
    template<typename T>
    static auto inches_to_meters(const T inches)
    {
        return inches / 39.37;
    }
    /**
     * @brief Returns the conversion from meters to inches
     * @param meters is the total meters
     * @returns inches
     */
    template<typename T>
    static auto meters_to_inches(const T meters)
    {
        return meters * 39.37;
    }
    /**
     * @brief Returns the conversion from centimeters to meters
     * @param cm centimeters
     * @returns meters
     */
    template<typename T>
    static auto centimeters_to_meters(const T cm)
    {
        return cm / 100;
    }
    template<typename T>
    static auto meters_to_centimeters(const T m)
    {
        return m * 100;
    }
    template<typename T>
    static auto kilometers_to_meters(const T km)
    {
        return km * 1000;
    }
    template<typename T>
    static auto millimeters_to_meters(const T mm)
    {
        return mm / 1000;
    }
    template<typename T>
    static auto micrometers_to_meters(const T Mm)
    {
        return Mm / pow(1, -6);
    }
    template<typename T>
    static auto nanometers_to_meters(const T nm)
    {
        return nm / pow(1, -9);
    }
    template<typename T>
    static auto kilogram_to_pound(const T kg)
    {
        return kg * 2.20462;
    }
    template<typename T>
    static auto pound_to_kilogram(const T lbs)
    {
        return lbs / 2.205;
    }
    template<typename T>
    static auto milligram_to_kilogram(const T mg)
    {
        return mg / pow(1, -6);
    }
    template<typename T>
    static auto gram_to_kilogram(const T g)
    {
        return g / 1000.0;
    }
    template<typename T>
    static auto ounce_to_kilogram(const T ounce)
    {
        return ounce / 35.274;
    }
    template<typename T>
    static auto watts_to_kilowatts(const T watt)
    {
        return watt / 1000;
    }
    template<typename T>
    static auto kWh_to_joules(const T kWh)
    {
        return kWh * 3.6e6;
    }
    template<typename T>
    static auto joules_to_kWh(const T j)
    {
        return j / (3.6 * pow(10, 6));
    }
    template<typename T>
    static auto joules_to_eV(const T j)
    {
        return j / constants::PROTON_CHARGE;
    }
    template<typename T>
    static auto newtonMeters_to_ftPounds(const T Nm)
    {
        return Nm / .73756;
    }
    template<typename T>
    static auto radians_to_revolutions(const T rad)
    {
        return rad / (2 * constants::PI);
    }
    template<typename T>
    static auto revolutions_to_radians(const T rev)
    {
        return rev * 2 * constants::PI;
    }
    template<typename T>
    static auto atm_to_pascals(const T atm)
    {
        return atm * 101325.0;
    }

    template<typename T>
    static auto kcalPerDay_to_watts(const T d) {
        return d * .0484259259;
    }

    template<typename T>
    static auto watts_to_hp(T d) {
        return d * .001341022089;
    }

    template<typename T>
    static auto hp_to_watts(T d) {
        return d * 745.7;
    }

    template<typename T>
    static auto lbs_kg(T lbs) {
        return lbs * .45359237;
    }

    template<typename T>
    static auto liters_to_kilograms(T liters, T density) {
        return liters * density;
    }

    template<typename T>
    static auto cubicMetersToLiters(T m3) {
        return m3 * 1000;
    }
}converter;

/// <summary>
/// structure filled with common densities
/// </summary>
static struct Densities
{
    const long double aluminum_S = 2.7e3; // 2700 kg/m^3
    const long double brass_S = 8.44e3; // 8440 kg/m^3
    const long double copperAverage_S = 8.84e3; // 8800 kg/m^3
    const long double gold_S = 19.32e3; // 19320 kg/m^3
    const long double ironOrSteele_S = 7.8e3; // 7800 kg/m^3
    const long double lead_S = 11.3e3; // 11300 kg/m^3
    const long double polystyrene_S = .10e3; // 100 kg/m^3
    const long double tungsten = 19.30e3; // 19300 kg/m^3
    const long double uranium = 18.7e3; // 18700 kg/m^3
    const long double concrete_light_S = 2.30e3; // 2300 kg/m^3
    const long double concrete_med_S = 2.7e3; // 2700 kg/m^3
    const long double concrete_heavyDuty_S = 3.0e3; // 3000 kg/m^3
    const long double cork_S = .24e3; // 240 kg/m^3
    const long double glassAverage_S = 2.6e3; // 2600 kg/m^3
    const long double granite = 2.7e3; // 2700 kg/m^3
    const long double earthsCrust_S = 3.3e3; // 3300 kg/m^3
    const long double woodSoft_S = .3e3; // 300 kg/m^3
    const long double woodMed_S = .6e3 ; // 600 kg/m^3
    const long double woodHard_S = .9e3; // 900 kg/m^3
    const long double ice_0deg_S = .917e3; // 917 kg/m^3
    const long double boneSoft_S = 1.7e3; // 1700 kg/m^3
    const long double boneHard_S = 2.0e3; // 2000 kg/m^3
    const long double water_L = 1.0e3; // 1000 kg/m^3
    const long double blood_L = 1.05e3; // 1050 kg/m^3
    const long double seaWater_L = 1.025e3; // 1025 kg/m^3
    const long double mercury_L = 13.6e3; // 13600 kg/m^3
    const long double ethylAlcohol_L = .79e3; // 790 kg/m^3
    const long double petrol_L = .68e3; // 680 kg/m^3
    const long double glycerin_L = 1.26e3; // 1260 kg/m^3
    const long double oliveOil_L = .92e3; // 920 kg/m^3
    const long double air_G = 1.293e3; // 1.29 kg/m^3
    const long double carbon_dioxide_G = 1.98e3; // 1.98 kg/m^3
    const long double carbon_monoxide_G3e = 1.25e3; // 1.25 kg/m^3
    const long double hydrogen_G = 0.090e3; // 0.090 kg/m^3
    const long double helium_G = 0.18e3; // 0.18 kg/m^3
    const long double methane_G = 0.72e3; // 0.72 kg/m^3
    const long double nitrogen_G = 1.25e3; // 1.25 kg/m^3
    const long double nitrous_oxide_G = 1.98e3; // 1.98 kg/m^3
    const long double oxygen_G = 1.43e3; // 1.43 kg/m^3
    const long double steam_G = 0.60e3; // 0.60 kg/m^3
    const long double interstellar_space_G = 10.0e-20; // 10.0 x 10^-20 kg/m^3
    const long double black_hole = 10e19; // 10 x 10^19 kg/m^3
}p;

#endif //PHYSICSFORMULA_CONSTANTS_H
