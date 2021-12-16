//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_WAVEOPTICS_H
#define PHYSICSFORMULA_WAVEOPTICS_H
#include "GeometricOptics.h"
#include <cmath>
#include <iostream>
//α=224,ß=225,π=227,Σ=228,σ=229,µ=230,τ=231,Φ=232,Θ=233
//Ω=234,δ=235,∞=236,φ=237,ε=238,∩=239,≡=240,Γ=226,γ, σ, ϑ, Å, Ώ, λ, γ
/**
 * @class WaveOptics
 * @details class of static methods that relate to chapter 27 of the open-stax
 * college physics text book.
 * @author Ryan Zurrin
 * dateBuilt  5/15/2021
 * lastEdit 5/15/2021
 */
static int waveOptics_objectCount = 0;

class WaveOptics :
        public GeometricOptics
{

public:
    WaveOptics* _waveOpticPtr;

    WaveOptics()
    {
        _waveOpticPtr = nullptr;
        waveOpticsVar = 0.0;
        countIncrease();
    }

    /**
     * @brief copy constructor
     */
    WaveOptics(const WaveOptics& t)
    {
        _waveOpticPtr = t._waveOpticPtr;
        waveOpticsVar = t.waveOpticsVar;
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    WaveOptics(WaveOptics&& t) noexcept
    {
        _waveOpticPtr = t._waveOpticPtr;
        waveOpticsVar = t.waveOpticsVar;
        countIncrease();
    }
    /**
     * @brief copy assignment operator
     */
    WaveOptics& operator=(const WaveOptics& t)
    {
        if (this != &t)
        {
            _waveOpticPtr = t._waveOpticPtr;
            waveOpticsVar = t.waveOpticsVar;
            countIncrease();
        }
        return *this;
    }

    static void show_objectCount() { std::cout <<"\n wave optics object count: "
                                               << waveOptics_objectCount << std::endl; }
    static int get_objectCount() { return waveOptics_objectCount; }


    ~WaveOptics()
    {
        delete _waveOpticPtr;
    }
    void setGeometricOpticsVar(ld var) { waveOpticsVar = var; }
    ld getGeometricOpticsVar() const { return waveOpticsVar; }


    /// <summary>
    /// Calculates the wavelength in a medium when the λ in a vacuum is λ and
    /// the index of refraction of the medium is n.
    /// </summary>
    /// <param name="λ">The wavelength in a vacuum.</param>
    /// <param name="n">The index of refraction.</param>
    /// <returns>the wavelength in a medium</returns>
    static auto wavelengthInMedium(const ld λ, const ld n);

    /// <summary>
    /// Calculates the wavelength of medium.
    /// </summary>
    /// <param name="n">The index of refraction of medium.</param>
    /// <param name="f">The frequency.</param>
    /// <returns>the wavelength of medium (Hz)</returns>
    static auto wavelengthOfMedium(const ld n, const ld f);

    /// <summary>
    /// Show that when light passes from nTop to nBottom, its wavelength changes
    /// to some value times its original value.
    /// </summary>
    /// <param name="nTop">The index of refraction of medium in.</param>
    /// <param name="nBottom">The index of refraction medium moving too.</param>
    /// <returns>ratio of wavelengths</returns>
    static auto wavelength_ratioOf2IndexOfRefractions(const ld nTop, const ld nBottom);

    /// <summary>
    /// Distances traveled by a wave front.
    /// </summary>
    /// <param name="v">The wave speed.</param>
    /// <param name="t">The time.</param>
    /// <returns></returns>
    static auto distanceTraveledByWaveFront(const ld v, const ld t);

    /// <summary>
    /// Calculates the index of refraction of a material for which the wavelength
    /// of light is xTimes its value in a vacuum? prints out medium if found
    /// </summary>
    /// <param name="xTimes">The x times.</param>
    /// <returns>index of refraction</returns>
    static auto indexOfRefractionFromRatioPrintMedium(const ld xTimes);

    /// <summary>
    /// Analysis of an interference effect in a clear solid shows that the
    /// wavelength of light in the solid is 329 nm. Knowing this light comes
    /// from a He-Ne laser and has a wavelength of 633 nm in air, is the
    /// substance zircon or diamond?
    /// </summary>
    /// <param name="λMedium">The w l medium.</param>
    /// <param name="λ2">The w l2.</param>
    /// <returns></returns>
    static auto indexOfRefractionFromWavelengths(const ld λMedium, const ld λ2);

    /// <summary>
    /// Calculates the angle of the n order of maximum for λ wavelength
    /// of light falling on double slits separated by d (m)?
    /// </summary>
    /// <param name="m">The order of interference: 0, 1, -1, 2, -2.....</param>
    /// <param name="λ">The wavelength.</param>
    /// <param name="d">The distance between slits.</param>
    /// <returns>the angle Θ</returns>
    static auto angleOf_nOrderOfInterference_doubleSlit(int m, const ld λ, const ld d);

    /// <summary>
    ///Calculates the separation between two slits for which a wavelength of λ
    /// light has its first maximum at an angle of Θ∘.
    /// </summary>
    /// <param name="m">The order of interference: 0, 1, -1, 2, -2.....</param>
    /// <param name="λ">The wavelength.</param>
    /// <param name="Θ">The angle Θ.</param>
    /// <returns>separation between slits (units)</returns>
    static auto separationBetweenSlits_doubleSlit(const int m, const ld λ, const ld Θ);

    /// <summary>
    /// Calculates the distance between two slits that produces the first minimum
    /// for λ(m) of light at an angle of Θ∘
    /// </summary>
    /// <param name="m">The order of interference: 0, 1, -1, 2, -2....</param>
    /// <param name="λ">The w l.</param>
    /// <param name="Θ">The Θ.</param>
    /// <returns></returns>
    static auto separationBetweenSlits_destructive(const int m, const ld λ, const ld Θ);

    /// <summary>
    /// Calculates the wavelength of light that has its m minimum at an
    /// angle of Θ∘ when falling on double slits separated by d(units).
    /// </summary>
    /// <param name="m">The minimum.</param>
    /// <param name="d">The distance between slits.</param>
    /// <param name="Θ">The angle Θ.</param>
    /// <returns>the wavelength (units)</returns>
    static auto wavelengthAt_nMinimum_doubleSlit(const int m, const ld d, const ld Θ);

    /// <summary>
    /// Calculates the wavelength of light falling on double slits separated by
    /// d units, if the nM maximum is at an angle of Θ∘.
    /// </summary>
    /// <param name="nM">The order of maximum.</param>
    /// <param name="d">The distance between slits.</param>
    /// <param name="Θ">The angle Θ.</param>
    /// <returns>wavelength</returns>
    static auto wavelengthAt_nOrderMaximum_doubleSlit(const ld nM, const ld d, const ld Θ);

    /// <summary>
    /// Calculates the wavelength of light that has its m minimum at an angle
    /// of Θ∘ when it falls on a single slit of width D units.
    /// </summary>
    /// <param name="m">The order of minimum.</param>
    /// <param name="D">The width of slit.</param>
    /// <param name="Θ">The angle θ.</param>
    /// <returns>wavelength</returns>
    static auto wavelength_nMinSingleSlit(const ld m, const ld D, const ld Θ);

    /// <summary>
    /// Calculates the wavelength of light that has its m-order maximum at angle Θ,
    /// when falling on a diffraction grating that has a total of s slits per centimeter.
    /// </summary>
    /// <param name="m">The order of interference </param>
    /// <param name="Θ">The angle θ.</param>
    /// <param name="s">The number of slits per cm.</param>
    /// <returns>the wavelength</returns>
    static auto wavelengthOfLight_nOrderMaxGrating(const ld m, const ld Θ, const ld s);

    /// <summary>
    /// What is the highest-order maximum for light with a wavelength of λ
    /// falling on double slits separated by d units.
    /// </summary>
    /// <param name="d">The distance of separation between slits.</param>
    /// <param name="λ">The wavelength.</param>
    /// <param name="Θ">The angle Θ is default at 90 degrees which
    /// would be thrush hold angle that would cause a maximum order.</param>
    /// <returns>m= order of interference</returns>
    static auto highestOrderMaximum(const ld d, const ld λ, const ld Θ);

    /// <summary>
    /// Calculates angle at nM order maximum, if the first-order maximum for pure-wavelength light
    /// falling on a double slit is at an angle of Θ∘
    /// nM-order maximum
    /// </summary>
    /// <param name="nM">The n m.</param>
    /// <param name="Θ">The Θ.</param>
    /// <returns>angle of Θ at nM maximum</returns>
    static auto angleOf_nOrderMaximum(const ld nM, const ld Θ);

    /// <summary>
    /// Calculates the angle of the nMim minimum, if the first-order minimum
    /// for pure-wavelength light falling on a double slit is at an angle of Θ∘
    /// </summary>
    /// <param name="nMin">The n minimum.</param>
    /// <param name="Θ">The Θ.</param>
    /// <returns>angle Θ at n minimum</returns>
    static auto angleOf_nMinimum(const ld nMin, const ld Θ);

    /// <summary>
    /// Calculates the highest order maximum, If the first-order maximum for pure-wavelength
    /// light falling on a double slit at an angle of Θ.
    /// </summary>
    /// <param name="Θ">The first order maximum Θ.</param>
    /// <returns>highest order of maximum</returns>
    static auto highestOrderMaximum(const ld Θ);

    /// <summary>
    /// Using Δy=x*λ*d, calculate the distance between fringes for 633-nm light
    /// falling on double slits separated by 0.0800 mm, located 3.00 m from a
    /// screen as in Figure
    /// </summary>
    /// <param name="x">The x.</param>
    /// <param name="λ">The w l.</param>
    /// <param name="d">The d.</param>
    /// <returns></returns>
    static auto distanceBetweenFringes(const ld x, const ld λ, const ld d);

    /// <summary>
    /// Calculate the wavelength of light that produces fringes Δy units
    /// apart on a screen x units from double slits separated by d units.
    /// </summary>
    /// <param name="x">The x.</param>
    /// <param name="Δy">The δy.</param>
    /// <param name="d">The d.</param>
    /// <returns>distance between fringes on screen</returns>
    static auto wavelengthFromFringes(const ld x, const ld Δy, const ld d);

    /// <summary>
    /// Waves the length at n order m fringe.
    /// </summary>
    /// <param name="m">The m.</param>
    /// <param name="y">The y.</param>
    /// <param name="x">The x.</param>
    /// <param name="d">The d.</param>
    /// <returns></returns>
    static auto waveLengthAt_nOrderMFringe(const ld m, const ld y, const ld x, const ld d);

    /// <summary>
    /// Young's double slit experiment is one of the quintessential experiments
    /// in physics. The availability of low cost lasers in recent years allows
    /// us to perform the double slit experiment rather easily in class.
    /// Your professor shines a green laser (λ units) on a double slit with a
    /// separation of d units. The diffraction pattern shines on the classroom
    /// wall x units away. Calculate the fringe separation between the m order
    /// and central fringe.
    /// </summary>
    /// <param name="m">The m.</param>
    /// <param name="x">The x.</param>
    /// <param name="λ">The λ.</param>
    /// <param name="d">The d.</param>
    /// <returns></returns>
    static auto fringeSeparationAt_nOrderMFromCenterDS(const ld m, const ld x, const ld λ, const ld d);

    /// <summary>
    /// Distances the between grating slits.
    /// </summary>
    /// <param name="slits">The slits.</param>
    /// <param name="totalLength">The total length in meters.</param>
    /// <returns>distance between the slits in meters</returns>
    static ld distanceBetweenGratingSlits(const ld slits, const ld totalLength);

    /// <summary>
    /// Calculates the distance between lines on a diffraction grating that
    /// produces a m-order maximum for λ-nm light at an angle of Θ∘.
    /// </summary>
    /// <param name="m">The order of interference.</param>
    /// <param name="λ">The wavelength λ.</param>
    /// <param name="Θ">The angle θ.</param>
    /// <returns>distance between lines in a diffraction grating</returns>
    static auto separationBetweenSlitsDiffractionGrating(const ld m, const ld  λ, const ld Θ);

    /// <summary>
    /// Calculates how many lines per centimeter are there on a diffraction
    /// grating that gives a m-order maximum for λ-m light at an angle of Θ.
    /// </summary>
    /// <param name="m">The order of interference.</param>
    /// <param name="λ">The wavelength λ.</param>
    /// <param name="Θ">The angle θ.</param>
    /// <returns>how many lines per centimeter in a diffraction grating</returns>
    static auto linesPer_cmDefractionGrating(const ld m, const ld λ, const ld Θ);

    /// <summary>
    /// Calculates the value of Θ with a order m interference.
    /// </summary>
    /// <param name="m">The order of interference.</param>
    /// <param name="d">The distance between slits.</param>
    /// <param name="λ">The wavelength .</param>
    /// <returns>the angle of Θ</returns>
    static auto thetaAtOrderOfInterference(const ld m, const ld d, const ld λ);

    /// <summary>
    /// Calculates the distance from a desired wave length to the central location
    /// </summary>
    /// <param name="x">The x-direction distance.</param>
    /// <param name="Θ">The angle Θ.</param>
    /// <returns>the length from the center to the where a wavelength fringe
    /// intersects on the screen</returns>
    static auto yDistanceApart(const ld x, const ld Θ);

    /// <summary>
    /// Calculates the width of a single slit.
    /// </summary>
    /// <param name="λ">The wavelength λ.</param>
    /// <param name="m">The order of interference m.</param>
    /// <param name="Θ">The angle theta θ.</param>
    /// <returns>width of slit</returns>
    static auto singleSlitWidth(const ld λ, const ld m, const ld Θ);

    /// <summary>
    /// Uses the Rayleigh criterion to solve for the minimum resolvable angle.
    /// between two objects where  λ is the wavelength of light and D is the
    /// diameter of aperture.
    /// </summary>
    /// <param name="λ">The wavelength λ.</param>
    /// <param name="D">The diameter of aperture.</param>
    /// <returns>the minimum angle between two objects that produce a resolvable
    /// image</returns>
    static auto rayleighEquation(const ld λ, const ld D);

    /// <summary>
    /// A telescope can be used to enlarge the diameter of a laser beam and
    /// limit diffraction spreading. The laser beam is sent through the telescope
    /// in opposite the normal direction and can then be projected onto a
    /// satellite or the Moon. If this is done with the
    /// telescope, producing a D-m-diameter beam of λ-nm light, neglecting atmospheric
    /// effects, calculate is the size of the spot this beam would make on the Moon,
    /// assuming a distance of x m?
    /// </summary>
    /// <param name="λ">The wave length λ.</param>
    /// <param name="D">The diameter of beam.</param>
    /// <param name="x">The distance away.</param>
    /// <returns>the total diffraction spreading of beam on object</returns>
    static auto diffractionSpreadingTotal(const ld λ, const ld D, const ld x);

    /// <summary>
    /// calculates the distance s between two object a distance r away and
    /// separated by an angle Θ.
    /// </summary>
    /// <param name="r">The distance away in any units.</param>
    /// <param name="Θ">The angle θ.</param>
    /// <returns>distance the two objects are apart</returns>
    static auto s_distance2Obj_rApart(const ld r, const ld Θ);

    /// <summary>
    /// What is the minimum diameter mirror on a looking scope that would allow
    /// you to see details as small as y units apart on a object some x units
    /// away? Assume an average wavelength of λ units for the light received.
    /// </summary>
    /// <param name="y">The separation between objects being viewed.</param>
    /// <param name="x">The distance away.</param>
    /// <param name="λ">The wavelength.</param>
    /// <returns>size of mirror in looking device</returns>
    static auto minimumMirrorDiameter(const ld y, const ld x, const ld λ);

    /// <summary>
    /// Uses the Rayleigh criterion to calculate where resolution is still possible
    /// looking through a microscope for which the minimum angular separation where
    /// d is the distance between the specimen and the objective lens, and we have used the small
    /// angle approximation assuming that x is much smaller then d, so that
    /// that tanΘ = sin Θ == Θ. so x is the resolving power from the resolving
    /// power equation.
    /// </summary>
    /// <param name="x">The resolving power.</param>
    /// <param name="d">The distance between the specimen and the
    /// objective lens.</param>
    /// <returns>the minimum angular separation where two point objects can
    /// be resolved</returns>
    static auto minimumAngularSeparation(const ld x, const ld d);

    /// <summary>
    /// Calculates the resolving power of a microscope
    /// </summary>
    /// <param name="λ">The wavelength λ.</param>
    /// <param name="d">The  distance between the specimen and the
    /// objective lens.</param>
    /// <param name="D">The diameter of aperture.</param>
    /// <returns>resolving power</returns>
    static auto resolvingPower(const ld λ, const ld d, const ld D);

    /// <summary>
    /// Calculates the resolving  power for a microscope lens.
    /// </summary>
    /// <param name="λ">The wavelength λ.</param>
    /// <param name="n">The index of refraction between the lens and the object
    /// .</param>
    /// <param name="NA">The Numerical Aperture.</param>
    /// <returns></returns>
    static auto resolvingPower_microscopeLens(const ld λ, const ld n, const ld NA);

    /// <summary>
    /// Calculates the thinnest thickness of a non reflective lens coating.
    /// </summary>
    /// <param name="λ">The λ.</param>
    /// <param name="n">The index of refraction of film.</param>
    /// <returns>thinnest thickness of coating</returns>
    static auto thicknessOfNonReflectiveLensCoating(const ld λ, const ld n);

    /// <summary>
    /// Suppose you have a lens(n= 1.52) system that is to be used primarily for λ-nm
    /// light. What is the second thinnest coating of (n)fluorite(n=1.38)
    /// (magnesium fluoride) that would be non- reflective for this wavelength?
    /// this uses the fact that there are two λ/2 phase shifts as the light
    /// travels from air91.00) into the fluorite(1.38) then to glass lens(1.52),
    /// with the second phase shift having an additional distance to travel as
    /// well being a total of λ/2 + ((2*thickness)/λ_n)*λ = λ/2 + 2*t*n after
    /// substituting in λ_n = λ/n which we will multiply instead because its
    /// being divided in the originally so this allows us to cancel the λ out
    /// of the formula completely.
    /// </summary>
    /// <param name="λ">The wave length of light trying to be blocked </param>
    /// <param name="n">The index of refraction of the coating.</param>
    /// <param name="m">The multiple integers of interference that cause
    /// a destructive interference.</param>
    /// <returns></returns>
    static auto thicknessOfThinnestCoating(const ld λ, const ld n, const ld m);

    /// <summary>
    /// To save money on making military aircraft invisible to radar, an inventor
    /// decides to coat them with a non-reflective material having an index of
    /// refraction of 1.20, which is between that of air and the surface of the
    /// plane. This, he reasons, should be much cheaper than designing Stealth
    /// bombers. Calculates What thickness should the coating be to inhibit the
    /// reflection of 4.00-cm wavelength radar.
    /// </summary>
    /// <param name="λ">The λ.</param>
    /// <param name="n">The n.</param>
    /// <param name="m">The m.</param>
    /// <returns>thickness</returns>
    static auto thicknessOfCoating(const ld λ, const ld n, const ld m);

    /// <summary>
    /// Malus's law used to calculate the intensity of a polarized wave after
    /// passing through a filter. Where Io is the incident wave and Θ is the angle
    /// between the direction of polarization and the axis of a filter.
    /// </summary>
    /// <param name="Io">The intensity of polarized wave.</param>
    /// <param name="Θ">The θ.</param>
    /// <returns>intensity of wave</returns>
    static auto intensityOfTransmittedWave(const ld Io, const ld Θ);

    /// <summary>
    /// A soap bubble is t units thick and illuminated by white light incident
    /// perpendicular to its surface. What wavelength and color of visible light
    /// is most constructively reflected, assuming the same index of refraction
    /// as water?
    /// </summary>
    /// <param name="t">The thickness.</param>
    /// <param name="n">The index of refraction.</param>
    /// <returns>wavelength</returns>
    static auto constructivelyReflectedWavelength(const ld t, const ld n);

    /// <summary>
    /// An oil slick on water is 120 nm(t) thick and illuminated by white light
    /// incident perpendicular to its surface. What color does the oil appear
    /// (Calculate the most constructively reflected wavelength), given its index
    /// of refraction is 1.40(n), using constant multiples of m to find the first
    /// visible wavelength.
    /// </summary>
    /// <param name="t">The thickness.</param>
    /// <param name="n">The index of refraction.</param>
    /// <param name="m">The constant multiple integers of order of
    /// interference..</param>
    /// <returns>wavelength</returns>
    static auto constructivelyReflectedWavelength(const ld t, const ld n, const ld m);

    /// <summary>
    /// A soap bubble is t units thick and illuminated by white light incident
    /// at a 45∘ to its surface. What wavelength and color of visible light is
    /// most constructively reflected, assuming the same index of refraction as
    /// water?
    /// </summary>
    /// <param name="t">The thickness.</param>
    /// <param name="n">The index of refraction.</param>
    /// <param name="m">The constant multiple of mOrder of interference.</param>
    /// <returns>wavelength</returns>
    static auto mostConstructivelyReflectedWavelength(const ld t, const ld n, const ld m);
    /// <summary>
    /// Waves the amplitude.
    /// </summary>
    /// <param name="E">The electric field amplitude.</param>
    /// <param name="Θ">The θ.</param>
    /// <returns></returns>
    static auto waveAmplitude(const ld E, const ld Θ);

    /// <summary>
    /// Calculates what angle is needed between the direction of polarized light
    /// and the axis of a polarizing filter to reduce its intensity by a specified
    /// percent. Use the percent value such as 90% you would enter 90 as the
    /// method argument and not .90.
    /// </summary>
    /// <param name="percentReduction">The percent reduction.</param>
    /// <returns>the angle the polarizing filter needs to be to filter
    /// out polarizing light waves.</returns>
    static auto angleForIntensityReductionByPolarizingFilter(const ld percentReduction);

    /// <summary>
    /// The building engineer installs new double paned polarizing sky lights
    /// to reduce the intensity of sunlight, which is non-polarized,
    /// calculate what angle the polarizing axis of the second pane of the window
    /// will make with the polarizing axis of the first pane of the window in order
    /// to reduce the intensity of the sunlight to percentReduction of the
    /// original value </summary>
    /// <param name="percentReduction">The percent reduction.</param>
    /// <returns>angle of second filter in relation to first</returns>
    static auto anglePolarizingAxis2ndFilter(const ld percentReduction);

    /// <summary>
    /// Calculates the angle using Brewster's law. tanΘ = n2/n1
    /// </summary>
    /// <param name="n1">The index of refraction for incident.</param>
    /// <param name="n2">The index of refraction for the medium of reflection.
    /// </param>
    /// <returns></returns>
    static auto angleByBrewstersLaw(const ld n1, const ld n2);

    /// <summary>
    /// Calculates index of refraction using Brewster's law solved for n1.
    /// </summary>
    /// <param name="n2">The index of refraction for the medium of reflection.
    /// </param>
    /// <param name="Θ">The angle θ.</param>
    /// <returns>The index of refraction for incident medium.</returns>
    static auto n1FromBrewstersLaw(const ld n2, const ld Θ);

    /// <summary>
    /// Calculates index of refraction using Brewster's law solved for n2.
    /// </summary>
    /// <param name="n1">The index of refraction for the incident medium.</param>
    /// <param name="Θ">The angle θ.</param>
    /// <returns>The index of refraction for the reflected medium.</returns>
    static auto n2FromBrewstersLaw(const ld n1, const ld Θ);

    /// <summary>
    /// Calculates the angle theta when the distance of x and height of y is
    /// known.
    /// </summary>
    /// <param name="x_len">Length of the x.</param>
    /// <param name="y_height">Height of the y.</param>
    /// <returns>angle theta</returns>
    static auto theta_toa_yx(const ld x_len, const ld y_height);

    /// <summary>
    /// light waves averaging  λ units in wavelength falls on a single slit of
    /// width D units.  Calculate the highest-order minimum produced.
    /// </summary>
    /// <param name="D">The d.</param>
    /// <param name="λ">The λ.</param>
    /// <returns></returns>
    static auto highestOrderMinimum_singleSlit(const ld D, const ld  λ);

    /// <summary>
    /// If a single slit produces a first minimum at Θ∘, Calculate at what
    /// angle the m order minimum is.
    /// </summary>
    /// <param name="m">The m-order minimum.</param>
    /// <param name="Θ">The angle theta of first order minimum.</param>
    /// <returns>angle at order m minimum</returns>
    static auto angleAt_nOrderMin(const ld m, const ld Θ);

    /// <summary>
    /// Angles at n order minimum single slit.
    /// </summary>
    /// <param name="m">The m.</param>
    /// <param name="D">The d.</param>
    /// <param name="λ">The λ.</param>
    /// <returns></returns>
    static auto angleAt_nOrderMinimum_singleSlit(const ld m, const ld D, const ld  λ);

    /// <summary>
    ///	t = ((m+1/2)*λ)/(2*n)
    /// Working on your car you spill oil (index of refraction = 1.55) on the
    /// ground into a puddle of water (n = 1.33). You notice a rainbow pattern
    /// appear across the oil slick.Recalling the lessons you learned in physics
    /// class, you realize you can calculate where constructive
    /// interference occurs based on the thickness of the oil slick.
    /// (Assume that the average wavelength is 584 nm.)
    /// </summary>
    /// <param name="n">The index of refraction.</param>
    /// <param name="mStart">The m starting of constructive interference.</param>
    /// <param name="mEnd">The m end.</param>
    /// <param name="λ">The wavelength λ.</param>
    /// <returns>a map of values of where constructive interference occurs</returns>
    static map<int, ld> constructiveInterferenceRange(const ld n, const int mStart, const int mEnd, const ld λ);

    /// <summary>
    /// t = (m*λ)/(2*n)
    /// Working on your car you spill oil (index of refraction = 1.55) on the
    /// ground into a puddle of water (n = 1.33). You notice a rainbow pattern
    /// appear across the oil slick.Recalling the lessons you learned in physics
    /// class, you realize you can calculate where destructive
    /// interference occurs based on the thickness of the oil slick.
    /// (Assume that the average wavelength is 584 nm.)
    /// </summary>
    /// <param name="n">The n.</param>
    /// <param name="mStart">The m start.</param>
    /// <param name="mEnd">The m end.</param>
    /// <param name="λ">The λ.</param>
    /// <returns></returns>
    static map<int, ld> destructiveInterferenceRange(const ld n, const int mStart, const int mEnd, const ld λ);




private:
    ld waveOpticsVar;
    static void countIncrease() { waveOptics_objectCount += 1; }
    static void countDecrease() { waveOptics_objectCount -= 1; }

};

#endif //PHYSICSFORMULA_WAVEOPTICS_H
//=============================================================================
//in-line class Implementation


inline auto WaveOptics::wavelengthInMedium(const ld λ, const ld n)
{
    return λ / n;//Hz
}

inline auto WaveOptics::wavelengthOfMedium(const ld n, const ld f)
{
    return _C_ / (n * f);
}

inline auto WaveOptics::wavelength_ratioOf2IndexOfRefractions(const ld nTop, const ld nBottom)
{
    return nTop / nBottom;
}

inline auto WaveOptics::distanceTraveledByWaveFront(const ld v, const ld t)
{
    return v * t;
}

inline auto WaveOptics::indexOfRefractionFromRatioPrintMedium(const ld xTimes)
{
    const auto val = 1.0 / xTimes;
    const auto scale = 0.001;
    const auto val2 = floor(val / scale + .5) * scale;
    printMedium(refractions, val2);
    return val2;
}

inline auto WaveOptics::indexOfRefractionFromWavelengths(const ld λMedium, const ld λ2)
{
    const auto temp = λ2 / λMedium;
    const auto scale = 0.001;
    const auto n = floor(temp / scale + .5) * scale;
    printMedium(refractions, n);
    return n;
}

inline auto WaveOptics::angleOf_nOrderOfInterference_doubleSlit(int m, const ld λ, const ld d)
{
    return asin((static_cast<ld>(m) * λ) / d) * DEGREE;
}

inline auto WaveOptics::separationBetweenSlits_doubleSlit(const int m, const ld λ, const ld Θ)
{
    return (static_cast<ld>(m) * λ) / sin(Θ * RADIAN);
}

inline auto WaveOptics::separationBetweenSlits_destructive(const int m, const ld λ, const ld Θ)
{
    return (((static_cast<ld>(m)-1) + (1 / 2)) * λ) / sin(Θ*RADIAN);
}

inline auto WaveOptics::wavelengthAt_nMinimum_doubleSlit(const int m, const ld d, const ld Θ)
{
    return (d * sin(Θ * RADIAN)) / ((m - 1.0) + (1 / 2));
}

inline auto WaveOptics::wavelengthAt_nOrderMaximum_doubleSlit(const ld nM, const ld d, const ld Θ)
{
    return (d * sin(Θ * RADIAN)) / nM;
}

inline auto WaveOptics::wavelength_nMinSingleSlit(const ld m, const ld D, const ld Θ)
{
    return (D * sin(Θ * RADIAN)) / m;
}

inline auto WaveOptics::wavelengthOfLight_nOrderMaxGrating(const ld m, const ld Θ, const ld s)
{
    const ld d = distanceBetweenGratingSlits(s, 1.0 * SU.CENTI);
    return (d * sin(Θ*RADIAN)) / m;
}

inline auto WaveOptics::highestOrderMaximum(const ld d, const ld λ, const ld Θ = 90)
{
    return floor( (d * sin(Θ * RADIAN)) / λ);
}

inline auto WaveOptics::angleOf_nOrderMaximum(const ld nM, const ld Θ)
{
    return asin(nM * sin(Θ * RADIAN))*DEGREE;
}

inline auto WaveOptics::angleOf_nMinimum(const ld nMin, const ld Θ)
{
    return asin(((nMin - 1.0) + (1.0 / 2.0)) * sin(Θ * RADIAN));
}

inline auto WaveOptics::highestOrderMaximum(const ld Θ)
{
    return floor(1.0 / sin(Θ * RADIAN));
}

inline auto WaveOptics::distanceBetweenFringes(const ld x, const ld λ, const ld d)
{
    return (x * λ) / d;
}

inline auto WaveOptics::wavelengthFromFringes(const ld x, const ld Δy, const ld d)
{
    return (Δy * d) / x;
}

inline auto WaveOptics::waveLengthAt_nOrderMFringe(const ld m, const ld y, const ld x, const ld d)
{
    return (y * d) / (m * x);
}

inline auto WaveOptics::fringeSeparationAt_nOrderMFromCenterDS(const ld m, const ld x, const ld λ, const ld d)
{
    return (m * x * λ) / d;
}


inline ld WaveOptics::distanceBetweenGratingSlits(const ld slits, const ld totalLength)
{
    return totalLength / slits;
}

inline auto WaveOptics::separationBetweenSlitsDiffractionGrating(const ld m, const ld λ, const ld Θ)
{
    return (m * λ) / sin(Θ*RADIAN);
}

inline auto WaveOptics::linesPer_cmDefractionGrating(const ld m, const ld λ, const ld Θ)
{
    return floor(1.0/((m * λ) / sin(Θ * RADIAN))*(1.0/100.0));
}

inline auto WaveOptics::thetaAtOrderOfInterference(const ld m, const ld d, const ld λ)
{
    return asin((m * λ) / d)*DEGREE;
}

inline auto WaveOptics::yDistanceApart(const ld x, const ld Θ)
{
    return x * tan(Θ*RADIAN);
}

inline auto WaveOptics::singleSlitWidth(const ld λ, const ld m, const ld Θ)
{
    return (m * λ) / sin(Θ*RADIAN);
}

inline auto WaveOptics::rayleighEquation(const ld λ, const ld D)
{
    return 1.22 * (λ / D);
}

inline auto WaveOptics::diffractionSpreadingTotal(const ld λ, const ld D, const ld x)
{
    const auto d = 1.22 * (λ / D);
    return D + (2 * x) * tan(d);
}

inline auto WaveOptics::s_distance2Obj_rApart(const ld r, const ld Θ)
{

    return r * Θ;
}

inline auto WaveOptics::minimumMirrorDiameter(const ld y, const ld x, const ld λ)
{
    const auto Θ = atan(y / x);
    return 1.22 * (λ / Θ);
}

inline auto WaveOptics::minimumAngularSeparation(const ld x, const ld d)
{
    return x / d;
}

inline auto WaveOptics::resolvingPower(const ld λ, const ld d, const ld D)
{
    return 1.22 * ((λ * d) / D);
}

inline auto WaveOptics::resolvingPower_microscopeLens(const ld λ, const ld n, const ld NA)
{
    return .61 * ((λ * n) / NA);
}

inline auto WaveOptics::thicknessOfNonReflectiveLensCoating(const ld λ, const ld n)
{
    return ((λ / n) / 4.0);
}

inline auto WaveOptics::thicknessOfThinnestCoating(const ld λ, const ld n, const ld m)
{
    return (λ / (4.0 * n)) * (2.0 * m - 1.0);
}

inline auto WaveOptics::thicknessOfCoating(const ld λ, const ld n, const ld m)
{
    return  (λ * (2.0 * m - 1)) / (4.0 * n);
}

inline auto WaveOptics::intensityOfTransmittedWave(const ld Io, const ld Θ)
{
    return Io * pow(cos(Θ), 2);
}

inline auto WaveOptics::constructivelyReflectedWavelength(const ld t, const ld n)
{
    return 4.0 * t * n;
}

inline auto WaveOptics::constructivelyReflectedWavelength(const ld t, const ld n, const ld m)
{
    return (4.0 * t * n) / (2.0 * (m)-1);
}

inline auto WaveOptics::mostConstructivelyReflectedWavelength(const ld t, const ld n, const ld m)
{
    return (4.0 * sqrt( (2.0) * t * n) / (2.0 * m - 1.0));
}

inline auto WaveOptics::waveAmplitude(const ld E, const ld Θ)
{
    return E * cos(Θ);
}

inline auto WaveOptics::angleForIntensityReductionByPolarizingFilter(const ld percentReduction)
{
    const ld I = (1.00 - (percentReduction / 100));
    return acos(sqrt(I / 1.0)) * DEGREE;
}

inline auto WaveOptics::anglePolarizingAxis2ndFilter(const ld percentReduction)
{
    const auto dec = percentReduction / 100.0;
    const auto temp = sqrt(2.0 * dec);
    return acos(temp) * DEGREE;
}

inline auto WaveOptics::angleByBrewstersLaw(const ld n1, const ld n2)
{
    return atan(n2 / n1)*DEGREE;
}

inline auto WaveOptics::n1FromBrewstersLaw(const ld n2, const ld Θ)
{
    return n2 / tan(Θ*RADIAN);
}

inline auto WaveOptics::n2FromBrewstersLaw(const ld n1, const ld Θ)
{
    return tan(Θ * RADIAN) * n1;
}

inline auto WaveOptics::theta_toa_yx(const ld x_len, const ld y_height)
{
    return atan(y_height / x_len);
}

inline auto WaveOptics::highestOrderMinimum_singleSlit(const ld D, const ld λ)
{
    return floor(D / λ);
}

inline auto WaveOptics::angleAt_nOrderMin(const ld m, const ld Θ)
{
    const auto ratio = sin(Θ * RADIAN)/1.0;
    return asin(m * ratio) * DEGREE;
}

inline auto WaveOptics::angleAt_nOrderMinimum_singleSlit(const ld m, const ld D, const ld λ)
{
    return asin((m * λ) / D) * DEGREE;
}

inline map<int, ld> WaveOptics::constructiveInterferenceRange(const ld n, const int mStart, const int mEnd, const ld λ)
{
    map<int, ld> results;
    for (int i = mStart, j = 1; i < mEnd; i++, j++)
    {
        auto val = ((i + .5) * λ / (2.0 * n));
        results[j] = val;
    }
    return results;
}

inline map<int, ld> WaveOptics::destructiveInterferenceRange(const ld n, const int mStart, const int mEnd, const ld λ)
{
    map<int, ld> results;
    for (int i = mStart, j = 1; i < mEnd; i++, j++)
    {
        auto val = ((i ) * λ / (2.0 * n));
        results[j] = val;
    }
    return results;
}