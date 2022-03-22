//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_WAVES_H
#define PHYSICSFORMULA_WAVES_H
#define GA 9.81 // gravitational acceleration in m/s^2
#include <iostream>
#include "Elasticity.h"
#include "Energy.h"
#include "FluidDynamics.h"
//α=224,ß=225,π=227,Σ=228,σ=229,µ=230,τ=231,Φ=232,Θ=233
//Ω=234,δ=235,∞=236,φ=237,ε=238,∩=239,≡=240,Γ=226,γ, σ, ϑ, Å, Ώ, λ, γ
/**
 * @class Waves
 * @details class of static methods that relate to chapter 16 of the open-stax
 * college physics text book.
 * @author Ryan Zurrin
 * dateBuilt  12/20/2020
 * lastEdit 12/26/2020
 */

static int waves_objectCount = 0;

/// <summary>
/// Quadratics equation.
/// </summary>
/// <param name="a">a.</param>
/// <param name="b">b.</param>
/// <param name="c">c.</param>
/// <returns>vector with the two results from calculation</returns>
static vector<ld> quadraticEquation(const ld a, const ld b, const ld c)
{
    vector<ld> result = { 0.0, 0.0 };
    result[0] = (-b - sqrt((b * b) - 4.0 * a * c)) / (2.0 * a);
    result[1] = (-b + sqrt((b * b) - 4.0 * a * c)) / (2.0 * a);
    return result;
}
/// <summary>
/// Quadratic equation only plus.
/// </summary>
/// <param name="a">a.</param>
/// <param name="b">b.</param>
/// <param name="c">c.</param>
/// <returns>answer to the plus calculation of quadratic</returns>
static ld quadraticEquation_Plus(const ld a, const ld b, const ld c)
{
    return (-b + sqrt((b * b) - 4.0 * a * c)) / (2.0 * a);
}
/// <summary>
/// Quadratic equation only minus.
/// </summary>
/// <param name="a">a.</param>
/// <param name="b">b.</param>
/// <param name="c">c.</param>
/// <returns>answer to minus calculation of quadratic</returns>
static ld quadraticEquation_minus(const ld a, const ld b, const ld c)
{
    return (-b - sqrt((b * b) - 4.0 * a * c)) / (2.0 * a);
}

class Waves :
        public Elasticity, Energy
{
private:
    static void countIncrease() { waves_objectCount += 1; }
    static void countDecrease() { waves_objectCount -= 1; }
public:
    Waves* _wavePtr;
    /**
     * @brief no argument constructor initiates the _wavePtr to nullptr
     */
    Waves()
    {
        _wavePtr = nullptr;
        countIncrease();
    }

    /**
     * @brief copy constructor
     */
    Waves(const Waves& t)
    {
        _wavePtr = t._wavePtr;
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    Waves(Waves&& t) noexcept
    {
        _wavePtr = t._wavePtr;
        countIncrease();
    }
    /**
     * @brief copy assignment operator
     */
    Waves& operator=(const Waves& t)
    {
        if (this != &t)
        {
            _wavePtr = t._wavePtr;
            countIncrease();
        }
        return *this;
    }

    static void show_objectCount() { std::cout << "\n waves object count: "
                                               << waves_objectCount << std::endl; }
    static int get_objectCount() { return waves_objectCount; }


    /// <summary>
    /// calculates the energy stored in a deformed system that obey's
    /// Hook's law.\n PE_elastic = .5 * (k * pow(x, 2))
    /// </summary>
    /// <param name="k">The force constant.</param>
    /// <param name="x">The displacement from equilibrium.</param>
    /// <returns>PE, stored potential energy</returns>
    static ld potentialEnergy_Elastic(const ld k, const ld x)
    {
        return .5 * (k * pow(x, 2));
    }

    /// <summary>
    /// Calculates the applied force on a system obeying hooks law.\n F_app =  k * x
    /// </summary>
    /// <param name="k">The force constant.</param>
    /// <param name="x">The total displacement from the equilibrium.</param>
    /// <returns>Force, applied</returns>
    static ld forceCompressSpring_hooksLaw(const ld k, const ld x)
    {
        return k * x;
    }

    /// <summary>
    /// calculates the restoring force.\n F_res = -k * x
    /// </summary>
    /// <param name="k">The force constant.</param>
    /// <param name="x">The total displacement from equilibrium.</param>
    /// <returns>Force, restoring</returns>
    static ld forceRestoreSpring_hooksLaw(const ld k, const ld x)
    {
        return -k * x;
    }

    /// <summary>
    /// finds the length of a spring when at equilibrium
    /// \n L = abs (((m * GA) + (k * l)) / k);
    /// </summary>
    /// <param name="k">The spring constant.</param>
    /// <param name="m">The mass.</param>
    /// <param name="l">The length.</param>
    /// <returns>length of spring at equilibrium</returns>
    static ld equilibriumLength(const ld k, const ld m, const ld l)
    {
        return abs (((m * GA) + (k * l)) / k);
    }

    /// <summary>
    /// Calculates the spring force constant (k).
    /// </summary>
    /// <param name="F">The force being applied in newtons.\n
    /// if you use F = ma, where a = 9.8m/s^2 due to gravity then be sure
    /// to get total before or run full F=ma function as argument.</param>
    /// <param name="x">The displacement from equilibrium position.</param>
    /// <returns>force constant, k</returns>
    static ld springConstant_hooksLaw(const ld F, const ld x)
    {
        return -(F / x);
    }

    /// <summary>
    /// Calculates the spring force constant (k) using the relationship of
    /// KE = PE, 1/2mv^2 = 1/2kx^2, multiply both sides by 2/x^2 to end up with
    /// spring constant k = mv^2/x^2
    /// </summary>
    /// <param name="m">The mass.</param>
    /// <param name="v">The velocity.</param>
    /// <param name="x">The total compression distance.</param>
    /// <returns>spring constant (k)</returns>
    static ld springConstant_velocity(const ld m, const ld v, const ld x)
    {
        return (m * (v * v)) / (x * x);
    }

    /// <summary>
    /// calculates the spring constant from two masses and two lengths
    /// </summary>
    /// <param name="m1">The mass of weight 1.</param>
    /// <param name="l1">The length weight 1 distorts spring.</param>
    /// <param name="m2">The mass of weight 2.</param>
    /// <param name="l2">The length weight 2 distorts the spring.</param>
    /// <returns>spring constant (k)</returns>
    static ld springConstant_2masses(const ld m1, const ld l1, const ld m2, const ld l2)
    {
        return (_Ga_ * (m2 - m1)) / (l1 - l2);
    }

    /// <summary>
    /// Calculates the spring constant of object moving in simple
    /// harmonic motion.\n k = (4.0 * (Pi_ * Pi_) * m) / (T * T)
    /// </summary>
    /// <param name="m">The mass in kg.</param>
    /// <param name="T">The period T.</param>
    /// <returns>spring constant (k)</returns>
    static ld springConstant_harmonicMotion(const ld m, const ld T)
    {
        return (4.0 * (Pi_ * Pi_) * m) / (T * T);
    }

    /// <summary>
    /// calculates the spring constant using mass.
    /// </summary>
    /// <param name="m">The mass.</param>
    /// <param name="x">The distance spring compressed.</param>
    /// <returns>spring constant (k)</returns>
    static ld springConstant_HangingMass(const ld m, const ld x)
    {
        return (-m * GA) / -x;
    }

    /// <summary>
    /// calculates the spring constant for each spring in a system of springs
    /// </summary>
    /// <param name="k">The spring constant total.</param>
    /// <param name="numSprings">The total springs.</param>
    /// <returns>spring constant each spring</returns>
    static ld springConstant_forEachSpring(const ld k, const ld numSprings)
    {
        return k / numSprings;
    }

    /// <summary>
    /// calculates teh mass of an object hanging vertically from a spring with
    /// a know spring constant.
    /// </summary>
    /// <param name="k">The spring constant.</param>
    /// <param name="x">The displacement from equilibrium.</param>
    /// <param name="acl">The acceleration, default is GA(9.8m/s^2).</param>
    /// <returns>mass in kg</returns>
    static ld mass(const ld k, const ld x, const ld acl = GA)
    {
        return (-k * x) / acl;
    }

    /// <summary>
    /// Calculates the Mass the of a pendulum.
    /// </summary>
    /// <param name="T">The period T.</param>
    /// <param name="k">The spring force constant.</param>
    /// <returns>mass of the pendulum</returns>
    static ld massOfPendulum(const ld T, const ld k)
    {
        return ((T * T) * k) / (4.0 * (Pi_ * Pi_));
    }

    /// <summary>
    /// calculates the distance the marks are apart at a given mass interval.
    /// </summary>
    /// <param name="k">The spring constant.</param>
    /// <param name="m">The mass.</param>
    /// <param name="g">The acceleration from gravity, default GA(9.8).</param>
    /// <returns>distance m</returns>
    static ld depressionDistanceMarksApart(const ld k, const ld m, const ld g = GA)
    {
        return (-m * g) / k;
    }

    /// <summary>
    /// calculates the projectile speed of a spring loaded gun.
    /// </summary>
    /// <param name="PEel">The elastic Potential Energy (J).</param>
    /// <param name="m">The mass of projectile (kg).</param>
    /// <returns>speed in m/s,converted from equivalent (J/kg)^.5</returns>
    static ld projectileSpeedSpringLoadedGun(const ld PEel, const ld m)
    {
        return pow((2.0 * PEel) / m, 1 / 2);
    }

    /// <summary>
    /// calculates the frequency for periodic motion which is the number
    /// of oscillation per unit time.
    /// </summary>
    /// <param name="T">The period T.</param>
    /// <returns>Frequency (Hz); 1 cycle per sec; 1/s</returns>
    static ld frequency(const ld T)
    {
        return 1.0 / T;
    }

    /// <summary>
    /// calculates the frequencies of a simple harmonic oscillator.
    /// </summary>
    /// <param name="m">The mass in kg.</param>
    /// <param name="k">The force constant.</param>
    /// <returns>frequency (Hz)</returns>
    static ld frequency_simpleHarmonicOscillator(const ld m, const ld k)
    {
        return (1.0 / (2.0 * Pi_)) * sqrt(k / m);
    }

    /// <summary>
    /// calculates teh period T from the know frequency.
    /// </summary>
    /// <param name="f">The frequency in Hz.</param>
    /// <returns>time per period</returns>
    static ld period(const ld f)
    {
        return 1.0 / f;
    }

    /// <summary>
    /// Calculates the period of a object moving in simple harmonic motion.
    /// </summary>
    /// <param name="m">The mass.</param>
    /// <param name="k">The spring constant.</param>
    /// <returns>period T</returns>
    static ld period_simpleHarmonicOscillator(const ld m, const ld k)
    {
        return (2.0 * Pi_) * sqrt(m / k);
    }

    /// <summary>
    /// Calculates the displacements as a function of time(t).
    /// </summary>
    /// <param name="X">The Amplitude.</param>
    /// <param name="t">The total time.</param>
    /// <param name="T">The period T of the oscillation.</param>
    /// <returns>displacement</returns>
    static ld displacement_functionOfTime(const ld X, const ld t, const ld T)
    {
        return X * cos(((2.0 * Pi_ * t) / T) * RADIAN);
    }

    /// <summary>
    /// When the block passes through the equilibrium position, all of the
    /// spring's potential is now kinetic energy of the block. This may be
    /// written as
    /// kxi^2/2 = mv^2/2
    /// </summary>
    /// <param name="k">The spring constant.</param>
    /// <param name="m">The mass.</param>
    /// <param name="x">The distance of compression or stretch from equilibrium.</param>
    /// <returns>velocity of a oscillator wave</returns>
    static ld speedThroughEquilibrium_oscillatingMass(const ld k, const ld m, const ld x)
    {
        return (pow(k/m,.5) * x);
    }

    /// <summary>
    /// Calculates the velocities of a oscillator.
    /// </summary>
    /// <param name="vMax">The vMax.</param>
    /// <param name="x">The x.</param>
    /// <param name="X">The .</param>
    /// <returns>velocity of a oscillator wave</returns>
    static ld velocity_oscillator(const ld vMax, const ld x, const ld X)
    {
        return vMax * sqrt(1.0 - ((x * x) / (X * X)));
    }

    /// <summary>
    /// Calculates the velocity as a function of time.
    /// </summary>
    /// <param name="vMax">The v maximum is a function of Amplitude and
    /// period T.</param>
    /// <param name="t">The total time.</param>
    /// <param name="T">The period T.</param>
    /// <returns>velocity</returns>
    static ld velocity_functionOfTime(const ld vMax, const ld t, const ld T)
    {
        return -vMax * sin(((2.0 * Pi_ * t) / T) * RADIAN);
    }

    static ld velocity_T(const ld waveLength, const ld T)
    {
        return waveLength / T;
    }

    static ld velocity_f(const ld waveLength, const ld f)
    {
        return waveLength * f;
    }

    /// <summary>
    /// calculates the velocity max.
    /// </summary>
    /// <param name="A">the amplitude</param>
    /// <param name="k">The spring constant.</param>
    /// <param name="m">The mass.</param>
    /// <returns></returns>
    static ld vMax(const ld A, const ld k, const ld m)
    {
        return sqrt((k / m)) * A;
    }

    /// <summary>
    /// calculates the velocity max using amplitude and period.
    /// </summary>
    /// <param name="A">a.</param>
    /// <param name="T">The t.</param>
    /// <returns></returns>
    static ld vMax(const ld A, const ld T)
    {
        return (2.0 * Pi_ * A) / T;
    }

    /// <summary>
    /// Calculates the velocities of a vibrating string.
    /// </summary>
    /// <param name="F">The force.</param>
    /// <param name="m">The mass.</param>
    /// <param name="L">The length.</param>
    /// <returns>speed of vibrating string</returns>
    static ld velocityString(const ld F, const ld m, const ld L)
    {
        return sqrt(F / (m / L));
    }

    /// <summary>
    /// calculates the velocities of a pendulum.
    /// </summary>
    /// <param name="wMax">The  maximum.</param>
    /// <param name="L">The l.</param>
    /// <param name="thetaMax">The theta maximum.</param>
    /// <returns></returns>
    static ld velocity_pendulum(const ld wMax, const ld L, const ld thetaMax)
    {
        return sqrt((_Ga_) / (L)) * thetaMax;
    }

    /// <summary>
    /// Calculates the acceleration as a function of time.
    /// </summary>
    /// <param name="k">The force constant.</param>
    /// <param name="X">The amplitude.</param>
    /// <param name="m">The mass.</param>
    /// <param name="t">The time.</param>
    /// <param name="T">The period T.</param>
    /// <returns>acceleration</returns>
    static ld acceleration_functionOfTime
            (const ld k, const ld X, const ld m, const ld t, const ld T)
    {
        return -((k * X) / m) * cos(((2.0 * Pi_ * t) / T) * RADIAN);
    }

    /// <summary>
    /// Calculates the speed of a engine.
    /// </summary>
    /// <param name="se__r">sound every ___ revolutions of engine.</param>
    /// <param name="freqHz">The freq hz, or pops per second sound.</param>
    /// <param name="revPerK">The revolutions per kilometer.</param>
    /// <param name="cylinders">how many cylinders are making sounds per
    /// every se__r.</param>
    /// <returns>speed of car in km/s</returns>
    static ld speedOfEngine(const ld se__r, const ld freqHz, const ld revPerK, const ld cylinders)
    {
        return (1.0 / revPerK)
               * (freqHz / 1.0)
               * (se__r / 1.0)
               * (1.0 / cylinders);
    }

    /// <summary>
    /// calculates the mass to add to a spring to change from one period T1
    /// to period T2.\n m2 = m1 * (pow(T2 / T1, 2.0) - 1.0)
    /// </summary>
    /// <param name="m1">The initial mass.</param>
    /// <param name="T1">The initial period T.</param>
    /// <param name="T2">The new period we are calculating the mass for</param>
    /// <returns>The add mass to the spring</returns>
    static ld massToAddToSpringToChangePeriod(const ld m1, const ld T1, const ld T2)
    {
        return m1 * (pow(T2 / T1, 2.0) - 1.0);
    }

    /// <summary>
    /// Calculates by how much leeway there would be in the selection of
    /// the masses added to a spring oscillating if you did not wish the new
    /// period to be greater than Tu in s or less than Tl in s.
    /// \n massLeeway = (m1 / (T1 * T1)) * ((Tu * Tu) - (Tl * Tl))
    /// </summary>
    /// <param name="m1">The mass initially.</param>
    /// <param name="T1">The period T initially.</param>
    /// <param name="Tu">The period T upper limit.</param>
    /// <param name="Tl">The period T lower limit.</param>
    /// <returns>the leeway in mass to keep within limits</returns>
    static ld differenceBetweenUpperLowerMasses(const ld m1, const ld T1, const ld Tu, const ld Tl)
    {
        return (m1 / (T1 * T1)) * ((Tu * Tu) - (Tl * Tl));
    }

    /// <summary>
    /// calculates the amplitudes of oscillations.\n A =(m * g) / k
    /// </summary>
    /// <param name="m">The mass.</param>
    /// <param name="k">The spring constant.</param>
    /// <param name="g">acceleration from gravity, default is GA(9.8).</param>
    /// <returns>amplitude (A)</returns>
    static ld amplitudeOfOscillation(const ld m, const ld k, const ld g = GA)
    {
        return (m * g) / k;
    }

    /// <summary>
    /// A diver on a diving board is undergoing simple harmonic motion.
    /// Her mass is m1 kg and the period of her motion is T1 s.
    /// The next diver is a male whose period of simple harmonic oscillation
    /// is T2 s. What is his mass if the mass of the board is negligible?
    /// \n m2 = pow((T2 / T1), 2.0) * m1
    /// </summary>
    /// <param name="m1">The female diver mass.</param>
    /// <param name="T1">The period of her harmonic motion.</param>
    /// <param name="T2">The period of his harmonic motion.</param>
    /// <returns>the male divers mass</returns>
    static ld massDiver2(const ld m1, const ld T1, const ld T2)
    {
        return pow((T2 / T1), 2.0) * m1;
    }

    /// <summary>
    /// Suppose a diving board with no one on it bounces up and down in a
    /// simple harmonic motion with a frequency of f1. The board has an
    /// effective mass of m1 kg. What is the frequency of the simple harmonic
    /// motion of a m2-kg diver on the board?
    /// \n f2 = f1 * sqrt(m1 / (m1 + m2))
    /// </summary>
    /// <param name="f1">The frequency initially.</param>
    /// <param name="m1">The mass of board.</param>
    /// <param name="m2">The mass of diver.</param>
    /// <returns>frequency of simple harmonic motion</returns>
    static ld frequency2_harmonicMotion(const ld f1, const ld m1, const ld m2)
    {
        return f1 * sqrt(m1 / (m1 + m2));
    }

    /// <summary>
    /// A  skydiver of mass m1 is hanging from a parachute bounces up and down
    /// with a period of T1 s. What is the new period T2 of oscillation when a
    /// second skydiver, whose mass is m2, hangs from the legs of the first.
    /// \n T2 = T1 * sqrt((m1 + m2) / m1)
    /// </summary>
    /// <param name="m1">The mass of first skydiver.</param>
    /// <param name="T1">The period T with one skydiver.</param>
    /// <param name="m2">The mass of the second skydiver.</param>
    /// <returns>the period T with both skydivers</returns>
    static ld period_T2(const ld m1, const ld T1, const ld m2)
    {
        return T1 * sqrt((m1 + m2) / m1);
    }

    /// <summary>
    /// calculates the period T of a simple pendulum. for angles < 15 degrees
    /// \n T = 2.0 * Pi_ * sqrt((L / GA))
    /// </summary>
    /// <param name="L">The length of the pendulum.</param>
    /// <returns>the period T</returns>
    static ld period_simplePendulum(const ld L)
    {
        return 2.0 * Pi_ * sqrt((L / GA));
    }

    /// <summary>
    /// Calculates the length of a simple pendulum.
    /// \n L = ((T * T) * g) / (4.0 * (Pi_ * Pi_))
    /// </summary>
    /// <param name="T">The period T.</param>
    /// <param name="g">the acceleration due to gravity</param>
    /// <returns>length of the pendulum</returns>
    static ld length_simplePendulum(const ld T, const ld g = GA)
    {
        return ((T * T) * g) / (4.0 * (Pi_ * Pi_));
    }

    /// <summary>
    /// Calculates the Frequency of a simple pendulum.
    /// \n f =(1.0 / (2.0 * Pi_)) * sqrt(GA / L)
    /// </summary>
    /// <param name="L">The length of pendulum.</param>
    /// <returns>frequency (Hz)</returns>
    static ld frequency_simplePendulum(const ld L)
    {
        return (1.0 / (2.0 * Pi_)) * sqrt(_Ga_ / L);
    }

    /// <summary>
    /// calculates the periods T of system obeying hooks law.
    /// </summary>
    /// <param name="m">The mass.</param>
    /// <param name="k">The spring force constant.</param>
    /// <returns>the period T</returns>
    static ld period_T(const ld m, const ld k)
    {
        return 2.0 * Pi_ * sqrt(m / k);
    }

    /// <summary>
    ///  A pendulum that has a period of T1s and that is located where
    ///  the acceleration due to gravity is g1 m/s2 is moved to a location
    ///  where it the acceleration due to gravity is g2 m/s2. What is its
    ///  new period?
    /// </summary>
    /// <param name="T1">The initial period T.</param>
    /// <param name="g1">The gravity at location one.</param>
    /// <param name="g2">The gravity at location two.</param>
    /// <returns>period T of pendulum at second location</returns>
    static ld period_T2_pendulum_gravityChange(const ld T1, const ld g1, const ld g2)
    {
        return T1 * sqrt(g1 / g2);
    }

    /// <summary>
    /// A pendulum with a period of T1 s in one location with acceleration due
    /// to gravity g1 and is moved to a new location where the period is now
    /// T2. What is the acceleration due to gravity at its new location?
    /// </summary>
    /// <param name="T1">The initial period T.</param>
    /// <param name="g1">The gravity at initial location.</param>
    /// <param name="T2">The period T of the new location.</param>
    /// <returns>the acceleration due to gravity</returns>
    static ld gravity_pendulum(const ld T1, const ld g1, const ld T2)
    {
        return g1 * pow(T1 / T2, 2);
    }

    /// <summary>
    /// Ropes the stretch.
    /// </summary>
    /// <param name="k">The k.</param>
    /// <param name="m">The m.</param>
    /// <param name="distFall">The dist fall.</param>
    /// <returns></returns>
    static ld ropeStretch(const ld k, const ld m, const ld distFall)
    {
        ld a = .5 * k;
        cout << "a: " << a << endl;
        ld b = -m * GA;
        cout << "b: " << b << endl;
        ld c = distFall * b;
        cout << "c: " << c << endl;

        return quadraticEquation_Plus(a, b, c);
    }

    /// <summary>
    /// calculates the intensity.
    /// </summary>
    /// <param name="P">The power(work/time).</param>
    /// <param name="A">amplitude.</param>
    /// <returns></returns>
    static ld intensity(const ld P, const ld A)
    {
        return P / A;
    }

    /// <summary>
    /// calculates the wavelength.
    /// </summary>
    /// <param name="v">The velocity.</param>
    /// <param name="T">The period T.</param>
    /// <returns>wavelength</returns>
    static ld wavelength_T(const ld v, const ld T)
    {
        return v * T;
    }

    /// <summary>
    /// calculates the wavelength
    /// </summary>
    /// <param name="v">The wave velocity.</param>
    /// <param name="f">The frequency.</param>
    /// <returns>wavelength</returns>
    static ld wavelength_f(const ld v, const ld f)
    {
        return v/f;
    }

    /// <summary>
    /// calculates the total energy caused by a wave of intensity I, over an
    /// area of A, for a time of t
    /// </summary>
    /// <param name="I">The Intensity.</param>
    /// <param name="A">the area the wave is acting on.</param>
    /// <param name="t">The time of measurement.</param>
    /// <returns>Energy of wave in joules</returns>
    static ld energyWave(const ld I, const ld A, const ld t)
    {
        return I * A * t;
    }


    /// <summary>
    /// Times the between waves.
    /// </summary>
    /// <param name="v_w">The v w.</param>
    /// <param name="lamda">The lamda.</param>
    /// <returns></returns>
    static ld timeBetweenWaves(const ld v_w, const ld lamda)
    {
        return lamda / v_w;
    }


    ~Waves()
    {
        delete _wavePtr;
    }

};
#endif //PHYSICSFORMULA_WAVES_H
