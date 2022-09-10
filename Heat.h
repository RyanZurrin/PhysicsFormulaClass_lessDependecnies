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
#include "Constants.h"
using namespace std;
static int heat_objectCount = 0;

typedef long double ld;

static struct HeatEnergyUnitConversion
{
    //returns calories from kCal
    static ld kCal_to_calorie(const ld kCal) { return kCal * 1000.0; }
    // returns kCal from calories
    static ld calorie_to_kCal(const ld C) { return C / 1000.0; }
    // returns joule from kCal
    static ld kiloCalorie_to_joule(const ld kCal) { return kCal * 4186.0; }
    // returns kCal from joule
    static ld joule_to_kCal(const ld joule) { return joule / 4186.0; }
    // returns kCal/kg from kJ/kg
    static ld kiloJoule_to_kCal_per_kg(const ld kJ_kg) { return kJ_kg/4.184; }
    // returns kJ/kg from kCal/kg
    static ld kCal_per_kg_to_kiloJoule(const ld kCal_kg) { return kCal_kg*4.184; }
    // returns kJ/kg from kJ/mol
    static ld kJ_per_mol_to_kJ_per_kg(const ld kJ_mol, const ld mol_mass)
    {
        return (kJ_mol/mol_mass)*1000.0;
    }
    // returns kJ/mol from kJ/kg
    static ld kJ_per_kg_to_kJ_per_mol(const ld kJ_kg, const ld mol_mass)
    {
        return (kJ_kg/1000.0)*mol_mass;
    }


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
    SpecificHeatCapacity() { }
    const struct ALUMINUM_SOLID {
        const ld J_kgC = 900.0;
        const ld kcal_kgC = .215;
    } aluminumSolid;
    const struct ASBESTOS_SOLID {
        const ld J_kgC = 800.0;
        const ld kcal_kgC = .19;
    } asbestosSolid;
    const struct CONCRETE_GRANITE_AVERAGE_SOLID {
        const ld J_kgC = 840.0;
        const ld kcal_kgC = .20;
    } concreteGraniteAverageSolid;
    const struct COPPER_SOLID {
        const ld J_kgC = 387.0;
        const ld kcal_kgC = .0924;
    } copperSolid;
    const struct GLASS_SOLID {
        const ld J_kgC = 840.0;
        const ld kcal_kgC = .20;
    } glassSolid;
   const struct SAND_SOLID {
        const ld J_kgC = 840.0;
        const ld kcal_kgC = .20;
    } sandSolid;
    const struct GOLD_SOLID {
        const ld J_kgC = 129.0;
        const ld kcal_kgC = .0308;
    } goldSolid;
    const struct HUMAN_BODY_AVERAGE_SOLID {
        const ld J_kgC = 3474.38;
        const ld kcal_kgC = .83;
    } humanBodyAverageSolid;
    const struct ICE_AVERAGE_SOLID {
        const ld J_kgC = 2090.0;
        const ld kcal_kgC = .50;
    } iceAverageSolid;
    const struct IRON_STEEL_SOLID {
        const ld J_kgC = 452;
        const ld kcal_kgC = .108;
    } ironSteelSolid;
    const struct LEAD_SOLID {
        const ld J_kgC = 128.0;
        const ld kcal_kgC = .0305;
    } leadSolid;
    const struct SILVER_SOLID {
        const ld J_kgC = 235.0;
        const ld kcal_kgC = .0562;
    } silverSolid;
    const struct WOOD_SOLID {
        const ld J_kgC = 1700;
        const ld kcal_kgC = .40;
    } woodSolid;
    const struct BENZENE_LIQUID {
        const ld J_kgC = 1740.0;
        const ld kcal_kgC = .415;
    } benzeneLiquid;
    const struct ETHANOL_LIQUID {
        const ld J_kgC = 2450;
        const ld kcal_kgC = .586;
    } ethanolLiquid;
    const struct GLYCERIN_LIQUID {
        const ld J_kgC = 2410.0;
        const ld kcal_kgC = .576;
    } glycerinLiquid;
    const struct MERCURY_LIQUID {
        const ld J_kgC = 139;
        const ld kcal_kgC = .0333;
    } mercuryLiquid;
    const struct WATER_LIQUID {
        const ld J_kgC = 4186.0;
        const ld kcal_kgC = 1.0;
    } waterLiquid;
    const struct AIR_GAS {
        const ld J_kgC = 721.0;
        const ld kcal_kgC = .172;
    } airGas;
    const struct AIR_DRY_GAS {
        const ld J_kgC = 1015.0;
        const ld kcal_kgC = .242;
    } airDryGas;
    const struct AMMONIA_GAS {
        const ld J_kgC = 1670.0;
        const ld kcal_kgC = .399;
    } ammoniaGas;
    const struct AMMONIA_DRY_GAS {
        const ld J_kgC = 2190.0;
        const ld kcal_kgC = .523;
    } ammoniaDryGas;
    const struct CARBON_DIOXIDE_GAS {
        const ld J_kgC = 638.0;
        const ld kcal_kgC = .152;
    } carbonDioxideGas;
    const struct CARBON_DIOXIDE_DRY_GAS {
        const ld J_kgC = 833.0;
        const ld kcal_kgC = .199;
    } carbonDioxideDryGas;
    const struct NITROGEN_GAS {
        const ld J_kgC = 739.0;
        const ld kcal_kgC = .177;
    } nitrogenGas;
    const struct NITROGEN_DRY_GAS {
        const ld J_kgC = 1040;
        const ld kcal_kgC = .248;
    } nitrogenDryGas;
    const struct OXYGEN_GAS {
        const ld J_kgC = 651.0;
        const ld kcal_kgC = .156;
    } oxygenGas;
    const struct OXYGEN_DRY_GAS {
        const ld J_kgC = 913.0;
        const ld kcal_kgC = .218;
    } oxygenDryGas;
    const struct STEAM_100C_GAS {
        const ld J_kgC = 1520.0;
        const ld kcal_kgC = .363;
    } steam100CGas;
    const struct STEAM_DRY_100C_GAS {
        const ld J_kgC = 2020.0;
        const ld kcal_kgC = .482;
    } steamDry100CGas;
} SHC;

/**
 * structure of latent heat coefficients for fusion (melting point)
 */
static struct LatentHeatFusion
{
    LatentHeatFusion() {}
    const struct HELIUM {
        const ld melting_point = -269.7;
        const ld kJ_kg = 5.23;
        const ld kcal_kg = 1.25;
    } helium;
    const struct HYDROGEN {
        const ld melting_point = -259.3;
        const ld kJ_kg = 58.60;
        const ld kcal_kg = 14.0;
    } hydrogen;
    const struct NITROGEN {
        const ld melting_point = -210.0;
        const ld kJ_kg = 25.50;
        const ld kcal_kg = 6.09;
    } nitrogen;
    const struct OXYGEN {
        const ld melting_point = -218.8;
        const ld kJ_kg = 13.80;
        const ld kcal_kg = 3.3;
    } oxygen;
    const struct ETHANOL {
        const ld melting_point = -114.0;
        const ld kJ_kg = 104.0;
        const ld kcal_kg = 24.9;
    } ethanol;
    const struct AMMONIA {
        const ld melting_point = -75.0;
        const ld kJ_kg = FP_NAN;
        const ld kcal_kg = 108.0;
    } ammonia;
    const struct MERCURY {
        const ld melting_point = -38.9;
        const ld kJ_kg = 11.40;
        const ld kcal_kg = 2.72;
    } mercury;
    const struct WATER {
        const ld melting_point = 0.0;
        const ld kJ_kg = 334.0;
        const ld kcal_kg = 79.8;
    } water;
    const struct SULFUR {
        const ld melting_point = 119;
        const ld kJ_kg = 38.10;
        const ld kcal_kg = 9.10;
    } sulfur;
    const struct LEAD {
        const ld melting_point = 327.0;
        const ld kJ_kg = 23.00;
        const ld kcal_kg = 5.49;
    } lead;
    const struct ANTIMONY {
        const ld melting_point = 631.0;
        const ld kJ_kg = 165.0;
        const ld kcal_kg = 39.4;
    } antimony;
    const struct ALUMINUM {
        const ld melting_point = 660.0;
        const ld kJ_kg = 380.0;
        const ld kcal_kg = 90.0;
    } aluminum;
    const struct SILVER {
        const ld melting_point = 961.0;
        const ld kJ_kg = 88.30;
        const ld kcal_kg = 21.1;
    } silver;
    const struct GOLD {
        const ld melting_point = 1063.0;
        const ld kJ_kg = 64.0;
        const ld kcal_kg = 15.4;
    } gold;
    const struct COPPER {
        const ld melting_point = 1083.0;
        const ld kJ_kg = 206.14;
        const ld kcal_kg = 49.2;
    } copper;
    const struct URANIUM {
        const ld melting_point = 1133.0;
        const ld kJ_kg = 84.0;
        const ld kcal_kg = 20.077;
    } uranium;
    const struct URANIUM_DIOXIDE {
        const ld melting_point = 2846.85;
        const ld kJ_kg = 259.0;
        const ld kcal_kg = 61.903;
    } uraniumDioxide;
    const struct PLATINUM {
        const ld melting_point = 1768.0;
        const ld kJ_kg = 103.0;
        const ld kcal_kg = 24.618;
    } platinum;
    const struct TUNGSTEN {
        const ld melting_point = 3410.0;
        const ld kJ_kg = 184.0;
        const ld kcal_kg = 43.9;
    } tungsten;
} LF;

/**
 * structure of latent heat coefficients for vaporization (boiling point)
 */
static struct LatentHeatVaporization
{
    LatentHeatVaporization() {}
    const struct HELIUM {
        const ld boiling_point = -268.9; // C
        const ld kJ_kg = 20.73; // kJ/kg
        const ld kcal_kg = 4.95; // kcal/kg
    } helium;
    const struct HYDROGEN {
        const ld boiling_point = -252.9;
        const ld kJ_kg = 452.0;
        const ld kcal_kg = 108.0;
    } hydrogen;
    const struct NITROGEN {
        const ld boiling_point = -195.8;
        const ld kJ_kg = 201.0;
        const ld kcal_kg = 48.0;
    } nitrogen;
    const struct OXYGEN {
        const ld boiling_point = -183.0;
        const ld kJ_kg = 213.0;
        const ld kcal_kg = 50.9;
    } oxygen;
    const struct ETHANOL {
        const ld boiling_point = 78.3;
        const ld kJ_kg = 854.0;
        const ld kcal_kg = 204.0;
    } ethanol;
    const struct AMMONIA {
        const ld boiling_point = -33.4;
        const ld kJ_kg = 1370.0;
        const ld kcal_kg = 327.0;
    } ammonia;
    const struct MERCURY {
        const ld boiling_point = 357;
        const ld kJ_kg = 272.0;
        const ld kcal_kg = 65.0;
    } mercury;
    const struct WATER {
        const ld boiling_point = 100.0;
        const ld kJ_kg = 2256.0;
        const ld kcal_kg = 539.0;
    } water;
    const struct SULFUR {
        const ld boiling_point = 444.6;
        const ld kJ_kg = 326.0;
        const ld kcal_kg = 77.9;
    } sulfur;
    const struct LEAD {
        const ld boiling_point = 1750.0;
        const ld kJ_kg = 859.0;
        const ld kcal_kg = 205.31;
    } lead;
    const struct ANTIMONY {
        const ld boiling_point = 1440.0;
        const ld kJ_kg = 561.0;
        const ld kcal_kg = 134.0;
    } antimony;
    const struct ALUMINUM {
        const ld melting_point = 2450.0;
        const ld kJ_kg = 11400.0;
        const ld kcal_kg = 2720.0;
    } aluminum;
    const struct SILVER {
        const ld boiling_point = 2193.0;
        const ld kJ_kg = 2336.0;
        const ld kcal_kg = 558.0;
    } silver;
    const struct GOLD {
        const ld boiling_point = 2660.0;
        const ld kJ_kg = 1578.0;
        const ld kcal_kg = 377.0;
    } gold;
    const struct COPPER {
        const ld boiling_point = 2595.0;
        const ld kJ_kg = 5069.0;
        const ld kcal_kg = 1211.0;
    } copper;
    const struct URANIUM {
        const ld boiling_point = 3900.0;
        const ld kJ_kg = 1900.0;
        const ld kcal_kg = 454.0;
    } uranium;
    const struct URANIUM_DIOXIDE {
        const ld boiling_point = 3541.85;
        const ld kJ_kg = 1533.0;
        const ld kcal_kg = 366.396;
    } uraniumDioxide;
    const struct PLATINUM {
        const ld boiling_point = 3825.0;
        const ld kJ_kg = 2511.8;
        const ld kcal_kg = 600.335;
    } platinum;
    const struct TUNGSTEN {
        const ld boiling_point = 5900.0;
        const ld kJ_kg = 4810.0;
        const ld kcal_kg = 1150.0;
    } tungsten;
}LV;

/**
 * @brief structure of thermal conductivities of common substances
 */
static struct ThermalConductivity
{
    ThermalConductivity() {}
//    const ld silver = 420.0;
    const struct SILVER {
        const ld W_mK = 403.0;
        const ld Btu_in_h_ft = 2790.0;
    } silver;
//    const ld copper = 390.0;
    const struct COPPER {
        const ld kJ_kgC = 401.0;
        const ld kcal_kgF = 2780.0;
    } copper;
//    const ld gold = 318.0;
    const struct GOLD {
        const ld W_mK = 327.0;
        const ld Btu_in_h_ft = 2270.0;
    } gold;
//    const ld aluminum = 220.0;
    const struct ALUMINUM {
        const ld W_mK = 237.0;
        const ld Btu_in_h_ft = 1640.0;
    } aluminum;
//    const ld steel_iron = 80.0;
    const struct IRON {
        const ld W_mK = 80.4;
        const ld Btu_in_h_ft = 558.0;
    } iron;
//    const ld steel_stainless = 14.0;
    const struct STEEL_STAINLESS {
        const ld W_mK = 14.0;
        const ld Btu_in_h_ft = 95.0;
    } steel_stainless;
//    const ld steele = 46.0;
    const struct STEEL {
        const ld W_mK = 46.0;
        const ld Btu_in_h_ft = 319.0;
    } steel;
//    const ld ice = 2.2;
    const struct ICE {
        const ld W_mK = 2.2;
        const ld Btu_in_h_ft = 15.3;
    } ice;
//    const ld glass = .84;
    const struct GLASS {
        const ld W_mK = 0.84;
        const ld Btu_in_h_ft = 5.8;
    } glass;
//    const ld concrete_brick = .84;
    const struct CONCRETE {
        const ld W_mK = 1.0;
        const ld Btu_in_h_ft = 7.0;
    } concrete;
//    const ld water = .61;
    const struct WATER {
        const ld W_mK = 0.61;
        const ld Btu_in_h_ft = 4.2;
    } water;
//    const ld fatty_tissue_no_blood = .2;
    const struct FATTY_TISSUE {
        const ld W_mK = 0.2;
        const ld Btu_in_h_ft = 1.39;
    } fatty_tissue_no_blood;
//    const ld asbestos = .16;
    const struct ASBESTOS {
        const ld W_mK = 0.16;
        const ld Btu_in_h_ft = 1.11;
    } asbestos;
//    const ld plasterboard = .16;
    const struct PLASTERBOARD {
        const ld W_mK = 0.16;
        const ld Btu_in_h_ft = 1.11;
    } plasterboard;
//    const ld wood_soft = .08;
    const struct WOOD_SOFT {
        const ld W_mK = 0.08;
        const ld Btu_in_h_ft = 0.555;
    } wood_soft;
//    const ld wood_medium = .12;
    const struct WOOD_MEDIUM {
        const ld W_mK = 0.12;
        const ld Btu_in_h_ft = 0.832;
    } wood_medium;
//    const ld wood_hard = .16;
    const struct WOOD_HARD {
        const ld W_mK = 0.16;
        const ld Btu_in_h_ft = 1.11;
    } wood_hard;
//    const ld wood_pine= .11
    const struct WOOD_PINE {
        const ld W_mK = 0.11;
        const ld Btu_in_h_ft = 0.78;
    } wood_pine;
//    const ld snow_dry = .10;
    const struct SNOW_DRY {
        const ld W_mK = 0.10;
        const ld Btu_in_h_ft = 0.693;
    } snow_dry;
//    const ld cork = .042;
    const struct CORK {
        const ld W_mK = 0.042;
        const ld Btu_in_h_ft = 0.291;
    } cork;
//    const ld glass_wool = .042;
    const struct GOOSE_DOWN {
        const ld W_mK = 0.043;
        const ld Btu_in_h_ft = 0.30;
    } goose_down;
//    const ld fiberglass = .042;
    const struct FIBERGLASS {
        const ld W_mK = 0.042;
        const ld Btu_in_h_ft = 0.29;
    } fiberglass;
//    const ld air = .023;
    const struct AIR {
        const ld W_mK = 0.026;
        const ld Btu_in_h_ft = 0.18;
    } air;
//    const ld styrofoam = .010;
    const struct STYROFOAM {
        const ld W_mK = 0.029;
        const ld Btu_in_h_ft = 0.20;
    } styrofoam;
//    const ld helium = .14;
    const struct HELIUM {
        const ld W_mK = 0.14;
        const ld Btu_in_h_ft = 0.97;
    } helium;
}K;

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
    const std::vector<ld> Brick_common ={.81, .82, .83, .84, .85, .86};
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
    const std::vector<ld> Concrete_rough = { 0.92, .93, .94, .95, .96, .97 };
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
    const ld Paint_oil_black_gloss = 0.92;
    const ld Paint_oil_grey_flat = 0.97;
    const ld Paint_oil_grey_gloss = 0.94;
    const ld Paint_oil_various_colours = 0.94;
    const ld Paint_plastic_black = 0.95;
    const ld Paint_plastic_white = 0.84;
    const ld Paper_black = 0.90;
    const ld Paper_black_dull = 0.94;
    const ld Paper_black_shiny = 0.90;
    const ld Paper_cardboard_box = 0.81;
    const ld Paper_green = 0.85;
    const ld Paper_red = 0.76;
    const ld Paper_white = 0.68;
    const ld Paper_white_bond = 0.93;
    const ld Paper_yellow = 0.72;
    const ld Paper_tar = 0.92;
    const ld Pipes_glazed = 0.83;
    const ld Plaster_common = 0.86;
    const ld Plaster_rough_coat = 0.91;
    const ld Plasterboard_untreated = 0.90;
    const ld Plastic_acrylic_clear = 0.94;
    const ld Plastic_black = 0.95;
    const ld Plastic_white = 0.84;
    const ld Plastic_paper_red = 0.94;
    const ld Plastic_paper_white = 0.84;
    const ld Plexiglass_Perpex = 0.86;
    const ld Plywood_common = 0.83;
    const ld Plywood_commercial_smooth_finish_dry = 0.82;
    const ld Plywood_untreated = 0.83;
    const ld Polypropylene = 0.97;
    const ld Porcelain_glazed = 0.92;
    const ld Quartz = 0.93;
    const ld Redwood_wrought_untreated = 0.83;
    const ld Redwood_unwrought_untreated = 0.84;
    const ld Rubber = 0.95;
    const ld Rubber_stopper_black = 0.97;
    const ld Sand = 0.90;
    const ld Skin_human = 0.95;
    const ld Snow = 0.80;
    const ld Soil_dry = 0.92;
    const ld Soil_frozen = 0.93;
    const ld Soil_saturated_with_water = 0.95;
    const ld Stainless_Steel = 0.59;
    const ld Stainless_Plate = 0.34;
    const ld Steel_galvanized = 0.28;
    const ld Steel_rolled_freshly = 0.24;
    const ld Styrofoam_insulation = 0.60;
    const ld Tape_electrical_insulating_black = 0.97;
    const ld Tape_masking = 0.92;
    const ld Tile_floor_asbestos = 0.94;
    const ld Tile_glazed = 0.94;
    const ld Tin_burnished = 0.05;
    const ld Tin_commercial_tin_plated_sheet_iron = 0.06;
    const ld Varnish_flat = 0.93;
    const ld Wallpaper_slight_pattern_light_grey = 0.85;
    const ld Wallpaper_slight_pattern_red = 0.90;
    const ld Water = 0.95;
    const ld Water_distilled = 0.95;
    const ld Water_ice_smooth = 0.96;
    const ld Water_frost_crystals = 0.98;
    const ld Water_snow = 0.85;
    const ld Wood_planed = 0.90;
    const ld Wood_panelling_light_finish = 0.90;
    const ld Wood_spruce_polished_dry = 0.86;
}emissivity;

#include "Temperature.h"
class Heat :
        public Temperature
{
private:
    static void countIncrease() { heat_objectCount += 1; }
    static void countDecrease() { heat_objectCount -= 1; }
public:
    /**
     * @brief no argument constructor
     */
    Heat()
    {
        countIncrease();
    }

    /**
     * @brief display method for outputting the count of Heat objects
     */
    static void show_heat_objectCount() { std::cout << "\nheat object count: "
                                                    << heat_objectCount
                                                    << std::endl; }
    /**
     * @brief getter method returns the value of heat objects
     */
    static int get_heat_objectCount() { return heat_objectCount; }

    /**
     * @brief heat capacity applies to specific object and therefore depends
     * on the objects mass and specific heat capacity
     * @param mass
     * @param specificHeat
     * @return  heat capacity
     */
    static ld heatCapacity(ld mass, ld specificHeat, bool print = false)
    {
        auto heat_capacity = mass * specificHeat;
        if (print)
            std::cout << "\nheat capacity: " << heat_capacity << std::endl;
        return heat_capacity;
    }

    /**
     * @brief heat of transformation of a substance from one state to another
     * @param mass of substance
     * @param latentHeat is the heat of transformation (fusion or vaporization)
     * @return heat of transformation
     */
    static ld heatOfTransformation(ld mass, ld latentHeat, bool print = false)
    {
        auto heatOfTransformation = mass * latentHeat;
        if (print)
            std::cout << "\nheat of transformation: " << heatOfTransformation
                      << std::endl;
        return heatOfTransformation;
    }

    /**
     * @brief calculates the required heat to heat an object up
     * @param mass is the mass of the object
     * @param c is the specific heat which depends on object type
     * @param deltaTemp is the change in temperature
     * @returns the heat in Joules
     */
    static ld heatEnergy(const ld mass,
                         const ld c,
                         const ld deltaTemp,
                         bool print = false)
    {
        auto heat = mass * c * deltaTemp;
        if (print)
            std::cout << "\nheat energy: " << heat << " J" << std::endl;
        return heat;
    }

    /**
     * @brief calculates the temp from heat transferred
     * @param Q is the heat in Joules
     * @param mass is the mass of the object
     * @param c is the specific heat which depends on object type
     * @returns the temperature in Kelvin
     */
    static ld tempFromHeatEnergy(const ld Q,
                                   const ld mass,
                                   const ld c,
                                   bool print = false)
    {
        auto temp = Q / (mass * c);
        if (print)
            std::cout << "\ntemp from heat energy: " << temp << " K"
            << std::endl;
        return temp;
    }

    /**
     * @brief calculates the mass from heat capacity
     * @param Q is the heat in Joules
     * @param temp is the temperature in Kelvin
     * @param c is the specific heat which depends on object type
     * @returns the mass in kilograms
     */
    static ld massFromHeatEnergy(const ld Q,
                                   const ld temp,
                                   const ld c,
                                   bool print = false)
    {
        auto mass = Q / (c * temp);
        if (print)
            std::cout << "\nmass from heat energy: " << mass << " kg"
            << std::endl;
        return mass;
    }

    /**
     * @brief calculates the specific heat from heat capacity
     * @param Q is the heat in Joules
     * @param mass is the mass of the object
     * @param temp is the temperature in Kelvin
     * @returns the specific heat in Joules per Kelvin
     */
    static ld specificHeatFromHeatEnergy(const ld Q,
                                           const ld mass,
                                           const ld temp,
                                           bool print = false)
    {
        auto sh = Q / (mass * temp);
        if (print)
            std::cout << "\nspecific heat from heat energy: " << sh << " J/K"
            << std::endl;
        return sh;
    }

    /**
     * @brief calculates the final temperature between objects
     * @param m1 is the mass of the first object
     * @param c1 is the specific heat of object 1
     * @param t1 is the temperature object 1
     * @param m2 is the mass of the second object
     * @param c2 is the specific heat of object 2
     * @param t2 is the temperature object 2
     * @returns thermal equilibrium {is when two objects come in contact
     * and the hotter object transfers heat to the cooler object until a equal
     * temp is reached between two objects}
     */
    static ld thermalEquilibriumTemp(const ld m1,
                                     const ld c1,
                                     const ld t1,
                                     const ld m2,
                                     const ld c2,
                                     const ld t2,
                                     bool print = false)
    {
        auto temp = ((m1 * c1 * t1) + (m2 * c2 * t2)) / ((m1 * c1) + (m2 * c2));
        if (print)
            std::cout << "thermal equilibrium temp: " << temp << std::endl;
        return temp;
    }

    /**
     * @brief calculates the phase change from melting/freezing
     * @param mass is the mass in kg
     * @param Lf is the latent heat coefficient for fusion
     * @returns the energy to cause phase change
     */
    static ld phaseChangeEnergy_Lf(const ld mass,
                                   const ld Lf,
                                   bool print = false)
    {
        auto energy = mass * Lf;
        if (print)
            std::cout << "phase change energy: " << energy << " J" << std::endl;
        return energy;
    }

    /**
     * @brief calculates the phase change from vaporization/condensation
     * @param mass is the mass in kg
     * @param Lv is the latent heat coefficient for vaporization
     * @returns the energy to cause phase change
     */
    static ld phaseChangeEnergy_Lv(const ld mass,
                                   const ld Lv,
                                   bool print = false)
    {
        auto energy = mass * Lv;
        if (print)
            std::cout << "phase change energy: " << energy << " J" << std::endl;
        return energy;
    }

    /**
     * @brief calculates the final temp after a phase change
     * @param heatTransferTotal is the total calculated value from the
     * heatEnergy method
     * @param phaseChangeTotal is the calculated value of the phase change in
     * question
     * @param totalMass of objects combined
     * @param c is the specific heat of substance
     * @returns the final temperature
     */
    static ld finalTempFromPhaseChange(const ld heatTransferTotal,
                                       const ld phaseChangeTotal,
                                       const ld totalMass,
                                       const ld c,
                                       bool print = false)
    {
        auto temp = (heatTransferTotal - phaseChangeTotal) / (totalMass * c);
        if (print)
            std::cout << "final temp from phase change: " << temp << " K"
            << std::endl;
        return temp;
    }

    /**
     * @brief calculates the heat transfer through conduction
     * @param k is the thermal conductivity
     * @param A is total surface area
     * @param deltaTemp is the change in temperature
     * @param d the thickness/length of substance
     * @returns the COULOMB value or heat transfer total
     */
    static ld heatConduction(const ld k,
                             const ld A,
                             const ld deltaTemp,
                             const ld d,
                             bool print = false)
    {
        auto heat_trans = ((k * A * deltaTemp) / d);
        if (print)
            std:: cout << "heat transfer from conduction: " << heat_trans <<
            std::endl;
        return heat_trans;
    }

    /**
     * Using the heat conduction and change of temperature of a substance,
     * calculate the length of thickness of the substance
     * @param H  heat conduction
     * @param k  thermal conductivity
     * @param A  cross sectional area
     * @param deltaTemp  change in temperature
     * @param print  print to console
     * @return thickness of substance
     */
    static ld lengthOfRod(const ld H,
                          const ld k,
                          const ld A,
                          const ld deltaTemp,
                          bool print = false) {
        auto length = (k * A * deltaTemp) / H;
        if (print)
            std::cout << "length of rod: " << length << std::endl;
        return length;
    }

    /**
     * @brief calculates the heat transfer through conduction through
     * composite slabs
     */
    static ld heatConductionComposite(const ld T1,
                             const ld R1,
                             const ld T3,
                             const ld R2,
                             bool print = false) {
        auto H = (T1 - T3) / (R1 + R2);
        if (print)
            std::cout << "heat transfer from conduction: " << H << std::endl;
        return H;
    }

    /**
     * @brief calculates the total mass as a result of heat transfer though
     * conduction
     * @param htcQ is the result from the heatConduction method using
     * those know variables
     * @param Lf is the latent heat fusion coefficient for material
     */
    static ld massFromHeatTransferThroughConduction(const ld htcQ,
                                                    const ld Lf,
                                                    bool print = false)
    {
        auto mass = htcQ / Lf;
        if (print)
            std::cout << "heat transfer from conduction: " << mass << " kg"
            << std::endl;
        return mass;
    }

    /**
     * @breif temperatureDifferenceMaintainedByHeatTransfer
     * @param QmLv is the result from method
     * phaseChangeEnergy_vaporizationCondensation_Q using the known values in
     * this method will provide the result for this method, unless the value is
     * given directly of course
     * @param d is the thickness of the material
     * @param k is the thermal conductivity value
     * @param A is the surface area
     * @returns temperature difference maintained in heat transfer
     */
    static ld temperatureDifferenceMaintainedByHeatTransfer(const ld QmLv,
                                                            const ld d,
                                                            const ld k,
                                                            const ld A,
                                                            bool print = false)
    {
        auto temp_diff =  QmLv * (d / (k * A));
        if (print)
            std::cout << "temperature difference maintained by heat transfer: "
            << temp_diff << " K" << std::endl;
        return temp_diff;
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
    static ld stefanBoltzmannLawOfRadiation(const ld e,
                                            const ld A,
                                            const ld T,
                                            bool print = false)
    {
        auto P = constants::STEFAN_BOLTZMANN * e * A * pow(T, 4);
        if (print)
            std::cout << "heat transfer by emitted radiation: " << P << " W"
            << std::endl;
        return P;
    }

    /**
     * @brief calculate the temperature of spherical object using the
     * Stefan-Boltzmann law of radiation equation
     * @param e emissivity
     * @param A surface area of object
     * @param P radiation intensity
     * @ return temperature in Kelvin
     */
    static ld temperatureOfSphericalObject(const ld e,
                                           const ld R,
                                           const ld P,
                                           bool print = false)
    {
        auto T = pow(P / (4.0*constants::PI*(R*R) * e * constants::STEFAN_BOLTZMANN), 0.25);
        if (print)
            std::cout << "temperature of spherical object: " << T << " K"
            << std::endl;
        return T;
    }

    /**
     * @brief calculate the temperature of object using the Stefan-Boltzmann law
     * of radiation equation
     * @param e emissivity
     * @param A surface area of object
     * @param P radiation intensity
     * @ return temperature in Kelvin
     */
    static ld temperatureOfObject(const ld e,
                                  const ld A,
                                  const ld P,
                                  bool print = false)
    {
        auto T = pow(P / (e * constants::STEFAN_BOLTZMANN * A), 0.25);
        if (print)
            std::cout << "temperature of object: " << T << " K" << std::endl;
        return T;
    }

    /**
     * @brief calculate the surface area of spherical object using the
     * Stefan-Boltzmann law of radiation equation
     * @param e emissivity
     * @param P radiation intensity
     * @param T temperature in Kelvin
     * @return surface area of object
     */
    static ld surfaceAreaOfSphericalObject(const ld e,
                                           const ld R,
                                           const ld P,
                                           const ld T,
                                           bool print = false)
    {
        auto A = 4.0 * constants::PI * (R*R) * e * P / (constants::STEFAN_BOLTZMANN * T);
        if (print)
            std::cout << "surface area of spherical object: " << A << " m^2"
            << std::endl;
        return A;
    }

    /**
     * @brief calculate the surface area of object using the Stefan-Boltzmann law
     * of radiation equation
     * @param e emissivity
     * @param P radiation intensity
     * @param T temperature in Kelvin
     * @return surface area of object
     */
    static ld surfaceAreaOfObject(const ld e,
                                  const ld P,
                                  const ld T,
                                  bool print = false)
    {
        auto A = P / (constants::STEFAN_BOLTZMANN * e * pow(T , 4));
        if (print)
            std::cout << "surface area of object: " << A << " m^2" << std::endl;
        return A;
    }

    /** @brief calculate the emissivity of spherical object using the
     * Stefan-Boltzmann law of radiation equation
     * @param P radiation intensity
     * @param T temperature in Kelvin
     * @param R radius of object
     * @return emissivity of object
     */
    static ld emissivityOfSphericalObject(const ld P,
                                          const ld T,
                                          const ld R,
                                          bool print = false)
    {
        auto e = P / (4.0 * constants::PI * (R*R) * constants::STEFAN_BOLTZMANN * pow(T, 4));
        if (print)
            std::cout << "emissivity of spherical object: " << e << std::endl;
        return e;
    }

    /** @brief calculate the emissivity of object using the
     * Stefan-Boltzmann law of radiation equation
     * @param P radiation intensity
     * @param T temperature in Kelvin
     * @param A surface area of object
     * @return emissivity of object
     */
    static ld emissivityOfObject(const ld P,
                                 const ld T,
                                 const ld A,
                                 bool print = false)
    {
        auto e = P / (constants::STEFAN_BOLTZMANN * A * pow(T, 4));
        if (print)
            std::cout << "emissivity of object: " << e << std::endl;
        return e;
    }

    /**
     * @brief thermal resistance of a material
     * @param k thermal conductivity
     * @param d thickness of material
     * @param A surface area of material
     * @returns thermal resistance of material
     */
    static ld thermalResistance(const ld k,
                                const ld d,
                                const ld A,
                                bool print = false)
    {
        auto res = d / (k * A);
        if (print)
            std::cout << "thermal resistance: " << res << " K/W" << std::endl;
        return res;
    }

    /**
     * @brief Uses the Stefan-Boltzmann law of radiation equation
     * @param e
     */
    static ld netRateOfHeatTransferByRadiation(const ld e,
                                               const ld A,
                                               const ld T1,
                                               const ld T2)
    {
        return constants::STEFAN_BOLTZMANN * e * A * ((pow(T2, 4) - pow(T1, 4)));
    }

    /**
     * @brief calculates the initial temperature of falling water using
     * conservation of mechanical energy
     * @param h is the height of the fall of water or substance
     * @param Tf is the final temp after the drop occurs
     * @param _c is the specific heat of something(default is waters value of
     */
    static ld initialTempFromFallingWater(const ld h, const ld Tf, const ld
    _c_ = SHC.waterLiquid.J_kgC)
    {
        return  Tf - (constants::Ga * h) / _c_;
    }

    /**
     * @brief calculates the initial temperature of an object after being
     * submerged into a liquid of a certain temperature, by using the final temp
     * of both and the specific heats
     * of both as well in the equation T1i = ((m2c2(T2f-T2i))/(m1c1))+T1f
     * @param m1 mass of object 1 in kg
     * @param c1 specific heat of object 1
     * @param m2 mass of object 2 in kg
     * @param c2 specific heat of object 2
     * @param T2i initial temperature of object 2
     * @param finalTboth temperature of both objects after equilibrium
     * @returns initial temperature of object 1
     */
    static ld initialTempFromEqualLibrium(const ld m1,
                                          const ld c1,
                                          const ld m2,
                                          const ld c2,
                                          const ld T2i,
                                          const ld finalTboth)
    {
        return ((m2 * c2 * (finalTboth - T2i)) / (m1 * c1)) + finalTboth;
    }

    /**
     * @brief calculates the initial temperature of a substance after equilibrium
     * when in contact or mixed with same substance,
     * which means the specific heats cancel so we are left with a simpler
     * equation: T1i = ((m2(T2f-T2i))/(m1))+T1f
     * @param m1 mass of object 1 in kg
     * @param m2 mass of object 2 in kg
     * @param T2i initial temperature of object 2
     * @param finalTboth temperature of both objects after equilibrium
     * @returns initial temperature of object 1
     */
    static ld initialTempFromEqualLibrium(const ld m1,
                                          const ld m2,
                                          const ld T2i,
                                          const ld finalTboth)
    {
        return ((m2 * (finalTboth - T2i)) / (m1)) + finalTboth;
    }

    /**
     * @brief calculates the amount of a fluid added to another fluid in single
     * container(think adding creamer to coffee)
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
            (const ld m1cup,
             const ld c1cup,
             const ld T1cup,
             const ld m2cof,
             const ld c2cof,
             const ld T2cof,
             const ld c3cr,
             const ld T3cr,
             const ld Tf,
             char mode = 'k')
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
    static ld thicknessOfIceOnWindshield(const ld iceTemp,
                                         const ld surfaceArea,
                                         const ld energyToMelt,
                                         const ld lf = LF.water.kJ_kg,
                                         const ld c = SHC.iceAverageSolid.J_kgC,
                                         const ld density = 917.0)
    {
        cout << "lf: " << lf << endl;
        auto q1 = c * -iceTemp;
        cout << "q1: " << q1 << endl;
        auto q2 = q1 + lf;
        cout << "q2: " << q2 << endl;
        auto q3 = energyToMelt / q2;
        cout << "q3: " << q3 << endl;
        auto volumeIce = q3 / density;
        cout << "v: " << volumeIce << endl;
        cout << "thickness: : " << volumeIce / surfaceArea << endl;
        return volumeIce / surfaceArea;
    }


    /**
     * @calculaes tF of a ice cube placed in water
     */
    static ld finalTemperatureMeltingIceInWater(const ld mI,
                                                const ld cI,
                                                const ld Ti,
                                                const ld mW,
                                                const ld cW,
                                                const ld Tw,
                                                const ld Lfw = LF.water.kcal_kg)
    {
        auto q1 = mI * cI * -Ti;
        auto q2 = mI * Lfw;
        auto q3 = mI;
        auto q4 = mW * cW * -Tw;
        return (-q4 - (q1+q2))/(q3 + mW);
    }

    /**
     * @brief calculates the final temperature of a bowl of soup placed in a
     * freezer when a specified amount of energy is transferred away from the
     * objects by the freezer the final temp found
     * @param m_b mass of bowl in Kg
     * @param c_b specific heat of bowl(varies with what bowl is made from)
     * @param m_s mass of soup in kg
     * @param c_s specific heat of soup (similar to that of water in most cases)
     * @param c_i specific heat of ice
     * @param Ti initial temperature of the soup and bowl
     * @param Lf latent heat of fusion
     * @param Q total energy transferred from soup and bowl
     */
    static ld finalTempBowlSoupInFreezer(const ld m_b,
                                         const ld c_b,
                                         const ld m_s,
                                         const ld c_s,
                                         const ld c_i,
                                         const ld Ti,
                                         const ld Lf,
                                         const ld Q)
    {
        return ((((m_b * c_b) * (Ti)) + ((m_s * c_s) * (Ti))) + (m_s * Lf) - Q)
                / ((m_b * c_b) + (m_s * c_i));
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
    /// <param name="deltaTemp">The change in temperature.</param>
    /// <param name="P">The power output.</param>
    /// <returns>time to heat object by specified temperature</returns>
    static ld timeToHeatObject(const ld m,
                               const ld c_,
                               const ld deltaTemp,
                               const ld P,
                               bool print = false)
    {
        auto time = (m * c_ * deltaTemp) / P;
        if(print)
            cout << "time to heat object: " << time << endl;
        return time;
    }

    static ld rFactor(const ld x, const ld k, bool print = false)
    {
        auto r = x / k;
        if(print)
            cout << "r factor: " << r << endl;
        return r;
    }

    /**
     * @brief calculates the surface areas of a house
     * @param length  length of house
     * @param width  width of house
     * @param heightToBaseOfRoof  height of house to base of roof
     * @param heightOfGable  height of gable
     * @param angelOfRoof  angle of roof
     * @param numberOfWindows  number of windows
     * @param widthOfWindows  width of windows
     * @param heightOfWindows  height of windows
     * @param print  print results
     * @return surface area of house
     */
    static vector<ld> calculateSurfaceAreaOfHouse(bool print = false,
                                                  ld length=0.0,
                                                  ld width=0.0,
                                                  ld heightToBaseOfRoof=0.0,
                                                  ld heightOfGable=0.0,
                                                  ld angelOfRoof=0.0,
                                                  ld numberOfWindows=0.0,
                                                  ld widthOfWindows=0.0,
                                                  ld heightOfWindows=0.0) {
        ld surfaceAreaOfWalls = 0.0;
        ld surfaceAreaOfRoof = 0.0;
        ld surfaceAreaOfWindows = 0.0;
        ld totalSurfaceArea = 0.0;
        vector<ld> results;
        // check if length and width are 0 and if so prompt user for input
        if (length == 0.0 && width == 0.0) {
            std::cout << "Enter the length of the house: ";
            std::cin >> length;
            std::cout << "Enter the width of the house: ";
            std::cin >> width;
            std::cout << "Enter the height to the base of the roof: ";
            std::cin >> heightToBaseOfRoof;
            std::cout << "Enter the height of the gable: ";
            std::cin >> heightOfGable;
            std::cout << "Enter the angle of the roof: ";
            std::cin >> angelOfRoof;
            std::cout << "Enter the number of windows: ";
            std::cin >> numberOfWindows;
            std::cout << "Enter the width of the windows: ";
            std::cin >> widthOfWindows;
            std::cout << "Enter the height of the windows: ";
            std::cin >> heightOfWindows;
        }

        // caluculate the surface area of the walls
        surfaceAreaOfWalls = (length * heightToBaseOfRoof * 2) +
                             (width * heightToBaseOfRoof * 2) +
                             ((1.0/2.0) * heightOfGable * tan(angelOfRoof*constants::RADIAN) *
                              width * 2);

        // calculate the surface area of the roof
        surfaceAreaOfRoof = (2.0 * length * (heightOfGable/cos
                (angelOfRoof*constants::RADIAN)));

        // calculate the surface area of the windows
        surfaceAreaOfWindows = numberOfWindows * widthOfWindows * heightOfWindows;

        // calculate the total surface area of the house
        totalSurfaceArea = surfaceAreaOfWalls + surfaceAreaOfRoof;

        // print the results
        if (print) {
            std::cout << "The surface area of the house is: " << totalSurfaceArea << std::endl;
            // print the surface area of the walls
            std::cout << "The surface area of the walls is: " << surfaceAreaOfWalls
                      << std::endl;
            // print the surface area of the roof
            std::cout << "The surface area of the roof is: " << surfaceAreaOfRoof << std::endl;
            // print the surface area of the windows
            std::cout << "The surface area of the windows is: " << surfaceAreaOfWindows << std::endl;
        }

        results.push_back(totalSurfaceArea);
        results.push_back(surfaceAreaOfWalls);
        results.push_back(surfaceAreaOfRoof);
        results.push_back(surfaceAreaOfWindows);

        return results;
    }

    static ld calculateHeatLossOfHouse(
            ld temperatureOfHouse,
            ld temperatureOfOutside,
            ld rValueOfWalls,
            ld rValueOfRoof,
            ld rValueOfWindows,
            bool print = false,
            ld surfaceAreaOfHouse=0.0,
            ld surfaceAreaOfWalls=0.0,
            ld surfaceAreaOfRoof=0.0,
            ld surfaceAreaOfWindows=0.0)
    {
        ld heatLossOfWalls = 0.0;
        ld heatLossOfRoof = 0.0;
        ld heatLossOfWindows = 0.0;
        ld totalHeatLoss = 0.0;
        // check if surface area of house is 0 and if so call calculateSurfaceAreaOfHouse
        if (surfaceAreaOfHouse == 0.0) {
            vector<ld> results = calculateSurfaceAreaOfHouse(true);
            surfaceAreaOfHouse = results[0];
            surfaceAreaOfWalls = results[1];
            surfaceAreaOfRoof = results[2];
            surfaceAreaOfWindows = results[3];
        }

        // calculate the heat loss of the walls
        heatLossOfWalls = (temperatureOfHouse - temperatureOfOutside) *
                          ((surfaceAreaOfWalls - surfaceAreaOfWindows) /
                          rValueOfWalls);
        // calculate the heat loss of the roof
        heatLossOfRoof = (temperatureOfHouse - temperatureOfOutside) *
                         (surfaceAreaOfRoof / rValueOfRoof);
        // calculate the heat loss of the windows
        heatLossOfWindows = (temperatureOfHouse - temperatureOfOutside) *
                            (surfaceAreaOfWindows / rValueOfWindows);
        // calculate the total heat loss of the house
        totalHeatLoss = heatLossOfWalls + heatLossOfRoof + heatLossOfWindows;
        // print the results
        if (print) {
            std::cout << "The total heat loss of the house is: " <<
            totalHeatLoss << " Btu/hr" << std::endl;
            // print the heat loss of the walls
            std::cout << "The heat loss of the walls is: " << heatLossOfWalls << std::endl;
            // print the heat loss of the roof
            std::cout << "The heat loss of the roof is: " << heatLossOfRoof << std::endl;
            // print the heat loss of the windows
            std::cout << "The heat loss of the windows is: " << heatLossOfWindows << std::endl;
        }
        return totalHeatLoss;
    }


    /**
     *@brief destructor
     */
    ~Heat()
    {
        countDecrease();
    }
};

#endif //PHYSICSFORMULA_HEAT_H
