//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_HEARING_H
#define PHYSICSFORMULA_HEARING_H
/**
 * @class Hearing
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @date   12/31/2020
 */
#include "Waves.h"

#include <iostream>


static int hearing_objectCount = 0;

/// <summary>
/// The reference Intensity, is the lowest threshold intensity of sound a
/// person with normal hearing can perceive at a frequency of 1000Hz
/// </summary>
constexpr auto I_ref = 1.0e-12;

static struct SoundSpeeds
{
    const ld air_0C = 331.0; // 331, gas 0C
    const ld carbonDioxide = 259.0; // 259, gas 0C
    const ld oxygen = 316.0; // 316, gas 0C
    const ld helium = 965.0; // 965, gas 0C
    const ld hydrogen = 1290.0; // 1290, gas 0C
    const ld ethanol = 1160.0; // 1160, liquid 20C
    const ld mercury = 1450.0; // 1450.0, liquid 20C
    const ld water_fresh = 1480.0; // 1480.0, liquid 20C
    const ld water_sea = 1540.0; // 1540.0, liquid 20C
    const ld humanTissue = 1540.0; // 1540.0, liquid 20C
    const ld vulcanized_rubber = 54.0; // 54.0, solid longitudinal or bulk
    const ld polyethylene = 920.0; // 920.0, solid longitudinal or bulk
    const ld marble = 3810.0; // 3810.0, solid longitudinal or bulk
    const ld glass_pyrex = 5640.0; // 5640.0, solid longitudinal or bulk
    const ld lead = 1960.0; // 1960.0, solid longitudinal or bulk
    const ld aluminum = 5120.0; // 5120.0, solid longitudinal or bulk
    const ld steel = 5960.0; // 5960.0, solid longitudinal or bulk

}Vw;


class Hearing :
        public Waves
{
private:
    static void countIncrease() { hearing_objectCount += 1; }
    static void countDecrease() { hearing_objectCount -= 1; }
public:
    Hearing* _hearingPtr;
    Waves* _wavePtr;

    Hearing()
    {
        _hearingPtr = nullptr;
        _wavePtr = nullptr;
        countIncrease();
    }

    /**
     * @brief copy constructor
     */
    Hearing(const Hearing& t)
            : Waves(t)
    {
        _hearingPtr = t._hearingPtr;
        _wavePtr = t._wavePtr;
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    Hearing(Hearing&& t) noexcept
    {
        _hearingPtr = t._hearingPtr;
        _wavePtr = t._wavePtr;
        countIncrease();
    }
    /**
     * @brief copy assignment operator
     */
    Hearing& operator=(const Hearing& t)
    {
        if (this != &t)
        {
            _hearingPtr = t._hearingPtr;
            _wavePtr = t._wavePtr;
            countIncrease();
        }
        return *this;
    }

    static void show_objectCount() { std::cout << "\n hearing object count: " << hearing_objectCount << std::endl; }
    static int get_objectCount() { return hearing_objectCount; }
    inline auto static printArr = []<class T>(const T arr[], T n, string label = "array values")
    {

        cout << "\n" + label + ": ";
        for (size_t i = 0; i < n; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
    };
    /*
    void static printArr(const double arr[], int n, string label = "array values")
    {

        cout << "\n"+ label+": ";
        for (size_t i = 0; i < n; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    */
    /// <summary>
    /// Calculates the speeds of sound when the temp of surrounding enviroment
    /// is known and converted to kelvins in this formula.
    /// Vw = (vw)*sqrt(temp / 273.0)
    /// </summary>
    /// <param name="temp">The temperature in celsius.</param>
    /// <param name="_Vw">The air speed at 0C is the default.</param>
    /// <returns></returns>
    static ld speedOfSound(const ld temp, const ld vw = Vw.air_0C)
    {
        return (vw)*sqrt( (temp+273.15) / 273.0);
    }

    /// <summary>
    /// calculates the speeds the sound with a wave length of wL and a
    /// frequency of f.
    /// </summary>
    /// <param name="f">The frequency.</param>
    /// <param name="wL">The wave length.</param>
    /// <returns>speed of sound (Vw)</returns>
    static ld speedOfSound_fwL(const ld f, const ld wL)
    {
        return f * wL;
    }

    /// <summary>
    /// Calculates the doppler effect of a moving source heading away from
    /// an observer.
    /// </summary>
    /// <param name="f">The frequency.</param>
    /// <param name="Vw">The speed of sound through material.</param>
    /// <param name="Vs">The speed of the moving source.</param>
    /// <returns>frequency of the sound waves</returns>
    static ld dopplerEffect_movingSource_awayFromObserver(const ld f, const ld Vw, const ld Vs)
    {
        return f * (Vw / (Vw + Vs));
    }

    /// <summary>
    /// calcualtes the doppler  effect of a moving source heading towards
    /// the observer.
    /// </summary>
    /// <param name="f">The frequency.</param>
    /// <param name="Vw">The speed of sound through material.</param>
    /// <param name="Vs">The speed of the moving source.</param>
    /// <returns>frequency of the sound waves</returns>
    static ld dopplerEffect_movingSource_towardsObserver(const ld f, const ld Vw, const ld Vs)
    {
        return f * (Vw / (Vw - Vs));
    }

    /// <summary>
    /// Calculates the doppler effect of a stationary source and observer
    /// moving towards source.
    /// </summary>
    /// <param name="f">The frequency.</param>
    /// <param name="Vw">The speed of sound through material.</param>
    /// <param name="Vobs">The speed of the observer.</param>
    /// <returns>frequency of sound waves</returns>
    static ld dopplerEffect_stationarySource_towardsSource(const ld f, const ld Vw, const ld Vobs)
    {
        return f * ((Vw + Vobs)/Vw);
    }

    /// <summary>
    ///  Calculates the dopple effect of a stationary source and observer
    /// moving away from the source.
    /// </summary>
    /// <param name="f">The frequency.</param>
    /// <param name="Vw">The speed of sound through material.</param>
    /// <param name="Vobs">The speed of the observer.</param>
    /// <returns>frequency of sound waves</returns>
    static ld dopplerEffect_stationarySource_awayFromSource(const ld f, const ld Vw, const ld Vobs)
    {
        return f *  ((Vw - Vobs)/Vw);
    }

    /// <summary>
    /// Two eagles fly directly toward one another, the first at v1 m/s and
    /// the second at v2 m/s. Both screech, the first one emitting a frequency
    /// of f1 Hz and the second one emitting a frequency of f2 Hz.
    /// What frequencies do they receive if the speed of sound is vw m/s?
    /// </summary>
    /// <param name="v1">The speed of object 1.</param>
    /// <param name="v2">The speed of object 2.</param>
    /// <param name="f1">The frequency of object 1.</param>
    /// <param name="f2">The frequency of object 2.</param>
    /// <param name="vw">The speed of sound.</param>
    /// <returns>vector with the frequency each object hears, <obj1, obj2></returns>
    static vector<ld> dopplerEffect_2movingSources_towards
            (const ld v1, const ld v2, const ld f1, const ld f2, const ld vw)
    {
        vector<ld> results = {0.0, 0.0};
        results[0] = f2 * ((vw + v1) / (vw - v2));//obj1 hears
        results[1] = f1 * ((vw + v2) / (vw - v1));//obj2 hears
        return results;
    }


    /// <summary>
    /// calculates the intensity of a sound wave as it is related to its amplitude
    /// squared by the following relationship
    /// (p * p) / (2.0 * density * v) here the p is the pressure variation or pressure amplitude
    /// </summary>
    /// <param name="p">The pressure variation.</param>
    /// <param name="density">The density of material for which the sound wave travels.</param>
    /// <param name="v">The speed of the sound in the medium in units of m/s.</param>
    /// <returns>the sound intensity</returns>
    static ld I(const ld p, const ld density, const ld v)
    {
        return (p * p) / (2.0 * density * v);
    }

    /// <summary>
    /// something produces a noise at a
    /// level of dB decibels. What is this in watts per meter squared, also
    /// known as intensity (I)?
    /// </summary>
    /// <param name="dB">The decibel level.</param>
    /// <returns>the intensity in W/m^2</returns>
    static ld intensityFrom_dB(const ld dB)
    {
        return I_ref * pow(10, dB / 10);
    }

    /// <summary>
    /// Calculates the decibel level of a sound wave with the know intensity.
    /// </summary>
    /// <param name="I">The i.</param>
    /// <returns></returns>
    static ld soundIntensityLevel_dB(const ld I)
    {
        return static_cast<ld>(10.0) * static_cast<ld>(log10((I / I_ref)));
    }

    /// <summary>
    ///  What is the intensity of a sound that has a level dB_dif lower than
    ///  a I1 intensity W/m2 sound?
    /// </summary>
    /// <param name="I1">The The know sound Intensity.</param>
    /// <param name="dB_dif">The difference in decibels.</param>
    /// <returns>Intensity of the second sound</returns>
    static ld soundIntensity(const ld I1, const ld dB_dif)
    {
        return I1 * pow(10, ((dB_dif / 10.0)));
    }


    /// <summary>
    /// calculates the length of the of tube from frequency.
    /// </summary>
    /// <param name="f">The f.</param>
    /// <param name="vw">The vw.</param>
    /// <returns>length of tube</returns>
    static ld lengthOfTube(const ld f, const ld vw = Vw.air_0C)
    {
        return vw / (4.0 * f);
    }

    /// <summary>
    /// Fundamentals the frequency closed tube.
    /// </summary>
    /// <param name="L">The l.</param>
    /// <param name="vw">The vw.</param>
    /// <returns>fundamental frequency</returns>
    static ld fundamentalFrequency_closedTube(const ld L, const ld vw = Vw.air_0C)
    {
        return vw / (4.0 * L);
    }

    static ld fundamentalFrequency_openTube(const ld vw, const ld L)
    {
        return vw / (2.0 * L);
    }

    /// <summary>
    /// calculates the overtones of sound wave with the first overtone being
    /// n = 3, second overtone n = 5, third n = 7, forth n = 9, etc..
    /// </summary>
    /// <param name="L">The length of a full wave.</param>
    /// <param name="n">The nth overtone value.</param>
    /// <param name="vw">The speed pf sound through material, defaulted
    /// to 0 celsius air.</param>
    /// <returns>overtone frequency</returns>
    static ld overtoneCalculator_closedTube(const ld L, const ld n = 1, const ld vw = Vw.air_0C)
    {
        return (n * vw) / (4.0 * L);
    }

    /// <summary>
    /// Overtones the generator open tube.
    /// </summary>
    /// <param name="vw">The speed of sound.</param>
    /// <param name="L">The length of tube.</param>
    /// <param name="totalOvertones">The total overtones.</param>
    template<typename T>
    static auto overtoneGenerator_openTube_L(const T vw, const T L, const T totalOvertones)
    {
        const auto S = totalOvertones+1.0;
        const auto result = new T[S];
        for (size_t i=1; i<totalOvertones+1.0;i++)
        {
            result[i - 1] = (static_cast<int>(i) * vw) / (2.0 * L);// Initialize all elements to zero.
        }
        printArr(result, totalOvertones, "openTube overtones");
        //delete[] result;
    }
    template<typename T>
    static auto overtoneGenerator_closedTube_L(const T vw, const T L, const T totalOvertones)
    {
        const auto S = totalOvertones+1.0;
        const auto result = new T[S];
        for (size_t i=0, j = 3; i<totalOvertones; j++,j++, i++)
        {
            result[i] = (static_cast<int>(j) * vw) / (4.0 * L); // Initialize all elements to zero.
        }

        printArr(result, totalOvertones, "closedTube overtones");
        //delete[] result;
    }

    template<typename T>
    static auto overtoneGenerator_openTube_f(const T funFreq, const T totalOvertones)
    {
        const auto S = totalOvertones+1.0;
        const auto result = new T[S];
        for (size_t i=1; i<totalOvertones+1.0;i++)
        {
            result[i - 1] = static_cast<int>(i) * funFreq;// Initialize all elements to zero.
        }
        printArr(result, totalOvertones, "openTube overtones");
        //delete[] result;

    }

    /// <summary>
    /// Overtones the generator closed tube.
    /// </summary>
    /// <param name="funFreq">The fun freq.</param>
    /// <param name="totalOvertones">The total overtones.</param>
    template<typename T>
    static auto overtoneGenerator_closedTube_f(const T funFreq, const T totalOvertones)
    {
        const auto S = totalOvertones+1.0;
        const auto result = new T[S];
        for (size_t i=1, j = 3; i<totalOvertones+1; j++,j++, i++)
        {
            result[i - 1] = funFreq * static_cast<int>(j); // Initialize all elements to zero.
        }

        printArr(result, totalOvertones, "closedTube overtones");
        //delete[] result;

    }

    /// <summary>
    /// What frequency sound has wvl wavelength when the speed of sound is vw
    /// </summary>
    /// <param name="wvl">The wavelength.</param>
    /// <param name="vw">The speed of sound.</param>
    /// <returns>frequency of sound(Hz)</returns>
    static ld frequency(const ld wvl, const ld vw)
    {
        return vw / wvl;
    }

    /// <summary>
    /// A sonar echo returns to a submarine t seconds after being emitted.
    /// What is the distance to the object creating the echo?
    /// (Assume that the submarine is in the ocean, not in fresh water.)
    /// </summary>
    /// <param name="t">The time is seconds.</param>
    /// <param name="vw">The speed of sound. default is sea water. change if
    /// need another value. values can be found in the Vw structure.</param>
    /// <returns>length between sonar source and object causing it to bounce
    /// back</returns>
    static ld distanceSonarEcho(const ld t, const ld vw = Vw.water_sea)
    {
        return (vw * t) / 2.0;
    }

    /// <summary>
    /// If a sound some distance away from you makes a noise of dB decibel,
    /// what is the noise level if x number more of those are added at the same
    /// distance, assuming interference has a negligible effect
    /// </summary>
    /// <param name="dB">The dB.</param>
    /// <param name="x">The increase factor.</param>
    /// <returns>noise level in decibels (dB)</returns>
    static ld noiseLevel(const ld dB, const ld x)
    {
        return dB + 10.0 * log(x);
    }

    /// <summary>
    /// calculates the pressure amplitude in terms of Intensity
    /// </summary>
    /// <param name="p">The pressure.</param>
    /// <param name="v">The velocity.</param>
    /// <param name="I">The intensity.</param>
    /// <returns>pressure amplitude, gauge pressure(</returns>
    static ld pressureAmplitude_I(const ld p, const ld v, const ld I)
    {
        return sqrt(2.0 * p * v * I);
    }

    /// <summary>
    /// If a sound intensity level of dB1 corresponds to a maximum
    /// gauge pressure (sound amplitude) of p1, what is the maximum gauge
    /// pressure in a db2 decibel sound?
    /// </summary>
    /// <param name="dB1">The decibels of sound 1.</param>
    /// <param name="p1">The gauge pressure of sound 1 .</param>
    /// <param name="dB2">The decibel level of the second sound.</param>
    /// <returns>p2, the pressure amplitude related to dB2</returns>
    static ld pressureAmplitude_p(const ld dB1, const ld p1, const ld dB2)
    {
        return p1*pow(10,(dB2 - dB1)/20);
    }

    /// <summary>
    /// A commuter train blows its horn at a frequency of fHorn as it approaches
    /// a crossing. The speed of sound is vw. An observer waiting at the crossing
    /// receives a frequency of fobs Hz. What is the speed of the train?
    /// </summary>
    /// <param name="fHorn">The known frequency of train horn.</param>
    /// <param name="fobs">The observed frequency as train approaches.</param>
    /// <param name="vw">The speed of sound.</param>
    /// <returns>speed of train</returns>
    static ld speedOfApproachingTrain(const ld fHorn, const ld fobs, const ld vw)
    {
        return vw - vw * (fHorn / fobs);
    }

    /// <summary>
    /// calculates the beat frequency which is the absolute difference between
    /// two frequencies.
    /// </summary>
    /// <param name="f1">The first frequency.</param>
    /// <param name="f2">The second frequency.</param>
    /// <returns>beat frequency</returns>
    static ld beatFrequency(const ld f1, const ld f2)
    {
        return abs(f1 - f2);
    }

    ~Hearing()
    {
        delete _hearingPtr;
    }

};
#endif //PHYSICSFORMULA_HEARING_H
