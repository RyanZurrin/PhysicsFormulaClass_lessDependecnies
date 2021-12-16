//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_VISIONOPTICALINSTRUMENTS_H
#define PHYSICSFORMULA_VISIONOPTICALINSTRUMENTS_H
#include "WaveOptics.h"

static auto visionOpticInstrument_objectCount = 0;

/// <summary>
///
/// </summary>
/// <seealso cref="WaveOptics" />
class VisionOpticalInstruments :
        public WaveOptics
{

public:
    VisionOpticalInstruments* _visOpticPtr;

    VisionOpticalInstruments()
    {
        _visOpticPtr = nullptr;
        visOpticInstVar = 0.0;
        countIncrease();
    }

    /**
     * @brief copy constructor
     */
    VisionOpticalInstruments(const VisionOpticalInstruments& t)
    {
        _visOpticPtr = t._visOpticPtr;
        visOpticInstVar = t.visOpticInstVar;
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    VisionOpticalInstruments(VisionOpticalInstruments&& t) noexcept
    {
        _visOpticPtr = t._visOpticPtr;
        visOpticInstVar = t.visOpticInstVar;
        countIncrease();
    }
    /**
     * @brief copy assignment operator
     */
    VisionOpticalInstruments& operator=(const VisionOpticalInstruments& t)
    {
        if (this != &t)
        {
            _visOpticPtr = t._visOpticPtr;
            visOpticInstVar = t.visOpticInstVar;
            countIncrease();
        }
        return *this;
    }

    /// <summary>
    /// Shows the object count.
    /// </summary>
    /// <returns></returns>
    static auto show_objectCount() {
        std::cout << "\n visOptInstrument object count: "
                  << visionOpticInstrument_objectCount << std::endl; }
    /// <summary>
    /// Gets the object count.
    /// </summary>
    /// <returns></returns>
    static auto get_objectCount() { return visionOpticInstrument_objectCount; }


    /// <summary>
    /// Finalizes an instance of the <see cref="VisionOpticalInstruments"/> class.
    /// </summary>
    ~VisionOpticalInstruments()
    {
        delete _visOpticPtr;
    }
    /// <summary>
    /// Sets the template variable.
    /// </summary>
    /// <param name="var">The variable.</param>
    void setTemplateVar(ld var) { visOpticInstVar = var; }
    /// <summary>
    /// Gets the template variable.
    /// </summary>
    /// <returns></returns>
    ld getTemplateVar() const { return visOpticInstVar; }

    /// <summary>
    /// Calculates the power of the eye when viewing an object d_o units away and
    /// with an image distance d_i units away. (this chapter uses the value of
    /// 2.00 cm for all the d_i values when dealing with problems relating to
    /// the eye)
    /// </summary>
    /// <param name="d_o">The object distance.</param>
    /// <param name="d_i">The image distance(default at 2.0*10^-2).</param>
    /// <returns>the power of the eye in diopters(D)</returns>
    template<typename T>
    static auto powerOfEye(const T d_o, const T d_i = 2.0*SU.CENTI);

    /// <summary>
    /// The print in many books averages h_o units in height. Calculate How high
    /// the image of the print on the retina when the book is held d_o units from
    /// the eye.
    /// </summary>
    /// <param name="h_o">The object height.</param>
    /// <param name="d_o">The object distance.</param>
    /// <param name="d_i">The image distance(default at 2.0*10^-2).</param>
    /// <returns>image height</returns>
    template<typename T>
    static auto imageHeight( const T h_o, const T d_o, const T d_i = 2.0*SU.CENTI);

    /// <summary>
    /// Suppose a certain person’s visual acuity is such that he can see objects
    /// clearly that form an image h_i units high on his retina. Calculate the maximum
    /// distance at which he can read the h_o units high letters on the side of
    /// an airplane?
    /// </summary>
    /// <param name="h_o">The object height.</param>
    /// <param name="h_i">The image height.</param>
    /// <param name="d_i">The image distance(default at 2.0*10^-2).</param>
    /// <returns>object distance</returns>
    template<typename T>
    static auto objectDistance(const T h_o, const T h_i, const T d_i = 2.0 * SU.CENTI);

    /// <summary>
    /// Calculate the far point of a person whose eyes have a relaxed
    /// power of P_ (D).
    /// </summary>
    /// <param name="P_">The power of the eye.</param>
    /// <param name="d_i">The image distance(default at 2.0*10^-2).</param>
    /// <returns>object distance</returns>
    template<typename T>
    static auto objectDistance_usingPower(const T P_, const T d_i = 2.00 * SU.CENTI);

    /// <summary>
    /// A severely myopic patient has a far point of d_o units. Calculate how many
    /// diopters the power of their eye should be reduced in laser vision
    /// correction to obtain normal distant vision.
    /// </summary>
    /// <param name="d_o">The d object distance.</param>
    /// <param name="d_i">The image distance(default at 2.0*10^-2).</param>
    /// <returns>power reduction in eye</returns>
    template<typename T>
    static auto eyePowerReductionLaserSurgery(const T d_o, const T d_i = 2.00 * SU.CENTI);

    /// <summary>
    /// A young woman with normal distant vision(d_i = default) has a percentCanAccommodate%
    /// ability to accommodate (that is, increase) the power of her eyes. What is
    /// the closest object she can see clearly?
    /// </summary>
    /// <param name="percentCanAccommodate">The percent can accommodate.</param>
    /// <param name="d_i">The image distance(default at 2.0*10^-2)</param>
    /// <returns>closest clear sight</returns>
    template<typename T>
    static auto closestObjectDistance_accommodatedPower(const T percentCanAccommodate);

    /// <summary>
    /// The far point of a myopic administrator is d_o Units. If they have the
    /// normal percentCanAccom% ability to accommodate, Calculate what the closest
    /// object they can see clearly.
    /// </summary>
    /// <param name="d_o">The far point or object distance.</param>
    /// <param name="percentCanAccom">The percent can accommodate.</param>
    /// <param name="d_i">The image distance(default at 2.0*10^-2)</param>
    /// <returns></returns>
    template<typename T>
    static auto closestObjectDistance_accomodateFarPoint(const T d_o, const T percentCanAccom, const T d_i = 2.00 * SU.CENTI);

    /// <summary>
    /// A very myopic man has a far point of d_o units. Calculate what power of
    /// contact lens(when on the eye) will correct his distant vision?
    /// </summary>
    /// <param name="d_o">The d object distance(far point).</param>
    /// <returns>lens power</returns>
    template<typename T>
    static auto powerOfLensToCorrectMyopicVision(const T d_o);

    /// <summary>
    /// A very myopic person has a far point of d_o units. Calculate what power eyeglasses,
    /// positioned posGlasses units from their eyes, will correct their
    /// distant vision.
    /// </summary>
    /// <param name="d_o">The object distance, far point.</param>
    /// <param name="posGlasses">The position of glasses to eye.</param>
    /// <returns>lens power of glasses</returns>
    template<typename T>
    static auto powerOfLensToCorrectMyopicVision(const T d_o, const T posGlasses);

    /// <summary>
    /// A myopic person sees that their contact lens prescription is lensPower D.
    /// Calculate what their far point is.
    /// </summary>
    /// <param name="lensPower">The lens power.</param>
    /// <returns>d_o, far point or object distance</returns>
    template<typename T>
    static auto farPoint_fromLensPowerPrescription(const T lensPower);

    /// <summary>
    /// A myopic person sees that her eyeglasses prescription is lensPower D,
    /// for eyeglasses positioned posGlasses units from her eyes.
    /// Calculate her far point?
    /// </summary>
    /// <param name="lensPower">The lens power.</param>
    /// <param name="posGlasses">The position glasses.</param>
    /// <returns>the far point, d_o</returns>
    template<typename T>
    static auto farPoint_fromLensPowerPrescription(const T lensPower, const T posGlasses);

    /// <summary>
    /// A microscope with an overall magnification of m and has an objective
    /// that magnifies by m_o. Calculate the magnification of the eyepiece.
    /// </summary>
    /// <param name="m">The overall magnification.</param>
    /// <param name="m_o">The objective magnification.</param>
    /// <returns>magnification of eyepiece, m_e</returns>
    template<typename T>
    static auto magnificationEyepiece(const T m, const T m_o);

    /// <summary>
    /// A microscope with an objective magnification of m_o has an eyepiece
    /// that magnifies by m_e. Calculate the overall magnification.
    /// </summary>
    /// <param name="m_o">The objective magnification.</param>
    /// <param name="m_e">The eyepiece magnification.</param>
    /// <returns>the overall magnification, m</returns>
    template<typename T>
    static auto magnificationMicroscope(const T m_o, const T m_e);

    /// <summary>
    /// Calculates the images distance with a object distance of d_o and a focal
    /// length of f.
    /// </summary>
    /// <param name="f">The focal length.</param>
    /// <param name="d_o">The object distance.</param>
    /// <returns>image distance, d_i</returns>
    template<typename T, typename K>
    static auto imageDistance(const T f, const K d_o);

    /// <summary>
    /// What magnification is produced by a f units focal length microscope
    /// objective that is d_o units from the object being viewed?
    /// </summary>
    /// <param name="d_o">The object distance.</param>
    /// <param name="f">The focal length.</param>
    /// <returns>magnification</returns>
    template<typename T>
    static auto magnification_objective(const ld d_o, const ld f);

    /// <summary>
    /// Calculates the magnification of a microscope having a image distance of
    /// d_i and a object distance of d_o.
    /// </summary>
    /// <param name="d_i">The d image distance.</param>
    /// <param name="d_o">The d object distance.</param>
    /// <returns>magnification</returns>
    template<typename T>
    static auto magnification_dido(const T d_i, const T d_o);

    /// <summary>
    /// Calculate the angular magnification of a telescope that has a f_o units
    /// focal length objective and a f_e units focal length eyepiece.
    /// </summary>
    /// <param name="f_o">The objective focal length.</param>
    /// <param name="f_e">The eyepiece focal length.</param>
    /// <returns>angular magnification</returns>
    template<typename T, typename K>
    static auto angularMagnification(const T f_o, const K f_e);

    /// <summary>
    /// A large reflecting telescope has an objective mirror with a
    /// R m radius of curvature. Calculate the angular magnification it
    /// produces when a f_e units focal length eyepiece is used?
    /// </summary>
    /// <param name="R_">The radius of curvature.</param>
    /// <param name="f_e">The eyepiece focal length.</param>
    /// <returns>angular magnification</returns>
    template<typename T, typename K>
    static auto angular_magnification(const T R_, const K f_e);


    /// <summary>
    /// When you hold an insect at the near point of your eye it subtends an
    /// angle of Θ rad. Calculate the angular size (magnitude only)
    /// of the insect when viewed through a microscope that has an angular
    /// magnification with a magnitude of m.
    /// </summary>
    /// <param name="Θ">The f e.</param>
    /// <param name="m">The m e.</param>
    /// <returns></returns>
    template<typename T, typename K>
    static auto angularMagnitude_objectThroughMicroscope(const T Θ, const K m);


    /// <summary>
    /// Where does an object need to be placed relative to a microscope for
    /// its f units focal length objective to produce a magnification of –m
    /// </summary>
    /// <param name="f">The focal length.</param>
    /// <param name="m_o">The object magnification.</param>
    /// <returns>object distance</returns>
    template<typename T, typename K>
    static auto object_Distance(const T f, const K m_o);

    /// <summary>
    /// Where should the f_e units focal length eyepiece be placed to produce
    /// a further (m_e)x magnification
    /// </summary>
    /// <param name="f_e">The eyepiece focal length.</param>
    /// <param name="m_e">The magnification xM example:(4X magnification)
    /// would be a m_e of 4.0.</param>
    /// <returns>object distance</returns>
    template<typename T, typename K>
    static auto object_distance(const T f_e, const K m_e);

    /// <summary>
    /// Calculate what a 1.40NA 60x oil immersion objective
    /// lens would have for acceptance angles. n = 1.51 for oil, substitute this
    /// for whatever you are looking to calculate in place. n is the index of
    /// refraction for a medium.
    /// </summary>
    /// <param name="NA">The numerical aperture value.</param>
    /// <param name="n">The index of refraction.</param>
    /// <returns>the acceptance angle, the larger this is the more resolution
    /// </returns>
    template<typename T, typename K>
    static auto acceptanceAngle(const T NA, const K n);

    /// <summary>
    /// The lens-to-retina distance of a person is d_r units, and the relaxed
    /// power of her eye is P (D). Calculate the far point?
    /// </summary>
    /// <param name="P">The relaxed power.</param>
    /// <param name="d_r">The lens-to-retina distance.</param>
    /// <returns>far point</returns>
    template<typename T>
    static auto farPoint(const T P, const T d_r);

    /// <summary>
    /// The lens-to-retina distance of a woman is LensToRetina units, and the relaxed power
    /// of her eye is P D. What eyeglass power will allow her to see distant
    /// objects clearly, if her glasses are glassesFromEyes units from her eyes?
    /// </summary>
    /// <param name="lensToRetina">The lens to retina.</param>
    /// <param name="P">The relaxed power.</param>
    /// <param name="glassesFromEyes">The glasses from eyes.</param>
    /// <returns>eyeglass power</returns>
    template<typename T>
    static auto eyeglassPower(const T lensToRetina, const T P, const T glassesFromEyes);

    /// <summary>
    /// Your physics TA has a far point of 0.663 m from her eyes and is able to see distant objects in focus when wearing glasses with a refractive power of
    ///−1.55 D. Determine the distance between her glasses and eyes.
    /// </summary>
    /// <param name="f_p">The far point.</param>
    /// <param name="P">The power.</param>
    /// <returns></returns>
    template<typename T>
    static auto distanceBetweenGlassesAndEyes(const T f_p, const T P);








private:
    ld visOpticInstVar;
    static void countIncrease() { visionOpticInstrument_objectCount += 1; }
    static void countDecrease() { visionOpticInstrument_objectCount -= 1; }
};

#endif //PHYSICSFORMULA_VISIONOPTICALINSTRUMENTS_H

template<typename T>
inline auto VisionOpticalInstruments::powerOfEye(const T d_o, const T d_i)
{
    return (1.0 / d_o) + (1 / d_i);//(D)
}

template<typename T>
inline auto VisionOpticalInstruments::imageHeight(const T h_o, const T d_o, const T d_i)
{
    return -(d_i * h_o) / d_o;
}

template<typename T>
inline auto VisionOpticalInstruments::objectDistance(const T h_o, const T h_i, const T d_i)
{
    return -(d_i * h_o) / h_i;
}

template<typename T>
inline auto VisionOpticalInstruments::objectDistance_usingPower(const T P_, const T d_i)
{
    return 1.0 / (P_ - (1.0 / d_i));
}

template<typename T>
inline auto VisionOpticalInstruments::eyePowerReductionLaserSurgery(const T d_o, const T d_i)
{
    return  (1.0 / d_i) - ((1.0 / d_o) + (1.0 / d_i));
}

template<typename T>
inline auto VisionOpticalInstruments::closestObjectDistance_accommodatedPower(const T percentCanAccommodate)
{
    const auto d_i = 2.00 * SU.CENTI;
    const auto decimal = percentCanAccommodate / 100.0;
    const auto increased = 1.0 + decimal;
    const auto pMax = increased * (1.0 / d_i);
    return 1.0 / (pMax - (1.0 / d_i));
}

template<typename T>
inline auto VisionOpticalInstruments::closestObjectDistance_accomodateFarPoint(const T d_o, const T percentCanAccom, const T d_i)
{
    const auto decimal = percentCanAccom / 100.0;
    const auto pFar = (1.0 / d_o) + (1.0 / d_i);
    const auto pClose = (1.0 + decimal) * pFar;
    return 1.00 / (pClose - (1.0 / d_i));
}

template<typename T>
inline auto VisionOpticalInstruments::powerOfLensToCorrectMyopicVision(const T d_o)
{
    return static_cast<ld>(-1.00) / d_o;
}

template<typename T>
inline auto VisionOpticalInstruments::powerOfLensToCorrectMyopicVision(const T d_o, const T posGlasses)
{
    const auto d_i = d_o - posGlasses;
    return static_cast<ld>(-1.00) / d_i;
}

template<typename T>
inline auto VisionOpticalInstruments::farPoint_fromLensPowerPrescription(const T lensPower)
{
    return static_cast<ld>(-1.00) / lensPower;
}

template<typename T>
inline auto VisionOpticalInstruments::farPoint_fromLensPowerPrescription(const T lensPower, const T posGlasses)
{
    const auto d_i = 1.00 / lensPower;
    return -(d_i)+posGlasses;
}

template<typename T>
inline auto VisionOpticalInstruments::magnificationEyepiece(const T m, const T m_o)
{
    return m / m_o;
}

template<typename T>
inline auto VisionOpticalInstruments::magnificationMicroscope(const T m_o, const T m_e)
{
    return m_o * m_e;
}

template<typename T, typename K>
inline auto VisionOpticalInstruments::imageDistance(const T f, const K d_o)
{
    return (f * d_o) / (d_o - f);
}

template<typename T>
inline auto VisionOpticalInstruments::magnification_objective(const ld d_o, const ld f)
{
    return -(f / (d_o - f));
}

template<typename T>
inline auto VisionOpticalInstruments::magnification_dido(const T d_i, const T d_o)
{
    return -(d_i / d_o);
}

template<typename T, typename K>
inline auto VisionOpticalInstruments::angularMagnification(const T f_o, const K f_e)
{
    return -(f_o / f_e);
}

template<typename T, typename K>
inline auto VisionOpticalInstruments::angular_magnification(const T R_, const K f_e)
{
    return -(R_ / 2.0) * (1.0 / f_e);
}

template <typename T, typename K>
inline auto VisionOpticalInstruments::angularMagnitude_objectThroughMicroscope(const T Θ, const K m)
{
    return m * Θ;
}

template<typename T, typename K>
inline auto VisionOpticalInstruments::object_Distance(const T f, const K m_o)
{
    return f - (f / m_o);
}

template<typename T, typename K>
inline auto VisionOpticalInstruments::object_distance(const T f_e, const K m_e)
{
    return f_e * (1 - (1.0 / m_e));
}

template<typename T, typename K>
inline auto VisionOpticalInstruments::acceptanceAngle(const T NA, const K n)
{
    return 2 * asin(NA / n) * DEGREE;
}

template<typename T>
inline auto VisionOpticalInstruments::farPoint(const T P, const T d_r)
{
    return 1.0 / (P - (1.0 / d_r));
}

template<typename T>
inline auto VisionOpticalInstruments::eyeglassPower(const T lensToRetina, const T P, const T glassesFromEyes)
{
    const auto fp = farPoint(P, lensToRetina);
    return -1.0 / (fp - glassesFromEyes);
}

template<typename T>
inline auto VisionOpticalInstruments::distanceBetweenGlassesAndEyes(const T f_p, const T P)
{
    return f_p + (1.0 / P);
}




