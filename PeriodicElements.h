//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_PERIODICELEMENTS_H
#define PHYSICSFORMULA_PERIODICELEMENTS_H
#pragma once

/**
 * @struct Elements
 * @details structure holding data on all the periodic elements
 * @author Ryan Zurrin
 * @date   1/1/2021
 */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <iomanip>

const int   screenSize_X = 640;
const int   screenSize_Y = 480;

static struct AtomicMass
{
    const long double kg = 1.66053906660 * 50 * pow(10, -27);
    const long double Mu = 1.0;
    const long double Me = 1822.888486209 * 53;
} am;
/// <summary>
/// The periodic table, also known as the periodic table of elements, is a
/// tabular display of the chemical elements, which are arranged by atomic
/// number, electron configuration, and recurring chemical properties.
/// The structure of the table shows periodic trends.\n\n
/// atomic_weight: The atomic mass is the mass of an atom. Although the SI unit
/// of mass is kilogram, the atomic mass is often expressed in the non-SI unit
/// dalton where 1 dalton is defined as 1⁄12 of the mass of a single
/// carbon-12 atom, at rest.\n\n
/// atomic_number: The atomic number or proton number (symbol Z_) of a chemical
/// element is the number of protons found in the nucleus of every atom of
/// that element. The atomic number uniquely identifies a chemical element.
/// It is identical to the charge number of the nucleus. In an uncharged atom,
/// the atomic number is also equal to the number of electrons.\n\n
/// density_STP: Density is a measure of an element's mass per unit volume.\n\n
/// melting_point: Melting point, temperature at which the solid and liquid forms
/// of a pure substance can exist in equilibrium. ... As heat is applied to a
/// solid, its temperature will increase until the melting point is reached.
/// More heat then will convert the solid into a liquid with no temperature change.\n\n
/// boiling_point: The boiling point of a substance is the temperature at which
/// the vapor pressure of a liquid equals the pressure surrounding the liquid
/// and the liquid changes into a vapor. ... The standard boiling point has
/// been defined by IUPAC since 1982 as the temperature at which boiling
/// occurs under a pressure of one bar.\n\n
/// thermal_conductivity: The heat transfer characteristics of a solid material
/// are measured by a property called the thermal conductivity, k (or λ),
/// measured in W/m.K. It is a measure of a substance's ability to transfer
/// heat through a material by conduction.\n\n
/// electric_conductivity: in metals is a result of the movement of electrically
/// charged particles. The atoms of metal elements are characterized by the
/// presence of valence electrons, which are electrons in the outer shell of
/// an atom that are free to move about.\n\n
/// resistivity: (also called specific electrical resistance or volume resistivity)
/// is a fundamental property of a material that measures how strongly it resists
/// electric current. Its inverse, called electrical conductivity, quantifies
/// how well a material conducts electricity.\n\n
/// heat_specific: the quantity of heat required to raise the temperature of one
/// gram of a substance by one Celsius degree. The units of specific heat are
/// usually calories or joules per gram per Celsius degree.\n\n
/// heat_vaporization: The enthalpy of vaporization, also known as the heat of
/// vaporization or heat of evaporation, is the amount of energy that must
/// be added to a liquid substance to transform a quantity of that substance
/// into a gas. The enthalpy of vaporization is a function of the pressure at
/// which that transformation takes place.\n\n
/// heat_fusion: The enthalpy of fusion of a substance, also known as heat of
/// fusion is the change in its enthalpy resulting from providing energy, typically
/// heat, to a specific quantity of the substance to change its state from a
/// solid to a liquid, at constant pressure.\n\n
/// ionization_1st: Ionization energy is the minimum amount of energy required
/// to remove the most loosely bound electron of a neutral atom.
/// </summary>
static struct Elements
{
    Elements() { //cout << "testing Element" << endl;
    };

    /// <summary>
    ///
    /// </summary>
    const struct NEUTRON
    {
        const long double atomic_weight = 1.008665;
        const long double halfLife = 622.2;
        const int atomic_number = 0;
    } n;

    /// <summary>
    /// Hydrogen is the chemical element with the symbol H and atomic number 1.
    /// With a standard atomic weight of 1.008, hydrogen is the lightest element
    /// in the periodic table. Hydrogen is the most abundant chemical substance
    /// in the universe, constituting roughly 75% of all baryonic mass
    /// </summary>
    const struct HYDROGEN
    {
        const int group = 1;
        const string type = "Reactive Nonmetal";
        const string crystal_type = "Hexagonal";
        const string electron_configuration = "1s1";
        const long double atomic_weight = 1.007825; // 1.007825 u (g/mol)
        const int atomic_number = 1; // Z_ = 1
        const vector<long double> energy_levels = {1};
        const long double density_STP = .0899; // .0899 kg/m^3
        const long double melting_point = -259.3; // -259.3 C
        const long double boiling_point = -252.9; // -252.9 C
        const long double thermal_conductivity = .18; // .18 W/mK
        const long double electric_conductivity = FP_NAN; // FP_NAN
        const long double resistivity = FP_NAN; //FP_NAN
        const long double heat_specific = 14300.0; // 14300.0 J/kgK
        const long double heat_vaporization = .452; // 452 kJ/mol
        const long double heat_fusion = .0585; // .558 kJ/mol
        const long double ionization_1st = 13.598;
        static void display()
        {
            displayElementImg(getFileName(1));		}

    } H;

    /// <summary>
    ///	Helium is a chemical element with the symbol He and atomic number 2.
    ///	It is a colorless, odorless, tasteless, non-toxic, inert, monatomic gas,
    ///	the first in the noble gas group in the periodic table. Its boiling point
    ///	is the lowest among all the elements
    /// </summary>
    const struct HELIUM
    {
        const int group = 18;
        const string type = "Noble Gas";
        const string crystal_type = "Hexagonal";
        const string electron_configuration = "1s2";
        const long double atomic_weight = 4.002602; // 4.002602 u (g/mol)
        const int atomic_number = 2; // Z_ = 2
        const vector<long double> energy_levels = {2};
        const long double density_STP = 0.1785; // 0.1785 kg/m^3
        const long double melting_point = FP_NAN; // C
        const long double boiling_point = -268.9; // -269 C
        const long double thermal_conductivity = 0.1513; // 0.1513 W/mK
        const long double electric_conductivity = FP_NAN; // FP_NAN
        const long double resistivity = FP_NAN; // FP_NAN
        const long double heat_specific = 5193.1; // 5193.1 J/kgK
        const long double heat_vaporization = .083; // .083 kJ/mol
        const long double heat_fusion = .02; // .02 kJ/mol
        const long double ionization_1st = 24.587; // eV
        static void display()
        {
            displayElementImg(getFileName(2));
        }
    } He;

    /// <summary>
    ///	Lithium is a chemical element with the symbol LinearMomentum and atomic number 3.
    ///	It is a soft, silvery-white alkali metal. Under standard conditions,
    ///	it is the lightest metal and the lightest solid element.
    /// </summary>
    const struct LITHIUM
    {
        const int group = 1;
        const string type = "Alkali Metal";
        const string crystal_type = "Body-Centered Cubic";
        const string electron_configuration = "[He]2s1";
        const long double atomic_weight = 6.941; // 6.94 u (g/mol)
        const int atomic_number = 3; // Z_ = 3
        const vector<long double> energy_levels = {2, 1};
        const long double density_STP = 535.0; // 535.0 kg/m^3
        const long double melting_point = 180.54; // 180.54 C
        const long double boiling_point = 1342.0; // 1342.0 C
        const long double thermal_conductivity = 85.0; // 85.0 W/mK
        const long double electric_conductivity = 11.0; // 11.0 MS/m
        const long double resistivity = 9.40 * pow(10, -8); // 9.4e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 3570.0; // 3570.0 J/kgK
        const long double heat_vaporization = 147.0; // 147.0 kJ/mol
        const long double heat_fusion = 3.0; // 3.0 kJ/mol
        const long double ionization_1st = 5.391; // eV
        static void display()
        {
            displayElementImg(getFileName(3));
        }
    } Li;

    /// <summary>
    /// Beryllium is a chemical element with the symbol Be and atomic number 4.
    /// It is a relatively rare element in the universe, usually occurring as a
    /// product of the spallation of larger atomic nuclei that have collided
    /// with cosmic rays. Within the cores of stars, beryllium is depleted as
    /// it is fused into heavier elements.
    /// </summary>
    const struct BERYLLIUM
    {
        const int group = 2;
        const string type = "Alkaline Earth Metal";
        const string crystal_type = "Hexagonal";
        const string electron_configuration = "[He]2s2";
        const long double atomic_weight = 9.0121831; // 9.0121831 u (g/mol)
        const int atomic_number = 4; //4
        const vector<long double> energy_levels = {2, 2};
        const long double density_STP = 1848.0; // 1848.0 kg/m^3
        const long double melting_point = 1287; // 1287 C
        const long double boiling_point = 2470; // 2470 C
        const long double thermal_conductivity = 190; // 190 W/mK
        const long double electric_conductivity = 25; // 25 MS/m
        const long double resistivity = 3.999999999998 * pow(10, -8); // 4e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 1820.0; // 1820.0 J/kgK
        const long double heat_vaporization = 297.0; // 297.0 kJ/mol
        const long double heat_fusion = 7.95; // 7.95 kJ/mol
        const long double ionization_1st = 9.323; // eV
        static void display()
        {
            displayElementImg(getFileName(4));
        }
    } Be;

    /// <summary>
    /// Boron is a chemical element with the symbol B and atomic number 5.
    /// Produced entirely by cosmic ray spallation and supernovae and not by
    /// stellar nucleosynthesis, it is a low-abundance element in the Solar
    /// System and in the Earth's crust. It constitutes about 0.001 percent
    /// by weight of Earth's crust.
    /// </summary>
    const struct BORON
    {
        const int group = 13;
        const string type = "Metalloid";
        const string crystal_type = "Rhombohedral";
        const string electron_configuration = "[He]2s2 2p1";
        const long double atomic_weight = 10.81; // 10.81 u (g/mol)
        const int atomic_number = 5; // 5
        const vector<long double> energy_levels = {2, 3}; //add u (g/mol)p to atomic number
        const long double density_STP = 2460.0; // 2460.0 kg/m^3
        const long double melting_point = 2075; // 2075 C
        const long double boiling_point = 4000; // 4000 C
        const long double thermal_conductivity = 27.0; // 27.0W/mK
        const long double electric_conductivity = 1; // MS/m
        const long double resistivity = 10000.0; // 10000 m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 1030.0; // J/kgK
        const long double heat_vaporization = 507.0; // kJ/mol
        const long double heat_fusion = 50.0; // kJ/mol
        const long double ionization_1st = 8.298; // eV
        static void display()
        {
            displayElementImg(getFileName(5));
        }
    } B;

    /// <summary>
    /// Carbon is a chemical element with the symbol C and atomic number 6.
    /// It is nonmetallic and tetravalent—making four electrons available to
    /// form covalent chemical bonds. It belongs to group 14 of the periodic
    /// table. Carbon makes up only about 0.025 percent of Earth's crust.
    /// </summary>
    const struct CARBON
    {
        const int group = 14;
        const string type = "Reactive Nonmetal";
        const string crystal_type = "Diamond";
        const string electron_configuration = "[He]2s2 2p2";
        const long double atomic_weight = 12.011; // u (g/mol)
        const int atomic_number = 6;
        const vector<long double> energy_levels = {2, 4};
        const long double density_STP = 2260.0; // kg/m^3
        const long double melting_point = 3550; // C
        const long double boiling_point = 4027; // C
        const long double thermal_conductivity = 140.0; // W/mK
        const long double electric_conductivity = .10; // MS/m
        const long double resistivity = 0.00001; // 0.00001 m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 710.0; // J/kgK
        const long double heat_vaporization = 715.0; // kJ/mol
        const long double heat_fusion = 105; // kJ/mol
        const long double ionization_1st = 11.261; // eV
        static void display()
        {
            displayElementImg(getFileName(6));
        }
    } C;

    /// <summary>
    /// Nitrogen is the chemical element with the symbol N and atomic number 7.
    /// It was first discovered and isolated by Scottish physician Daniel
    /// Rutherford in 1772.
    /// </summary>
    const struct NITROGEN
    {
        const int group = 15;
        const string type = "Reactive Nonmetal";
        const string crystal_type = "Hexagonal";
        const string electron_configuration = "[He]2s2 2p3";
        const long double atomic_weight = 14.007; // u (g/mol)
        const int atomic_number = 7;
        const vector<long double> energy_levels = {2, 5};
        const long double density_STP = 1.251; // kg/m^3
        const long double melting_point = -210.1; // C
        const long double boiling_point = -195.8; // C
        const long double thermal_conductivity = .025; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; //FP_NAN
        const long double heat_specific = 1040; // J/kgK
        const long double heat_vaporization = 2.79; // kJ/mol
        const long double heat_fusion = .36; // kJ/mol
        const long double ionization_1st = 14.534; // eV
        static void display()
        {
            displayElementImg(getFileName(7));
        }
    } N;

    /// <summary>
    /// Oxygen is the chemical element with the symbol O and atomic number 8.
    /// It is a member of the chalcogen group in the periodic table, a highly
    /// reactive nonmetal, and an oxidizing agent that readily forms oxides with
    /// most elements as well as with other compounds.
    /// </summary>
    const struct OXYGEN
    {
        const int group = 16;
        const string type = "Reactive Nonmetal";
        const string crystal_type = "Simple Cubic";
        const string electron_configuration = "[He]2s2 2p4";
        const long double atomic_weight = 15.999; // u (g/mol)
        const int atomic_number = 8;
        const vector<long double> energy_levels = {2, 6};
        const long double density_STP = 1.251; // kg/m^3
        const long double melting_point = -218.0; // C
        const long double boiling_point = -183.0; // C
        const long double thermal_conductivity = 0.02658; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // FP_NAN
        const long double heat_specific = 919; // J/kgK
        const long double heat_vaporization = 3.41; // kJ/mol
        const long double heat_fusion = .222; // kJ/mol
        const long double ionization_1st = 13.681; // eV
        static void display()
        {
            displayElementImg(getFileName(8));
        }
    } O;

    /// <summary>
    /// Fluorine is a chemical element with the symbol F and atomic number 9.
    /// It is the lightest halogen and exists at standard conditions as a highly
    /// toxic, pale yellow diatomic gas. As the most electronegative element,
    /// it is extremely reactive, as it reacts with all other elements, except
    /// for argon, neon, and helium.
    /// </summary>
    const struct FLUORINE
    {
        const int group = 17;
        const string type = "Reactive Nonmetal";
        const string crystal_type = "Monoclinc";
        const string electron_configuration = "[He]2s2 2p5";
        const long double atomic_weight = 18.998403163; // u (g/mol)
        const int atomic_number = 9;
        const vector<long double> energy_levels = {2, 7};
        const long double density_STP = 1.696; // kg/m^3
        const long double melting_point = -220.0; // C
        const long double boiling_point = -188.1; // C
        const long double thermal_conductivity = .0277; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // FP_NAN
        const long double heat_specific = 824; // J/kgK
        const long double heat_vaporization = 3.27; // kJ/mol
        const long double heat_fusion = .26; // kJ/mol
        const long double ionization_1st = 17.422; // eV
        static void display()
        {
            displayElementImg(getFileName(9));
        }
    } F;

    /// <summary>
    /// Neon is a chemical element with the symbol Ne and atomic number 10.
    /// It is a noble gas. Neon is a colorless, odorless, inert monatomic gas
    /// u (g/mol)nder standard conditions, with about two-thirds the density of air.
    /// </summary>
    const struct NEON
    {
        const int group = 18;
        const string type = "Noble Gas";
        const string crystal_type = "Face-Centered Cubic";
        const string electron_configuration = "[He]2s2 2p6";
        const long double atomic_weight = 20.1797; // u (g/mol)
        const int atomic_number = 10;
        const vector<long double> energy_levels = {2, 8};
        const long double density_STP = .900; // kg/m^3
        const long double melting_point = -248.6; // C
        const long double boiling_point = -246.1; // C
        const long double thermal_conductivity = .0491; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // FP_NAN
        const long double heat_specific = 1030; // J/kgK
        const long double heat_vaporization = 1.75; // kJ/mol
        const long double heat_fusion = 0.34; // kJ/mol
        const long double ionization_1st = 21.565; // eV
        static void display()
        {
            displayElementImg(getFileName(10));
        }
    } Ne;

    /// <summary>
    /// Sodium is a chemical element with the symbol Na and atomic number 11.
    /// It is a soft, silvery-white, highly reactive metal. Sodium is an
    /// alkali metal, being in group 1 of the periodic table. Its only stable
    /// isotope is ²³Na. The free metal does not occur in nature, and must be
    /// prepared from compounds.
    /// </summary>
    const struct SODIUM
    {
        const int group = 1;
        const string type = "Alkali Metal";
        const string crystal_type = "Body-Centered Cubic";
        const string electron_configuration = "[Ne]3s1";
        const long double atomic_weight = 22.98976928; // u (g/mol)
        const int atomic_number = 11;
        const vector<long double> energy_levels = {2, 8, 1};
        const long double density_STP = 968; // kg/m^3
        const long double melting_point = 97.720; // C
        const long double boiling_point = 882.9; // C
        const long double thermal_conductivity = 140.0; // W/mK
        const long double electric_conductivity = 21.0; // MS/m
        const long double resistivity = 4.69999999e-8; // 4.7e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 1230; // J/kgK
        const long double heat_vaporization = 97.7; // kJ/mol
        const long double heat_fusion = 2.60; // kJ/mol
        const long double ionization_1st = 5.139; // eV
        static void display()
        {
            displayElementImg(getFileName(11));
        }
    } Na;

    /// <summary>
    /// Magnesium is a chemical element with the symbol Mg and atomic number 12.
    /// It is a shiny gray solid which bears a close physical resemblance to
    /// the other five elements in the second column of the periodic
    /// </summary>
    const struct MAGNESIUM
    {
        const int group = 2;
        const string type = "Alkaline Earth Metal";
        const string crystal_type = "Hexagonal Close Packed";
        const string electron_configuration = "[Ne]3s2";
        const long double atomic_weight = 24.305; // u (g/mol)
        const int atomic_number = 12;
        const vector<long double> energy_levels = {2, 8, 2};
        const long double density_STP = 1738.0; // kg/m^3
        const long double melting_point = 650; // C
        const long double boiling_point = 1090; // C
        const long double thermal_conductivity = 160.0; // W/mK
        const long double electric_conductivity = 23.0; // MS/m
        const long double resistivity = 4.39999999e-8; // 4.4e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 1020; // J/kgK
        const long double heat_vaporization = 128; // kJ/mol
        const long double heat_fusion = 8.7; // kJ/mol
        const long double ionization_1st = 7.646; // eV
        static void display()
        {
            displayElementImg(getFileName(12));
        }
    } Mg;

    /// <summary>
    /// Aluminium is a chemical element with the symbol Al and atomic number 13.
    /// Aluminium has a density lower than those of other common metals, at
    /// approximately one third that of steel. It has a great affinity towards
    /// oxygen, and forms a protective layer of oxide on the surface when
    /// exposed to air.
    /// </summary>
    const struct ALUMINIUM
    {
        const int group = 13;
        const string type = "Post-Transition Metal";
        const string crystal_type = "Face-Centered Cubic";
        const string electron_configuration = "[Ne]3s2 3p1";
        const long double atomic_weight = 26.9815385; // 26.9815385 u (g/mol)
        const int atomic_number = 13; // 13
        const vector<long double> energy_levels = {2, 8, 3};
        const long double density_STP = 2700; // 2700 kg/m^3
        const long double melting_point = 660.32; // 660.32 C
        const long double boiling_point = 2519.0; // 2519C
        const long double thermal_conductivity = 235; // 235 W/mK
        const long double electric_conductivity = 38.0; // 38 MS/m
        const long double resistivity = 2.6e-8; // 2.6e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 904.0; // 904 J/kgK
        const long double heat_vaporization = 293.0; // 293 kJ/mol
        const long double heat_fusion = 10.7; // 10.7 kJ/mol
        const long double ionization_1st = 5.985; // eV
        static void display()
        {
            displayElementImg(getFileName(13));
        }
    } Al;

    /// <summary>
    /// Silicon is a chemical element with the symbol Si and atomic number 14.
    /// It is a hard, brittle crystalline solid with a blue-grey metallic lustre,
    /// and is a tetravalent metalloid and semiconductor. It is a member of group
    /// 14 in the periodic table: carbon is above it; and germanium, tin, lead
    /// and flerovium, are below it
    /// </summary>
    const struct SILICON
    {
        const int group = 14;
        const string type = "Metalloid";
        const string crystal_type = "Diamond Cubic";
        const string electron_configuration = "[Ne]3s2 3p2";
        const long double atomic_weight = 28.085; // 28.085 u (g/mol)
        const int atomic_number = 14; //14
        const vector<long double> energy_levels = {2, 8, 4};
        const long double density_STP = 2330.0; // 2330 kg/m^3
        const long double melting_point = 1414.0; // 1414 C
        const long double boiling_point = 2900.0; // 2000 C
        const long double thermal_conductivity = 150.0; // 150 W/mK
        const long double electric_conductivity = .0010; // .0010 MS/m
        const long double resistivity = .001; // .001 m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 710.0; // 710 J/kgK
        const long double heat_vaporization = 359.0; // 359 kJ/mol
        const long double heat_fusion = 50.2; // 50.2 kJ/mol
        const long double ionization_1st = 8.151; // eV
        static void display()
        {
            displayElementImg(getFileName(14));
        }
    } Si;

    /// <summary>
    /// Phosphorus is a chemical element with the symbol P and atomic number 15.
    /// Elemental phosphorus exists in two major forms, white phosphorus and
    /// red phosphorus, but because it is highly reactive, phosphorus is never
    /// found as a free element on Earth.
    /// </summary>
    const struct PHOSPHORUS
    {
        const int group = 15;
        const string type = "Reactive Nonmetal";
        const string crystal_type = "Orthorhombic";
        const string electron_configuration = "[Ne]3s2 3p3";
        const long double atomic_weight = 30.973761998; // 30.973761998 u (g/mol)
        const int atomic_number = 15; //15
        const vector<long double> energy_levels = {2, 8, 5};
        const long double density_STP = 1823.0; // 1823 kg/m^3
        const long double melting_point = 44.15; // 44.15 C
        const long double boiling_point = 280.5; // 280.5 C
        const long double thermal_conductivity = .236; // .236 W/mK
        const long double electric_conductivity = 10.0; // 10 MS/m
        const long double resistivity = 1e-7; // 1e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 769.7; // 769.7 J/kgK
        const long double heat_vaporization = 12.4; // 12.4 kJ/mol
        const long double heat_fusion = .64; // .64 kJ/mol
        const long double ionization_1st = 10.487; // eV
        static void display()
        {
            displayElementImg(getFileName(15));
        }
    } P;

    /// <summary>
    /// Sulfur is a chemical element with the symbol S and atomic number 16.
    /// It is abundant, multivalent and nonmetallic. Under normal conditions,
    /// sulfur atoms form cyclic octatomic molecules with a chemical formula S₈.
    /// Elemental sulfur is a bright yellow, crystalline solid at room temperature
    /// </summary>
    const struct SULFUR
    {
        const int group = 16;
        const string type = "Reactive Nonmetal";
        const string crystal_type = "Orthorhombic";
        const string electron_configuration = "[Ne]3s2 3p4";
        const long double atomic_weight = 32.06; // 32.06 u (g/mol)
        const int atomic_number = 16; // 16
        const vector<long double> energy_levels = {2, 8, 6};
        const long double density_STP = 1960.0; // 1960.0 kg/m^3
        const long double melting_point = 115.21; // 115.21 C
        const long double boiling_point = 444.72; // 444.72 C
        const long double thermal_conductivity = .205; // .205 W/mK
        const long double electric_conductivity = pow(1.0, -21); // 1e-21 MS/m
        const long double resistivity = 1e15; // 1e15 m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 705.0; // 705 J/kgK
        const long double heat_vaporization = 9.8; // 9.8 kJ/mol
        const long double heat_fusion = 1.73; // 1.73 kJ/mol
        const long double ionization_1st = 10.36; // eV
        static void display()
        {
            displayElementImg(getFileName(16));
        }
    } S;

    /// <summary>
    /// Chlorine is a chemical element with the symbol Cl and atomic number 17.
    /// The second-lightest of the halogens, it appears between fluorine and
    /// bromine in the periodic table and its properties are mostly intermediate
    /// between them. Chlorine is a yellow-green gas at room temperature.
    /// </summary>
    const struct CHLORINE
    {
        const int group = 17;
        const string type = "Reactive Nonmetal";
        const string crystal_type = "Orthorhombic";
        const string electron_configuration = "[Ne]3s2 3p5";
        const long double atomic_weight = 35.45; // 35.45 u (g/mol)
        const int atomic_number = 17; //17
        const vector<long double> energy_levels = {2, 8, 7};
        const long double density_STP = 3.214; // 3.214 kg/m^3
        const long double melting_point = -101.5; // -101.5 C
        const long double boiling_point = -34.040; // -34.040 C
        const long double thermal_conductivity = .0089; // .0089 W/mK
        const long double electric_conductivity = pow(1.0, -8.0); // 1e-8 MS/m
        const long double resistivity = 100; // 100 m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 478.2; // 478.2 J/kgK
        const long double heat_vaporization = 10.2; // 10.2 kJ/mol
        const long double heat_fusion = 3.2; // 3.2 kJ/mol
        const long double ionization_1st = 12.968; // eV
        static void display()
        {
            displayElementImg(getFileName(17));
        }
    } Cl;

    /// <summary>
    /// Argon is a chemical element with the symbol Ar and atomic number 18.
    /// It is in group 18 of the periodic table and is a noble gas. Argon is
    /// the third-most abundant gas in the Earth's atmosphere, at 0.934%
    /// </summary>
    const struct ARGON
    {
        const int group = 18;
        const string type = "Noble Gas";
        const string crystal_type = "Face-Centered Cubic";
        const string electron_configuration = "[Ne]3s2 3p6";
        const long double atomic_weight = 39.948; // 39.948 u (g/mol)
        const int atomic_number = 18; //18
        const vector<long double> energy_levels = {2, 8, 8};
        const long double density_STP = 1784.0; // 1784 kg/m^3
        const long double melting_point = -189; // -189 C
        const long double boiling_point = -186; // -186 C
        const long double thermal_conductivity = .01772; // .01772 W/mK
        const long double electric_conductivity = FP_NAN; // FP_NAN
        const long double resistivity = FP_NAN; // FP_NAN
        const long double heat_specific = 520.33; // 520.33 J/kgK
        const long double heat_vaporization = 6.5; // 6.5 kJ/mol
        const long double heat_fusion = 1.18; // 1.18 kJ/mol
        const long double ionization_1st = 15.760; // eV
        static void display()
        {
            displayElementImg(getFileName(18));
        }
    } Ar;

    /// <summary>
    /// Potassium is a chemical element with the symbol K and atomic number 19.
    /// Potassium is a silvery-white metal that is soft enough to be cut with a
    /// knife with little force. Potassium metal reacts rapidly with atmospheric
    /// oxygen to form flaky white potassium peroxide in only seconds of exposure.
    /// </summary>
    const struct POTASSIUM
    {
        const int group = 1;
        const string type = "Alkali Metal";
        const string crystal_type = "Body-Centered Cubic";
        const string electron_configuration = "[Ar]4s1";
        const long double atomic_weight = 39.0983; // 39.0983 u (g/mol)
        const int atomic_number = 19; // 19
        const vector<long double> energy_levels = {2, 8, 8, 1};
        const long double density_STP = 856; // 856 kg/m^3
        const long double melting_point = 63.380; // 63.38C
        const long double boiling_point = 758.9; // 758.9C
        const long double thermal_conductivity = 100.0; // 100 W/mK
        const long double electric_conductivity = 14.0; // 14 MS/m
        const long double resistivity = 7.000000000002e-8; // 7.0e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 757; // 757 J/kgK
        const long double heat_vaporization = 76.9; // 76.9 kJ/mol
        const long double heat_fusion = 2.33; // 2.33kJ/mol
        const long double ionization_1st = 4.341; // eV
        static void display()
        {
            displayElementImg(getFileName(19));
        }
    } K;

    /// <summary>
    /// Calcium is a chemical element with the symbol Ca and atomic number 20.
    /// As an alkaline earth metal, calcium is a reactive metal that forms a
    /// dark oxide-nitride layer when exposed to air. ... It is the fifth most
    /// abundant element in Earth's crust, and the third most abundant metal,
    /// after iron and aluminium
    /// </summary>
    const struct CALCIUM
    {
        const int group = 2;
        const string type = "Alkaline Earth Metal";
        const string crystal_type = "Face-Centered Cubic";
        const string electron_configuration = "[Ar]4s2";
        const long double atomic_weight = 40.078; // 40.078 u (g/mol)
        const int atomic_number = 20; // 20
        const vector<long double> energy_levels = {2, 8, 8, 2};
        const long double density_STP = 1550.0; // 1550kg/m^3
        const long double melting_point = 841.9; // 841.9C
        const long double boiling_point = 1484; // 1484 C
        const long double thermal_conductivity = 200.0; //200 W/mK
        const long double electric_conductivity = 29; // 29 MS/m
        const long double resistivity = 3.39999999e-8; // 3.4e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 631; // 631 J/kgK
        const long double heat_vaporization = 155.0; // 155 kJ/mol
        const long double heat_fusion = 8.54; // 8.54 kJ/mol
        const long double ionization_1st = 6.113; // eV
        static void display()
        {
            displayElementImg(getFileName(20));
        }
    } Ca;

    /// <summary>
    /// Scandium is a chemical element with the symbol Sc and atomic number 21.
    /// A silvery-white metallic d-block element, it has historically been
    /// classified as a rare-earth element, together with yttrium and the
    /// lanthanide.
    /// </summary>
    const struct SCANDIUM
    {
        const int group = 3;
        const string type = "Transition Metal";
        const string crystal_type = "Hexagonal Close Packed";
        const string electron_configuration = "[Ar]3d1 4s2";
        const long double atomic_weight = 44.955908; // 44.955908 u (g/mol)
        const int atomic_number = 21; // 21
        const vector<long double> energy_levels = {2, 8, 9, 2};
        const long double density_STP = 2985.0; // 2985 kg/m^3
        const long double melting_point = 1541.0; // 1541 C
        const long double boiling_point = 2830.0; // 2830 C
        const long double thermal_conductivity = 16; // 16W/mK
        const long double electric_conductivity = 1.8; // 1.8 MS/m
        const long double resistivity = 5.5e-7; // 5.5e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 567.0; // 567 J/kgK
        const long double heat_vaporization = 318.0; // 318 kJ/mol
        const long double heat_fusion = 16.0; // 16 kJ/mol
        const long double ionization_1st = 6.562; // eV
        static void display()
        {
            displayElementImg(getFileName(21));
        }
    } Sc;

    /// <summary>
    /// Titanium is a chemical element with the symbol Ti and atomic number 22.
    /// Its atomic weight is 47.867 measured in daltons. It is a lustrous
    /// transition metal with a silver color, low density, and high strength.
    /// Titanium is resistant to corrosion in sea water, aqua regia, and chlorine.
    /// </summary>
    const struct TITANIUM
    {
        const int group = 4;
        const string type = "Transition Metal";
        const string crystal_type = "Hexagonal Close Packed";
        const string electron_configuration = "[Ar]3d2 4s2";
        const long double atomic_weight = 47.867; // 47.867 u (g/mol)
        const int atomic_number = 22; //22
        // energy_levels must add u (g/mol)p to atomic_number
        const vector<long double> energy_levels = {2, 8, 10, 2};
        const long double density_STP = 4507.0; // 4507 kg/m^3
        const long double melting_point = 1668.0; // 1668 C
        const long double boiling_point = 3287.0; // 3287 C
        const long double thermal_conductivity = 22.0; // 22.0 W/mK
        const long double electric_conductivity = 2.5; // 2.5 MS/m
        const long double resistivity = 4e-7; // 4e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 520.0; // 525 J/kgK
        const long double heat_vaporization = 425.0; // 425 kJ/mol
        const long double heat_fusion = 18.7; // 18.7 kJ/mol
        const long double ionization_1st = 6.828; // eV
        static void display()
        {
            displayElementImg(getFileName(22));
        }
    } Ti;

    /// <summary>
    /// Vanadium is a chemical element with the symbol V and atomic number 23.
    /// It is a hard, silvery-grey, malleable transition metal. The elemental
    /// metal is rarely found in nature, but once isolated artificially, the
    /// formation of an oxide layer somewhat stabilizes the free metal against
    /// further oxidation.
    /// </summary>
    const struct VANADIUM
    {
        const int group = 5;
        const string type = "Transition Metal";
        const string crystal_type = "Body-Centered Cubic";
        const string electron_configuration = "[Ar]3d3 4s2";
        const long double atomic_weight = 50.9415; // 50.9415 u (g/mol)
        const int atomic_number = 23; // 23
        const vector<long double> energy_levels = {2, 8, 11, 2};
        const long double density_STP = 6110; // kg/m^3
        const long double melting_point = 1910; // 1910 C
        const long double boiling_point = 3407; // 3407 C
        const long double thermal_conductivity = 31; // 31 W/mK
        const long double electric_conductivity = 5; // MS/m
        const long double resistivity = 2e-7; // 2e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 489; // J/kgK
        const long double heat_vaporization = 453; // kJ/mol
        const long double heat_fusion = 22.8; // kJ/mol
        const long double ionization_1st = 6.746; // eV
        static void display()
        {
            displayElementImg(getFileName(23));
        }
    } V;

    /// <summary>
    /// Chromium is a chemical element with the symbol Cr and atomic number 24.
    /// It is the first element in group 6. It is a steely-grey, lustrous, hard,
    /// and brittle transition metal. Chromium is the main additive in stainless
    /// steel, to which it adds anti-corrosive properties.
    /// </summary>
    const struct CHROMIUM
    {
        const int group = 6;
        const string type = "Transition Metal";
        const string crystal_type = "Face-Centered Cubic";
        const string electron_configuration = "[Ar]3d5 4s1";
        const long double atomic_weight = 51.996; // u (g/mol)
        const int atomic_number = 24; // 24
        const vector<long double> energy_levels = {2, 8, 13, 1};
        const long double density_STP = 7190; // kg/m^3
        const long double melting_point = 1907; // C
        const long double boiling_point = 2671; // C
        const long double thermal_conductivity = 94; // W/mK
        const long double electric_conductivity = 7.9; // MS/m
        const long double resistivity = 1.3e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 448; // J/kgK
        const long double heat_vaporization = 339; // kJ/mol
        const long double heat_fusion = 20.5; // kJ/mol
        const long double ionization_1st = 6.767; // eV
        static void display()
        {
            displayElementImg(getFileName(24));
        }
    } Cr;

    /// <summary>
    /// Manganese is a chemical element with the symbol Mn and atomic number 25.
    /// It is not found as a free element in nature; it is often found in minerals
    /// in combination with iron. Manganese is a transition metal with a
    /// multifaceted array of industrial alloy u (g/mol)ses, particularly in
    /// stainless steels.
    /// </summary>
    const struct MANGANESE
    {
        const int group = 7;
        const string type = "Transition Metal";
        const string crystal_type = "Body-Centered Cubic";
        const string electron_configuration = "[Ar]3d5 4s2";
        const long double atomic_weight = 54.938; // u (g/mol)
        const int atomic_number = 25;
        const vector<long double> energy_levels = {2, 8, 13, 2};
        const long double density_STP = 7470; // kg/m^3
        const long double melting_point = 1246; // C
        const long double boiling_point = 2061; // C
        const long double thermal_conductivity = 7.8; // W/mK
        const long double electric_conductivity = .62; // MS/m
        const long double resistivity = 1.6e-6; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 479; // J/kgK
        const long double heat_vaporization = 220; // kJ/mol
        const long double heat_fusion = 13.2; // kJ/mol
        const long double ionization_1st = 7.434; // eV
        static void display()
        {
            displayElementImg(getFileName(25));
        }
    } Mn;

    /// <summary>
    /// Iron is a chemical element with symbol Fe and atomic number 26.
    /// It is a metal that belongs to the first transition series and group
    /// 8 of the periodic table. It is, by mass, the most common element on
    /// Earth, right in front of oxygen, forming much of Earth's outer and
    /// inner core.
    /// </summary>
    const struct IRON
    {
        const int group = 8;
        const string type = "Transition Metal";
        const string crystal_type = "Body-Centered Cubic";
        const string electron_configuration = "[Ar]3d6 4s2";
        const long double atomic_weight = 55.845; // u (g/mol)
        const int atomic_number = 26;
        const vector<long double> energy_levels = {2, 8, 14, 2};
        const long double density_STP = 7874; // kg/m^3
        const long double melting_point = 1538; // C
        const long double boiling_point = 2861; // C
        const long double thermal_conductivity = 80; // W/mK
        const long double electric_conductivity = 10; // MS/m
        const long double resistivity = 9.7e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 449; // J/kgK
        const long double heat_vaporization = 347; // kJ/mol
        const long double heat_fusion = 13.8; // kJ/mol
        const long double ionization_1st = 7.903; // eV
        static void display()
        {
            displayElementImg(getFileName(26));
        }
    } Fe;

    /// <summary>
    /// Cobalt is a chemical element with the symbol Co and atomic number 27.
    /// Like nickel, cobalt is found in the Earth's crust only in a chemically
    /// combined form, save for small deposits found in alloys of natural meteoric
    /// iron. The free element, produced by reductive smelting, is a hard,
    /// lustrous, silver-gray metal.
    /// </summary>
    const struct COBALT
    {
        const int group = 9;
        const string type = "Transition Metal";
        const string crystal_type = "Hexagonal close-packed";
        const string electron_configuration = "[Ar]3d7 4s2";
        const long double atomic_weight = 58.933; // u (g/mol)
        const int atomic_number = 27;
        const vector<long double> energy_levels = {2, 8, 15, 2};
        const long double density_STP = 8900; // kg/m^3
        const long double melting_point = 1495; // C
        const long double boiling_point = 2900; // C
        const long double thermal_conductivity = 100; // W/mK
        const long double electric_conductivity = 17; // MS/m
        const long double resistivity = 6e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 421; // J/kgK
        const long double heat_vaporization = 375; // kJ/mol
        const long double heat_fusion = 16.2; // kJ/mol
        const long double ionization_1st = 7.881; // eV
        static void display()
        {
            displayElementImg(getFileName(27));
        }
    } Co;

    /// <summary>
    /// Nickel is a chemical element with the symbol Ni and atomic number 28.
    /// It is a silvery-white lustrous metal with a slight golden tinge.
    /// Nickel belongs to the transition metals and is hard and ductile.
    /// </summary>
    const struct NICKEL
    {
        const int group = 10;
        const string type = "Transition Metal";
        const string crystal_type = "Face-Centered Cubic";
        const string electron_configuration = "[Ar]3d8 4s2";
        const long double atomic_weight = 58.693; // u (g/mol)
        const int atomic_number = 28;
        const vector<long double> energy_levels = {2, 8, 16, 2};
        const long double density_STP = 8908.0; // kg/m^3
        const long double melting_point = 1455; // C
        const long double boiling_point = 2913; // C
        const long double thermal_conductivity = 91; // W/mK
        const long double electric_conductivity = 14; // MS/m
        const long double resistivity = 7e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 445; // J/kgK
        const long double heat_vaporization = 378; // kJ/mol
        const long double heat_fusion = 17.2; // kJ/mol
        const long double ionization_1st = 7.641; // eV
        static void display()
        {
            displayElementImg(getFileName(28));
        }
    } Ni;

    /// <summary>
    /// Copper is a chemical element with the symbol Cu and atomic number 29.
    /// It is a soft, malleable, and ductile metal with very high thermal and
    /// electrical conductivity. A freshly exposed surface of pure copper has
    /// a pinkish-orange color.
    /// </summary>
    const struct COPPER
    {
        const int group = 11;
        const string type = "Transition Metal";
        const string crystal_type = "Face-Centered Cubic";
        const string electron_configuration = "[Ar]3d10 4s1";
        const long double atomic_weight = 63.546; // u (g/mol)
        const int atomic_number = 29;
        const vector<long double> energy_levels = {2, 8, 18, 1};
        const long double density_STP = 8940.0; // kg/m^3
        const long double melting_point = 1084.62; // C
        const long double boiling_point = 2562; // C
        const long double thermal_conductivity = 400; // W/mK
        const long double electric_conductivity = 59; // MS/m
        const long double resistivity = 1.7e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 384.4; // J/kgK
        const long double heat_vaporization = 300; // kJ/mol
        const long double heat_fusion = 13.1; // kJ/mol
        const long double ionization_1st = 7.727; // eV
        static void display()
        {
            displayElementImg(getFileName(29));
        }
    } Cu;

    /// <summary>
    /// Zinc is a chemical element with the symbol Zn and atomic number 30.
    /// Zinc is a slightly brittle metal at room temperature and has a
    /// silvery-grayish appearance when oxidation is removed. It is the first
    /// element in group 12 of the periodic table.
    /// </summary>
    const struct ZINC
    {
        const int group = 12;
        const string type = "Transition Metal";
        const string crystal_type = "hexagonal close-packed";
        const string electron_configuration = "[Ar]3d10 4s2";
        const long double atomic_weight = 65.38; // u (g/mol)
        const int atomic_number = 30;
        const vector<long double> energy_levels = {2, 8, 18, 2};
        const long double density_STP = 7140; // kg/m^3
        const long double melting_point = 419.53; // C
        const long double boiling_point = 906.9; // C
        const long double thermal_conductivity = 120; // W/mK
        const long double electric_conductivity = 17; // MS/m
        const long double resistivity = 5.9e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 388; // J/kgK
        const long double heat_vaporization = 119; // kJ/mol
        const long double heat_fusion = 7.35; // kJ/mol
        const long double ionization_1st = 9.394; // eV
        static void display()
        {
            displayElementImg(getFileName(30));
        }
    } Zn;

    /// <summary>
    /// Gallium is a chemical element with the symbol Ga and atomic number 31.
    /// Elemental gallium is a soft, silvery metal at standard temperature and
    /// pressure; however in its liquid state it becomes silvery white. If too
    /// much force is applied, the gallium may fracture conchoidally.
    /// </summary>
    const struct GALLIUM
    {
        const int group = 13;
        const string type = "Post-Transition Metal";
        const string crystal_type = "Orthorhombic";
        const string electron_configuration = "[Ar]3d10 4s2 4p1";
        const long double atomic_weight = 69.723; // u (g/mol)
        const int atomic_number = 31;
        const vector<long double> energy_levels = {2, 8, 18, 3};
        const long double density_STP = 5904.0; // kg/m^3
        const long double melting_point = 29.760; // C
        const long double boiling_point = 2204.0; // C
        const long double thermal_conductivity = 29.0; // W/mK
        const long double electric_conductivity = 7.1; // MS/m
        const long double resistivity = 1.4e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 371.0; // J/kgK
        const long double heat_vaporization = 256.0; // kJ/mol
        const long double heat_fusion = 5.59; // kJ/mol
        const long double ionization_1st = 5.999; // eV
        static void display()
        {
            displayElementImg(getFileName(31));
        }
    } Ga;

    /// <summary>
    /// Germanium is a chemical element with the symbol Ge and atomic number 32.
    /// It is a lustrous, hard-brittle, grayish-white metalloid in the carbon
    /// group, chemically similar to its group neighbors silicon and tin.
    /// Pure germanium is a semiconductor with an appearance similar to
    /// elemental silicon.
    /// </summary>
    const struct GERMANIUM
    {
        const int group = 14;
        const string type = "Metalloid";
        const string crystal_type = "Diamond Cubic";
        const string electron_configuration = "[Ar]3d10 4s2 4p2";
        const long double atomic_weight = 72.630; // u (g/mol)
        const int atomic_number = 32;
        const vector<long double> energy_levels = {2, 8, 18, 4};
        const long double density_STP = 5323; // kg/m^3
        const long double melting_point = 938.25; // C
        const long double boiling_point = 2820; // C
        const long double thermal_conductivity = 60.0; // W/mK
        const long double electric_conductivity = .0020; // MS/m
        const long double resistivity = .0005; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 321.4; // J/kgK
        const long double heat_vaporization = 334.0; // kJ/mol
        const long double heat_fusion = 31.8; // kJ/mol
        const long double ionization_1st = 7.90; // eV
        static void display()
        {
            displayElementImg(getFileName(32));
        }
    } Ge;

    /// <summary>
    /// Arsenic is a chemical element with the symbol As and atomic number 33.
    /// Arsenic occurs in many minerals, u (g/mol)sually in combination with sulfur and
    /// metals, but also as a pure elemental crystal. Arsenic is a metalloid.
    /// </summary>
    const struct ARSENIC
    {
        const int group = 15;
        const string type = "Metalloid";
        const string crystal_type = "Rhombohedral";
        const string electron_configuration = "[Ar]3d10 4s2 4p3";
        const long double atomic_weight = 74.922; // u (g/mol)
        const int atomic_number = 33;
        const vector<long double> energy_levels = {2, 8, 18, 5};
        const long double density_STP = 5727; // kg/m^3
        const long double melting_point = 816.9; // C
        const long double boiling_point = 614; // C
        const long double thermal_conductivity = 50.0; // W/mK
        const long double electric_conductivity = 3.3; // MS/m
        const long double resistivity = 3e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 328.0; // J/kgK
        const long double heat_vaporization = 32.4; // kJ/mol
        const long double heat_fusion = 27.7; // kJ/mol
        const long double ionization_1st = 9.815; // eV
        static void display()
        {
            displayElementImg(getFileName(33));
        }
    } As;

    /// <summary>
    /// Selenium is a chemical element with the symbol Se and atomic number 34.
    /// It is a nonmetal with properties that are intermediate between the
    /// elements above and below in the periodic table, sulfur and tellurium,
    /// and also has similarities to arsenic
    /// </summary>
    const struct SELENIUM
    {
        const int group = 16;
        const string type = "Reactive Nonmetal";
        const string crystal_type = "Hexagonal";
        const string electron_configuration = "[Ar]3d10 4s2 4p4";
        const long double atomic_weight = 78.971; // u (g/mol)
        const int atomic_number = 34;
        const vector<long double> energy_levels = {2, 8, 18, 6};
        const long double density_STP = 4819; // kg/m^3
        const long double melting_point = 221; // C
        const long double boiling_point = 685; // C
        const long double thermal_conductivity = 0; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 321.2; // J/kgK
        const long double heat_vaporization = 26.0; // kJ/mol
        const long double heat_fusion = 5.4; // kJ/mol
        const long double ionization_1st = 9.753; // eV
        static void display()
        {
            displayElementImg(getFileName(34));
        }
    } Se;

    /// <summary>
    /// Bromine is a chemical element with the symbol Br and atomic number 35.
    /// It is the third-lightest halogen, and is a fuming red-brown liquid at
    /// room temperature that evaporates readily to form a similarly coloured
    /// vapour. Its properties are intermediate between those of chlorine
    /// and iodine.
    /// </summary>
    const struct BROMINE
    {
        const int group = 17;
        const string type = "Reactive Nonmetal";
        const string crystal_type = "Orthorhombic";
        const string electron_configuration = "[Ar]3d10 4s2 4p5";
        const long double atomic_weight = 79.904; // u (g/mol)
        const int atomic_number = 35;
        const vector<long double> energy_levels = {2, 8, 18, 7};
        const long double density_STP = 3120; // kg/m^3
        const long double melting_point = -7.350; // C
        const long double boiling_point = 58.9; // C
        const long double thermal_conductivity = 0.12; // W/mK
        const long double electric_conductivity = 1.0e-16; // MS/m
        const long double resistivity = 1.0e10; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 947.3; // J/kgK
        const long double heat_vaporization = 14.8; // kJ/mol
        const long double heat_fusion = 5.8; // kJ/mol
        const long double ionization_1st = 11.814; // eV
        static void display()
        {
            displayElementImg(getFileName(35));
        }
    } Br;

    /// <summary>
    /// Krypton is a chemical element with the symbol Kr and atomic number 36.
    /// It is a colorless, odorless, tasteless noble gas that occurs in trace
    /// amounts in the atmosphere and is often u (g/mol)sed with other rare gases in
    /// fluorescent lamps. With rare exceptions, krypton is chemically inert
    /// </summary>
    const struct KRYPTON
    {
        const int group = 18;
        const string type = "Noble Gas";
        const string crystal_type = "Face-Centered Cubic";
        const string electron_configuration = "[Ar]3d10 4s2 4p6";
        const long double atomic_weight = 83.798; // u (g/mol)
        const int atomic_number = 36;
        const vector<long double> energy_levels = {2, 8, 18, 8};
        const long double density_STP = 3.75; // kg/m^3
        const long double melting_point = -157.36; // C
        const long double boiling_point = -153.22; // C
        const long double thermal_conductivity = 0.00943; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 248.05; // J/kgK
        const long double heat_vaporization = 9.02; // kJ/mol
        const long double heat_fusion = 1.64; // kJ/mol
        const long double ionization_1st = 14.000; // eV
        static void display()
        {
            displayElementImg(getFileName(36));
        }
    } Kr;

    /// <summary>
    /// Rubidium is the chemical element with the symbol Rb and atomic number 37.
    /// Rubidium is a very soft, silvery-white metal in the alkali metal group.
    /// Rubidium metal shares similarities to potassium metal and caesium metal
    /// in physical appearance, softness and conductivity.
    /// </summary>
    const struct RUBIDIUM
    {
        const int group = 1;
        const string type = "Alkali Metal";
        const string crystal_type = "Body-Centered Cubic";
        const string electron_configuration = "[Kr]5s1";
        const long double atomic_weight = 85.468; // u (g/mol)
        const int atomic_number = 37;
        const vector<long double> energy_levels = {2, 8, 18, 8, 1};
        const long double density_STP = 1532; // kg/m^3
        const long double melting_point = 39.310; // C
        const long double boiling_point = 688.0; // C
        const long double thermal_conductivity = 58.0; // W/mK
        const long double electric_conductivity = 8.30; // MS/m
        const long double resistivity = 1.2e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 364; // J/kgK
        const long double heat_vaporization = 72.0; // kJ/mol
        const long double heat_fusion = 2.19; // kJ/mol
        const long double ionization_1st = 4.177; // eV
        static void display()
        {
            displayElementImg(getFileName(37));
        }
    } Rb;

    /// <summary>
    /// Strontium is the chemical element with the symbol Sr and atomic number 38.
    /// An alkaline earth metal, strontium is a soft silver-white yellowish metallic
    /// element that is highly chemically reactive. The metal forms a dark oxide
    /// layer when it is exposed to air.
    /// </summary>
    const struct STRONTIUM
    {
        const int group = 2;
        const string type = "Alkaline Earth Metal";
        const string crystal_type = "Face-Centered Cubic";
        const string electron_configuration = "[Kr]5s2";
        const long double atomic_weight = 87.62; // u (g/mol)
        const int atomic_number = 38;
        const vector<long double> energy_levels = {2, 8, 18, 8, 2};
        const long double density_STP = 2630; // kg/m^3
        const long double melting_point = 776.9; // C
        const long double boiling_point = 1382.0; // C
        const long double thermal_conductivity = 35; // W/mK
        const long double electric_conductivity = 7.7; // MS/m
        const long double resistivity = 1.3e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 300.0; // J/kgK
        const long double heat_vaporization = 137.0; // kJ/mol
        const long double heat_fusion = 8.0; // kJ/mol
        const long double ionization_1st = 5.695; // eV
        static void display()
        {
            displayElementImg(getFileName(38));
        }
    } Sr;

    /// <summary>
    /// Yttrium is a chemical element with the symbol Y_ and atomic number 39.
    /// It is a silvery-metallic transition metal chemically similar to the
    /// lanthanides and has often been classified as a "rare-earth element"
    /// </summary>
    const struct YTTRIUM
    {
        const int group = 3;
        const string type = "Transition Metal";
        const string crystal_type = "Hexagonal Close Packed";
        const string electron_configuration = "[Kr]4d1 5s2";
        const long double atomic_weight = 88.906; // u (g/mol)
        const int atomic_number = 39;
        const vector<long double> energy_levels = {2, 8, 18, 9, 2};
        const long double density_STP = 4472; // kg/m^3
        const long double melting_point = 1526.0; // C
        const long double boiling_point = 3345.0; // C
        const long double thermal_conductivity = 17; // W/mK
        const long double electric_conductivity = 1.80; // MS/m
        const long double resistivity = 5.6e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 298.0; // J/kgK
        const long double heat_vaporization = 380.0; // kJ/mol
        const long double heat_fusion = 11.4; // kJ/mol
        const long double ionization_1st = 6.22; // eV
        static void display()
        {
            displayElementImg(getFileName(39));
        }
    } Y;

    /// <summary>
    /// Zirconium is a chemical element with the symbol Zr and atomic number 40.
    /// The name zirconium is taken from the name of the mineral zircon, the
    /// most important source of zirconium. It is a lustrous, grey-white, strong
    /// transition metal that closely resembles hafnium and, to a lesser
    /// extent, titanium.
    /// </summary>
    const struct ZIRCONIUM
    {
        const int group = 4;
        const string type = "Transition Metal";
        const string crystal_type = "Hexagonal Close Packed";
        const string electron_configuration = "[Kr]4d2 5s2";
        const long double atomic_weight = 91.224; // u (g/mol)
        const int atomic_number = 40;
        const vector<long double> energy_levels = {2, 8, 18, 10, 2};
        const long double density_STP = 6511; // kg/m^3
        const long double melting_point = 1855.0; // C
        const long double boiling_point = 4409.0; // C
        const long double thermal_conductivity = 23; // W/mK
        const long double electric_conductivity = 2.4; // MS/m
        const long double resistivity = 4.2e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 278.0; // J/kgK
        const long double heat_vaporization = 580.0; // kJ/mol
        const long double heat_fusion = 21.0; // kJ/mol
        const long double ionization_1st = 6.634; // eV
        static void display()
        {
            displayElementImg(getFileName(40));
        }
    } Zr;

    /// <summary>
    /// Niobium, also known as columbium,
    /// is a chemical element with the symbol Nb and atomic number 41.
    /// Niobium is a light grey, crystalline, and ductile transition metal.
    /// Pure niobium has a Mohs hardness rating similar to that of pure titanium,
    /// and it has similar ductility to iron.
    /// </summary>
    const struct NIOBIUM
    {
        const int group = 5;
        const string type = "Transition Metal";
        const string crystal_type = "Body-Centered Cubic";
        const string electron_configuration = "[Kr]4d4 5s1";
        const long double atomic_weight = 92.906; // u (g/mol)
        const int atomic_number = 41;
        const vector<long double> energy_levels = {2, 8, 18, 12, 1};
        const long double density_STP = 8570; // kg/m^3
        const long double melting_point = 2477.0; // C
        const long double boiling_point = 4744.0; // C
        const long double thermal_conductivity = 54; // W/mK
        const long double electric_conductivity = 6.7; // MS/m
        const long double resistivity = 1.5e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 265.0; // J/kgK
        const long double heat_vaporization = 690.0; // kJ/mol
        const long double heat_fusion = 26.8; // kJ/mol
        const long double ionization_1st = 6.759; // eV
        static void display()
        {
            displayElementImg(getFileName(41));
        }
    } Nb;

    /// <summary>
    /// Molybdenum is a chemical element with the symbol Mo and atomic number 42.
    /// The name is from Neo-Latin molybdaenum, which is based on Ancient Greek
    /// Μόλυβδος molybdos, meaning lead, since its ores were confused with lead ores.
    /// </summary>
    const struct MOLYBDENUM
    {
        const int group = 6;
        const string type = "Transition Metal";
        const string crystal_type = "Body-Centered Cubic";
        const string electron_configuration = "[Kr]4d5 5s1";
        const long double atomic_weight = 95.95; // u (g/mol)
        const int atomic_number = 42;
        const vector<long double> energy_levels = {2, 8, 18, 13, 1};
        const long double density_STP = 10280; // kg/m^3
        const long double melting_point = 2623.0; // C
        const long double boiling_point = 4639.0; // C
        const long double thermal_conductivity = 139.0; // W/mK
        const long double electric_conductivity = 20.0; // MS/m
        const long double resistivity = 5.0e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 251.0; // J/kgK
        const long double heat_vaporization = 600.0; // kJ/mol
        const long double heat_fusion = 36.0; // kJ/mol
        const long double ionization_1st = 7.092; // eV
        static void display()
        {
            displayElementImg(getFileName(42));
        }
    } Mo;

    /// <summary>
    /// Technetium is a chemical element with the symbol Tc and atomic number 43.
    /// It is the lightest element whose isotopes are all radioactive, none of
    /// which is stable other than the fully ionized state of ⁹⁷Tc. Nearly all
    /// available technetium is produced as a synthetic element.
    /// </summary>
    const struct TECHNETIUM
    {
        const int group = 7;
        const string type = "Transition Metal";
        const string crystal_type = "Hexagonal Close Packed";
        const string electron_configuration = "[Kr]4d5 5s2";
        const long double atomic_weight = (98); // u (g/mol)
        const int atomic_number = 43;
        const vector<long double> energy_levels = {2, 8, 18, 13, 2};
        const long double density_STP = 11500; // kg/m^3
        const long double melting_point = 2157.0; // C
        const long double boiling_point = 4265.0; // C
        const long double thermal_conductivity = 51.0; // W/mK
        const long double electric_conductivity = 5.0; // MS/m
        const long double resistivity = 2.0e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 63.0; // J/kgK
        const long double heat_vaporization = 550.0; // kJ/mol
        const long double heat_fusion = 23.0; // kJ/mol
        const long double ionization_1st = 7.28; // eV
        static void display()
        {
            displayElementImg(getFileName(43));
        }
    } Tc;

    /// <summary>
    /// Ruthenium is a chemical element with the symbol Ru and atomic number 44.
    /// It is a rare transition metal belonging to the platinum group of the
    /// periodic table. Like the other metals of the platinum group, ruthenium
    /// is inert to most other chemicals.
    /// </summary>
    const struct RUTHENIUM
    {
        const int group = 8;
        const string type = "Transition Metal";
        const string crystal_type = "Hexagonal Close Packed";
        const string electron_configuration = "[Kr]4d7 5s1";
        const long double atomic_weight = 101.07; // u (g/mol)
        const int atomic_number = 44;
        const vector<long double> energy_levels = {2, 8, 18, 15, 1};
        const long double density_STP = 12370; // kg/m^3
        const long double melting_point = 2334.0; // C
        const long double boiling_point = 4150.0; // C
        const long double thermal_conductivity = 120.0; // W/mK
        const long double electric_conductivity = 14.0; // MS/m
        const long double resistivity = 7.1e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 238.0; // J/kgK
        const long double heat_vaporization = 580.0; // kJ/mol
        const long double heat_fusion = 25.7; // kJ/mol
        const long double ionization_1st = 7.361; // eV
        static void display()
        {
            displayElementImg(getFileName(44));
        }
    } Ru;

    /// <summary>
    /// Rhodium is a chemical element with the symbol Rh and atomic number 45.
    /// It is an extraordinarily rare, silvery-white, hard, corrosion-resistant,
    /// and chemically inert transition metal. It is a noble metal and a member
    /// of the platinum group. It has only one naturally occurring isotope, ¹⁰³Rh
    /// </summary>
    const struct RHODIUM
    {
        const int group = 9;
        const string type = "Transition Metal";
        const string crystal_type = "Face-Centered Cubic";
        const string electron_configuration = "[Kr]4d8 5s1";
        const long double atomic_weight = 102.91; // u (g/mol)
        const int atomic_number = 45;
        const vector<long double> energy_levels = {2, 8, 18, 16, 1};
        const long double density_STP = 12450; // kg/m^3
        const long double melting_point = 1964.0; // C
        const long double boiling_point = 3695.0; // C
        const long double thermal_conductivity = 150.0; // W/mK
        const long double electric_conductivity = 23.0; // MS/m
        const long double resistivity = 4.3e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 240.0; // J/kgK
        const long double heat_vaporization = 495.0; // kJ/mol
        const long double heat_fusion = 21.7; // kJ/mol
        const long double ionization_1st = 7.459; // eV
        static void display()
        {
            displayElementImg(getFileName(45));
        }
    } Rh;

    /// <summary>
    /// Palladium is a chemical element with the symbol Pd and atomic number 46.
    /// It is a rare and lustrous silvery-white metal discovered in 1803 by the
    /// English chemist William Hyde Wollaston.
    /// </summary>
    const struct PALLADIUM
    {
        const int group = 10;
        const string type = "Transition Metal";
        const string crystal_type = "Face-Centered Cubic";
        const string electron_configuration = "[Kr]4d10";
        const long double atomic_weight = 106.42; // u (g/mol)
        const int atomic_number = 46;
        const vector<long double> energy_levels = {2, 8, 18, 18};
        const long double density_STP = 12023; // kg/m^3
        const long double melting_point = 1554.90; // C
        const long double boiling_point = 2963.0; // C
        const long double thermal_conductivity = 72.0; // W/mK
        const long double electric_conductivity = 10.0; // MS/m
        const long double resistivity = 1.0e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 240.0; // J/kgK
        const long double heat_vaporization = 380.0; // kJ/mol
        const long double heat_fusion = 16.7; // kJ/mol
        const long double ionization_1st = 8.337; // eV
        static void display()
        {
            displayElementImg(getFileName(46));
        }
    } Pd;

    /// <summary>
    /// Silver is a chemical element with the symbol Ag and atomic number 47.
    /// A soft, white, lustrous transition metal, it exhibits the highest
    /// electrical conductivity, thermal conductivity, and reflectivity of
    /// any metal.
    /// </summary>
    const struct SILVER
    {
        const int group = 11;
        const string type = "Transition Metal";
        const string crystal_type = "Face-Centered Cubic";
        const string electron_configuration = "[Kr]4d10 5s1";
        const long double atomic_weight = 107.87; // u (g/mol)
        const int atomic_number = 47;
        const vector<long double> energy_levels = {2, 8, 18, 18, 1};
        const long double density_STP = 10490; // kg/m^3
        const long double melting_point = 961.780; // C
        const long double boiling_point = 2162.0; // C
        const long double thermal_conductivity = 430.0; // W/mK
        const long double electric_conductivity = 62.0; // MS/m
        const long double resistivity = 1.6e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 235.0; // J/kgK
        const long double heat_vaporization = 255.0; // kJ/mol
        const long double heat_fusion = 11.3; // kJ/mol
        const long double ionization_1st = 7.576; // eV
        static void display()
        {
            displayElementImg(getFileName(47));
        }
    } Ag;

    /// <summary>
    /// Cadmium is a chemical element with the symbol Cd and atomic number 48.
    /// This soft, silvery-white metal is chemically similar to the two other
    /// stable metals in group 12, zinc and mercury.
    /// </summary>
    const struct CADMIUM
    {
        const int group = 12;
        const string type = "Transition Metal";
        const string crystal_type = "Hexagonal Close Packed";
        const string electron_configuration = "[Kr]4d10 5s2";
        const long double atomic_weight = 112.41; // u (g/mol)
        const int atomic_number = 48;
        // energy_levels must add u (g/mol)p to the atomic number
        const vector<long double> energy_levels = {2, 8, 18, 18, 2};
        const long double density_STP = 8650; // kg/m^3
        const long double melting_point = 321.07; // C
        const long double boiling_point = 766.9; // C
        const long double thermal_conductivity = 97.0; // W/mK
        const long double electric_conductivity = 14.0; // MS/m
        const long double resistivity = 7.0e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 230.0; // J/kgK
        const long double heat_vaporization = 100.0; // kJ/mol
        const long double heat_fusion = 6.3; // kJ/mol
        const long double ionization_1st = 8.994; // eV
        static void display()
        {
            displayElementImg(getFileName(48));
        }
    } Cd;

    /// <summary>
    /// Indium is a chemical element with the symbol In and atomic number 49.
    /// Indium is the softest metal that is not an alkali metal. It is a
    /// silvery-white metal that resembles tin in appearance. It is a
    /// post-transition metal that makes u (g/mol)p 0.21 parts per million of the
    /// Earth's crust
    /// </summary>
    const struct INDIUM
    {
        const int group = 13;
        const string type = "Post-Transition Metal";
        const string crystal_type = "Tetragonal";
        const string electron_configuration = "[Kr]4d10 5s2 5p1";
        const long double atomic_weight = 114.82; // u (g/mol)
        const int atomic_number = 49;
        const vector<long double> energy_levels = {2, 8, 18, 18, 3};
        const long double density_STP = 7310; // kg/m^3
        const long double melting_point = 156.60; // C
        const long double boiling_point = 2072.0; // C
        const long double thermal_conductivity = 82.0; // W/mK
        const long double electric_conductivity = 12.0; // MS/m
        const long double resistivity = 8.0e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 233.0; // J/kgK
        const long double heat_vaporization = 230.0; // kJ/mol
        const long double heat_fusion = 3.26; // kJ/mol
        const long double ionization_1st = 5.786; // eV
        static void display()
        {
            displayElementImg(getFileName(49));
        }
    } In;

    /// <summary>
    /// Tin is a chemical element with the symbol Sn and atomic number 50.
    /// Tin is a silvery metal that characteristically has a faint yellow hue.
    /// Tin, like indium, is soft enough to be cut without much force.
    /// </summary>
    const struct TIN
    {
        const int group = 14;
        const string type = "Post-Transition Metal";
        const string crystal_type = "Tetragonal";
        const string electron_configuration = "[Kr]4d10 5s2 5p2";
        const long double atomic_weight = 118.71; // u (g/mol)
        const int atomic_number = 50;
        const vector<long double> energy_levels = {2, 8, 18, 18, 4};
        const long double density_STP = 7310; // kg/m^3
        const long double melting_point = 231.93; // C
        const long double boiling_point = 2602.0; // C
        const long double thermal_conductivity = 67.0; // W/mK
        const long double electric_conductivity = 9.1; // MS/m
        const long double resistivity = 1.1e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 217.0; // J/kgK
        const long double heat_vaporization = 290.0; // kJ/mol
        const long double heat_fusion = 7.0; // kJ/mol
        const long double ionization_1st = 7.344; // eV
        static void display()
        {
            displayElementImg(getFileName(50));
        }
    } Sn;

    /// <summary>
    /// Antimony is a chemical element with the symbol Sb and atomic number 51.
    /// A lustrous gray metalloid, it is found in nature mainly as the sulfide
    /// mineral stibnite. Antimony compounds have been known since ancient times
    /// and were powdered for u (g/mol)se as medicine and cosmetics, often known by the
    /// Arabic name kohl.
    /// </summary>
    const struct ANTIMONY
    {
        const int group = 15;
        const string type = "Metalloid";
        const string crystal_type = "Rhombohedral";
        const string electron_configuration = "[Kr]4d10 5s2 5p3";
        const long double atomic_weight = 121.76; // u (g/mol)
        const int atomic_number = 51;
        const vector<long double> energy_levels = {2, 8, 18, 18, 5};
        const long double density_STP = 6697; // kg/m^3
        const long double melting_point = 630.63; // C
        const long double boiling_point = 1587.0; // C
        const long double thermal_conductivity = 24.0; // W/mK
        const long double electric_conductivity = 2.5; // MS/m
        const long double resistivity = 4.0e-7; //m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 207.0; // J/kgK
        const long double heat_vaporization = 68.0; // kJ/mol
        const long double heat_fusion = 19.7; // kJ/mol
        const long double ionization_1st = 8.64; // eV
        static void display()
        {
            displayElementImg(getFileName(51));
        }
    } Sb;

    /// <summary>
    /// Tellurium is a chemical element with the symbol Te and atomic number 52.
    /// It is a brittle, mildly toxic, rare, silver-white metalloid. Tellurium
    /// is chemically related to selenium and sulfur, all three of which are
    /// chalcogens. It is occasionally found in native form as elemental crystals
    /// </summary>
    const struct TELLURIUM
    {
        const int group = 16;
        const string type = "Metalloid";
        const string crystal_type = "Hexagonal";
        const string electron_configuration = "[Kr]4d10 5s2 5p4";
        const long double atomic_weight = 127.60; // u (g/mol)
        const int atomic_number = 52;
        const vector<long double> energy_levels = {2, 8, 18, 18, 6};
        const long double density_STP = 62420; // kg/m^3
        const long double melting_point = 449.51; // C
        const long double boiling_point = 987.9; // C
        const long double thermal_conductivity = 3.0; // W/mK
        const long double electric_conductivity = 0.010; // MS/m
        const long double resistivity = .0001; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 201.0; // J/kgK
        const long double heat_vaporization = 48.0; // kJ/mol
        const long double heat_fusion = 17.5; // kJ/mol
        const long double ionization_1st = 9.010; // eV
        static void display()
        {
            displayElementImg(getFileName(52));
        }
    } Te;

    /// <summary>
    /// Iodine is a chemical element with the symbol I and atomic number 53.
    /// The heaviest of the stable halogens, it exists as a semi-lustrous,
    /// non-metallic solid at standard conditions that melts to form a deep
    /// violet liquid at 114 degrees Celsius, and boils to a violet gas at
    /// 184 degrees Celsius.
    /// </summary>
    const struct IODINE
    {
        const int group = 17;
        const string type = "Halogen";
        const string crystal_type = "Orthorhombic";
        const string electron_configuration = "[Kr]4d10 5s2 5p5";
        const long double atomic_weight = 126.90; // u (g/mol)
        const int atomic_number = 53;
        const vector<long double> energy_levels = {2, 8, 18, 18, 7};
        const long double density_STP = 4940; // kg/m^3
        const long double melting_point = 113.7; // C
        const long double boiling_point = 184.3; // C
        const long double thermal_conductivity = 0.449; // W/mK
        const long double electric_conductivity = 1.0e-13; // MS/m
        const long double resistivity = 1.0e7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 429.0; // J/kgK
        const long double heat_vaporization = 20.9; // kJ/mol
        const long double heat_fusion = 7.76; // kJ/mol
        const long double ionization_1st = 10.451; // eV
        static void display()
        {
            displayElementImg(getFileName(53));
        }
    } I;

    /// <summary>
    /// Xenon is a chemical element with the symbol Xe and atomic number 54.
    /// It is a colorless, dense, odorless noble gas found in Earth's atmosphere
    /// in trace amounts.
    /// </summary>
    const struct XENON
    {
        const int group = 18;
        const string type = "Noble Gas";
        const string crystal_type = "Face-Centered Cubic";
        const string electron_configuration = "[Kr]4d10 5s2 5p6";
        const long double atomic_weight = 131.29; // u (g/mol)
        const int atomic_number = 54;
        const vector<long double> energy_levels = {2, 8, 18, 18, 8};
        const long double density_STP = 5.9; // kg/m^3
        const long double melting_point = -111.8; // C
        const long double boiling_point = -108.0; // C
        const long double thermal_conductivity = .00565; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 158.32; // J/kgK
        const long double heat_vaporization = 12.64; // kJ/mol
        const long double heat_fusion = 2.30; // kJ/mol
        const long double ionization_1st = 12.130; // eV
        static void display()
        {
            displayElementImg(getFileName(54));
        }
    } Xe;

    /// <summary>
    /// Caesium is a chemical element with the symbol Cs and atomic number 55.
    /// It is a soft, silvery-golden alkali metal with a melting point of 28.5 °C,
    /// which makes it one of only five elemental metals that are liquid at or
    /// near room temperature
    /// </summary>
    const struct CAESIUM
    {
        const int group = 1;
        const string type = "Alkali Metal";
        const string crystal_type = "Body-Centered Cubic";
        const string electron_configuration = "[Xe]6s1";
        const long double atomic_weight = 132.91; // u (g/mol)
        const int atomic_number = 55;
        const vector<long double> energy_levels = {2, 8, 18, 18, 8, 1};
        const long double density_STP = 1879; // kg/m^3
        const long double melting_point = 28.440; // C
        const long double boiling_point = 671.0; // C
        const long double thermal_conductivity = 36.0; // W/mK
        const long double electric_conductivity = 5.0; // MS/m
        const long double resistivity = 2.0e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 242.0; // J/kgK
        const long double heat_vaporization = 65.0; // kJ/mol
        const long double heat_fusion = 2.09; // kJ/mol
        const long double ionization_1st = 3.894; // eV
        static void display()
        {
            displayElementImg(getFileName(55));
        }
    } Cs;

    /// <summary>
    /// Barium is a chemical element with the symbol Ba and atomic number 56.
    /// It is the fifth element in group 2 and is a soft, silvery alkaline earth
    /// metal. Because of its high chemical reactivity, barium is never found in
    /// nature as a free element.
    /// </summary>
    const struct BARIUM
    {
        const int group = 2;
        const string type = "Alkaline Earth Metal";
        const string crystal_type = "Body-Centered Cubic";
        const string electron_configuration = "[Xe]6s2";
        const long double atomic_weight = 137.33; // u (g/mol)
        const int atomic_number = 56;
        const vector<long double> energy_levels = {2, 8, 18, 18, 8, 2};
        const long double density_STP = 3510; // kg/m^3
        const long double melting_point = 730.0; // C
        const long double boiling_point = 1870.0; // C
        const long double thermal_conductivity = 18.0; // W/mK
        const long double electric_conductivity = 2.9; // MS/m
        const long double resistivity = 3.5e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 205.0; // J/kgK
        const long double heat_vaporization = 140.0; // kJ/mol
        const long double heat_fusion = 8.0; // kJ/mol
        const long double ionization_1st = 5.212; // eV
        static void display()
        {
            displayElementImg(getFileName(56));
        }
    } Ba;


    /// <summary>
    ///	Lanthanum is a chemical element with the symbol La and atomic number 57.
    ///	It is a soft, ductile, silvery-white metal that tarnishes slowly when
    ///	exposed to air.
    /// </summary>
    const struct LANTHANUM
    {
        const int group = 3;
        const string type = "Lanthanoid";
        const string crystal_type = "Double Hexagonal Close Packed";
        const string electron_configuration = "[Xe]5d1 6s2";
        const long double atomic_weight = 138.91; // u (g/mol)
        const int atomic_number = 57;
        const vector<long double> energy_levels = {2, 8, 18, 18, 9, 2};
        const long double density_STP = 6146; // kg/m^3
        const long double melting_point = 919.9; // C
        const long double boiling_point = 3463.0; // C
        const long double thermal_conductivity = 13.0; // W/mK
        const long double electric_conductivity = 1.6; // MS/m
        const long double resistivity = 6.1e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 195.0; // J/kgK
        const long double heat_vaporization = 400.0; // kJ/mol
        const long double heat_fusion = 6.2; // kJ/mol
        const long double ionization_1st = 5.577; // eV
        static void display()
        {
            displayElementImg(getFileName(57));
        }
    } La;

    /// <summary>
    ///	Cerium is a chemical element with the symbol Ce and atomic number 58.
    ///	Cerium is a soft, ductile, and silvery-white metal that tarnishes when
    ///	exposed to air, and it is soft enough to be cut with a steel kitchen knife.
    /// </summary>
    const struct CERIUM
    {
        const int group = 3;
        const string type = "Lanthanoid";
        const string crystal_type = "Double Hexagonal Close Packed / Face-Centered Cubic";
        const string electron_configuration = "[Xe]4f1 5d1 6s2";
        const long double atomic_weight = 140.12; // u (g/mol)
        const int atomic_number = 58;
        const vector<long double> energy_levels = {2, 8, 18, 19, 9, 2};
        const long double density_STP = 6689; // kg/m^3
        const long double melting_point = 797.9; // C
        const long double boiling_point = 3360.0; // C
        const long double thermal_conductivity = 11.0; // W/mK
        const long double electric_conductivity = 1.4; // MS/m
        const long double resistivity = 7.4e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 192.0; // J/kgK
        const long double heat_vaporization = 350.0; // kJ/mol
        const long double heat_fusion = 5.5; // kJ/mol
        const long double ionization_1st = 5.539; // eV
        static void display()
        {
            displayElementImg(getFileName(58));
        }
    } Ce;

    /// <summary>
    ///	Praseodymium is a chemical element with the symbol Pr and atomic number 59.
    ///	It is the third member of the lanthanide series and is traditionally
    ///	considered to be one of the rare-earth metals.
    /// </summary>
    const struct PRASEODYMIUM
    {
        const int group = 3;
        const string type = "Lanthanoid";
        const string crystal_type = "Double Hexagonal Close Packed";
        const string electron_configuration = "[Xe]4f3 6s2";
        const long double atomic_weight = 140.91; // u (g/mol)
        const int atomic_number = 59;
        const vector<long double> energy_levels = {2, 8, 18, 21, 8, 2};
        const long double density_STP = 6640; // kg/m^3
        const long double melting_point = 930.9; // C
        const long double boiling_point = 3290.0; // C
        const long double thermal_conductivity = 13.0; // W/mK
        const long double electric_conductivity = 1.4; // MS/m
        const long double resistivity = 7.0e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 193.0; // J/kgK
        const long double heat_vaporization = 330.0; // kJ/mol
        const long double heat_fusion = 6.9; // kJ/mol
        const long double ionization_1st = 5.46; // eV
        static void display()
        {
            displayElementImg(getFileName(59));
        }
    }Pr;

    /// <summary>
    ///	Neodymium is a chemical element with the symbol Nd and atomic number 60.
    ///	Neodymium belongs to the lanthanide series and is a rare-earth element.
    ///	It is a hard, slightly malleable silvery metal that quickly tarnishes
    ///	in air and moisture
    /// </summary>
    const struct NEODYMIUM
    {
        const int group = 3;
        const string type = "Lanthanoid";
        const string crystal_type = "Double Hexagonal Close Packed";
        const string electron_configuration = "[Xe]4f4 6s2";
        const long double atomic_weight = 144.24; // u (g/mol)
        const int atomic_number = 60;
        const vector<long double> energy_levels = {2, 8, 18, 22, 8, 2};
        const long double density_STP = 7010; // kg/m^3
        const long double melting_point = 1021.0; // C
        const long double boiling_point = 3100.0; // C
        const long double thermal_conductivity = 17.0; // W/mK
        const long double electric_conductivity = 1.6; // MS/m
        const long double resistivity = 6.4e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 190.0; // J/kgK
        const long double heat_vaporization = 285.0; // kJ/mol
        const long double heat_fusion = 7.1; // kJ/mol
        const long double ionization_1st = 5.525; // eV
        static void display()
        {
            displayElementImg(getFileName(60));
        }
    } Nd;

    /// <summary>
    ///	Promethium is a chemical element with the symbol Pm and atomic number 61.
    ///	All of its isotopes are radioactive; it is extremely rare, with only
    ///	about 500–600 grams naturally occurring in Earth's crust at any
    ///	given time.
    /// </summary>
    const struct PROMETHIUM
    {
        const int group = 3;
        const string type = "Lanthanoid";
        const string crystal_type = "Double Hexagonal Close Packed";
        const string electron_configuration = "[Xe]4f5 6s2";
        const long double atomic_weight = (145); // u (g/mol)
        const int atomic_number = 61;
        const vector<long double> energy_levels = {2, 8, 18, 23, 8, 2};
        const long double density_STP = 7264; // kg/m^3
        const long double melting_point = 1100.0; // C
        const long double boiling_point = 3000.0; // C
        const long double thermal_conductivity = 15.0; // W/mK
        const long double electric_conductivity = 1.3; // MS/m
        const long double resistivity = 7.5e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = 290.0; // kJ/mol
        const long double heat_fusion = 7.7; // kJ/mol
        const long double ionization_1st = 5.6; // eV
        static void display()
        {
            displayElementImg(getFileName(61));
        }
    } Pm;

    /// <summary>
    ///	Samarium is a chemical element with the symbol Sm and atomic number 62.
    ///	It is a moderately hard silvery metal that slowly oxidizes in air.
    ///	Being a typical member of the lanthanide series, samarium usually assumes
    ///	the oxidation state +3.
    /// </summary>
    const struct SAMARIUM
    {
        const int group = 3;
        const string type = "Lanthanoid";
        const string crystal_type = "Rhombohedral";
        const string electron_configuration = "[Xe]4f6 6s2";
        const long double atomic_weight = 150.36; // u (g/mol)
        const int atomic_number = 62;
        const vector<long double> energy_levels = {2, 8, 18, 24, 8, 2};
        const long double density_STP = 7353; // kg/m^3
        const long double melting_point = 1072.0; // C
        const long double boiling_point = 1803.0; // C
        const long double thermal_conductivity = 13.0; // W/mK
        const long double electric_conductivity = 1.1; // MS/m
        const long double resistivity = 9.4e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 196.0; // J/kgK
        const long double heat_vaporization = 175.0; // kJ/mol
        const long double heat_fusion = 8.6; // kJ/mol
        const long double ionization_1st = 5.643; // eV
        static void display()
        {
            displayElementImg(getFileName(62));
        }
    } Sm;

    /// <summary>
    ///	Europium is a chemical element with the symbol Eu and atomic number 63.
    ///	Europium is the most reactive lanthanide by far, having to be stored
    ///	under an inert fluid to protect it from atmospheric oxygen or moisture.
    /// </summary>
    const struct EUROPIUM
    {
        const int group = 3;
        const string type = "Lanthanoid";
        const string crystal_type = "Body-Centered Cubic";
        const string electron_configuration = "[Xe]4f7 6s2";
        const long double atomic_weight = 151.96; // u (g/mol)
        const int atomic_number = 63;
        const vector<long double> energy_levels = {2, 8, 18, 25, 8, 2};
        const long double density_STP = 5244; // kg/m^3
        const long double melting_point = 821.9; // C
        const long double boiling_point = 1500.0; // C
        const long double thermal_conductivity = 14.0; // W/mK
        const long double electric_conductivity = 1.1; // MS/m
        const long double resistivity = 9.0e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 182.0; // J/kgK
        const long double heat_vaporization = 175.0; // kJ/mol
        const long double heat_fusion = 9.2; // kJ/mol
        const long double ionization_1st = 5.670; // eV
        static void display()
        {
            displayElementImg(getFileName(63));
        }
    } Eu;

    /// <summary>
    ///	Gadolinium is a chemical element with the symbol Gd and atomic number 64.
    ///	Gadolinium is a silvery-white metal when oxidation is removed. It is
    ///	only slightly malleable and is a ductile rare-earth element. Gadolinium
    ///	reacts with atmospheric oxygen or moisture slowly to form a black coating.
    /// </summary>
    const struct GADOLINIUM
    {
        const int group = 3;
        const string type = "Lanthanoid";
        const string crystal_type = "Hexagonal Close Packed";
        const string electron_configuration = "[Xe]4f7 5d1 6s2";
        const long double atomic_weight = 157.25; // u (g/mol)
        const int atomic_number = 64;
        const vector<long double> energy_levels = {2, 8, 18, 25, 9, 2};
        const long double density_STP = 7901; // kg/m^3
        const long double melting_point = 1313.0; // C
        const long double boiling_point = 3250.0; // C
        const long double thermal_conductivity = 11.0; // W/mK
        const long double electric_conductivity = .77; // MS/m
        const long double resistivity = 1.3e-6; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 240.0; // J/kgK
        const long double heat_vaporization = 305.0; // kJ/mol
        const long double heat_fusion = 10.0; // kJ/mol
        const long double ionization_1st = 6.150; // eV
        static void display()
        {
            displayElementImg(getFileName(64));
        }
    } Gd;

    /// <summary>
    ///	Terbium is a chemical element with the symbol Tb and atomic number 65.
    ///	It is a silvery-white, rare earth metal that is malleable, ductile,
    ///	and soft enough to be cut with a knife. The ninth member of the
    ///	lanthanide series, terbium is a fairly electro-positive metal that reacts
    ///	with water, evolving hydrogen gas.
    /// </summary>
    const struct TERBIUM
    {
        const int group = 3;
        const string type = "Lanthanoid";
        const string crystal_type = "Hexagonal Close Packed";
        const string electron_configuration = "[Xe]4f9 6s2";
        const long double atomic_weight = 158.93; // u (g/mol)
        const int atomic_number = 65;
        const vector<long double> energy_levels = {2, 8, 18, 27, 8, 2};
        const long double density_STP = 8219; // kg/m^3
        const long double melting_point = 1356.0; // C
        const long double boiling_point = 3230.0; // C
        const long double thermal_conductivity = 11.0; // W/mK
        const long double electric_conductivity = .83; // MS/m
        const long double resistivity = 1.2e-6; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 182.0; // J/kgK
        const long double heat_vaporization = 295.0; // kJ/mol
        const long double heat_fusion = 10.8; // kJ/mol
        const long double ionization_1st = 5.864; // eV
        static void display()
        {
            displayElementImg(getFileName(65));
        }
    } Tb;

    /// <summary>
    ///	Dysprosium is the chemical element with the symbol Dy and atomic number 66.
    ///	It is a rare-earth element with a metallic silver luster. Dysprosium is
    ///	never found in nature as a free element, though it is found in various
    ///	minerals, such as xenotime.
    /// </summary>
    const struct DYSPROSIUM
    {
        const int group = 3;
        const string type = "Lanthanoid";
        const string crystal_type = "Hexagonal Close Packed";
        const string electron_configuration = "[Xe]4f10 6s2";
        const long double atomic_weight = 162.50; // u (g/mol)
        const int atomic_number = 66;
        const vector<long double> energy_levels = {2, 8, 18, 28, 8, 2};
        const long double density_STP = 8551; // kg/m^3
        const long double melting_point = 1412.0; // C
        const long double boiling_point = 2567.0; // C
        const long double thermal_conductivity = 11.0; // W/mK
        const long double electric_conductivity = 1.1; // MS/m
        const long double resistivity = 9.1e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 167.0; // J/kgK
        const long double heat_vaporization = 280.0; // kJ/mol
        const long double heat_fusion = 11.1; // kJ/mol
        const long double ionization_1st = 5.934; // eV
        static void display()
        {
            displayElementImg(getFileName(66));
        }
    } Dy;

    /// <summary>
    /// Holmium is a chemical element with the symbol Ho and atomic number 67.
    /// Part of the lanthanide series, holmium is a rare-earth element. Holmium
    /// was discovered through isolation by Swedish chemist Per Theodor Cleve
    /// and independently by Jacques-Louis Soret and Marc Delafontaine who
    /// observed it spectroscopically in 1878.
    /// </summary>
    const struct HOLMIUM
    {
        const int group = 3;
        const string type = "Lanthanoid";
        const string crystal_type = "Hexagonal Close Packed";
        const string electron_configuration = "[Xe]4f11 6s2";
        const long double atomic_weight = 164.93; // u (g/mol)
        const int atomic_number = 67;
        const vector<long double> energy_levels = {2, 8, 18, 29, 8, 2};
        const long double density_STP = 8795; // kg/m^3
        const long double melting_point = 1474.0; // C
        const long double boiling_point = 2700.0; // C
        const long double thermal_conductivity = 16.0; // W/mK
        const long double electric_conductivity = 1.1; // MS/m
        const long double resistivity = 9.4e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 165.0; // J/kgK
        const long double heat_vaporization = 265.0; // kJ/mol
        const long double heat_fusion = 17.0; // kJ/mol
        const long double ionization_1st = 6.022; // eV
        static void display()
        {
            displayElementImg(getFileName(67));
        }
    } Ho;

    /// <summary>
    /// Erbium is a chemical element with the symbol Er and atomic number 68.
    /// A silvery-white solid metal when artificially isolated, natural erbium
    /// is always found in chemical combination with other elements.
    /// </summary>
    const struct ERBIUM
    {
        const int group = 3;
        const string type = "Lanthanoid";
        const string crystal_type = "Hexagonal Close Packed";
        const string electron_configuration = "[Xe]4f12 6s2";
        const long double atomic_weight = 167.26; // u (g/mol)
        const int atomic_number = 68;
        const vector<long double> energy_levels = {2, 8, 18, 30, 8, 2};
        const long double density_STP = 9066; // kg/m^3
        const long double melting_point = 1497.0; // C
        const long double boiling_point = 2868.0; // C
        const long double thermal_conductivity = 15.0; // W/mK
        const long double electric_conductivity = 1.2; // MS/m
        const long double resistivity = 8.6e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 168.0; // J/kgK
        const long double heat_vaporization = 285.0; // kJ/mol
        const long double heat_fusion = 19.9; // kJ/mol
        const long double ionization_1st = 6.108; // eV
        static void display()
        {
            displayElementImg(getFileName(68));
        }
    } Er;

    /// <summary>
    ///	Thulium is a chemical element with the symbol Tm and atomic number 69.
    ///	It is the thirteenth and third-last element in the lanthanide series.
    /// </summary>
    const struct THULIUM
    {
        const int group = 3;
        const string type = "Lanthanoid";
        const string crystal_type = "Hexagonal Close Packed";
        const string electron_configuration = "[Xe]4f13 6s2";
        const long double atomic_weight = 168.93; // u (g/mol)
        const int atomic_number = 69;
        const vector<long double> energy_levels = {2, 8, 18, 31, 8, 2};
        const long double density_STP = 9320; // kg/m^3
        const long double melting_point = 1545.0; // C
        const long double boiling_point = 1950.0; // C
        const long double thermal_conductivity = 17.0; // W/mK
        const long double electric_conductivity = 1.4; // MS/m
        const long double resistivity = 7.0e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 160.0; // J/kgK
        const long double heat_vaporization = 250.0; // kJ/mol
        const long double heat_fusion = 16.8; // kJ/mol
        const long double ionization_1st = 6.184; // eV
        static void display()
        {
            displayElementImg(getFileName(69));
        }
    } Tm;

    /// <summary>
    ///	Ytterbium is a chemical element with the symbol Yb and atomic number 70.
    ///	It is the fourteenth and penultimate element in the lanthanide series,
    ///	which is the basis of the relative stability of its +2 oxidation state.
    /// </summary>
    const struct YTTERBIUM
    {
        const int group = 3;
        const string type = "Lanthanoid";
        const string crystal_type = "Face-Centered Cubic";
        const string electron_configuration = "[Xe]4f14 6s2";
        const long double atomic_weight = 173.05; // u (g/mol)
        const int atomic_number = 70;
        const vector<long double> energy_levels = {2, 8, 18, 32, 8, 2};
        const long double density_STP = 6570; // kg/m^3
        const long double melting_point = 818.9; // C
        const long double boiling_point = 1196.0; // C
        const long double thermal_conductivity = 39.0; // W/mK
        const long double electric_conductivity = 3.6; // MS/m
        const long double resistivity = 2.8e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 154.0; // J/kgK
        const long double heat_vaporization = 160.0; // kJ/mol
        const long double heat_fusion = 7.7; // kJ/mol
        const long double ionization_1st = 6.254; // eV
        static void display()
        {
            displayElementImg(getFileName(70));
        }
    } Yb;

    /// <summary>
    ///	Lutetium is a chemical element with the symbol Lu and atomic number 71.
    ///	It is a silvery white metal, which resists corrosion in dry air,
    ///	but not in moist air. Lutetium is the last element in the lanthanide series,
    ///	and it is traditionally counted among the rare earths.
    /// </summary>
    const struct LUTERTIUM
    {
        const int group = 3;
        const string type = "Lanthanoid";
        const string crystal_type = "Hexagonal Close Packed";
        const string electron_configuration = "[Xe]4f14 5d1 6s2";
        const long double atomic_weight = 174.97; // u (g/mol)
        const int atomic_number = 71;
        const vector<long double> energy_levels = {2, 8, 18, 32, 9, 2};
        const long double density_STP = 9841; // kg/m^3
        const long double melting_point = 1663.0; // C
        const long double boiling_point = 3402.0; // C
        const long double thermal_conductivity = 16.0; // W/mK
        const long double electric_conductivity = 1.8; // MS/m
        const long double resistivity = 5.6e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 154.0; // J/kgK
        const long double heat_vaporization = 415.0; // kJ/mol
        const long double heat_fusion = 22.0; // kJ/mol
        const long double ionization_1st = 5.426; // eV
        static void display()
        {
            displayElementImg(getFileName(71));
        }
    } Lu;


    /// <summary>
    ///	Hafnium is a chemical element with the symbol Hf and atomic number 72.
    ///	A lustrous, silvery gray, tetravalent transition metal, hafnium chemically
    ///	resembles zirconium and is found in many zirconium minerals.
    /// </summary>
    const struct HAFNIUM
    {
        const int group = 4;
        const string type = "Transition Metal";
        const string crystal_type = "Hexagonal Close Packed";
        const string electron_configuration = "[Xe]4f14 5d2 6s2";
        const long double atomic_weight = 178.49; // u (g/mol)
        const int atomic_number = 72;
        const vector<long double> energy_levels = {2, 8, 18, 32, 10, 2};
        const long double density_STP = 13310; // kg/m^3
        const long double melting_point = 2233.0; // C
        const long double boiling_point = 4603.0; // C
        const long double thermal_conductivity = 23.0; // W/mK
        const long double electric_conductivity = 3.3; // MS/m
        const long double resistivity = 3.0e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 144.0; // J/kgK
        const long double heat_vaporization = 630.0; // kJ/mol
        const long double heat_fusion = 25.5; // kJ/mol
        const long double ionization_1st = 6.825; // eV
        static void display()
        {
            displayElementImg(getFileName(72));
        }
    } Hf;


    /// <summary>
    ///	Tantalum is a chemical element with the symbol Ta and atomic number 73.
    ///	Previously known as tantalium, it is named after Tantalus, a villain
    ///	from Greek mythology. Tantalum is a rare, hard, blue-gray, lustrous
    ///	transition metal that is highly corrosion-resistant.
    /// </summary>
    const struct TANTALUM
    {
        const int group = 5;
        const string type = "Transition Metal";
        const string crystal_type = "Body-Centered Cubic / Tetragonal";
        const string electron_configuration = "[Xe]4f14 5d3 6s2";
        const long double atomic_weight = 180.95; // u (g/mol)
        const int atomic_number = 73;
        const vector<long double> energy_levels = {2, 8, 18, 32, 11, 2};
        const long double density_STP = 16650; // kg/m^3
        const long double melting_point = 3017.0; // C
        const long double boiling_point = 5458.0; // C
        const long double thermal_conductivity = 57.0; // W/mK
        const long double electric_conductivity = 7.7; // MS/m
        const long double resistivity = 1.3e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 140.0; // J/kgK
        const long double heat_vaporization = 735.0; // kJ/mol
        const long double heat_fusion = 36.0; // kJ/mol
        const long double ionization_1st = 7.89; // eV
        static void display()
        {
            displayElementImg(getFileName(73));
        }
    } Ta;
    /// <summary>
    ///	Tungsten, or wolfram, is a chemical element with the symbol W and atomic number 74.
    ///	Tungsten is a rare metal found naturally on Earth almost exclusively as
    ///	compounds with other elements. It was identified as a new element in 1781
    ///	and first isolated as a metal in 1783.
    /// </summary>
    const struct TUNGSTEN
    {
        const int group = 6;
        const string type = "Transition Metal";
        const string crystal_type = "Body-Centered Cubic";
        const string electron_configuration = "[Xe]4f14 5d4 6s2";
        const long double atomic_weight = 183.84; // u (g/mol)
        const int atomic_number = 74;
        const vector<long double> energy_levels = {2, 8, 18, 32, 12, 2};
        const long double density_STP = 19250; // kg/m^3
        const long double melting_point = 3422.0; // C
        const long double boiling_point = 5555.0; // C
        const long double thermal_conductivity = 170.0; // W/mK
        const long double electric_conductivity = 20.0; // MS/m
        const long double resistivity = 5.0e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 132.0; // J/kgK
        const long double heat_vaporization = 800.0; // kJ/mol
        const long double heat_fusion = 35.0; // kJ/mol
        const long double ionization_1st = 7.98; // eV
        static void display()
        {
            displayElementImg(getFileName(74));
        }
    } W;

    /// <summary>
    ///	Rhenium is a chemical element with the symbol Re and atomic number 75.
    ///	It is a silvery-gray, heavy, third-row transition metal in group 7 of
    ///	the periodic table. With an estimated average concentration of 1 part
    ///	per billion, rhenium is one of the rarest elements in the Earth's crust.
    /// </summary>
    const struct RHENIUM
    {
        const int group = 7;
        const string type = "Transition Metal";
        const string crystal_type = "Hexagonal Close Packed";
        const string electron_configuration = "[Xe]4f14 5d5 6s2";
        const long double atomic_weight = 186.21; // u (g/mol)
        const int atomic_number = 75;
        const vector<long double> energy_levels = {2, 8, 18, 32, 13, 2};
        const long double density_STP = 21020; // kg/m^3
        const long double melting_point = 3186.0; // C
        const long double boiling_point = 5596.0; // C
        const long double thermal_conductivity = 48.0; // W/mK
        const long double electric_conductivity = 5.6; // MS/m
        const long double resistivity = 1.8e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 137.0; // J/kgK
        const long double heat_vaporization = 705.0; // kJ/mol
        const long double heat_fusion = 33.0; // kJ/mol
        const long double ionization_1st = 7.88; // eV
        static void display()
        {
            displayElementImg(getFileName(75));
        }
    } Re;

    /// <summary>
    ///	Osmium is a chemical element with the symbol Os and atomic number 76.
    ///	It is a hard, brittle, bluish-white transition metal in the platinum
    ///	group that is found as a trace element in alloys, mostly in platinum ores.
    /// </summary>
    const struct OSMIUM
    {
        const int group = 8;
        const string type = "Transition Metal";
        const string crystal_type = "Hexagonal Close Packed";
        const string electron_configuration = "[Xe]4f14 5d6 6s2";
        const long double atomic_weight = 190.23; // u (g/mol)
        const int atomic_number = 76;
        const vector<long double> energy_levels = {2, 8, 18, 32, 14, 2};
        const long double density_STP = 22590; // kg/m^3
        const long double melting_point = 3033.0; // C
        const long double boiling_point = 5012.0; // C
        const long double thermal_conductivity = 88.0; // W/mK
        const long double electric_conductivity = 12.0; // MS/m
        const long double resistivity = 8.1e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 130.0; // J/kgK
        const long double heat_vaporization = 630.0; // kJ/mol
        const long double heat_fusion = 31.0; // kJ/mol
        const long double ionization_1st = 8.71; // eV
        static void display()
        {
            displayElementImg(getFileName(76));
        }
    } Os;

    /// <summary>
    ///	Iridium is a chemical element with the symbol Ir and atomic number 77.
    ///	A very hard, brittle, silvery-white transition metal of the platinum group,
    ///	iridium is considered to be the second-densest metal with a density of
    ///	22.56 g/cm³ as defined by experimental X_-ray crystallography.
    /// </summary>
    const struct IRIDIUM
    {
        const int group = 9;
        const string type = "Transition Metal";
        const string crystal_type = "Face-Centered Cubic";
        const string electron_configuration = "[Xe]4f14 5d7 6s2";
        const long double atomic_weight = 192.22; // u (g/mol)
        const int atomic_number = 77;
        const vector<long double> energy_levels = {2, 8, 18, 32, 15, 2};
        const long double density_STP = 22560; // kg/m^3
        const long double melting_point = 2466.0; // C
        const long double boiling_point = 4428.0; // C
        const long double thermal_conductivity = 150.0; // W/mK
        const long double electric_conductivity = 21.0; // MS/m
        const long double resistivity = 4.7e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 131.0; // J/kgK
        const long double heat_vaporization = 560.0; // kJ/mol
        const long double heat_fusion = 26.0; // kJ/mol
        const long double ionization_1st = 9.12; // eV
        static void display()
        {
            displayElementImg(getFileName(77));
        }
    } Ir;

    /// <summary>
    ///	Platinum is a chemical element with the symbol Pt and atomic number 78.
    ///	It is a dense, malleable, ductile, highly nonreactive, precious,
    ///	silverish-white transition metal. Its name is derived from the Spanish
    ///	term platino, meaning "little silver".
    /// </summary>
    const struct PLATINUM
    {
        const int group = 10;
        const string type = "Transition Metal";
        const string crystal_type = "Face-Centered Cubic";
        const string electron_configuration = "[Xe]4f14 5d9 6s1";
        const long double atomic_weight = 195.08; // u (g/mol)
        const int atomic_number = 78;
        const vector<long double> energy_levels = {2, 8, 18, 32, 17, 1};
        const long double density_STP = 21450; // kg/m^3
        const long double melting_point = 1768.3; // C
        const long double boiling_point = 3825.0; // C
        const long double thermal_conductivity = 72.0; // W/mK
        const long double electric_conductivity = 9.4; // MS/m
        const long double resistivity = 1.1e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 133.0; // J/kgK
        const long double heat_vaporization = 490.0; // kJ/mol
        const long double heat_fusion = 20.0; // kJ/mol
        const long double ionization_1st = 9.02; // eV
        static void display()
        {
            displayElementImg(getFileName(78));
        }
    } Pt;

    /// <summary>
    ///	Gold is a chemical element with the symbol Au and atomic number 79,
    ///	making it one of the higher atomic number elements that occur naturally.
    ///	In a pure form, it is a bright, slightly reddish yellow, dense, soft,
    ///	malleable, and ductile metal. Chemically, gold is a transition metal
    ///	and a group 11 element.
    /// </summary>
    const struct GOLD
    {
        const int group = 11;
        const string type = "Transition Metal";
        const string crystal_type = "Face-Centered Cubic";
        const string electron_configuration = "[Xe]4f14 5d10 6s1";
        const long double atomic_weight = 196.97; // u (g/mol)
        const int atomic_number = 79;
        const vector<long double> energy_levels = {2, 8, 18, 32, 18, 1};
        const long double density_STP = 19300; // kg/m^3
        const long double melting_point = 1064.18; // C
        const long double boiling_point = 2856; // C
        const long double thermal_conductivity = 320.0; // W/mK
        const long double electric_conductivity = 45.0; // MS/m
        const long double resistivity = 2.2e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 129.1; // J/kgK
        const long double heat_vaporization = 330.0; // kJ/mol
        const long double heat_fusion = 12.5; // kJ/mol
        const long double ionization_1st = 9.225; // eV
        static void display()
        {
            displayElementImg(getFileName(79));
        }
    } Au;

    /// <summary>
    ///	Mercury is a chemical element with the symbol Hg and atomic number 80.
    ///	It is commonly known as quicksilver and was formerly named hydrargyrum.
    /// </summary>
    const struct MERCURY
    {
        const int group = 12;
        const string type = "Transition Metal";
        const string crystal_type = "Rhombohedral";
        const string electron_configuration = "[Xe]4f14 5d10 6s2";
        const long double atomic_weight = 200.59; // u (g/mol)
        const int atomic_number = 80;
        const vector<long double> energy_levels = {2, 8, 18, 32, 18, 2};
        const long double density_STP = 13534; // kg/m^3
        const long double melting_point = -38.830; // C
        const long double boiling_point = 356.73; // C
        const long double thermal_conductivity = 8.3; // W/mK
        const long double electric_conductivity = 1.0; // MS/m
        const long double resistivity = 9.6e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 139.5; // J/kgK
        const long double heat_vaporization = 59.2; // kJ/mol
        const long double heat_fusion = 2.29; // kJ/mol
        const long double ionization_1st = 10.438; // eV
        static void display()
        {
            displayElementImg(getFileName(80));
        }
    } Hg;

    /// <summary>
    ///	Thallium is a chemical element with the symbol Tl and atomic number 81.
    ///	It is a gray post-transition metal that is not found free in nature.
    ///	When isolated, thallium resembles tin, but discolors when exposed to air.
    /// </summary>
    const struct THALLIUM
    {
        const int group = 13;
        const string type = "Post-Transition Metal";
        const string crystal_type = "Hexagonal Close Packed";
        const string electron_configuration = "[Xe]4f14 5d10 6s2 6p1";
        const long double atomic_weight = 204.38; // u (g/mol)
        const int atomic_number = 81;
        const vector<long double> energy_levels = {2, 8, 18, 32, 18, 3};
        const long double density_STP = 11850; // kg/m^3
        const long double melting_point = 304.0; // C
        const long double boiling_point = 1473.0; // C
        const long double thermal_conductivity = 46.0; // W/mK
        const long double electric_conductivity = 6.7; // MS/m
        const long double resistivity = 1.5e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 129.0; // J/kg
        const long double heat_vaporization = 165.0; // kJ/mol
        const long double heat_fusion = 4.2; // kJ/mol
        const long double ionization_1st = 6.109; // eV
        static void display()
        {
            displayElementImg(getFileName(81));
        }
    } Tl;

    /// <summary>
    ///	Lead is a chemical element with the symbol Pb and atomic number 82.
    ///	It is a heavy metal that is denser than most common materials. Lead is
    ///	soft and malleable, and also has a relatively low melting point. When
    ///	freshly cut, lead is silvery with a hint of blue; it tarnishes to a dull
    ///	gray color when exposed to air.
    /// </summary>
    const struct LEAD
    {
        const int group = 14;
        const string type = "Post-Transition Metal";
        const string crystal_type = "Face-Centered Cubic";
        const string electron_configuration = "[Xe]4f14 5d10 6s2 6p2";
        const long double atomic_weight = 207.2; // u (g/mol)
        const int atomic_number = 82;
        const vector<long double> energy_levels = {2, 8, 18, 32, 18, 4};
        const long double density_STP = 11340; // kg/m^3
        const long double melting_point = 327.46; // C
        const long double boiling_point = 1749.0; // C
        const long double thermal_conductivity = 35.0; // W/mK
        const long double electric_conductivity = 4.8; // MS/m
        const long double resistivity = 2.1e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 127.0; // J/kgK
        const long double heat_vaporization = 178.0; // kJ/mol
        const long double heat_fusion = 4.77; // kJ/mol
        const long double ionization_1st = 7.417; // eV
        static void display()
        {
            displayElementImg(getFileName(82));
        }
    } Pb;

    /// <summary>
    ///	Bismuth is a chemical element with the symbol Bi and atomic number 83.
    ///	It is a pentavalent post-transition metal and one of the pnictogens with
    ///	chemical properties resembling its lighter group 15 siblings arsenic
    ///	and antimony.
    /// </summary>
    const struct BISMUTH
    {
        const int group = 15;
        const string type = "Post-Transition Metal";
        const string crystal_type = "Rhombohedral";
        const string electron_configuration = "[Xe]4f14 5d10 6s2 6p3";
        const long double atomic_weight = 208.98; // u (g/mol)
        const int atomic_number = 83;
        const vector<long double> energy_levels = {2, 8, 18, 32, 18, 5};
        const long double density_STP = 9780; // kg/m^3
        const long double melting_point = 271.3; // C
        const long double boiling_point = 1564.0; // C
        const long double thermal_conductivity = 8.0; // W/mK
        const long double electric_conductivity = .77; // MS/m
        const long double resistivity = 1.3e-6; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 122.0; // J/kgK
        const long double heat_vaporization = 160.0; // kJ/mol
        const long double heat_fusion = 10.9; // kJ/mol
        const long double ionization_1st = 7.29; // eV
        static void display()
        {
            displayElementImg(getFileName(83));
        }
    } Bi;

    /// <summary>
    ///	Polonium is a chemical element with the symbol Po and atomic number 84.
    ///	A rare and highly radioactive metal with no stable isotopes, polonium
    ///	is chemically similar to selenium and tellurium, though its metallic
    ///	character resembles that of its horizontal neighbors in the periodic
    ///	table: thallium, lead, and bismuth.
    /// </summary>
    const struct POLONIUM
    {
        const int group = 16;
        const string type = "Post-Transition Metal";
        const string crystal_type = "Simple Cubic / Rhombohedral";
        const string electron_configuration = "[Xe]4f14 5d10 6s2 6p4";
        const long double atomic_weight = (209); // u (g/mol)
        const int atomic_number = 84;
        const vector<long double> energy_levels = {2, 8, 18, 32, 18, 6};
        const long double density_STP = 9196.0; // kg/m^3
        const long double melting_point = 255.0; // C
        const long double boiling_point = 961.9; // C
        const long double thermal_conductivity = FP_NAN; // W/mK
        const long double electric_conductivity = 2.3; // MS/m
        const long double resistivity = 4.3e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = 100.0; // kJ/mol
        const long double heat_fusion = 13.0; // kJ/mol
        const long double ionization_1st = 8.417; // eV
        static void display()
        {
            displayElementImg(getFileName(84));
        }
    } Po;

    /// <summary>
    ///	Astatine is a chemical element with the symbol At and atomic number 85.
    ///	It is the rarest naturally occurring element in the Earth's crust,
    ///	occurring only as the decay product of various heavier elements.
    ///	All of astatine's isotopes are short-lived; the most stable is
    ///	astatine-210, with a half-life of 8.1 hours.
    /// </summary>
    const struct ASTATINE
    {
        const int group = 17;
        const string type = "Metalloid";
        const string crystal_type = "Face-Centered Cubic:?";
        const string electron_configuration = "[Xe]4f14 5d10 6s2 6p5";
        const long double atomic_weight = (210); // u (g/mol)
        const int atomic_number = 85;
        const vector<long double> energy_levels = {2, 8, 18, 32, 18, 7};
        const long double density_STP = FP_NAN; // kg/m^3
        const long double melting_point = 302.0; // C
        const long double boiling_point = 350.0; // C
        const long double thermal_conductivity = 2.0; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = 40.0; // kJ/mol
        const long double heat_fusion = 6.0; // kJ/mol
        const long double ionization_1st = 9.22; // eV
        static void display()
        {
            displayElementImg(getFileName(85));
        }
    } At;

    /// <summary>
    ///	Radon is a chemical element with the symbol Rn and atomic number 86.
    ///	It is a radioactive, colorless, odorless, tasteless noble gas.
    /// </summary>
    const struct RADON
    {
        const int group = 18;
        const string type = "Noble Gas";
        const string crystal_type = "Face-Centered Cubic";
        const string electron_configuration = "[Xe]4f14 5d10 6s2 6p6";
        const long double atomic_weight = (222); // u (g/mol)
        const int atomic_number = 86;
        const vector<long double> energy_levels = {2, 8, 18, 32, 18, 8};
        const long double density_STP = 9.73; // kg/m^3
        const long double melting_point = -71.1; // C
        const long double boiling_point = -61.85; // C
        const long double thermal_conductivity = .00361; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 93.65; // J/kgK
        const long double heat_vaporization = 17.0; // kJ/mol
        const long double heat_fusion = 3.0; // kJ/mol
        const long double ionization_1st = 10.75; // eV
        static void display()
        {
            displayElementImg(getFileName(86));
        }
    } Rn;

    /// <summary>
    ///	Francium is a chemical element with the symbol Fr and atomic number 87.
    ///	Prior to its discovery, it was referred to as eka-caesium. It is extremely
    ///	radioactive; its most stable isotope, francium-223, has a half-life
    ///	of only 22 minutes.
    /// </summary>
    const struct FRANCIUM
    {
        const int group = 1;
        const string type = "Alkali Metal";
        const string crystal_type = "Body-Centered Cubic:?";
        const string electron_configuration = "[Rn]7s1";
        const long double atomic_weight = (223); // u (g/mol)
        const int atomic_number = 87;
        const vector<long double> energy_levels = {2, 8, 18, 32, 18, 8, 1};
        const long double density_STP = FP_NAN; // kg/m^3
        const long double melting_point = 20.9; // C
        const long double boiling_point = 650.0; // C
        const long double thermal_conductivity = FP_NAN; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = 65.0; // kJ/mol
        const long double heat_fusion = 2.0; // kJ/mol
        const long double ionization_1st = 3.94; // eV
        static void display()
        {
            displayElementImg(getFileName(87));
        }
    } Fr;

    /// <summary>
    ///	Radium is a chemical element with the symbol Ra and atomic number 88.
    ///	It is the sixth element in group 2 of the periodic table, also known
    ///	as the alkaline earth metals. Pure radium is silvery-white, but it
    ///	readily reacts with nitrogen on exposure to air, forming a black
    ///	surface layer of radium nitride.
    /// </summary>
    const struct RADIUM
    {
        const int group = 2;
        const string type = "Alkaline Earth Metal";
        const string crystal_type = "Body-Centered Cubic";
        const string electron_configuration = "[Rn]7s2";
        const long double atomic_weight = (226); // u (g/mol)
        const int atomic_number = 88;
        const vector<long double> energy_levels = {2, 8, 18, 32, 18, 8, 2};
        const long double density_STP = 5000.0; // kg/m^3
        const long double melting_point = 700.0; // C
        const long double boiling_point = 1737.0; // C
        const long double thermal_conductivity = 19.0; // W/mK
        const long double electric_conductivity = 1.0; // MS/m
        const long double resistivity = 1.0e-6; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 92.0; // J/kgK
        const long double heat_vaporization = 125.0; // kJ/mol
        const long double heat_fusion = 8.0; // kJ/mol
        const long double ionization_1st = 5.279; // eV
        static void display()
        {
            displayElementImg(getFileName(88));
        }
    } Ra;


    /// <summary>
    ///	Actinium is a chemical element with the symbol Ac and atomic number 89.
    ///	It was first isolated by Friedrich Oskar Giesel in 1902, who gave it
    ///	the name emanium; the element got its name by being wrongly identified
    ///	with a substance André-Louis Debierne found and called actinium.
    /// </summary>
    const struct ACTINIUM
    {
        const int group = 3;
        const string type = "Actinoid";
        const string crystal_type = "Face-Centered Cubic";
        const string electron_configuration = "[Rn]6d1 7s2";
        const long double atomic_weight = (227); // u (g/mol)
        const int atomic_number = 89;
        const vector<long double> energy_levels = {2, 8, 18, 32, 18, 9, 2};
        const long double density_STP = 10070.0; // kg/m^3
        const long double melting_point = 1050.0; // C
        const long double boiling_point = 3200.0; // C
        const long double thermal_conductivity = 12.0; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 120.0; // J/kgK
        const long double heat_vaporization = 400.0; // kJ/mol
        const long double heat_fusion = 14.0; // kJ/mol
        const long double ionization_1st = 5.17; // eV
        static void display()
        {
            displayElementImg(getFileName(89));
        }
    } Ac;

    /// <summary>
    ///	Thorium is a weakly radioactive metallic chemical element with the symbol Th and atomic number 90.
    ///	Thorium is silvery and tarnishes black when it is exposed to air, forming
    ///	thorium dioxide; it is moderately soft, malleable, and has a high melting point.
    /// </summary>
    const struct THORIUM
    {
        const int group = 3;
        const string type = "Actinoid";
        const string crystal_type = "Face-Centered Cubic";
        const string electron_configuration = "[Rn]6d2 7s2";
        const long double atomic_weight = 232.04; // u (g/mol)
        const int atomic_number = 90;
        const vector<long double> energy_levels = {2, 8, 18, 32, 18, 10, 2};
        const long double density_STP = 11724.0; // kg/m^3
        const long double melting_point = 1750.0; // C
        const long double boiling_point = 4820.0; // C
        const long double thermal_conductivity = 54.0; // W/mK
        const long double electric_conductivity = 6.7; // MS/m
        const long double resistivity = 1.5e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 118.0; // J/kgK
        const long double heat_vaporization = 530.0; // kJ/mol
        const long double heat_fusion = 16.0; // kJ/mol
        const long double ionization_1st = 6.08; // eV
        static void display()
        {
            displayElementImg(getFileName(90));
        }
    } Th;

    /// <summary>
    ///	Protactinium is a chemical element with the symbol Pa and atomic number 91.
    ///	It is a dense, silvery-gray actinide metal which readily reacts with oxygen,
    ///	water vapor and inorganic acids.
    /// </summary>
    const struct PROTACTINIUM
    {
        const int group = 3;
        const string type = "Actinoid";
        const string crystal_type = "Tetragonal";
        const string electron_configuration = "[Rn]5f2 6d1 7s2";
        const long double atomic_weight = 231.04; // u (g/mol)
        const int atomic_number = 91;
        const vector<long double> energy_levels = {2, 8, 18, 32, 20, 9, 2};
        const long double density_STP = 15370.0; // kg/m^3
        const long double melting_point = 1572.0; // C
        const long double boiling_point = 4000.0; // C
        const long double thermal_conductivity = 47.0; // W/mK
        const long double electric_conductivity = 5.6; // MS/m
        const long double resistivity = 1.8e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 99.1; // J/kgK
        const long double heat_vaporization = 470.0; // kJ/mol
        const long double heat_fusion = 15.0; // kJ/mol
        const long double ionization_1st = 5.89; // eV
        static void display()
        {
            displayElementImg(getFileName(91));
        }
    } Pa;

    /// <summary>
    ///	Uranium is a chemical element with the symbol U and atomic number 92.
    ///	It is a silvery-grey metal in the actinide series of the periodic table.
    ///	A uranium atom has 92 protons and 92 electrons, of which 6 are
    ///	valence electrons.
    /// </summary>
    const struct URANIUM
    {
        const int group = 3;
        const string type = "Actinoid";
        const string crystal_type = "Orthorhombic";
        const string electron_configuration = "[Rn]5f3 6d1 7s2";
        const long double atomic_weight = 238.03; // u (g/mol)
        const int atomic_number = 92;
        const vector<long double> energy_levels = {2, 8, 18, 32, 21, 9, 2};
        const long double density_STP = 19050.0; // kg/m^3
        const long double melting_point = 1135.0; // C
        const long double boiling_point = 3900.0; // C
        const long double thermal_conductivity = 27.0; // W/mK
        const long double electric_conductivity = 3.6; // MS/m
        const long double resistivity = 2.8e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = 116.0; // J/kgK
        const long double heat_vaporization = 420.0; // kJ/mol
        const long double heat_fusion = 14.0; // kJ/mol
        const long double ionization_1st = 6.194; // eV
        static void display()
        {
            displayElementImg(getFileName(192));
        }
    } U;

    /// <summary>
    ///	Neptunium is a chemical element with the symbol Np and atomic number 93.
    ///	A radioactive actinide metal, neptunium is the first transuranic element.
    ///	Its position in the periodic table just after uranium, named after the
    ///	planet Uranus, led to it being named after Neptune, the next planet
    ///	beyond Uranus.
    /// </summary>
    const struct NEPTUNIUM
    {
        const int group = 3;
        const string type = "Actinoid";
        const string crystal_type = "Orthorhombic";
        const string electron_configuration = "[Rn]5f4 6d1 7s2";
        const long double atomic_weight = (237); // u (g/mol)
        const int atomic_number = 93;
        const vector<long double> energy_levels = {2, 8, 18, 32, 22, 9, 2};
        const long double density_STP = 20450.0; // kg/m^3
        const long double melting_point = 644.0; // C
        const long double boiling_point = 4000.0; // C
        const long double thermal_conductivity = 6.0; // W/mK
        const long double electric_conductivity = .83; // MS/m
        const long double resistivity = 1.2e-6; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = 335.0; // kJ/mol
        const long double heat_fusion = 10.0; // kJ/mol
        const long double ionization_1st = 6.265; // eV
        static void display()
        {
            displayElementImg(getFileName(93));
        }
    } Np;

    /// <summary>
    ///	Plutonium is a radioactive chemical element with the symbol Pu and atomic number 94.
    ///	It is an actinide metal of silvery-gray appearance that tarnishes when exposed to air,
    ///	and forms a dull coating when oxidized. The element normally exhibits six allotropes
    ///	and four oxidation states.
    /// </summary>
    const struct PLUTONIUM
    {
        const int group = 3;
        const string type = "Actinoid";
        const string crystal_type = "Monoclinic";
        const string electron_configuration = "[Rn]5f6 7s2";
        const long double atomic_weight = (244); // u (g/mol)
        const int atomic_number = 94;
        const vector<long double> energy_levels = {2, 8, 18, 32, 24, 8, 2};
        const long double density_STP = 19816.0; // kg/m^3
        const long double melting_point = 640.0; // C
        const long double boiling_point = 3230.0; // C
        const long double thermal_conductivity = 6.0; // W/mK
        const long double electric_conductivity = .67; // MS/m
        const long double resistivity = 1.5e-6; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = 325.0; // kJ/mol
        const long double heat_fusion = FP_NAN; // kJ/mol
        const long double ionization_1st = 6.060; // eV
        static void display()
        {
            displayElementImg(getFileName(94));
        }
    } Pu;

    /// <summary>
    ///	Americium is a synthetic radioactive chemical element with the symbol Am and atomic number 95.
    ///	It is a transuranic member of the actinide series, in the periodic table located under
    ///	the lanthanide element europium, and thus by analogy was named after the Americas.
    /// </summary>
    const struct AMERICIUM
    {
        const int group = 3;
        const string type = "Actinoid";
        const string crystal_type = "Double Hexagonal Close Packed";
        const string electron_configuration = "[Rn]5f7 7s2";
        const long double atomic_weight = (243); // u (g/mol)
        const int atomic_number = 95;
        const vector<long double> energy_levels = {2, 8, 18, 32, 25, 8, 2};
        const long double density_STP = 13670.0; // kg/m^3
        const long double melting_point = 1176.0; // C
        const long double boiling_point = 2011.0; // C
        const long double thermal_conductivity = 10.0; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = FP_NAN; // kJ/mol
        const long double heat_fusion = FP_NAN; // kJ/mol
        const long double ionization_1st = 5.99; // eV
        static void display()
        {
            displayElementImg(getFileName(95));
        }
    } Am;

    /// <summary>
    ///	Curium is a transuranic radioactive chemical element with the symbol Cm and atomic number 96.
    ///	This element of the actinide series was named after Marie and Pierre Curie, both known
    ///	for their research on radioactivity.
    /// </summary>
    const struct CURIUM
    {
        const int group = 3;
        const string type = "Actinoid";
        const string crystal_type = "Double Hexagonal Close Packed";
        const string electron_configuration = "[Rn]5f7 6d1 7s2";
        const long double atomic_weight = (247); // u (g/mol)
        const int atomic_number = 96;
        const vector<long double> energy_levels = {2, 8, 18, 32, 25, 9, 2};
        const long double density_STP = 13510.0; // kg/m^3
        const long double melting_point = 1345.0; // C
        const long double boiling_point = 3110.0; // C
        const long double thermal_conductivity = FP_NAN; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = FP_NAN; // kJ/mol
        const long double heat_fusion = FP_NAN; // kJ/mol
        const long double ionization_1st = 6.02; // eV
        static void display()
        {
            displayElementImg(getFileName(96));
        }
    } Cm;

    /// <summary>
    ///	Berkelium is a transuranic radioactive chemical element with the symbol Bk and atomic number 97.
    ///	It is a member of the actinide and transuranium element series. It is named
    ///	after the city of Berkeley, California, the location of the Lawrence Berkeley
    ///	National Laboratory where it was discovered in December 1949.
    /// </summary>
    const struct BERKELIUM
    {
        const int group = 3;
        const string type = "Actinoid";
        const string crystal_type = "Double Hexagonal Close Packed";
        const string electron_configuration = "[Rn]5f9 7s2";
        const long double atomic_weight = (247); // u (g/mol)
        const int atomic_number = 97;
        const vector<long double> energy_levels = {2, 8, 18, 32, 27, 8, 2};
        const long double density_STP = 14780.00; // kg/m^3
        const long double melting_point = 1050.0; // C
        const long double boiling_point = FP_NAN; // C
        const long double thermal_conductivity = 10.0; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = FP_NAN; // kJ/mol
        const long double heat_fusion = FP_NAN; // kJ/mol
        const long double ionization_1st = 6.23; // eV
        static void display()
        {
            displayElementImg(getFileName(97));
        }
    } Bk;

    /// <summary>
    ///	Californium is a radioactive chemical element with the symbol Cf and atomic number 98.
    ///	The element was first synthesized in 1950 at the Lawrence Berkeley National Laboratory,
    ///	by bombarding curium with alpha particles.
    /// </summary>
    const struct CALIFORNIUM
    {
        const int group = 3;
        const string type = "Actinoid";
        const string crystal_type = "Double Hexagonal Close Packed";
        const string electron_configuration = "[Rn]5f10 7s2";
        const long double atomic_weight = (251); // u (g/mol)
        const int atomic_number = 98;
        const vector<long double> energy_levels = {2, 8, 18, 32, 28, 8, 2};
        const long double density_STP = 15100.0; // kg/m^3
        const long double melting_point = 899.9; // C
        const long double boiling_point = FP_NAN; // C
        const long double thermal_conductivity = FP_NAN; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = FP_NAN; // kJ/mol
        const long double heat_fusion = FP_NAN; // kJ/mol
        const long double ionization_1st = 6.30; // eV
        static void display()
        {
            displayElementImg(getFileName(98));
        }
    } Cf;

    /// <summary>
    ///	Einsteinium is a synthetic element with the symbol Es and atomic number 99.
    ///	Einsteinium is a member of the actinide series and it is the seventh transuranic
    ///	element. It is named to honor Albert Einstein. Einsteinium was discovered
    ///	as a component of the debris of the first hydrogen bomb explosion in 1952.
    /// </summary>
    const struct EINSTEINIUM
    {
        const int group = 3;
        const string type = "Actinoid";
        const string crystal_type = "Face-Centered Cubic";
        const string electron_configuration = "[Rn]5f11 7s2";
        const long double atomic_weight = (252); // u (g/mol)
        const int atomic_number = 99;
        const vector<long double> energy_levels = {2, 8, 18, 32, 29, 8, 2};
        const long double density_STP = FP_NAN; // kg/m^3
        const long double melting_point = 859.9; // C
        const long double boiling_point = FP_NAN; // C
        const long double thermal_conductivity = FP_NAN; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = FP_NAN; // kJ/mol
        const long double heat_fusion = FP_NAN; // kJ/mol
        const long double ionization_1st = 6.42; // eV
        static void display()
        {
            displayElementImg(getFileName(99));
        }
    } Es;

    /// <summary>
    ///	Fermium is a synthetic element with the symbol Fm and atomic number 100.
    ///	It is an actinide and the heaviest element that can be formed by neutron
    ///	bombardment of lighter elements, and hence the last element that can be
    ///	prepared in macroscopic quantities, although pure fermium metal has not
    ///	yet been prepared.
    /// </summary>
    const struct FERMIUM
    {
        const int group = 3;
        const string type = "Actinoid";
        const string crystal_type = "Face-Centered Cubic";
        const string electron_configuration = "[Rn]5f12 7s2";
        const long double atomic_weight = (257); // u (g/mol)
        const int atomic_number = 100;
        const vector<long double> energy_levels = {2, 8, 18, 32, 30, 8, 2};
        const long double density_STP = FP_NAN; // kg/m^3
        const long double melting_point = 1500.0; // C
        const long double boiling_point = FP_NAN; // C
        const long double thermal_conductivity = FP_NAN; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = FP_NAN; // kJ/mol
        const long double heat_fusion = FP_NAN; // kJ/mol
        const long double ionization_1st = 6.50; // eV
        static void display()
        {
            displayElementImg(getFileName(100));
        }
    } Fm;

    /// <summary>
    ///	Mendelevium is a synthetic element with the symbol Md and atomic number 101.
    ///	A metallic radioactive transuranic element in the actinide series, it is the
    ///	first element by atomic number that currently cannot be produced in
    ///	macroscopic quantities through neutron bombardment of lighter elements.
    /// </summary>
    const struct MANDELEVIUM
    {
        const int group = 3;
        const string type = "Actinoid";
        const string crystal_type = "Face-Centered Cubic";
        const string electron_configuration = "[Rn]5f13 7s2";
        const long double atomic_weight = (258); // u (g/mol)
        const int atomic_number = 101;
        const vector<long double> energy_levels = {2, 8, 18, 32, 31, 8, 2};
        const long double density_STP = FP_NAN; // kg/m^3
        const long double melting_point = 830.0; // C
        const long double boiling_point = FP_NAN; // C
        const long double thermal_conductivity = FP_NAN; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = FP_NAN; // kJ/mol
        const long double heat_fusion = FP_NAN; // kJ/mol
        const long double ionization_1st = 6.58; // eV
        static void display()
        {
            displayElementImg(getFileName(101));
        }
    } Md;

    /// <summary>
    ///	Nobelium is a synthetic chemical element with the symbol No and atomic number 102.
    ///	It is named in honor of Alfred Nobel, the inventor of dynamite and benefactor
    ///	of science. A radioactive metal, it is the tenth transuranic element and is
    ///	the penultimate member of the actinide series.
    /// </summary>
    const struct NOBELIUM
    {
        const int group = 3;
        const string type = "Actinoid";
        const string crystal_type = "Face-Centered Cubic";
        const string electron_configuration = "[Rn]5f14 7s2";
        const long double atomic_weight = (259); // u (g/mol)
        const int atomic_number = 102;
        const vector<long double> energy_levels = {2, 8, 18, 32, 32, 8, 2};
        const long double density_STP = FP_NAN; // kg/m^3
        const long double melting_point = 830.0; // C
        const long double boiling_point = FP_NAN; // C
        const long double thermal_conductivity = FP_NAN; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = FP_NAN; // kJ/mol
        const long double heat_fusion = FP_NAN; // kJ/mol
        const long double ionization_1st = 6.65; // eV
        static void display()
        {
            displayElementImg(getFileName(102));
        }
    } No;

    /// <summary>
    ///	Lawrencium is a synthetic chemical element with the symbol Lr and atomic number 103.
    ///	It is named in honor of Ernest Lawrence, inventor of the cyclotron, a
    ///	device that was used to discover many artificial radioactive elements.
    /// </summary>
    const struct LAWRENCIUM
    {
        const int group = 3;
        const string type = "Actinoid";
        const string crystal_type = "Hexagonal Close Packed:?";
        const string electron_configuration = "[Rn]5f14 7s2 7p1";
        const long double atomic_weight = (266); // u (g/mol)
        const int atomic_number = 103;
        const vector<long double> energy_levels = {2, 8, 18, 32, 32, 8, 3};
        const long double density_STP = FP_NAN; // kg/m^3
        const long double melting_point = 1600.0; // C
        const long double boiling_point = FP_NAN; // C
        const long double thermal_conductivity = FP_NAN; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = FP_NAN; // kJ/mol
        const long double heat_fusion = FP_NAN; // kJ/mol
        const long double ionization_1st = 4.87; // eV
        static void display()
        {
            displayElementImg(getFileName(103));
        }
    } Lr;

    /// <summary>
    ///	Rutherfordium is a synthetic chemical element with the symbol Rf and atomic number 104,
    ///	named after New Zealand physicist Ernest Rutherford. As a synthetic element,
    ///	it is not found in nature and can only be created in a laboratory.
    /// </summary>
    const struct RUTHERFORDIUM
    {
        const int group = 4;
        const string type = "Transition Metal";
        const string crystal_type = "Hexagonal Close Packed:?";
        const string electron_configuration = "[Rn]5f14 6d2 7s2";
        const long double atomic_weight = (267); // u (g/mol)
        const int atomic_number = 104;
        const vector<long double> energy_levels = {2, 8, 18, 32, 32, 10, 2};
        const long double density_STP = FP_NAN; // kg/m^3
        const long double melting_point = FP_NAN; // C
        const long double boiling_point = FP_NAN; // C
        const long double thermal_conductivity = FP_NAN; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = FP_NAN; // kJ/mol
        const long double heat_fusion = FP_NAN; // kJ/mol
        const long double ionization_1st = 6.01; // eV
        static void display()
        {
            displayElementImg(getFileName(104));
        }
    } Rf;

    /// <summary>
    ///	Dubnium is a synthetic chemical element with the symbol Db and atomic number 105.
    ///	Dubnium is highly radioactive: the most stable known isotope, dubnium-268,
    ///	has a half-life of about 28 hours. This greatly limits extended research
    ///	on dubnium. Dubnium does not occur naturally on Earth and is produced
    ///	artificially.
    /// </summary>
    const struct DUBNIUM
    {
        const int group = 5;
        const string type = "Transition Metal";
        const string crystal_type = "Body-Centered Cubic:?";
        const string electron_configuration = "[Rn]5f14 6d3 7s2";
        const long double atomic_weight = (268); // u (g/mol)
        const int atomic_number = 105;
        const vector<long double> energy_levels = {2, 8, 18, 32, 32, 11, 2};
        const long double density_STP = FP_NAN; // kg/m^3
        const long double melting_point = FP_NAN; // C
        const long double boiling_point = FP_NAN; // C
        const long double thermal_conductivity = FP_NAN; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = FP_NAN; // kJ/mol
        const long double heat_fusion = FP_NAN; // kJ/mol
        const long double ionization_1st = FP_NAN; // eV
        static void display()
        {
            displayElementImg(getFileName(105));
        }
    } Db;

    /// <summary>
    ///	Seaborgium is a synthetic chemical element with the symbol Sg and atomic number 106.
    ///	It is named after the American nuclear chemist Glenn T. Seaborg. As a synthetic
    ///	element, it can be created in a laboratory but is not found in nature.
    /// </summary>
    const struct SEABORGIUM
    {
        const int group = 6;
        const string type = "Transition Metal";
        const string crystal_type = "Body-Centered Cubic:?";
        const string electron_configuration = "[Rn]5f14 6d4 7s2";
        const long double atomic_weight = (269); // u (g/mol)
        const int atomic_number = 106;
        const vector<long double> energy_levels = {2, 8, 18, 32, 32, 12, 2};
        const long double density_STP = FP_NAN; // kg/m^3
        const long double melting_point = FP_NAN; // C
        const long double boiling_point = FP_NAN; // C
        const long double thermal_conductivity = FP_NAN; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = FP_NAN; // kJ/mol
        const long double heat_fusion = FP_NAN; // kJ/mol
        const long double ionization_1st = FP_NAN; // eV
        static void display()
        {
            displayElementImg(getFileName(106));
        }
    } Sg;

    /// <summary>
    ///	Bohrium is a synthetic chemical element with the symbol Bh and atomic number 107.
    ///	It is named after Danish physicist Niels Bohr. As a synthetic element,
    ///	it can be created in a laboratory but is not found in nature.
    /// </summary>
    const struct BOHRIUM
    {
        const int group = 7;
        const string type = "Transition Metal";
        const string crystal_type = "Hexagonal Close Packed:?";
        const string electron_configuration = "[Rn]5f14 6d5 7s2";
        const long double atomic_weight = (270); // u (g/mol)
        const int atomic_number = 107;
        const vector<long double> energy_levels = {2, 8, 18, 32, 32, 13, 2};
        const long double density_STP = FP_NAN; // kg/m^3
        const long double melting_point = FP_NAN; // C
        const long double boiling_point = FP_NAN; // C
        const long double thermal_conductivity = FP_NAN; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = FP_NAN; // kJ/mol
        const long double heat_fusion = FP_NAN; // kJ/mol
        const long double ionization_1st = FP_NAN; // eV
        static void display()
        {
            displayElementImg(getFileName(107));
        }
    } Bh;

    /// <summary>
    ///	Hassium is a chemical element with the symbol Hs and the atomic number 108.
    ///	Hassium is highly radioactive; its most stable known isotopes have half-lives
    ///	of approximately ten seconds.
    /// </summary>
    const struct HASSIUM
    {
        const int group = 8;
        const string type = "Transition Metal";
        const string crystal_type = "Hexagonal Close Packed:?";
        const string electron_configuration = "[Rn]5f14 6d6 7s2";
        const long double atomic_weight = 277; // u (g/mol)
        const int atomic_number = 108;
        const vector<long double> energy_levels = {2, 8, 18, 32, 32, 14, 2};
        const long double density_STP = FP_NAN; // kg/m^3
        const long double melting_point = FP_NAN; // C
        const long double boiling_point = FP_NAN; // C
        const long double thermal_conductivity = FP_NAN; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = FP_NAN; // kJ/mol
        const long double heat_fusion = FP_NAN; // kJ/mol
        const long double ionization_1st = FP_NAN; // eV
        static void display()
        {
            displayElementImg(getFileName(108));
        }
    } Hs;

    /// <summary>
    ///	Meitnerium is a synthetic chemical element with the symbol Mt and atomic number 109.
    ///	It is an extremely radioactive synthetic element. The most stable known isotope,
    ///	meitnerium-278, has a half-life of 4.5 seconds, although the unconfirmed
    ///	meitnerium-282 may have a longer half-life of 67 seconds.
    /// </summary>
    const struct MEITNERIUM
    {
        const int group = 9;
        const string type = "N/A";
        const string crystal_type = "Face-Centered Cubic:?";
        const string electron_configuration = "([Rn]5f14 6d7 7s2):?";
        const long double atomic_weight = 278; // u (g/mol)
        const int atomic_number = 109;
        const vector<long double> energy_levels = {2, 8, 18, 32, 32, 15, 2};
        const long double density_STP = FP_NAN; // kg/m^3
        const long double melting_point = FP_NAN; // C
        const long double boiling_point = FP_NAN; // C
        const long double thermal_conductivity = FP_NAN; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = FP_NAN; // kJ/mol
        const long double heat_fusion = FP_NAN; // kJ/mol
        const long double ionization_1st = FP_NAN; // eV
        static void display()
        {
            displayElementImg(getFileName(109));
        }
    } Mt;

    /// <summary>
    ///	Darmstadtium is a chemical element with the symbol Ds and atomic number 110.
    ///	It is an extremely radioactive synthetic element. The most stable known
    ///	isotope, darmstadtium-281, has a half-life of approximately 12.7 seconds.
    /// </summary>
    const struct DARMSTADTIUM
    {
        const int group = 10;
        const string type = "N/A";
        const string crystal_type = "Body-Centered Cubic:?";
        const string electron_configuration = "([Rn]5f14 6d9 7s1):?";
        const long double atomic_weight = 281; // u (g/mol)
        const int atomic_number = 110;
        const vector<long double> energy_levels = {2, 8, 18, 32, 32, 17, 1};
        const long double density_STP = FP_NAN; // kg/m^3
        const long double melting_point = FP_NAN; // C
        const long double boiling_point = FP_NAN; // C
        const long double thermal_conductivity = FP_NAN; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = FP_NAN; // kJ/mol
        const long double heat_fusion = FP_NAN; // kJ/mol
        const long double ionization_1st = FP_NAN; // eV
        static void display()
        {
            displayElementImg(getFileName(110));
        }
    } Ds;


    /// <summary>
    ///	Roentgenium is a chemical element with the symbol Rg and atomic number 111.
    ///	It is an extremely radioactive synthetic element that can be created in a
    ///	laboratory but is not found in nature.
    /// </summary>
    const struct ROENTGENUIM
    {
        const int group = 11;
        const string type = "N/A";
        const string crystal_type = "Body-Centered Cubic:?";
        const string electron_configuration = "([Rn]5f14 6d10 7s1):?";
        const long double atomic_weight = 282; // u (g/mol)
        const int atomic_number = 111;
        const vector<long double> energy_levels = {2, 8, 18, 32, 32, 17, 2};
        const long double density_STP = FP_NAN; // kg/m^3
        const long double melting_point = FP_NAN; // C
        const long double boiling_point = FP_NAN; // C
        const long double thermal_conductivity = FP_NAN; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = FP_NAN; // kJ/mol
        const long double heat_fusion = FP_NAN; // kJ/mol
        const long double ionization_1st = FP_NAN; // eV
        static void display()
        {
            displayElementImg(getFileName(111));
        }
    } Rg;

    /// <summary>
    ///	Copernicium is a synthetic chemical element with the symbol Cn and atomic number 112.
    ///	Its known isotopes are extremely radioactive, and have only been created in a laboratory.
    ///	The most stable known isotope, copernicium-285, has a half-life of approximately 28 seconds.
    /// </summary>
    const struct COPERNICIUM
    {
        const int group = 12;
        const string type = "N/A";
        const string crystal_type = "Hexagonal Close Packed:?";
        const string electron_configuration = "([Rn]5f14 6d10 7s2):?";
        const long double atomic_weight = 285; // u (g/mol)
        const int atomic_number = 112;
        const vector<long double> energy_levels = {2, 8, 18, 32, 32, 18, 2};
        const long double density_STP = FP_NAN; // kg/m^3
        const long double melting_point = FP_NAN; // C
        const long double boiling_point = FP_NAN; // C
        const long double thermal_conductivity = FP_NAN; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = FP_NAN; // kJ/mol
        const long double heat_fusion = FP_NAN; // kJ/mol
        const long double ionization_1st = FP_NAN; // eV
        static void display()
        {
            displayElementImg(getFileName(112));
        }
    } Cn;

    /// <summary>
    ///	Nihonium is a synthetic chemical element with the symbol Nh and atomic number 113.
    ///	It is extremely radioactive; its most stable known isotope, nihonium-286,
    ///	has a half-life of about 10 seconds. In the periodic table, nihonium is
    ///	a transactinide element in the p-block. It is a member of period 7
    ///	and group 13.
    /// </summary>
    const struct NIHONIUM
    {
        const int group = 13;
        const string type = "N/A";
        const string crystal_type = "Hexagonal Close Packed:?";
        const string electron_configuration = "([Rn]5f14 6d10 7s2 7p1):?";
        const long double atomic_weight = 286; // u (g/mol)
        const int atomic_number = 113;
        const vector<long double> energy_levels = {2, 8, 18, 32, 32, 18, 3};
        const long double density_STP = FP_NAN; // kg/m^3
        const long double melting_point = FP_NAN; // C
        const long double boiling_point = FP_NAN; // C
        const long double thermal_conductivity = FP_NAN; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = FP_NAN; // kJ/mol
        const long double heat_fusion = FP_NAN; // kJ/mol
        const long double ionization_1st = FP_NAN; // eV
        static void display()
        {
            displayElementImg(getFileName(113));
        }
    } Nh;

    /// <summary>
    ///	Flerovium is a superheavy artificial chemical element with the symbol Fl and atomic number 114.
    ///	It is an extremely radioactive synthetic element. The element is named
    ///	after the Flerov Laboratory of Nuclear Reactions of the Joint Institute
    ///	for Nuclear Research in Dubna, Russia, where the element was discovered in 1998.
    /// </summary>
    const struct FLEROVIUM
    {
        const int group = 14;
        const string type = "N/A";
        const string crystal_type = "N/A";
        const string electron_configuration = "([Rn]5f14 6d10 7s2 7p2):?";
        const long double atomic_weight = 289; // u (g/mol)
        const int atomic_number = 114;
        const vector<long double> energy_levels = {2, 8, 18, 32, 32, 18, 4};
        const long double density_STP = FP_NAN; // kg/m^3
        const long double melting_point = FP_NAN; // C
        const long double boiling_point = FP_NAN; // C
        const long double thermal_conductivity = FP_NAN; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = FP_NAN; // kJ/mol
        const long double heat_fusion = FP_NAN; // kJ/mol
        const long double ionization_1st = FP_NAN; // eV
        static void display()
        {
            displayElementImg(getFileName(114));
        }
    } Fl;

    /// <summary>
    ///	Moscovium is a synthetic chemical element with the symbol Mc and atomic number 115.
    ///	It was first synthesized in 2003 by a joint team of Russian and American scientists
    ///	at the Joint Institute for Nuclear Research in Dubna, Russia.
    /// </summary>
    const struct MOSCOVIUM
    {
        const int group = 15;
        const string type = "N/A";
        const string crystal_type = "N/A";
        const string electron_configuration = "([Rn]5f14 6d10 7s2 7p3):?";
        const long double atomic_weight = 290; // u (g/mol)
        const int atomic_number = 115;
        const vector<long double> energy_levels = {2, 8, 18, 32, 32, 18, 5};
        const long double density_STP = FP_NAN; // kg/m^3
        const long double melting_point = FP_NAN; // C
        const long double boiling_point = FP_NAN; // C
        const long double thermal_conductivity = FP_NAN; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = FP_NAN; // kJ/mol
        const long double heat_fusion = FP_NAN; // kJ/mol
        const long double ionization_1st = FP_NAN; // eV
        static void display()
        {
            displayElementImg(getFileName(115));
        }
    } Mc;

    /// <summary>
    ///	Livermorium is a synthetic chemical element with the symbol Lv and has an atomic number of 116.
    ///	It is an extremely radioactive element that has only been created in the
    ///	laboratory and has not been observed in nature.
    /// </summary>
    const struct LIVERMORIUM
    {
        const int group = 16;
        const string type = "N/A";
        const string crystal_type = "N/A";
        const string electron_configuration = "([Rn]5f14 6d10 7s2 7p4):?";
        const long double atomic_weight = 293; // u (g/mol)
        const int atomic_number = 116;
        const vector<long double> energy_levels = {2, 8, 18, 32, 32, 18, 6};
        const long double density_STP = FP_NAN; // kg/m^3
        const long double melting_point = FP_NAN; // C
        const long double boiling_point = FP_NAN; // C
        const long double thermal_conductivity = FP_NAN; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = FP_NAN; // kJ/mol
        const long double heat_fusion = FP_NAN; // kJ/mol
        const long double ionization_1st = FP_NAN; // eV
        static void display()
        {
            displayElementImg(getFileName(116));
        }
    } Lv;

    /// <summary>
    ///	Tennessine is a synthetic chemical element with the symbol Ts and atomic number 117.
    ///	It is the second-heaviest known element and the penultimate element of the
    ///	7th period of the periodic table.
    /// </summary>
    const struct TENNESSINE
    {
        const int group = 17;
        const string type = "N/A";
        const string crystal_type = "N/A";
        const string electron_configuration = "([Rn]5f14 6d10 7s2 7p5):?";
        const long double atomic_weight = 294; // u (g/mol)
        const int atomic_number = 117;
        const vector<long double> energy_levels = {2, 8, 18, 32, 32, 18, 7};
        const long double density_STP = FP_NAN; // kg/m^3
        const long double melting_point = FP_NAN; // C
        const long double boiling_point = FP_NAN; // C
        const long double thermal_conductivity = FP_NAN; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = FP_NAN; // kJ/mol
        const long double heat_fusion = FP_NAN; // kJ/mol
        const long double ionization_1st = FP_NAN; // eV
        static void display()
        {
            displayElementImg(getFileName(117));
        }
    } Ts;

    /// <summary>
    ///	Oganesson is a synthetic chemical element with the symbol Og and atomic number 118.
    ///	It was first synthesized in 2002 at the Joint Institute for Nuclear Research in Dubna,
    ///	near Moscow, Russia, by a joint team of Russian and American scientists.
    /// </summary>
    const struct OGANESSON
    {
        const int group = 18;
        const string type = "N/A";
        const string crystal_type = "Face-centered cubic:?";
        const string electron_configuration = "([Rn]5f14 6d10 7s2 7p6):?";
        const long double atomic_weight = 294; // u (g/mol)
        const int atomic_number = 118;
        const vector<long double> energy_levels = {2, 8, 18, 32, 32, 18, 8};
        const long double density_STP = FP_NAN; // kg/m^3
        const long double melting_point = FP_NAN; // C
        const long double boiling_point = FP_NAN; // C
        const long double thermal_conductivity = FP_NAN; // W/mK
        const long double electric_conductivity = FP_NAN; // MS/m
        const long double resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        const long double heat_specific = FP_NAN; // J/kgK
        const long double heat_vaporization = FP_NAN; // kJ/mol
        const long double heat_fusion = FP_NAN; // kJ/mol
        const long double ionization_1st = FP_NAN; // eV
        static void display()
        {
            displayElementImg(getFileName(118));
        }
    } Og;


private:
    static void loadImage(const char* pathname, sf::Texture& texture, sf::Sprite& sprite)
    {
        texture.loadFromFile(pathname);     // load it from the file
        sprite.setTexture(texture);         // put that texture in our sprite
        // the rectangle of the texture to use for this
        sprite.setTextureRect( sf::IntRect(0,0,screenSize_X,screenSize_Y) );
    }
private:
    static void displayElementImg(const char elementName[])
    {

        // Create our window
        sf::RenderWindow window(
                sf::VideoMode(screenSize_X,screenSize_Y),       // size of the client area we want
                "Display an Image"                              // The text to appear on the window title
        );

        // load our image
        sf::Texture     texture;        // the texture which will contain our pixel data
        sf::Sprite      sprite;         // the sprite which will actually draw it
        loadImage(elementName,texture,sprite);

        // Set FPS so this draws at 60 FPS (note:  I didn't do this for the WinAPI version because it'd be too hard for such
        //  a small example)
        window.setFramerateLimit( 60 );

        bool program_running = true;        // true until the user wants to quit
        while(program_running)
        {
            // Do the event pump -- same idea as with Windows... look for events and process them
            sf::Event evt;
            while( window.pollEvent(evt) )      // while there are any events to process...
            {
                // process them. But we're only interested in the closed event
                if(evt.type == sf::Event::EventType::Closed)        // is this a close event?
                    program_running = false;                        // indicate that we want the window to close
            }

            // now that events are processed... draw our image
            window.draw(sprite);        // just draw it to the back buffer
            window.display();           // and display it so the back buffer moves to the front
        }
    }

private:
    static const char* getFileName(int atomicNumber)
    {
        switch (atomicNumber)
        {
            case 1:		return "img\\hydrogen.bmp";
            case 2:		return "img\\helium.bmp";
            case 3:		return "img\\lithium.bmp";
            case 4:		return "img\\beryllium.bmp";
            case 5:		return "img\\boron.bmp";
            case 6:		return "img\\carbon.bmp";
            case 7:		return "img\\nitrogen.bmp";
            case 8:		return "img\\oxygen.bmp";
            case 9:		return "img\\fluorine.bmp";
            case 10:	return "img\\neon.bmp";
            case 11:	return "img\\sodium.bmp";
            case 12:	return "img\\magnesium.bmp";
            case 13:	return "img\\aluminium.bmp";
            case 14:	return "img\\silicon.bmp";
            case 15:	return "img\\phosphorus.bmp";
            case 16:	return "img\\sulfur.bmp";
            case 17:	return "img\\chlorine.bmp";
            case 18:	return "img\\argon.bmp";
            case 19:	return "img\\potassium.bmp";
            case 20:	return "img\\calcium.bmp";
            case 21:	return "img\\scandium.bmp";
            case 22:	return "img\\titanium.bmp";
            case 23:	return "img\\vanadium.bmp";
            case 24:	return "img\\chromium.bmp";
            case 25:	return "img\\manganese.bmp";
            case 26:	return "img\\iron.bmp";
            case 27:	return "img\\cobalt.bmp";
            case 28:	return "img\\nickel.bmp";
            case 29:	return "img\\copper.bmp";
            case 30:	return "img\\zinc.bmp";
            case 31:	return "img\\gallium.bmp";
            case 32:	return "img\\germanium.bmp";
            case 33:	return "img\\arsenic.bmp";
            case 34:	return "img\\selenium.bmp";
            case 35:	return "img\\bromine.bmp";
            case 36:	return "img\\krypton.bmp";
            case 37:	return "img\\rubidium.bmp";
            case 38:	return "img\\strontium.bmp";
            case 39:	return "img\\yttrium.bmp";
            case 40:	return "img\\zirconium.bmp";
            case 41:	return "img\\niobium.bmp";
            case 42:	return "img\\molybdenum.bmp";
            case 43:	return "img\\technetium.bmp";
            case 44:	return "img\\ruthenium.bmp";
            case 45:	return "img\\rhodium.bmp";
            case 46:	return "img\\palladium.bmp";
            case 47:	return "img\\silver.bmp";
            case 48:	return "img\\cadmium.bmp";
            case 49:	return "img\\indium.bmp";
            case 50:	return "img\\tin.bmp";
            case 51:	return "img\\antimony.bmp";
            case 52:	return "img\\tellurium.bmp";
            case 53:	return "img\\iodine.bmp";
            case 54:	return "img\\xenon.bmp";
            case 55:	return "img\\ceasium.bmp";
            case 56:	return "img\\barium.bmp";
            case 57:	return "img\\lanthanum.bmp";
            case 58:	return "img\\cerium.bmp";
            case 59:	return "img\\praseodymium.bmp";
            case 60:	return "img\\neodymium.bmp";
            case 61:	return "img\\promethium.bmp";
            case 62:	return "img\\samarium.bmp";
            case 63:	return "img\\europium.bmp";
            case 64:	return "img\\gadolinium.bmp";
            case 65:	return "img\\terbium.bmp";
            case 66:	return "img\\dysprosium.bmp";
            case 67:	return "img\\holmium.bmp";
            case 68:	return "img\\erbium.bmp";
            case 69:	return "img\\thulium.bmp";
            case 70:	return "img\\ytterbium.bmp";
            case 71:	return "img\\lutetium.bmp";
            case 72:	return "img\\hafnium.bmp";
            case 73:	return "img\\tantalum.bmp";
            case 74:	return "img\\tungsten.bmp";
            case 75:	return "img\\rhenium.bmp";
            case 76:	return "img\\osmium.bmp";
            case 77:	return "img\\iridium.bmp";
            case 78:	return "img\\platinum.bmp";
            case 79:	return "img\\gold.bmp";
            case 80:	return "img\\mercury.bmp";
            case 81:	return "img\\thallium.bmp";
            case 82:	return "img\\lead.bmp";
            case 83:	return "img\\bismuth.bmp";
            case 84:	return "img\\polonium.bmp";
            case 85:	return "img\\astatine.bmp";
            case 86:	return "img\\radon.bmp";
            case 87:	return "img\\francium.bmp";
            case 88:	return "img\\radium.bmp";
            case 89:	return "img\\actinium.bmp";
            case 90:	return "img\\thorium.bmp";
            case 91:	return "img\\protactinium.bmp";
            case 92:	return "img\\uranium.bmp";
            case 93:	return "img\\neptunium.bmp";
            case 94:	return "img\\plutonium.bmp";
            case 95:	return "img\\americium.bmp";
            case 96:	return "img\\curium.bmp";
            case 97:	return "img\\berkelium.bmp";
            case 98:	return "img\\califomium.bmp";
            case 99:	return "img\\einsteinium.bmp";
            case 100:	return "img\\fermium.bmp";
            case 101:	return "img\\mendelevium.bmp";
            case 102:	return "img\\nobelium.bmp";
            case 103:	return "img\\lawrencium.bmp";
            case 104:	return "img\\rutherfordium.bmp";
            case 105:	return "img\\dubnium.bmp";
            case 106:	return "img\\seaborgium.bmp";
            case 107:	return "img\\bohrium.bmp";
            case 108:	return "img\\hassium.bmp";
            case 109:	return "img\\meitnerium.bmp";
            case 110:	return "img\\darmstadtium.bmp";
            case 111:	return "img\\roentgenium.bmp";
            case 112:	return "img\\copernicium.bmp";
            case 113:	return "img\\nihonium.bmp";
            case 114:	return "img\\flerovium.bmp";
            case 115:	return "img\\moscovium.bmp";
            case 116:	return "img\\livermorium.bmp";
            case 117:	return "img\\tennessine.bmp";
            case 118:	return "img\\oganesson.bmp";
        }
        return "no file";
    }
#endif //PHYSICSFORMULA_PERIODICELEMENTS_H
} elements;
//

template <class T>
static void printVect(std::vector<T> vec)
{
    for(auto el : vec)
    {
        cout << el << " ";
    }
}

template<typename ELEM>
static void printElementData(ELEM el)
{
    printf("\nelement:               (%s)\n", typeid(el).name()+11);
    std::cout << setw(23) << left << "atomic #: " << el.atomic_number << " Z_" << std::endl;
    std::cout << setw(23) << left << "atomic Weight: " << el.atomic_weight << " u" << std::endl;
    std::cout << setw(23) << left << "energy levels: ";
    printVect(el.energy_levels);
    std::cout << std::endl;
    std::cout << setw(23) << left << "density STP: " << el.density_STP << " kg/m^3" << std::endl;
    std::cout << setw(23) << left << "melting point: " << el.melting_point << " C" << std::endl;
    std::cout << setw(23) << left << "boiling point: " << el.boiling_point << " C" << std::endl;
    std::cout << setw(23) << left << "thermal conductivity: " << el.thermal_conductivity << " W/mK" << std::endl;
    std::cout << setw(23) << left << "electric conductivity: " << el.electric_conductivity << " MS/m" << std::endl;
    std::cout << setw(23) << left << "resistivity: " << el.resistivity << " Ohm*m" << std::endl;
    std::cout << setw(23) << left << "specific heat: " << el.heat_specific << " J/kgK" << std::endl;
    std::cout << setw(23) << left << "vaporization heat: " << el.heat_vaporization << " kJ/mol" << std::endl;
    std::cout << setw(23) << left << "fusion heat: " << el.heat_fusion << " kJ/mol" << std::endl;
    std::cout << setw(23) << left << "first ionization: " << el.ionization_1st << " eV" << std::endl;
}


static long double getBoilingPoint(string element)
{
    if(element == "hydrogen") return 20.28;
    if(element == "helium") return 4.22;
    if(element == "lithium") return 1603;
    if(element == "beryllium") return 2742;
    if(element == "boron") return 4200;
    if(element == "carbon") return 4300;
    if(element == "nitrogen") return 77.36;
    if(element == "oxygen") return 90.20;
    if(element == "fluorine") return 85.03;
    if(element == "neon") return 27.07;
    if(element == "sodium") return 1156;
    if(element == "magnesium") return 1363;
    if(element == "aluminum") return 2743;
    if(element == "silicon") return 3538;
    if(element == "phosphorus") return 280.5;
    if(element == "sulfur") return 444.7;
    if(element == "chlorine") return 239.11;
    if(element == "argon") return 87.30;
    if(element == "potassium") return 1032;
    if(element == "calcium") return 1757;
    if(element == "scandium") return 3109;
    if(element == "titanium") return 3560;
    if(element == "vanadium") return 3680;
    if(element == "chromium") return 2944;
    if(element == "manganese") return 2334;
    if(element == "iron") return 3134;
    if(element == "cobalt") return 3200;
    if(element == "nickel") return 3186;
    if(element == "copper") return 2835;
    if(element == "zinc") return 1180;
    if(element == "gallium") return 2673;
    if(element == "germanium") return 3106;
    if(element == "arsenic") return 887;
    if(element == "selenium") return 958;
    if(element == "bromine") return 332.0;
    if(element == "krypton") return 119.93;
    if(element == "rubidium") return 961;
    if(element == "strontium") return 1655;
    if(element == "yttrium") return 3618;
    if(element == "zirconium") return 4682;
    if(element == "niobium") return 5017;
    if(element == "molybdenum") return 4912;
    if(element == "technetium") return 4538;
    if(element == "ruthenium") return 4423;
    if(element == "rhodium") return 3968;
    if(element == "palladium") return 3236;
    if(element == "silver") return 2435;
    if(element == "cadmium") return 1040;
    if(element == "indium") return 2345;
    if(element == "tin") return 2875;
    if(element == "antimony") return 1860;
    if(element == "tellurium") return 1261;
    if(element == "iodine") return 457.4;
    if(element == "xenon") return 165.03;
    if(element == "cesium") return 944;
    if(element == "barium") return 2118;
    if(element == "lanthanum") return 3737;
    if(element == "cerium") return 3716;
    if(element == "praseodymium") return 3403;
    if(element == "neodymium") return 3347;
    if(element == "promethium") return 3273;
    if(element == "samarium") return 2067;
    if(element == "europium") return 1802;
    if(element == "gadolinium") return 3546;
    if(element == "terbium") return 3503;
    if(element == "dysprosium") return 2840;
    if(element == "holmium") return 2873;
    if(element == "erbium") return 3141;
    if(element == "thulium") return 2223;
    if(element == "ytterbium") return 1469;
    if(element == "lutetium") return 3675;
    if(element == "hafnium") return 4876;
    if(element == "tantalum") return 5731;
    if(element == "tungsten") return 5828;
    if(element == "rhenium") return 5869;
    if(element == "osmium") return 5285;
    if(element == "iridium") return 4701;
    if(element == "platinum") return 4098;
    if(element == "gold") return 3129;
    if(element == "mercury") return 629.88;
    if(element == "thallium") return 1746;
    if(element == "lead") return 2022;
    if(element == "bismuth") return 1837;
    if(element == "polonium") return 1235;
    if(element == "astatine") return 610;
    if(element == "radon") return 211.3;
    if(element == "francium") return 950;
    if(element == "radium") return 2010;
    if(element == "actinium") return 3503;
    if(element == "thorium") return 5061;
    if(element == "protactinium") return 4300;
    if(element == "uranium") return 4404;
    if(element == "neptunium") return 4447;
    if(element == "plutonium") return 3505;
    if(element == "americium") return 2880;
    if(element == "curium") return 3383;
    if(element == "berkelium") return 2900;
    if(element == "californium") return 1743;
    if(element == "einsteinium") return 1269;
    if(element == "fermium") return 1173;
    if(element == "mendelevium") return 1100;
    if(element == "nobelium") return 1100;
    if(element == "lawrencium") return 1900;
    if(element == "rutherfordium") return 5800;
    if(element == "dubnium") return 5800;
    if(element == "seaborgium") return 5800;
    if(element == "bohrium") return 5800;
    if(element == "hassium") return 5800;
    if(element == "meitnerium") return 5800;
    if(element == "darmstadtium") return 5800;
    if(element == "roentgenium") return 5800;
    if(element == "copernicium") return 3570;
    if(element == "nihonium") return 5800;
    if(element == "flerovium") return 5800;
    if(element == "moscovium") return 5800;
    if(element == "livermorium") return 5800;
    if(element == "tennessine") return 5800;
    if(element == "oganesson") return 5800;
    return 0;
}

static long double getMeltingPoint(string element)
{
    if(element == "hydrogen") return 14.01;
    if(element == "helium") return 0.95;
    if(element == "lithium") return 453.69;
    if(element == "beryllium") return 1560;
    if(element == "boron") return 2348;
    if(element == "carbon") return 3823;
    if(element == "nitrogen") return 63.15;
    if(element == "oxygen") return 54.36;
    if(element == "fluorine") return 53.53;
    if(element == "neon") return 24.56;
    if(element == "sodium") return 370.87;
    if(element == "magnesium") return 923;
    if(element == "aluminum") return 933.47;
    if(element == "silicon") return 1687;
    if(element == "phosphorus") return 317.30;
    if(element == "sulfur") return 388.36;
    if(element == "chlorine") return 171.6;
    if(element == "argon") return 83.80;
    if(element == "potassium") return 336.53;
    if(element == "calcium") return 1115;
    if(element == "scandium") return 1814;
    if(element == "titanium") return 1941;
    if(element == "vanadium") return 2183;
    if(element == "chromium") return 2180;
    if(element == "manganese") return 1519;
    if(element == "iron") return 1811;
    if(element == "cobalt") return 1768;
    if(element == "nickel") return 1728;
    if(element == "copper") return 1357.77;
    if(element == "zinc") return 692.68;
    if(element == "gallium") return 302.91;
    if(element == "germanium") return 1211.40;
    if(element == "arsenic") return 1090;
    if(element == "selenium") return 494;
    if(element == "bromine") return 266.9;
    if(element == "krypton") return 115.79;
    if(element == "rubidium") return 312.46;
    if(element == "strontium") return 1050;
    if(element == "yttrium") return 1799;
    if(element == "zirconium") return 2128;
    if(element == "niobium") return 2750;
    if(element == "molybdenum") return 2896;
    if(element == "technetium") return 2430;
    if(element == "ruthenium") return 2607;
    if(element == "rhodium") return 2237;
    if(element == "palladium") return 1828.05;
    if(element == "silver") return 1234.93;
    if(element == "cadmium") return 594.22;
    if(element == "indium") return 429.75;
    if(element == "tin") return 505.08;
    if(element == "antimony") return 903.78;
    if(element == "tellurium") return 722.66;
    if(element == "iodine") return 386.85;
    if(element == "xenon") return 161.4;
    if(element == "caesium") return 301.59;
    if(element == "barium") return 1000;
    if(element == "lanthanum") return 1193;
    if(element == "cerium") return 1068;
    if(element == "praseodymium") return 1208;
    if(element == "neodymium") return 1297;
    if(element == "promethium") return 1315;
    if(element == "samarium") return 1345;
    if(element == "europium") return 1095;
    if(element == "gadolinium") return 1585;
    if(element == "terbium") return 1629;
    if(element == "dysprosium") return 1680;
    if(element == "holmium") return 1734;
    if(element == "erbium") return 1802;
    if(element == "thulium") return 1818;
    if(element == "ytterbium") return 1097;
    if(element == "lutetium") return 1936;
    if(element == "hafnium") return 2506;
    if(element == "tantalum") return 3290;
    if(element == "tungsten") return 3695;
    if(element == "rhenium") return 3459;
    if(element == "osmium") return 3306;
    if(element == "iridium") return 2719;
    if(element == "platinum") return 2041.4;
    if(element == "gold") return 1337.33;
    if(element == "mercury") return 234.43;
    if(element == "thallium") return 577;
    if(element == "lead") return 600.61;
    if(element == "bismuth") return 544.7;
    if(element == "polonium") return 527;
    if(element == "astatine") return 575;
    if(element == "radon") return 202;
    if(element == "francium") return 300;
    if(element == "radium") return 973;
    if(element == "actinium") return 1323;
    if(element == "thorium") return 2023;
    if(element == "protactinium") return 1841;
    if(element == "uranium") return 1405.3;
    if(element == "neptunium") return 917;
    if(element == "plutonium") return 913.4;
    if(element == "americium") return 1449;
    if(element == "curium") return 1613;
    if(element == "berkelium") return 1259;
    if(element == "californium") return 1173;
    if(element == "einsteinium") return 1133;
    if(element == "fermium") return 1800;
    if(element == "mendelevium") return 1100;
    if(element == "nobelium") return 1100;
    if(element == "lawrencium") return 1900;
    if(element == "rutherfordium") return 2400;
    if(element == "dubnium") return 2900;
    if(element == "seaborgium") return 3500;
    if(element == "bohrium") return 4100;
    if(element == "hassium") return 4700;
    if(element == "meitnerium") return 5200;
    if(element == "darmstadtium") return 5800;
    if(element == "roentgenium") return 6400;
    if(element == "copernicium") return 7000;
    if(element == "nihonium") return 7000;
    if(element == "flerovium") return 7000;
    if(element == "moscovium") return 7000;
    if(element == "livermorium") return 7000;
    if(element == "tennessine") return 7000;
    if(element == "oganesson") return 7000;
    return 0;
}
