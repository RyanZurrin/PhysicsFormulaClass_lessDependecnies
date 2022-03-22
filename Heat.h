//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_HEAT_H
#define PHYSICSFORMULA_HEAT_H
/**
 * @class Heat
 * @details driver class for solving physics problems
 * @author Ryan Zurrin testing a push to git hub with this line here
 * @date   11/29/2020
 * @last_modified_on 12/14/2020
 */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
constexpr auto _ga_ = 9.81;
using namespace std;
static int heat_objectCount = 0;
/***
 * @ the Stefan Boltzmann constant is often represented as sigma in the
 * Stefan Boltzmann->(σ) law of radiation equation
 */
constexpr auto _epsilon_ = 5.67e-8;
typedef long double ld;

static struct HeatEnergyUnitConversion
{
    static ld kCal_to_calorie(const ld kCal) { return kCal * 1000.0; } //returns calories from kCal
    static ld calorie_to_kCal(const ld C) { return C / 1000.0; } // returns kCal from calories
    static ld kiloCalorie_to_joule(const ld kCal) { return kCal * 4186.0; } //returns Joules
    static ld joule_to_kCal(const ld joule) { return joule / 4186.0; } // returns kCal

}heConverter;

/**
 * @brief structure holding the heat values of different substances. this is the c value in the
 * heat transfer equation, that we must use. Each value is a std::vector holding two different units
 * of heat; J/kg*C`  or kCal/kg*C`. So c.aluminum[0] would give the value of 900J/kg*C` and
 * c.aluminum[1] holds the value of .215 kCal/kg*C` respectfully.
 * @variable c stands for specific heat
 */
static struct SpecificHeatCapacity
{

    const std::vector<ld> aluminum_S = { 900.0, .215 };//< 900J/kg*C`, .215kCal/kg*C` >
    const std::vector<ld> asbestos_S = { 800.0, .19 };//< 800J/kg*C`, .19kCal/kg*C` >
    const std::vector<ld> concrete_granite_average_S = { 840.0, .20 };//< 840J/kg*C`, .20kCal/kg*C` >
    const std::vector<ld> copper_S = { 387.0, .0924 };//< 387J/kg*C`, .0924kCal/kg*C` >
    const std::vector<ld> glass_S = { 840.0, .20 };//< 840.0J/kg*C`, .20kCal/kg*C` >
    const std::vector<ld> sand_s = { 840.0, };//< 840.0J/kg*C`, .20kCal/kg*C` >
    const std::vector<ld> gold_S = { 129.0, .0308 };//< 129.0J/kg*C`,.0308kCal/kg*C` >
    const std::vector<ld> human_body_average_S = { 3474.38, .83 };//< 3500.0J/kg*C`, .83kCal/kg*C` >
    const std::vector<ld> ice_average_S = { 2090.0, .50 };//< 2090.0J/kg*C`, .50kCal/kg*C` >
    const std::vector<ld> iron_steel_S = { 452, .108 };//< 452J/kg*C`, .108kCal/kg*C` >
    const std::vector<ld> lead_S = { 128.0, .0305 };//< 128.0J/kg*C`, .0305kCal/kg*C` >
    const std::vector<ld> silver_S = { 235.0, .0562 };//< 235.0J/kg*C`, .0562kCal/kg*C` >
    const std::vector<ld> wood_S = { 1700, .40 };//< 1700J/kg*C`, .40kCal/kg*C` >
    const std::vector<ld> benzene_L = { 1740.0, .415 };//< 1740.0J/kg*C`, .415kCal/kg*C` >
    const std::vector<ld> ethanol_L = { 2450, .586 };//< 2450J/kg*C`, .586kCal/kg*C` >
    const std::vector<ld> glycerin_L = { 2410.0, .576 };//< 2410.0J/kg*C`, .576kCal/kg*C` >
    const std::vector<ld> mercury_L = { 139, .0333 };//< 139J/kg*C`, .0333kCal/kg*C` >
    const std::vector<ld> water_L = { 4186.0, 1.0 };//< 4186.0J/kg*C`, 1.0kCal/kg*C` >
    const std::vector<ld> air_G = { 721.0, .172 };//< 721.0J/kg*C`, .172kCal/kg*C` >
    const std::vector<ld> air_dry_G = { 1015.0, .242 };//< 1015.0J/kg*C`, .242kCal/kg*C` >
    const std::vector<ld> ammonia_G = { 1670.0, .399 };//< 1670.0J/kg*C`, .399kCal/kg*C` >
    const std::vector<ld> ammonia_dry_G = { 2190.0, .523 };//< 2190.0J/kg*C`, .523kCal/kg*C` >
    const std::vector<ld> carbonDioxide_G = { 638.0, .152 };//< 638.0J/kg*C`, .152kCal/kg*C` >
    const std::vector<ld> carbonDioxide_dry_G = { 833.0, .199 };//< 833.0J/kg*C`, .199kCal/kg*C` >
    const std::vector<ld> nitrogen_G = { 739.0, .177 };//< 739.0J/kg*C`, .177kCal/kg*C` >
    const std::vector<ld> nitrogen_dry_G = { 1040, .248 };//< 1040J/kg*C`,.248kCal/kg*C` >
    const std::vector<ld> oxygen_G = { 651.0, .156 };//< 651.0J/kg*C`, .156kCal/kg*dC` >
    const std::vector<ld> oxygen_dry_G = { 913.0, .218 };//< 913.0J/kg*C`, .218kCal/kg*dC` >
    const std::vector<ld> steam_100C_G = { 1520.0, .363 };//< 1520.0J/kg*C`, .363kCal/kg*dC` >
    const std::vector<ld> steam_dry_100C_G = { 2020.0, .482 };//< 2020.0J/kg*C`, .482kCal/kg*dC` >

}_c;

/**
 * structure of latent heat coefficients for fusion (melting point)
 */
static struct LatentHeatFusion
{
    const std::vector<ld> helium = { -269.7, 5230.0, 1.25 };// <MeltingPoint(-269.7), j/kg(5230.0), kCal/kg(1.25)>
    const std::vector<ld> hydrogen = { -259.3, 58600.0, 14.0 };// <MeltingPoint(-259.3), j/kg(5858600.0), kCal/kg(14.0)>
    const std::vector<ld> nitrogen = { -210.0, 25500.0, 6.09 };// <MeltingPoint(-210.0), j/kg(25500.0), kCal/kg(6.09)>
    const std::vector<ld> oxygen = { -218.8, 13800.0, 3.3 };// <MeltingPoint(-218.8), j/kg(13800.0), kCal/kg(3.3)>
    const std::vector<ld> ethanol = { -114.0, 104000.0, 24.9 };// <MeltingPoint(-114.0), j/kg(104000.0), kCal/kg(24.9)>
    const std::vector<ld> ammonia = { -75.0, 0.00, 108.0 };// <MeltingPoint(-75.0), j/kg(0.00), kCal/kg()>
    const std::vector<ld> mercury = { -38.9, 11800.0, 2.82 };// <MeltingPoint(-38.9), j/kg(), kCal/kg(108.0)>
    const std::vector<ld> water = { 0.0, 334000.0, 79.8 };// <MeltingPoint(0.0), j/kg(334000.0), kCal/kg(79.8)>
    const std::vector<ld> sulfur = { 119, 38100.0, 9.10 };// <MeltingPoint(119), j/kg(38100.0), kCal/kg(9.10)>
    const std::vector<ld> lead = { 327.0, 24500.0, 5.85 };// <MeltingPoint(327.0), j/kg(24500.0), kCal/kg(5.85)>
    const std::vector<ld> antimony = { 631.0, 165000.0, 39.4 };// <MeltingPoint(631.0), j/kg(165000.0), kCal/kg(39.4)>
    const std::vector<ld> aluminum = { 660.0, 380000.0, 90.0 };// <MeltingPoint(660.0), j/kg(380000.0), kCal/kg(90.0)>
    const std::vector<ld> silver = { 961.0, 88300.0, 21.1 };// <MeltingPoint(961.0), j/kg(88300.0), kCal/kg(21.1)>
    const std::vector<ld> gold = { 1063.0, 64500.0, 15.4 };// <MeltingPoint(1063.0), j/kg(64500.0), kCal/kg(15.4)>
    const std::vector<ld> copper = { 1083.0, 134000.0, 32.0 };// <MeltingPoint(1083.0), j/kg(134000.0), kCal/kg(32.0)>
    const std::vector<ld> uranium = { 1133.0, 84000.0, 20.0 };// <MeltingPoint(1133.0), j/kg(84000.0), kCal/kg(20.0)>
    const std::vector<ld> tungsten = { 3410.0, 184000.0, 44.0 };// <MeltingPoint(3410.0), j/kg(184000.0), kCal/kg(44.0)>

}_Lf;

/**
 * structure of latent heat coefficients for vaporization (boiling point)
 */
static struct LatentHeatVaporization
{
    const std::vector<ld> helium = { -268.9, 20900.0, 4.99 };// <BoilingPoint(-268.9), j/kg(20900.0), kCal/kg(4.99)>
    const std::vector<ld> hydrogen = { -252.9, 452000.0, 108.0 };// <BoilingPoint(-252.9), j/kg(452000.0), kCal/kg(108.0)>
    const std::vector<ld> nitrogen = { -195.8, 201000.0, 48.0 };// <BoilingPoint(-195.8), j/kg(201000.0), kCal/kg(48.0)>
    const std::vector<ld> oxygen = { -183.0, 213000.0, 50.9 };// <BoilingPoint(-183.0), j/kg(213000.0), kCal/kg(50.9)>
    const std::vector<ld> ethanol = { 78.3, 854000.0, 204.0 };// <BoilingPoint(78.3), j/kg(854000.0), kCal/kg(204.0)>
    const std::vector<ld> ammonia = { -33.4, 1370000.0, 327.0 };// <BoilingPoint(-33.4), j/kg(1370000.0), kCal/kg(327.0)>
    const std::vector<ld> mercury = { 357, 272000.0, 65.0 };// <BoilingPoint(357), j/kg(272000.0), kCal/kg(65.0)>
    const std::vector<ld> water = { 100.0, 2256000.0, 539.0 };// <BoilingPoint(100.0), j/kg(2256000.0), kCal/kg(539.0)>
    const std::vector<ld> sulfur = { 444.6, 326000.0, 77.9 };// <BoilingPoint(444.6), j/kg(326000.0), kCal/kg(77.9)>
    const std::vector<ld> lead = { 1750.0, 871000.0, 208.0 };// <BoilingPoint(1750.0), j/kg(871000.0), kCal/kg(208.0)>
    const std::vector<ld> antimony = { 1440.0, 561000.0, 134.0 };// <BoilingPoint(1440.0), j/kg(561000.0), kCal/kg(134.0)>
    const std::vector<ld> aluminum = { 2450.0, 11400000.0, 2720.0 };// <MeltingPoint(2450.0), j/kg(11400000.0), kCal/kg(2720.0)>
    const std::vector<ld> silver = { 2193.0, 2336000.0, 558.0 };// <BoilingPoint(2193.0), j/kg(2336000.0), kCal/kg(558.0)>
    const std::vector<ld> gold = { 2660.0, 1578000.0, 377.0 };// <BoilingPoint(2660.0), j/kg(1578000.0), kCal/kg(377.0)>
    const std::vector<ld> copper = { 2595.0, 5069000.0, 1211.0 };// <BoilingPoint(2595.0), j/kg(5069000.0), kCal/kg(1211.0)>
    const std::vector<ld> uranium = { 3900.0, 1900000.0, 454.0 };// <BoilingPoint(3900.0), j/kg(1900000.0), kCal/kg(454.0)>
    const std::vector<ld> tungsten = { 5900.0, 4810000.0, 1150.0 };// <BoilingPoint(5900.0), j/kg(4810000.0), kCal/kg(1150.0)>
}_Lv;

/**
 * @brief structure of thermal conductivities of common substances
 */
static struct ThermalConductivity
{
    const ld silver = 420.0;
    const ld copper = 390.0;
    const ld gold = 318.0;
    const ld aluminum = 220.0;
    const ld steel_iron = 80.0;
    const ld steel_stainless = 14.0;
    const ld ice = 2.2;
    const ld glass = .84;
    const ld concrete_brick = .84;
    const ld water = .6;
    const ld fatty_tissue_no_blood = .2;
    const ld asbestos = .16;
    const ld plasterboard = .16;
    const ld wood_soft = .08;
    const ld wood_medium = .12;
    const ld wood_hard = .16;
    const ld snow_dry = .10;
    const ld cork = .042;
    const ld glass_wool = .042;
    const ld downFeathers = .025;
    const ld air = .023;
    const ld styrofoam = .010;
}_k;



/**
 * @brief struct of Infrared Emissivity values which are a measure
 * of the amount of heat radiation a surface can reflect back out and is a value
 * from 0 (perfect thermal mirror) to a 1.0 (perfect black body)
 */
static struct InfraredEmissivityValues
{
    const ld aluminium_anodised = 0.77;
    const ld aluminium_polished = 0.05;
    const ld asbestos_board = 0.96;
    const ld asbestos_fabric = 0.78;
    const ld asbestos_paper = 0.93;
    const ld asbestos_slate = 0.96;
    const ld Brass_highlyPolished = 0.03;
    const ld Brass_oxidized = 0.61;
    const std::vector<ld> Brick_common =	{.81, .82, .83, .84, .85, .86};//	{.81, .82, .83, .84, .85, .86};
    const ld Brick_common_red =	0.93;
    const ld Brick_facing_red = 0.92;
    const ld Brick_fireClay = 0.75;
    const ld Brick_masonry = 0.94;
    const ld Brick_red = 0.90;
    const ld Carbon_candle_soot = 0.95;
    const ld Carbon_graphite_filed_surface = 0.98;
    const ld Carbon_purified = 0.80;
    const ld Cement_ = 0.54;
    const ld Charcoal_powder = 0.96;
    const ld Chipboard_untreated = 0.90;
    const ld Chromium_polished = 0.10;
    const ld Clay_fired = 0.91;
    const ld Concrete = 0.92;
    const ld Concrete_dry =	0.95;
    const std::vector<ld> Concrete_rough = { 0.92, .93, .94, .95, .96, .97 };//{ .92, .93, .94, .95, .96, .97 }
    const ld Copper_polished = 0.05;
    const ld Copper_oxidized = 0.65;
    const ld Enamel_lacquer = 0.90;
    const ld Fabric_Hessian_green =	0.88;
    const ld Fabric_Hessian_uncoloured = 0.87;
    const ld Fibreglass = 0.75;
    const ld Fibre_board_porous_untreated = 0.85;
    const ld Fibre_board_hard_untreated = 0.85;
    const ld Filler_white =	0.88;
    const ld Firebrick = 0.68;
    const ld Food_and_Organic_Materials = 0.96;
    const ld Formica = 0.94;
    const ld Galvanized_Pipe = 0.46;
    const ld Glass = 0.92;
    const ld Glass_chemical_ware_partly_transparent = 0.97;
    const ld Glass_frosted_high = 0.96;
    const ld Glass_frosted_low 	= 0.70;
    const ld Glass_polished_plate = 0.94;
    const ld Granite_natural_surface = 0.96;
    const ld Graphite_powder = 0.97;
    const ld Gravel = 0.28;
    const ld Gypsum = 0.08;
    const ld Hardwood_across_grain = 0.82;
    const ld Hardwood_along_grain =	0.715;
    const ld Ice = 0.97;
    const ld Iron_heavily_rusted = 0.935;
    const ld Lacquer_bakelite = 0.93;
    const ld Lacquer_dull_black = 0.97;
    const ld Lampblack = 0.96;
    const ld Limestone_natural_surface = 0.96;
    const ld Mortar = 0.87;
    const ld Mortar_dry = 0.94;
    const ld PVC = 0.92;
    const ld Paint_3M_black_velvet_coating_9560_series_optical_black = 1.00;
    const ld Paint_aluminium = 0.45;
    const ld Paint_oil_average_of_16_colors = 0.94;
    const ld Paint_oil_black_flat =	0.94;
    /*
    const ld Paint: oil, black, gloss 	0.92;
    const ld Paint: oil, grey, flat 	0.97;
    const ld Paint: oil, grey, gloss 	0.94;
    const ld Paint: oil, various colours 	0.94;
    const ld Paint: plastic, black 	0.95;
    const ld Paint: plastic, white 	0.84;
    const ld Paper: black 	0.90;
    const ld Paper: black, dull 	0.94;
    const ld Paper: black, shiny 	0.90;
    const ld Paper: cardboard box 	0.81;
    const ld Paper: green 	0.85;
    const ld Paper: red 	0.76;
    const ld Paper: white 	0.68;
    const ld Paper: white bond 	0.93;
    const ld Paper: yellow 	0.72;
    const ld Paper: tar 	0.92;
    const ld Pipes: glazed 	0.83;
    const ld Plaster 	0.86 - 0.90;
    const ld Plaster: rough coat 	0.91;
    const ld Plasterboard: untreated 	0.90;
    const ld Plastic: acrylic, clear 	0.94;
    const ld Plastic: black 	0.95;
    const ld Plastic: white 	0.84;
    const ld Plastic paper : red 	0.94;
    const ld Plastic paper : white 	0.84;
    const ld Plexiglass: Perpex 	0.86;
    const ld Plywood 	0.83 - 0.98;
    const ld Plywood: commercial, smooth finish, dry 	0.82;
    const ld Plywood: untreated 	0.83;
    const ld Polypropylene 	0.97;
    const ld Porcelain: glazed 	0.92;
    const ld Quartz 	0.93;
    const ld Redwood: wrought, untreated 	0.83;
    const ld Redwood: unwrought, untreated 	0.84;;
    const ld Rubber 	0.95;
    const ld Rubber: stopper, black 	0.97;
    const ld Sand 	0.90;
    const ld Skin, human 	0.95 - 0.98;
    const ld Snow 	0.80;
    const ld Soil: dry 	0.92;
    const ld Soil: frozen 	0.93;
    const ld Soil: saturated with water 	0.95;
    const ld Stainless Steel 	0.59;
    const ld Stainless Plate 	0.34;
    const ld Steel: galvanized 	0.28;
    const ld Steel: rolled freshly 	0.24;
    const ld Styrofoam: insulation 	0.60;
    const ld Tape: electrical, insulating, black 	0.97;
    const ld Tape: masking 	0.92;
    const ld Tile: floor, asbestos 	0.94;
    const ld Tile: glazed 	0.94;
    const ld Tin: burnished 	0.05;
    const ld Tin: commercial tin - plated sheet iron 	0.06;
    const ld Varnish: flat 	0.93;
    const ld Wallpaper: slight pattern, light grey 	0.85;
    const ld Wallpaper: slight pattern, red 	0.90;
    const ld Water: 0.95;
    const ld Water: distilled 	0.95;
    const ld Water: ice, smooth 	0.96;
    const ld Water: frost crystals 	0.98;
    const ld Water: snow 	0.85;
    const ld Wood: planed 	0.90;
    const ld Wood: panelling, light finish;
    const ld Wood: spruce, polished, dry 	0.86;
    */


}emissivity;

#include "Temperature.h"
class Heat :
        public Temperature
{
private:
    static void countIncrease() { heat_objectCount += 1; }
    static void countDecrease() { heat_objectCount -= 1; }
public:
    //null pointer to class if ever needed
    Heat* _heatPtr;

    /**
     * @brief no argument constructor
     */
    Heat()
    {
        _heatPtr = nullptr;
    }

    /**
     * @brief display method for outputting the count of Heat objects
     */
    static void show_heat_objectCount() { std::cout << "\nheat object count: " << heat_objectCount << std::endl; }
    /**
     * @brief getter method returns the value of heat objects
     */
    static int get_heat_objectCount() { return heat_objectCount; }

    /**
     * @brief calculates the required heat to heat an object up
     * @param mass is the mass of the object
     * @param c is the specific heat which depends on object type
     * @param deltaTemp is the change in temperature
     * @returns the heat in Joules
     */
    static ld heatTransfer_Q(const ld mass, const ld c, const ld deltaTemp)
    {
        return mass * c * deltaTemp;
    }

    /**
     * @brief calculates the temp from heat transferred
     */
    static ld temperatureFromHeatTransferred(const ld Q, const ld mass, const ld c)
    {
        return Q / (mass * c);
    }

    /**
     * @brief calculates the final temperature between objects
     * @param m1 is the mass of the first object
     * @param c1 is the specific heat of object 1
     * @param t1 is the temperature object 1
     * @param m2 is the mass of the second object
     * @param c2 is the specific heat of object 2
     * @param t2 is the temperature object 2
     * @returns thermal equilibrium {is when two objects come in contact and the hotter
     * object transfers heat to the cooler object until a equal temp is reached between two objects}
     */
    static ld finalTemp_ThermalEquilibrium2objects(const ld m1, const ld c1, const ld t1, const ld m2, const ld c2, const ld t2)
    {
        return ((m1 * c1 * t1) + (m2 * c2 * t2)) / ((m1 * c1) + (m2 * c2));
    }

    /**
     * @brief calculates the phase change from melting/freezing
     * @param mass is the mass in kg
     * @param Lf is the latent heat coefficient for fusion
     * @returns the energy to cause phase change
     */
    static ld phaseChangeEnergy_Lf(const ld mass, const ld Lf)
    {
        return mass * Lf;
    }

    /**
     * @brief calculates the phase change from vaporization/condensation
     * @param mass is the mass in kg
     * @param Lv is the latent heat coefficient for vaporization
     * @returns the energy to cause phase change
     */
    static ld phaseChangeEnergy_Lv(const ld mass, const ld Lv)
    {
        return mass * Lv;
    }

    /**
     * @brief calculates the final temp after a phase change
     * @param heatTransferTotal is the total calculated value from the heatTransfer_Q method
     * @param phaseChangeTotal is the calculated value of the phase change in question
     * @param totalMass of objects combined
     * @param c is the specific heat of substance
     * @returns the final temperature
     */
    static ld finalTempFromPhaseChange(const ld heatTransferTotal, const ld phaseChangeTotal, const ld totalMass, const ld c)
    {
        return (heatTransferTotal - phaseChangeTotal) / (totalMass * c);
    }

    /**
     * @brief calculates the heat transfer through conduction
     * @param k is the thermal conductivity
     * @param A is total surface area
     * @param deltaTemp is the change in temperature
     * @param d the thickness of substance
     * @returns the Q value or heat transfer total
     */
    static ld heatTransferConduction_Q(const ld k, const ld A, const ld deltaTemp, const ld d)
    {
        return ((k * A * deltaTemp) / d);
    }

    /**
     * @brief calculates the total mass as a result of heat transfer though conduction
     * @param htcQ is the result from the heatTransferConduction_Q method using those know variables
     * @param Lf is the latent heat fusion coefficient for material
     */
    static ld heatTransferConduction_mass(const ld htcQ, const ld Lf)
    {
        return htcQ / Lf;
    }

    /**
     * @breif temperatureDifferenceMaintainedByHeatTransfer
     * @param QmLv is the result from method phaseChangeEnergy_vaporizationCondensation_Q using the known values in
     * this method will provide the result for this method, unless the value is given directly of course
     * @param d is the thickness of the material
     * @param k is the thermal conductivity value
     * @param A is the surface area
     * @returns temperature difference maintained in heat transfer
     */
    static ld temperatureDifferenceMaintainedByHeatTransfer(const ld QmLv, const ld d, const ld k, const ld A)
    {
        return QmLv * (d / (k * A));
    }

    /**
     * @brief calculates mass flow during convection (sweat-heat transfer)
     */
    static ld massFlowDuringConvection(const ld QmLv, const ld Lv)
    {
        return  QmLv / Lv;
    }

    /**
     * @brief Stefan-Boltzmann law of radiation
     * @param e emissivity
     * @param A surface area of object
     * @param T absolute temperature in Kelvin
     * @returns heat transfer by emitted radiation
     */
    static ld stefanBoltzmannLawOfRadiation(const ld e, const ld A, const ld T)
    {
        return _epsilon_ * e * A * pow(T, 4);
    }


    /**
     * @brief Uses the Stefan-Boltzmann law of radiation equation
     * @param e
     */
    static ld netRateOfHeatTransferByRadiation(const ld e, const ld A, const ld T1, const ld T2)
    {
        return _epsilon_ * e * A * ((pow(T2, 4) - pow(T1, 4)));
    }

    /**
     * @brief calculates the initial temperature of falling water using conservation of mechanical energy
     * @param h is the height of the fall of water or substance
     * @param Tf is the final temp after the drop occurs
     * @param _c is the specific heat of something(default is waters value of
     */
    static ld initialTempFromFallingWater(const ld h, const ld Tf, const ld _c_ = _c.water_L[0])
    {
        return  Tf - (_ga_ * h) / _c_;
    }

    /**
     * @brief calculates the initial temperature of an object after being submerged into a
     * liquid of a certain temperature, by using the final temp of both and the specific heats
     * of both as well in the equation T1i = ((m2c2(T2f-T2i))/(m1c1))+T1f
     * @param m1 mass of object 1 in kg
     * @param c1 specific heat of object 1
     * @param m2 mass of object 2 in kg
     * @param c2 specific heat of object 2
     * @param T2i initial temperature of object 2
     * @param finalTboth temperature of both objects after equilibrium
     * @returns initial temperature of object 1
     */
    static ld initialTempFromEqualLibrium(const ld m1, const ld c1, const ld m2, const ld c2, const ld T2i, const ld finalTboth)
    {
        return ((m2 * c2 * (finalTboth - T2i)) / (m1 * c1)) + finalTboth;
    }

    /**
     * @brief calculates the initial temperature of a substance after equilibrium when in contact or mixed with same substance,
     * which means the specific heats cancel so we are left with a simpler equation: T1i = ((m2(T2f-T2i))/(m1))+T1f
     * @param m1 mass of object 1 in kg
     * @param m2 mass of object 2 in kg
     * @param T2i initial temperature of object 2
     * @param finalTboth temperature of both objects after equilibrium
     * @returns initial temperature of object 1
     */
    static ld initialTempFromEqualLibrium(const ld m1, const ld m2, const ld T2i, const ld finalTboth)
    {
        return ((m2 * (finalTboth - T2i)) / (m1)) + finalTboth;
    }

    /**
     * @brief calculates the amount of a fluid added to another fluid in single container(think adding creamer to coffee)
     * @param m1cup mass in kg
     * @param c1cup specific heat
     * @param T1cup initial temp in c
     * @param m2cof mass 2 in kg
     * @param c2cof specific heat 2
     * @param T2cof initial temp of m2
     * @param c3cr specific heat of m3(unknown being solved for)
     * @param T3cr initial temp of m3
     * @param Tf equilibrium temp
     * @param mode 'k' kilograms is default, use 'g' for answer in grams
     * @returns the mass of m3cr in kg
     */
    static ld massOfFluid2AddedToFluid1In1Container
            (const ld m1cup, const ld c1cup, const ld T1cup, const ld m2cof, const ld c2cof, const ld T2cof, const ld c3cr, const ld T3cr, const ld Tf, char mode = 'k')
    {
        const ld heatGainedByCup = m1cup * c1cup * (Tf - T1cup);
        cout << "heat gain by cup: " << heatGainedByCup << endl;
        const ld heatLostByCoffee = m2cof * c2cof * (Tf - T2cof);
        cout << "heat lost by coffee: " << heatLostByCoffee << endl;
        const ld heatGainedByCream = c3cr * (Tf - T3cr);
        cout << "heat gain by cream: " << heatGainedByCream << endl;

        if(mode == 'k')
        {
            return  (abs(heatLostByCoffee) - heatGainedByCup) / (heatGainedByCream);
        }
        else
            return (abs(heatLostByCoffee) - heatGainedByCup) / (heatGainedByCream) * 1000.0;
    }

    /**
     * @brief calculates the thickness of ice on a windshield
     */
    static ld thicknessOfIceOnWindshield(const ld iceTemp, const ld surfaceArea, const ld energyToMelt, const ld _Lf_ = _Lf.water[1], const ld _c_ = _c.ice_average_S[0], const ld density = 917.0)
    {
        cout << "lf: " << _Lf_ << endl;
        const double q1 = _c_ * -iceTemp;
        cout << "q1: " << q1 << endl;
        const double q2 = q1 + _Lf_;
        cout << "q2: " << q2 << endl;
        const double q3 = energyToMelt / q2;
        cout << "q3: " << q3 << endl;
        const double volumeIce = q3 / density;
        cout << "v: " << volumeIce << endl;
        cout << "thickness: : " << volumeIce / surfaceArea << endl;
        return volumeIce / surfaceArea;
    }


    /**
     * @calculaes tF of a ice cube placed in water
     */
    static ld finalTemperatureMeltingIceInWater(const ld mI, const ld cI, const ld Ti, const ld mW, const ld cW, const ld Tw, const ld Lfw = _Lf.water[2] )
    {
        const double q1 = mI * cI * -Ti;
        const double q2 = mI * Lfw;
        const double q3 = mI;
        const double q4 = mW * cW * -Tw;
        return (-q4 - (q1+q2))/(q3 + mW);
    }

    /**
     * @brief calculates the final temperature of a bowl of soup placed in a freezer when a
     * specified amount of energy is transferred away from the objects by the freezer the final temp found
     * @param m_b mass of bowl in Kg
     * @param c_b specific heat of bowl(varies with what bowl is made from)
     * @param m_s mass of soup in kg
     * @param c_s specific heat of soup (similar to that of water in most cases)
     * @param c_i specific heat of ice
     * @param Ti initial temperature of the soup and bowl
     * @param Lf latent heat of fusion
     * @param Q total energy transferred from soup and bowl
     */
    static ld finalTempBowlSoupInFreezer(const ld m_b, const ld c_b, const ld m_s, const ld c_s, const ld c_i, const ld Ti, const ld Lf, const ld Q)
    {
        return ((((m_b * c_b) * (Ti)) + ((m_s * c_s) * (Ti))) + (m_s * Lf) - Q) / ((m_b * c_b) + (m_s * c_i));
    }

    /**
     * @brief calculates the specific heat of a substance
     * @param m mass in kg
     * @param Ti initial temp
     * @param Tf final temp
     * @param Q heat energy used
     */
    static ld specificHeat(const ld m, const ld Ti, const ld Tf, const ld Q)
    {
        return Q / (m * (Tf - Ti));
    }

    /**
     * @brief calculates the time to heat water
     * @param Q heat energy
     * @param P power in watts
     * @returns time in seconds
     */
    static ld timeToHeatWater(const ld Q, const ld P)
    {
        return Q / P;
    }


    /// <summary>
    /// Times to heat object.
    /// </summary>
    /// <param name="m">The mass.</param>
    /// <param name="c_">The specific heat.</param>
    /// <param name="deltaTime">The δ temperature.</param>
    /// <param name="P">The power output.</param>
    /// <returns>time to heat object by specified temperature</returns>
    static ld timeToHeatObject(const ld m, const ld c_, const ld deltaTime, const ld P)
    {
        return (m * c_ * deltaTime) / P;
    }


    /**
     *@brief destructor
     */
    ~Heat()
    {
        delete _heatPtr;
    }
};

#endif //PHYSICSFORMULA_HEAT_H
