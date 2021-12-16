//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_SPECIALRELATIVITY_H
#define PHYSICSFORMULA_SPECIALRELATIVITY_H
/**
 * class: SpecialRelativity
 * details: driver class for solving complex physics problems
 * author: Ryan Zurrin
 * dateBuilt:  5/3/2021
 * lastEdit: 5/15/2021
 */
//α=224,ß=225,π=227,Σ=228,σ=229,µ=230,τ=231,Φ=232,Θ=233
//Ω=234,δ=235,∞=236,φ=237,ε=238,∩=239,≡=240,Γ=226,γ, σ, ϑ, Å, Ώ, λ, γ

#include <iostream>

#include "VisionOpticalInstruments.h"
static int specialRelativity_objectCount = 0;
typedef long double ld;

inline static auto lFactor = []<class T>(const T & v) {
    const auto γ = 1.0 / sqrt(1.0 - (v * v));
    std::cout << "gamma: "<< γ;
    return γ;
};


class SpecialRelativity:
        public VisionOpticalInstruments
{
public:
    SpecialRelativity* _specialRelativityPtr;

    SpecialRelativity()
    {
        _specialRelativityPtr = nullptr;
        specialRelativityVar = 0.0;
        countIncrease();
    }

    /**
     * @brief copy constructor
     */
    SpecialRelativity(const SpecialRelativity& t)
    {
        _specialRelativityPtr = t._specialRelativityPtr;
        specialRelativityVar = t.specialRelativityVar;
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    SpecialRelativity(SpecialRelativity&& t) noexcept
    {
        _specialRelativityPtr = t._specialRelativityPtr;
        specialRelativityVar = t.specialRelativityVar;
        countIncrease();
    }
    /**
     * @brief copy assignment operator
     */
    SpecialRelativity& operator=(SpecialRelativity&& t) noexcept
    {
        if (this != &t)
        {
            _specialRelativityPtr = t._specialRelativityPtr;
            specialRelativityVar = t.specialRelativityVar;
            countIncrease();
        }
        return *this;
    }

    static void show_objectCount() { std::cout << "\n special relativity object count: "
                                               << specialRelativity_objectCount << std::endl; }
    static int get_objectCount() { return specialRelativity_objectCount; }

    /// <summary>
    /// Calculates the Lorentz factor(γ) if v is a decimal of the percent of the
    /// speed of light, for instance if something was going half the speed of
    /// light you would put a value of .500 for v.
    /// </summary>
    /// <param name="ν">The velocity .</param>
    /// <returns>Lorentz factor, gamma (γ)</returns>
    template<typename T>
    static constexpr auto lorentzFactor(const T ν);


    /// <summary>
    /// Find the value of γ(gamma) for the following situation. An Earth-bound
    /// observer measures t h to have passed while signals from a high-velocity
    /// space probe indicate that t_o h have passed on board.
    /// </summary>
    /// <param name="t">The relativistic time(should be greater then proper).</param>
    /// <param name="t_o">The proper time.</param>
    /// <returns>value of gamma, Lorentz factor</returns>
    template<typename T, typename K>
    static constexpr auto lorentzValue(const T t, const K t_o);

    /// <summary>
    /// Particles called π-mesons are produced by accelerator beams. If these
    /// particles travel at v m/s and live t s when at rest
    /// relative to an observer, this method will calculate how long they
    /// live as viewed in the laboratory?
    /// </summary>
    /// <param name="ν">The speed of particle.</param>
    /// <param name="t_o">The time in seconds particle can live.</param>
    /// <returns>relativistic time alive is seconds, time dilation</returns>
    template<typename T, typename K>
    static constexpr auto relativisticTimeDilation(const T ν, const K t_o);

    /// <summary>
    /// Suppose a particle called a kaon is created by cosmic radiation striking
    /// the atmosphere. It moves by you at vc, and it lives t s when
    /// at rest relative to an observer. How long does it live as you observe it?
    /// </summary>
    /// <param name="ν">The velocity .</param>
    /// <param name="t_o">The relatively observed time.</param>
    /// <returns>time from observers perspective</returns>
    template<typename T, typename K>
    static constexpr auto timeDilation(const T νc, const K t_o);

    /// <summary>
    /// A neutral π-meson is a particle that can be created by accelerator
    /// beams. If one such particle lives t s as measured in the
    /// laboratory, and t_o s when at rest relative to an observer,
    /// what is its velocity relative to the laboratory?
    /// </summary>
    /// <param name="t">The observed time.</param>
    /// <param name="t_o">The proper time, time at rest.</param>
    /// <returns>speed relative to the observed time</returns>
    template<typename T, typename K>
    static constexpr auto relativeVelocity(const T t, const K t_o);

    /// <summary>
    /// If relativistic effects are to be less than percent_γ %, then γ must be less
    /// than x = 1.00 + %. At what relative velocity is γ=x
    /// </summary>
    /// <param name="percent_γ">The percent of Lorentz(γ).</param>
    /// <returns>speed to achieve desired percent of Lorentz factor</returns>
    template<typename T>
    static constexpr auto relativeVelocity_percentLorentz(const T percent_γ);

    /// <summary>
    /// Calculate at what relative velocity is gamma= γ
    /// </summary>
    /// <param name="γ">The γ.</param>
    /// <returns></returns>
    template<typename T>
    static constexpr auto relativeVelocity_lorantzAt(const T γ);

    /// <summary>
    /// A neutron lives t_o s when at rest relative to an observer. How fast
    /// is the neutron moving relative to an observer who measures its life
    /// span to be t s?
    /// </summary>
    /// <param name="t">The time at rest with respect to observer(proper time).</param>
    /// <param name="t_o">The observed time.</param>
    /// <returns>speed of particle as measured by while being observed in
    /// under proper time</returns>
    template<typename T, typename K>
    static constexpr auto observedVelocity(const T t, const K t_o);


    /// <summary>
    /// A spaceship, L_o m long as seen on board, moves by the Earth at vc.
    /// (.950 = .950c) ->leave out the c but this is what % of the speed of
    /// light something is traveling.
    /// What is its length as measured by an Earth-bound observer?
    /// </summary>
    /// <param name="L_o">The actual length.</param>
    /// <param name="vc">The velocity relative to light speed c.</param>
    /// <returns>observed length, relativistic length</returns>
    template<typename T, typename K>
    static constexpr auto lengthContraction(const T L_o, const K vc);

    /// <summary>
    /// How fast would a l_o m-long sports car have to be going past you in
    /// order for it to appear only l m long?
    /// </summary>
    /// <param name="l_o">The original length, real length.</param>
    /// <param name="l">The relativistic length.</param>
    /// <returns>velocity to appear length</returns>
    template<typename T, typename K>
    static constexpr auto speedToAppearSomeLength(const T l_o, const K l);

    /// <summary>
    /// Suppose a cosmic ray colliding with a nucleus in the Earth’s upper
    /// atmosphere produces a muon that has a velocity v=0.950c(vc). The muon then
    /// travels at constant velocity and lives 1.52μs(t_o) as measured in the muon’s
    /// frame of reference. (You can imagine this as the muon’s internal clock.)
    /// How long does the muon live as measured by an Earth-bound observer?
    /// </summary>
    /// <param name="t_o">The t o.</param>
    /// <param name="vc">The vc.</param>
    /// <returns>distance traveled by particle from stationary observers
    /// perspective</returns>
    template<typename T, typename K>
    static constexpr auto distanceTraveled_earthBoundObserver(const T t_o, const K vc);

    /// <summary>
    /// Suppose a cosmic ray colliding with a nucleus in the Earth’s upper
    /// atmosphere produces a muon that has a velocity v=0.950c(vc). The muon then
    /// travels at constant velocity and lives 1.52μs(t_o) as measured in the muon’s
    /// frame of reference. (You can imagine this as the muon’s internal clock.)
    /// How far does it travel as viewed by an observer moving with it?
    /// Base your calculation on its velocity relative to the Earth and the
    /// time it lives (proper time)
    /// </summary>
    /// <param name="t_o">The t o.</param>
    /// <param name="vc">The vc.</param>
    /// <returns>distance traveled (m)</returns>
    template<typename T, typename K>
    static constexpr auto distanceTraveled_proper(const T t_o, const K vc);


    /// <summary>
    /// Verify that two distances are related through length contraction
    /// if gamma = γ.
    /// </summary>
    /// <param name="l_o">The proper length.</param>
    /// <param name="γ">The γ.</param>
    /// <returns>contracted length</returns>
    template<typename T, typename K>
    static constexpr auto contractedLength(const T l_o, const K γ);

    /// <summary>
    ///  How long does it take the astronaut  to travel
    ///  l_o units at vc units of speed (as measured by the Earth- bound observer)
    /// </summary>
    /// <param name="l_o">The proper length.</param>
    /// <param name="vc">The velocity with respect to speed of light.</param>
    /// <returns>time to travel some distance</returns>
    template<typename T, typename K>
    static constexpr auto time(const T l_o, const K vc);

    /// <summary>
    /// How long does it take a astronaut to travel t units at a speed of vc units
    /// according to the astronaut, which is proper time
    /// </summary>
    /// <param name="t">The relativistic time.</param>
    /// <param name="vc">The speed.</param>
    /// <returns>proper time</returns>
    template<typename T, typename K>
    static constexpr auto properTime(const T t, const K vc);

    /// <summary>
    /// Verify time is related through time dilation with gamma = γ as given.
    /// </summary>
    /// <param name="t_o">The t o.</param>
    /// <param name="γ">The γ.</param>
    /// <returns></returns>
    template<typename T, typename K>
    static constexpr auto timeGamma(const T t_o, const K  γ);

    /// <summary>
    /// A spaceship is heading directly toward the Earth at a velocity of
    /// 0.800c(uv) . The astronaut on board claims that he can send a canister
    /// toward the Earth at 1.20c(v) relative to the Earth. Calculate the
    /// velocity the canister must have relative to the spaceship.
    /// </summary>
    /// <param name="v">The v.</param>
    /// <param name="uv">The uv.</param>
    /// <returns>speed relativity relationship</returns>
    template<typename T, typename K>
    static constexpr auto relative_velocity_away(const T v, const K uv);

    /// <summary>
    /// Relatives the velocity towards.
    /// </summary>
    /// <param name="v">The v.</param>
    /// <param name="uv">The uv.</param>
    /// <returns></returns>
    template<typename T, typename K>
    static constexpr auto relative_velocity_towards(const T v, const K uv);

    /// <summary>
    /// When a missile is shot from one spaceship towards another, it leaves
    /// the first at 0.950c(u_) and approaches the other at 0.750c(u). What is the
    /// relative velocity of the two ships?
    /// </summary>
    /// <param name="u">The relative velocity of object to observer .</param>
    /// <param name="u_">The relative velocity to the other observer.</param>
    /// <returns>relative velocity between the two observers</returns>
    template<typename T, typename K>
    static constexpr auto relativeVelocity_between2Objects(const T u, const K u_);

    /// <summary>
    /// Suppose the speed of light were only 3000 m/s(c_) . A jet fighter moving
    /// toward a target on the ground at 800 m/s(v) shoots bullets, each having a
    /// muzzle velocity of 1000 m/s(uv). calculate the bullets’ velocity relative
    /// to the target.
    /// </summary>
    /// <param name="v">The velocity of observer.</param>
    /// <param name="uv">The velocity of object.</param>
    /// <param name="c_">The speed of light.</param>
    /// <returns>velocity relative to target</returns>
    template<typename T, typename K, typename C>
    static constexpr auto relative_velocity(const T v, const K uv, const C c_);

    /// <summary>
    /// If a galaxy moving away from the Earth has a speed of 1000 km/s(u) and
    /// emits 656 nm(λ_s) light characteristic of hydrogen (the most common element
    /// in the universe). Calculate the wavelength we observe on the Earth
    /// </summary>
    /// <param name="u">The speed.</param>
    /// <param name="λ_s">The wavelength source.</param>
    /// <returns>observed wavelength</returns>
    template<typename T, typename K>
    static constexpr auto wavelengthObserved(const T u, const K λ_s);

    /// <summary>
    /// A space probe speeding towards the nearest star moves at 0.250c(u) and
    /// sends radio information at a broadcast frequency of 1.00 GHz(f_s).
    /// Calculate what frequency is received on the Earth.
    /// </summary>
    /// <param name="uc">The speed.</param>
    /// <param name="f_s">The f s.</param>
    /// <returns></returns>
    template<typename T, typename K>
    static constexpr auto frequencyObserved(const T uc, const K f_s);

    /// <summary>
    /// Near the center of our galaxy, hydrogen gas is moving directly away
    /// from us in its orbit about a black hole. We receive 1900(λ_obs) nm electromagnetic
    /// radiation and know that it was 1875 nm(λ_s) when emitted by the hydrogen gas.
    /// What is the speed of the gas
    /// </summary>
    /// <param name="λ_s">The λ s.</param>
    /// <param name="λ_obs">The λ obs.</param>
    /// <returns></returns>
    template<typename T, typename K>
    static constexpr auto velocity_fromWaveLengths(const T λ_s, const K λ_obs);

    /// <summary>
    /// A highway patrol officer uses a device that measures the speed of
    /// vehicles by bouncing radar off them and measuring the Doppler shift.
    /// The outgoing radar has a frequency of 100 GHz(f_S) and the returning echo
    /// has a frequency 15.0 kHz(increase) higher. What is the velocity of the vehicle?
    /// Note that there are two Doppler shifts in echoes. Be certain not to
    /// round off until the end of the problem, because the effect is small.
    /// </summary>
    /// <param name="f_s">The frequency from the source.</param>
    /// <param name="increase">The increase in the frequency from it bouncing
    /// back to the radar gun.</param>
    /// <returns>velocity of moving object the frequency bounced off of</returns>
    template<typename T, typename K>
    static constexpr auto velocity_fromFrequencyEcho(const T f_s, const K increase);

    /// <summary>
    /// All but the closest galaxies are receding from our own Milky Way Galaxy.
    /// If a galaxy 12.0×109 ly(l_o) away is receding from us at 0.900c(v), if
    /// the velocity relative to us of the probe moving towards the other galaxy
    /// is 0.99947c(u), as measured from that galaxy, calculate
    /// How long it will take the probe to reach the other galaxy as
    /// measured from the Earth. You may assume that the velocity of the other
    /// galaxy remains constant.
    /// <param name="u">The u.</param>
    /// <param name="v">The v.</param>
    /// <param name="l_o">The l o.</param>
    /// <returns>time for probe to reach other galaxy</returns>
    template<typename T, typename K, typename L>
    static constexpr auto relativisticTime(const T u, const K v, const L l_o);

    /// <summary>
    /// Find the momentum of a helium nucleus having a mass of 6.68×10−27 kg(m)
    /// that is moving at 0.200c.(u)
    /// </summary>
    /// <param name="m">The mass.</param>
    /// <param name="u">The velocity.</param>
    /// <returns>relativistic momentum</returns>
    template<typename T, typename K>
    static constexpr auto relativisticMomentum(const T m, const K u);

    /// <summary>
    /// One cosmic ray neutron has a velocity of 0.250c relative to the Earth.
    /// Calculate its momentum.
    /// </summary>
    /// <param name="v">The velocity.</param>
    /// <param name="E_o">The rest energy, can be looked up in tables.</param>
    /// <returns>momentum</returns>
    template<typename V, typename E>
    static constexpr auto momentum_fromEnergies(const V v, const E E_o);

    /// <summary>
    /// Find the momentum of a 1.00×109 kg(m) asteroid heading towards the
    /// Earth at 30.0 km/s(u).
    /// </summary>
    /// <param name="m">The m.</param>
    /// <param name="u">The u.</param>
    /// <returns></returns>
    template<typename T, typename K>
    static constexpr auto momentum_slowerObject(const T m, const K u);

    /// <summary>
    ///  Find the ratio of this momentum to the classical momentum.
    ///  (Use the approximation that γ=1+12v2c2 at low velocities.)
    /// </summary>
    /// <param name="v">The velocity.</param>
    /// <returns>gamma, Lorentz factor</returns>
    template<typename T>
    static constexpr auto momentumRatios_classical2relativistic(const T v);

    /// <summary>
    /// What is the velocity of an electron that has a momentum of
    /// 3.04×10−21 kg⋅m/s?(p) Note that you must calculate the velocity to
    /// at least four digits to see the difference from c.
    /// </summary>
    /// <param name="p">The relativistic momentum.</param>
    /// <param name="m">The mass.</param>
    /// <returns>velocity</returns>
    template<typename T, typename M>
    static constexpr auto velocityFrom_momentum(const T p, const M m);

    /// <summary>
    /// What is the rest energy of an electron, given its mass is 9.11
    /// *10^-31 kg(m)
    /// </summary>
    /// <param name="m">The mass.</param>
    /// <returns>energy in joules</returns>
    template<typename T>
    static constexpr auto newtonsEnergy(const T m);

    /// <summary>
    /// Calculates the mass from rest energy.
    /// </summary>
    /// <param name="E_o">The rest energy o.</param>
    /// <returns>mass in kg</returns>
    template<typename T>
    static constexpr auto mass_fromRestEnergy(const T E_o);

    /// <summary>
    /// If the rest energies of a proton and a neutron (the two constituents
    /// of nuclei) are 938.3(E_o2) and 939.6(E_o1) MeV respectively, what is the difference
    /// in their masses in kilograms?
    /// </summary>
    /// <param name="E_o1">The rest energy 1.</param>
    /// <param name="E_o2">The rest energy 2.</param>
    /// <returns>difference in Mass</returns>
    template<typename T, typename K>
    static constexpr auto difference_inMass_fromRestEnergies(const T E_o1, const K E_o2);

    /// <summary>
    /// The Big Bang that began the universe is estimated to have released
    /// 10^68 J(E_o) of energy. How many stars could half this energy create,
    /// assuming the average star's mass is 4.00×1030 kg(m).
    /// </summary>
    /// <param name="E_o">The rest energy.</param>
    /// <param name="m">The mass.</param>
    /// <returns>N objects that can be made(stars) from energy</returns>
    template<typename T, typename K>
    static constexpr auto objectsMade(const T E_o, const K m);

    /// <summary>
    /// Relativistics the total energy.
    /// </summary>
    /// <param name="p">The p.</param>
    /// <param name="m">The m.</param>
    /// <returns></returns>
    template<typename P, typename M>
    static constexpr auto relativisticTotalEnergy(const P p, const M m);

    /// <summary>
    /// A supernova explosion of a 2.00×1030 kg star produces 1.00×1044 J of
    /// energy. What is the ratio Δm/m_i of mass destroyed to the original
    /// mass of the star?
    /// </summary>
    /// <param name="m">The m.</param>
    /// <param name="m_i">The m i.</param>
    /// <returns></returns>
    template<typename T, typename K>
    static constexpr auto ratioOfMassUsedAsEnergy(const T m, const K m_i);

    /// <summary>
    /// Calculates the kinetics energy.
    /// </summary>
    /// <param name="γ">gamma.</param>
    /// <param name="m">The mass.</param>
    /// <returns>kinetic energy (J)</returns>
    template<typename T, typename K>
    static constexpr auto kineticEnergy(const T γ, const K m);

    /// <summary>
    /// Totals the energy.
    /// </summary>
    /// <param name="E_o">The e o.</param>
    /// <param name="v">The v.</param>
    /// <returns></returns>
    template<typename E, typename V>
    static constexpr auto totalEnergy(const E E_o, const V v);

    /// <summary>
    /// Calculate the relativistic kinetic energy of a 1000-kg(m) car moving at
    /// 30.0 m/s(v) if the speed of light were only 45.0 m/ s(c_).
    /// </summary>
    /// <param name="v">The velocity.</param>
    /// <param name="m">The mass.</param>
    /// <param name="c_">The speed of light.</param>
    /// <returns>relativistic kinetic energy</returns>
    template<typename V, typename M, typename C>
    static  auto relativisticKineticEnergy(const V v, const M m, const C c_ = _C_);

    /// <summary>
    /// Calculate the kinetic energy in MeV of a π-meson that lives 1.40×10−16 s(t)
    /// as measured in the laboratory, and 0.840×10−16 s(t_o) when at rest relative
    /// to an observer, given that its rest energy is 135 MeV(E_o)
    /// </summary>
    /// <param name="t_o">The proper time.</param>
    /// <param name="t">time dilation.</param>
    /// <param name="E_o">The rest energy.</param>
    /// <returns>kinetic energy</returns>
    template<typename T, typename T1, typename E>
    static constexpr auto kineticEnergy_fromTimesAndRestEnergy(const T t_o, const T1 t, const E E_o);

    /// <summary>
    /// A muon has a rest mass energy of 105.7 MeV(m_i), and it decays into an
    /// electron(m_d = .5110MeV) and a mass-less particle. If all the lost
    /// mass is converted into the electron’s kinetic energy, find γ for the
    /// electron.
    /// </summary>
    /// <param name="m_i">The initial rest mass.</param>
    /// <param name="m_d">The rest mass of particle after decay.</param>
    /// <returns></returns>
    template<typename T, typename M>
    static constexpr auto gamma_fromRestMassesOfDecayingParticle(const T m_i, const M m_d);

    /// <summary>
    /// A π-meson is a particle that decays into a muon and a mass-less particle.
    /// The π-meson has a rest mass energy of 139.6 MeV(E_i), and the muon has a
    /// rest mass energy of 105.7 MeV(E_f). Suppose the π-meson is at rest and all
    /// of the missing mass goes into the muon’s kinetic energy.Calculate How fast
    /// the muon moves.
    /// </summary>
    /// <param name="E_i">The e i.</param>
    /// <param name="E_f">The e f.</param>
    /// <returns>gamma γ</returns>
    template<typename T, typename E>
    static constexpr auto gamma_fromRestMassEnergies(const T E_i, const E E_f);

    /// <summary>
    /// What is γ for a proton->(q) having a mass energy of 938.3 MeV->(M) accelerated
    /// through an effective potential of 1.0 TV(teravolt)->(volts) at Fermilab
    /// outside Chicago
    /// </summary>
    /// <param name="q">The charge of the particle.</param>
    /// <param name="volts">The volts.</param>
    /// <param name="m">The mass energy.</param>
    /// <returns>gamma γ</returns>
    template<typename Q, typename V, typename M>
    static constexpr auto gamma_fromAccelerationThroughVoltage(const Q q, const V volts, const M m);

    /// <summary>
    /// Calculate the effective accelerating potential for electrons->(m) at the
    /// Stanford Linear Accelerator, if gamma=1.00×105->(γ) for them
    /// </summary>
    /// <param name="γ">gamma (γ).</param>
    /// <param name="m">The mass of particle.</param>
    /// <param name="q">The charge of particle.</param>
    /// <returns>the effective volts needed to accelerate particle</returns>
    template<typename G, typename M, typename Q>
    static constexpr auto effectiveAccelerationPotential(const G γ, const M m, const Q q);

    /// <summary>
    /// Using a calculation of the energy released by the destruction of 1.00 kg->(m)
    /// of mass. Calculate how many kilograms could be lifted to a 10.0 km->(h)
    /// height by this amount of energy?
    /// </summary>
    /// <param name="m">The m.</param>
    /// <param name="h">The h.</param>
    /// <returns></returns>
    template<typename M, typename H>
    static constexpr auto forDestructionMassHowManyKgCanBeLiftedHeightKm(const M m, const H h);




    ~SpecialRelativity()
    {
        delete _specialRelativityPtr;
    }
    void setTemplateVar(ld var) { specialRelativityVar = var; }
    ld getTemplateVar() const { return specialRelativityVar; }

private:
    ld specialRelativityVar;
    static void countIncrease() { specialRelativity_objectCount += 1; }
    static void countDecrease() { specialRelativity_objectCount -= 1; }

};

#endif //PHYSICSFORMULA_SPECIALRELATIVITY_H

template<typename T>
constexpr auto SpecialRelativity::lorentzFactor(const T ν)
{
    return 1.0 / sqrt(1.0 - (ν * ν));
}

template<typename T, typename K>
constexpr auto SpecialRelativity::lorentzValue(const T t, const K t_o)
{
    return t / t_o;
}

template<typename T, typename K>
constexpr auto SpecialRelativity::relativisticTimeDilation(const T ν, const K t_o)
{
    return t_o / sqrt(1.0 - ((ν * ν)/(C_*C_) ));
}

template<typename T, typename K>
constexpr auto SpecialRelativity::timeDilation(const T νc, const K t_o)
{
    return t_o / sqrt(1.0 - (νc * νc));
}

template<typename T, typename K>
constexpr auto SpecialRelativity::relativeVelocity(const T t, const K t_o)
{
    return (_C_ / t) * sqrt(pow(t, 2) - pow(t_o, 2));
}

template<typename T>
constexpr auto SpecialRelativity::relativeVelocity_percentLorentz(const T percent_γ)
{// γ = gamma = Lorentz
    const auto γ = 1.00 + percent_γ / 100;
    return (_C_ / γ) * sqrt((γ * γ) - 1);
}

template<typename T>
constexpr auto SpecialRelativity::relativeVelocity_lorantzAt(const T γ)
{
    return _C_ * sqrt(1.0 - (1.0 / (γ * γ)));
}

template<typename T, typename K>
constexpr auto SpecialRelativity::observedVelocity(const T t, const K t_o)
{
    return _C_ * sqrt((1.0 - (t_o * t_o) / (t * t)));
}

template<typename T, typename K>
constexpr auto SpecialRelativity::lengthContraction(const T L_o, const K vc)
{
    return L_o * sqrt(1.0 - (vc * vc));
}

template<typename T, typename K>
constexpr auto SpecialRelativity::speedToAppearSomeLength(const T l_o, const K l)
{
    return _C_ * sqrt(1.0 - ((l*l)/ (l_o* l_o)));
}

template<typename T, typename K>
constexpr auto SpecialRelativity::distanceTraveled_earthBoundObserver(const T t_o, const K vc)
{
    return sqrt(1.0 - (vc * vc)) * vc * _C_ * t_o;
}

template<typename T, typename K>
constexpr auto SpecialRelativity::distanceTraveled_proper(const T t_o, const K vc)
{
    return vc * _C_ * t_o;
}

template<typename T, typename K>
constexpr auto SpecialRelativity::contractedLength(const T l_o, const K γ)
{
    return l_o / γ;
}

template<typename T, typename K>
constexpr auto SpecialRelativity::time(const T l_o, const K vc)
{
    return l_o / (vc*_C_);
}

template<typename T, typename K>
constexpr auto SpecialRelativity::properTime(const T t, const K vc)
{
    return sqrt(1.0 - (vc * vc)) * t;
}

template<typename T, typename K>
constexpr auto SpecialRelativity::timeGamma(const T t_o, const K γ)
{
    return  γ * t_o;
}

template<typename T, typename K>
constexpr auto SpecialRelativity::relative_velocity_away(const T v, const K uv)
{
    return (v - uv) / (1.0 - (v * uv));
}

template<typename T, typename K>
constexpr auto SpecialRelativity::relative_velocity_towards(const T v, const K uv)
{
    return (v + uv) / (1.0 + (v * uv));
}

template<typename T, typename K>
constexpr auto SpecialRelativity::relativeVelocity_between2Objects(const T u, const K u_)
{
    return (u_ - u) / ((u_ * u) - 1);
}

template<typename T, typename K, typename C>
constexpr auto SpecialRelativity::relative_velocity(const T v, const K uv, const C c_)
{
    return (v + uv) / (1.0 + ((v * uv)/(c_*c_)));
}

template<typename T, typename K>
constexpr auto SpecialRelativity::wavelengthObserved(const T u, const K λ_s)
{
    return λ_s * sqrt((1.0 + (u / _C_)) / (1.0 - (u / _C_)));
}

template<typename T, typename K>
constexpr auto SpecialRelativity::frequencyObserved(const T uc, const K f_s)
{
    return f_s * sqrt((1.0 - (uc )) / (1.0 + (uc )));
}

template<typename T, typename K>
constexpr auto SpecialRelativity::velocity_fromWaveLengths(const T λ_s, const K λ_obs)
{
    return _C_ * ((((λ_obs * λ_obs) / (λ_s * λ_s)) - 1.0) / (1.0 + (((λ_obs * λ_obs) / (λ_s * λ_s)))));
}

template<typename T, typename K>
constexpr auto SpecialRelativity::velocity_fromFrequencyEcho(const T f_s, const K increase)
{
    return _C_ * (-increase) / (2.0 * f_s + increase);
}

template<typename T, typename K, typename L>
constexpr auto SpecialRelativity::relativisticTime(const T u, const K v, const L l_o)
{
    return l_o / (u - v);
}

template<typename T, typename K>
constexpr auto SpecialRelativity::relativisticMomentum(const T m, const K u)
{
    return (m * (u * _C_)) / sqrt(1.0 - (u * u));
}

template<typename V, typename E>
constexpr auto SpecialRelativity::momentum_fromEnergies(const V v, const E E_o)
{
    const auto E_ = totalEnergy(E_o, v);
    return sqrt((E_ * E_) - (E_o * E_o) );
}

template<typename T, typename K>
constexpr auto SpecialRelativity::momentum_slowerObject(const T m, const K u)
{
    return (m * u) / sqrt(1.0 - ((u * u)/(_C_*_C_)));
}

template<typename T>
constexpr auto SpecialRelativity::momentumRatios_classical2relativistic(const T v)
{
    return 1.0 + (1 / 2) * ((v * v) / (_C_ * _C_));
}

template<typename T, typename M>
constexpr auto SpecialRelativity::velocityFrom_momentum(const T p, const M m)
{
    return p / sqrt((m * m) + ((p * p) / (_C_ * _C_)));
}

template<typename T>
constexpr auto SpecialRelativity::newtonsEnergy(const T m)
{
    return m * (_C_ * _C_);
}

template<typename T>
constexpr auto SpecialRelativity::mass_fromRestEnergy(const T E_o)
{
    return E_o / (_C_ * _C_);
}

template<typename T, typename K>
constexpr auto SpecialRelativity::difference_inMass_fromRestEnergies(const T E_o1, const K E_o2)
{
    return abs((E_o1 - E_o2) / (_C_ * _C_));
}

template<typename T, typename K>
constexpr auto SpecialRelativity::objectsMade(const T E_o, const K m)
{
    return E_o / (2.0 * m * (_C_ * _C_));
}

template<typename P, typename M>
constexpr auto SpecialRelativity::relativisticTotalEnergy(const P p, const M m)
{
    return sqrt((pow(p * _C_,2) + pow(m * (_C_ * _C_), 2)));
}

template<typename T, typename K>
constexpr auto SpecialRelativity::ratioOfMassUsedAsEnergy(const T m, const K m_i)
{
    return m / m_i;
}

template<typename T, typename K>
constexpr auto SpecialRelativity::kineticEnergy(const T γ, const K m)
{
    return (γ - 1.0) * m * (_C_ * _C_);
}

template<typename E, typename V>
constexpr auto SpecialRelativity::totalEnergy(const E E_o, const V v)
{
    return E_o / sqrt(1.0 - (v * v));
}

template<typename V, typename M, typename C>
inline auto SpecialRelativity::relativisticKineticEnergy(const V v, const M m, const C c_)
{
    return (((m * (c_*c_))/ sqrt(1.0 - ((v * v) / (c_ * c_)))) - (m * (c_*c_)));
}

template<typename T, typename T1, typename E>
constexpr auto SpecialRelativity::kineticEnergy_fromTimesAndRestEnergy(const T t_o, const T1 t, const E E_o)
{
    return ((t / t_o) - 1.0) * E_o;
}

template<typename T, typename M>
constexpr auto SpecialRelativity::gamma_fromRestMassesOfDecayingParticle(const T m_i, const M m_d)
{
    return m_i / m_d;
}

template<typename T, typename E>
constexpr auto SpecialRelativity::gamma_fromRestMassEnergies(const T E_i, const E E_f)
{
    return ((E_i - E_f) / E_f) + 1.0;
}

template<typename Q, typename V, typename M>
constexpr auto SpecialRelativity::gamma_fromAccelerationThroughVoltage(const Q q, const V volts, const M m)
{
    return ((q * volts) / (m * (_C_ * _C_))) + 1.0;
}

template<typename G, typename M, typename Q>
constexpr auto SpecialRelativity::effectiveAccelerationPotential(const G γ, const M m, const Q q)
{
    return ((γ - 1.0) * m * (_C_ * _C_)) / q;
}

template<typename M, typename H>
constexpr auto SpecialRelativity::forDestructionMassHowManyKgCanBeLiftedHeightKm(const M m, const H h)
{
    const auto PE = newtonsEnergy(m);
    return PE / (_Ga_ * h);
}


