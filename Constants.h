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
    constexpr auto e0 = 8.854187819013e-12; // 8.8542e-12
    /**
     * Vacuum permeability, commonly denoted μ0 (pronounced as "mu nought" or
     * "mu zero") is the value of the absolute permeability of classical vacuum.
     */
    constexpr auto mu0 = 4.0 * PI * 1.0e-7;//permeability of free space


    /// <summary>
    /// the Rydberg constant is expressed for either hydrogen as R_H or at the limit
    /// of infinite nuclear mass as R_∞. In either case, the constant is used to
    /// express the limiting value of the highest wave number (inverse wavelength)
    /// of any photon that can be emitted from an atom, or, alternatively,
    /// the wave number of the lowest-energy photon capable of ionizing an atom from
    /// its ground state. The hydrogen spectral series can be expressed simply in
    /// terms of the Rydberg constant for hydrogen R_H and the Rydberg formula.
    /// </summary>
    constexpr auto RYDBERG = 1.09678e7;

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
    constexpr auto K = 1.0 / (4.0 * PI * e0);
    constexpr auto COULOMB = 1.0 / (ELECTRON_CHARGE);
    constexpr auto PLANKS_J = 6.62607004e-34;
    constexpr auto PLANKS_EM = 4.14e-15;
    constexpr auto PLANKS_C = PLANKS_EM * 2.99792e8;
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

    constexpr auto ATOMIC_MASS_UNIT = 1.66e-27;



    constexpr auto G = 6.67408e-11;

    long double Ga = 9.81;
    void set_Ga(long double g) { Ga = g; }
}

#endif //PHYSICSFORMULA_CONSTANTS_H
