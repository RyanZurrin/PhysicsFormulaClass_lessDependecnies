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
 * @version 12.13.2022
 */
#include "Heat.h"
#include "Energy.h"
#include "PeriodicTable.h"

static int thermodynamics_objectCount = 0;

ld static kiloJoulesToCalories(const ld kJ)
{
    return (kJ * 1000.0) / 4186.0;
}
static double Eff(const double W, const double Qh)
{
    return W / Qh;
}

static struct MolecularSpecificHeatCV {
    const ld monoatomic = (3.0 / 2.0) * constants::R.joules;
    const ld diatomic = (5.0 / 2.0) * constants::R.joules;
    const ld triatomic = 3.0 * constants::R.joules;
    const ld tetraatomic = (7.0 / 2.0) * constants::R.joules;
    const ld pentaatomic = 4.0 * constants::R.joules;
    const ld hexaatomic = (9.0 / 2.0) * constants::R.joules;
    const ld heptaatomic = 5.0 * constants::R.joules;
    const ld octaatomic = (11.0 / 2.0) * constants::R.joules;
    const ld nonaatomic = 6.0 * constants::R.joules;
}CV;

static struct MolecularSpecificHeatCP {
    const ld monoatomic = CV.monoatomic + constants::R.joules;
    const ld diatomic = CV.diatomic + constants::R.joules;
    const ld triatomic = CV.triatomic + constants::R.joules;
    const ld tetraatomic = CV.tetraatomic + constants::R.joules;
    const ld pentaatomic = CV.pentaatomic + constants::R.joules;
    const ld hexaatomic = CV.hexaatomic + constants::R.joules;
    const ld heptaatomic = CV.heptaatomic + constants::R.joules;
    const ld octaatomic = CV.octaatomic + constants::R.joules;
    const ld nonaatomic = CV.nonaatomic + constants::R.joules;
}CP;

static struct VanderWaalsConstants {
    VanderWaalsConstants() {}
//    Acetic acid 	17.7098 L^2bar / mol^2 	0.1065 L/mol
    struct ACETIC_ACID {
        const ld a = 17.7098; // L^2bar / mol^2
        const ld b = 0.1065; // L/mol
    }aceticAcid;
//    Acetic anhydride 	20.158 L^2bar / mol^2 	0.1263 L/mol
    struct ACETIC_ANHYDRIDE {
        const ld a = 20.158; // L^2bar / mol^2
        const ld b = 0.1263; // L/mol
    }aceticAnhydride;
//    Acetone 	16.02 L^2bar / mol^2 	0.1124 L/mol
    struct ACETONE {
        const ld a = 16.02; // L^2bar / mol^2
        const ld b = 0.1124; // L/mol
    }acetone;
//    Acetonitrile 	17.81 L^2bar / mol^2 	0.1168 L/mol
    struct ACETONITRILE {
        const ld a = 17.81; // L^2bar / mol^2
        const ld b = 0.1168; // L/mol
    }acetonitrile;
//    Acetylene 	4.516 L^2bar / mol^2 	0.0522 L/mol
    struct ACETYLENE {
        const ld a = 4.516; // L^2bar / mol^2
        const ld b = 0.0522; // L/mol
    }acetylene;
//    Ammonia 	4.225 L^2bar / mol^2 	0.0371 L/mol
    struct AMMONIA {
        const ld a = 4.225; // L^2bar / mol^2
        const ld b = 0.0371; // L/mol
    }ammonia;
//    Argon 	1.355 L^2bar / mol^2 	0.03201 L/mol
    struct ARGON {
        const ld a = 1.355; // L^2bar / mol^2
        const ld b = 0.03201; // L/mol
    }argon;
//    Benzene 	18.24 L^2bar / mol^2 	0.1193 L/mol
    struct BENZENE {
        const ld a = 18.24; // L^2bar / mol^2
        const ld b = 0.1193; // L/mol
    }benzene;
//    Bromobenzene 	28.94 L^2bar / mol^2 	0.1539 L/mol
    struct BROMOBENZENE {
        const ld a = 28.94; // L^2bar / mol^2
        const ld b = 0.1539; // L/mol
    }bromobenzene;
//    Butane 	14.66 L^2bar / mol^2 	0.1226 L/mol
    struct BUTANE {
        const ld a = 14.66; // L^2bar / mol^2
        const ld b = 0.1226; // L/mol
    }butane;
//    Carbon dioxide 	3.640 L^2bar / mol^2 	0.04267 L/mol
    struct CARBON_DIOXIDE {
        const ld a = 3.640; // L^2bar / mol^2
        const ld b = 0.04267; // L/mol
    }carbonDioxide;
//    Carbon disulfide 	11.77 L^2bar / mol^2 	0.07685 L/mol
    struct CARBON_DISULFIDE {
        const ld a = 11.77; // L^2bar / mol^2
        const ld b = 0.07685; // L/mol
    }carbonDisulfide;
//    Carbon monoxide 	1.505 L^2bar / mol^2 	0.0398500 L/mol
    struct CARBON_MONOXIDE {
        const ld a = 1.505; // L^2bar / mol^2
        const ld b = 0.0398500; // L/mol
    }carbonMonoxide;
//    Carbon tetrachloride 	19.7483 L^2bar / mol^2 	0.1281 L/mol
    struct CARBON_TETRACHLORIDE {
        const ld a = 19.7483; // L^2bar / mol^2
        const ld b = 0.1281; // L/mol
    }carbonTetrachloride;
//    Chlorine 	6.579 L^2bar / mol^2 	0.05622 L/mol
    struct CHLORINE {
        const ld a = 6.579; // L^2bar / mol^2
        const ld b = 0.05622; // L/mol
    }chlorine;
//    Chlorobenzene 	25.77 L^2bar / mol^2 	0.1453 L/mol
    struct CHLOROBENZENE {
        const ld a = 25.77; // L^2bar / mol^2
        const ld b = 0.1453; // L/mol
    }chlorobenzene;
//    Chloroethane 	11.05 L^2bar / mol^2 	0.08651 L/mol
    struct CHLOROETHANE {
        const ld a = 11.05; // L^2bar / mol^2
        const ld b = 0.08651; // L/mol
    }chloroethane;
//    Chloromethane 	7.570 L^2bar / mol^2 	0.06483 L/mol
    struct CHLOROMETHANE {
        const ld a = 7.570; // L^2bar / mol^2
        const ld b = 0.06483; // L/mol
    }chloromethane;
//    Cyanogen 	7.769 L^2bar / mol^2 	0.06901 L/mol
    struct CYANOGEN {
        const ld a = 7.769; // L^2bar / mol^2
        const ld b = 0.06901; // L/mol
    }cyanogen;
//    Cyclohexane 	23.11 L^2bar / mol^2 	0.1424 L/mol
    struct CYCLOhexANE {
        const ld a = 23.11; // L^2bar / mol^2
        const ld b = 0.1424; // L/mol
    }cyclohexane;
//    Diethyl ether 	17.61 L^2bar / mol^2 	0.1344 L/mol
    struct DIETHYL_ETHER {
        const ld a = 17.61; // L^2bar / mol^2
        const ld b = 0.1344; // L/mol
    }diethylEther;
//    Diethyl sulfide 	19.00 L^2bar / mol^2 	0.1214 L/mol
    struct DIETHYL_SULFIDE {
        const ld a = 19.00; // L^2bar / mol^2
        const ld b = 0.1214; // L/mol
    }diethylSulfide;
//    Dimethyl ether 	8.180 L^2bar / mol^2 	0.07246 L/mol
    struct DIMETHYL_ETHER {
        const ld a = 8.180; // L^2bar / mol^2
        const ld b = 0.07246; // L/mol
    }dimethylEther;
//    Dimethyl sulfide 	13.04 L^2bar / mol^2 	0.09213 L/mol
    struct DIMETHYL_SULFIDE {
        const ld a = 13.04; // L^2bar / mol^2
        const ld b = 0.09213; // L/mol
    }dimethylSulfide;
//    Ethane 	5.562 L^2bar / mol^2 	0.0638 L/mol
    struct ETHANE {
        const ld a = 5.562; // L^2bar / mol^2
        const ld b = 0.0638; // L/mol
    }ethane;
//    Ethanethiol 	11.39 L^2bar / mol^2 	0.08098 L/mol
    struct ETHANETHIOL {
        const ld a = 11.39; // L^2bar / mol^2
        const ld b = 0.08098; // L/mol
    }ethanethiol;
//    Ethanol 	12.18 L^2bar / mol^2 	0.08407 L/mol
    struct ETHANOL {
        const ld a = 12.18; // L^2bar / mol^2
        const ld b = 0.08407; // L/mol
    }ethanol;
//    Ethyl acetate 	20.72 L^2bar / mol^2 	0.1412 L/mol
    struct ETHYL_ACETATE {
        const ld a = 20.72; // L^2bar / mol^2
        const ld b = 0.1412; // L/mol
    }ethylAcetate;
//    Ethylamine 	10.74 L^2bar / mol^2 	0.08409 L/mol
    struct ETHYLANE {
        const ld a = 10.74; // L^2bar / mol^2
        const ld b = 0.08409; // L/mol
    }ethylamine;
//    Fluorobenzene 	20.19 L^2bar / mol^2 	0.1286 L/mol
    struct FLUOROBENZENE {
        const ld a = 20.19; // L^2bar / mol^2
        const ld b = 0.1286; // L/mol
    }fluorobenzene;
//    Fluoromethane 	4.692 L^2bar / mol^2 	0.05264 L/mol
    struct FLUOROMETHANE {
        const ld a = 4.692; // L^2bar / mol^2
        const ld b = 0.05264; // L/mol
    }fluoromethane;
//    Freon 	10.78 L^2bar / mol^2 	0.0998 L/mol
    struct FREON {
        const ld a = 10.78; // L^2bar / mol^2
        const ld b = 0.0998; // L/mol
    }freon;
//    Germanium tetrachloride 	22.90 L^2bar / mol^2 	0.1485 L/mol
    struct GERMANIUM_TETRACHLORIDE {
        const ld a = 22.90; // L^2bar / mol^2
        const ld b = 0.1485; // L/mol
    }germaniumTetrachloride;
//    Helium 	0.0346 L^2bar / mol^2 	0.0238 L/mol
    struct HELIUM {
        const ld a = 0.0346; // L^2bar / mol^2
        const ld b = 0.0238; // L/mol
    }helium;
//    Hexane 	24.71 L^2bar / mol^2 	0.1735 L/mol
    struct HEXANE {
        const ld a = 24.71; // L^2bar / mol^2
        const ld b = 0.1735; // L/mol
    }hexane;
//    Hydrogen 	0.2476 L^2bar / mol^2 	0.02661 L/mol
    struct HYDROGEN {
        const ld a = 0.2476; // L^2bar / mol^2
        const ld b = 0.02661; // L/mol
    }hydrogen;
//    Hydrogen bromide 	4.510 L^2bar / mol^2 	0.04431 L/mol
    struct HYDROGEN_BROMIDE {
        const ld a = 4.510; // L^2bar / mol^2
        const ld b = 0.04431; // L/mol
    }hydrogenBromide;
//    Hydrogen chloride 	3.716 L^2bar / mol^2 	0.04081 L/mol
    struct HYDROGEN_CHLORIDE {
        const ld a = 3.716; // L^2bar / mol^2
        const ld b = 0.04081; // L/mol
    }hydrogenChloride;
//    Hydrogen selenide 	5.338 L^2bar / mol^2 	0.04637 L/mol
    struct HYDROGEN_SELENIDE {
        const ld a = 5.338; // L^2bar / mol^2
        const ld b = 0.04637; // L/mol
    }hydrogenSelenide;
//    Hydrogen sulfide 	4.490 L^2bar / mol^2 	0.04287 L/mol
    struct HYDROGEN_SULFIDE {
        const ld a = 4.490; // L^2bar / mol^2
        const ld b = 0.04287; // L/mol
    }hydrogenSulfide;
//    Iodobenzene 	33.52 L^2bar / mol^2 	0.1656 L/mol
    struct IODOBENZENE {
        const ld a = 33.52; // L^2bar / mol^2
        const ld b = 0.1656; // L/mol
    }iodobenzene;
//    Krypton 	2.349 L^2bar / mol^2 	0.03978 L/mol
    struct KRYPTON {
        const ld a = 2.349; // L^2bar / mol^2
        const ld b = 0.03978; // L/mol
    }krypton;
//    Mercury 	8.200 L^2bar / mol^2	0.01696 L/mol
    struct MERCURY {
        const ld a = 8.200; // L^2bar / mol^2
        const ld b = 0.01696; // L/mol
    }mercury;
//    Methane 	2.283 L^2bar / mol^2 	0.04278 L/mol
    struct METHANE {
        const ld a = 2.283; // L^2bar / mol^2
        const ld b = 0.04278; // L/mol
    }methane;
//    Methanol 	9.649 L^2bar / mol^2 	0.06702 L/mol
    struct METHANOL {
        const ld a = 9.649; // L^2bar / mol^2
        const ld b = 0.06702; // L/mol
    }methanol;
//    Neon 	0.2135 L^2bar / mol^2 	0.01709 L/mol
    struct NEON {
        const ld a = 0.2135; // L^2bar / mol^2
        const ld b = 0.01709; // L/mol
    }neon;
//    Nitric oxide 	1.358 L^2bar / mol^2 	0.02789 L/mol
    struct NITRIC_OXIDE {
        const ld a = 1.358; // L^2bar / mol^2
        const ld b = 0.02789; // L/mol
    }nitricOxide;
//    Nitrogen 	1.370 L^2bar / mol^2 	0.0387 L/mol
    struct NITROGEN {
        const ld a = 1.370; // L^2bar / mol^2
        const ld b = 0.0387; // L/mol
    }nitrogen;
//    Nitrogen dioxide 	5.354 L^2bar / mol^2 	0.04424 L/mol
    struct NITROGEN_DIOXIDE {
        const ld a = 5.354; // L^2bar / mol^2
        const ld b = 0.04424; // L/mol
    }nitrogenDioxide;
//    Nitrous oxide 	3.832 L^2bar / mol^2 	0.04415 L/mol
    struct NITROUS_OXIDE {
        const ld a = 3.832; // L^2bar / mol^2
        const ld b = 0.04415; // L/mol
    }nitrousOxide;
//    Oxygen 	1.382 L^2bar / mol^2 	0.03186 L/mol
    struct OXYGEN {
        const ld a = 1.382; // L^2bar / mol^2
        const ld b = 0.03186; // L/mol
    }oxygen;
//    Pentane 	19.26 L^2bar / mol^2 	0.146 L/mol
    struct PENTANE {
        const ld a = 19.26; // L^2bar / mol^2
        const ld b = 0.146; // L/mol
    }pentane;
//    Phosphine 	4.692 L^2bar / mol^2 	0.05156 L/mol
    struct PHOSPHINE {
        const ld a = 4.692; // L^2bar / mol^2
        const ld b = 0.05156; // L/mol
    }phosphine;
//    Propane 	8.779 L^2bar / mol^2 	0.08445 L/mol
    struct PROPANE {
        const ld a = 8.779; // L^2bar / mol^2
        const ld b = 0.08445; // L/mol
    }propane;
//    Radon 	6.601 L^2bar / mol^2 	0.06239 L/mol
    struct RADON {
        const ld a = 6.601; // L^2bar / mol^2
        const ld b = 0.06239; // L/mol
    }radon;
//    Silane 	4.377 L^2bar / mol^2 	0.05786 L/mol
    struct SILANE {
        const ld a = 4.377; // L^2bar / mol^2
        const ld b = 0.05786; // L/mol
    }silane;
//    Silicon tetrafluoride 	4.251 L^2bar / mol^2 	0.05571 L/mol
    struct SILICON_TETRAFLUORIDE {
        const ld a = 4.251; // L^2bar / mol^2
        const ld b = 0.05571; // L/mol
    }siliconTetrafluoride;
//    Sulfur dioxide 	6.803 L^2bar / mol^2 	0.05636 L/mol
    struct SULFUR_DIOXIDE {
        const ld a = 6.803; // L^2bar / mol^2
        const ld b = 0.05636; // L/mol
    }sulfurDioxide;
//    Tin tetrachloride 	27.27 L^2bar / mol^2 	0.1642 L/mol
    struct TIN_TETRACHLORIDE {
        const ld a = 27.27; // L^2bar / mol^2
        const ld b = 0.1642; // L/mol
    }tinTetrachloride;
//    Toluene 	24.38 L^2bar / mol^2 	0.1463 L/mol
    struct TOLUENE {
        const ld a = 24.38; // L^2bar / mol^2
        const ld b = 0.1463; // L/mol
    }toluene;
//    Water 	5.536 L^2bar / mol^2 	0.03049 L/mol
    struct WATER {
        const ld a = 5.536; // L^2bar / mol^2
        const ld b = 0.03049; // L/mol
    }water;
//    Xenon 	4.250 L^2bar / mol^2 	0.05105 L/mol
    struct XENON {
        const ld a = 4.250; // L^2bar / mol^2
        const ld b = 0.05105; // L/mol
    }xenon;
}vanderwaals;


class Thermodynamics :
        public Energy, public Heat
{
private:
    static void countIncrease() { thermodynamics_objectCount += 1; }
    static void countDecrease() { thermodynamics_objectCount -= 1; }
public:
    /**
     * @brief  no argument constructor
     */
    Thermodynamics()
    {
        countIncrease();
    }//end no argument constructor
    /**
     * @brief copy constructor
     */
    Thermodynamics(const Thermodynamics& t)
     : Energy(t), Heat(t) {
        T._celsius = t.T._celsius;
        T._fahrenheit = t.T._fahrenheit;
        T._kelvin = t.T._kelvin;
        T._rankine = t.T._rankine;
        T._mode = t._mode;
        countIncrease();
    }//end copy constructor

    /**
     * #brief move constructor
     */
    Thermodynamics(Thermodynamics&& t) noexcept
    {
        T._fahrenheit = t.T._fahrenheit;
        T._celsius = t.T._celsius;
        T._kelvin = t.T._kelvin;
        T._rankine = t.T._rankine;
        _mode = t._mode;
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
            T._rankine = t.T._rankine;
            _mode = t._mode;
            countIncrease();
        }
        return *this;
    }

    static void show_thermodynamics_objectCount() { std::cout << "\nthermodynamic object count: " << thermodynamics_objectCount << std::endl; }
    static int get_thermodynamics_objectCount() { return thermodynamics_objectCount; }

    /**
     * @brief the first law of thermodynamics
     * @param Q the heat transferred
     * @param W the work done
     * @return the change in the system's internal energy
     */
    static ld firstLaw(ld Q, ld W, bool print = true);

    /**
     * @brief first law of thermodynamics  delta_U = COULOMB - W
     * @param Q is the sum of all heat transfer into and out of the system
     * @param W is the sum of all work done on or by the system
     * @returns delta U, is the change in internal energy U of the system
     */
    static ld changeOfInternalEnergy(ld Q, ld W);

    /**
     * @brief isothermal process, work done is proportional to temperature difference
     * @param T the temperature of the system
     * @param n the number of moles in the system
     * @param Vi the initial volume of the system
     * @param Vf the final volume of the system
     * @return the heat supplied to the system during an isothermal process
     */
    static ld workByIsothermalProcess(
            ld T, ld n, ld Vi, ld Vf, bool print = true);

    /**
     * @brief work by isothermal process
     * @param p  the pressure of the system
     * @param Vi  the initial volume of the system
     * @param Vf  the final volume of the system
     * @param print  print the result
     * @return  the work done by the system during an isothermal process
     */
    static ld workByIsothermalProcess(
            ld p, ld Vi, ld Vf, bool print = true);

    /**
     * @brief temperature of an isothermal process
     * @param n  the number of moles in the system
     * @param W  the work done by the system
     * @param Vi  the initial volume of the system
     * @param Vf  the final volume of the system
     * @param print  print the result
     * @return  the temperature of the system during an isothermal process
     */
    static ld temperatureIsothermalProcess(
            ld n, ld W, ld Vi, ld Vf, bool print = true);

    /**
     * @brief work by isothermal and adiabatic process
     * @param p the pressure of the system
     * @param Vi  the initial volume of the system
     * @param Vf  the final volume of the system
     * @param gamma  the ratio of specific heats
     * @param print  print the result
     * @return  the work done by the system during an isothermal and adiabatic process
     */
    static ld workByIsothermalAdiabaticProcess(
            ld p, ld Vi, ld Vf, ld gamma, bool print = true);

    /**
     * An ideal gas with γ=gamma occupies a volume of V m^3 at T K and p1 Pa
     * pressure and is heated at constant volume until its pressure has
     * reached a point of x times p1. It's then compressed adiabatically until
     * its volume is 1/y V m^3, then cooled at constant volume back to its
     * original temperature T K , and finally allowed to expand isothermally
     * to its original state. This method calculates the work done by the
     * system.
     * @param p1 the initial pressure of the system
     * @param p2 the final pressure of the system
     * @param V1 the initial volume of the system
     * @param V2 the final volume of the system
     * @param T the temperature of the system
     * @param gamma  the ratio of specific heats
     * @param print print the result
     * @return  the work done by the system
     */
    static ld workByIsothermalAdiabaticProcess(
            const ld p1, const ld x, const ld V, const ld y, const ld T,
            const ld gamma, bool print = true)
    {
        auto Wbc = (p1 * V * (x * pow(y, gamma-1.0) - x))/ (1.0 - gamma);
        auto Wcd = (p1 * V * log (y));
        auto Wnet = -(Wbc + Wcd);
        if (print) {
            cout << "the work done by the system during an isothermal adiabatic process is "
            << Wnet << " J" << std::endl;
        }
        return Wnet;
    }



    /**
     * @brief isobaric process, work done
     * @param p the pressure of the system
     * @param Vi the initial volume of the system
     * @param Vf the final volume of the system
     * @return the heat supplied to the system during an isobaric process
     */
    static ld workByIsobaricProcess(const ld p,
                               const ld Vi,
                               const ld Vf,
                               bool print = true)
    {
        auto Q = -p*(Vi - Vf);
         if (print)
             cout << "the heat supplied to the system during an isobaric process is "
             << Q << " J" << std::endl;
         return Q;
    }

    static ld temperatureIsobaricProcess(const ld n,
                                         const ld  Q,
                                         const int degreesOfFreedom,
                                         bool print = true)
    {
        auto Cv = (constants::R.joules * degreesOfFreedom) / 2.0;
        auto Cp = Cv + constants::R.joules;
        auto T = (Q / (n * Cp));
        if (print)
            cout << "the temperature of the system during an isobaric process is "
                 << T << " K" << std::endl;
        return T;
    }

    /**
     * @brief adiabatic process, work done
     * @param lambda the ratio of molar specific heats
     * @param p_i the initial pressure of the system
     * @param p_f the final pressure of the system
     * @param Vi the initial volume of the system
     * @param Vf the final volume of the system
     * @return the heat supplied to the system during an adiabatic process
     */
    static ld workByAdiabaticProcess(const ld lambda,
                                const ld p_i,
                                const ld p_f,
                                const ld Vi,
                                const ld Vf,
                                bool print = true)
    {
        auto Q = (p_f * Vf - p_i * Vi) / (lambda - 1);
        if (print)
            cout << "the heat supplied to the system during an adiabatic process is "
                 << Q << " J" << std::endl;
        return Q;
    }

    /**
     * @brief change in the internal energy of a gas undergoing an isobaric process
     * @param n  the number of moles of gas
     * @param Cv  the molar specific heat at constant pressure
     * @param deltaT  the change in temperature
     * @param print  print the result
     * @return  the change in the internal energy of a gas undergoing an isobaric process
     */
    static ld changeInInternalEnergyAnyProcess(const ld n,
                                                    const ld Cv,
                                                    const ld deltaT,
                                                    bool print = true)
    {
        auto deltaU = n * Cv * deltaT;
        if (print)
            cout << "the change in internal energy of the system is "
                 << deltaU << " J" << std::endl;
        return deltaU;
    }

    /**
     * @brief first law of thermodynamics  delta_U = COULOMB - W
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
    static ld energyLossToEnvironment(const ld Qin, const ld efficiency)
    {
        return Qin * (1.0 - (efficiency / 100));
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
    static vector<ld> systemOfAnswers_workDone_heatTransfer_internalChange(
            const ld mass,
            const ld Ti,
            const ld Tf,
            const ld c,
            const ld density,
            const ld coefLinExp,
            const ld Patm = 1.0)
    {
        const ld v0 = mass / density;
        const ld changeV = 3.0 * coefLinExp * v0 * (Tf - Ti);
        const ld W = Patm * constants::ATM_TO_PASCAL_MULTIPLIER * changeV; // a
        const ld Q = heatEnergy(mass, c, Tf - Ti);
        const ld U = Q - W;
        vector<ld> results = { W, Q, U };
        return results;
    }

    /**
     * @brief calculates the food energy used in doing kJ worth of work at a certain efficiency%
     * @param w total work in kJ
     * @param efficiency efficiency of work done
     * @returns calories used
     */
    static ld caloriesUsed(const ld w, const ld efficiency)
    {
        return kiloJoulesToCalories(w / (efficiency / 100));
    }


    /**
     * @brief using first law of thermodynamics  COULOMB = delta_U + W
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
     * @param efficiency efficiency rating
     * @returns the total heat transfer to environment, usually as heat loss
     */
    static ld heatTransferToEnvironment(const ld W, const ld efficiency)
    {
        return ((1.0 / (efficiency / 100.0)) - 1.0) * W;
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
     * doing steady work in w at an efficiency %
     * @param var either calories(default) or kiloJoules. must use a mode of 'k' if using kJ
     * @param w work rate of person
     * @param efficiency efficiency rate
     * @param mode is 'c' for Calorie mode, use 'k' for kiloJoules input instead
     * @param timeSetting 'm' for minutes 's' of seconds and 'h' for hours 'd' for days
     * @returns how long energy from calories will last
     */
    static ld energyDuration(const ld var,
                             const ld w,
                             const ld efficiency,
                             const char mode = 'c',
                             const char timeSetting = 'm')
    {
        if (mode == 'c')
        {
            if (timeSetting == 's')
            {
                return ((var * 4.184) * 1000.0 * (efficiency / 100.0)) / w;
            }
            if (timeSetting == 'h')
            {
                return (((var * 4.184) * 1000.0 * (efficiency / 100.0)) / w) / 3600.0;
            }
            if (timeSetting == 'm')
            {
                return (((var * 4.184) * 1000.0 * (efficiency / 100.0)) / w) / 60.0;
            }
            if (timeSetting == 'd')
            {
                return (((var * 4.184) * 1000.0 * (efficiency / 100.0)) / w) / 86400.0;
            }
        }

        if (timeSetting == 's')
        {
            return (var * 1000.0 * (efficiency / 100.0)) / w;
        }
        if (timeSetting == 'h')
        {
            return ((var * 1000.0 * (efficiency / 100.0)) / w) / 3600.0;
        }
        if (timeSetting == 'm')
        {
            return ((var * 1000.0 * (efficiency / 100.0)) / w) / 60.0;
        }
        if (timeSetting == 'd')
        {
            return ((var * 1000.0 * (efficiency / 100.0)) / w) / 86400.0;
        }
        return (var * 1000.0 * (efficiency / 100.0)) / w;
    }

    static ld workByIdeaHeatEngine(const ld Qh, const ld Qc, bool print = true)
    {
        const ld W = Qh - Qc;
        if (print)
        {
            cout << "Work done by the engine is: " << W << " kJ" << endl;
        }
        return W;
    }

    /**
     * @brief calculates the carnot efficiency of a process
     * @param Tc absolute temp of cold reservoirs
     * @param Th absolute temp of hot reservoirs
     * @returns Carnot Efficiency
     */
    static ld carnotEfficiency(const ld Tc, const ld Th, bool print = true)
    {
        const ld efficiency = 1.0 - (Tc / Th);
        if (print)
        {
            cout << "Carnot Efficiency is: " << efficiency * 100 << "%" << endl;
        }
        return efficiency;
    }

    /**
     * @brief calculates the work done during a carnot cycle
     * @param Qh  heat transfer to hot reservoir
     * @param Th  absolute temp of hot reservoir
     * @param Tc  absolute temp of cold reservoir
     * @param print  print the results
     * @return work done
     */
    static ld workByCarnotCycle(const ld Qh,
                                const ld Th,
                                const ld Tc,
                                bool print = true)
    {
        const ld W = Qh * (1.0 - (Tc / Th));
        if (print)
        {
            cout << "Work done by Carnot Cycle: " << W << " kJ" << endl;
        }
        return W;
    }

    static ld efficiencyHeatEngine(const ld Qh, const ld Qc, bool print = true)
    {
        const ld efficiency = (Qh - Qc) / Qh;
        if (print)
        {
            cout << "Efficiency: " << efficiency * 100 << "%" << endl;
        }
        return efficiency;
    }

    /**
     * @brief calculates the heat Qh absorbed during the isothermal expansion
     * between two points on a pV diagram Vi and Vf.
     * @param n  number of moles
     * @param T  absolute temperature
     * @param Va  initial volume
     * @param Vb  final volume
     * @param print  print results
     * @return  heat absorbed in kJ
     */
    static ld heatExtractedFromHotReservoir(const ld n,
                                            const ld T,
                                            const ld Va,
                                            const ld Vb, bool print = true)
    {
        const ld Qh = n * constants::R.joules * T * log(Vb / Va);
        if (print)
        {
            cout << "Heat extracted from hot reservoir: " << Qh << " J" << endl;
        }
        return Qh;
    }

    /**
     * @ brief calculates the heat Qc rejected during the isothermal
     * compression between two points on a pV diagram Vi and Vf.
     * @param n number of moles
     * @param T absolute temperature
     * @param Vi initial volume
     * @param Vf final volume
     * @param print print results
     * @return heat rejected in kJ
     */
    static ld heatRejectedToColdReservoir(const ld n,
                                          const ld T,
                                          const ld Vc,
                                          const ld Vd, bool print = true)
    {
        const ld Qc = n * constants::R.joules * T * log(Vc / Vd);
        if (print)
        {
            cout << "Heat rejected to cold reservoir: " << Qc << " J" << endl;
        }
        return Qc;
    }

    /**
     * @brief calculates the energy efficiency rating of a system (EER)
     * @param Qc amount of heat transfer from a cold environment in BTU's(British thermal units)
     * @param t1 time in hours
     * @param W work input in Joules
     * @param t2 time in seconds
     * @returns the EEF of a product such as a AC or Refrigerator
     */
    static ld energyEfficiencyRating(const ld Qc,
                                     const ld t1,
                                     const ld W,
                                     const ld t2)
    {
        return (Qc / t1) / (W / t2);
    }

    /**
     * @brief calculates the energy efficiency of a engine cycle of n moles of
     * gas with a cold reservoir at Tc and a hot reservoir at Th and a volume
     * starting at Va and moving through Vb and Vc and ending at Vd
     * @param Tc absolute temp of cold reservoir
     * @param Th  absolute temp of hot reservoir
     * @param Va initial volume
     * @param Vb second state volume
     * @param Vc  third state volume
     * @param Vd  final volume
     * @param n  number of moles
     * @param print  print results
     * @return  energy efficiency of the engine cycle
     */
    static ld engineEfficiency(
            const ld Tc, const ld Th, const ld Va, const ld Vb, const ld Vc,
            const ld Vd, const ld n, bool print = true)
    {
        const ld Qh = heatExtractedFromHotReservoir(n, Th, Va, Vb);
        const ld Qc = heatRejectedToColdReservoir(n, Tc, Vc, Vd);
        const ld efficiency = efficiencyHeatEngine(Qh, Qc);
        if (print)
        {
            cout << "Efficiency: " << efficiency * 100 << "%" << endl;
        }
        return efficiency;
    }
    /**
     * @brief Imagine an ideal (Carnot) refrigerator that keeps soda bottles
     * chilled to a temperature of about Tc K. The refrigerator is located in
     * a hot room with a temperature of about Th K. Because of the imperfect
     * insulation, W J of heat is absorbed by the refrigerator in t s. How
     * much electrical energy E must be used by the refrigerator to maintain the
     * temperature of Tc K inside for tf s?
     * @param Tc  temperature of the cold reservoir
     * @param Th  temperature of the hot reservoir
     * @param W  heat absorbed by the refrigerator
     * @param t  time in seconds that the refrigerator is running and
     * absorbing heat of W J
     * @param tf  time in seconds for the refrigerator to maintain the temperature
     * @param print  print results
     * @return  energy in Joules
     */
    static ld energyUsedByRefrigerator(
            const ld Tc, const ld Th, const ld W, const ld t, const ld tf,
            bool print = true)
    {
        auto dT = Th - Tc;
        auto COP_r = Tc / dT;
        auto P = W / t;
        auto P_r = P / COP_r;
        auto E = P_r * tf;
        if (print)
        {
            cout << "Energy used by refrigerator: " << E << " J" << " to maintain "
                 << Tc << " K for " << tf << " s" << endl;
        }
        return E;
    }

    /**
     * @brief calculates the change in entropy for a reversible process {(S)rev}
     * (S)rev = COULOMB/T
     * @param Q is the heat transfer necessary to change forms of an object
     * @param Th is the temperature it takes in kelvin to change an objects
     * forms
     * @returns entropy
     */
    static ld changeInEntropy(const ld Q,
                              const ld Th,
                              bool print = true,
                              bool isAbsorbed = false)
    {
        auto S = Q / Th;
        if (!isAbsorbed)
            S *= -1;
        if (print)
        {
            cout << "Change in entropy: " << S << " J/K" << endl;
        }
        return S;
    }

    static ld changeInEntropyIdealGasConstantVolume(const ld n,
                                                    const ld T1,
                                                    const ld T2,
                                                    const ld Cv,
                                                    bool print = true)
    {
        const ld S = n * Cv * log(T2 / T1);
        if (print)
        {
            cout << "Change in entropy: " << S << " J/K" << endl;
        }
        return S;
    }
    static ld changeInEntropyIdealGasConstantPressure(const ld n,
                                                      const ld T1,
                                                      const ld T2,
                                                      const ld Cp,
                                                      bool print = true)
    {
        const ld S = n * Cp * log(T2 / T1);
        if (print)
        {
            cout << "Change in entropy: " << S << " J/K" << endl;
        }
        return S;
    }

    static ld changeInEntropyIdealGasAdiabatic(const ld V1,
                                               const ld V2,
                                               const ld Cp,
                                               const ld Cv,
                                               bool print = true)
    {
        if (print)
            cout << "Change in entropy: " << 0 << " J/K" << endl;
        return 0;
    }

    static ld changeInEntropy(const ld n,
                              const ld Va,
                              const ld Vb,
                              bool print = true,
                              bool isAbsorbed = false)
    {
        auto S = n * constants::R.joules * log(Vb / Va);
        if (!isAbsorbed)
            S *= -1;
        if (print)
        {
            cout << "Change in entropy: " << S << " J/K" << endl;
        }
        return S;
    }

    /**
     * @brief calculate the change in entropy of a system during a reversible
     * process.
     * @param m mass of the system
     * @param Ti  initial temperature
     * @param Tf  final temperature
     * @param c  specific heat capacity
     * @param print  print results
     * @return  change in entropy
     */
    static ld changeInEntropyOfSubstance(const ld m,
                                         const ld Ti,
                                         const ld Tf,
                                         const ld c,
                                         bool print = true)
    {
        const ld S = m * c * log(Tf / Ti);
        if (print)
        {
            cout << "Change in entropy: " << S << " J/K" << endl;
        }
        return S;
    }

    /**
     * @brief calculates the change in entropy of a thawing pond
     * @param m mass of the pond
     * @param Th  initial temperature
     * @param print  print results
     * @return  change in entropy
     */
    static ld entropyIncreaseOfThawingPond(const ld m,
                                           const ld Th,
                                           bool print = true)
    {
        const ld Lf = LF.water.J_kg;
        const ld S1 = changeInEntropy(m * Lf, Th, false, true);
        auto c = SHC.waterLiquid.J_kgC;
        const ld S2 = changeInEntropyOfSubstance(m, 273, Th, c);
        const ld S = S1 + S2;
        if (print)
        {
            cout << "Change in entropy: " << S << " J/K" << endl;
        }
        return S;
    }

    /**
     * @brief In a well-insulated calorimeter, m_w kg of water at T_w ∘C is
     * mixed with m_i of ice at 0 ∘C. Calculate the net change in entropy of
     * the system from the time of mixing until the ice melts.
     * @param m_w mass of water
     * @param T_w temperature of water in kelvin
     * @param m_i mass of ice
     * @param print print results
     * @return change in entropy
     */
    static ld entropyIncreaseOfMeltingIce(const ld m_w,
                                          const ld T_w,
                                          const ld m_i,
                                          bool print = true)
    {
        auto Lf = LF.water.J_kg;
        auto Q = Heat::heatOfTransformation(m_i, Lf, false);
        cout << "Heat of transformation: " << Q << " J" << endl;
        auto Sice = changeInEntropy(Q, 273.0, false, true);
        cout << "Sice: " << Sice << endl;
        auto Swater = changeInEntropy(Q, T_w, false, false);
        cout << "Swater: " << Swater << endl;
        auto S = Sice + Swater;
        if (print)
        {
            cout << "Change in entropy: " << S << " J/K" << endl;
        }
        return S;
    }

    /**
     * @brief  calculates the difference of internal pressure if it was at zero gauge pressure
     * @param atmP atm or pascals for pressure
     * @param vol liters default use 'm' for meters cubed as a volume
     * @param mode default 'l' for liters 'm' is meters cubed as a volume measurement
     * @returns the difference the internal energy would need to be
     */
    static ld differenceOfGaugePressureToZeroGaugePressure(const ld atmP,
                                                           const ld vol,
                                                           const char mode = 'l')
    {
        if (mode == 'l')
        {
            const ld U2 = 1.5 * (101325.0) * (vol / 1000.0);
            cout << "u2: " << U2 << endl;
            const ld U1 = ((1.0 + atmP) / (1.0)) * U2;
            cout << "u1: " << U1 << endl;
            return U1 - U2;
        }
        else {
            const ld U2 = 1.5 * (101325.0) * (vol);
            cout << "u2: " << U2 << endl;
            const ld U1 = ((atmP) / (101325.0)) * U2;
            return U1 - U2;
        }
    }

    /**
     * @brief calculates the hot reservoir of a carnot engine
     * @param eff efficiency %
     * @param coldResTempCelsius
     * @returns the temp in celsius of the Hot Reservoir
     */
    static ld carnotEngineHotReservoir(const ld efficiency,
                                       const ld coldResTempCelsius,
                                       bool print = true)
    {
        auto Tc = TemperatureConversions::k2c(
                TemperatureConversions::c2k(coldResTempCelsius) /
                (1.0 - (efficiency/100.0)));
        if (print)
        {
            cout << "Hot Reservoir Temperature: " << Tc << " C" << endl;
        }
        return Tc;
    }

    /**
     * @brief calculates the coefficient of performance
     */
    static ld coefficientOfPerformance(const ld Q, const ld W, bool print = true)
    {
        const ld COP = Q / W;
        if (print)
        {
            cout << "COP: " << COP << endl;
        }
        return COP;
    }

    static ld cop(const ld Tc, const ld Th, bool print = true)
    {
        auto COP = Tc / (Th - Tc);
        if (print)
        {
            cout << "COP: " << COP << endl;
        }
        return COP;
    }

    /**
     * @brief calculates the cold reservoir of a carnot engine
     * @param efficiency efficiency %
     * @param hotResTempCelsius
     * @returns the temp in celsius of the Hot Reservoir
     */
    static ld carnotEngineColdReservoir(const ld efficiency,
                                        const ld hotResTempCelsius,
                                        bool print = true)
    {
        auto Tc = TemperatureConversions::k2c(
                (1.0 - (efficiency / 100.0)) *
                TemperatureConversions::c2k(hotResTempCelsius));
        if (print)
        {
            cout << "Cold Reservoir Temperature: " << Tc << " C" << endl;
        }
        return Tc;
    }

    /**
     * @brief calculates the chance in volume with a constant pressure is maintained
     * @param kPa pressure in kilo pascals
     * @param Qin total work ii
     */
    static ld changeInVolumeConstantPressure(const ld kPa,
                                             const ld Qin,
                                             const ld Qchange)
    {
        return (Qin - Qchange) / kPa;
    }

    /**
     * @brief monoatomic ideal gas internal energy change
     */
    static ld monatomicInternalEnergyChange(const ld Vi,
                                             const ld Vf,
                                             const ld pressureConstant)
    {
        return (pressureConstant * (Vf - Vi)) / (constants::ATOMIC_MASS_UNIT - 1);
    }
    /**
     * @brief calculates the work done during an isobaric process
     * @param gP gauge pressure supplied
     * @param A cross sectional area of piston head A = pi*radius^2
     * @param d is the distance it travels
     * @returns work in J
     */
    static ld work_isobaricProcessOnPiston(const ld gP,
                                           const ld A,
                                           const ld d)
    {
        return gP * A * d;
    }

    static ld criticalPressure(const ld a, const ld b, bool print = true)
    {
        auto cp = a/(27.0*(b*b));
        if (print)
            cout << "Critical Pressure: " << cp << " kPa" << endl;
        return cp;
    }

    /**
     * @brief van der Waals equation for calculating the gas pressure
     * @param n is the number of moles in the gas
     * @param T is the temperature in Kelvin
     * @param V is the molar volume in m^3/mol
     * @param b is the vanderwaals constant b
     * @param a is the vanderwaals constant a
     * @param R is the gas constant R
     *@returns the gas pressure in Pa
     */
    static ld vanDerWaalsPressure(const ld n,
                                  const ld T,
                                  const ld V,
                                  const ld b,
                                  const ld a,
                                  bool print = true)
    {
        const ld R = constants::R.joules;
        auto P = ((n * R * T) / (V - (n * b))) - ((n * n * a) / (V * V));
        if (print)
            std::cout << "The gas pressure is: " << P << " Pa\n";
        return P;
    }


    static ld vanDerWaalsInternalEnergy(const ld f,
                                        const ld T,
                                        const ld n,
                                        const ld a,
                                        const ld V,
                                        bool print = true)
    {
        auto U = (1.0/2.0) * f * n * (T * constants::R.joules) -
                ((n*n) * a) / V;
        if (print)
            std::cout << "The internal energy is: " << U << " J\n";
        return U;
    }

        /**
         * @brief calculates the power in watts (joles per second)
         * @param Q  is the heat transfered in joules
         * @param t  is the time in seconds
         * @param print  prints the result
         * @return  the power in watts
         */
    static ld thermodynamicPower(const ld Q, const ld t, bool print = true)
    {
        auto P = Q / t;
        if (print)
            std::cout << "The thermodynamic power is: " << P << " W\n";
        return P;
    }

    /**
     * @brief Consider an ideal gas at 27.0 degrees Celsius and 1.00-atmosphere
     * pressure.Imagine the molecules to be uniformly spaced, with each molecule
     * at the center of a small cube. What is the length L of an edge if each
     * small cube if adjacent cubes touch but don't overlap? Calculate the
     * length L of an edge of each small cube if adjacent cubes touch but don't
     * overlap.
     * @param T is the temperature in celsius
     * @param P is the pressure in atm
     * @param print prints the result
     * @return the length of an edge of each small cube
     */
    static ld idealGasEdgeLength(const ld T, const ld P, bool print = true)
    {
        const ld R = constants::R.joules;
        const ld N = constants::AVOGADRO;
        const ld Pa = PressureConversions::atm_to_Pa(P);
        const ld Tkelvin = TemperatureConversions::c2k(T);
        const ld V = (R * Tkelvin) / (N * Pa);
        const ld L = pow(V, 1.0/3.0);
        if (print)
            std::cout << "The length of an edge of each small cube is: "
            << L << " m\n";
        return L;
    }

    /**
     * @brief calculates the latent heat of fusion
     * @param m  is the mass of the substance in kg
     * @param Q  is the heat transferred in joules
     * @param print  prints the result
     * @return  the latent heat of fusion in J/kg
     */
    static ld latentHeatOfFusion(const ld m, const ld Q, bool print = true)
    {
        const ld L = Q / m;
        if (print)
            std::cout << "The latent heat of fusion is: " << L << " J/kg\n";
        return L;
    }

    /**
     * @brief calculates the latent heat of vaporization
     * @param m  is the mass of the substance in kg
     * @param Q  is the heat transferred in joules
     * @param print  prints the result
     * @return  the latent heat of vaporization in J/kg
     */
    static ld latentHeatOfVaporization(const ld m, const ld Q, bool print = true)
    {
        const ld L = Q / m;
        if (print)
            std::cout << "The latent heat of vaporization is: " << L << " J/kg\n";
        return L;
    }

    /**
     * @brief determine what a substance is from its heat of vaporization
     * @param Lv is the heat of vaporization in J/kg
     * @param print prints the result
     * @return the substance
     */
    static vector<string> substanceFromHeatOfFusion(const ld Lv,
                                                    bool print = true,
                                                    const ld threshold = 4.0)
    {
        vector<string> substances = {};
        auto elems = LF.elems_kj;
        for (const auto& elem : elems)
        {
            if (abs(elem.second - Lv) < threshold)
            {
                substances.push_back(elem.first);
            }
        }
        if (print)
        {
            if (substances.empty())
            {
                std::cout << "No substances found within threshold\n";
            }
            else
            {
                std::cout << "The substances are: ";
                for (const auto& s : substances)
                {
                    std::cout << s << ", ";
                }
                std::cout << "\n";
            }
        }
        return substances;
    }

    /**
     * @brief determine what process is occuring from the P-V diagram.
     * Options are isothermal, isobaric, isochoric, adiabatic
     * @param P1  is the initial pressure in Pa
     * @param P2  is the final pressure in Pa
     * @param V1  is the initial volume in m^3
     * @param V2  is the final volume in m^3
     * @param print  prints the result
     * @return  the process
     */
    static string determineProcessFromPVdiagram(const ld P1,
                                                const ld P2,
                                                const ld V1,
                                                const ld V2,
                                                bool heatTransferred = false,
                                                bool print = true)
    {
        string process;
        if (P1 == P2)
        {
            process = "isobaric";
        }
        else if (V1 == V2)
        {
            process = "isochoric";
        }
        else if (!heatTransferred)
        {
            process = "adiabatic";
        }
        else
        {
            process = "isothermal";
        }
        if (print)
            std::cout << "The process is: " << process << "\n";
        return process;
    }


    static ld workFromPVdiagram(
            const ld P1, const ld P2, const ld V1, const ld V2, const ld n,
            const ld T, bool heatTransferred, bool isMonoatomic,
            bool print = true)
    {
        auto R = constants::R.joules;
        const string process = determineProcessFromPVdiagram(
                P1, P2, V1, V2, heatTransferred, false);
        ld W = 0.0;
        if (process == "isothermal")
        {
            W = n * R * T * log(V2 / V1);
        }
        else if (process == "isobaric")
        {
            W = P1 * (V2 - V1);
        }
        else if (process == "isochoric")
        {
            W = 0.0;
        }
        else if (process == "adiabatic")
        {
            if (isMonoatomic)
            {
                W = -(3.0/2.0)*(P2*V2 - P1*V1);
            }
            else
            {
                W = -(5.0/2.0)*(P2*V2 - P1*V1);
            }
        }
        if (print)
            std::cout << "The work is: " << W << " J\n";
        return W;
    }
    /**
     * @brief calcuates the molar specific heat capacity of a substance at constant
     * volume - Cv
     * @param C  is the specific heat capacity at constant volume in J/(kg*K)
     * @param molarMass  is the molar mass in kg/mol
     * @param print  prints the result
     * @return  the molar specific heat capacity at constant volume in J/(mol*K)
     */
    static ld molarSpecificHeatCapacity_Cv(const ld C,
                                           const ld molarMass,
                                           bool print = true)
    {
        const ld Cv = C * molarMass;
        if (print)
            std::cout << "The molar specific heat capacity is: "
            << Cv << " J/(mol*K)\n";
        return Cv;
    }
    /**
     * @brief calcuates the molar specific heat capacity of a substance at constant
     * pressure - Cp
     * @param C  is the specific heat capacity at constant pressure in J/(kg*K)
     * @param molarMass  is the molar mass in kg/mol
     * @param print  prints the result
     * @return  the molar specific heat capacity at constant pressure in J/(mol*K)
     */
    static ld molarSpecificHeatCapacity_Cp(const ld C,
                                           const ld molarMass,
                                           bool print = true)
    {
        const ld Cv = C * molarMass;
        const ld Cp = Cv + constants::R.joules;
        if (print)
            std::cout << "The molar specific heat capacity is: "
            << Cp << " J/(mol*K)\n";
        return Cp;
    }
    /**
     * @brief calculates the ratio of the molar specific heat capacities,
     * better known as the gamma value
     * @param Cv  is the molar specific heat capacity at constant volume in J/(mol*K)
     * @param Cp  is the molar specific heat capacity at constant pressure in J/(mol*K)
     * @param print  prints the result
     * @return  the ratio of the molar specific heat capacities
     */
    static ld heatCapacityRatio(const ld Cv, const ld Cp, bool print = true)
    {
        const ld gamma = Cp / Cv;
        if (print)
            std::cout << "The heat capacity ratio is: " << gamma << "\n";
        return gamma;
    }

    /**
     * @brief calculates the final temperature of a monatomic gas from the
     * number of moles (n), the initial temp (Ti), the energy transferred to
     * the gas (Q_in), the work done by the gas (W_out).
     * @param n  is the number of moles in mol
     * @param Ti  is the initial temperature
     * @param Q_in  is the energy transferred to the gas in J
     * @param W_out  is the work done by the gas in J
     * @param print  prints the result
     * @return  the final temperature in K
     */
    static ld finalTemperatureOfMonatomicGas(
            const ld n, const ld Ti, const ld Q_in, const ld W_out,
            bool print = true)
    {
        auto deltaU = Q_in - W_out;
        auto R = constants::R.joules;
        const ld Tf = Ti + (deltaU / (n * (3.0/2.0) * R));
        if (print)
            std::cout << "The final temperature is: " << Tf << " K\n";
        return Tf;
    }

    static ld pressure2AdiabaticProcess(
            const ld gamma, const ld P1, const ld V1, const ld V2,
            bool print = true)
    {
        const ld P2 = P1 * pow(V1 / V2, gamma);
        if (print)
            std::cout << "The final pressure is: " << P2 << " Pa\n";
        return P2;
    }

    static ld volume2AdiabaticProcess(
            const ld gamma, const ld P1, const ld P2, const ld V1,
            bool print = true)
    {
        const ld V2 = V1 * pow(P1 / P2, 1.0 / gamma);
        if (print)
            std::cout << "The final volume is: " << V2 << " m^3\n";
        return V2;
    }

    /**
     * @brief calculates the missing temperature of an adiabatic process when
     * you know pressure P1 and its temp T1 and you know the final pressure
     * P2 and need to find the final temp T2
     * @param P1  is the initial pressure in Pa
     * @param P2  is the final pressure in Pa
     * @param T1  is the initial temperature in K
     * @param print  prints the result
     * @return  the final temperature in K
     */
    static ld temperature2AdiabaticProcess(
            const ld P1, const ld P2, const ld T1, bool print = true)
    {
        const ld T2 = (T1 * P2) / P1;
        if (print)
            std::cout << "The final temperature is: " << T2 << " K\n";
        return T2;
    }

    /**
     * @brief how much water starting at 0 can a freezer freeze in t seconds
     * if the freezer has an inner temp of Tc and discharges heat to the
     * surrounding environment at Th. It consumes electrical power at a rate
     * of P.
     * @param t
     * @param Tc
     * @param Th
     * @param P
     * @param print
     * @return
     */
    static ld howMuchWaterCanFreezerFreezeInTime(
            const ld t, const ld Tc, const ld Th, const ld P, bool print = true)
    {
        auto Lf = LF.water.J_kg;
        auto cop = Thermodynamics::cop(Tc, Th);
        auto W = P * t;
        auto Qc = W * cop;
        auto m = Qc / Lf;
        if (print)
            std::cout << "The amount of water that can be frozen is: "
            << m << " kg\n";
        return m;
    }

    /**
     * brief An oven loses energy at the rate of pLoss W per ∘C temperature
     * difference between its interior and the Tk ∘C temperature of the kitchen.
     * Calculate what the average power must be supplied to maintain the oven
     * at a temperature of Tc ∘C.
     * @param Tc is the temperature of the oven in K
     * @param Tk is the temperature of the kitchen in K
     * @param pLoss is the power loss in W
     * @param print prints the result
     * @return  the power in W
     */
    static ld powerToMaintainOvenTemperature(
            const ld Tc, const ld Tk, const ld pLoss, bool print = true)
    {
        auto deltaT = Tc - Tk;
        auto P = pLoss * deltaT;
        if (print)
            std::cout << "The power is: " << P << " W\n";
        return P;
    }

    static ld idealGasVolume(const ld n, const ld pb, const ld tb){
        return n * constants::R.joules * tb / pb;
    }

    /**
     * @brief A diver observes a bubble of air rising from the bottom of a lake
     * (where the absolute pressure is pb atm) to the surface (where the
     * pressure is ps atm). The temperature at the bottom is Tb ∘C, and the
     * temperature at the surface is Ts ∘C. Calculate the ratio of the
     * volume of the bubble as it reaches the surface ( Vs ) to its volume at
     * the bottom ( Vb ).
     * @param pb is the pressure at the bottom in atm
     * @param ps is the pressure at the surface in atm
     * @param Tb is the temperature at the bottom in K
     * @param Ts is the temperature at the surface in K
     * @param print prints the result
     * @return  the ratio of the volume of the bubble as it reaches the surface
     */
    static ld ratioOfBubbleVolumeAtSurface(
            const ld pb, const ld ps, const ld Tb, const ld Ts,
            bool print = true)
    {
        // convert the temperatures to kelvin
        auto TbK = Tb + 273.15;
        auto TsK = Ts + 273.15;
        auto Vb = Thermodynamics::idealGasVolume(1, pb, TbK);
        auto Vs = Thermodynamics::idealGasVolume(1, ps, TsK);
        auto ratio = Vs / Vb;
        if (print) {
            std::cout << "The ratio of the volume of the bubble as it reaches "
                      << "the surface is: " << ratio << "\n";
        }
        return ratio;
    }

    /**
     * @brief A vol L flask is initially open in a room containing air at Pi atm
     * and Ti ∘C. The flask is then closed and immersed in boiling water. When
     * the air in the flask has reached thermodynamic equilibrium, the flask is
     * opened and air is allowed to escape. The flask is then closed and cooled
     * back to Ti ∘C.
     * Calculate the maximum pressure reached in the flask.
     * Calculate the number of moles tht escape from the flask when it is opened.
     * Calculate the final pressure in the flask.
     * @param vol is the volume of the flask in L
     * @param Pi is the initial pressure in atm
     * @param Ti is the initial temperature in K
     * @param print prints the result
     * @return  the maximum pressure reached in the flask, the number of
     * moles, and the final pressure in the flask
     */
    static vector<ld> flaskInBoilingWaterData(
            ld vol, ld Pi, ld Ti, bool print = true);

    /**
     * @brief A thin partition divides a thermally insulated vessel into a lower
     * compartment of volume V m^3 and an upper compartment of volume x*V m^3.
     * The lower compartment contains some number of moles of an ideal gas;
     * the upper part is evacuated. When the partition is removed, the gas
     * expands and fills both compartments. How many moles n of gas were
     * initially contained in the lower compartment if the entropy change of
     * the gas in this free-expansion process is S J/K?
     * @param V is the volume of the lower compartment in m^3
     * @param x is the ratio of the upper compartment to the lower compartment
     * @param S is the entropy change in J/K
     * @param print prints the result
     * @return  the number of moles of gas initially contained in the lower
     */
    static ld molesOfGasInLowerCompartment(
            ld V, ld x, ld S, bool print = true);

    /**
     * @brief Melting a block of substance already at its melting point results
     * in an entropy increase of S J/K . Calculate the mass of the block.
     * @param S is the entropy change in J/K
     * @param substance is the substance
     * @param print prints the result
     * @return  the mass of the block
     */
    static ld massOfBlock(
            ld S, const string& substance, bool print = true);

    /**
     * @brief destructor
     */
    ~Thermodynamics() {
        countDecrease();
    }
};
#endif //PHYSICSFORMULA_THERMODYNAMICS_H
//*************************  Method Definitions  *****************************//
ld Thermodynamics::massOfBlock(const ld S, const string &substance, bool print)
{
    auto boilingPoint = round(getMeltingPoint(substance));
    auto Lf = getLatentHeatFusion(substance);
    auto mass = (S * boilingPoint) / (Lf);
    if (print) {
        std::cout << "The mass of the block is: " << mass << " kg\n";
    }
    return mass;
}

ld Thermodynamics::molesOfGasInLowerCompartment(
        const ld V, const ld x, const ld S, bool print)
{
    auto vf = (V * x) + V;
    auto n = S / (constants::R.joules * log(vf / V));
    if (print) {
        std::cout << "The number of moles of gas initially contained in "
                  << "the lower compartment is: " << n << " moles\n";
    }
    return n;
}

vector<ld>
Thermodynamics::flaskInBoilingWaterData(
        const ld vol, const ld Pi, const ld Ti,  bool print)
{
    // convert pressure to pascals
    auto PiPa = Pi * 101325;
    // convert temperature to kelvin
    auto TiK = Ti + 273.15;
    // temp of boiling water
    auto TbK = 373.15;
    // get the number of moles
    auto n = numberMoles_idealGasLaw(PiPa, vol, TiK);
    // get the maximum pressure (nRT/V = P)
    auto Pmax = (n * constants::R.joules * TbK) / vol;
    // convert to atm
    Pmax /= 101325;
    // get the moles that escapes when the flask is opened
    auto n2 = numberMoles_idealGasLaw(PiPa, vol, TbK);
    auto n2f = n - n2;
    // get the final pressure
    auto Pf = (n2 * constants::R.joules * TiK) / vol;
    cout << "The final pressure reached in the flask is: " << Pf
         << " Pascals\n";
    // convert to atm
    Pf /= 101325;
    if (print) {
        std::cout << "The maximum pressure reached in the flask is: "
                  << Pmax << " atm\n";
        std::cout << "The number of moles that escape from the flask "
                  << "when it is opened is: " << n2f << " moles\n";
        std::cout << "The final pressure in the flask is: " << Pf
                  << " atm\n";
    }
    return {Pmax, n2, Pf};
}

ld Thermodynamics::firstLaw(const ld Q, const ld W, bool print)
{
    ld E = Q + W;
    if (print)
        cout << "the change in the system's internal energy is "
             << E << " J" << std::endl;
    return E;
}

ld Thermodynamics::changeOfInternalEnergy(const ld Q, const ld W)
{
    return Q - W;
}

ld Thermodynamics::workByIsothermalProcess(
        const ld T, const ld n, const ld Vi, const ld Vf, bool print)
{
    auto Q = (n * constants::R.L_atm * T * log(Vi / Vf));
    if (print)
        cout << "the heat supplied to the system during an isothermal process is "
             << Q << " J" << std::endl;
    return Q;
}

ld Thermodynamics::workByIsothermalProcess(
        const ld p, const ld Vi, const ld Vf,  bool print)
{
    auto Q = ((p * Vf) * log(Vf / Vi));
    if (print) {
        cout << "the heat supplied to the system during an isothermal process is "
             << Q << " J" << std::endl;
    }
    return Q;
}

ld Thermodynamics::temperatureIsothermalProcess(
        const ld n, const ld W, const ld Vi, const ld Vf, bool print)
{
    auto T = (W / (n * constants::R.joules * log(Vi / Vf)));
    if (print)
        cout << "the temperature of the system during an isothermal process is "
             << T << " K" << std::endl;
    return T;
}

ld Thermodynamics::workByIsothermalAdiabaticProcess(
        const ld p, const ld Vi, const ld Vf, const ld gamma, bool print)
{
    auto p2 = pressure2AdiabaticProcess(gamma, p, Vi, Vf);
    auto Wad = workByAdiabaticProcess(gamma, p, p2, Vi, Vf);
    auto Wiso = workByIsothermalProcess(p, Vf, Vi);
    auto W = Wad - Wiso;
    if (print) {
        cout << "the work done by the system during an isothermal adiabatic process is "
             << W << " J" << std::endl;
    }
    return W;
}
