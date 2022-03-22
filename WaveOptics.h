//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_WAVEOPTICS_H
#define PHYSICSFORMULA_WAVEOPTICS_H
#include "GeometricOptics.h"
#include <cmath>
#include <iostream>
//α=224,ß=225,π=227,Σ=228,σ=229,µ=230,τ=231,Φ=232,theta=233
//Ω=234,delta=235,∞=236,φ=237,ε=238,∩=239,≡=240,Γ=226,γ, σ, theta, Å, Ώ, lambda, γ
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
    /// Calculates the wavelength in a medium when the lamda in a vacuum is lamda and
    /// the index of refraction of the medium is n.
    /// </summary>
    /// <param name="lamda">The wavelength in a vacuum.</param>
    /// <param name="n">The index of refraction.</param>
    /// <returns>the wavelength in a medium</returns>
    static auto wavelengthInMedium(const ld lamda, const ld n);

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
    /// <param name="lambdaMid">The w l medium.</param>
    /// <param name="lambda2">The w l2.</param>
    /// <returns></returns>
    static auto indexOfRefractionFromWavelengths(const ld lambdaMid, const ld lambda2);

    /// <summary>
    /// Calculates the angle of the n order of maximum for lambda wavelength
    /// of light falling on double slits separated by d (m)?
    /// </summary>
    /// <param name="m">The order of interference: 0, 1, -1, 2, -2.....</param>
    /// <param name="lambda">The wavelength.</param>
    /// <param name="d">The distance between slits.</param>
    /// <returns>the angle theta</returns>
    static auto angleOf_nOrderOfInterference_doubleSlit(int m, const ld lambda, const ld d);

    /// <summary>
    ///Calculates the separation between two slits for which a wavelength of lambda
    /// light has its first maximum at an angle of theta∘.
    /// </summary>
    /// <param name="m">The order of interference: 0, 1, -1, 2, -2.....</param>
    /// <param name="lambda">The wavelength.</param>
    /// <param name="theta">The angle theta.</param>
    /// <returns>separation between slits (units)</returns>
    static auto separationBetweenSlits_doubleSlit(const int m, const ld lambda, const ld theta);

    /// <summary>
    /// Calculates the distance between two slits that produces the first minimum
    /// for lambda(m) of light at an angle of theta∘
    /// </summary>
    /// <param name="m">The order of interference: 0, 1, -1, 2, -2....</param>
    /// <param name="lambda">The w l.</param>
    /// <param name="theta">The theta.</param>
    /// <returns></returns>
    static auto separationBetweenSlits_destructive(const int m, const ld lambda, const ld theta);

    /// <summary>
    /// Calculates the wavelength of light that has its m minimum at an
    /// angle of theta∘ when falling on double slits separated by d(units).
    /// </summary>
    /// <param name="m">The minimum.</param>
    /// <param name="d">The distance between slits.</param>
    /// <param name="theta">The angle theta.</param>
    /// <returns>the wavelength (units)</returns>
    static auto wavelengthAt_nMinimum_doubleSlit(const int m, const ld d, const ld theta);

    /// <summary>
    /// Calculates the wavelength of light falling on double slits separated by
    /// d units, if the nM maximum is at an angle of theta∘.
    /// </summary>
    /// <param name="nM">The order of maximum.</param>
    /// <param name="d">The distance between slits.</param>
    /// <param name="theta">The angle theta.</param>
    /// <returns>wavelength</returns>
    static auto wavelengthAt_nOrderMaximum_doubleSlit(const ld nM, const ld d, const ld theta);

    /// <summary>
    /// Calculates the wavelength of light that has its m minimum at an angle
    /// of theta∘ when it falls on a single slit of width D units.
    /// </summary>
    /// <param name="m">The order of minimum.</param>
    /// <param name="D">The width of slit.</param>
    /// <param name="theta">The angle theta.</param>
    /// <returns>wavelength</returns>
    static auto wavelength_nMinSingleSlit(const ld m, const ld D, const ld theta);

    /// <summary>
    /// Calculates the wavelength of light that has its m-order maximum at angle theta,
    /// when falling on a diffraction grating that has a total of s slits per centimeter.
    /// </summary>
    /// <param name="m">The order of interference </param>
    /// <param name="theta">The angle theta.</param>
    /// <param name="s">The number of slits per cm.</param>
    /// <returns>the wavelength</returns>
    static auto wavelengthOfLight_nOrderMaxGrating(const ld m, const ld theta, const ld s);

    /// <summary>
    /// What is the highest-order maximum for light with a wavelength of lambda
    /// falling on double slits separated by d units.
    /// </summary>
    /// <param name="d">The distance of separation between slits.</param>
    /// <param name="lambda">The wavelength.</param>
    /// <param name="theta">The angle theta is default at 90 degrees which
    /// would be thrush hold angle that would cause a maximum order.</param>
    /// <returns>m= order of interference</returns>
    static auto highestOrderMaximum(const ld d, const ld lambda, const ld theta);

    /// <summary>
    /// Calculates angle at nM order maximum, if the first-order maximum for pure-wavelength light
    /// falling on a double slit is at an angle of theta∘
    /// nM-order maximum
    /// </summary>
    /// <param name="nM">The n m.</param>
    /// <param name="theta">The theta.</param>
    /// <returns>angle of theta at nM maximum</returns>
    static auto angleOf_nOrderMaximum(const ld nM, const ld theta);

    /// <summary>
    /// Calculates the angle of the nMim minimum, if the first-order minimum
    /// for pure-wavelength light falling on a double slit is at an angle of theta∘
    /// </summary>
    /// <param name="nMin">The n minimum.</param>
    /// <param name="theta">The theta.</param>
    /// <returns>angle theta at n minimum</returns>
    static auto angleOf_nMinimum(const ld nMin, const ld theta);

    /// <summary>
    /// Calculates the highest order maximum, If the first-order maximum for pure-wavelength
    /// light falling on a double slit at an angle of theta.
    /// </summary>
    /// <param name="theta">The first order maximum theta.</param>
    /// <returns>highest order of maximum</returns>
    static auto highestOrderMaximum(const ld theta);

    /// <summary>
    /// Using deltay=x*lambda*d, calculate the distance between fringes for 633-nm light
    /// falling on double slits separated by 0.0800 mm, located 3.00 m from a
    /// screen as in Figure
    /// </summary>
    /// <param name="x">The x.</param>
    /// <param name="lambda">The w l.</param>
    /// <param name="d">The d.</param>
    /// <returns></returns>
    static auto distanceBetweenFringes(const ld x, const ld lambda, const ld d);

    /// <summary>
    /// Calculate the wavelength of light that produces fringes deltay units
    /// apart on a screen x units from double slits separated by d units.
    /// </summary>
    /// <param name="x">The x.</param>
    /// <param name="deltay">The deltay.</param>
    /// <param name="d">The d.</param>
    /// <returns>distance between fringes on screen</returns>
    static auto wavelengthFromFringes(const ld x, const ld deltay, const ld d);

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
    /// Your professor shines a green laser (lambda units) on a double slit with a
    /// separation of d units. The diffraction pattern shines on the classroom
    /// wall x units away. Calculate the fringe separation between the m order
    /// and central fringe.
    /// </summary>
    /// <param name="m">The m.</param>
    /// <param name="x">The x.</param>
    /// <param name="lambda">The lambda.</param>
    /// <param name="d">The d.</param>
    /// <returns></returns>
    static auto fringeSeparationAt_nOrderMFromCenterDS(const ld m, const ld x, const ld lambda, const ld d);

    /// <summary>
    /// Distances the between grating slits.
    /// </summary>
    /// <param name="slits">The slits.</param>
    /// <param name="totalLength">The total length in meters.</param>
    /// <returns>distance between the slits in meters</returns>
    static ld distanceBetweenGratingSlits(const ld slits, const ld totalLength);

    /// <summary>
    /// Calculates the distance between lines on a diffraction grating that
    /// produces a m-order maximum for lambda-nm light at an angle of theta∘.
    /// </summary>
    /// <param name="m">The order of interference.</param>
    /// <param name="lambda">The wavelength lambda.</param>
    /// <param name="theta">The angle theta.</param>
    /// <returns>distance between lines in a diffraction grating</returns>
    static auto separationBetweenSlitsDiffractionGrating(const ld m, const ld  lambda, const ld theta);

    /// <summary>
    /// Calculates how many lines per centimeter are there on a diffraction
    /// grating that gives a m-order maximum for lambda-m light at an angle of theta.
    /// </summary>
    /// <param name="m">The order of interference.</param>
    /// <param name="lambda">The wavelength lambda.</param>
    /// <param name="theta">The angle theta.</param>
    /// <returns>how many lines per centimeter in a diffraction grating</returns>
    static auto linesPer_cmDefractionGrating(const ld m, const ld lambda, const ld theta);

    /// <summary>
    /// Calculates the value of theta with a order m interference.
    /// </summary>
    /// <param name="m">The order of interference.</param>
    /// <param name="d">The distance between slits.</param>
    /// <param name="lambda">The wavelength .</param>
    /// <returns>the angle of theta</returns>
    static auto thetaAtOrderOfInterference(const ld m, const ld d, const ld lambda);

    /// <summary>
    /// Calculates the distance from a desired wave length to the central location
    /// </summary>
    /// <param name="x">The x-direction distance.</param>
    /// <param name="theta">The angle theta.</param>
    /// <returns>the length from the center to the where a wavelength fringe
    /// intersects on the screen</returns>
    static auto yDistanceApart(const ld x, const ld theta);

    /// <summary>
    /// Calculates the width of a single slit.
    /// </summary>
    /// <param name="lambda">The wavelength lambda.</param>
    /// <param name="m">The order of interference m.</param>
    /// <param name="theta">The angle theta theta.</param>
    /// <returns>width of slit</returns>
    static auto singleSlitWidth(const ld lambda, const ld m, const ld theta);

    /// <summary>
    /// Uses the Rayleigh criterion to solve for the minimum resolvable angle.
    /// between two objects where  lambda is the wavelength of light and D is the
    /// diameter of aperture.
    /// </summary>
    /// <param name="lambda">The wavelength lambda.</param>
    /// <param name="D">The diameter of aperture.</param>
    /// <returns>the minimum angle between two objects that produce a resolvable
    /// image</returns>
    static auto rayleighEquation(const ld lambda, const ld D);

    /// <summary>
    /// A telescope can be used to enlarge the diameter of a laser beam and
    /// limit diffraction spreading. The laser beam is sent through the telescope
    /// in opposite the normal direction and can then be projected onto a
    /// satellite or the Moon. If this is done with the
    /// telescope, producing a D-m-diameter beam of lambda-nm light, neglecting atmospheric
    /// effects, calculate is the size of the spot this beam would make on the Moon,
    /// assuming a distance of x m?
    /// </summary>
    /// <param name="lambda">The wave length lambda.</param>
    /// <param name="D">The diameter of beam.</param>
    /// <param name="x">The distance away.</param>
    /// <returns>the total diffraction spreading of beam on object</returns>
    static auto diffractionSpreadingTotal(const ld lambda, const ld D, const ld x);

    /// <summary>
    /// calculates the distance s between two object a distance r away and
    /// separated by an angle theta.
    /// </summary>
    /// <param name="r">The distance away in any units.</param>
    /// <param name="theta">The angle theta.</param>
    /// <returns>distance the two objects are apart</returns>
    static auto s_distance2Obj_rApart(const ld r, const ld theta);

    /// <summary>
    /// What is the minimum diameter mirror on a looking scope that would allow
    /// you to see details as small as y units apart on a object some x units
    /// away? Assume an average wavelength of lambda units for the light received.
    /// </summary>
    /// <param name="y">The separation between objects being viewed.</param>
    /// <param name="x">The distance away.</param>
    /// <param name="lambda">The wavelength.</param>
    /// <returns>size of mirror in looking device</returns>
    static auto minimumMirrorDiameter(const ld y, const ld x, const ld lambda);

    /// <summary>
    /// Uses the Rayleigh criterion to calculate where resolution is still possible
    /// looking through a microscope for which the minimum angular separation where
    /// d is the distance between the specimen and the objective lens, and we have used the small
    /// angle approximation assuming that x is much smaller then d, so that
    /// that tantheta = sin theta == theta. so x is the resolving power from the resolving
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
    /// <param name="lambda">The wavelength lambda.</param>
    /// <param name="d">The  distance between the specimen and the
    /// objective lens.</param>
    /// <param name="D">The diameter of aperture.</param>
    /// <returns>resolving power</returns>
    static auto resolvingPower(const ld lambda, const ld d, const ld D);

    /// <summary>
    /// Calculates the resolving  power for a microscope lens.
    /// </summary>
    /// <param name="lambda">The wavelength lambda.</param>
    /// <param name="n">The index of refraction between the lens and the object
    /// .</param>
    /// <param name="NA">The Numerical Aperture.</param>
    /// <returns></returns>
    static auto resolvingPower_microscopeLens(const ld lambda, const ld n, const ld NA);

    /// <summary>
    /// Calculates the thinnest thickness of a non reflective lens coating.
    /// </summary>
    /// <param name="lambda">The lambda.</param>
    /// <param name="n">The index of refraction of film.</param>
    /// <returns>thinnest thickness of coating</returns>
    static auto thicknessOfNonReflectiveLensCoating(const ld lambda, const ld n);

    /// <summary>
    /// Suppose you have a lens(n= 1.52) system that is to be used primarily for lambda-nm
    /// light. What is the second thinnest coating of (n)fluorite(n=1.38)
    /// (magnesium fluoride) that would be non- reflective for this wavelength?
    /// this uses the fact that there are two lambda/2 phase shifts as the light
    /// travels from air91.00) into the fluorite(1.38) then to glass lens(1.52),
    /// with the second phase shift having an additional distance to travel as
    /// well being a total of lambda/2 + ((2*thickness)/lambda_n)*lambda = lambda/2 + 2*t*n after
    /// substituting in lambda_n = lambda/n which we will multiply instead because its
    /// being divided in the originally so this allows us to cancel the lambda out
    /// of the formula completely.
    /// </summary>
    /// <param name="lambda">The wave length of light trying to be blocked </param>
    /// <param name="n">The index of refraction of the coating.</param>
    /// <param name="m">The multiple integers of interference that cause
    /// a destructive interference.</param>
    /// <returns></returns>
    static auto thicknessOfThinnestCoating(const ld lambda, const ld n, const ld m);

    /// <summary>
    /// To save money on making military aircraft invisible to radar, an inventor
    /// decides to coat them with a non-reflective material having an index of
    /// refraction of 1.20, which is between that of air and the surface of the
    /// plane. This, he reasons, should be much cheaper than designing Stealth
    /// bombers. Calculates What thickness should the coating be to inhibit the
    /// reflection of 4.00-cm wavelength radar.
    /// </summary>
    /// <param name="lambda">The lambda.</param>
    /// <param name="n">The n.</param>
    /// <param name="m">The m.</param>
    /// <returns>thickness</returns>
    static auto thicknessOfCoating(const ld lambda, const ld n, const ld m);

    /// <summary>
    /// Malus's law used to calculate the intensity of a polarized wave after
    /// passing through a filter. Where Io is the incident wave and theta is the angle
    /// between the direction of polarization and the axis of a filter.
    /// </summary>
    /// <param name="Io">The intensity of polarized wave.</param>
    /// <param name="theta">The theta.</param>
    /// <returns>intensity of wave</returns>
    static auto intensityOfTransmittedWave(const ld Io, const ld theta);

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
    /// <param name="theta">The theta.</param>
    /// <returns></returns>
    static auto waveAmplitude(const ld E, const ld theta);

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
    /// Calculates the angle using Brewster's law. tantheta = n2/n1
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
    /// <param name="theta">The angle theta.</param>
    /// <returns>The index of refraction for incident medium.</returns>
    static auto n1FromBrewstersLaw(const ld n2, const ld theta);

    /// <summary>
    /// Calculates index of refraction using Brewster's law solved for n2.
    /// </summary>
    /// <param name="n1">The index of refraction for the incident medium.</param>
    /// <param name="theta">The angle theta.</param>
    /// <returns>The index of refraction for the reflected medium.</returns>
    static auto n2FromBrewstersLaw(const ld n1, const ld theta);

    /// <summary>
    /// Calculates the angle theta when the distance of x and height of y is
    /// known.
    /// </summary>
    /// <param name="x_len">Length of the x.</param>
    /// <param name="y_height">Height of the y.</param>
    /// <returns>angle theta</returns>
    static auto theta_toa_yx(const ld x_len, const ld y_height);

    /// <summary>
    /// light waves averaging  lambda units in wavelength falls on a single slit of
    /// width D units.  Calculate the highest-order minimum produced.
    /// </summary>
    /// <param name="D">The d.</param>
    /// <param name="lambda">The lambda.</param>
    /// <returns></returns>
    static auto highestOrderMinimum_singleSlit(const ld D, const ld  lambda);

    /// <summary>
    /// If a single slit produces a first minimum at theta∘, Calculate at what
    /// angle the m order minimum is.
    /// </summary>
    /// <param name="m">The m-order minimum.</param>
    /// <param name="theta">The angle theta of first order minimum.</param>
    /// <returns>angle at order m minimum</returns>
    static auto angleAt_nOrderMin(const ld m, const ld theta);

    /// <summary>
    /// Angles at n order minimum single slit.
    /// </summary>
    /// <param name="m">The m.</param>
    /// <param name="D">The d.</param>
    /// <param name="lambda">The lambda.</param>
    /// <returns></returns>
    static auto angleAt_nOrderMinimum_singleSlit(const ld m, const ld D, const ld  lambda);

    /// <summary>
    ///	t = ((m+1/2)*lambda)/(2*n)
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
    /// <param name="lambda">The wavelength lambda.</param>
    /// <returns>a map of values of where constructive interference occurs</returns>
    static map<int, ld> constructiveInterferenceRange(const ld n, const int mStart, const int mEnd, const ld lambda);

    /// <summary>
    /// t = (m*lambda)/(2*n)
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
    /// <param name="lambda">The lambda.</param>
    /// <returns></returns>
    static map<int, ld> destructiveInterferenceRange(const ld n, const int mStart, const int mEnd, const ld lambda);




private:
    ld waveOpticsVar;
    static void countIncrease() { waveOptics_objectCount += 1; }
    static void countDecrease() { waveOptics_objectCount -= 1; }

};

#endif //PHYSICSFORMULA_WAVEOPTICS_H
//=============================================================================
//in-line class Implementation


inline auto WaveOptics::wavelengthInMedium(const ld lamda, const ld n)
{
    return lamda / n;//Hz
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

inline auto WaveOptics::indexOfRefractionFromWavelengths(const ld lambdaMid, const ld lambda2)
{
    const auto temp = lambda2 / lambdaMid;
    const auto scale = 0.001;
    const auto n = floor(temp / scale + .5) * scale;
    printMedium(refractions, n);
    return n;
}

inline auto WaveOptics::angleOf_nOrderOfInterference_doubleSlit(int m, const ld lambda, const ld d)
{
    return asin((static_cast<ld>(m) * lambda) / d) * DEGREE;
}

inline auto WaveOptics::separationBetweenSlits_doubleSlit(const int m, const ld lambda, const ld theta)
{
    return (static_cast<ld>(m) * lambda) / sin(theta * RADIAN);
}

inline auto WaveOptics::separationBetweenSlits_destructive(const int m, const ld lambda, const ld theta)
{
    return (((static_cast<ld>(m)-1) + (1 / 2)) * lambda) / sin(theta*RADIAN);
}

inline auto WaveOptics::wavelengthAt_nMinimum_doubleSlit(const int m, const ld d, const ld theta)
{
    return (d * sin(theta * RADIAN)) / ((m - 1.0) + (1 / 2));
}

inline auto WaveOptics::wavelengthAt_nOrderMaximum_doubleSlit(const ld nM, const ld d, const ld theta)
{
    return (d * sin(theta * RADIAN)) / nM;
}

inline auto WaveOptics::wavelength_nMinSingleSlit(const ld m, const ld D, const ld theta)
{
    return (D * sin(theta * RADIAN)) / m;
}

inline auto WaveOptics::wavelengthOfLight_nOrderMaxGrating(const ld m, const ld theta, const ld s)
{
    const ld d = distanceBetweenGratingSlits(s, 1.0 * SU.CENTI);
    return (d * sin(theta*RADIAN)) / m;
}

inline auto WaveOptics::highestOrderMaximum(const ld d, const ld lambda, const ld theta = 90)
{
    return floor( (d * sin(theta * RADIAN)) / lambda);
}

inline auto WaveOptics::angleOf_nOrderMaximum(const ld nM, const ld theta)
{
    return asin(nM * sin(theta * RADIAN))*DEGREE;
}

inline auto WaveOptics::angleOf_nMinimum(const ld nMin, const ld theta)
{
    return asin(((nMin - 1.0) + (1.0 / 2.0)) * sin(theta * RADIAN));
}

inline auto WaveOptics::highestOrderMaximum(const ld theta)
{
    return floor(1.0 / sin(theta * RADIAN));
}

inline auto WaveOptics::distanceBetweenFringes(const ld x, const ld lambda, const ld d)
{
    return (x * lambda) / d;
}

inline auto WaveOptics::wavelengthFromFringes(const ld x, const ld deltay, const ld d)
{
    return (deltay * d) / x;
}

inline auto WaveOptics::waveLengthAt_nOrderMFringe(const ld m, const ld y, const ld x, const ld d)
{
    return (y * d) / (m * x);
}

inline auto WaveOptics::fringeSeparationAt_nOrderMFromCenterDS(const ld m, const ld x, const ld lambda, const ld d)
{
    return (m * x * lambda) / d;
}


inline ld WaveOptics::distanceBetweenGratingSlits(const ld slits, const ld totalLength)
{
    return totalLength / slits;
}

inline auto WaveOptics::separationBetweenSlitsDiffractionGrating(const ld m, const ld lambda, const ld theta)
{
    return (m * lambda) / sin(theta*RADIAN);
}

inline auto WaveOptics::linesPer_cmDefractionGrating(const ld m, const ld lambda, const ld theta)
{
    return floor(1.0/((m * lambda) / sin(theta * RADIAN))*(1.0/100.0));
}

inline auto WaveOptics::thetaAtOrderOfInterference(const ld m, const ld d, const ld lambda)
{
    return asin((m * lambda) / d)*DEGREE;
}

inline auto WaveOptics::yDistanceApart(const ld x, const ld theta)
{
    return x * tan(theta*RADIAN);
}

inline auto WaveOptics::singleSlitWidth(const ld lambda, const ld m, const ld theta)
{
    return (m * lambda) / sin(theta*RADIAN);
}

inline auto WaveOptics::rayleighEquation(const ld lambda, const ld D)
{
    return 1.22 * (lambda / D);
}

inline auto WaveOptics::diffractionSpreadingTotal(const ld lambda, const ld D, const ld x)
{
    const auto d = 1.22 * (lambda / D);
    return D + (2 * x) * tan(d);
}

inline auto WaveOptics::s_distance2Obj_rApart(const ld r, const ld theta)
{

    return r * theta;
}

inline auto WaveOptics::minimumMirrorDiameter(const ld y, const ld x, const ld lambda)
{
    const auto theta = atan(y / x);
    return 1.22 * (lambda / theta);
}

inline auto WaveOptics::minimumAngularSeparation(const ld x, const ld d)
{
    return x / d;
}

inline auto WaveOptics::resolvingPower(const ld lambda, const ld d, const ld D)
{
    return 1.22 * ((lambda * d) / D);
}

inline auto WaveOptics::resolvingPower_microscopeLens(const ld lambda, const ld n, const ld NA)
{
    return .61 * ((lambda * n) / NA);
}

inline auto WaveOptics::thicknessOfNonReflectiveLensCoating(const ld lambda, const ld n)
{
    return ((lambda / n) / 4.0);
}

inline auto WaveOptics::thicknessOfThinnestCoating(const ld lambda, const ld n, const ld m)
{
    return (lambda / (4.0 * n)) * (2.0 * m - 1.0);
}

inline auto WaveOptics::thicknessOfCoating(const ld lambda, const ld n, const ld m)
{
    return  (lambda * (2.0 * m - 1)) / (4.0 * n);
}

inline auto WaveOptics::intensityOfTransmittedWave(const ld Io, const ld theta)
{
    return Io * pow(cos(theta), 2);
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

inline auto WaveOptics::waveAmplitude(const ld E, const ld theta)
{
    return E * cos(theta);
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

inline auto WaveOptics::n1FromBrewstersLaw(const ld n2, const ld theta)
{
    return n2 / tan(theta*RADIAN);
}

inline auto WaveOptics::n2FromBrewstersLaw(const ld n1, const ld theta)
{
    return tan(theta * RADIAN) * n1;
}

inline auto WaveOptics::theta_toa_yx(const ld x_len, const ld y_height)
{
    return atan(y_height / x_len);
}

inline auto WaveOptics::highestOrderMinimum_singleSlit(const ld D, const ld lambda)
{
    return floor(D / lambda);
}

inline auto WaveOptics::angleAt_nOrderMin(const ld m, const ld theta)
{
    const auto ratio = sin(theta * RADIAN)/1.0;
    return asin(m * ratio) * DEGREE;
}

inline auto WaveOptics::angleAt_nOrderMinimum_singleSlit(const ld m, const ld D, const ld lambda)
{
    return asin((m * lambda) / D) * DEGREE;
}

inline map<int, ld> WaveOptics::constructiveInterferenceRange(const ld n, const int mStart, const int mEnd, const ld lambda)
{
    map<int, ld> results;
    for (int i = mStart, j = 1; i < mEnd; i++, j++)
    {
        auto val = ((i + .5) * lambda / (2.0 * n));
        results[j] = val;
    }
    return results;
}

inline map<int, ld> WaveOptics::destructiveInterferenceRange(const ld n, const int mStart, const int mEnd, const ld lambda)
{
    map<int, ld> results;
    for (int i = mStart, j = 1; i < mEnd; i++, j++)
    {
        auto val = ((i ) * lambda / (2.0 * n));
        results[j] = val;
    }
    return results;
}