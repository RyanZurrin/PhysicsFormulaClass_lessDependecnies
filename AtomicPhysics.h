//
// Created by Ryan.Zurrin001 on 12/15/2021.
//

#ifndef PHYSICSFORMULA_ATOMICPHYSICS_H
#define PHYSICSFORMULA_ATOMICPHYSICS_H

#include "Constants.h"
#include "PeriodicElements.h"


/// <summary>
/// The atomic physics object count
/// </summary>
static int atomicPhysics_objectCount = 0;

static struct HydrogenSpectralSeries
{
    HydrogenSpectralSeries()
    = default;
    explicit HydrogenSpectralSeries(int further )
    {
        FURTHER = further;
    }
    const long double LYMAN		= 1.0;
    const long double BALMER		= 2.0;
    const long double PASCHEN	= 3.0;
    const long double BRACKETT	= 4.0;
    const long double PFUND		= 5.0;
    const long double HUMPHREYS	= 6.0;
    long double FURTHER = 7.0; // FURTHER  >6

}n_f;

//α=224,ß=225,π=227,Σ=228,σ=229,µ=230,τ=231,Φ=232,Θ=233
//Ω=234,δ=235,∞=236,φ=237,ε=238,∩=239,≡=240,Γ=226,γ, σ, ϑ, Å, Ώ, λ, γ, Δ
/**
 * @class AtomicPhysics
 * @details class of static methods that relate to chapter 30 of the
 * open-stax college physics text book.
 * @author Ryan Zurrin
 * dateBuilt  6/8/2021
 * lastEdit 6/8/2021
 */
class AtomicPhysics
{

    long double atomPhysicsVar;
    static auto countIncrease() { atomicPhysics_objectCount += 1; }
    static auto countDecrease() { atomicPhysics_objectCount -= 1; }
public:
    AtomicPhysics()
    {

        atomPhysicsVar = 0.0;
        countIncrease();
    }

    /**
     * @brief copy constructor
     */
    AtomicPhysics(const AtomicPhysics& t)
    {
        atomPhysicsVar = t.atomPhysicsVar;
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    AtomicPhysics(AtomicPhysics&& t) noexcept
    {
        atomPhysicsVar = t.atomPhysicsVar;
        countIncrease();
    }
    /**
     * @brief copy assignment operator
     */
    AtomicPhysics& operator=(AtomicPhysics&& t) noexcept
    {
        if (this != &t)
        {
            std::swap(atomPhysicsVar, t.atomPhysicsVar);
            countIncrease();
        }
        return *this;
    }

    /**
     * @brief user-defined copy assignment (copy-and-swap idiom)
     */
    AtomicPhysics& operator=(AtomicPhysics other)
    {
        std::swap(atomPhysicsVar, other.atomPhysicsVar);
        return *this;
    }

    static void show_objectCount() { std::cout << "\n atomic physics object count: "
                                               << atomicPhysics_objectCount << std::endl; }
    static int get_objectCount() { return atomicPhysics_objectCount; }

    auto setTemplateVar(long double var) { atomPhysicsVar = var; }
    [[nodiscard]] auto getTemplateVar() const { return atomPhysicsVar; }


    /// <summary>
    /// Rutherford found the size of the nucleus to be about 10−15 m .
    /// This implied a huge density. Calculate what would this density be for some
    /// other element such as gold.
    /// </summary>
    /// <param name="elementMass">The element mass.</param>
    /// <returns></returns>
    template<typename T>
    static constexpr auto elementDensityFromNucleusSize(T elementMass);

    /// <summary>
    /// In Millikan’s oil-drop experiment, one looks at a small oil drop held
    /// motionless between two plates. Take the voltage between the plates to
    /// be 2033 V, and the plate separation to be 2.00 cm. The oil drop
    /// (of density 0.81 g/cm3) has a diameter of 4.0×10−6 m . Calculate the
    /// charge on the drop, in terms of electron units
    /// </summary>
    /// <param name="volts">The volts.</param>
    /// <param name="d">The plate separation distance.</param>
    /// <param name="p">The density.</param>
    /// <param name="diameter">The diameter</param>
    /// <returns>charge on the oil drop</returns>
    template<typename V, typename D, typename P, typename A>
    static constexpr auto chargeOnDrop(V volts, D d, P p, A diameter);

    /// <summary>
    ///  An aspiring physicist wants to build a scale model of a hydrogen atom
    ///  for her science fair project. If the atom is d m in diameter,
    ///  how big should she try to make the nucleus
    /// </summary>
    /// <param name="d">The diameter.</param>
    /// <returns>size of nucleus on model</returns>
    template<typename D>
    static constexpr auto toScale(D d);

    /// <summary>
    /// calculate the wavelength within the hydrogen spectrum using the Rydberg
    /// constant and this formula. n_i and nf are integer values where n_i is
    /// always at least one larger then nf.
    /// </summary>
    /// <param name="n_i">positive integer larger then > nf</param>
    /// <param name="nf">The positive integer associated with some series..</param>
    /// <returns>wavelength of hydrogen spectrum element</returns>
    template<typename NI, typename NF>
    static constexpr auto hydrogenSpectrum_wavelength(NI n_i, NF nf);

    /// <summary>
    /// If a hydrogen atom has its electron in the n=4 state,
    /// Calculate how much energy in eV is needed to ionize it.
    /// </summary>
    /// <param name="state">The state.</param>
    /// <param name="E_0">The e 0.</param>
    /// <returns></returns>
    template<typename N, typename E>
    static constexpr auto energyToIonizedState(N state, E E_0);

    /// <summary>
    /// A hydrogen atom in an excited state can be ionized with less energy
    /// than when it is in its ground state(e_0). What is n for a hydrogen atom if
    /// 0.850 eV(e_i) of energy can ionize it
    /// </summary>
    /// <param name="e_0">The e 0.</param>
    /// <param name="e_i">The e i.</param>
    /// <returns></returns>
    template<typename E0, typename EI>
    static constexpr auto stateOfExcitedAtom(E0 e_0, EI e_i);

    /// <summary>
    /// How much energy in eV is needed to ionize the ion from this excited state?
    /// </summary>
    /// <param name="e_0">The e 0.</param>
    /// <param name="z">The atomic weight or mass (z).</param>
    /// <param name="n">The excited state the atom is in now.</param>
    /// <returns>energy needed to ionize atom from excited state</returns>
    template<typename E0, typename Z, typename N>
    static constexpr auto energyNeededToIonizeAtom(E0 e_0, Z z, N n);

    /// <summary>
    /// Find the radius of a hydrogen atom in the n=2 state according to Bohr’s
    /// theory.
    /// </summary>
    /// <param name="n">The n.</param>
    /// <param name="z">The z.</param>
    /// <returns></returns>
    template<typename N, typename Z>
    static constexpr auto atomRadius_nState(N n, Z z);

    /// <summary>
    /// What is the smallest-wavelength line in the Balmer series? Is it in the
    /// visible part of the spectrum?
    /// </summary>
    /// <param name="nf">The n f.</param>
    /// <returns></returns>
    template<typename NF>
    static constexpr auto smallest_wavelength(NF nf);

    /// <summary>
    /// A wavelength of 4.653 μm is observed in a hydrogen spectrum for a
    /// transition that ends in the nf=5 level. What was ni for the initial
    /// level of the electron
    /// </summary>
    /// <param name="theta">The theta.</param>
    /// <param name="nf">The n f.</param>
    /// <returns></returns>
    template<typename W, typename NF>
    static constexpr auto initialEnergyLevel(W theta, NF nf);

    /// <summary>
    /// Atoms can be ionized by thermal collisions, such as at the high
    /// temperatures found in the solar corona. One such ion is C^+5(z), a carbon
    /// atom with only a single electron. What is the wavelength of the first
    /// line(nf) in this ion’s Paschen series(n_i)
    /// </summary>
    /// <param name="e_0">The ground state.</param>
    /// <param name="z">The atomic number z.</param>
    /// <param name="n_i">The initial electron orbit.</param>
    /// <param name="nf">The final electron orbit.</param>
    /// <returns></returns>
    template<typename E0, typename Z, typename N>
    static constexpr auto wavelength_nLineInIonsSeries(E0 e_0,
                                                       Z z,
                                                       N n_i,
                                                       N nf);

    /// <summary>
    /// Calculate the shortest-wavelength x-ray radiation that can be generated
    /// in an x-ray tube with an applied voltage of 50.0 kV(volts)
    /// </summary>
    /// <param name="volts">The volts.</param>
    /// <returns>shortest wavelength</returns>
    template<typename V>
    static constexpr auto shortestWavelength_xRayTubeAppliedVoltage(V volts);

    /// <summary>
    /// Calculate the photon energy in eV
    /// </summary>
    /// <param name="theta">The theta.</param>
    /// <returns>energy in eV</returns>
    template<typename W>
    static constexpr auto photonEnergy_eV(W theta);

    /// <summary>
    /// What are the approximate energies of the Kα x-rays for copper(z)
    /// </summary>
    /// <param name="e_0">The e 0.</param>
    /// <param name="z">The z.</param>
    /// <returns>energy of x-ray for Kα transition</returns>
    template<typename E0, typename Z>
    static constexpr auto energyK_alphaTransition(E0 e_0, Z z);

    /// <summary>
    /// What are the approximate energies of the Kβ x-rays for copper(z)
    /// </summary>
    /// <param name="e_0">The e 0.</param>
    /// <param name="z">The z.</param>
    /// <returns>energy of x-ray for Kβ transition</returns>
    template<typename E0, typename Z>
    static constexpr auto energyK_betaTransition(E0 e_0, Z z);

    /// <summary>
    /// A helium-neon laser is pumped by electric discharge. Calculate the wavelength
    /// the electromagnetic radiation would need to be to pump it if it was
    /// being energized by 20.61eV(volts).
    /// </summary>
    /// <param name="energy">The energy supplied.</param>
    /// <returns>wavelength</returns>
    template<typename E>
    static constexpr auto wavelengthNeededToPumpLaserTo_evState(E energy);

    /// <summary>
    /// Calculate the magnitude of the angular momentum for an l=1(l) electron.
    /// </summary>
    /// <param name="l">The l.</param>
    /// <returns>magnitude of angular momentum</returns>
    template<typename L>
    static constexpr auto magnitudeAngularMomentum(L l);



    ~AtomicPhysics() = default;




};
#endif //PHYSICSFORMULA_ATOMICPHYSICS_H

template<typename T>
constexpr auto AtomicPhysics::elementDensityFromNucleusSize(const T elementMass)
{
    return elementMass / ((4.0 / 3.0) * constants::PI * (pow((1e-15/2.0), 3)));
}

template<typename V, typename D, typename P, typename A>
constexpr auto AtomicPhysics::chargeOnDrop(const V volts, const D d, const P p, const A diameter)
{
    return ((d * constants::PI * pow(diameter, 3.0) * p * constants::Ga) / (6.0 * volts))*
    (1.0/constants::PROTON_CHARGE);
}

template<typename D>
constexpr auto AtomicPhysics::toScale(const D d)
{
    return (d * 1e-15) / 1e-10;
}

template<typename NI, typename NF>
constexpr auto AtomicPhysics::hydrogenSpectrum_wavelength(const NI n_i, const NF nf)
{
    return 1.0 / (constants::RYDBERG * ((1.0 / (nf * nf)) - (1.0 / (n_i * n_i)
    )));
}

template<typename N, typename E>
constexpr auto AtomicPhysics::energyToIonizedState(const N state, const E E_0)
{
    return E_0 / pow(state, 2);
}

template<typename E0, typename EI>
constexpr auto AtomicPhysics::stateOfExcitedAtom(const E0 e_0, const EI e_i)
{
    return sqrt(-e_0 / -e_i);
}

template<typename E0, typename Z, typename N>
constexpr auto AtomicPhysics::energyNeededToIonizeAtom(const E0 e_0, const Z z, const N n)
{

    return -(e_0 * ((z*z)/(n*n)));
}

template<typename N, typename Z>
constexpr auto AtomicPhysics::atomRadius_nState(const N n, const Z z)
{
    return ((n * n) / z) * constants::A_B;
}

template<typename NF>
constexpr auto AtomicPhysics::smallest_wavelength(const NF nf)
{
    return (nf * nf) / constants::RYDBERG;
}

template<typename W, typename NF>
constexpr auto AtomicPhysics::initialEnergyLevel(const W theta, const NF nf)
{
    return nf * sqrt((theta * constants::RYDBERG) /
                     ((constants::RYDBERG * theta) - (nf * nf)));
}

template<typename E0, typename Z, typename N>
constexpr auto AtomicPhysics::wavelength_nLineInIonsSeries(const E0 e_0,
                                                           const Z z,
                                                           const N n_i,
                                                           const N nf)
{
    auto E_i = energyNeededToIonizeAtom(e_0, z, n_i);
    auto E_f = energyNeededToIonizeAtom(e_0, z, nf);
    return constants::PLANKS_C / (E_i - E_f);
}

template<typename V>
constexpr auto AtomicPhysics::shortestWavelength_xRayTubeAppliedVoltage(const V volts)
{
    return (constants::PLANKS_J*constants::LIGHT_SPEED) /
    (constants::PROTON_CHARGE * volts);
}

template<typename W>
constexpr auto AtomicPhysics::photonEnergy_eV(const W theta)
{
    return constants::PLANKS_C / theta;
}

template<typename E0, typename Z>
constexpr auto AtomicPhysics::energyK_alphaTransition(const E0 e_0, const Z z)
{
    return e_0 * (z * z) * (1.0 - (1.0 / (2.0 * 2.0)));
}

template<typename E0, typename Z>
constexpr auto AtomicPhysics::energyK_betaTransition(const E0 e_0, const Z z)
{
    return e_0 * (z * z) * (1.0 - (1.0 / (3.0 * 3.0)));
}

template<typename E>
constexpr auto AtomicPhysics::wavelengthNeededToPumpLaserTo_evState(const E energy)
{
    return constants::PLANKS_C / energy;
}

template<typename L>
constexpr auto AtomicPhysics::magnitudeAngularMomentum(const L l)
{
    return sqrt(l * (l + 1.0)) * (constants::PLANKS_J / (2.0 * constants::PI));
}


