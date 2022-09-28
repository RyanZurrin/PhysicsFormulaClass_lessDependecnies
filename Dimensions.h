//
// Created by ryanz on 9/28/2022.
//

#ifndef PHYSICSFORMULA_DIMENSIONS_H
#define PHYSICSFORMULA_DIMENSIONS_H

#include <iostream>


/**
 * @brief A structure representing a list of the dimensions of common physical
 * quantities, together with their conventional symbols and the SI units in
 * which they are usually quoted. The dimensional basis used is Length (L),
 * mass (M), time (T), electric current (I), thermodynamic temperature (Θ),
 * amount of substance (N), and luminous intensity (J).
 */
static struct Dimensions
{
    Dimensions()  {}

    const struct ACCELERATION {
        const std::string symbol = "a";
        const std::string dimensions = "L/T^2";
        const std::string SI_units = "m/s^2";
    } acceleration;

    const struct ACTION {
        const std::string symbol = "S";
        const std::string dimensions = "L^2M/T";
        const std::string SI_units = "Js";
    } action;

    const struct ANGULAR_MOMENTUM {
        const std::string symbol = "L, J";
        const std::string dimensions = "L^2M/T";
        const std::string SI_units = "m^2kg/s";
    } angular_momentum;

    const struct ANGULAR_SPEED {
        const std::string symbol = "ω";
        const std::string dimensions = "1/T";
        const std::string SI_units = "rad/s";
    } angular_velocity;

    const struct ANGULAR_ACCELERATION {
        const std::string symbol = "α";
        const std::string dimensions = "1/T^2";
        const std::string SI_units = "rad/s^2";
    } angular_acceleration;

    const struct ANGULAR_MOMENTUM_OF_INERTIA {
        const std::string symbol = "I";
        const std::string dimensions = "L^2M";
        const std::string SI_units = "kgm^2";
    } angular_momentum_of_inertia;

    const struct area  {
        const std::string symbol = "A, S";
        const std::string dimensions = "L^2";
        const std::string SI_units = "m^2";
    } area;

    const struct AVOGADRO_CONSTANT {
        const std::string symbol = "N_A";
        const std::string dimensions = "1/N";
        const std::string SI_units = "mol^-1";
    } avogadro_constant;

    const struct BENDING_MOMENT {
        const std::string symbol = "G_b";
        const std::string dimensions = "L^2M/T^2";
        const std::string SI_units = "Nm";
    } bending_moment;

    const struct  BOHR_MAGNETON {
        const std::string symbol = "μ_B";
        const std::string dimensions = "L^2I";
        const std::string SI_units = "J/T";
    } bohr_magneton;

    const struct BOLTZMANN_CONSTANT {
        const std::string symbol = "k, k_B";
        const std::string dimensions = "L^2M/ΘT^2";
        const std::string SI_units = "J/K";
    } boltzmann_constant;

    const struct BULK_MODULUS {
        const std::string symbol = "K";
        const std::string dimensions = "L^-1M/T^2";
        const std::string SI_units = "Pa";
    } bulk_modulus;

    const struct CAPACITANCE {
        const std::string symbol = "C";
        const std::string dimensions = "T^4I^2/L^2M^1";
        const std::string SI_units = "F";
    } capacitance;

    const struct CHARGE_ELECTRIC {
        const std::string symbol = "q";
        const std::string dimensions = "TI";
        const std::string SI_units = "C";
    } charge;

    const struct CHARGE_DENSITY {
        const std::string symbol = "ρ";
        const std::string dimensions = "TI/L^3";
        const std::string SI_units = "C/m^3";
    } charge_density;

    const struct CONDUCTANCE {
        const std::string symbol = "G";
        const std::string dimensions = "T^3I^2/L^2M^1";
        const std::string SI_units = "S";
    } conductance;

    const struct CONDUCTIVITY {
        const std::string symbol = "σ";
        const std::string dimensions = "L^-3M^-1T^3I^2S";
        const std::string SI_units = "S/m";
    } conductivity;

    const struct COUPLE {
        const std::string symbol = "G, T";
        const std::string dimensions = "L^2M/T^2N";
        const std::string SI_units = "Nm";
    } couple;

    const struct CURRENT {
        const std::string symbol = "I, i";
        const std::string dimensions = "I";
        const std::string SI_units = "A";
    } current;

    const struct CURRENT_DENSITY {
        const std::string symbol = "J, j";
        const std::string dimensions = "L^-2I";
        const std::string SI_units = "A/m^2";
    } current_density;

    const struct DENSITY {
        const std::string symbol = "ρ";
        const std::string dimensions = "L^-3M";
        const std::string SI_units = "kg/m^3";
    } density;

    const struct ELECTRIC_DISPLACEMENT {
        const std::string symbol = "D";
        const std::string dimensions = "L^-2T";
        const std::string SI_units = "C/m^2";
    } electric_displacement;

    const struct ELECTRIC_FIELD_STRENGTH {
        const std::string symbol = "E";
        const std::string dimensions = "LMT^-3I^-1";
        const std::string SI_units = "V/m";
    } electric_field_strength;

    const struct ELECTRIC_POLARISABILITY {
        const std::string symbol = "α";
        const std::string dimensions = "M^-1T^4I^2C";
        const std::string SI_units = "m^2/V";
    } electric_polarisability;

    const struct ELECTRIC_POLARISATION {
        const std::string symbol = "P";
        const std::string dimensions = "L^-2T";
        const std::string SI_units = "C/m^2";
    } electric_polarisation;

    const struct ELECTRIC_POTENTIAL_DIFFERENCE {
        const std::string symbol = "V";
        const std::string dimensions = "L^2MT^-3I^-1";
        const std::string SI_units = "V";
    } electric_potential_difference;

    const struct ENERGY {
        const std::string symbol = "E, U";
        const std::string dimensions = "L^2MT^-2";
        const std::string SI_units = "J";
    } energy;

    const struct ENERGY_DENSITY {
        const std::string symbol = "u";
        const std::string dimensions = "L^-1MT^-2";
        const std::string SI_units = "J/m^3";
    } energy_density;

    const struct ENTROPY {
        const std::string symbol = "S";
        const std::string dimensions = "L^2MT^-2Θ^-1";
        const std::string SI_units = "J/K";
    } entropy;

    const struct FARADAY_CONSTANT {
        const std::string symbol = "F";
        const std::string dimensions = "TI";
        const std::string SI_units = "C/mol";
    } faraday_constant;

    const struct FORCE {
        const std::string symbol = "F";
        const std::string dimensions = "LMT^-2";
        const std::string SI_units = "N";
    } force;

    const struct FREQUENCY {
        const std::string symbol = "ν, f";
        const std::string dimensions = "T^-1";
        const std::string SI_units = "Hz";
    } frequency;

    const struct GRAVITATIONAL_CONSTANT {
        const std::string symbol = "G";
        const std::string dimensions = "L^3M^-1T^-2";
        const std::string SI_units = "m^3/kg/s^2";
    } gravitational_constant;

    const struct HALL_COEFFICIENT {
        const std::string symbol = "RH";
        const std::string dimensions = "L^3T^-1I^-1";
        const std::string SI_units = "m^3/C";
    } hall_coefficient;

    const struct HAMILTONIAN {
        const std::string symbol = "H";
        const std::string dimensions = "L^2MT^-2";
        const std::string SI_units = "J";
    } hamiltonian;

    const struct HEAT_CAPACITY {
        const std::string symbol = "C";
        const std::string dimensions = "L^2MT^-2Θ^-1";
        const std::string SI_units = "J/K";
    } heat_capacity;

    const struct HUBBLE_CONSTANT {
        const std::string symbol = "1";
        const std::string dimensions = "T^-1";
        const std::string SI_units = "s^-1";
    } hubble_constant;

    const struct ILLUMINANCE {
        const std::string symbol = "Ev";
        const std::string dimensions = "L^-2";
        const std::string SI_units = "lx";
    } illuminance;

    const struct IMPEDANCE {
        const std::string symbol = "Z";
        const std::string dimensions = "L^2MT^-3I^-2";
        const std::string SI_units = "Ω";
    } impedance;

    const struct IMPULSE {
        const std::string symbol = "I";
        const std::string dimensions = "LMT^-1";
        const std::string SI_units = "N s";
    } impulse;

    const struct INDUCTANCE {
        const std::string symbol = "L";
        const std::string dimensions = "L^2MT^-2I^-2";
        const std::string SI_units = "H";
    } inductance;

    const struct IRRADIANCE {
        const std::string symbol = "Ee";
        const std::string dimensions = "MT^-3";
        const std::string SI_units = "W/m^2";
    } irradiance;

    const struct LAGRANGIAN {
        const std::string symbol = "L";
        const std::string dimensions = "L^2MT^-2";
        const std::string SI_units = "J";
    } lagrangian;

    const struct LENGTH {
        const std::string symbol = "L, l";
        const std::string dimensions = "L";
        const std::string SI_units = "m";
    } length;

    const struct LUMINOUS_INTENSITY {
        const std::string symbol = "Iv";
        const std::string dimensions = "";
        const std::string SI_units = "cd";
    } luminous_intensity;

    const struct MAGNETIC_DIPOLE_MOMENT {
        const std::string symbol = "m, μ";
        const std::string dimensions = "L^2I";
        const std::string SI_units = "A m^2";
    } magnetic_dipole_moment;

    const struct MAGNETIC_FIELD_STRENGTH {
        const std::string symbol = "H";
        const std::string dimensions = "L^-1I";
        const std::string SI_units = "A m^-1";
    } magnetic_field_strength;

    const struct MAGNETIC_FLUX {
        const std::string symbol = "Φ";
        const std::string dimensions = "L^2MT^-2I^-1";
        const std::string SI_units = "Wb";
    } magnetic_flux;

    const struct MAGNETIC_FLUX_DENSITY {
        const std::string symbol = "B";
        const std::string dimensions = "MT^-2I^-1";
        const std::string SI_units = "T";
    } magnetic_flux_density;

    const struct MAGNETIC_VECTOR_POTENTIAL {
        const std::string symbol = "A";
        const std::string dimensions = "LMT^-2I^-1";
        const std::string SI_units = "Wb m^-1";
    } magnetic_vector_potential;

    const struct MAGNETISATION {
        const std::string symbol = "M";
        const std::string dimensions = "L^-1I";
        const std::string SI_units = "A m^-1";
    } magnetisation;

    const struct MASS {
        const std::string symbol = "m, M";
        const std::string dimensions = "M";
        const std::string SI_units = "kg";
    } mass;

    const struct MOBILITY {
        const std::string symbol = "μ";
        const std::string dimensions = "M^-1T^2I";
        const std::string SI_units = "m^2/V/s";
    } mobility;

    const struct MOLAR_GAS_CONSTANT {
        const std::string symbol = "R";
        const std::string dimensions = "L^2MT^-2Θ^-1N^-1";
        const std::string SI_units = "J/mol/K";
    } molar_gas_constant;

    const struct MOMENT_OF_INERTIA {
        const std::string symbol = "I";
        const std::string dimensions = "L^2Mkg";
        const std::string SI_units = "m^2";
    } moment_of_inertia;

    const struct MOMENTUM {
        const std::string symbol = "p";
        const std::string dimensions = "LMT^-1Mkg";
        const std::string SI_units = "m/s";
    } momentum;

    const struct NUMBER_DENSITY {
        const std::string symbol = "n";
        const std::string dimensions = "L^-3";
        const std::string SI_units = "m^-3";
    } number_density;

    const struct PERMEABILITY {
        const std::string symbol = "μ";
        const std::string dimensions = "LMT^-2I^-2";
        const std::string SI_units = "H/m";
    } permeability;

    const struct PERMITTIVITY {
        const std::string symbol = "";
        const std::string dimensions = "L^-3M^-1T^4I^2";
        const std::string SI_units = "F/m";
    } permittivity;

    const struct PLANCK_CONSTANT {
        const std::string symbol = "h";
        const std::string dimensions = "L^2MT^-1";
        const std::string SI_units = "J s";
    } planck_constant;

    const struct POWER {
        const std::string symbol = "P";
        const std::string dimensions = "L^2MT^-3";
        const std::string SI_units = "W";
    } power;

    const struct POYNTING_VECTOR {
        const std::string symbol = "S";
        const std::string dimensions = "MT^-3";
        const std::string SI_units = "W/m^2";
    } poynting_vector;

    const struct PRESSURE {
        const std::string symbol = "p, P";
        const std::string dimensions = "L^-1MT^-2";
        const std::string SI_units = "Pa";
    } pressure;

    const struct RADIANT_INTENSITY {
        const std::string symbol = "Ie";
        const std::string dimensions = "L^2MT^-3";
        const std::string SI_units = "W/sr";
    } radiant_intensity;

    const struct RESISTANCE {
        const std::string symbol = "R";
        const std::string dimensions = "L^2M^-3I^-2";
        const std::string SI_units = "Ω";
    } resistance;

    const struct RYDBERG_CONSTANT {
        const std::string symbol = "R∞";
        const std::string dimensions = "L^-1";
        const std::string SI_units = "m^-1";
    } rydberg_constant;

    const struct SHEAR_MODULUS {
        const std::string symbol = "μ, G";
        const std::string dimensions = "L^-1MT^-2";
        const std::string SI_units = "Pa";
    } shear_modulus;

    const struct SPECIFIC_HEAT_CAPACITY {
        const std::string symbol = "c";
        const std::string dimensions = "L^2T^-2Θ^-1";
        const std::string SI_units = "J/kg/K";
    } specific_heat_capacity;

    const struct SPEED {
        const std::string symbol = "u, v, c";
        const std::string dimensions = "LT^-1";
        const std::string SI_units = "m/s";
    } speed;

    const struct STEFAN_BOLTZMANN_CONSTANT {
        const std::string symbol = "σ";
        const std::string dimensions = "MT^-3Θ^-4";
        const std::string SI_units = "W/m^2/K^4";
    } stefan_boltzmann_constant;

    const struct STRESS {
        const std::string symbol = "σ, τ";
        const std::string dimensions = "L^-1MT^-2";
        const std::string SI_units = "Pa";
    } stress;

    const struct SURFACE_TENSION {
        const std::string symbol = "σ, γ";
        const std::string dimensions = "MT^-2";
        const std::string SI_units = "N/m";
    } surface_tension;

    const struct TEMPERATURE {
        const std::string symbol = "T";
        const std::string dimensions = "Θ";
        const std::string SI_units = "K";
    } temperature;

    const struct THERMAL_CONDUCTIVITY {
        const std::string symbol = "λ";
        const std::string dimensions = "LMT^-3Θ^-1";
        const std::string SI_units = "W/m/K";
    } thermal_conductivity;

    const struct TIME {
        const std::string symbol = "t";
        const std::string dimensions = "T";
        const std::string SI_units = "s";
    } time;

    const struct VELOCITY {
        const std::string symbol = "v, u";
        const std::string dimensions = "LT^-1";
        const std::string SI_units = "m/s";
    } velocity;

    const struct VISCOSITY_DYNAMIC {
        const std::string symbol = "η, μ";
        const std::string dimensions = "L^-1MT^-1";
        const std::string SI_units = "Pa s";
    } viscosity_dynamic;

    const struct VISCOSITY_KINEMATIC {
        const std::string symbol = "ν";
        const std::string dimensions = "L^2T^-1";
        const std::string SI_units = "m^2/s";
    } viscosity_kinematic;

    const struct VOLUME {
        const std::string symbol = "V , v";
        const std::string dimensions = "L^3";
        const std::string SI_units = "m^3";
    } volume;

    const struct WAVEVECTOR {
        const std::string symbol = "k";
        const std::string dimensions = "L^-1";
        const std::string SI_units = "m^-1";
    } wavevector;

    const struct WEIGHT {
        const std::string symbol = "W";
        const std::string dimensions = "LMT^-2";
        const std::string SI_units = "N";
    } weight;

    const struct WORK {
        const std::string symbol = "W";
        const std::string dimensions = "L^2MT^-2";
        const std::string SI_units = "J";
    } work;

    const struct YOUNG_MODULUS {
        const std::string symbol = "E";
        const std::string dimensions = "L^-1MT^-2";
        const std::string SI_units = "Pa";
    } young_modulus;
}dimensions;

#endif //PHYSICSFORMULA_DIMENSIONS_H
