//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_FLUIDSTATICS_H
#define PHYSICSFORMULA_FLUIDSTATICS_H
/**
 * @class FluidStatics
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @date   10/15/2020
 */
#include <iostream>

#include "Constants.h"

static int fluidStatics_objectCount = 0;

static struct VolumeCalculator
{
    /**
    * @brief calculates the volume of a sphere
    * @param r radius
    */
    static ld sphere(const ld r)
    {
        return (4.0 / 3.0) * constants::PI * pow(r, 3.0);
    }
    /**
    * @brief calculates the volume of a cone
    * @param r radius
    * @param h height
    */
    static ld cone(const ld r, const ld h)
    {
        return (1.0 / 3.0) * constants::PI * pow(r, 2.0) * h;
    }
    /**
    * @brief calculates the volume of a cube
    * @param edgeL edge length
    */
    static ld cube(const ld edgeL)
    {
        return pow(edgeL, 3.0);
    }
    /**
    * @brief calculates the volume of a cylinder
    * @param r radius
    * @param h height
    */
    static ld cylinder(const ld r, const ld h)
    {
        return constants::PI * r * 2 * h;
    }
    /**
    * @brief calculates the volume of rectangular tank
    * @param l length
    * @param w width
    * @param h height
    */
    static ld rectangularTank(const ld l, const ld w, const ld h)
    {
        return l * w * h;
    }

    /**
    * @brief calculates the volume of capsule
    * @param r radius
    * @param h height
    * returns volume m^3
    */
    static ld capsule(const ld r, const ld h)
    {
        return (constants::PI * pow(r, 2.0)) * ((4.0 / 3.0) * r + h);
    }

    /**
    * @brief calculates the volume of spherical cap (button-like)
    * @param r radius
    * @param h height
    * returns volume m^3
    */
    static ld sphericalCap(const ld r, const ld h)
    {
        return ((1.0 / 3.0) * constants::PI * pow(h, 2.0)) * (3.0 * r - h);
    }

}v;

static struct PressureConversions
{
    static ld atm_to_Pa(const ld atm)
    {
        return atm * 1.013 * pow(10, 5);// Pa = N/m^2
    }

    static ld dynePer_cmSquared_to_Pa(const ld d)
    {
        return d * .10;// Pa = N/m^2
    }
    static ld Pa_to_dynePer_cmSquared(const ld Pa)
    {
        return Pa / .10;// dyne/cm^2
    }
    static ld kgPer_cmSquared_to_Pa(const ld kg)
    {
        return kg * 9.8 * pow(10, 4);// N/m^2
    }
    static ld Pa_to_kgPer_cmSquared(const ld Pa)
    {
        return Pa / 9.8 * pow(10, 4);// kg/cm^2
    }
    static ld lbPer_inSquared_to_Pa(const ld atm)
    {
        return atm * 1.013 * pow(10, 5);// N/m^2
    }
    static ld Pa_to_lbPer_inSquared(const ld Pa)
    {
        return Pa / 1.013 * pow(10, 5);// lb/in^2
    }
    static ld mmHg_to_Pa(const ld mm)
    {
        return mm * 133.3224;// N/m^2
    }
    static ld Pa_to_mmHg(const ld Pa)
    {
        return Pa / 133.3224;// mm Hg
    }
    static ld cmHg_to_Pa(const ld cm)
    {
        return cm * 1.33 * pow(10, 3);// N/m^2
    }
    static ld Pa_to_cmHg(const ld Pa)
    {
        return Pa / 1.33 * pow(10, 3);// cm Hg
    }
    static ld cmWater_to_Pa(const ld w)
    {
        return w * 98.1;// N/m^2
    }
    static ld Pa_to_cmWater(const ld Pa)
    {
        return Pa / 98.1;// cm water
    }
    static ld bar_to_Pa(const ld bar)
    {
        return bar * 1.000 * pow(10, 5);// N/m^2
    }
    static ld Pa_to_bar(const ld Pa)
    {
        return Pa / 1.000 * pow(10, 5);// bar
    }
    static ld millibar_to_Pa(const ld cm)
    {
        return cm * 1.000 * pow(10, 2);// Pa = N/m^2
    }
    static ld Pa_to_millibar(const ld Pa)
    {
        return Pa / 1.000 * pow(10, 2);// millibar
    }
    static ld atm_to_dyneCmSquared(const ld atm)
    {
        return atm * 1.013 * pow(10, 6);// dyne/cm^2
    }
    static ld dyneCmSquared_to_atm(const ld n)
    {
        return n / 1.013 * pow(10, 6);// atm
    }
    static ld atm_to_kgCmSquared(const ld atm)
    {
        return atm * 1.013;// kg/cm^2
    }
    static ld kgCmSquared_to_atm(const ld n)
    {
        return n / 1.013;// atm
    }
    static ld atm_to_lbsPerInchSquared(const ld atm)
    {
        return atm * 14.7;// lb/in^2
    }
    static ld lbsPerInchSquared_to_atm(const ld n)
    {
        return n / 14.7;// atm
    }
    static ld atm_to_mmHg(const ld atm)
    {
        return atm * 760.0;// mm Hg
    }
    static ld mmHg_to_atm(const ld n)
    {
        return n / 760.0;// atm
    }
    static ld atm_to_cmHg(const ld atm)
    {
        return atm * 76.0;// cm Hg
    }
    static ld cmHg_to_atm(const ld n)
    {
        return n / 76.0;// atm
    }
    static ld atm_to_cmWater(const ld atm)
    {
        return atm * 1.03 * pow(10, 3);// cm water
    }
    static ld cmWater_to_atm(const ld n)
    {
        return n / 1.03 * pow(10, 3);// atm
    }
    static ld atm_to_bar(const ld atm)
    {
        return atm * 1.013;// bar
    }
    static ld bar_to_atm(const ld n)
    {
        return n / 1.013;// atm
    }
    static ld atm_to_millibar(const ld atm)
    {
        return atm * 1013;// millibar
    }
    static ld millibar_to_atm(const ld n)
    {
        return n / 1013;// atm
    }
}pressure_converter;

static struct SurfaceTensions
{
    const ld water_0C = 0.0756; // 0.0756 N/m
    const ld water_20C = 0.0728; // 0.0728 N/m
    const ld water_100C = 0.0589; // 0.0589 N/m
    const ld soapyWater_typical = 0.0370; // 0.0370 N/m
    const ld ethyl_alcohol = 0.0223; // 0.0223 N/m
    const ld glycerin = 0.0631; // 0.0631 N/m
    const ld mercury = 0.465; // 0.465 N/m
    const ld olive_oil = 0.032; // 0.032 N/m
    const ld tissueFluids_typical = 0.050; // 0.050 N/m
    const ld blood_whole_at_37C = 0.058; // 0.058 N/m
    const ld blood_plasma_at_37C = 0.073; // 0.073 N/m
    const ld gold_at_1070C = 1.00; // 1.00 N/m
    const ld oxygen_at_negative193C = 0.0157; // 0.0157 N/m
    const ld helium_at_negative269C = 0.00012; // 0.00012 N/m

}surface_tensions;

static struct ContactAngles
{
    const ld mercury_glass = 140.0; // 140 degrees
    const ld water_glass = 0.0; // 0.0 degrees
    const ld water_paraffin = 107.0; // 107.0 degrees
    const ld water_silver = 90.0; // 90.0 degrees
    const ld organic_liquids_most_glass = 0.0; // 0.0 degrees
    const ld ethyl_alcohol_glass = 0.0; // 0.0 degrees
    const ld kerosene_glass = 26.0; // 26.0 degrees
}contact_angles;


/**
* @brief circumference to radius
*/
static ld radiusFromCircumference(const ld c)
{
    return c / (2 * constants::PI);
}
/**
* @brief diameter to radius
*/
static ld radiusFromDiameter(const ld d){
    return d/2;
}


class FluidStatics
{

public:
    FluidStatics* _fluidStaticPtr;


    FluidStatics()
    {
        _fluidStaticPtr = nullptr;
        countIncrease();
    }

    /**
     * @brief copy constructor
     */
    FluidStatics(const FluidStatics& t)
    {
        _fluidStaticPtr = t._fluidStaticPtr;
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    FluidStatics(FluidStatics&& t) noexcept
    {
        _fluidStaticPtr = t._fluidStaticPtr;
        countIncrease();
    }
    /**
     * @brief copy assignment operator
     */
    FluidStatics& operator=(const FluidStatics& t)
    {
        if (this != &t)
        {
            _fluidStaticPtr = t._fluidStaticPtr;
            countIncrease();
        }
        return *this;
    }

    static void show_objectCount() { std::cout << "\nfluid statics object count: "
    << fluidStatics_objectCount << std::endl; }
    static int get_objectCount() { return fluidStatics_objectCount; }


    /// <summary>
    /// calculates the density with know mass and volume.
    /// </summary>
    /// <param name="mass">The mass.</param>
    /// <param name="volume">The volume.</param>
    /// <returns>density</returns>
    static ld density(const ld mass, const ld volume, bool print = false) {
        ld density = mass / volume;     if (print) {
            std::cout << "density: " << density << std::endl;
        }
        return density;
    }

    /// <summary>
    /// calculates the density of a substance made of other substances by adding
    /// the total parts together.
    /// example: 18.0-karat gold that is a mixture of 18 parts gold, 5 parts
    /// silver, and 1 part copper?
    /// (These values are parts by mass, not volume.)
    /// Assume that this is a simple mixture having an average density equal to
    /// the weighted densities of its constituents
    /// </summary>
    /// <param name="partsA">The parts of substance A.</param>
    /// <param name="pA">The density of substance A.</param>
    /// <param name="partsB">The parts of substance B.</param>
    /// <param name="pB">The density of substance B.</param>
    /// <param name="partsC">The parts of substance dC</param>
    /// <param name="pC">The density of substance C.</param>
    /// <returns></returns>
    static ld densityAvg_partsByMass(const ld partsA,
                                     const ld pA,
                                     const ld partsB = 0.0,
                                     const ld pB = 0.0,
                                     const ld partsC = 0.0,
                                     const ld pC = 0.0)
    {
        return (partsA + partsB + partsC) /
        ((partsA / pA) + (partsB / pB) + (partsC / pC));
    }


    static ld densityAvg_partsByMass(const vector<ld>& parts, const vector<ld>& p)
    {
        ld numerator = 0.0;
        ld denominator = 0.0;
        for (int i = 0; i < parts.size(); i++)
        {
            numerator += parts[i];
            denominator += parts[i]/p[i];
        }
        return numerator / denominator;
    }

    /// <summary>
    /// calculates the average density using mass and density of .
    /// </summary>
    /// <param name="massA">The mass a.</param>
    /// <param name="pA">The p a.</param>
    /// <param name="massB">The mass b.</param>
    /// <param name="pB">The p b.</param>
    /// <param name="massC">The mass c.</param>
    /// <param name="pC">The p c.</param>
    /// <returns></returns>
    static ld densityAvg(const ld massA,
                         const ld pA,
                         const ld massB = 0.0,
                         const ld pB = 0.0,
                         const ld massC = 0.0,
                         const ld pC = 0.0)
    {
        return (massA + massB + massB) / ((massA / pA) + (massB / pB) + (massC / pC));
    }
    static ld densityAvg(const vector<ld>& mass, const vector<ld>& p)
    {
        ld numerator = 0.0;
        ld denominator = 0.0;
        for (int i = 0; i < mass.size(); i++)
        {
            numerator += mass[i];
            denominator += mass[i] / p[i];
        }
        return numerator / denominator;
    }

    /// <summary>
    /// calculates the volume from the mass and density.
    /// </summary>
    /// <param name="mass">The mass.</param>
    /// <param name="density">The density.</param>
    /// <returns>the volume</returns>
    static ld volume(const ld mass,
                     const ld density,
                     bool print = false) {
        ld volume = mass / density;
        if (print)
        {
            cout << "volume: " << volume << endl;
        }
        return volume;
    }

    /// <summary>
    /// calculates the mass from the density and volume.
    /// </summary>
    /// <param name="density">The density.</param>
    /// <param name="volume">The volume.</param>
    /// <returns>the mass</returns>
    static ld mass(const ld density,
                   const ld volume,
                   bool print = false) {
        auto mass = density * volume;
        if (print) {
            cout << "mass: " << mass << endl;
        }
        return mass;
    }

    /// <summary>
    /// Calculates the mass of fluid displaced my weight of object.
    /// </summary>
    /// <param name="massOut">The mass of object out of fluid.</param>
    /// <param name="massIn">The mass of object in the fluid.</param>
    /// <returns>mass of displaced fluid</returns>
    static ld massOfFluidDisplaced(const ld massOut,
                                   const ld massIn)
    {
        return massOut - massIn;
    }

    /// <summary>
    /// calculates the pressure form force and area.
    /// </summary>
    /// <param name="force">The force.</param>
    /// <param name="area">The area.</param>
    /// <returns>pressure</returns>
    static ld pressure(const ld force,
                       const ld area) {
        return force / area;
    }

    /**
     * @brief calculates the pressure on bottom of tank
     * using P = F / A, F = ma and A = l*w
     * @param m the mass
     * @param l the length
     * @param w the width
     * @returns the pressure on bottom of tank
     */
    static ld pressure(const ld m,
                       const ld l,
                       const ld w)
    {
        return (m * constants::Ga) / (l * w);
    }

    /**
     * @brief calculates the average pressure.
     * @param p the density
     * @param l the length
     * @param h the height
     * @return the average pressure
     */
    static ld pressureAvg(const ld p,
                          const ld l,
                          const ld h)
    {
        return ((p * constants::Ga * h) / 2.0) * (l * h);
    }

    /// <summary>
    /// calculates the surface tension
    /// </summary>
    /// <param name="force">The force per unit length.</param>
    /// <param name="length">length exerted by a stretched liquid membrane.</param>
    /// <returns>surface tension</returns>
    static ld surfaceTension(const ld force,
                             const ld length)
    {
        return force / length;
    }

    /// <summary>
    /// calculates the pressure in a sphere.
    /// </summary>
    /// <param name="surfaceTension">The surface tension.</param>
    /// <param name="radius">The radius.</param>
    /// <returns>pressure inside a sphere</returns>
    static ld pressureInSphericalObject(const ld surfaceTension,
                                        const ld radius)
    {
        return (4.0 * surfaceTension) / radius;
    }

    /// <summary>
    /// the surface tension of a spherical object.
    /// </summary>
    /// <param name="pressure">The pressure.</param>
    /// <param name="radius">The radius.</param>
    /// <returns>surface tension</returns>
    static ld surfaceTensionSphericalObject(const ld pressure,
                                            const ld radius)
    {
        return (pressure * radius) / 4.0;
    }

    /// <summary>
    /// Force caused by a pressure.
    /// </summary>
    /// <param name="pressure">the pressure</param>
    /// <param name="area">the area</param>
    /// <returns>force</returns>
    static ld force(const ld pressure,
                    const ld area) {
        return pressure * area;
    }

    /// <summary>
    /// Force needed by the master hydraulic to support weight on the slave.
    /// </summary>
    /// <param name="m">The mass.</param>
    /// <param name="dM">The diameter master.</param>
    /// <param name="dS">The diameter slave s.</param>
    /// <returns>Force master cylinder</returns>
    static ld forceMaster_hydraulicSystemPascal(const ld m,
                                                const ld dM,
                                                const ld dS)
    {
        return (m * constants::Ga * (dM * dM)) / (dS * dS);
    }

    /// <summary>
    /// Force2 using pascals principles.
    /// </summary>
    /// <param name="F1">Force 1.</param>
    /// <param name="a1">The area 1.</param>
    /// <param name="a2">The area 2.</param>
    /// <returns>Force 2 in newtons</returns>
    static ld force2pascalPrinciples(const ld F1,
                                     const ld a1,
                                     const ld a2)
    {
        return F1 * (a2 / a1);
    }

    /// <summary>
    /// Radius of a cylinder.
    /// </summary>
    /// <param name="m">The mass.</param>
    /// <param name="h">The height.</param>
    /// <param name="_p">The density.</param>
    /// <returns>the radius</returns>
    static ld radiusCylinder(const ld m,
                             const ld h,
                             const ld _p)
    {
        return sqrt((m * _p) / (constants::PI * h));
    }

    /// <summary>
    /// Depth of a rectangular tank.
    /// </summary>
    /// <param name="m">The mass.</param>
    /// <param name="_p">The density.</param>
    /// <param name="l">The length.</param>
    /// <param name="w">The width.</param>
    /// <returns></returns>
    static ld depthRectangularTank(const ld m,
                                   const ld _p,
                                   const ld l,
                                   const ld w)
    {
        return m / (_p * l * w);
    }

    /// <summary>
    /// Ratios the of density.
    /// </summary>
    /// <param name="percentDecrease">The percent decrease.</param>
    /// <returns></returns>
    static ld ratioOfDensity(const ld percentDecrease)
    {
        return 1.0 / percentDecrease;
    }

    /// <summary>
    /// Radius of a sphere with a known mass and density
    /// </summary>
    /// <param name="m">The mass.</param>
    /// <param name="p">The density.</param>
    /// <returns>radius</returns>
    static ld radiusOfSphere(const ld m, const ld p)
    {
        return pow((3.0 * m) / (4.0 * constants::PI * p), 1 / 3);
    }

    /// <summary>
    /// calculates the height of the fluid.
    /// </summary>
    /// <param name="pressure">The pressure.</param>
    /// <param name="density">The density.</param>
    /// <returns>height</returns>
    static ld heightOfFluid(const ld pressure, const ld density)
    {
        return pressure / (density * constants::Ga);
    }

    /// <summary>
    /// calculates the gauge-pressure from density and height of a fluid.
    /// </summary>
    /// <param name="density">The density.</param>
    /// <param name="height">The height.</param>
    /// <returns></returns>
    static ld gaugePressure(const ld density, const ld height)
    {
        return density * constants::Ga * height;
    }

    /// <summary>
    /// Area the in contact
    /// </summary>
    /// <param name="F">The force.</param>
    /// <param name="P">The pressure.</param>
    /// <returns>area in contact</returns>
    static ld area(const ld F, const ld P)
    {
        return F / P;
    }

    /// <summary>
    /// Fraction of object submerged.
    /// </summary>
    /// <param name="avgDensityObject">The average density of the object.</param>
    /// <param name="densityFluid">The density of the fluid.</param>
    /// <returns>the fraction of the object that will be submerged</returns>
    static ld fractionSubmerged(const ld avgDensityObject, const ld densityFluid)
    {
        return avgDensityObject / densityFluid;
    }

    /// <summary>
    /// calculates the relative density. if object floats will be less than 1.0
    /// if object sinks will be over 1, and if is 1 will remain suspended in the
    /// fluid, either sinking or floating
    /// </summary>
    /// <param name="densitySubstance">The density of the test substance.</param>
    /// <param name="densityReference">The density of the reference
    /// substance.</param>
    /// <returns>the relative density</returns>
    static ld relativeDensity(const ld densitySubstance, const ld densityReference)
    {
        return densitySubstance / densityReference;
    }

    /// <summary>
    /// Density of the fluid.
    /// </summary>
    /// <param name="densityObject">The density of the object.</param>
    /// <param name="percentSubmerged">The percent of the object that is
    /// submerged.</param>
    /// <returns>the density of the fluid</returns>
    static ld densityOfFluid(const ld densityObject, const ld percentSubmerged)
    {
        return densityObject / (percentSubmerged / 100.0);
    }

    /// <summary>
    /// Force required to stay submerged. think fish
    /// </summary>
    /// <param name="massObj">The mass object.</param>
    /// <param name="densityObj">The density object.</param>
    /// <param name="densityFluid">The density fluid.</param>
    /// <returns>force</returns>
    static ld forceToStaySubmerged(const ld massObj,
                                   const ld densityObj,
                                   const ld densityFluid)
    {
        return massObj * constants::Ga * ((densityFluid / densityObj) - 1.0);
    }

    /// <summary>
    /// Calculates the maximum weight supported my an air mattress
    /// </summary>
    /// <param name="massMattress">The mass of the air mattress.</param>
    /// <param name="length">The length.</param>
    /// <param name="width">The width.</param>
    /// <param name="height">The height.</param>
    /// <param name="fluidDensity">The fluids density.</param>
    /// <returns>max weight before sinking in fluid</returns>
    static ld maxWeightSupportedByFloatingAirMattress(const ld massMattress,
                                                      const ld length,
                                                      const ld width,
                                                      const ld height,
                                                      const ld fluidDensity,
                                                      bool print = false) {
        auto result = constants::Ga * (fluidDensity * (length * width *
                height) -
        massMattress);
        if (print) {
            std::cout << "max weight supported by floating air mattress: "
            << result << std::endl;
        }
        return result;
    }

    /// <summary>
    /// calculates the capacity of lungs.
    /// </summary>
    /// <param name="mass">The mass.</param>
    /// <param name="percentFloatLungEmpty">The percent floating when lung
    /// empty.</param>
    /// <param name="percentFloatLungFull">The percent floating when lung
    /// full.</param>
    /// <param name="densityFluid">The density of the fluid.</param>
    /// <returns>capacity in m^3, multiply answer by 1000 to have in liters
    /// cubed</returns>
    static ld lungCapacity(const ld mass,
                           const ld percentFloatLungEmpty,
                           const ld percentFloatLungFull,
                           const ld densityFluid,
                           bool print = false) {
        auto result = (mass / densityFluid) *
                ((1.0 / (1.0 -(percentFloatLungFull / 100.0)) -
                (1.0 / (1.0 - (percentFloatLungEmpty / 100.0)))));
        if (print)  {
            std::cout << "Lung Capacity: " << result << " m^3" << std::endl;
        }
        return result;
    }

    /// <summary>
    /// calculates the capillary tube height.
    /// </summary>
    /// <param name="surfaceTension">The surface tension.</param>
    /// <param name="contactAngle">The contact angle.</param>
    /// <param name="density">The density.</param>
    /// <param name="radius">The radius.</param>
    /// <returns>height the fluid will rise in a capillary tube</returns>
    static ld capillaryTubeHeight(const ld surfaceTension,
                                  const ld contactAngle,
                                  const ld density,
                                  const ld radius,
                                  bool print = false) {
        auto result = (2.0 * surfaceTension * cos(contactAngle)) /
        (density * constants::Ga * radius);
        if (print) {
            std::cout << "Capillary Tube Height: " << result << " m" << std::endl;
        }
        return result;
    }

    /// <summary>
    ///  calculates the capillaries tube radius.
    /// </summary>
    /// <param name="surfaceTension">The surface tension.</param>
    /// <param name="contactAngle">The contact angle.</param>
    /// <param name="density">The density.</param>
    /// <param name="height">The height.</param>
    /// <returns>the radius of a capillary tube</returns>
    static ld capillaryTubeRadius(const ld surfaceTension,
                                  const ld contactAngle,
                                  const ld density,
                                  const ld height,
                                  bool print = false) {
            auto result = (2.0 * surfaceTension * cos(contactAngle)) /
            (density * constants::Ga * height);
            if (print) {
                std::cout << "Capillary Tube Radius: " << result << " m"
                << std::endl;
            }
            return result;
    }

    /// <summary>
    /// calculates the surfaces tension using a sliding wire device.
    /// </summary>
    /// <param name="force">The force.</param>
    /// <param name="lengthOfWire">The length of wire.</param>
    /// <returns>gamma(surface tension)</returns>
    static ld surfaceTension_usingSlidingWireDevice(const ld force,
                                                    const ld lengthOfWire,
                                                    bool print = false) {
        auto result = force / (2.0 * lengthOfWire);
        if (print) {
            std::cout << "Surface Tension: " << result << " N/m" << std::endl;
        }
        return result;
    }

    /// <summary>
    /// Effective surface tension of a ballon.
    /// </summary>
    /// <param name="density">The density.</param>
    /// <param name="height">The height.</param>
    /// <param name="radius">The radius.</param>
    /// <returns>surface tension</returns>
    static ld effectiveSurfaceTensionBalloon(const ld density,
                                             const ld height,
                                             const ld radius,
                                             bool print = false) {
        auto result = (density * constants::Ga * height * radius) / 4.0;
        if (print) {
            std::cout << "Effective Surface Tension: " << result << " N/m"
            << std::endl;
        }
        return result;
    }

    /// <summary>
    /// Hieghts the of capillary action by ratio of contact angles.
    /// </summary>
    /// <param name="height1">The height1.</param>
    /// <param name="contactAngle1">The contact angle1.</param>
    /// <param name="contactAngle2">The contact angle2.</param>
    /// <returns></returns>
    static ld heightOfCapillaryActionByRatioOfContactAngles(
            const ld height1,
            const ld contactAngle1,
            const ld contactAngle2,
            bool print = false) {
        auto result = height1 * (cos(contactAngle2*constants::RADIAN) /
                cos(contactAngle1*constants::RADIAN));
        if (print) {
            std::cout << "Height of Capillary Action: " << result << " m"
            << std::endl;
        }
        return result;
    }

    /// <summary>
    /// calculates the contact angle theta.
    /// </summary>
    /// <param name="density">The density.</param>
    /// <param name="height">The height.</param>
    /// <param name="radius">The radius.</param>
    /// <param name="surfaceTension">The surface tension.</param>
    /// <returns>contact angle</returns>
    static ld contactAngleTheta(const ld density,
                                const ld height,
                                const ld radius,
                                const ld surfaceTension,
                                bool print = false) {
        auto result =  acos((density * constants::Ga * height * radius) /
                (2.0 * surfaceTension))*constants::DEGREE;
        if (print) {
            std::cout << "Contact Angle Theta: " << result << " rad" << std::endl;
        }
        return result;
    }

    /// <summary>
    /// calculates the ratio of heights of capillary action.
    /// </summary>
    /// <param name="st1">The surface tension 1.</param>
    /// <param name="ca1">The contact angle 1.</param>
    /// <param name="density1">The density 1.</param>
    /// <param name="st2">The surface tension 2.</param>
    /// <param name="ca2">The contact angle 2.</param>
    /// <param name="density2">The density 2.</param>
    /// <returns>ration of heights</returns>
    static ld ratioOfHeights_capillaryAction(const ld st1,
                                             const ld ca1,
                                             const ld density1,
                                             const ld st2,
                                             const ld ca2,
                                             const ld density2,
                                             bool print = false) {
        auto result = (st1 * cos(ca1*constants::RADIAN) * density2) /
                      (st2 * cos(ca2*constants::RADIAN) * density1);
        if (print) {
            std::cout << "Ratio of Heights: " << result << std::endl;
        }
        return result;
    }


    /**
    * @brief destructor
    */
    ~FluidStatics()
    {
        delete _fluidStaticPtr;
        countDecrease();
    }

private:
    static void countIncrease() { fluidStatics_objectCount += 1; }
    static void countDecrease() { fluidStatics_objectCount -= 1; }
};
#endif //PHYSICSFORMULA_FLUIDSTATICS_H
