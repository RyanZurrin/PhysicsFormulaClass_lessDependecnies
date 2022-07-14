//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_FLUIDDYNAMICS_H
#define PHYSICSFORMULA_FLUIDDYNAMICS_H
/**
 * @class FluidDynamics
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @date   12/17/2020
 */
#include <iostream>
#include <cmath>
#include "Constants.h"
using namespace std;
static int fluidDynamic_objectCount = 0;

static struct FlowRateConversions
{
    static ld litersPerSecond_to_cubicMetersPerSecond(const ld lps)
    {
        return lps * .001; // m^3/sec
    }
    static ld litersPerSecond_to_cubicMetersPerMin(const ld lps)
    {
        return lps * .06; // m^3/min
    }

    static ld literMin_to_cubicCentimeterSecond(const ld ltrMin)
    {
        return ltrMin * 16.6667; // cm^3/s
    }
    static ld cubicCentimeterSecond_to_literMin(const ld ccms)
    {
        return ccms / 16.6667; // L/min
    }
    static ld literMin_to_cubicMeterSecond(const ld ltrMin)
    {
        return ltrMin * 1.6667 * pow(10.0, -5.0); // m^3/s
    }
    static ld cubicMeterSecond_to_literMin(const ld cms)
    {
        return cms / 1.6667 * pow(10.0, -5.0); // L/min
    }


}flow_rate_converter;

static struct ViscosityCoefficients
{
    const ld air_0C = 0.0171; //mPa*s
    const ld air_20C = 0.0181; //mPa*s
    const ld air_40C = 0.0190; //mPa*s
    const ld air_100C = 0.00974; //mPa*s
    const ld ammonia_20C = 0.00974; // mPa*s
    const ld carbonDioxide_20C = 0.0147; //mPa*s
    const ld helium_20C = 0.0196; // mPa*s
    const ld hydrogen_0C = .0090; // mPa*s
    const ld mercury_20C = 0.0450; // mPa*s
    const ld oxygen_20C = .0203; // mPa*s
    const ld steam_100C = .0130; // mPa*s
    const ld water_0C = 1.792; // mPa*s
    const ld water_20C = 1.002; // mPa*s
    const ld water_37C = 0.6947; // mPa*s
    const ld water_40C = 0.653; // mPa*s
    const ld water_100C = 0.282; // mPa*s
    const ld wholeBlood_20C = 3.015; // mPa*s
    const ld wholeBlood_37C = 2.084; // mPa*s
    const ld bloodPlasma_20C = 1.810; // mPa*s
    const ld bloodPlasma_37C = 1.257; // mPa*s
    const ld ethylAlcohol_20C = 1.20; // mPa*s
    const ld methanol_20C = 0.584; // mPa*s
    const ld oil_heavyMachine_20C = 660.0; // mPa*s
    const ld oil_motorSAE10_30C = 200.0; // mPa*s
    const ld oil_olive_20C = 138.0; // mPa*s
    const ld glycerin_20C = 1500; // mPa*s
    ld honey_20C = 2000; // mPa*s
    /// <summary>
/// Sets the honey_20C viscosity which can be between 2000 and 10000.
/// </summary>
/// <param name="n">The argument.</param>
    void setHoney(ld n)
    {
        if(n >=2000 && n <= 10000)
        {
            honey_20C = n;
        }
        else
            honey_20C = 2000;

    }
    ld mapleSyrup_20C = 2000; //mPa*s
    /// <summary>
    /// Sets the maple syrup between 2000 and 3000.
    /// </summary>
    /// <param name="n">The n.</param>
    void setMapleSyrup(ld n)
    {
        if (n >= 2000 && n <= 3000)
        {
            mapleSyrup_20C = n;
        }
        else
            mapleSyrup_20C = 2000;
    }
    const ld milk_20C = 3.0; // //mPa*s
    const ld oil_corn_20C = 65.0; //mPa*s
}viscosity_coefficients;

static struct DiffusionConstants
{
    const ld HYDROGEN_AIR = 6.4 * pow(10.0, -5.0); // .000064
    const ld OXYGEN_AIR = 1.8 * pow(10.0, -5.0); //.000018
    const ld OXYGEN_WATER = 1.0 * pow(10.0, -9.0); // .000000001
    const ld GLUCOSE_WATER = 6.7 * pow(10.0, -10.0); // .00000000067
    const ld HEMOGLOBIN_WATER = 6.9 * pow(10.0, -11.0); //.000000000069
    const ld DNA_WATER = 1.3 * pow(10.0, -12.0); // .0000000000013
}diffusion_constants;

class FluidDynamics
{
private:
    static void countIncrease() { fluidDynamic_objectCount += 1; }
    static void countDecrease() { fluidDynamic_objectCount -= 1; }
public:
    FluidDynamics* _fluidDynamicPtr;

    FluidDynamics()
    {
        _fluidDynamicPtr = nullptr;
        countIncrease();
    }

    /**
     * @brief copy constructor
     */
    FluidDynamics(const FluidDynamics& t)
    {
        _fluidDynamicPtr = t._fluidDynamicPtr;
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    FluidDynamics(FluidDynamics&& t) noexcept
    {
        _fluidDynamicPtr = t._fluidDynamicPtr;
        countIncrease();
    }
    /**
     * @brief copy assignment operator
     */
    FluidDynamics& operator=(FluidDynamics&& t) noexcept
    {
        if (this != &t)
        {
            _fluidDynamicPtr = t._fluidDynamicPtr;
            countIncrease();
        }
        return *this;
    }

    static void show_objectCount() { std::cout << "\n fluid dynamic object count: "
    << fluidDynamic_objectCount << std::endl; }
    static int get_objectCount() { return fluidDynamic_objectCount; }

    /// <summary>
    /// calculates the volumes of a cylinder.
    /// </summary>
    /// <param name="radius">The radius is used to find the cross sectional area of a cylinder.</param>
    /// <param name="distance">The distance.</param>
    /// <returns>volume</returns>
    static ld volumeCylinder(const ld radius, const ld distance)
    {
        return constants::PI * (radius * radius) * distance;
    }

    /// <summary>
    /// finds the flow rate of fluid in a cylinder.
    /// </summary>
    /// <param name="radius">The radius.</param>
    /// <param name="distance">The distance.</param>
    /// <param name="time">The time.</param>
    /// <returns>flow rate (COULOMB)</returns>
    static ld flowRateCylinder_radius(const ld radius, const ld distance, const ld time)
    {
        return constants::PI * (radius * radius) * distance * time;
    }

    /// <summary>
    /// calculates the flow rate of a cylinder using the diameter.
    /// </summary>
    /// <param name="diameter">The diameter.</param>
    /// <param name="velocity">The velocity.</param>
    /// <returns></returns>
    static ld flowRateCylinder_diameter(const ld diameter, const ld velocity)
    {
        return (constants::PI * (diameter * diameter) / 4.0) * velocity;
    }

    /// <summary>
    /// calculates the flow rate.
    /// </summary>
    /// <param name="volume">The volume.</param>
    /// <param name="time">The time.</param>
    /// <returns>flow rate</returns>
    static ld flowRate(const ld volume, const ld time)
    {
        return volume / time;
    }

    /// <summary>
    /// calculates the volume of flow rate.
    /// </summary>
    /// <param name="crossSectionalArea">The cross sectional area.</param>
    /// <param name="avgVelocity">The average velocity.</param>
    /// <returns>volume flow rate</returns>
    static ld volumeFlowRate(const ld crossSectionalArea, const ld avgVelocity)
    {
        return crossSectionalArea * avgVelocity;
    }

    /// <summary>
    /// finds the average velocity.
    /// </summary>
    /// <param name="volumeFlowRate">The volume flow rate.</param>
    /// <param name="area">The area.</param>
    /// <returns>average velocity</returns>
    static ld averageVelocity(const ld volumeFlowRate, const ld area)
    {
        return volumeFlowRate / area;
    }

    /// <summary>
    /// average velocity in tube or aorta with given radius and flow.
    /// </summary>
    /// <param name="volumeFlowRate">The volume flow rate.</param>
    /// <param name="radius">The radius.</param>
    /// <returns>average velocity</returns>
    static ld averageVelocity_tubeLike(const ld volumeFlowRate, const ld radius)
    {
        return volumeFlowRate / (constants::PI * (radius * radius));
    }

    /// <summary>
    /// calculates the volume from flow rate and time
    /// </summary>
    /// <param name="flowRate">The flow rate.</param>
    /// <param name="time">The time.</param>
    /// <returns>volume</returns>
    static ld volume(const ld flowRate, const ld time)
    {
        return flowRate * time;
    }

    /// <summary>
    /// calculates the time
    /// </summary>
    /// <param name="flowRate">The flow rate.</param>
    /// <param name="volume">The volume.</param>
    /// <returns>time</returns>
    static ld time(const ld flowRate, const ld volume)
    {
        return volume / flowRate;
    }

    /// <summary>
    /// finds the velocity using the equation of continuity solved for
    /// velocity2.
    /// </summary>
    /// <param name="velocity1">The velocity of flow through the area1.</param>
    /// <param name="area1">The cross-sectional area1.</param>
    /// <param name="area2">The cross-sectional area2.</param>
    /// <returns>velocity through area2</returns>
    static ld velocity2_eqOfContinuity(const ld velocity1, const ld area1, const ld area2)
    {
        return (area1 / area2) * velocity1;
    }

    /// <summary>
    /// Flows the rate tube like.
    /// </summary>
    /// <param name="radius">The radius.</param>
    /// <param name="avgVelocity">The average velocity.</param>
    /// <returns></returns>
    static ld flowRate_tubeLike(const ld radius, const ld avgVelocity)
    {
        return constants::PI * (radius * radius) * avgVelocity;
    }

    /// <summary>
    /// calculates the total volume to flow over a period of time.
    /// </summary>
    /// <param name="radius">The radius.</param>
    /// <param name="avgVelocity">The average velocity.</param>
    /// <param name="time">The time.</param>
    /// <returns>volume total</returns>
    static ld volumeTotal(const ld radius, const ld avgVelocity, const ld time)
    {
        return constants::PI * (radius * radius) * avgVelocity * time;
    }

    /// <summary>
    /// finds the factor the velocity is reduced by branching.
    /// </summary>
    /// <param name="mainRadius">The main radius.</param>
    /// <param name="branchRadius">The branch radius.</param>
    /// <param name="branches">The number of smaller branches.</param>
    /// <returns>factor of velocity reduction</returns>
    static ld reducedVelocity_branchingArteries(const ld mainRadius, const ld branchRadius, const ld branches)
    {
        return (1.0 * mainRadius) / (branches * branchRadius);
    }

    /// <summary>
    /// Average velocity of blood flow through ad capillary.
    /// </summary>
    /// <param name="flowRate">The flow rate.</param>
    /// <param name="capillaryVessels">The capillary vessels.</param>
    /// <param name="diameterEach">The diameter each.</param>
    /// <returns>average blood flow</returns>
    static ld averageVelocityBloodFlowThroughCapillary_diameter(const ld flowRate, const ld capillaryVessels, const ld diameterEach)
    {
        return (4.0 * flowRate) / (capillaryVessels * constants::PI * (diameterEach * diameterEach));
    }

    /// <summary>
    /// Averages the velocity blood flow through capillary with the radius.
    /// </summary>
    /// <param name="flowRate">The flow rate.</param>
    /// <param name="radius">The radius.</param>
    /// <returns></returns>
    static ld averageVelocityBloodFlowThroughCapillary_radius(const ld flowRate, const ld radius)
    {
        return flowRate / (constants::PI * (radius * radius));
    }

    /// <summary>
    /// calculates the total number of capillaries.
    /// </summary>
    /// <param name="area">The area.</param>
    /// <param name="diameter">The diameter.</param>
    /// <returns>capillaries</returns>
    static ld capillaryFlowTotal_diameter(const ld area, const ld diameter)
    {
        return (4.0 * area) / (constants::PI * (diameter * diameter));
    }

    /// <summary>
    /// calculates the total number of Capillaries with the radius.
    /// </summary>
    /// <param name="flow">The flow.</param>
    /// <param name="radius">The radius.</param>
    /// <returns></returns>
    static ld capillaryFlowTotal_radius(const ld flow, const ld radius)
    {
        return flow / (constants::PI * (radius * radius));
    }

    /// <summary>
    /// calculates the total flow rate
    /// </summary>
    /// <param name="capillaries">The number of capillaries.</param>
    /// <param name="crossSectionalArea">The cross sectional area.</param>
    /// <param name="avgVelocity">The average velocity.</param>
    /// <returns>total flow rate</returns>
    static ld totalFlowRate_capillary(const ld capillaries, const ld crossSectionalArea, const ld avgVelocity)
    {
        return capillaries * crossSectionalArea * avgVelocity;
    }

    /// <summary>
    /// Calculates the air flow through a circular duct into a rectangular room.
    /// </summary>
    /// <param name="roomVolume">The rooms volume = L * W * H.</param>
    /// <param name="radiusDuct">The radius duct or r = diameter/2.</param>
    /// <param name="time">The time in seconds.</param>
    /// <returns>average speed of air flow out of duct</returns>
    static ld airFlowThroughCircularDuctIntoRectangularRoom(const ld roomVolume, const ld radiusDuct, const ld time)
    {
        return roomVolume / (constants::PI * (radiusDuct * radiusDuct) * time);
    }

    /// <summary>
    /// calculates the inside diameters of a hose nozzle.
    /// </summary>
    /// <param name="flowRate">The flow rate.</param>
    /// <param name="velocity">The velocity.</param>
    /// <returns>diameter</returns>
    static ld diameterStream(const ld flowRate, const ld velocity)
    {
        return 2.0 * sqrt((flowRate) / (constants::PI * velocity));
    }

    /// <summary>
    /// calculates the diameter that a pipe would need to be at minimum to
    /// meet the requirements for the specified values
    /// </summary>
    /// <param name="densityFluid">The density fluid.</param>
    /// <param name="flowRateFluid">The flow rate fluid.</param>
    /// <param name="viscosityFluid">The viscosity fluid.</param>
    /// <param name="reynoldsNumber">The Reynolds number.</param>
    /// <returns></returns>
    static ld diameterPipeForSpecifiedValues(const ld densityFluid,
                                             const ld flowRateFluid,
                                             const ld viscosityFluid,
                                             const ld reynoldsNumber)
    {
        return (4.0 * densityFluid * flowRateFluid) /
        (constants::PI * reynoldsNumber * viscosityFluid);
    }


    /// <summary>
    /// uses Bernoulli's equation to calculate the amount of work.
    /// </summary>
    /// <param name="mass">The mass.</param>
    /// <param name="velocityFinal">The velocity final.</param>
    /// <param name="velocityInitial">The velocity initial.</param>
    /// <returns>work new</returns>
    static ld workNet_BernoulliEquation(const ld mass, const ld velocityFinal, const ld velocityInitial = 0.0)
    {
        return (.5 * mass * (velocityFinal * velocityFinal)) - (.5 * mass * (velocityInitial * velocityInitial));
    }

    /// <summary>
    /// calculates the final Velocity using the  Bernoulli equation.
    /// </summary>
    /// <param name="velocityInitial">The velocity initial.</param>
    /// <param name="changeInHeight">Height of the change in.</param>
    /// <returns>final velocity</returns>
    static ld velocityFinal_bernoulliEquation(const ld velocityInitial, const ld changeInHeight)
    {
        return sqrt(pow(velocityInitial, 2.0) + (2.0 * constants::Ga * changeInHeight));
    }

    /**
     * @brief  speed of liquid emerging from the drain of a tank.
     * @param  height of liquid in tank
     * @return  speed of liquid
     */
    static ld speedOfLiquidEmergingFromTank(const ld height,
                                            bool print =false) {
        auto speed = sqrt(2.0 * constants::Ga * height);
        if (print) {
            std::cout << "speed of liquid emerging from tank: "
            << speed << std::endl;
        }
        return speed;
    }

    /**
     * @brief X has a nuclei density around rhoX while Y's density is rhoY.
     * Roughly what fraction of Y's volume is not empty space?
     * @param rhoX nuclei density of X
     * @param rhoY nuclei density of Y
     * @param print print results to console
     * @return fraction of Y's volume that is not empty space
     */
    static ld fractionOfYVolumeNotEmptySpace(const ld rhoX,
                                             const ld rhoY,
                                             bool print = false) {
        auto fraction = (rhoY / rhoX);
        if (print) {
            std::cout << "fraction of Y's volume that is not empty space: "
            << fraction << std::endl;
        }
        return fraction;
    }


    /// <summary>
    /// calculates the final pressure.
    /// </summary>
    /// <param name="pressureInitial">The initial pressure.</param>
    /// <param name="density">The density.</param>
    /// <param name="velocityInitial">The initial velocity</param>
    /// <param name="velocityFinal">The final velocity final.</param>
    /// <returns></returns>
    static ld pressureFinal_bernoulliEquationConstantAltitude(
            const ld pressureInitial,
            const ld density,
            const ld velocityInitial,
            const ld velocityFinal)
    {
        return pressureInitial + .5 * density *
        ((velocityInitial * velocityInitial) - (velocityFinal * velocityFinal));
    }

    /// <summary>
    /// Calculates the maximums height water from a hose can reach.
    /// </summary>
    /// <param name="velocity">The velocity.</param>
    /// <returns>height</returns>
    static ld maxHeightWaterFromHose(const ld velocity)
    {
        return (velocity * velocity) / (2.0 * constants::Ga);
    }

    /**
     * @brief  calculates the maximum height above a nozzle the water can rise?
     * (The actual height will be significantly smaller due to air resistance.)
     * @param  volumeROF volume rate of flow
     * @param  nozzleDiameter nozzle diameter (in meters)
     * @param print print to console
     * @return  max height
     */
    static ld maxHeightAboveNozzleLiquidRise(const ld volumeROF,
                                             const ld nozzleDiameter,
                                             bool print =false) {
        auto maxHeight = (8.0 * pow(volumeROF, 2.0)) /
                (pow(constants::PI, 2.0) *
                constants::Ga * pow(nozzleDiameter, 4.0));
        if (print) {
            std::cout << "max height above nozzle: "
            << maxHeight << std::endl;
        }
        return maxHeight;
    }

    /**
     * @brief venturi flowmeter guage reading
     * @param p
     * @param A_big
     * @param A_small
     * @param density
     * @param print print to console
     * @return flowrate
     */
     static ld venturiFlowSpeed(const ld p,
                                const ld A_big,
                                const ld A_small,
                                const ld density,
                                bool print =false) {
        auto ratioOfAreas = A_big / A_small;
        auto flowRate = sqrt((2.0 * p)/(density*(ratioOfAreas*ratioOfAreas-1.0)));
        if (print) {
            std::cout << "flow rate: "
            << flowRate << std::endl;

        }
        return flowRate;
     }

    /// <summary>
    /// Calculates approximately the force due to the Bernoulli effect on a roof
    /// having a specified area. F = 1/2 * p * v^2 * A
    /// </summary>
    /// <param name="density">The density of the air.</param>
    /// <param name="velocity">The velocity of the wind.</param>
    /// <param name="area">The area of the roof.</param>
    /// <returns>Force on roof</returns>
    static ld force_bernoulliEquationConstantAltitude(const ld density,
                                                      const ld velocity,
                                                      const ld area)
    {
        return .5 * density * (velocity * velocity) * area;
    }

    /// <summary>
    /// Calculate the approximate force on a area of sail, given the
    /// horizontal velocityHigh of the wind is faster and parallel to its front surface
    /// while a velocitySlow wind runs along its back surface.
    /// </summary>
    /// <param name="density">The density.</param>
    /// <param name="velocityHigh">The velocity high.</param>
    /// <param name="velocityLow">The velocity low.</param>
    /// <param name="area">The area.</param>
    /// <returns>force of wind</returns>
    static ld force_bernoulliEquationConstantAltitude(const ld density,
                                                      const ld velocityHigh,
                                                      const ld velocityLow,
                                                      const ld area)
    {
        return .5 * density * ((velocityHigh * velocityHigh) -
        (velocityLow * velocityLow)) * area;
    }

    /// <summary>
    /// calculates the pressure drop due to the Bernoulli effect as water goes into a
    /// smaller diameter nozzle from a larger diameter hose while carrying a
    /// specified volumeFlowRate.
    /// </summary>
    /// <param name="density">The density.</param>
    /// <param name="volumeRateOfFlow">The volume rate of flow.</param>
    /// <param name="diameterLarge">The larger diameter.</param>
    /// <param name="diameterSmall">The smaller diameter.</param>
    /// <returns>drop in pressure</returns>
    static ld pressureDrop_bernoulliEquationConstantAlt(const ld density,
                                                        const ld volumeRateOfFlow,
                                                        const ld diameterLarge,
                                                        const ld diameterSmall)
    {
        return (8.0 * density * (volumeRateOfFlow * volumeRateOfFlow) /
        (constants::PI * constants::PI)) * (1.0 / pow(diameterSmall, 4.0) - 1.0 /
        pow(diameterLarge, 4));
    }

    /// <summary>
    /// Fluids the speed pitot tube.
    /// </summary>
    /// <param name="meterFluidDensity">The meter fluid density.</param>
    /// <param name="heightOfFluid">The height of fluid.</param>
    /// <param name="airDensity">The air density.</param>
    /// <returns></returns>
    static ld fluidSpeed_pitotTube(const ld meterFluidDensity, const ld heightOfFluid, const ld airDensity)
    {
        return pow((2.0 * meterFluidDensity * constants::Ga * heightOfFluid) / airDensity, .5);
    }

    /// <summary>
    /// calculates the powers by multiplying Bernoulli's equation by the flow rate
    /// </summary>
    /// <param name="density">The density.</param>
    /// <param name="changeInHeight">change in Height.</param>
    /// <param name="flowRate">The flow rate.</param>
    /// <returns>Power in Watts</returns>
    static ld power_bernoulliEquation(const ld density, const ld changeInHeight, const ld flowRate)
    {
        return density * constants::Ga * changeInHeight * flowRate;
    }

    /// <summary>
    /// The left ventricle of a resting adult's heart pumps blood at a fluidFlowRate of,
    /// increasing its pressureToFluid by mm Hg, its speedChangeOfFluid in m/s, and its heightChangeOfFluid.
    /// (All numbers are averaged over the entire heartbeat.)
    /// Calculate the total power output of the left ventricle. Note that most of the power is used to increase blood pressure.
    /// </summary>
    /// <param name="pressureToFluid">The pressure to fluid.</param>
    /// <param name="fluidDensity">The fluid density.</param>
    /// <param name="speedChangeOfFluid">The speed change of fluid.</param>
    /// <param name="heightChangeOfFluid">The height change of fluid.</param>
    /// <param name="fluidFlowRate">The fluid flow rate.</param>
    /// <returns>power</returns>
    static ld power_bernoulliEquation_ventricle(const ld pressureToFluid,
                                                const ld fluidDensity,
                                                const ld speedChangeOfFluid,
                                                const ld heightChangeOfFluid,
                                                const ld fluidFlowRate)
    {
        return (pressureToFluid + (.5 * (fluidDensity * pow(speedChangeOfFluid, 2)))
        + (fluidDensity *constants::Ga * heightChangeOfFluid)) * fluidFlowRate;
    }

    /// <summary>
    /// calculates the power of a force at a certain speed
    /// </summary>
    /// <param name="force">The force.</param>
    /// <param name="velocity">The velocity.</param>
    /// <returns></returns>
    static ld power(const ld force, const ld velocity)
    {
        return force * velocity;
    }

    /// <summary>
    /// calculates the power
    /// </summary>
    /// <param name="flowRate">The flow rate.</param>
    /// <param name="power">The power.</param>
    /// <returns>power to provide flow</returns>
    static ld powerQP(const ld flowRate, const ld power)
    {
        return flowRate * power;
    }

    /// <summary>
    /// A frequently quoted rule of thumb in aircraft design is that wings should
    /// produce about 1000 N of lift per square meter of wing. (The fact that a
    /// wing has a top and bottom surface does not double its area.)
    /// At takeoff, an aircraft travels at 60.0 m/s, so that the air speed relative
    /// to the bottom of the wing is 60.0 m/s. Given the sea level density of air to be
    /// 1.29 kg/m3, how fast must it move over the upper surface to create the ideal lift?
    /// </summary>
    /// <param name="density">The density.</param>
    /// <param name="forceLiftPerSquareMeterOfWing">The force lift per square meter of wing.</param>
    /// <param name="speedUnderWing">The speed under wing.</param>
    /// <returns>wind speed over wing</returns>
    static ld speedTopOfWing_bernoulliEquation(const ld density,
                                               const ld forceLiftPerSquareMeterOfWing,
                                               const ld speedUnderWing)
    {
        return sqrt(((2.0 * forceLiftPerSquareMeterOfWing) /
        (density)) + (speedUnderWing * speedUnderWing));
    }

    /// <summary>
    /// calculates the pressure at a certain point along a sump pump.
    /// </summary>
    /// <param name="outputPressure">The pressure at pump level.</param>
    /// <param name="density">The density.</param>
    /// <param name="HeightOfPoint">The height of point.</param>
    /// <returns>pressure</returns>
    static ld sumpPumpPressureAtPoint(const ld outputPressure,
                                      const ld density,
                                      const ld HeightOfPoint)
    {
        return outputPressure + ((density * constants::Ga) * (-HeightOfPoint));
    }

    /// <summary>
    /// A pump hose goes over the foundation wall, it is a certain height from the pump and widens from diameter1 to diameter2.
    /// It can pump water from a basement at a volumeFlowRate and starts at the pump with a outputPressure. this method will
    /// calculate the pressure at the widened spot of the hose.
    /// widened part of the hose?
    /// </summary>
    /// <param name="outputPressure">The output pressure where hose leaves pump.</param>
    /// <param name="density">The density of water on average is 1000kg/m^3.</param>
    /// <param name="volumeFlowRate">The volume flow rate.</param>
    /// <param name="diameter1">The diameter of the hose at start.</param>
    /// <param name="diameter2">The diameter the hose changes to.</param>
    /// <param name="height">The height.</param>
    /// <returns>pressure in hose</returns>
    static ld sumpPumpPressureChangeInPipeDiameter(const ld outputPressure,
                                                   const ld density,
                                                   const ld volumeFlowRate,
                                                   const ld diameter1,
                                                   const ld diameter2,
                                                   const ld height)
    {
        return (outputPressure + ((8.0 * density * (volumeFlowRate * volumeFlowRate)) /
        (constants::PI * constants::PI)) * ((1.0 / pow(diameter1, 4) -
        (1.0 / pow(diameter2, 4))))) + (density * constants::Ga * -height);
    }

    /// <summary>
    ///  Calculates the retarding force due to the viscosity of the air layer between a cart and
    ///  a level air track given the following information
    ///  — air temperature,
    ///  — the carts velocity,
    ///  — its surface area,
    ///  — the thickness of the air layer
    /// </summary>
    /// <param name="viscosity">The viscosity.</param>
    /// <param name="velocity">The velocity.</param>
    /// <param name="crossSectionalArea">The cross sectional area.</param>
    /// <param name="layerThickness">The layer thickness.</param>
    /// <returns>retarding force</returns>
    static ld retardingForce_airLayer(const ld viscosity,
                                      const ld velocity,
                                      const ld crossSectionalArea,
                                      const ld layerThickness)
    {
        return viscosity * (velocity * crossSectionalArea) / (layerThickness);
    }

    /// <summary>
    /// finds the coefficient of viscosity of a fluid.
    /// </summary>
    /// <param name="force">The force.</param>
    /// <param name="layerLength">Length of the layer.</param>
    /// <param name="velocity">The velocity.</param>
    /// <param name="crossSectionalArea">The cross sectional area.</param>
    /// <returns>viscosity coefficient</returns>
    static ld viscosityCoefficient(const ld force, const ld layerLength,
                                   const ld velocity, const ld crossSectionalArea)
    {
        return (force * layerLength) / (velocity * crossSectionalArea);
    }

    /// <summary>
    /// calculates the viscosity of fluid in a pipe with laminar flow using
    /// Perseus law for laminar flow solved for viscosity
    /// </summary>
    /// <param name="radiusPipe">The radius of the pipe.</param>
    /// <param name="resistance">The resistance.</param>
    /// <param name="lengthOfPipe">The length of pipe.</param>
    /// <returns>viscosity</returns>
    static ld viscosity_laminarFlowPerseusLaw(const ld radiusPipe,
                                              const ld resistance,
                                              const ld lengthOfPipe)
    {
        return (constants::PI * pow(radiusPipe, 4.0) * resistance) /
        (8.0 * lengthOfPipe);
    }

    /// <summary>
    /// calculates the flow rate between two pressures
    /// </summary>
    /// <param name="pressure1">The pressure1.</param>
    /// <param name="pressure2">The pressure2.</param>
    /// <param name="resistance">The resistance.</param>
    /// <returns>flow rate</returns>
    static ld pressureDifferentialFlowRate(const ld pressure1,
                                           const ld pressure2,
                                           const ld resistance)
    {
        return (pressure2 - pressure1) / resistance;
    }

    /// <summary>
    /// calculates the resistance using pressure change and flow rate
    /// </summary>
    /// <param name="pressureStart">The pressure start.</param>
    /// <param name="pressureEnd">The pressure end.</param>
    /// <param name="flowRate">The flow rate.</param>
    /// <returns>resistance</returns>
    static ld resistance(const ld pressureStart,
                         const ld pressureEnd,
                         const ld flowRate)
    {
        return (pressureStart - pressureEnd) / flowRate;
    }

    /// <summary>
    /// calculates the resistances using Poiseuille's law.
    /// </summary>
    /// <param name="viscosityCoef">The viscosity coef.</param>
    /// <param name="lengthOfTube">The length of tube.</param>
    /// <param name="radiusOfTube">The radius of tube.</param>
    /// <returns></returns>
    static ld resistance_poiseuilleLawFor(const ld viscosityCoef,
                                          const ld lengthOfTube,
                                          const ld radiusOfTube)
    {
        return (8.0 * viscosityCoef * lengthOfTube) /
        (constants::PI * pow(radiusOfTube, 4.0));
    }

    /// <summary>
    /// calculates the flow rate using Poiseuille's law for laminar flow
    /// </summary>
    /// <param name="pressure1">pressure 1.</param>
    /// <param name="pressure2">pressure 2.</param>
    /// <param name="radiusOfTube">The radius of tube.</param>
    /// <param name="viscosity">The viscosity of the fluid in tube.</param>
    /// <param name="lengthOfTube">The length of tube.</param>
    /// <returns>flow rate</returns>
    static ld laminarFlow_poiseuilleLawFor(const ld pressure1,
                                           const ld pressure2,
                                           const ld radiusOfTube,
                                           const ld viscosity,
                                           const ld lengthOfTube)
    {
        return ((pressure2 - pressure1) * constants::PI * pow(radiusOfTube, 4.0)) / (8.0 * viscosity * lengthOfTube);
    }

    /// <summary>
    /// calculates the pressures to produce a specified flow rate assuming laminar flow.
    /// </summary>
    /// <param name="supplyFlowRate">The supply flow rate.</param>
    /// <param name="lengthTube">The length tube.</param>
    /// <param name="radiusTube">The radius tube.</param>
    /// <param name="viscosity">The viscosity.</param>
    /// <param name="gaugePressurePoint1">The gauge pressure point 1.</param>
    /// <returns>pressure point 2</returns>
    static ld pressureToProduceFlowRate_laminarFLow(const ld supplyFlowRate,
                                                    const ld lengthTube,
                                                    const ld radiusTube,
                                                    const ld viscosity,
                                                    const ld gaugePressurePoint1)
    {
        return ((8.0 * viscosity * lengthTube) /
        (constants::PI * pow(radiusTube, 4.0))) *
        supplyFlowRate + gaugePressurePoint1;
    }

    /// <summary>
    /// calculates the Reynolds Number(NR) for the flow in a tube.\n
    /// if NR <= 2000 than flow is laminar.\n
    /// if NR > 2000 && NR <= 3000 than flow is unstable.\n
    /// if NR > 3000 flow is turbulent.
    /// </summary>
    /// <param name="fluidDensity">The fluid density.</param>
    /// <param name="fluidSpeed">The fluid speed.</param>
    /// <param name="viscosity">The viscosity.</param>
    /// <param name="tubeRadius">The tube radius.</param>
    /// <returns>Reynolds Number, flow in a tube</returns>
    static ld reynoldsNumber_flowInHorizontalTube(const ld fluidDensity,
                                                  const ld fluidSpeed,
                                                  const ld viscosity,
                                                  const ld tubeRadius)
    {
        return (2.0 * fluidDensity * fluidSpeed * tubeRadius) / viscosity;
    }

    /// <summary>
    /// calculates the Reynolds number using flowrate solved for velocity subbed into the equation.
    /// </summary>
    /// <param name="density">The density.</param>
    /// <param name="flowRate">The flow rate.</param>
    /// <param name="radius">The radius.</param>
    /// <param name="viscosity">The viscosity.</param>
    /// <returns>Reynolds number</returns>
    static ld reynoldsNumber_usingFlowRate(const ld density,
                                           const ld flowRate,
                                           const ld radius,
                                           const ld viscosity)
    {
        return (2.0 * density * flowRate) / (constants::PI * radius * viscosity);
    }

    /// <summary>
    /// calculates the Reynolds Number(NR) for the flow in a vertical tube.\n
    /// if NR <= 2000 than flow is laminar.\n
    /// if NR > 2000 && NR <= 3000 than flow is unstable.\n
    /// if NR > 3000 flow is turbulent.
    /// </summary>
    /// <param name="fluidDensity">The fluid density.</param>
    /// <param name="height">The fluid height.</param>
    /// <param name="viscosity">The viscosity.</param>
    /// <param name="tubeRadius">The tube radius.</param>
    /// <returns>Reynolds Number, flow in a tube</returns>
    static ld reynoldsNumber_flowInVerticalTube(const ld fluidDensity,
                                                const ld height,
                                                const ld viscosity,
                                                const ld tubeRadius)
    {
        return (2.0 * fluidDensity * (sqrt(2.0*constants::Ga*height)) * tubeRadius) / viscosity;
    }

    /// <summary>
    /// calculates the Reynolds Number(NR) for a object in fluid
    /// if NR <= 1 than flow around object can be laminar.\n
    /// if NR > 1 && NR < 10 than flow is in transition to turbulent flow.\n
    /// if NR > 10 && NR <= 10^6 than either laminar or turbulent or may oscillate between the two.\n
    /// if NR > 10^6 than flow is entirely turbulent.
    /// </summary>
    /// <param name="fluidDensity">The fluid density.</param>
    /// <param name="viscosity">The viscosity of fluid.</param>
    /// <param name="objectSpeed">The objects speed.</param>
    /// <param name="objectLength">Length of the object; a spheres diameter for example.</param>
    /// <returns>Reynolds Number, object in fluid</returns>
    static ld reynoldsNumber_objectInFluid(const ld fluidDensity,
                                           const ld viscosity,
                                           const ld objectSpeed,
                                           const ld objectLength)
    {
        return (fluidDensity * objectSpeed * objectLength) / viscosity;
    }

    /// <summary>
    /// calculates the viscous drag of a small sphere
    /// </summary>
    /// <param name="radius">The radius.</param>
    /// <param name="viscosity">The viscosity.</param>
    /// <param name="velocity">The velocity.</param>
    /// <returns></returns>
    static ld viscous_drag_sphereSM(const ld radius, const ld viscosity, const ld velocity)
    {
        return 6.0 * constants::PI * radius * viscosity * velocity;
    }

    /// <summary>
    /// calculates the net force from the change in pressure and the area of the cross sectional
    /// </summary>
    /// <param name="pressureChange">The pressure change.</param>
    /// <param name="crossSectionalArea">The cross sectional area.</param>
    /// <returns>net force</returns>
    static ld forceNetFromPressureDifference(const ld pressureChange, const ld crossSectionalArea)
    {
        return pressureChange * crossSectionalArea;
    }

    /// <summary>
    /// calculates the pressure change.
    /// </summary>
    /// <param name="pressureStart">The start pressure.</param>
    /// <param name="pressureEnd">The end pressure.</param>
    /// <returns>difference in pressure</returns>
    static ld pressureChange(const ld pressureStart, const ld pressureEnd)
    {
        return pressureEnd - pressureStart;
    }

    /// <summary>
    /// calculates the pressure being supplied with the change in flow rate
    /// </summary>
    /// <param name="startingPressure">The starting pressure.</param>
    /// <param name="startingFlowRate">The starting flow rate.</param>
    /// <param name="changedFlowRate">The changed flow rate.</param>
    /// <returns>the pressure related to the changed flow rate</returns>
    static ld changedPressure_byFlowRateChange_withConstantResistance(
            const ld startingPressure,
            const ld startingFlowRate,
            const ld changedFlowRate)
    {
        return (startingPressure * changedFlowRate) / startingFlowRate;
    }

    /// <summary>
    /// Pressures the difference factor by decreased radius.
    /// </summary>
    /// <param name="percentChange">The percent change.</param>
    /// <returns></returns>
    static ld pressureDifferenceFactor_byChangedRadius(const ld percentChange)
    {
        return 1.0 / (pow(percentChange / 100.0, 4.0));
    }

    /// <summary>
    /// calculates the percent change in the radius when there is a certain percent
    /// change in laminar flow in a tube.
    /// </summary>
    /// <param name="percentChangeInLaminarFlow">The percent change in laminar flow.</param>
    /// <returns></returns>
    static ld radiusChangePercent_byPercentChangeInLaminarFlowInTube(const ld percentChangeInLaminarFlow)
    {
        return (1.0 - pow(1.0 - (percentChangeInLaminarFlow / 100.0), 1.0/4.0)) * 100;
    }

    /// <summary>
    /// calculates the terminals velocity of a falling spherical particle in fluid.
    /// </summary>
    /// <param name="radius">The radius.</param>
    /// <param name="viscosity">The viscosity of fluid.</param>
    /// <param name="densitySphere">The density of the sphere.</param>
    /// <param name="densityFluid">The density of the fluid.</param>
    /// <returns>velocity at terminal speed</returns>
    static ld terminalSpeed_sphericalParticleFallingInFluid(
            const ld radius,
            const ld viscosity,
            const ld densitySphere,
            const ld densityFluid)
    {
        return ((2.0 * pow(radius, 2.0) * constants::Ga) / (9.0 * viscosity)) * (densitySphere - densityFluid);
    }

    /// <summary>
    /// Calculates the viscosity of a spherical particle falling in fluid.
    /// </summary>
    /// <param name="radius">The radius.</param>
    /// <param name="velocity">The velocity.</param>
    /// <param name="densitySphere">The density sphere.</param>
    /// <param name="densityFluid">The density fluid.</param>
    /// <returns>viscosity</returns>
    static ld viscosity_sphericalParticleFallingInFluid(const ld radius,
                                                        const ld velocity,
                                                        const ld densitySphere,
                                                        const ld densityFluid)
    {
        return ((2.0 * pow(radius, 2.0) * constants::Ga) / (9.0 * velocity)) *
        (densitySphere - densityFluid);
    }

    /// <summary>
    /// calculates the terminal velocity.
    /// </summary>
    /// <param name="mass">The mass of falling object.</param>
    /// <param name="crossSectionalArea">The cross sectional area facing the drag force.</param>
    /// <param name="density">The density of the fluid or air.</param>
    /// <returns>terminal velocity</returns>
    static ld terminalVelocity(const ld mass, const ld crossSectionalArea, const ld density)
    {
        return sqrt((2.0 * mass * constants::Ga) / (density * crossSectionalArea));
    }

    /// <summary>
    /// calculates the gauge pressure at end to vertical pipe shooting fluid up in air.
    /// </summary>
    /// <param name="fluidHeight">Height of the fluid.</param>
    /// <param name="viscosity">The viscosity.</param>
    /// <param name="lengthOfPipe">The length of pipe.</param>
    /// <param name="pipeRadius">The pipe radius.</param>
    /// <returns>gauge pressure</returns>
    static ld gaugePressure_atEntranceToVerticalPipeShootingFluid(
            const ld fluidHeight,
            const ld viscosity,
            const ld lengthOfPipe,
            const ld pipeRadius)
    {
        return (8.0 * sqrt((2.0 * constants::Ga * fluidHeight) * viscosity * lengthOfPipe)) / pipeRadius;
    }

    /// <summary>
    /// calculates the gauge pressure caused by gravity and fluid in a vertical pipe. 90 degrees up
    /// </summary>
    /// <param name="viscosity">The viscosity.</param>
    /// <param name="lengthOfPipe">The length of pipe.</param>
    /// <returns></returns>
    static ld gaugePressureByFluidInVerticalPipe(const ld viscosity, const ld lengthOfPipe)
    {
        return viscosity * constants::Ga * lengthOfPipe;
    }

    /// <summary>
    /// Calculates the critical flow rate
    /// </summary>
    /// <param name="radius">The radius.</param>
    /// <param name="viscosity">The viscosity.</param>
    /// <param name="reynoldsNumber">The Reynolds number.</param>
    /// <param name="density">The density.</param>
    /// <returns>flow rate</returns>
    static ld criticalFLowRate(const ld radius,
                               const ld viscosity,
                               const ld reynoldsNumber,
                               const ld density)
    {
        return (constants::PI * radius * reynoldsNumber) / (2.0 * density);
    }

    /// <summary>
    /// calculates the Roots  mean square distance.
    /// </summary>
    /// <param name="diffusionConstant">The diffusion constant.</param>
    /// <param name="time">The time.</param>
    /// <returns>root mean square</returns>
    static ld rootMeanSquareDistance(const ld diffusionConstant, const ld time)
    {
        return sqrt(2.0 * diffusionConstant * time);
    }

    /// <summary>
    /// calculates the supply pressure of a hose laying horizontal
    /// </summary>
    /// <param name="viscosity">The viscosity.</param>
    /// <param name="lengthHose">The length hose.</param>
    /// <param name="volumeFlowRate">The volume flow rate.</param>
    /// <param name="radius">The radius.</param>
    /// <param name="pressureAir">The pressure.</param>
    /// <returns>pressure supplied by faucet</returns>
    static ld pressureHoseHorizontal_poiseuilleLlawWithFlowRate(
            const ld viscosity,
            const ld  lengthHose,
            const ld volumeFlowRate,
            const ld radius,
            const ld pressureAir)
    {
        return ((8.0 * viscosity * lengthHose * volumeFlowRate) /
        (constants::PI * radius)) + pressureAir;
    }

    /// <summary>
    /// Calculates the average time using the root mean square  and the diffusion constant
    /// </summary>
    /// <param name="diffusionConstant">The diffusion constant.</param>
    /// <param name="averageDistanceRMS">The average distance RMS.</param>
    /// <returns>time in seconds</returns>
    static ld time_rms(const ld diffusionConstant, const ld averageDistanceRMS)
    {
        return pow(averageDistanceRMS, 2) / (2.0 * diffusionConstant);
    }

    /// <summary>
    /// calculates the time it takes a particle to diffuse through a certain volume and area
    /// </summary>
    /// <param name="volume">The volume.</param>
    /// <param name="area">The area.</param>
    /// <param name="diffusionConstant">The diffusion constant.</param>
    /// <returns>time in seconds</returns>
    static ld time_diffusion(const ld volume, const ld area, const ld diffusionConstant)
    {
        return (volume * volume) / (2.0 * diffusionConstant * (area * area));
    }
    /**
     * calculats the  weight of a column of air
     * @param pascals  pressure of the air
     * @param A  the section of the column
     * @param print if true prints the results
     */
    static ld weightOfColumnOfAir(ld pascals, ld A, bool print = false) {
        auto weight = pascals * A;
        if (print) {
            std::cout << "The weight of the column of air is " << weight
            << " kg" << std::endl;
        }
        return weight;
    }

    ~FluidDynamics()
    {
        delete _fluidDynamicPtr;
    }


};
#endif //PHYSICSFORMULA_FLUIDDYNAMICS_H
