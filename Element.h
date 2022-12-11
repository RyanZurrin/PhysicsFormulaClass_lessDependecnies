//
// Created by ryanz on 12/10/2022.
//

#ifndef PHYSICSFORMULA_ELEMENT_H
#define PHYSICSFORMULA_ELEMENT_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Element {
public:
    [[nodiscard]] virtual int getGroup() const { return group; }
    [[nodiscard]] virtual std::string getSymbol() const { return symbol; }
    [[nodiscard]] virtual std::string getType() const { return type; }
    [[nodiscard]] virtual std::string getCrystalType() const { return crystal_type; }
    [[nodiscard]] virtual std::string getElectronConfiguration() const { return electron_configuration; }
    [[nodiscard]] virtual long double getAtomicWeight() const { return atomicWeight; }
    [[nodiscard]] virtual int getAtomicNumber() const { return atomicNumber; }
    [[nodiscard]] virtual std::vector<long double> getEnergyLevels() const { return energyLevels; }
    [[nodiscard]] virtual long double getDensitySTP() const { return densitySTP; }
    [[nodiscard]] virtual long double getMeltingPoint() const { return meltingPoint; }
    [[nodiscard]] virtual long double getBoilingPoint() const { return boilingPoint; }
    [[nodiscard]] virtual long double getThermalConductivity() const { return thermalConductivity; }
    [[nodiscard]] virtual long double getElectricConductivity() const { return electricConductivity; }
    [[nodiscard]] virtual long double getResistivity() const { return resistivity; }
    [[nodiscard]] virtual long double getHeatSpecific() const { return heatSpecific; }
    [[nodiscard]] virtual long double getHeatVaporization() const { return heatVaporization; }
    [[nodiscard]] virtual long double getHeatFusion() const { return heatFusion; }
    [[nodiscard]] virtual long double getIonization1st() const { return ionization1st; }

    void print() const {
        // print all the data including the SI units if applicable
        std::cout << "Element: " << typeid(*this).name()+1 << std::endl;
        std::cout << "Group: " << getGroup() << std::endl;
        std::cout << "Symbol: " << getSymbol() << std::endl;
        std::cout << "Type: " << getType() << std::endl;
        std::cout << "Crystal Type: " << getCrystalType() << std::endl;
        std::cout << "Electron Configuration: " << getElectronConfiguration() << std::endl;
        std::cout << "Atomic Weight: " << getAtomicWeight() << " u (g/mol)" << std::endl;
        std::cout << "Atomic Number: " << getAtomicNumber() << std::endl;
        std::cout << "Energy Levels: ";
        for (auto &i : getEnergyLevels()) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        std::cout << "Density STP: " << getDensitySTP() << " kg/m^3" << std::endl;
        std::cout << "Melting Point: " << getMeltingPoint() << " C" << std::endl;
        std::cout << "Boiling Point: " << getBoilingPoint() << " C" << std::endl;
        std::cout << "Thermal Conductivity: " << getThermalConductivity() << " W/mK" << std::endl;
        std::cout << "Electric Conductivity: " << getElectricConductivity() << " MS/m" << std::endl;
        std::cout << "Resistivity: " << getResistivity() << " m Ohm" << std::endl;
        std::cout << "Heat Specific: " << getHeatSpecific() << " J/kgK" << std::endl;
        std::cout << "Heat Vaporization: " << getHeatVaporization() << " kJ/mol" << std::endl;
        std::cout << "Heat Fusion: " << getHeatFusion() << " kJ/mol" << std::endl;
        std::cout << "Ionization 1st: " << getIonization1st() << " eV" << std::endl;
    }

    void display() const {
        displayElementImg(getFileName(this->atomicNumber));
    }




    virtual ~Element() = default;
protected:
    int group{};
    std::string symbol;
    std::string type;
    std::string crystal_type;
    std::string electron_configuration;
    long double atomicWeight{};
    int atomicNumber{};
    std::vector<long double> energyLevels;
    long double densitySTP{};
    long double meltingPoint{};
    long double boilingPoint{};
    long double thermalConductivity{};
    long double electricConductivity{};
    long double resistivity{};
    long double heatSpecific{};
    long double heatVaporization{};
    long double heatFusion{};
    long double ionization1st{};

private:
    static void loadImage(const char* pathname, sf::Texture& texture, sf::Sprite& sprite)
    {
        texture.loadFromFile(pathname);     // load it from the file
        sprite.setTexture(texture);         // put that texture in our sprite
        // the rectangle of the texture to use for this
        sprite.setTextureRect( sf::IntRect(0,0,screenSize_X,screenSize_Y) );
    }

    static void displayElementImg(const char elementName[])
    {

        // Create our window
        sf::RenderWindow window(
                sf::VideoMode(screenSize_X,screenSize_Y),       // size of the client area we want
                "Display an Image"                              // The text to appear on the window title
        );

        // load our image
        sf::Texture     texture;        // the texture which will contain our pixel data
        sf::Sprite      sprite;         // the sprite which will actually draw it
        loadImage(elementName,texture,sprite);

        // Set FPS so this draws at 60 FPS (note:  I didn't do this for the WinAPI version because it'd be too hard for such
        //  a small example)
        window.setFramerateLimit( 60 );

        bool program_running = true;        // true until the user wants to quit
        while(program_running)
        {
            // Do the event pump -- same idea as with Windows... look for events and process them
            sf::Event evt{};
            while( window.pollEvent(evt) )      // while there are any events to process...
            {
                // process them. But we're only interested in the closed event
                if(evt.type == sf::Event::EventType::Closed)        // is this a close event?
                    program_running = false;                        // indicate that we want the window to close
            }

            // now that events are processed... draw our image
            window.draw(sprite);        // just draw it to the back buffer
            window.display();           // and display it so the back buffer moves to the front
        }
    }

    static const char* getFileName(int atomicNumber)
    {
        switch (atomicNumber)
        {
            case 1:		return "img\\hydrogen.bmp";
            case 2:		return "img\\helium.bmp";
            case 3:		return "img\\lithium.bmp";
            case 4:		return "img\\beryllium.bmp";
            case 5:		return "img\\boron.bmp";
            case 6:		return "img\\carbon.bmp";
            case 7:		return "img\\nitrogen.bmp";
            case 8:		return "img\\oxygen.bmp";
            case 9:		return "img\\fluorine.bmp";
            case 10:	return "img\\neon.bmp";
            case 11:	return "img\\sodium.bmp";
            case 12:	return "img\\magnesium.bmp";
            case 13:	return "img\\aluminium.bmp";
            case 14:	return "img\\silicon.bmp";
            case 15:	return "img\\phosphorus.bmp";
            case 16:	return "img\\sulfur.bmp";
            case 17:	return "img\\chlorine.bmp";
            case 18:	return "img\\argon.bmp";
            case 19:	return "img\\potassium.bmp";
            case 20:	return "img\\calcium.bmp";
            case 21:	return "img\\scandium.bmp";
            case 22:	return "img\\titanium.bmp";
            case 23:	return "img\\vanadium.bmp";
            case 24:	return "img\\chromium.bmp";
            case 25:	return "img\\manganese.bmp";
            case 26:	return "img\\iron.bmp";
            case 27:	return "img\\cobalt.bmp";
            case 28:	return "img\\nickel.bmp";
            case 29:	return "img\\copper.bmp";
            case 30:	return "img\\zinc.bmp";
            case 31:	return "img\\gallium.bmp";
            case 32:	return "img\\germanium.bmp";
            case 33:	return "img\\arsenic.bmp";
            case 34:	return "img\\selenium.bmp";
            case 35:	return "img\\bromine.bmp";
            case 36:	return "img\\krypton.bmp";
            case 37:	return "img\\rubidium.bmp";
            case 38:	return "img\\strontium.bmp";
            case 39:	return "img\\yttrium.bmp";
            case 40:	return "img\\zirconium.bmp";
            case 41:	return "img\\niobium.bmp";
            case 42:	return "img\\molybdenum.bmp";
            case 43:	return "img\\technetium.bmp";
            case 44:	return "img\\ruthenium.bmp";
            case 45:	return "img\\rhodium.bmp";
            case 46:	return "img\\palladium.bmp";
            case 47:	return "img\\silver.bmp";
            case 48:	return "img\\cadmium.bmp";
            case 49:	return "img\\indium.bmp";
            case 50:	return "img\\tin.bmp";
            case 51:	return "img\\antimony.bmp";
            case 52:	return "img\\tellurium.bmp";
            case 53:	return "img\\iodine.bmp";
            case 54:	return "img\\xenon.bmp";
            case 55:	return "img\\cerium.bmp";
            case 56:	return "img\\barium.bmp";
            case 57:	return "img\\lanthanum.bmp";
            case 58:	return "img\\cerium.bmp";
            case 59:	return "img\\praseodymium.bmp";
            case 60:	return "img\\neodymium.bmp";
            case 61:	return "img\\promethium.bmp";
            case 62:	return "img\\samarium.bmp";
            case 63:	return "img\\europium.bmp";
            case 64:	return "img\\gadolinium.bmp";
            case 65:	return "img\\terbium.bmp";
            case 66:	return "img\\dysprosium.bmp";
            case 67:	return "img\\holmium.bmp";
            case 68:	return "img\\erbium.bmp";
            case 69:	return "img\\thulium.bmp";
            case 70:	return "img\\ytterbium.bmp";
            case 71:	return "img\\lutetium.bmp";
            case 72:	return "img\\hafnium.bmp";
            case 73:	return "img\\tantalum.bmp";
            case 74:	return "img\\tungsten.bmp";
            case 75:	return "img\\rhenium.bmp";
            case 76:	return "img\\osmium.bmp";
            case 77:	return "img\\iridium.bmp";
            case 78:	return "img\\platinum.bmp";
            case 79:	return "img\\gold.bmp";
            case 80:	return "img\\mercury.bmp";
            case 81:	return "img\\thallium.bmp";
            case 82:	return "img\\lead.bmp";
            case 83:	return "img\\bismuth.bmp";
            case 84:	return "img\\polonium.bmp";
            case 85:	return "img\\astatine.bmp";
            case 86:	return "img\\radon.bmp";
            case 87:	return "img\\francium.bmp";
            case 88:	return "img\\radium.bmp";
            case 89:	return "img\\actinium.bmp";
            case 90:	return "img\\thorium.bmp";
            case 91:	return "img\\protactinium.bmp";
            case 92:	return "img\\uranium.bmp";
            case 93:	return "img\\neptunium.bmp";
            case 94:	return "img\\plutonium.bmp";
            case 95:	return "img\\americium.bmp";
            case 96:	return "img\\curium.bmp";
            case 97:	return "img\\berkelium.bmp";
            case 98:	return "img\\califomium.bmp";
            case 99:	return "img\\einsteinium.bmp";
            case 100:	return "img\\fermium.bmp";
            case 101:	return "img\\mendelevium.bmp";
            case 102:	return "img\\nobelium.bmp";
            case 103:	return "img\\lawrencium.bmp";
            case 104:	return "img\\rutherfordium.bmp";
            case 105:	return "img\\dubnium.bmp";
            case 106:	return "img\\seaborgium.bmp";
            case 107:	return "img\\bohrium.bmp";
            case 108:	return "img\\hassium.bmp";
            case 109:	return "img\\meitnerium.bmp";
            case 110:	return "img\\darmstadtium.bmp";
            case 111:	return "img\\roentgenium.bmp";
            case 112:	return "img\\copernicium.bmp";
            case 113:	return "img\\nihonium.bmp";
            case 114:	return "img\\flerovium.bmp";
            case 115:	return "img\\moscovium.bmp";
            case 116:	return "img\\livermorium.bmp";
            case 117:	return "img\\tennessine.bmp";
            case 118:	return "img\\oganesson.bmp";
            default:	return "no image";
        }
    }
};

#endif //PHYSICSFORMULA_ELEMENT_H


/**
 * @brief Hydrogen is the chemical element with the symbol H and atomic number 1.
 * With a standard atomic weight of 1.008, hydrogen is the lightest element
 * in the periodic table. Hydrogen is the most abundant chemical substance
 * in the universe, constituting roughly 75% of all baryonic mass
 */
class Hydrogen : public Element {
public:
    Hydrogen() {
        group = 1;
        symbol = "H";
        type = "Reactive Nonmetal";
        crystal_type = "Hexagonal";
        electron_configuration = "1s1";
        atomicWeight = 1.007825; // 1.007825 u (g/mol)
        atomicNumber = 1; // Z_ = 1
        energyLevels = {1};
        densitySTP = .0899; // .0899 kg/m^3
        meltingPoint = -259.3; // -259.3 C
        boilingPoint = -252.9; // -252.9 C
        thermalConductivity = .18; // .18 W/mK
        electricConductivity = FP_NAN; // FP_NAN
        resistivity = FP_NAN; //FP_NAN
        heatSpecific = 14300.0; // 14300.0 J/kgK
        heatVaporization = .452; // 452 kJ/mol
        heatFusion = .558; // .558 kJ/mol
        ionization1st = 13.598;
    }
};

/**
 * @brief Helium is a chemical element with the symbol He and atomic number 2.
 * It is a colorless, odorless, tasteless, non-toxic, inert, monatomic gas,
 * the first in the noble gas group in the periodic table. Its boiling point
 * is the lowest among all the elements
 */
class Helium : public Element {
public:
    Helium() {
        group = 18;
        symbol = "He";
        type = "Noble Gas";
        crystal_type = "Hexagonal";
        electron_configuration = "1s2";
        atomicWeight = 4.002602; // 4.002602 u (g/mol)
        atomicNumber = 2; // Z_ = 2
        energyLevels = {2};
        densitySTP = 0.1785; // 0.1785 kg/m^3
        meltingPoint = FP_NAN; // C
        boilingPoint = -268.9; // -269 C
        thermalConductivity = 0.1513; // 0.1513 W/mK
        electricConductivity = FP_NAN; // FP_NAN
        resistivity = FP_NAN; // FP_NAN
        heatSpecific = 5193.1; // 5193.1 J/kgK
        heatVaporization = .083; // .083 kJ/mol
        heatFusion = .02; // .02 kJ/mol
        ionization1st = 24.587; // eV
    }
};

/**
 * @brief Lithium is a chemical element with the symbol LinearMomentum and atomic number 3.
 * It is a soft, silvery-white alkali metal. Under standard conditions,
 * it is the lightest metal and the lightest solid element.
 */
class Lithium : public Element {
public:
    Lithium() {
        group = 1;
        symbol = "Li";
        type = "Alkali Metal";
        crystal_type = "Body-Centered Cubic";
        electron_configuration = "[He]2s1";
        atomicWeight = 6.941; // 6.94 u (g/mol)
        atomicNumber = 3; // Z_ = 3
        energyLevels = {2, 1};
        densitySTP = 535.0; // 535.0 kg/m^3
        meltingPoint = 180.54; // 180.54 C
        boilingPoint = 1342.0; // 1342.0 C
        thermalConductivity = 85.0; // 85.0 W/mK
        electricConductivity = 11.0; // 11.0 MS/m
        resistivity = 9.40 * pow(10, -8); // 9.4e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 3570.0; // 3570.0 J/kgK
        heatVaporization = 147.0; // 147.0 kJ/mol
        heatFusion = 3.0; // 3.0 kJ/mol
        ionization1st = 5.391; // eV
    }
};

/**
 * @brief Beryllium is a chemical element with the symbol Be and atomic number 4.
 * It is a relatively rare element in the universe, usually occurring as a
 * product of the spallation of larger atomic nuclei that have collided
 * with cosmic rays. Within the cores of stars, beryllium is depleted as
 * it is fused into heavier elements.
 */
class Beryllium : public Element {
public:
    Beryllium() {
        group = 2;
        symbol = "Be";
        type = "Alkaline Earth Metal";
        crystal_type = "Hexagonal";
        electron_configuration = "[He]2s2";
        atomicWeight = 9.0121831; // 9.0121831 u (g/mol)
        atomicNumber = 4; //4
        energyLevels = {2, 2};
        densitySTP = 1848.0; // 1848.0 kg/m^3
        meltingPoint = 1287; // 1287 C
        boilingPoint = 2470; // 2470 C
        thermalConductivity = 190; // 190 W/mK
        electricConductivity = 25; // 25 MS/m
        resistivity = 3.999999999998 * pow(10, -8); // 4e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 1820.0; // 1820.0 J/kgK
        heatVaporization = 297.0; // 297.0 kJ/mol
        heatFusion = 7.95; // 7.95 kJ/mol
        ionization1st = 9.323; // eV
    }
};

/**
 * @brief Boron is a chemical element with the symbol B and atomic number 5.
 * Produced entirely by cosmic ray spallation and supernovae and not by
 * stellar nucleosynthesis, it is a low-abundance element in the Solar
 * System and in the Earth's crust. It constitutes about 0.001 percent
 * by weight of Earth's crust.
 */
class Boron : public Element {
public:
    Boron() {
        group = 13;
        symbol = "B";
        type = "Metalloid";
        crystal_type = "Rhombohedral";
        electron_configuration = "[He]2s2 2p1";
        atomicWeight = 10.81; // 10.81 u (g/mol)
        atomicNumber = 5; // 5
        energyLevels = {2, 3}; //add u (g/mol)p to atomic number
        densitySTP = 2460.0; // 2460.0 kg/m^3
        meltingPoint = 2075; // 2075 C
        boilingPoint = 4000; // 4000 C
        thermalConductivity = 27.0; // 27.0W/mK
        electricConductivity = 1; // MS/m
        resistivity = 10000.0; // 10000 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 1030.0; // J/kgK
        heatVaporization = 507.0; // kJ/mol
        heatFusion = 50.0; // kJ/mol
        ionization1st = 8.298; // eV
    }
};

/**
 * @brief Carbon is a chemical element with the symbol C and atomic number 6.
 * It is nonmetallic and tetravalent—making four electrons available to
 * form covalent chemical bonds. It belongs to group 14 of the periodic
 * table. Carbon makes up only about 0.025 percent of Earth's crust.
 */
class Carbon : public Element {
public:
    Carbon() {
        group = 14;
        symbol = "C";
        type = "Reactive Nonmetal";
        crystal_type = "Diamond";
        electron_configuration = "[He]2s2 2p2";
        atomicWeight = 12.011; // u (g/mol)
        atomicNumber = 6;
        energyLevels = {2, 4};
        densitySTP = 2260.0; // kg/m^3
        meltingPoint = 3550; // C
        boilingPoint = 4027; // C
        thermalConductivity = 140.0; // W/mK
        electricConductivity = .10; // MS/m
        resistivity = 0.00001; // 0.00001 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 710.0; // J/kgK
        heatVaporization = 715.0; // kJ/mol
        heatFusion = 105; // kJ/mol
        ionization1st = 11.261; // eV
    }
};

/**
 * @brief Nitrogen is the chemical element with the symbol N and atomic number 7.
 * It was first discovered and isolated by Scottish physician Daniel
 * Rutherford in 1772.
 */
class Nitrogen : public Element {
public:
    Nitrogen() {
        group = 15;
        symbol = "N";
        type = "Reactive Nonmetal";
        crystal_type = "Hexagonal";
        electron_configuration = "[He]2s2 2p3";
        atomicWeight = 14.007; // u (g/mol)
        atomicNumber = 7;
        energyLevels = {2, 5};
        densitySTP = 1.251; // kg/m^3
        meltingPoint = -210.1; // C
        boilingPoint = -195.8; // C
        thermalConductivity = .025; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; //FP_NAN
        heatSpecific = 1040; // J/kgK
        heatVaporization = 2.79; // kJ/mol
        heatFusion = .36; // kJ/mol
        ionization1st = 14.534; // eV
    }
};

/**
 * @brief Oxygen is the chemical element with the symbol O and atomic number 8.
 * It is a member of the chalcogen group in the periodic table, a highly
 * reactive nonmetal, and an oxidizing agent that readily forms oxides with
 * most elements as well as with other compounds.
 */
class Oxygen : public Element {
public:
    Oxygen() {
        group = 16;
        symbol = "O";
        type = "Reactive Nonmetal";
        crystal_type = "Simple Cubic";
        electron_configuration = "[He]2s2 2p4";
        atomicWeight = 15.999; // u (g/mol)
        atomicNumber = 8;
        energyLevels = {2, 6};
        densitySTP = 1.251; // kg/m^3
        meltingPoint = -218.0; // C
        boilingPoint = -183.0; // C
        thermalConductivity = 0.02658; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // FP_NAN
        heatSpecific = 919; // J/kgK
        heatVaporization = 3.41; // kJ/mol
        heatFusion = .222; // kJ/mol
        ionization1st = 13.681; // eV
    }
};

/**
 * @brief Fluorine is a chemical element with the symbol F and atomic number 9.
 * It is the lightest halogen and exists at standard conditions as a highly
 * toxic, pale yellow diatomic gas. As the most electronegative element,
 * it is extremely reactive, as it reacts with all other elements, except
 * for argon, neon, and helium.
 */
class Fluorine : public Element {
public:
    Fluorine() {
        group = 17;
        symbol = "F";
        type = "Reactive Nonmetal";
        crystal_type = "Monoclinc";
        electron_configuration = "[He]2s2 2p5";
        atomicWeight = 18.998403163; // u (g/mol)
        atomicNumber = 9;
        energyLevels = {2, 7};
        densitySTP = 1.696; // kg/m^3
        meltingPoint = -220.0; // C
        boilingPoint = -188.1; // C
        thermalConductivity = .0277; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // FP_NAN
        heatSpecific = 824; // J/kgK
        heatVaporization = 3.27; // kJ/mol
        heatFusion = .26; // kJ/mol
        ionization1st = 17.422; // eV
    }
};

/**
 * @brief Neon is a chemical element with the symbol Ne and atomic number 10.
 * It is a noble gas. Neon is a colorless, odorless, inert monatomic gas
 * u (g/mol)nder standard conditions, with about two-thirds the density of air.
 */
class Neon : public Element {
public:
    Neon() {
        group = 18;
        symbol = "Ne";
        type = "Noble Gas";
        crystal_type = "Face-Centered Cubic";
        electron_configuration = "[He]2s2 2p6";
        atomicWeight = 20.1797; // u (g/mol)
        atomicNumber = 10;
        energyLevels = {2, 8};
        densitySTP = .900; // kg/m^3
        meltingPoint = -248.6; // C
        boilingPoint = -246.1; // C
        thermalConductivity = .0491; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // FP_NAN
        heatSpecific = 1030; // J/kgK
        heatVaporization = 1.75; // kJ/mol
        heatFusion = 0.34; // kJ/mol
        ionization1st = 21.565; // eV
    }
};

/**
 * @brief Sodium is a chemical element with the symbol Na and atomic number 11.
 * It is a soft, silvery-white, highly reactive metal. Sodium is an
 * alkali metal, being in group 1 of the periodic table. Its only stable
 * isotope is ²³Na. The free metal does not occur in nature, and must be
 * prepared from compounds.
 */
class Sodium : public Element {
public:
    Sodium() {
        group = 1;
        symbol = "Na";
        type = "Alkali Metal";
        crystal_type = "Body-Centered Cubic";
        electron_configuration = "[Ne]3s1";
        atomicWeight = 22.98976928; // u (g/mol)
        atomicNumber = 11;
        energyLevels = {2, 8, 1};
        densitySTP = 968; // kg/m^3
        meltingPoint = 97.720; // C
        boilingPoint = 882.9; // C
        thermalConductivity = 140.0; // W/mK
        electricConductivity = 21.0; // MS/m
        resistivity = 4.69999999e-8; // 4.7e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 1230; // J/kgK
        heatVaporization = 97.7; // kJ/mol
        heatFusion = 2.60; // kJ/mol
        ionization1st = 5.139; // eV
    }
};

/**
 * @brief Magnesium is a chemical element with the symbol Mg and atomic
 * number 12. It is a shiny gray solid which bears a close physical
 * resemblance to the other five elements in the second column of the
 * periodic table: all group 2 elements have the same electron configuration
 * in the outer electron shell and a similar crystal structure.
 */
class Magnesium : public Element {
public:
    Magnesium() {
        group = 2;
        symbol = "Mg";
        type = "Alkaline Earth Metal";
        crystal_type = "Hexagonal Close Packed";
        electron_configuration = "[Ne]3s2";
        atomicWeight = 24.305; // u (g/mol)
        atomicNumber = 12;
        energyLevels = {2, 8, 2};
        densitySTP = 1738.0; // kg/m^3
        meltingPoint = 650; // C
        boilingPoint = 1090; // C
        thermalConductivity = 160.0; // W/mK
        electricConductivity = 23.0; // MS/m
        resistivity = 4.39999999e-8; // 4.4e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 1020; // J/kgK
        heatVaporization = 128; // kJ/mol
        heatFusion = 8.7; // kJ/mol
        ionization1st = 7.646; // eV
    }
};

/**
 * @brief Aluminium is a chemical element with the symbol Al and atomic
 * number 13. Aluminium has a density lower than those of other common
 * metals, at approximately one third that of steel. It has a great affinity
 * towards oxygen, and forms a protective layer of oxide on the surface when
 * exposed to air.
 */
class Aluminium : public Element {
public:
    Aluminium() {
        group = 13;
        symbol = "Al";
        type = "Post-Transition Metal";
        crystal_type = "Face-Centered Cubic";
        electron_configuration = "[Ne]3s2 3p1";
        atomicWeight = 26.9815385; // 26.9815385 u (g/mol)
        atomicNumber = 13; // 13
        energyLevels = {2, 8, 3};
        densitySTP = 2700; // 2700 kg/m^3
        meltingPoint = 660.32; // 660.32 C
        boilingPoint = 2519.0; // 2519C
        thermalConductivity = 235; // 235 W/mK
        electricConductivity = 38.0; // 38 MS/m
        resistivity = 2.6e-8; // 2.6e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 904.0; // 904 J/kgK
        heatVaporization = 293.0; // 293 kJ/mol
        heatFusion = 10.7; // 10.7 kJ/mol
        ionization1st = 5.985; // eV
    }
};

/**
 * @brief Silicon is a chemical element with the symbol Si and atomic number
 * 14. It is a hard, brittle crystalline solid with a blue-grey metallic
 * lustre, and is a tetravalent metalloid and semiconductor. It is a member
 * of group 14 in the periodic table: carbon is above it; and germanium, tin,
 * lead and flerovium, are below it
 */
class Silicon : public Element {
public:
    Silicon() {
        group = 14;
        symbol = "Si";
        type = "Metalloid";
        crystal_type = "Diamond Cubic";
        electron_configuration = "[Ne]3s2 3p2";
        atomicWeight = 28.085; // 28.085 u (g/mol)
        atomicNumber = 14; //14
        energyLevels = {2, 8, 4};
        densitySTP = 2330.0; // 2330 kg/m^3
        meltingPoint = 1414.0; // 1414 C
        boilingPoint = 2900.0; // 2000 C
        thermalConductivity = 150.0; // 150 W/mK
        electricConductivity = .0010; // .0010 MS/m
        resistivity = .001; // .001 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 710.0; // 710 J/kgK
        heatVaporization = 359.0; // 359 kJ/mol
        heatFusion = 50.2; // 50.2 kJ/mol
        ionization1st = 8.151; // eV
    }
};

/**
 * @brief Phosphorus is a chemical element with the symbol P and atomic number
 * 15. Elemental phosphorus exists in two major forms, white phosphorus and
 * red phosphorus, but because it is highly reactive, phosphorus is never
 * found as a free element on Earth.
 */
class Phosphorus : public Element {
public:
    Phosphorus() {
        group = 15;
        symbol = "P";
        type = "Reactive Nonmetal";
        crystal_type = "Orthorhombic";
        electron_configuration = "[Ne]3s2 3p3";
        atomicWeight = 30.973761998; // 30.973761998 u (g/mol)
        atomicNumber = 15; //15
        energyLevels = {2, 8, 5};
        densitySTP = 1823.0; // 1823 kg/m^3
        meltingPoint = 44.15; // 44.15 C
        boilingPoint = 280.5; // 280.5 C
        thermalConductivity = .236; // .236 W/mK
        electricConductivity = 10.0; // 10 MS/m
        resistivity = 1e-7; // 1e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 769.7; // 769.7 J/kgK
        heatVaporization = 12.4; // 12.4 kJ/mol
        heatFusion = .64; // .64 kJ/mol
        ionization1st = 10.487; // eV
    }
};

/**
 * @brief Sulfur is a chemical element with the symbol S and atomic number 16.
 * It is abundant, multivalent and nonmetallic. Under normal conditions,
 * sulfur atoms form cyclic octatomic molecules with a chemical formula S₈.
 * Elemental sulfur is a bright yellow, crystalline solid at room temperature
 */
class Sulfur : public Element {
public:
    Sulfur() {
        group = 16;
        symbol = "S";
        type = "Reactive Nonmetal";
        crystal_type = "Orthorhombic";
        electron_configuration = "[Ne]3s2 3p4";
        atomicWeight = 32.06; // 32.06 u (g/mol)
        atomicNumber = 16; // 16
        energyLevels = {2, 8, 6};
        densitySTP = 1960.0; // 1960.0 kg/m^3
        meltingPoint = 115.21; // 115.21 C
        boilingPoint = 444.72; // 444.72 C
        thermalConductivity = .205; // .205 W/mK
        electricConductivity = pow(1.0, -21); // 1e-21 MS/m
        resistivity = 1e15; // 1e15 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 705.0; // 705 J/kgK
        heatVaporization = 9.8; // 9.8 kJ/mol
        heatFusion = 1.73; // 1.73 kJ/mol
        ionization1st = 10.36; // eV
    }
};

/**
 * @brief Chlorine is a chemical element with the symbol Cl and atomic number 17.
 * The second-lightest of the halogens, it appears between fluorine and
 * bromine in the periodic table and its properties are mostly intermediate
 * between them. Chlorine is a yellow-green gas at room temperature.
 */
class Chlorine : public Element {
public:
    Chlorine() {
        group = 17;
        symbol = "Cl";
        type = "Reactive Nonmetal";
        crystal_type = "Orthorhombic";
        electron_configuration = "[Ne]3s2 3p5";
        atomicWeight = 35.45; // 35.45 u (g/mol)
        atomicNumber = 17; //17
        energyLevels = {2, 8, 7};
        densitySTP = 3.214; // 3.214 kg/m^3
        meltingPoint = -101.5; // -101.5 C
        boilingPoint = -34.040; // -34.040 C
        thermalConductivity = .0089; // .0089 W/mK
        electricConductivity = pow(1.0, -8.0); // 1e-8 MS/m
        resistivity = 100; // 100 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 478.2; // 478.2 J/kgK
        heatVaporization = 10.2; // 10.2 kJ/mol
        heatFusion = 3.2; // 3.2 kJ/mol
        ionization1st = 12.968; // eV
    }
};

/**
 * @brief Argon is a chemical element with the symbol Ar and atomic number 18.
 * It is in group 18 of the periodic table and is a noble gas. Argon is
 * the third-most abundant gas in the Earth's atmosphere, at 0.934%
 */
class Argon : public Element {
public:
    Argon() {
        group = 18;
        symbol = "Ar";
        type = "Noble Gas";
        crystal_type = "Face-Centered Cubic";
        electron_configuration = "[Ne]3s2 3p6";
        atomicWeight = 39.948; // 39.948 u (g/mol)
        atomicNumber = 18; //18
        energyLevels = {2, 8, 8};
        densitySTP = 1784.0; // 1784 kg/m^3
        meltingPoint = -189; // -189 C
        boilingPoint = -186; // -186 C
        thermalConductivity = .01772; // .01772 W/mK
        electricConductivity = FP_NAN; // FP_NAN
        resistivity = FP_NAN; // FP_NAN
        heatSpecific = 520.33; // 520.33 J/kgK
        heatVaporization = 6.5; // 6.5 kJ/mol
        heatFusion = 1.18; // 1.18 kJ/mol
        ionization1st = 15.760; // eV
    }
};

/**
 * @brief Potassium is a chemical element with the symbol K and atomic number 19.
 * Potassium is a silvery-white metal that is soft enough to be cut with a
 * knife with little force. Potassium metal reacts rapidly with atmospheric
 * oxygen to form flaky white potassium peroxide in only seconds of exposure.
 */
class Potassium : public Element {
public:
    Potassium() {
        group = 1;
        symbol = "K";
        type = "Alkali Metal";
        crystal_type = "Body-Centered Cubic";
        electron_configuration = "[Ar]4s1";
        atomicWeight = 39.0983; // 39.0983 u (g/mol)
        atomicNumber = 19; // 19
        energyLevels = {2, 8, 8, 1};
        densitySTP = 856; // 856 kg/m^3
        meltingPoint = 63.380; // 63.38C
        boilingPoint = 758.9; // 758.9C
        thermalConductivity = 100.0; // 100 W/mK
        electricConductivity = 14.0; // 14 MS/m
        resistivity = 7.000000000002e-8; // 7.0e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 757; // 757 J/kgK
        heatVaporization = 76.9; // 76.9 kJ/mol
        heatFusion = 2.33; // 2.33kJ/mol
        ionization1st = 4.341; // eV
    }
};

/**
 * @brief Calcium is a chemical element with the symbol Ca and atomic number 20.
 * As an alkaline earth metal, calcium is a reactive metal that forms a
 * dark oxide-nitride layer when exposed to air. ... It is the fifth most
 * abundant element in Earth's crust, and the third most abundant metal,
 * after iron and aluminium
 */
class Calcium : public Element {
public:
    Calcium() {
        group = 2;
        symbol = "Ca";
        type = "Alkaline Earth Metal";
        crystal_type = "Face-Centered Cubic";
        electron_configuration = "[Ar]4s2";
        atomicWeight = 40.078; // 40.078 u (g/mol)
        atomicNumber = 20; // 20
        energyLevels = {2, 8, 8, 2};
        densitySTP = 1550.0; // 1550kg/m^3
        meltingPoint = 841.9; // 841.9C
        boilingPoint = 1484; // 1484 C
        thermalConductivity = 200.0; //200 W/mK
        electricConductivity = 29; // 29 MS/m
        resistivity = 3.39999999e-8; // 3.4e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 631; // 631 J/kgK
        heatVaporization = 155.0; // 155 kJ/mol
        heatFusion = 8.54; // 8.54 kJ/mol
        ionization1st = 6.113; // eV
    }
};

/**
 * @brief Scandium is a chemical element with the symbol Sc and atomic number 21.
 * A silvery-white metallic d-block element, it has historically been
 * classified as a rare-earth element, together with yttrium and the
 * lanthanide.
 */
class Scandium : public Element {
public:
    Scandium() {
        group = 3;
        symbol = "Sc";
        type = "Transition Metal";
        crystal_type = "Hexagonal Close Packed";
        electron_configuration = "[Ar]3d1 4s2";
        atomicWeight = 44.955908; // 44.955908 u (g/mol)
        atomicNumber = 21; // 21
        energyLevels = {2, 8, 9, 2};
        densitySTP = 2985.0; // 2985 kg/m^3
        meltingPoint = 1541.0; // 1541 C
        boilingPoint = 2830.0; // 2830 C
        thermalConductivity = 16; // 16W/mK
        electricConductivity = 1.8; // 1.8 MS/m
        resistivity = 5.5e-7; // 5.5e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 567.0; // 567 J/kgK
        heatVaporization = 318.0; // 318 kJ/mol
        heatFusion = 16.0; // 16 kJ/mol
        ionization1st = 6.562; // eV
    }
};

/**
 * @brief Titanium is a chemical element with the symbol Ti and atomic number 22.
 * Its atomic weight is 47.867 measured in daltons. It is a lustrous
 * transition metal with a silver color, low density, and high strength.
 * Titanium is resistant to corrosion in sea water, aqua regia, and chlorine.
 */
class Titanium : public Element {
public:
    Titanium() {
        group = 4;
        symbol = "Ti";
        type = "Transition Metal";
        crystal_type = "Hexagonal Close Packed";
        electron_configuration = "[Ar]3d2 4s2";
        atomicWeight = 47.867; // 47.867 u (g/mol)
        atomicNumber = 22; //22
        energyLevels = {2, 8, 10, 2};
        densitySTP = 4507.0; // 4507 kg/m^3
        meltingPoint = 1668.0; // 1668 C
        boilingPoint = 3287.0; // 3287 C
        thermalConductivity = 22.0; // 22.0 W/mK
        electricConductivity = 2.5; // 2.5 MS/m
        resistivity = 4e-7; // 4e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 520.0; // 525 J/kgK
        heatVaporization = 425.0; // 425 kJ/mol
        heatFusion = 18.7; // 18.7 kJ/mol
        ionization1st = 6.828; // eV
    }
};

/**
 * @brief Vanadium is a chemical element with the symbol V and atomic number 23.
 * It is a hard, silvery-grey, malleable transition metal. The elemental
 * metal is rarely found in nature, but once isolated artificially, the
 * formation of an oxide layer somewhat stabilizes the free metal against
 * further oxidation.
 */
class Vanadium : public Element {
public:
    Vanadium() {
        group = 5;
        symbol = "V";
        type = "Transition Metal";
        crystal_type = "Body-Centered Cubic";
        electron_configuration = "[Ar]3d3 4s2";
        atomicWeight = 50.9415; // 50.9415 u (g/mol)
        atomicNumber = 23; //23
        energyLevels = {2, 8, 11, 2};
        densitySTP = 6110; // 6110 kg/m^3
        meltingPoint = 1910; // 1910 C
        boilingPoint = 3407; // 3407 C
        thermalConductivity = 31; // 31 W/mK
        electricConductivity = 5; // 5 MS/m
        resistivity = 2e-7; // 2e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 489; // 489 J/kgK
        heatVaporization = 453; // 453 kJ/mol
        heatFusion = 22.8; // 22.8 kJ/mol
        ionization1st = 6.746; // eV
    }
};

/**
 * @brief Chromium is a chemical element with the symbol Cr and atomic number 24.
 * It is the first element in group 6. It is a steely-grey, lustrous, hard, and
 * brittle transition metal. Chromium is the main additive in stainless steel,
 * to which it adds anti-corrosive properties.
 */
class Chromium : public Element {
public:
    Chromium() {
        group = 6;
        symbol = "Cr";
        type = "Transition Metal";
        crystal_type = "Body-Centered Cubic";
        electron_configuration = "[Ar]3d5 4s1";
        atomicWeight = 51.996; // 51.996 u (g/mol)
        atomicNumber = 24; //24
        energyLevels = {2, 8, 13, 1};
        densitySTP = 7190; // 7190 kg/m^3
        meltingPoint = 1907; // 1907 C
        boilingPoint = 2671; // 2671 C
        thermalConductivity = 94; // 94 W/mK
        electricConductivity = 7.9; // 7.9 MS/m
        resistivity = 1.3e-7; // 1.3e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 448; // 448 J/kgK
        heatVaporization = 339; // 339 kJ/mol
        heatFusion = 20.5; // 20.5 kJ/mol
        ionization1st = 6.767; // eV
    }
};

/**
 * @brief Manganese is a chemical element with the symbol Mn and atomic number 25.
 * It is not found as a free element in nature; it is often found in minerals
 * in combination with iron. Manganese is a transition metal with a
 * multifaceted array of industrial alloy u (g/mol)ses, particularly in
 * stainless steels.
 */
class Manganese : public Element {
public:
    Manganese() {
        group = 7;
        symbol = "Mn";
        type = "Transition Metal";
        crystal_type = "Body-Centered Cubic";
        electron_configuration = "[Ar]3d5 4s2";
        atomicWeight = 54.938; // 54.938 u (g/mol)
        atomicNumber = 25; //25
        energyLevels = {2, 8, 13, 2};
        densitySTP = 7470; // 7470 kg/m^3
        meltingPoint = 1246; // 1246 C
        boilingPoint = 2061; // 2061 C
        thermalConductivity = 7.8; // 7.8 W/mK
        electricConductivity = .62; // .62 MS/m
        resistivity = 1.6e-6; // 1.6e-6 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 479; // 479 J/kgK
        heatVaporization = 220; // 220 kJ/mol
        heatFusion = 13.2; // 13.2 kJ/mol
        ionization1st = 7.434; // eV
    }
};

/**
 * @brief Iron is a chemical element with symbol Fe and atomic number 26.
 * It is a metal that belongs to the first transition series and group
 * 8 of the periodic table. It is, by mass, the most common element on
 * Earth, right in front of oxygen, forming much of Earth's outer and
 * inner core.
 */
class Iron : public Element {
public:
    Iron() {
        group = 8;
        symbol = "Fe";
        type = "Transition Metal";
        crystal_type = "Body-Centered Cubic";
        electron_configuration = "[Ar]3d6 4s2";
        atomicWeight = 55.845; // 55.845 u (g/mol)
        atomicNumber = 26; //26
        energyLevels = {2, 8, 14, 2};
        densitySTP = 7874; // 7874 kg/m^3
        meltingPoint = 1538; // 1538 C
        boilingPoint = 2861; // 2861 C
        thermalConductivity = 80; // 80 W/mK
        electricConductivity = 10; // 10 MS/m
        resistivity = 9.7e-8; // 9.7e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 449; // 449 J/kgK
        heatVaporization = 347; // 347 kJ/mol
        heatFusion = 13.8; // 13.8 kJ/mol
        ionization1st = 7.903; // eV
    }
};

/**
 * @brief Cobalt is a chemical element with the symbol Co and atomic number 27.
 * Like nickel, cobalt is found in the Earth's crust only in a chemically
 * combined form, save for small deposits found in alloys of natural meteoric
 * iron. The free element, produced by reductive smelting, is a hard,
 * lustrous, silver-gray metal.
 */
class Cobalt : public Element {
public:
    Cobalt() {
        group = 9;
        symbol = "Co";
        type = "Transition Metal";
        crystal_type = "Hexagonal Close Packed";
        electron_configuration = "[Ar]3d7 4s2";
        atomicWeight = 58.933; // 58.933 u (g/mol)
        atomicNumber = 27; //27
        energyLevels = {2, 8, 15, 2};
        densitySTP = 8900; // 8900 kg/m^3
        meltingPoint = 1495; // 1495 C
        boilingPoint = 2900; // 2900 C
        thermalConductivity = 100; // 100 W/mK
        electricConductivity = 17; // 17 MS/m
        resistivity = 6e-8; // 6e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 421; // 421 J/kgK
        heatVaporization = 375; // 375 kJ/mol
        heatFusion = 16.2; // 16.2 kJ/mol
        ionization1st = 7.881; // eV
    }
};

/**
 * @brief Nickel is a chemical element with the symbol Ni and atomic number 28.
 * It is a silvery-white lustrous metal with a slight golden tinge.
 * Nickel belongs to the transition metals and is hard and ductile.
 */
class Nickel : public Element {
public:
    Nickel() {
        group = 10;
        symbol = "Ni";
        type = "Transition Metal";
        crystal_type = "Face-Centered Cubic";
        electron_configuration = "[Ar]3d8 4s2";
        atomicWeight = 58.693; // 58.693 u (g/mol)
        atomicNumber = 28; //28
        energyLevels = {2, 8, 16, 2};
        densitySTP = 8908.0; // 8908.0 kg/m^3
        meltingPoint = 1455; // 1455 C
        boilingPoint = 2913; // 2913 C
        thermalConductivity = 91; // 91 W/mK
        electricConductivity = 14; // 14 MS/m
        resistivity = 7e-8; // 7e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 445; // 445 J/kgK
        heatVaporization = 378; // 378 kJ/mol
        heatFusion = 17.2; // 17.2 kJ/mol
        ionization1st = 7.641; // eV
    }
};

/**
 * @brief Copper is a chemical element with the symbol Cu and atomic number 29.
 * It is a soft, malleable, and ductile metal with very high thermal and
 * electrical conductivity. A freshly exposed surface of pure copper has
 * a pinkish-orange color.
 */
class Copper : public Element
{
public:
    Copper() {
        group = 11;
        symbol = "Cu";
        type = "Transition Metal";
        crystal_type = "Face-Centered Cubic";
        electron_configuration = "[Ar]3d10 4s1";
        atomicWeight = 63.546; // 63.546 u (g/mol)
        atomicNumber = 29; //29
        energyLevels = {2, 8, 18, 1};
        densitySTP = 8940.0; // 8940.0 kg/m^3
        meltingPoint = 1084.62; // 1084.62 C
        boilingPoint = 2562; // 2562 C
        thermalConductivity = 400; // 400 W/mK
        electricConductivity = 59; // 59 MS/m
        resistivity = 1.7e-8; // 1.7e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 384.4; // 384.4 J/kgK
        heatVaporization = 300; // 300 kJ/mol
        heatFusion = 13.1; // 13.1 kJ/mol
        ionization1st = 7.727; // eV
    }
};

/**
 * @brief Zinc is a chemical element with the symbol Zn and atomic number 30.
 * Zinc is a slightly brittle metal at room temperature and has a
 * silvery-grayish appearance when oxidation is removed. It is the first
 * element in group 12 of the periodic table.
 */
class Zinc : public Element {
public:
    Zinc() {
        group = 12;
        symbol = "Zn";
        type = "Transition Metal";
        crystal_type = "Hexagonal Close-Packed";
        electron_configuration = "[Ar]3d10 4s2";
        atomicWeight = 65.38; // 65.38 u (g/mol)
        atomicNumber = 30; //30
        energyLevels = {2, 8, 18, 2};
        densitySTP = 7140; // 7140 kg/m^3
        meltingPoint = 419.53; // 419.53 C
        boilingPoint = 906.9; // 906.9 C
        thermalConductivity = 120; // 120 W/mK
        electricConductivity = 17; // 17 MS/m
        resistivity = 5.9e-8; // 5.9e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 388; // 388 J/kgK
        heatVaporization = 119; // 119 kJ/mol
        heatFusion = 7.35; // 7.35 kJ/mol
        ionization1st = 9.394; // eV
    }
};

/**
 * @brief Gallium is a chemical element with the symbol Ga and atomic number 31.
 * Elemental gallium is a soft, silvery metal at standard temperature and
 * pressure; however in its liquid state it becomes silvery white. If too
 * much force is applied, the gallium may fracture conchoidally.
 */
class Gallium : public Element {
public:
    Gallium() {
        group = 13;
        symbol = "Ga";
        type = "Post-Transition Metal";
        crystal_type = "Orthorhombic";
        electron_configuration = "[Ar]3d10 4s2 4p1";
        atomicWeight = 69.723; // 69.723 u (g/mol)
        atomicNumber = 31; //31
        energyLevels = {2, 8, 18, 3};
        densitySTP = 5904.0; // 5904.0 kg/m^3
        meltingPoint = 29.760; // 29.760 C
        boilingPoint = 2204.0; // 2204.0 C
        thermalConductivity = 29.0; // 29.0 W/mK
        electricConductivity = 7.1; // 7.1 MS/m
        resistivity = 1.4e-7; // 1.4e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 371.0; // 371.0 J/kgK
        heatVaporization = 256.0; // 256.0 kJ/mol
        heatFusion = 5.59; // 5.59 kJ/mol
        ionization1st = 5.999; // eV
    }
};

/**
 * @brief Germanium is a chemical element with the symbol Ge and atomic number 32.
 * It is a lustrous, hard-brittle, grayish-white metalloid in the carbon
 * group, chemically similar to its group neighbors silicon and tin.
 * Pure germanium is a semiconductor with an appearance similar to
 * elemental silicon.
 */
class Germanium : public Element {
public:
    Germanium() {
        group = 14;
        symbol = "Ge";
        type = "Metalloid";
        crystal_type = "Diamond Cubic";
        electron_configuration = "[Ar]3d10 4s2 4p2";
        atomicWeight = 72.630; // 72.630 u (g/mol)
        atomicNumber = 32; //32
        energyLevels = {2, 8, 18, 4};
        densitySTP = 5323; // 5323 kg/m^3
        meltingPoint = 938.25; // 938.25 C
        boilingPoint = 2820; // 2820 C
        thermalConductivity = 60.0; // 60.0 W/mK
        electricConductivity = .0020; // .0020 MS/m
        resistivity = .0005; // .0005 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 321.4; // 321.4 J/kgK
        heatVaporization = 334.0; // 334.0 kJ/mol
        heatFusion = 31.8; // 31.8 kJ/mol
        ionization1st = 7.90; // eV
    }
};

/**
 * @brief Arsenic is a chemical element with the symbol As and atomic number 33.
 * Arsenic occurs in many minerals, u (g/mol)sually in combination with sulfur and
 * metals, but also as a pure elemental crystal. Arsenic is a metalloid.
 */
class Arsenic : public Element {
public:
    Arsenic() {
        group = 15;
        symbol = "As";
        type = "Metalloid";
        crystal_type = "Rhombohedral";
        electron_configuration = "[Ar]3d10 4s2 4p3";
        atomicWeight = 74.922; // 74.922 u (g/mol)
        atomicNumber = 33; //33
        energyLevels = {2, 8, 18, 5};
        densitySTP = 5727; // 5727 kg/m^3
        meltingPoint = 816.9; // 816.9 C
        boilingPoint = 614; // 614 C
        thermalConductivity = 50.0; // 50.0 W/mK
        electricConductivity = 3.3; // 3.3 MS/m
        resistivity = 3e-7; // 3e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 328.0; // 328.0 J/kgK
        heatVaporization = 32.4; // 32.4 kJ/mol
        heatFusion = 27.7; // 27.7 kJ/mol
        ionization1st = 9.815; // eV
    }
};

/**
 * @brief Selenium is a chemical element with the symbol Se and atomic number 34.
 * It is a nonmetal with properties that are intermediate between the
 * elements above and below in the periodic table, sulfur and tellurium,
 * and also has similarities to arsenic
 */
class Selenium : public Element {
public:
    Selenium() {
        group = 16;
        symbol = "Se";
        type = "Reactive Nonmetal";
        crystal_type = "Hexagonal";
        electron_configuration = "[Ar]3d10 4s2 4p4";
        atomicWeight = 78.971; // 78.971 u (g/mol)
        atomicNumber = 34; //34
        energyLevels = {2, 8, 18, 6};
        densitySTP = 4819; // 4819 kg/m^3
        meltingPoint = 221; // 221 C
        boilingPoint = 685; // 685 C
        thermalConductivity = 0; // 0 W/mK
        electricConductivity = FP_NAN; // FP_NAN MS/m
        resistivity = FP_NAN; // FP_NAN m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 321.2; // 321.2 J/kgK
        heatVaporization = 26.0; // 26.0 kJ/mol
        heatFusion = 5.4; // 5.4 kJ/mol
        ionization1st = 9.753; // eV
    }
};

/**
 * @brief Bromine is a chemical element with the symbol Br and atomic number 35.
 * It is the third-lightest halogen, and is a fuming red-brown liquid at
 * room temperature that evaporates readily to form a similarly coloured
 * vapour. Its properties are intermediate between those of chlorine
 * and iodine.
 */
class Bromine : public Element {
public:
    Bromine() {
        group = 17;
        symbol = "Br";
        type = "Reactive Nonmetal";
        crystal_type = "Orthorhombic";
        electron_configuration = "[Ar]3d10 4s2 4p5";
        atomicWeight = 79.904; // 79.904 u (g/mol)
        atomicNumber = 35; //35
        energyLevels = {2, 8, 18, 7};
        densitySTP = 3120; // 3120 kg/m^3
        meltingPoint = -7.350; // -7.350 C
        boilingPoint = 58.9; // 58.9 C
        thermalConductivity = 0.12; // 0.12 W/mK
        electricConductivity = 1.0e-16; // 1.0e-16 MS/m
        resistivity = 1.0e10; // 1.0e10 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 947.3; // 947.3 J/kgK
        heatVaporization = 14.8; // 14.8 kJ/mol
        heatFusion = 5.8; // 5.8 kJ/mol
        ionization1st = 11.814; // eV
    }
};

/**
 * @brief Krypton is a chemical element with the symbol Kr and atomic number 36.
 * It is a colorless, odorless, tasteless noble gas that occurs in trace
 * amounts in the atmosphere and is often u (g/mol)sed with other rare gases in
 * fluorescent lamps. With rare exceptions, krypton is chemically inert
 */
class Krypton : public Element {
public:
    Krypton() {
        group = 18;
        symbol = "Kr";
        type = "Noble Gas";
        crystal_type = "Face-Centered Cubic";
        electron_configuration = "[Ar]3d10 4s2 4p6";
        atomicWeight = 83.798; // 83.798 u (g/mol)
        atomicNumber = 36; //36
        energyLevels = {2, 8, 18, 8};
        densitySTP = 3.75; // 3.75 kg/m^3
        meltingPoint = -157.36; // -157.36 C
        boilingPoint = -153.22; // -153.22 C
        thermalConductivity = 0.00943; // 0.00943 W/mK
        electricConductivity = FP_NAN; // FP_NAN MS/m
        resistivity = FP_NAN; // FP_NAN m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 248.05; // 248.05 J/kgK
        heatVaporization = 9.02; // 9.02 kJ/mol
        heatFusion = 1.64; // 1.64 kJ/mol
        ionization1st = 14.000; // eV
    }
};

/**
 * @brief Rubidium is the chemical element with the symbol Rb and atomic number 37.
 * Rubidium is a very soft, silvery-white metal in the alkali metal group.
 * Rubidium metal shares similarities to potassium metal and caesium metal
 * in physical appearance, softness and conductivity.
 */
class Rubidium : public Element {
public:
    Rubidium() {
        group = 1;
        symbol = "Rb";
        type = "Alkali Metal";
        crystal_type = "Body-Centered Cubic";
        electron_configuration = "[Kr]5s1";
        atomicWeight = 85.468; // 85.468 u (g/mol)
        atomicNumber = 37; //37
        energyLevels = {2, 8, 18, 8, 1};
        densitySTP = 1532; // 1532 kg/m^3
        meltingPoint = 39.310; // 39.310 C
        boilingPoint = 688.0; // 688.0 C
        thermalConductivity = 58.0; // 58.0 W/mK
        electricConductivity = 8.30; // 8.30 MS/m
        resistivity = 1.2e-7; // 1.2e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 364; // 364 J/kgK
        heatVaporization = 72.0; // 72.0 kJ/mol
        heatFusion = 2.19; // 2.19 kJ/mol
        ionization1st = 4.177; // eV
    }
};

/**
 * @brief Strontium is the chemical element with the symbol Sr and atomic number 38.
 * An alkaline earth metal, strontium is a soft silver-white yellowish metallic
 * element that is highly chemically reactive. The metal forms a dark oxide
 * layer when it is exposed to air.
 */
class Strontium : public Element {
public:
    Strontium() {
        group = 2;
        symbol = "Sr";
        type = "Alkaline Earth Metal";
        crystal_type = "Face-Centered Cubic";
        electron_configuration = "[Kr]5s2";
        atomicWeight = 87.62; // 87.62 u (g/mol)
        atomicNumber = 38; //38
        energyLevels = {2, 8, 18, 8, 2};
        densitySTP = 2630; // 2630 kg/m^3
        meltingPoint = 776.9; // 776.9 C
        boilingPoint = 1382.0; // 1382.0 C
        thermalConductivity = 35; // 35 W/mK
        electricConductivity = 7.7; // 7.7 MS/m
        resistivity = 1.3e-7; // 1.3e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 300.0; // 300.0 J/kgK
        heatVaporization = 137.0; // 137.0 kJ/mol
        heatFusion = 8.0; // 8.0 kJ/mol
        ionization1st = 5.695; // eV
    }
};

/**
 * @brief Yttrium is a chemical element with the symbol Y_ and atomic number 39.
 * It is a silvery-metallic transition metal chemically similar to the
 * lanthanides and has often been classified as a "rare-earth element"
 */
class Yttrium : public Element {
public:
    Yttrium() {
        group = 3;
        symbol = "Y";
        type = "Transition Metal";
        crystal_type = "Hexagonal Close Packed";
        electron_configuration = "[Kr]4d1 5s2";
        atomicWeight = 88.906; // 88.906 u (g/mol)
        atomicNumber = 39; //39
        energyLevels = {2, 8, 18, 9, 2};
        densitySTP = 4472; // 4472 kg/m^3
        meltingPoint = 1526.0; // 1526.0 C
        boilingPoint = 3345.0; // 3345.0 C
        thermalConductivity = 17; // 17 W/mK
        electricConductivity = 1.80; // 1.80 MS/m
        resistivity = 5.6e-7; // 5.6e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 298.0; // 298.0 J/kgK
        heatVaporization = 380.0; // 380.0 kJ/mol
        heatFusion = 11.4; // 11.4 kJ/mol
        ionization1st = 6.22; // eV
    }
};

/**
 * @brief Zirconium is a chemical element with the symbol Zr and atomic number 40.
 * The name zirconium is taken from the name of the mineral zircon, the
 * most important source of zirconium. It is a lustrous, grey-white, strong
 * transition metal that closely resembles hafnium and, to a lesser
 * extent, titanium.
 */
class Zirconium : public Element {
public:
    Zirconium() {
        group = 4;
        symbol = "Zr";
        type = "Transition Metal";
        crystal_type = "Hexagonal Close Packed";
        electron_configuration = "[Kr]4d2 5s2";
        atomicWeight = 91.224; // 91.224 u (g/mol)
        atomicNumber = 40; //40
        energyLevels = {2, 8, 18, 10, 2};
        densitySTP = 6511; // 6511 kg/m^3
        meltingPoint = 1855.0; // 1855.0 C
        boilingPoint = 4409.0; // 4409.0 C
        thermalConductivity = 23; // 23 W/mK
        electricConductivity = 2.4; // 2.4 MS/m
        resistivity = 4.2e-7; // 4.2e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 278.0; // 278.0 J/kgK
        heatVaporization = 580.0; // 580.0 kJ/mol
        heatFusion = 21.0; // 21.0 kJ/mol
        ionization1st = 6.634; // eV
    }
};

/**
 * @brief Niobium, also known as columbium,
 * is a chemical element with the symbol Nb and atomic number 41.
 * Niobium is a light grey, crystalline, and ductile transition metal.
 * Pure niobium has a Mohs hardness rating similar to that of pure titanium,
 * and it has similar ductility to iron.
 */
class Niobium : public Element {
public:
    Niobium() {
        group = 5;
        symbol = "Nb";
        type = "Transition Metal";
        crystal_type = "Body-Centered Cubic";
        electron_configuration = "[Kr]4d4 5s1";
        atomicWeight = 92.906; // 92.906 u (g/mol)
        atomicNumber = 41; //41
        energyLevels = {2, 8, 18, 12, 1};
        densitySTP = 8570; // 8570 kg/m^3
        meltingPoint = 2477.0; // 2477.0 C
        boilingPoint = 4744.0; // 4744.0 C
        thermalConductivity = 54; // 54 W/mK
        electricConductivity = 6.7; // 6.7 MS/m
        resistivity = 1.5e-7; // 1.5e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 265.0; // 265.0 J/kgK
        heatVaporization = 690.0; // 690.0 kJ/mol
        heatFusion = 26.8; // 26.8 kJ/mol
        ionization1st = 6.759; // eV
    }
};

/**
 * @brief Molybdenum is a chemical element with the symbol Mo and atomic number 42.
 * The name is from Neo-Latin molybdaenum, which is based on Ancient Greek
 * Μόλυβδος molybdos, meaning lead, since its ores were confused with lead ores.
 */
class Molybdenum : public Element {
public:
    Molybdenum() {
        group = 6;
        symbol = "Mo";
        type = "Transition Metal";
        crystal_type = "Body-Centered Cubic";
        electron_configuration = "[Kr]4d5 5s1";
        atomicWeight = 95.95; // 95.95 u (g/mol)
        atomicNumber = 42; //42
        energyLevels = {2, 8, 18, 13, 1};
        densitySTP = 10280; // 10280 kg/m^3
        meltingPoint = 2623.0; // 2623.0 C
        boilingPoint = 4639.0; // 4639.0 C
        thermalConductivity = 139.0; // 139.0 W/mK
        electricConductivity = 20.0; // 20.0 MS/m
        resistivity = 5.0e-8; // 5.0e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 251.0; // 251.0 J/kgK
        heatVaporization = 600.0; // 600.0 kJ/mol
        heatFusion = 36.0; // 36.0 kJ/mol
        ionization1st = 7.092; // eV
    }
};
/**
 * @brief Technetium is a chemical element with the symbol Tc and atomic number 43.
 * It is the lightest element whose isotopes are all radioactive, none of
 * which is stable other than the fully ionized state of ⁹⁷Tc. Nearly all
 * available technetium is produced as a synthetic element.
 */
class Technetium : public Element {
public:
    Technetium() {
        group = 7;
        symbol = "Tc";
        type = "Transition Metal";
        crystal_type = "Hexagonal Close Packed";
        electron_configuration = "[Kr]4d5 5s2";
        atomicWeight = (98); // (98) u (g/mol)
        atomicNumber = 43; //43
        energyLevels = {2, 8, 18, 13, 2};
        densitySTP = 11500; // 11500 kg/m^3
        meltingPoint = 2157.0; // 2157.0 C
        boilingPoint = 4265.0; // 4265.0 C
        thermalConductivity = 51.0; // 51.0 W/mK
        electricConductivity = 5.0; // 5.0 MS/m
        resistivity = 2.0e-7; // 2.0e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 63.0; // 63.0 J/kgK
        heatVaporization = 550.0; // 550.0 kJ/mol
        heatFusion = 23.0; // 23.0 kJ/mol
        ionization1st = 7.28; // eV
    }
};

/**
 * @brief Ruthenium is a chemical element with the symbol Ru and atomic number 44.
 * It is a rare transition metal belonging to the platinum group of the
 * periodic table. Like the other metals of the platinum group, ruthenium
 * is inert to most other chemicals.
 */
class Ruthenium : public Element {
public:
    Ruthenium() {
        group = 8;
        symbol = "Ru";
        type = "Transition Metal";
        crystal_type = "Hexagonal Close Packed";
        electron_configuration = "[Kr]4d7 5s1";
        atomicWeight = 101.07; // 101.07 u (g/mol)
        atomicNumber = 44; //44
        energyLevels = {2, 8, 18, 15, 1};
        densitySTP = 12370; // 12370 kg/m^3
        meltingPoint = 2334.0; // 2334.0 C
        boilingPoint = 4150.0; // 4150.0 C
        thermalConductivity = 120.0; // 120.0 W/mK
        electricConductivity = 14.0; // 14.0 MS/m
        resistivity = 7.1e-8; // 7.1e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 238.0; // 238.0 J/kgK
        heatVaporization = 580.0; // 580.0 kJ/mol
        heatFusion = 25.7; // 25.7 kJ/mol
        ionization1st = 7.361; // eV
    }
};

/**
 * @brief Rhodium is a chemical element with the symbol Rh and atomic number 45.
 * It is an extraordinarily rare, silvery-white, hard, corrosion-resistant,
 * and chemically inert transition metal. It is a noble metal and a member
 * of the platinum group. It has only one naturally occurring isotope, ¹⁰³Rh
 */
class Rhodium : public Element {
public:
    Rhodium() {
        group = 9;
        symbol = "Rh";
        type = "Transition Metal";
        crystal_type = "Face-Centered Cubic";
        electron_configuration = "[Kr]4d8 5s1";
        atomicWeight = 102.91; // 102.91 u (g/mol)
        atomicNumber = 45; //45
        energyLevels = {2, 8, 18, 16, 1};
        densitySTP = 12450; // 12450 kg/m^3
        meltingPoint = 1964.0; // 1964.0 C
        boilingPoint = 3695.0; // 3695.0 C
        thermalConductivity = 150.0; // 150.0 W/mK
        electricConductivity = 23.0; // 23.0 MS/m
        resistivity = 4.3e-8; // 4.3e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 240.0; // 240.0 J/kgK
        heatVaporization = 495.0; // 495.0 kJ/mol
        heatFusion = 21.7; // 21.7 kJ/mol
        ionization1st = 7.459; // eV
    }
};

/**
 * @brief Palladium is a chemical element with the symbol Pd and atomic number 46.
 * It is a rare and lustrous silvery-white metal discovered in 1803 by the
 * English chemist William Hyde Wollaston.
 */
class Palladium : public Element {
public:
    Palladium() {
        group = 10;
        symbol = "Pd";
        type = "Transition Metal";
        crystal_type = "Face-Centered Cubic";
        electron_configuration = "[Kr]4d10";
        atomicWeight = 106.42; // 102.91 u (g/mol)
        atomicNumber = 46; //45
        energyLevels = {2, 8, 18, 18};
        densitySTP = 12023; // 12450 kg/m^3
        meltingPoint = 1554.90; // 1964.0 C
        boilingPoint = 2963.0; // 3695.0 C
        thermalConductivity = 72.0; // 150.0 W/mK
        electricConductivity = 10.0; // 23.0 MS/m
        resistivity = 1.0e-7; // 4.3e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 240.0; // 240.0 J/kgK
        heatVaporization = 380.0; // 495.0 kJ/mol
        heatFusion = 16.7; // 21.7 kJ/mol
        ionization1st = 8.337; // eV
    }
};

/**
 * @brief Silver is a chemical element with the symbol Ag and atomic number 47.
 * A soft, white, lustrous transition metal, it exhibits the highest
 * electrical conductivity, thermal conductivity, and reflectivity of
 * any metal.
 */
class Silver : public Element {
public:
    Silver() {
        group = 11;
        symbol = "Ag";
        type = "Transition Metal";
        crystal_type = "Face-Centered Cubic";
        electron_configuration = "[Kr]4d10 5s1";
        atomicWeight = 107.87; // 102.91 u (g/mol)
        atomicNumber = 47; //45
        energyLevels = {2, 8, 18, 18, 1};
        densitySTP = 10490; // 12450 kg/m^3
        meltingPoint = 961.780; // 1964.0 C
        boilingPoint = 2162.0; // 3695.0 C
        thermalConductivity = 430.0; // 150.0 W/mK
        electricConductivity = 62.0; // 23.0 MS/m
        resistivity = 1.6e-8; // 4.3e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 235.0; // 240.0 J/kgK
        heatVaporization = 255.0; // 495.0 kJ/mol
        heatFusion = 11.3; // 21.7 kJ/mol
        ionization1st = 7.576; // eV
    }
};

/**
 * @brief Cadmium is a chemical element with the symbol Cd and atomic number 48.
 * This soft, silvery-white metal is chemically similar to the two other
 * stable metals in group 12, zinc and mercury.
 */
class Cadmium : public Element {
public:
    Cadmium() {
        group = 12;
        symbol = "Cd";
        type = "Transition Metal";
        crystal_type = "Hexagonal Close Packed";
        electron_configuration = "[Kr]4d10 5s2";
        atomicWeight = 112.41; // 102.91 u (g/mol)
        atomicNumber = 48; //45
        energyLevels = {2, 8, 18, 18, 2};
        densitySTP = 8650; // 12450 kg/m^3
        meltingPoint = 321.07; // 1964.0 C
        boilingPoint = 766.9; // 3695.0 C
        thermalConductivity = 97.0; // 150.0 W/mK
        electricConductivity = 14.0; // 23.0 MS/m
        resistivity = 7.0e-8; // 4.3e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 230.0; // 240.0 J/kgK
        heatVaporization = 100.0; // 495.0 kJ/mol
        heatFusion = 6.3; // 21.7 kJ/mol
        ionization1st = 8.994; // eV
    }
};

/**
 * @brief Indium is a chemical element with the symbol In and atomic number 49.
 * Indium is the softest metal that is not an alkali metal. It is a
 * silvery-white metal that resembles tin in appearance. It is a
 * post-transition metal that makes u (g/mol)p 0.21 parts per million of the
 * Earth's crust
 */
class Indium : public Element {
public:
    Indium() {
        group = 13;
        symbol = "In";
        type = "Post-Transition Metal";
        crystal_type = "Tetragonal";
        electron_configuration = "[Kr]4d10 5s2 5p1";
        atomicWeight = 114.82; // 114.82 u (g/mol)
        atomicNumber = 49; //45
        energyLevels = {2, 8, 18, 18, 3};
        densitySTP = 7310; // 7310 kg/m^3
        meltingPoint = 156.60; // 156.60 C
        boilingPoint = 2072.0; // 2072.0 C
        thermalConductivity = 82.0; // 82.0 W/mK
        electricConductivity = 12.0; // 12.0 MS/m
        resistivity = 8.0e-8; // 8.0e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 233.0; // 233.0 J/kgK
        heatVaporization = 230.0; // 230.0 kJ/mol
        heatFusion = 3.26; // 3.26 kJ/mol
        ionization1st = 5.786; // eV
    }
};

/**
 * @brief Tin is a chemical element with the symbol Sn and atomic number 50.
 * Tin is a silvery metal that characteristically has a faint yellow hue.
 * Tin, like indium, is soft enough to be cut without much force.
 */
class Tin : public Element {
public:
    Tin() {
        group = 14;
        symbol = "Sn";
        type = "Post-Transition Metal";
        crystal_type = "Tetragonal";
        electron_configuration = "[Kr]4d10 5s2 5p2";
        atomicWeight = 118.71; // 118.71 u (g/mol)
        atomicNumber = 50; //46
        energyLevels = {2, 8, 18, 18, 4};
        densitySTP = 7310; // 7310 kg/m^3
        meltingPoint = 231.93; // 231.93 C
        boilingPoint = 2602.0; // 2602.0 C
        thermalConductivity = 67.0; // 67.0 W/mK
        electricConductivity = 9.1; // 9.1 MS/m
        resistivity = 1.1e-7; // 1.1e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 217.0; // 217.0 J/kgK
        heatVaporization = 290.0; // 290.0 kJ/mol
        heatFusion = 7.0; // 7.0 kJ/mol
        ionization1st = 7.344; // eV
    }
};

/**
 * @brief Antimony is a chemical element with the symbol Sb and atomic number 51.
 * A lustrous gray metalloid, it is found in nature mainly as the sulfide
 * mineral stibnite. Antimony compounds have been known since ancient times
 * and were powdered for u (g/mol)se as medicine and cosmetics, often known by the
 * Arabic name kohl.
 */
class Antimony : public Element {
public:
    Antimony() {
        group = 15;
        symbol = "Sb";
        type = "Metalloid";
        crystal_type = "Rhombohedral";
        electron_configuration = "[Kr]4d10 5s2 5p3";
        atomicWeight = 121.76; // 121.76 u (g/mol)
        atomicNumber = 51; //47
        energyLevels = {2, 8, 18, 18, 5};
        densitySTP = 6697; // 6697 kg/m^3
        meltingPoint = 630.63; // 630.63 C
        boilingPoint = 1587.0; // 1587.0 C
        thermalConductivity = 24.0; // 24.0 W/mK
        electricConductivity = 2.5; // 2.5 MS/m
        resistivity = 4.0e-7; // 4.0e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 207.0; // 207.0 J/kgK
        heatVaporization = 68.0; // 68.0 kJ/mol
        heatFusion = 19.7; // 19.7 kJ/mol
        ionization1st = 8.64; // eV
    }
};

/**
 * @brief Tellurium is a chemical element with the symbol Te and atomic number 52.
 * It is a brittle, mildly toxic, rare, silver-white metalloid. Tellurium
 * is chemically related to selenium and sulfur, all three of which are
 * chalcogens. It is occasionally found in native form as elemental crystals
 */
class Tellurium : public Element {
public:
    Tellurium() {
        group = 16;
        symbol = "Te";
        type = "Metalloid";
        crystal_type = "Hexagonal";
        electron_configuration = "[Kr]4d10 5s2 5p4";
        atomicWeight = 127.60; // 127.60 u (g/mol)
        atomicNumber = 52; //48
        energyLevels = {2, 8, 18, 18, 6};
        densitySTP = 62420; // 62420 kg/m^3
        meltingPoint = 449.51; // 449.51 C
        boilingPoint = 987.9; // 987.9 C
        thermalConductivity = 3.0; // 3.0 W/mK
        electricConductivity = 0.010; // 0.010 MS/m
        resistivity = .0001; // .0001 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 201.0; // 201.0 J/kgK
        heatVaporization = 48.0; // 48.0 kJ/mol
        heatFusion = 17.5; // 17.5 kJ/mol
        ionization1st = 9.010; // eV
    }
};

/**
 * @brief Iodine is a chemical element with the symbol I and atomic number 53.
 * The heaviest of the stable halogens, it exists as a semi-lustrous,
 * non-metallic solid at standard conditions that melts to form a deep
 * violet liquid at 114 degrees Celsius, and boils to a violet gas at
 * 184 degrees Celsius.
 */
class Iodine : public Element {
public:
    Iodine() {
        group = 17;
        symbol = "I";
        type = "Halogen";
        crystal_type = "Orthorhombic";
        electron_configuration = "[Kr]4d10 5s2 5p5";
        atomicWeight = 126.90; // 126.90 u (g/mol)
        atomicNumber = 53; //49
        energyLevels = {2, 8, 18, 18, 7};
        densitySTP = 4940; // 4940 kg/m^3
        meltingPoint = 113.7; // 113.7 C
        boilingPoint = 184.3; // 184.3 C
        thermalConductivity = 0.449; // 0.449 W/mK
        electricConductivity = 1.0e-13; // 1.0e-13 MS/m
        resistivity = 1.0e7; // 1.0e7 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 429.0; // 429.0 J/kgK
        heatVaporization = 20.9; // 20.9 kJ/mol
        heatFusion = 7.76; // 7.76 kJ/mol
        ionization1st = 10.451; // eV
    }
};

/**
 * @brief Xenon is a chemical element with the symbol Xe and atomic number 54.
 * It is a colorless, dense, odorless noble gas found in Earth's atmosphere
 * in trace amounts.
 */
class Xenon : public Element {
public:
    Xenon() {
        group = 18;
        symbol = "Xe";
        type = "Noble Gas";
        crystal_type = "Face-Centered Cubic";
        electron_configuration = "[Kr]4d10 5s2 5p6";
        atomicWeight = 131.29; // 131.29 u (g/mol)
        atomicNumber = 54; //50
        energyLevels = {2, 8, 18, 18, 8};
        densitySTP = 5.9; // 5.9 kg/m^3
        meltingPoint = -111.8; // -111.8 C
        boilingPoint = -108.0; // -108.0 C
        thermalConductivity = .00565; // .00565 W/mK
        electricConductivity = FP_NAN; // FP_NAN MS/m
        resistivity = FP_NAN; // FP_NAN m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 158.32; // 158.32 J/kgK
        heatVaporization = 12.64; // 12.64 kJ/mol
        heatFusion = 2.30; // 2.30 kJ/mol
        ionization1st = 12.130; // eV
    }
};

/**
 * @brief Caesium is a chemical element with the symbol Cs and atomic number 55.
 * It is a soft, silvery-golden alkali metal with a melting point of 28.5 °C,
 * which makes it one of only five elemental metals that are liquid at or
 * near room temperature
 */
class Caesium : public Element {
public:
    Caesium() {
        group = 1;
        symbol = "Cs";
        type = "Alkali Metal";
        crystal_type = "Body-Centered Cubic";
        electron_configuration = "[Xe]6s1";
        atomicWeight = 132.91; // 132.91 u (g/mol)
        atomicNumber = 55; //51
        energyLevels = {2, 8, 18, 18, 8, 1};
        densitySTP = 1879; // 1879 kg/m^3
        meltingPoint = 28.440; // 28.440 C
        boilingPoint = 671.0; // 671.0 C
        thermalConductivity = 36.0; // 36.0 W/mK
        electricConductivity = 5.0; // 5.0 MS/m
        resistivity = 2.0e-7; // 2.0e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 242.0; // 242.0 J/kgK
        heatVaporization = 65.0; // 65.0 kJ/mol
        heatFusion = 2.09; // 2.09 kJ/mol
        ionization1st = 3.894; // eV
    }
};

/**
 * @brief Barium is a chemical element with the symbol Ba and atomic number 56.
 * It is the fifth element in group 2 and is a soft, silvery alkaline earth
 * metal. Because of its high chemical reactivity, barium is never found in
 * nature as a free element.
 */
class Barium : public Element {
public:
    Barium() {
        group = 2;
        symbol = "Ba";
        type = "Alkaline Earth Metal";
        crystal_type = "Body-Centered Cubic";
        electron_configuration = "[Xe]6s2";
        atomicWeight = 137.33; // 137.33 u (g/mol)
        atomicNumber = 56; //52
        energyLevels = {2, 8, 18, 18, 8, 2};
        densitySTP = 3510; // 3510 kg/m^3
        meltingPoint = 730.0; // 730.0 C
        boilingPoint = 1870.0; // 1870.0 C
        thermalConductivity = 18.0; // 18.0 W/mK
        electricConductivity = 2.9; // 2.9 MS/m
        resistivity = 3.5e-7; // 3.5e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 205.0; // 205.0 J/kgK
        heatVaporization = 140.0; // 140.0 kJ/mol
        heatFusion = 8.0; // 8.0 kJ/mol
        ionization1st = 5.212; // eV
    }
};

/**
 * @brief Lanthanum is a chemical element with the symbol La and atomic number 57.
 * It is a soft, ductile, silvery-white metal that tarnishes slowly when
 * exposed to air.
 */
class Lanthanum : public Element {
public:
    Lanthanum() {
        group = 3;
        symbol = "La";
        type = "Lanthanoid";
        crystal_type = "Double Hexagonal Close Packed";
        electron_configuration = "[Xe]5d1 6s2";
        atomicWeight = 138.91; // u (g/mol)
        atomicNumber = 57;
        energyLevels = {2, 8, 18, 18, 9, 2};
        densitySTP = 6146; // kg/m^3
        meltingPoint =  919.9; // C
        boilingPoint = 3463.0; // C
        thermalConductivity = 13.0; // W/mK
        electricConductivity = 1.6; // MS/m
        resistivity = 6.1e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 195.0; // J/kgK
        heatVaporization = 400.0; // kJ/mol
        heatFusion = 6.2; // kJ/mol
        ionization1st = 5.577; // eV
    }
};

/**
 * @brief Cerium is a chemical element with the symbol Ce and atomic number 58.
 * Cerium is a soft, ductile, and silvery-white metal that tarnishes when
 * exposed to air, and it is soft enough to be cut with a steel kitchen knife.
 */
class Cerium : public Element {
public:
    Cerium() {
        group = 3;
        symbol = "Ce";
        type = "Lanthanoid";
        crystal_type = "Double Hexagonal Close Packed / Face-Centered Cubic";
        electron_configuration = "[Xe]4f1 5d1 6s2";
        atomicWeight = 140.12; // u (g/mol)
        atomicNumber = 58;
        energyLevels = {2, 8, 18, 19, 9, 2};
        densitySTP = 6689; // kg/m^3
        meltingPoint = 797.9; // C
        boilingPoint = 3360.0; // C
        thermalConductivity = 11.0; // W/mK
        electricConductivity = 1.4; // MS/m
        resistivity =  7.4e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 192.0; // J/kgK
        heatVaporization = 350.0; // kJ/mol
        heatFusion = 5.5; // kJ/mol
        ionization1st = 5.539; // eV
    }
};

/**
 * @brief Praseodymium is a chemical element with the symbol Pr and atomic number 59.
 * It is the third member of the lanthanide series and is traditionally
 * considered to be one of the rare-earth metals.
 */
class Praseodymium : public Element {
public:
    Praseodymium() {
        group = 3;
        symbol = "Pr";
        type = "Lanthanoid";
        crystal_type = "Double Hexagonal Close Packed";
        electron_configuration = "[Xe]4f3 6s2";
        atomicWeight = 140.91; // u (g/mol)
        atomicNumber = 59;
        energyLevels = {2, 8, 18, 21, 8, 2};
        densitySTP = 6640; // kg/m^3
        meltingPoint = 930.9; // C
        boilingPoint = 3290.0; // C
        thermalConductivity = 13.0; // W/mK
        electricConductivity = 1.4; // MS/m
        resistivity = 7.0e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 193.0; // J/kgK
        heatVaporization = 330.0; // kJ/mol
        heatFusion = 6.9; // kJ/mol
        ionization1st = 5.46; // eV
    }
};

/**
 * @brief Neodymium is a chemical element with the symbol Nd and atomic number 60.
 * Neodymium belongs to the lanthanide series and is a rare-earth element.
 * It is a hard, slightly malleable silvery metal that quickly tarnishes
 * in air and moisture
 */
class Neodymium : public Element {
public:
    Neodymium() {
        group = 3;
        symbol = "Nd";
        type = "Lanthanoid";
        crystal_type = "Double Hexagonal Close Packed";
        electron_configuration = "[Xe]4f4 6s2";
        atomicWeight = 144.24; // u (g/mol)
        atomicNumber = 60;
        energyLevels = {2, 8, 18, 22, 8, 2};
        densitySTP = 7010; // kg/m^3
        meltingPoint = 1021.0; // C
        boilingPoint = 3100.0; // C
        thermalConductivity = 17.0; // W/mK
        electricConductivity = 1.6; // MS/m
        resistivity = 6.4e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 190.0; // J/kgK
        heatVaporization = 285.0; // kJ/mol
        heatFusion = 7.1; // kJ/mol
        ionization1st = 5.525; // eV
    }
};

/**
 * @brief Promethium is a chemical element with the symbol Pm and atomic number 61.
 * All of its isotopes are radioactive; it is extremely rare, with only
 * about 500–600 grams naturally occurring in Earth's crust at any
 * given time.
 */
class Promethium : public Element {
public:
    Promethium() {
        group = 3;
        symbol = "Pm";
        type = "Lanthanoid";
        crystal_type = "Double Hexagonal Close Packed";
        electron_configuration = "[Xe]4f5 6s2";
        atomicWeight = (145); // u (g/mol)
        atomicNumber = 61;
        energyLevels = {2, 8, 18, 23, 8, 2};
        densitySTP = 7264; // kg/m^3
        meltingPoint = 1100.0; // C
        boilingPoint = 3000.0; // C
        thermalConductivity = 15.0; // W/mK
        electricConductivity = 1.3; // MS/m
        resistivity = 7.5e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = 290.0; // kJ/mol
        heatFusion = 7.7; // kJ/mol
        ionization1st = 5.6; // eV
    }
};

/**
 * @brief Samarium is a chemical element with the symbol Sm and atomic number 62.
 * It is a moderately hard silvery metal that slowly oxidizes in air.
 * Being a typical member of the lanthanide series, samarium usually assumes
 * the oxidation state +3.
 */
class Samarium : public Element {
public:
    Samarium() {
        group = 3;
        symbol = "Sm";
        type = "Lanthanoid";
        crystal_type = "Rhombohedral";
        electron_configuration = "[Xe]4f6 6s2";
        atomicWeight = 150.36; // u (g/mol)
        atomicNumber = 62;
        energyLevels = {2, 8, 18, 24, 8, 2};
        densitySTP = 7353; // kg/m^3
        meltingPoint = 1072.0; // C
        boilingPoint = 1803.0; // C
        thermalConductivity = 13.0; // W/mK
        electricConductivity = 1.1; // MS/m
        resistivity = 9.4e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 196.0; // J/kgK
        heatVaporization = 175.0; // kJ/mol
        heatFusion = 8.6; // kJ/mol
        ionization1st = 5.643; // eV
    }
};

/**
 * @brief Europium is a chemical element with the symbol Eu and atomic number 63.
 * Europium is the most reactive lanthanide by far, having to be stored
 * under an inert fluid to protect it from atmospheric oxygen or moisture.
 */
class Europium : public Element {
public:
    Europium() {
        group = 3;
        symbol = "Eu";
        type = "Lanthanoid";
        crystal_type = "Body-Centered Cubic";
        electron_configuration = "[Xe]4f7 6s2";
        atomicWeight = 151.96; // u (g/mol)
        atomicNumber = 63;
        energyLevels = {2, 8, 18, 25, 8, 2};
        densitySTP = 5244; // kg/m^3
        meltingPoint = 821.9; // C
        boilingPoint = 1500.0; // C
        thermalConductivity = 14.0; // W/mK
        electricConductivity = 1.1; // MS/m
        resistivity = 9.0e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 182.0; // J/kgK
        heatVaporization = 175.0; // kJ/mol
        heatFusion = 9.2; // kJ/mol
        ionization1st = 5.670; // eV
    }
};

/**
 * @brief Gadolinium is a chemical element with the symbol Gd and atomic number 64.
 * Gadolinium is a silvery-white metal when oxidation is removed. It is
 * only slightly malleable and is a ductile rare-earth element. Gadolinium
 * reacts with atmospheric oxygen or moisture slowly to form a black coating.
 */
class Gadolinium : public Element {
public:
    Gadolinium() {
        group = 3;
        symbol = "Gd";
        type = "Lanthanoid";
        crystal_type = "Hexagonal Close Packed";
        electron_configuration = "[Xe]4f7 5d1 6s2";
        atomicWeight = 157.25; // u (g/mol)
        atomicNumber = 64;
        energyLevels = {2, 8, 18, 25, 9, 2};
        densitySTP = 7901; // kg/m^3
        meltingPoint = 1313.0; // C
        boilingPoint = 3250.0; // C
        thermalConductivity = 11.0; // W/mK
        electricConductivity = .77; // MS/m
        resistivity = 1.3e-6; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 240.0; // J/kgK
        heatVaporization = 305.0; // kJ/mol
        heatFusion = 10.0; // kJ/mol
        ionization1st = 6.150; // eV
    }
};

/**
 * @brief Terbium is a chemical element with the symbol Tb and atomic number 65.
 * It is a silvery-white, rare earth metal that is malleable, ductile,
 * and soft enough to be cut with a knife. The ninth member of the
 * lanthanide series, terbium is a fairly electro-positive metal that reacts
 * with water, evolving hydrogen gas.
 */
class Terbium : public Element {
public:
    Terbium() {
        group = 3;
        symbol = "Tb";
        type = "Lanthanoid";
        crystal_type = "Hexagonal Close Packed";
        electron_configuration = "[Xe]4f9 6s2";
        atomicWeight = 158.93; // u (g/mol)
        atomicNumber = 65;
        energyLevels = {2, 8, 18, 27, 8, 2};
        densitySTP = 8219; // kg/m^3
        meltingPoint = 1356.0; // C
        boilingPoint = 3230.0; // C
        thermalConductivity = 11.0; // W/mK
        electricConductivity = .83; // MS/m
        resistivity = 1.2e-6; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 182.0; // J/kgK
        heatVaporization = 295.0; // kJ/mol
        heatFusion = 10.8; // kJ/mol
        ionization1st = 5.864; // eV
    }
};

/**
 * @brief Dysprosium is the chemical element with the symbol Dy and atomic number 66.
 * It is a rare-earth element with a metallic silver luster. Dysprosium is
 * never found in nature as a free element, though it is found in various
 * minerals, such as xenotime.
 */
class Dysprosium : public Element {
public:
    Dysprosium() {
        group = 3;
        symbol = "Dy";
        type = "Lanthanoid";
        crystal_type = "Hexagonal Close Packed";
        electron_configuration = "[Xe]4f10 6s2";
        atomicWeight = 162.50; // u (g/mol)
        atomicNumber = 66;
        energyLevels = {2, 8, 18, 28, 8, 2};
        densitySTP = 8551; // kg/m^3
        meltingPoint = 1412.0; // C
        boilingPoint = 2567.0; // C
        thermalConductivity = 11.0; // W/mK
        electricConductivity = 1.1; // MS/m
        resistivity = 9.1e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 167.0; // J/kgK
        heatVaporization = 280.0; // kJ/mol
        heatFusion = 11.1; // kJ/mol
        ionization1st = 5.934; // eV
    }
};

/**
 * @brief Holmium is a chemical element with the symbol Ho and atomic number 67.
 * Part of the lanthanide series, holmium is a rare-earth element. Holmium
 * was discovered through isolation by Swedish chemist Per Theodor Cleve
 * and independently by Jacques-Louis Soret and Marc Delafontaine who
 * observed it spectroscopically in 1878.
 */
class Holmium : public Element {
public:
    Holmium() {
        group = 3;
        symbol = "Ho";
        type = "Lanthanoid";
        crystal_type = "Hexagonal Close Packed";
        electron_configuration = "[Xe]4f11 6s2";
        atomicWeight = 164.93; // u (g/mol)
        atomicNumber = 67;
        energyLevels = {2, 8, 18, 29, 8, 2};
        densitySTP = 8795; // kg/m^3
        meltingPoint = 1474.0; // C
        boilingPoint = 2700.0; // C
        thermalConductivity = 16.0; // W/mK
        electricConductivity = 1.1; // MS/m
        resistivity = 9.4e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 165.0; // J/kgK
        heatVaporization = 265.0; // kJ/mol
        heatFusion = 17.0; // kJ/mol
        ionization1st = 6.022; // eV
    }
};

/**
 * @brief Erbium is a chemical element with the symbol Er and atomic number 68.
 * A silvery-white solid metal when artificially isolated, natural erbium
 * is always found in chemical combination with other elements.
 */
class Erbium : public Element {
public:
    Erbium() {
        group = 3;
        symbol = "Er";
        type = "Lanthanoid";
        crystal_type = "Hexagonal Close Packed";
        electron_configuration = "[Xe]4f12 6s2";
        atomicWeight = 167.26; // u (g/mol)
        atomicNumber = 68;
        energyLevels = {2, 8, 18, 30, 8, 2};
        densitySTP = 9066; // kg/m^3
        meltingPoint = 1497.0; // C
        boilingPoint = 2868.0; // C
        thermalConductivity = 15.0; // W/mK
        electricConductivity = 1.2; // MS/m
        resistivity = 8.6e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 168.0; // J/kgK
        heatVaporization = 285.0; // kJ/mol
        heatFusion = 19.9; // kJ/mol
        ionization1st = 6.108; // eV
    }
};

/**
 * @brief Thulium is a chemical element with the symbol Tm and atomic number 69.
 * It is the thirteenth and third-last element in the lanthanide series.
 */
class Thulium : public Element {
public:
    Thulium() {
        group = 3;
        symbol = "Tm";
        type = "Lanthanoid";
        crystal_type = "Hexagonal Close Packed";
        electron_configuration = "[Xe]4f13 6s2";
        atomicWeight = 168.93; // u (g/mol)
        atomicNumber = 69;
        energyLevels = {2, 8, 18, 31, 8, 2};
        densitySTP = 9320; // kg/m^3
        meltingPoint = 1545.0; // C
        boilingPoint = 1950.0; // C
        thermalConductivity = 17.0; // W/mK
        electricConductivity = 1.4; // MS/m
        resistivity = 7.0e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 160.0; // J/kgK
        heatVaporization = 250.0; // kJ/mol
        heatFusion = 16.8; // kJ/mol
        ionization1st = 6.184; // eV
    }
};

/**
 * @brief Ytterbium is a chemical element with the symbol Yb and atomic number 70.
 * It is the fourteenth and penultimate element in the lanthanide series,
 * which is the basis of the relative stability of its +2 oxidation state.
 */
class Ytterbium : public Element {
public:
    Ytterbium() {
        group = 3;
        symbol = "Yb";
        type = "Lanthanoid";
        crystal_type = "Face-Centered Cubic";
        electron_configuration = "[Xe]4f14 6s2";
        atomicWeight = 173.05; // u (g/mol)
        atomicNumber = 70;
        energyLevels = {2, 8, 18, 32, 8, 2};
        densitySTP = 6570; // kg/m^3
        meltingPoint = 818.9; // C
        boilingPoint = 1196.0; // C
        thermalConductivity = 39.0; // W/mK
        electricConductivity = 3.6; // MS/m
        resistivity = 2.8e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 154.0; // J/kgK
        heatVaporization = 160.0; // kJ/mol
        heatFusion = 7.7; // kJ/mol
        ionization1st = 6.254; // eV
    }
};

/**
 * @brief Lutetium is a chemical element with the symbol Lu and atomic number 71.
 * It is a silvery white metal, which resists corrosion in dry air,
 * but not in moist air. Lutetium is the last element in the lanthanide series,
 * and it is traditionally counted among the rare earths.
 */
class Lutetium : public Element {
public:
    Lutetium() {
        group = 3;
        symbol = "Lu";
        type = "Lanthanoid";
        crystal_type = "Hexagonal Close Packed";
        electron_configuration = "[Xe]4f14 5d1 6s2";
        atomicWeight = 174.97; // u (g/mol)
        atomicNumber = 71;
        energyLevels = {2, 8, 18, 32, 9, 2};
        densitySTP = 9841; // kg/m^3
        meltingPoint = 1663.0; // C
        boilingPoint = 3402.0; // C
        thermalConductivity = 16.0; // W/mK
        electricConductivity = 1.8; // MS/m
        resistivity = 5.6e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 154.0; // J/kgK
        heatVaporization = 415.0; // kJ/mol
        heatFusion = 22.0; // kJ/mol
        ionization1st = 5.426; // eV
    }
};

/**
 * @brief Hafnium is a chemical element with the symbol Hf and atomic number 72.
 * A lustrous, silvery gray, tetravalent transition metal, hafnium chemically
 * resembles zirconium and is found in many zirconium minerals.
 */
class Hafnium : public Element {
public:
    Hafnium() {
        group = 4;
        symbol = "Hf";
        type = "Transition Metal";
        crystal_type = "Hexagonal Close Packed";
        electron_configuration = "[Xe]4f14 5d2 6s2";
        atomicWeight = 178.49; // u (g/mol)
        atomicNumber = 72;
        energyLevels = {2, 8, 18, 32, 10, 2};
        densitySTP = 13310; // kg/m^3
        meltingPoint = 2233.0; // C
        boilingPoint = 4603.0; // C
        thermalConductivity = 23.0; // W/mK
        electricConductivity = 3.3; // MS/m
        resistivity = 3.0e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 144.0; // J/kgK
        heatVaporization = 630.0; // kJ/mol
        heatFusion = 25.5; // kJ/mol
        ionization1st = 6.825; // eV
    }
};

/**
 * @brief Tantalum is a chemical element with the symbol Ta and atomic number 73.
 * Previously known as tantalium, it is named after Tantalus, a villain
 * from Greek mythology. Tantalum is a rare, hard, blue-gray, lustrous
 * transition metal that is highly corrosion-resistant.
 */
class Tantalum : public Element {
public:
    Tantalum() {
        group = 5;
        symbol = "Ta";
        type = "Transition Metal";
        crystal_type = "Body-Centered Cubic / Tetragonal";
        electron_configuration = "[Xe]4f14 5d3 6s2";
        atomicWeight = 180.95; // u (g/mol)
        atomicNumber = 73;
        energyLevels = {2, 8, 18, 32, 11, 2};
        densitySTP = 16650; // kg/m^3
        meltingPoint = 3017.0; // C
        boilingPoint = 5458.0; // C
        thermalConductivity = 57.0; // W/mK
        electricConductivity = 7.7; // MS/m
        resistivity = 1.3e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 140.0; // J/kgK
        heatVaporization = 735.0; // kJ/mol
        heatFusion = 36.0; // kJ/mol
        ionization1st = 7.89; // eV
    }
};

/**
 * @brief Tungsten, or wolfram, is a chemical element with the symbol W and atomic number 74.
 * Tungsten is a rare metal found naturally on Earth almost exclusively as
 * compounds with other elements. It was identified as a new element in 1781
 * and first isolated as a metal in 1783.
 */
class Tungsten : public Element {
public:
    Tungsten() {
        group = 6;
        symbol = "W";
        type = "Transition Metal";
        crystal_type = "Body-Centered Cubic";
        electron_configuration = "[Xe]4f14 5d4 6s2";
        atomicWeight = 183.84; // u (g/mol)
        atomicNumber = 74;
        energyLevels = {2, 8, 18, 32, 12, 2};
        densitySTP = 19250; // kg/m^3
        meltingPoint = 3422.0; // C
        boilingPoint = 5555.0; // C
        thermalConductivity = 170.0; // W/mK
        electricConductivity = 20.0; // MS/m
        resistivity = 5.0e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 132.0; // J/kgK
        heatVaporization = 800.0; // kJ/mol
        heatFusion = 35.0; // kJ/mol
        ionization1st = 7.98; // eV
    }
};

/**
 * @brief Rhenium is a chemical element with the symbol Re and atomic number 75.
 * It is a silvery-gray, heavy, third-row transition metal in group 7 of
 * the periodic table. With an estimated average concentration of 1 part
 * per billion, rhenium is one of the rarest elements in the Earth's crust.
 */
class Rhenium : public Element {
public:
    Rhenium() {
        group = 7;
        symbol = "Re";
        type = "Transition Metal";
        crystal_type = "Hexagonal Close Packed";
        electron_configuration = "[Xe]4f14 5d5 6s2";
        atomicWeight = 186.21; // u (g/mol)
        atomicNumber = 75;
        energyLevels = {2, 8, 18, 32, 13, 2};
        densitySTP = 21020; // kg/m^3
        meltingPoint = 3186.0; // C
        boilingPoint = 5596.0; // C
        thermalConductivity = 48.0; // W/mK
        electricConductivity = 5.6; // MS/m
        resistivity = 1.8e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 137.0; // J/kgK
        heatVaporization = 705.0; // kJ/mol
        heatFusion = 33.0; // kJ/mol
        ionization1st = 7.88; // eV
    }
};

/**
 * @brief Osmium is a chemical element with the symbol Os and atomic number 76.
 * It is a hard, brittle, bluish-white transition metal in the platinum
 * group that is found as a trace element in
 * alloys, mostly in platinum ores.
 */
class Osmium : public Element {
public:
    Osmium() {
        group = 8;
        symbol = "Os";
        type = "Transition Metal";
        crystal_type = "Hexagonal Close Packed";
        electron_configuration = "[Xe]4f14 5d6 6s2";
        atomicWeight = 190.23; // u (g/mol)
        atomicNumber = 76;
        energyLevels = {2, 8, 18, 32, 14, 2};
        densitySTP = 22590; // kg/m^3
        meltingPoint = 3033.0; // C
        boilingPoint = 5012.0; // C
        thermalConductivity = 88.0; // W/mK
        electricConductivity = 12.0; // MS/m
        resistivity = 8.1e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 130.0; // J/kgK
        heatVaporization = 630.0; // kJ/mol
        heatFusion = 31.0; // kJ/mol
        ionization1st = 8.71; // eV
    }
};

/**
 * @brief Iridium is a chemical element with the symbol Ir and atomic number 77.
 * A very hard, brittle, silvery-white transition metal of the platinum group,
 * iridium is considered to be the second-densest metal with a density of
 * 22.56 g/cm³ as defined by experimental X_-ray crystallography.
 */
class Iridium : public Element {
public:
    Iridium() {
        group = 9;
        symbol = "Ir";
        type = "Transition Metal";
        crystal_type = "Face-Centered Cubic";
        electron_configuration = "[Xe]4f14 5d7 6s2";
        atomicWeight = 192.22; // u (g/mol)
        atomicNumber = 77;
        energyLevels = {2, 8, 18, 32, 15, 2};
        densitySTP = 22560; // kg/m^3
        meltingPoint = 2466.0; // C
        boilingPoint = 4428.0; // C
        thermalConductivity = 150.0; // W/mK
        electricConductivity = 21.0; // MS/m
        resistivity = 4.7e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 131.0; // J/kgK
        heatVaporization = 560.0; // kJ/mol
        heatFusion = 26.0; // kJ/mol
        ionization1st = 9.12; // eV
    }
};

/**
 * @brief Platinum is a chemical element with the symbol Pt and atomic number 78.
 * It is a dense, malleable, ductile, highly nonreactive, precious,
 * silverish-white transition metal. Its name is derived from the Spanish
 * term platino, meaning "little silver".
 */
class Platinum : public Element {
public:
    Platinum() {
        group = 10;
        symbol = "Pt";
        type = "Transition Metal";
        crystal_type = "Face-Centered Cubic";
        electron_configuration = "[Xe]4f14 5d9 6s1";
        atomicWeight = 195.08; // u (g/mol)
        atomicNumber = 78;
        energyLevels = {2, 8, 18, 32, 17, 1};
        densitySTP = 21450; // kg/m^3
        meltingPoint = 1768.3; // C
        boilingPoint = 3825.0; // C
        thermalConductivity = 72.0; // W/mK
        electricConductivity = 9.4; // MS/m
        resistivity = 1.1e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 133.0; // J/kgK
        heatVaporization = 490.0; // kJ/mol
        heatFusion = 20.0; // kJ/mol
        ionization1st = 9.02; // eV
    }
};

/**
 * @brief Gold is a chemical element with the symbol Au and atomic number 79,
 * making it one of the higher atomic number elements that occur naturally.
 * In a pure form, it is a bright, slightly reddish yellow, dense, soft,
 * malleable, and ductile metal. Chemically, gold is a transition metal
 * and a group 11 element.
 */
class Gold : public Element {
public:
    Gold() {
        group = 11;
        symbol = "Au";
        type = "Transition Metal";
        crystal_type = "Face-Centered Cubic";
        electron_configuration = "[Xe]4f14 5d10 6s1";
        atomicWeight = 196.97; // u (g/mol)
        atomicNumber = 79;
        energyLevels = {2, 8, 18, 32, 18, 1};
        densitySTP = 19300; // kg/m^3
        meltingPoint = 1064.18; // C
        boilingPoint = 2856; // C
        thermalConductivity = 320.0; // W/mK
        electricConductivity = 45.0; // MS/m
        resistivity = 2.2e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 129.1; // J/kgK
        heatVaporization = 330.0; // kJ/mol
        heatFusion = 12.5; // kJ/mol
        ionization1st = 9.225; // eV
    }
};

/**
 * @brief Mercury is a chemical element with the symbol Hg and atomic number 80.
 * It is commonly known as quicksilver and was formerly named hydrargyrum.
 */
class Mercury : public Element {
public:
    Mercury() {
        group = 12;
        symbol = "Hg";
        type = "Transition Metal";
        crystal_type = "Rhombohedral";
        electron_configuration = "[Xe]4f14 5d10 6s2";
        atomicWeight = 200.59; // u (g/mol)
        atomicNumber = 80;
        energyLevels = {2, 8, 18, 32, 18, 2};
        densitySTP = 13534; // kg/m^3
        meltingPoint = -38.830; // C
        boilingPoint = 356.73; // C
        thermalConductivity = 8.3; // W/mK
        electricConductivity = 1.0; // MS/m
        resistivity = 9.6e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 139.5; // J/kgK
        heatVaporization = 59.2; // kJ/mol
        heatFusion = 2.29; // kJ/mol
        ionization1st = 10.438; // eV
    }
};

/**
 * @brief Thallium is a chemical element with the symbol Tl and atomic number 81.
 * It is a gray post-transition metal that is not found free in nature.
 * When isolated, thallium resembles tin, but discolors when exposed to air.
 */
class Thallium : public Element {
public:
    Thallium() {
        group = 13;
        symbol = "Tl";
        type = "Post-Transition Metal";
        crystal_type = "Hexagonal Close Packed";
        electron_configuration = "[Xe]4f14 5d10 6s2 6p1";
        atomicWeight = 204.38; // u (g/mol)
        atomicNumber = 81;
        energyLevels = {2, 8, 18, 32, 18, 3};
        densitySTP = 11850; // kg/m^3
        meltingPoint = 304.0; // C
        boilingPoint = 1473.0; // C
        thermalConductivity = 46.0; // W/mK
        electricConductivity = 6.7; // MS/m
        resistivity = 1.5e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 129.0; // J/kg
        heatVaporization = 165.0; // kJ/mol
        heatFusion = 4.2; // kJ/mol
        ionization1st = 6.109; // eV
    }
};

/**
 * @brief Lead is a chemical element with the symbol Pb and atomic number 82.
 * It is a heavy metal that is denser than most common materials. Lead is
 * soft and malleable, and also has a relatively low melting point. When
 * freshly cut, lead is silvery with a hint of blue; it tarnishes to a dull
 * gray color when exposed to air.
 */
class Lead : public Element {
public:
    Lead() {
        group = 14;
        symbol = "Pb";
        type = "Post-Transition Metal";
        crystal_type = "Face-Centered Cubic";
        electron_configuration = "[Xe]4f14 5d10 6s2 6p2";
        atomicWeight = 207.2; // u (g/mol)
        atomicNumber = 82;
        energyLevels = {2, 8, 18, 32, 18, 4};
        densitySTP = 11340; // kg/m^3
        meltingPoint = 327.46; // C
        boilingPoint = 1749.0; // C
        thermalConductivity = 35.0; // W/mK
        electricConductivity = 4.8; // MS/m
        resistivity = 2.1e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 127.0; // J/kgK
        heatVaporization = 178.0; // kJ/mol
        heatFusion = 4.77; // kJ/mol
        ionization1st = 7.417; // eV
    }
};

/**
 * @brief Bismuth is a chemical element with the symbol Bi and atomic number 83.
 * It is a pentavalent post-transition metal and one of the pnictogens with
 * chemical properties resembling its lighter group 15 siblings arsenic
 * and antimony.
 */
class Bismuth : public Element {
public:
    Bismuth() {
        group = 15;
        symbol = "Bi";
        type = "Post-Transition Metal";
        crystal_type = "Rhombohedral";
        electron_configuration = "[Xe]4f14 5d10 6s2 6p3";
        atomicWeight = 208.98; // u (g/mol)
        atomicNumber = 83;
        energyLevels = {2, 8, 18, 32, 18, 5};
        densitySTP = 9780; // kg/m^3
        meltingPoint = 271.3; // C
        boilingPoint = 1564.0; // C
        thermalConductivity = 8.0; // W/mK
        electricConductivity = .77; // MS/m
        resistivity = 1.3e-6; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 122.0; // J/kgK
        heatVaporization = 160.0; // kJ/mol
        heatFusion = 10.9; // kJ/mol
        ionization1st = 7.29; // eV
    }
};

/**
 * @brief Polonium is a chemical element with the symbol Po and atomic number 84.
 * A rare and highly radioactive metal with no stable isotopes, polonium
 * is chemically similar to selenium and tellurium, though its metallic
 * character resembles that of its horizontal neighbors in the periodic
 * table: thallium, lead, and bismuth.
 */
class Polonium : public Element {
public:
    Polonium() {
        group = 16;
        symbol = "Po";
        type = "Post-Transition Metal";
        crystal_type = "Simple Cubic / Rhombohedral";
        electron_configuration = "[Xe]4f14 5d10 6s2 6p4";
        atomicWeight = (209); // u (g/mol)
        atomicNumber = 84;
        energyLevels = {2, 8, 18, 32, 18, 6};
        densitySTP = 9196.0; // kg/m^3
        meltingPoint = 255.0; // C
        boilingPoint = 961.9; // C
        thermalConductivity = FP_NAN; // W/mK
        electricConductivity = 2.3; // MS/m
        resistivity = 4.3e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = 100.0; // kJ/mol
        heatFusion = 13.0; // kJ/mol
        ionization1st = 8.417; // eV
    }
};

/**
 * @brief Astatine is a chemical element with the symbol At and atomic number 85.
 * It is the rarest naturally occurring element in the Earth's crust,
 * occurring only as the decay product of various heavier elements.
 * All of astatine's isotopes are short-lived; the most stable is
 * astatine-210, with a half-life of 8.1 hours.
 */
class Astatine : public Element {
public:
    Astatine() {
        group = 17;
        symbol = "At";
        type = "Metalloid";
        crystal_type = "Face-Centered Cubic:?";
        electron_configuration = "[Xe]4f14 5d10 6s2 6p5";
        atomicWeight = (210); // u (g/mol)
        atomicNumber = 85;
        energyLevels = {2, 8, 18, 32, 18, 7};
        densitySTP = FP_NAN; // kg/m^3
        meltingPoint = 302.0; // C
        boilingPoint = 350.0; // C
        thermalConductivity = 2.0; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = 40.0; // kJ/mol
        heatFusion = 6.0; // kJ/mol
        ionization1st = 9.22; // eV
    }
};

/**
 * @brief Radon is a chemical element with the symbol Rn and atomic number 86.
 * It is a radioactive, colorless, odorless, tasteless noble gas.
 */
class Radon : public Element {
public:
    Radon() {
        group = 18;
        symbol = "Rn";
        type = "Noble Gas";
        crystal_type = "Face-Centered Cubic";
        electron_configuration = "[Xe]4f14 5d10 6s2 6p6";
        atomicWeight = (222); // u (g/mol)
        atomicNumber = 86;
        energyLevels = {2, 8, 18, 32, 18, 8};
        densitySTP = 9.73; // kg/m^3
        meltingPoint = -71.1; // C
        boilingPoint = -61.85; // C
        thermalConductivity = .00361; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 93.65; // J/kgK
        heatVaporization = 17.0; // kJ/mol
        heatFusion = 3.0; // kJ/mol
        ionization1st = 10.75; // eV
    }
};

/**
 * @brief Francium is a chemical element with the symbol Fr and atomic number 87.
 * Prior to its discovery, it was referred to as eka-caesium. It is extremely
 * radioactive; its most stable isotope, francium-223, has a half-life
 * of only 22 minutes.
 */
class Francium : public Element {
public:
    Francium() {
        group = 1;
        symbol = "Fr";
        type = "Alkali Metal";
        crystal_type = "Body-Centered Cubic:?";
        electron_configuration = "[Rn]7s1";
        atomicWeight = (223); // u (g/mol)
        atomicNumber = 87;
        energyLevels = {2, 8, 18, 32, 18, 8, 1};
        densitySTP = FP_NAN; // kg/m^3
        meltingPoint = 20.9; // C
        boilingPoint = 650.0; // C
        thermalConductivity = FP_NAN; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = 65.0; // kJ/mol
        heatFusion = 2.0; // kJ/mol
        ionization1st = 3.94; // eV
    }
};

/**
 * @brief Radium is a chemical element with the symbol Ra and atomic number 88.
 * It is the sixth element in group 2 of the periodic table, also known
 * as the alkaline earth metals. Pure radium is silvery-white, but it
 * readily reacts with nitrogen on exposure to air, forming a black
 * surface layer of radium nitride.
 */
class Radium : public Element {
public:
    Radium() {
        group = 2;
        symbol = "Ra";
        type = "Alkaline Earth Metal";
        crystal_type = "Body-Centered Cubic";
        electron_configuration = "[Rn]7s2";
        atomicWeight = (226); // u (g/mol)
        atomicNumber = 88;
        energyLevels = {2, 8, 18, 32, 18, 8, 2};
        densitySTP = 5000.0; // kg/m^3
        meltingPoint = 700.0; // C
        boilingPoint = 1737.0; // C
        thermalConductivity = 19.0; // W/mK
        electricConductivity = 1.0; // MS/m
        resistivity = 1.0e-6; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 92.0; // J/kgK
        heatVaporization = 125.0; // kJ/mol
        heatFusion = 8.0; // kJ/mol
        ionization1st = 5.279; // eV
    }
};

/**
 * @brief Actinium is a chemical element with the symbol Ac and atomic number 89.
 * It was first isolated by Friedrich Oskar Giesel in 1902, who gave it
 * the name emanium; the element got its name by being wrongly identified
 * with a substance André-Louis Debierne found and called actinium.
 */
class Actinium : public Element {
public:
    Actinium() {
        group = 3;
        symbol = "Ac";
        type = "Actinoid";
        crystal_type = "Face-Centered Cubic";
        electron_configuration = "[Rn]6d1 7s2";
        atomicWeight = (227); // u (g/mol)
        atomicNumber = 89;
        energyLevels = {2, 8, 18, 32, 18, 9, 2};
        densitySTP = 10070.0; // kg/m^3
        meltingPoint = 1050.0; // C
        boilingPoint = 3200.0; // C
        thermalConductivity = 12.0; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 120.0; // J/kgK
        heatVaporization = 400.0; // kJ/mol
        heatFusion = 14.0; // kJ/mol
        ionization1st = 5.17; // eV
    }
};

/**
 * @brief Thorium is a weakly radioactive metallic chemical element with the symbol Th and atomic number 90.
 * Thorium is silvery and tarnishes black when it is exposed to air, forming
 * thorium dioxide; it is moderately soft, malleable, and has a high melting point.
 */
class Thorium : public Element {
public:
    Thorium() {
        group = 3;
        symbol = "Th";
        type = "Actinoid";
        crystal_type = "Face-Centered Cubic";
        electron_configuration = "[Rn]6d2 7s2";
        atomicWeight = 232.04; // u (g/mol)
        atomicNumber = 90;
        energyLevels = {2, 8, 18, 32, 18, 10, 2};
        densitySTP = 11724.0; // kg/m^3
        meltingPoint = 1750.0; // C
        boilingPoint = 4820.0; // C
        thermalConductivity = 54.0; // W/mK
        electricConductivity = 6.7; // MS/m
        resistivity = 1.5e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 118.0; // J/kgK
        heatVaporization = 530.0; // kJ/mol
        heatFusion = 16.0; // kJ/mol
        ionization1st = 6.08; // eV
    }
};

/**
 * @brief Protactinium is a chemical element with the symbol Pa and atomic number 91.
 * It is a dense, silvery-gray actinide metal which readily reacts with oxygen,
 * water vapor and inorganic acids.
 */
class Protactinium : public Element {
public:
    Protactinium() {
        group = 3;
        symbol = "Pa";
        type = "Actinoid";
        crystal_type = "Tetragonal";
        electron_configuration = "[Rn]5f2 6d1 7s2";
        atomicWeight = 231.04; // u (g/mol)
        atomicNumber = 91;
        energyLevels = {2, 8, 18, 32, 20, 9, 2};
        densitySTP = 15370.0; // kg/m^3
        meltingPoint = 1572.0; // C
        boilingPoint = 4000.0; // C
        thermalConductivity = 47.0; // W/mK
        electricConductivity = 5.6; // MS/m
        resistivity = 1.8e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 99.1; // J/kgK
        heatVaporization = 470.0; // kJ/mol
        heatFusion = 15.0; // kJ/mol
        ionization1st = 5.89; // eV
    }
};

/**
 * @brief Uranium is a chemical element with the symbol U and atomic number 92.
 * It is a silvery-grey metal in the actinide series of the periodic table.
 * A uranium atom has 92 protons and 92 electrons, of which 6 are
 * valence electrons.
 */
class Uranium : public Element {
public:
    Uranium() {
        group = 3;
        symbol = "U";
        type = "Actinoid";
        crystal_type = "Orthorhombic";
        electron_configuration = "[Rn]5f3 6d1 7s2";
        atomicWeight = 238.03; // u (g/mol)
        atomicNumber = 92;
        energyLevels = {2, 8, 18, 32, 21, 9, 2};
        densitySTP = 19050.0; // kg/m^3
        meltingPoint = 1135.0; // C
        boilingPoint = 3900.0; // C
        thermalConductivity = 27.0; // W/mK
        electricConductivity = 3.6; // MS/m
        resistivity = 2.8e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = 116.0; // J/kgK
        heatVaporization = 420.0; // kJ/mol
        heatFusion = 14.0; // kJ/mol
        ionization1st = 6.194; // eV
    }
};

/**
 * @brief Neptunium is a chemical element with the symbol Np and atomic number 93.
 * A radioactive actinide metal, neptunium is the first transuranic element. Its
 * position in the periodic table just after uranium, named after the planet
 * Uranus, led to it being named after Neptune, the next planet beyond Uranus.
 */
class Neptunium : public Element {
public:
    Neptunium() {
        group = 3;
        symbol = "Np";
        type = "Actinoid";
        crystal_type = "Orthorhombic";
        electron_configuration = "[Rn]5f4 6d1 7s2";
        atomicWeight = (237); // u (g/mol)
        atomicNumber = 93;
        energyLevels = {2, 8, 18, 32, 22, 9, 2};
        densitySTP = 20450.0; // kg/m^3
        meltingPoint = 644.0; // C
        boilingPoint = 4000.0; // C
        thermalConductivity = 6.0; // W/mK
        electricConductivity = .83; // MS/m
        resistivity = 1.2e-6; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = 335.0; // kJ/mol
        heatFusion = 10.0; // kJ/mol
        ionization1st = 6.265; // eV
    }
};

/**
 * @brief Plutonium is a radioactive chemical element with the symbol Pu and atomic
 * number 94. It is an actinide metal of silvery-gray appearance that tarnishes when
 * exposed to air, and forms a dull coating when oxidized. The element normally
 * exhibits six allotropes and four oxidation states.
 */
class Plutonium : public Element {
public:
    Plutonium() {
        group = 3;
        symbol = "Pu";
        type = "Actinoid";
        crystal_type = "Monoclinic";
        electron_configuration = "[Rn]5f6 7s2";
        atomicWeight = (244); // u (g/mol)
        atomicNumber = 94;
        energyLevels = {2, 8, 18, 32, 24, 8, 2};
        densitySTP = 19816.0; // kg/m^3
        meltingPoint = 640.0; // C
        boilingPoint = 3230.0; // C
        thermalConductivity = 6.0; // W/mK
        electricConductivity = .67; // MS/m
        resistivity = 1.5e-6; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = 325.0; // kJ/mol
        heatFusion = FP_NAN; // kJ/mol
        ionization1st = 6.060; // eV
    }
};

/**
 * @brief Americium is a synthetic radioactive chemical element with the symbol Am and
 * atomic number 95. It is a transuranic member of the actinide series, in the periodic
 * table located under the lanthanide element europium, and thus by analogy was named
 * after the Americas.
 */
class Americium : public Element {
public:
    Americium() {
        group = 3;
        symbol = "Am";
        type = "Actinoid";
        crystal_type = "Double Hexagonal Close Packed";
        electron_configuration = "[Rn]5f7 7s2";
        atomicWeight = (243); // u (g/mol)
        atomicNumber = 95;
        energyLevels = {2, 8, 18, 32, 25, 8, 2};
        densitySTP = 13670.0; // kg/m^3
        meltingPoint = 1176.0; // C
        boilingPoint = 2011.0; // C
        thermalConductivity = 10.0; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = FP_NAN; // kJ/mol
        heatFusion = FP_NAN; // kJ/mol
        ionization1st = 5.99; // eV
    }
};

/**
 * @brief Curium is a transuranic radioactive chemical element with the symbol Cm and
 * atomic number 96. This element of the actinide series was named after Marie and Pierre
 * Curie, both known for their research on radioactivity.
 */
class Curium : public Element {
public:
    Curium() {
        group = 3;
        symbol = "Cm";
        type = "Actinoid";
        crystal_type = "Double Hexagonal Close Packed";
        electron_configuration = "[Rn]5f7 6d1 7s2";
        atomicWeight = (247); // u (g/mol)
        atomicNumber = 96;
        energyLevels = {2, 8, 18, 32, 25, 9, 2};
        densitySTP = 13510.0; // kg/m^3
        meltingPoint = 1345.0; // C
        boilingPoint = 3110.0; // C
        thermalConductivity = FP_NAN; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = FP_NAN; // kJ/mol
        heatFusion = FP_NAN; // kJ/mol
        ionization1st = 6.02; // eV
    }
};

/**
 * @brief Berkelium is a transuranic radioactive chemical element with the symbol Bk and
 * atomic number 97. It is a member of the actinide and transuranium element
 * series. It is named after the city of Berkeley, California, the location
 * of the Lawrence Berkeley National Laboratory where it was discovered in
 * December 1949.
 */
class Berkelium : public Element {
public:
    Berkelium() {
        group = 3;
        symbol = "Bk";
        type = "Actinoid";
        crystal_type = "Double Hexagonal Close Packed";
        electron_configuration = "[Rn]5f9 7s2";
        atomicWeight = (247); // u (g/mol)
        atomicNumber = 97;
        energyLevels = {2, 8, 18, 32, 27, 8, 2};
        densitySTP = 14780.00; // kg/m^3
        meltingPoint = 1050.0; // C
        boilingPoint = FP_NAN; // C
        thermalConductivity = 10.0; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = FP_NAN; // kJ/mol
        heatFusion = FP_NAN; // kJ/mol
        ionization1st = 6.23; // eV
    }
};

/**
 * @brief Californium is a radioactive chemical element with the symbol Cf and atomic
 * number 98. The element was first synthesized in 1950 at the Lawrence Berkeley
 * National Laboratory, by bombarding curium with alpha particles.
 */
class Californium : public Element {
public:
    Californium() {
        group = 3;
        symbol = "Cf";
        type = "Actinoid";
        crystal_type = "Double Hexagonal Close Packed";
        electron_configuration = "[Rn]5f10 7s2";
        atomicWeight = (251); // u (g/mol)
        atomicNumber = 98;
        energyLevels = {2, 8, 18, 32, 28, 8, 2};
        densitySTP = 15100.0; // kg/m^3
        meltingPoint = 899.9; // C
        boilingPoint = FP_NAN; // C
        thermalConductivity = FP_NAN; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = FP_NAN; // kJ/mol
        heatFusion = FP_NAN; // kJ/mol
        ionization1st = 6.30; // eV
    }
};

/**
 * @brief Einsteinium is a synthetic element with the symbol Es and atomic number 99.
 * Einsteinium is a member of the actinide series and it is the seventh transuranic
 * element. It is named to honor Albert Einstein. Einsteinium was discovered as a
 * component of the debris of the first hydrogen bomb explosion in 1952.
 */
class Einsteinium : public Element {
public:
    Einsteinium() {
        group = 3;
        symbol = "Es";
        type = "Actinoid";
        crystal_type = "Face-Centered Cubic";
        electron_configuration = "[Rn]5f11 7s2";
        atomicWeight = (252); // u (g/mol)
        atomicNumber = 99;
        energyLevels = {2, 8, 18, 32, 29, 8, 2};
        densitySTP = FP_NAN; // kg/m^3
        meltingPoint = 859.9; // C
        boilingPoint = FP_NAN; // C
        thermalConductivity = FP_NAN; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = FP_NAN; // kJ/mol
        heatFusion = FP_NAN; // kJ/mol
        ionization1st = 6.42; // eV
    }
};

/**
 * @brief Fermium is a synthetic element with the symbol Fm and atomic number 100.
 * It is an actinide and the heaviest element that can be formed by neutron
 * bombardment of lighter elements, and hence the last element that can be
 * prepared in macroscopic quantities, although pure fermium metal has not yet
 * been prepared.
 */
class Fermium : public Element {
public:
    Fermium() {
        group = 3;
        symbol = "Fm";
        type = "Actinoid";
        crystal_type = "Face-Centered Cubic";
        electron_configuration = "[Rn]5f12 7s2";
        atomicWeight = (257); // u (g/mol)
        atomicNumber = 100;
        energyLevels = {2, 8, 18, 32, 30, 8, 2};
        densitySTP = FP_NAN; // kg/m^3
        meltingPoint = 1500.0; // C
        boilingPoint = FP_NAN; // C
        thermalConductivity = FP_NAN; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = FP_NAN; // kJ/mol
        heatFusion = FP_NAN; // kJ/mol
        ionization1st = 6.50; // eV
    }
};

/**
 * @brief Mendelevium is a synthetic element with the symbol Md and atomic number 101.
 * A metallic radioactive transuranic element in the actinide series, it is the
 * first element by atomic number that currently cannot be produced in
 * macroscopic quantities through neutron bombardment of lighter elements.
 */
class Mendelevium : public Element {
public:
    Mendelevium() {
        group = 3;
        symbol = "Md";
        type = "Actinoid";
        crystal_type = "Face-Centered Cubic";
        electron_configuration = "[Rn]5f13 7s2";
        atomicWeight = (258); // u (g/mol)
        atomicNumber = 101;
        energyLevels = {2, 8, 18, 32, 31, 8, 2};
        densitySTP = FP_NAN; // kg/m^3
        meltingPoint = 830.0; // C
        boilingPoint = FP_NAN; // C
        thermalConductivity = FP_NAN; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = FP_NAN; // kJ/mol
        heatFusion = FP_NAN; // kJ/mol
        ionization1st = 6.58; // eV
    }
};

/**
 * @brief Nobelium is a synthetic chemical element with the symbol No and atomic number 102.
 * It is named in honor of Alfred Nobel, the inventor of dynamite and benefactor
 * of science. A radioactive metal it is the tenth transuranic element and is
 * the penultimate member of the actinide series.
 */
class Nobelium : public Element {
public:
    Nobelium() {
        group = 3;
        symbol = "No";
        type = "Actinoid";
        crystal_type = "Face-Centered Cubic";
        electron_configuration = "[Rn]5f14 7s2";
        atomicWeight = (259); // u (g/mol)
        atomicNumber = 102;
        energyLevels = {2, 8, 18, 32, 32, 8, 2};
        densitySTP = FP_NAN; // kg/m^3
        meltingPoint = 830.0; // C
        boilingPoint = FP_NAN; // C
        thermalConductivity = FP_NAN; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = FP_NAN; // kJ/mol
        heatFusion = FP_NAN; // kJ/mol
        ionization1st = 6.65; // eV
    }
};

/**
 * @brief Lawrencium is a synthetic chemical element with the symbol Lr and atomic number 103.
 * It is named in honor of Ernest Lawrence, inventor of the cyclotron, a
 * device that was used to discover many artificial radioactive elements.
 */
class Lawrencium : public Element {
public:
    Lawrencium() {
        group = 3;
        symbol = "Lr";
        type = "Actinoid";
        crystal_type = "Hexagonal Close Packed:?";
        electron_configuration = "[Rn]5f14 7s2 7p1";
        atomicWeight = (266); // u (g/mol)
        atomicNumber = 103;
        energyLevels = {2, 8, 18, 32, 32, 8, 3};
        densitySTP = FP_NAN; // kg/m^3
        meltingPoint = 1600.0; // C
        boilingPoint = FP_NAN; // C
        thermalConductivity = FP_NAN; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = FP_NAN; // kJ/mol
        heatFusion = FP_NAN; // kJ/mol
        ionization1st = 4.87; // eV
    }
};

/**
 * @brief Rutherfordium is a synthetic chemical element with the symbol Rf and atomic number 104,
 * named after New Zealand physicist Ernest Rutherford. As a synthetic element,
 * it is not found in nature and can only be created in a laboratory.
 */
class Rutherfordium : public Element {
public:
    Rutherfordium() {
        group = 4;
        symbol = "Rf";
        type = "Transition Metal";
        crystal_type = "Hexagonal Close Packed:?";
        electron_configuration = "[Rn]5f14 6d2 7s2";
        atomicWeight = (267); // u (g/mol)
        atomicNumber = 104;
        energyLevels = {2, 8, 18, 32, 32, 10, 2};
        densitySTP = FP_NAN; // kg/m^3
        meltingPoint = FP_NAN; // C
        boilingPoint = FP_NAN; // C
        thermalConductivity = FP_NAN; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = FP_NAN; // kJ/mol
        heatFusion = FP_NAN; // kJ/mol
        ionization1st = 6.01; // eV
    }
};

/**
 * @brief Dubnium is a synthetic chemical element with the symbol Db and atomic number 105.
 * Dubnium is highly radioactive: the most stable known isotope, dubnium-268,
 * has a half-life of about 28 hours. This greatly limits extended research
 * on dubnium. Dubnium does not occur naturally on Earth and is produced
 * artificially.
 */
class Dubnium : public Element {
public:
    Dubnium() {
        group = 5;
        symbol = "Db";
        type = "Transition Metal";
        crystal_type = "Body-Centered Cubic:?";
        electron_configuration = "[Rn]5f14 6d3 7s2";
        atomicWeight = (268); // u (g/mol)
        atomicNumber = 105;
        energyLevels = {2, 8, 18, 32, 32, 11, 2};
        densitySTP = FP_NAN; // kg/m^3
        meltingPoint = FP_NAN; // C
        boilingPoint = FP_NAN; // C
        thermalConductivity = FP_NAN; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = FP_NAN; // kJ/mol
        heatFusion = FP_NAN; // kJ/mol
        ionization1st = FP_NAN; // eV
    }
};

/**
 * @brief Seaborgium is a synthetic chemical element with the symbol Sg and atomic number 106.
 * It is named after the American nuclear chemist Glenn T. Seaborg. As a synthetic
 * element, it can be created in a laboratory but is not found in nature.
 */
class Seaborgium : public Element {
public:
    Seaborgium() {
        group = 6;
        symbol = "Sg";
        type = "Transition Metal";
        crystal_type = "Body-Centered Cubic:?";
        electron_configuration = "[Rn]5f14 6d4 7s2";
        atomicWeight = (269); // u (g/mol)
        atomicNumber = 106;
        energyLevels = {2, 8, 18, 32, 32, 12, 2};
        densitySTP = FP_NAN; // kg/m^3
        meltingPoint = FP_NAN; // C
        boilingPoint = FP_NAN; // C
        thermalConductivity = FP_NAN; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = FP_NAN; // kJ/mol
        heatFusion = FP_NAN; // kJ/mol
        ionization1st = FP_NAN; // eV
    }
};

/**
 * @brief Bohrium is a synthetic chemical element with the symbol Bh and atomic number 107.
 * It is named after Danish physicist Niels Bohr. As a synthetic element,
 * it can be created in a laboratory but is not found in nature.
 */
class Bohrium : public Element {
public:
    Bohrium() {
        group = 7;
        symbol = "Bh";
        type = "Transition Metal";
        crystal_type = "Hexagonal Close Packed:?";
        electron_configuration = "[Rn]5f14 6d5 7s2";
        atomicWeight = (270); // u (g/mol)
        atomicNumber = 107;
        energyLevels = {2, 8, 18, 32, 32, 13, 2};
        densitySTP = FP_NAN; // kg/m^3
        meltingPoint = FP_NAN; // C
        boilingPoint = FP_NAN; // C
        thermalConductivity = FP_NAN; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = FP_NAN; // kJ/mol
        heatFusion = FP_NAN; // kJ/mol
        ionization1st = FP_NAN; // eV
    }
};

/**
 * @brief Hassium is a chemical element with the symbol Hs and the atomic number 108.
 * Hassium is highly radioactive; its most stable known isotopes have half-lives
 * of approximately ten seconds.
 */
class Hassium : public Element {
public:
    Hassium() {
        group = 8;
        symbol = "Hs";
        type = "Transition Metal";
        crystal_type = "Hexagonal Close Packed:?";
        electron_configuration = "[Rn]5f14 6d6 7s2";
        atomicWeight = 277; // u (g/mol)
        atomicNumber = 108;
        energyLevels = {2, 8, 18, 32, 32, 14, 2};
        densitySTP = FP_NAN; // kg/m^3
        meltingPoint = FP_NAN; // C
        boilingPoint = FP_NAN; // C
        thermalConductivity = FP_NAN; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = FP_NAN; // kJ/mol
        heatFusion = FP_NAN; // kJ/mol
        ionization1st = FP_NAN; // eV
    }
};

/**
 * @brief Meitnerium is a synthetic chemical element with the symbol Mt and atomic number 109.
 * It is an extremely radioactive synthetic element. The most stable known isotope,
 * meitnerium-278, has a half-life of 4.5 seconds, although the unconfirmed
 * meitnerium-282 may have a longer half-life of 67 seconds.
 */
class Meitnerium : public Element {
public:
    Meitnerium() {
        group = 9;
        symbol = "Mt";
        type = "N/A";
        crystal_type = "Face-Centered Cubic:?";
        electron_configuration = "([Rn]5f14 6d7 7s2):?";
        atomicWeight = 278; // u (g/mol)
        atomicNumber = 109;
        energyLevels = {2, 8, 18, 32, 32, 15, 2};
        densitySTP = FP_NAN; // kg/m^3
        meltingPoint = FP_NAN; // C
        boilingPoint = FP_NAN; // C
        thermalConductivity = FP_NAN; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = FP_NAN; // kJ/mol
        heatFusion = FP_NAN; // kJ/mol
        ionization1st = FP_NAN; // eV
    }
};

/**
 * @brief Darmstadtium is a chemical element with the symbol Ds and atomic number 110.
 * It is an extremely radioactive synthetic element. The most stable known
 * isotope, darmstadtium-281, has a half-life of approximately 12.7 seconds.
 */
class Darmstadtium : public Element {
public:
    Darmstadtium() {
        group = 10;
        symbol = "Ds";
        type = "N/A";
        crystal_type = "Body-Centered Cubic:?";
        electron_configuration = "([Rn]5f14 6d9 7s1):?";
        atomicWeight = 281; // u (g/mol)
        atomicNumber = 110;
        energyLevels = {2, 8, 18, 32, 32, 17, 1};
        densitySTP = FP_NAN; // kg/m^3
        meltingPoint = FP_NAN; // C
        boilingPoint = FP_NAN; // C
        thermalConductivity = FP_NAN; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = FP_NAN; // kJ/mol
        heatFusion = FP_NAN; // kJ/mol
        ionization1st = FP_NAN; // eV
    }
};

/**
 * @brief Roentgenium is a chemical element with the symbol Rg and atomic number 111.
 * It is an extremely radioactive synthetic element that can be created in a
 * laboratory but is not found in nature.
 */
class Roentgenium : public Element {
public:
    Roentgenium() {
        group = 11;
        symbol = "Rg";
        type = "N/A";
        crystal_type = "Body-Centered Cubic:?";
        electron_configuration = "([Rn]5f14 6d10 7s1):?";
        atomicWeight = 282; // u (g/mol)
        atomicNumber = 111;
        energyLevels = {2, 8, 18, 32, 32, 17, 2};
        densitySTP = FP_NAN; // kg/m^3
        meltingPoint = FP_NAN; // C
        boilingPoint = FP_NAN; // C
        thermalConductivity = FP_NAN; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = FP_NAN; // kJ/mol
        heatFusion = FP_NAN; // kJ/mol
        ionization1st = FP_NAN; // eV
    }
};

/**
 * @brief Copernicium is a synthetic chemical element with the symbol Cn and atomic number 112.
 * Its known isotopes are extremely radioactive, and have only been created in a laboratory.
 * The most stable known isotope, copernicium-285, has a half-life of approximately 28 seconds.
 */
class Copernicium : public Element {
public:
    Copernicium() {
        group = 12;
        symbol = "Cn";
        type = "N/A";
        crystal_type = "Hexagonal Close Packed:?";
        electron_configuration = "([Rn]5f14 6d10 7s2):?";
        atomicWeight = 285; // u (g/mol)
        atomicNumber = 112;
        energyLevels = {2, 8, 18, 32, 32, 18, 2};
        densitySTP = FP_NAN; // kg/m^3
        meltingPoint = FP_NAN; // C
        boilingPoint = FP_NAN; // C
        thermalConductivity = FP_NAN; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = FP_NAN; // kJ/mol
        heatFusion = FP_NAN; // kJ/mol
        ionization1st = FP_NAN; // eV
    }
};

/**
 * @brief Nihonium is a synthetic chemical element with the symbol Nh and atomic number 113.
 * It is extremely radioactive; its most stable known isotope, nihonium-286,
 * has a half-life of about 10 seconds. In the periodic table nihonium is a
 * transactinide element in the p-block. It is a member of period 7 and group 13.
 */
class Nihonium : public Element {
public:
    Nihonium() {
        group = 13;
        symbol = "Nh";
        type = "N/A";
        crystal_type = "Hexagonal Close Packed:?";
        electron_configuration = "([Rn]5f14 6d10 7s2 7p1):?";
        atomicWeight = 286; // u (g/mol)
        atomicNumber = 113;
        energyLevels = {2, 8, 18, 32, 32, 18, 3};
        densitySTP = FP_NAN; // kg/m^3
        meltingPoint = FP_NAN; // C
        boilingPoint = FP_NAN; // C
        thermalConductivity = FP_NAN; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = FP_NAN; // kJ/mol
        heatFusion = FP_NAN; // kJ/mol
        ionization1st = FP_NAN; // eV
    }
};

/**
 * @brief Flerovium is a superheavy artificial chemical element with the symbol Fl and atomic number 114.
 * It is an extremely radioactive synthetic element. The element is named
 * after the Flerov Laboratory of Nuclear Reactions of the Joint Institute
 * for Nuclear Research in Dubna, Russia, where the element was discovered in 1998.
 */
class Flerovium : public Element {
public:
    Flerovium() {
        group = 14;
        symbol = "Fl";
        type = "N/A";
        crystal_type = "N/A";
        electron_configuration = "([Rn]5f14 6d10 7s2 7p2):?";
        atomicWeight = 289; // u (g/mol)
        atomicNumber = 114;
        energyLevels = {2, 8, 18, 32, 32, 18, 4};
        densitySTP = FP_NAN; // kg/m^3
        meltingPoint = FP_NAN; // C
        boilingPoint = FP_NAN; // C
        thermalConductivity = FP_NAN; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = FP_NAN; // kJ/mol
        heatFusion = FP_NAN; // kJ/mol
        ionization1st = FP_NAN; // eV
    }
};

/**
 * @brief Moscovium is a synthetic chemical element with the symbol Mc and atomic number 115.
 * It was first synthesized in 2003 by a joint team of Russian and American scientists
 * at the Joint Institute for Nuclear Research in Dubna, Russia.
 */
class Moscovium : public Element {
public:
    Moscovium() {
        group = 15;
        symbol = "Mc";
        type = "N/A";
        crystal_type = "N/A";
        electron_configuration = "([Rn]5f14 6d10 7s2 7p3):?";
        atomicWeight = 290; // u (g/mol)
        atomicNumber = 115;
        energyLevels = {2, 8, 18, 32, 32, 18, 5};
        densitySTP = FP_NAN; // kg/m^3
        meltingPoint = FP_NAN; // C
        boilingPoint = FP_NAN; // C
        thermalConductivity = FP_NAN; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = FP_NAN; // kJ/mol
        heatFusion = FP_NAN; // kJ/mol
        ionization1st = FP_NAN; // eV
    }
};

/**
 * @brief Livermorium is a synthetic chemical element with the symbol Lv and has an atomic number of 116.
 * It is an extremely radioactive element that has only been created in the
 * laboratory and has not been observed in nature.
 */
class Livermorium : public Element {
public:
    Livermorium() {
        group = 16;
        symbol = "Lv";
        type = "N/A";
        crystal_type = "N/A";
        electron_configuration = "([Rn]5f14 6d10 7s2 7p4):?";
        atomicWeight = 293; // u (g/mol)
        atomicNumber = 116;
        energyLevels = {2, 8, 18, 32, 32, 18, 6};
        densitySTP = FP_NAN; // kg/m^3
        meltingPoint = FP_NAN; // C
        boilingPoint = FP_NAN; // C
        thermalConductivity = FP_NAN; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = FP_NAN; // kJ/mol
        heatFusion = FP_NAN; // kJ/mol
        ionization1st = FP_NAN; // eV
    }
};

/**
 * @brief Tennessine is a synthetic chemical element with the symbol Ts and atomic number 117.
 * It is the second-heaviest known element and the penultimate element of the
 * 7th period of the periodic table.
 */
class Tennessine : public Element {
public:
    Tennessine() {
        group = 17;
        symbol = "Ts";
        type = "N/A";
        crystal_type = "N/A";
        electron_configuration = "([Rn]5f14 6d10 7s2 7p5):?";
        atomicWeight = 294; // u (g/mol)
        atomicNumber = 117;
        energyLevels = {2, 8, 18, 32, 32, 18, 7};
        densitySTP = FP_NAN; // kg/m^3
        meltingPoint = FP_NAN; // C
        boilingPoint = FP_NAN; // C
        thermalConductivity = FP_NAN; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = FP_NAN; // kJ/mol
        heatFusion = FP_NAN; // kJ/mol
        ionization1st = FP_NAN; // eV
    }
};

/**
 * @brief Oganesson is a synthetic chemical element with the symbol Og and atomic number 118.
 * It was first synthesized in 2002 at the Joint Institute for Nuclear Research in Dubna,
 * near Moscow, Russia, by a joint team of Russian and American scientists.
 */
class Oganesson : public Element {
public:
    Oganesson() {
        group = 18;
        symbol = "Og";
        type = "N/A";
        crystal_type = "Face-centered cubic:?";
        electron_configuration = "([Rn]5f14 6d10 7s2 7p6):?";
        atomicWeight = 294; // u (g/mol)
        atomicNumber = 118;
        energyLevels = {2, 8, 18, 32, 32, 18, 8};
        densitySTP = FP_NAN; // kg/m^3
        meltingPoint = FP_NAN; // C
        boilingPoint = FP_NAN; // C
        thermalConductivity = FP_NAN; // W/mK
        electricConductivity = FP_NAN; // MS/m
        resistivity = FP_NAN; // m Ohm (m * kg*m^2*s^-3*A^-2)
        heatSpecific = FP_NAN; // J/kgK
        heatVaporization = FP_NAN; // kJ/mol
        heatFusion = FP_NAN; // kJ/mol
        ionization1st = FP_NAN; // eV
    }
};


static long double getLatentHeatFusion(string element) {
    // turn element into lowercase
    transform(element.begin(), element.end(), element.begin(), ::tolower);
    // get the latent heat converted from kJ/mol to J/kg
    if (element == "h" || element == "hydrogen") {
        Hydrogen h;
        return h.getHeatFusion() * 1000.0 / (h.getAtomicWeight()/1000.0);
    }
    else if (element == "he" || element == "helium") {
        Helium he;
        return he.getHeatFusion() * 1000.0 / (he.getAtomicWeight()/1000.0);
    }
    else if (element == "li" || element == "lithium") {
        Lithium li;
        return li.getHeatFusion() * 1000.0 / (li.getAtomicWeight()/1000.0);
    }
    else if (element == "be" || element == "beryllium") {
        Beryllium be;
        return be.getHeatFusion() * 1000.0 / (be.getAtomicWeight()/1000.0);
    }
    else if (element == "b" || element == "boron") {
        Boron b;
        return b.getHeatFusion() * 1000.0 / (b.getAtomicWeight()/1000.0);
    }
    else if (element == "c" || element == "carbon") {
        Carbon c;
        return c.getHeatFusion() * 1000.0 / (c.getAtomicWeight()/1000.0);
    }
    else if (element == "n" || element == "nitrogen") {
        Nitrogen n;
        return n.getHeatFusion() * 1000.0 / (n.getAtomicWeight()/1000.0);
    }
    else if (element == "o" || element == "oxygen") {
        Oxygen o;
        return o.getHeatFusion() * 1000.0 / (o.getAtomicWeight()/1000.0);
    }
    else if (element == "f" || element == "fluorine") {
        Fluorine f;
        return f.getHeatFusion() * 1000.0 / (f.getAtomicWeight()/1000.0);
    }
    else if (element == "ne" || element == "neon") {
        Neon ne;
        return ne.getHeatFusion() * 1000.0 / (ne.getAtomicWeight()/1000.0);
    }
    else if (element == "na" || element == "sodium") {
        Sodium na;
        return na.getHeatFusion() * 1000.0 / (na.getAtomicWeight() / 1000.0);
    }
    else if (element == "mg" || element == "magnesium") {
        Magnesium mg;
        return mg.getHeatFusion() * 1000.0 / (mg.getAtomicWeight() / 1000.0);
    }
    else if (element == "al" || element == "aluminium") {
        Aluminium al;
        return al.getHeatFusion() * 1000.0 / (al.getAtomicWeight() / 1000.0);
    }
    else if (element == "si" || element == "silicon") {
        Silicon si;
        return si.getHeatFusion() * 1000.0 / (si.getAtomicWeight() / 1000.0);
    }
    else if (element == "p" || element == "phosphorus") {
        Phosphorus p;
        return p.getHeatFusion() * 1000.0 / (p.getAtomicWeight() / 1000.0);
    }
    else if (element == "s" || element == "sulfur") {
        Sulfur s;
        return s.getHeatFusion() * 1000.0 / (s.getAtomicWeight() / 1000.0);
    }
    else if (element == "cl" || element == "chlorine") {
        Chlorine cl;
        return cl.getHeatFusion() * 1000.0 / (cl.getAtomicWeight() / 1000.0);
    }
    else if (element == "ar" || element == "argon") {
        Argon ar;
        return ar.getHeatFusion() * 1000.0 / (ar.getAtomicWeight() / 1000.0);
    }
    else if (element == "k" || element == "potassium") {
        Potassium k;
        return k.getHeatFusion() * 1000.0 / (k.getAtomicWeight() / 1000.0);
    }
    else if (element == "ca" || element == "calcium") {
        Calcium ca;
        return ca.getHeatFusion() * 1000.0 / (ca.getAtomicWeight() / 1000.0);
    }
    else if (element == "sc" || element == "scandium") {
        Scandium sc;
        return sc.getHeatFusion() * 1000.0 / (sc.getAtomicWeight() / 1000.0);
    }
    else if (element == "ti" || element == "titanium") {
        Titanium ti;
        return ti.getHeatFusion() * 1000.0 / (ti.getAtomicWeight() / 1000.0);
    }
    else if (element == "v" || element == "vanadium") {
        Vanadium v;
        return v.getHeatFusion() * 1000.0 / (v.getAtomicWeight() / 1000.0);
    }
    else if (element == "cr" || element == "chromium") {
        Chromium cr;
        return cr.getHeatFusion() * 1000.0 / (cr.getAtomicWeight() / 1000.0);
    }
    else if (element == "mn" || element == "manganese") {
        Manganese mn;
        return mn.getHeatFusion() * 1000.0 / (mn.getAtomicWeight() / 1000.0);
    }
    else if (element == "fe" || element == "iron") {
        Iron fe;
        return fe.getHeatFusion() * 1000.0 / (fe.getAtomicWeight() / 1000.0);
    }
    else if (element == "co" || element == "cobalt") {
        Cobalt co;
        return co.getHeatFusion() * 1000.0 / (co.getAtomicWeight() / 1000.0);
    }
    else if (element == "ni" || element == "nickel") {
        Nickel ni;
        return ni.getHeatFusion() * 1000.0 / (ni.getAtomicWeight() / 1000.0);
    }
    else if (element == "cu" || element == "copper") {
        Copper cu;
        return cu.getHeatFusion() * 1000.0 / (cu.getAtomicWeight() / 1000.0);
    }
    else if (element == "zn" || element == "zinc") {
        Zinc zn;
        return zn.getHeatFusion() * 1000.0 / (zn.getAtomicWeight() / 1000.0);
    }
    else if (element == "ga" || element == "gallium") {
        Gallium ga;
        return ga.getHeatFusion() * 1000.0 / (ga.getAtomicWeight() / 1000.0);
    }
    else if (element == "ge" || element == "germanium") {
        Germanium ge;
        return ge.getHeatFusion() * 1000.0 / (ge.getAtomicWeight() / 1000.0);
    }
    else if (element == "as" || element == "arsenic") {
        Arsenic as;
        return as.getHeatFusion() * 1000.0 / (as.getAtomicWeight() / 1000.0);
    }
    else if (element == "se" || element == "selenium") {
        Selenium se;
        return se.getHeatFusion() * 1000.0 / (se.getAtomicWeight() / 1000.0);
    }
    else if (element == "br" || element == "bromine") {
        Bromine br;
        return br.getHeatFusion() * 1000.0 / (br.getAtomicWeight() / 1000.0);
    }
    else if (element == "kr" || element == "krypton") {
        Krypton kr;
        return kr.getHeatFusion() * 1000.0 / (kr.getAtomicWeight() / 1000.0);
    }
    else if (element == "rb" || element == "rubidium") {
        Rubidium rb;
        return rb.getHeatFusion() * 1000.0 / (rb.getAtomicWeight() / 1000.0);
    }
    else if (element == "sr" || element == "strontium") {
        Strontium sr;
        return sr.getHeatFusion() * 1000.0 / (sr.getAtomicWeight() / 1000.0);
    }
    else if (element == "y" || element == "yttrium") {
        Yttrium y;
        return y.getHeatFusion() * 1000.0 / (y.getAtomicWeight() / 1000.0);
    }
    else if (element == "zr" || element == "zirconium") {
        Zirconium zr;
        return zr.getHeatFusion() * 1000.0 / (zr.getAtomicWeight() / 1000.0);
    }
    else if (element == "nb" || element == "niobium") {
        Niobium nb;
        return nb.getHeatFusion() * 1000.0 / (nb.getAtomicWeight() / 1000.0);
    }
    else if (element == "mo" || element == "molybdenum") {
        Molybdenum mo;
        return mo.getHeatFusion() * 1000.0 / (mo.getAtomicWeight() / 1000.0);
    }
    else if (element == "tc" || element == "technetium") {
        Technetium tc;
        return tc.getHeatFusion() * 1000.0 / (tc.getAtomicWeight() / 1000.0);
    }
    else if (element == "ru" || element == "ruthenium") {
        Ruthenium ru;
        return ru.getHeatFusion() * 1000.0 / (ru.getAtomicWeight() / 1000.0);
    }
    else if (element == "rh" || element == "rhodium") {
        Rhodium rh;
        return rh.getHeatFusion() * 1000.0 / (rh.getAtomicWeight() / 1000.0);
    }
    else if (element == "pd" || element == "palladium") {
        Palladium pd;
        return pd.getHeatFusion() * 1000.0 / (pd.getAtomicWeight() / 1000.0);
    }
    else if (element == "ag" || element == "silver") {
        Silver ag;
        return ag.getHeatFusion() * 1000.0 / (ag.getAtomicWeight() / 1000.0);
    }
    else if (element == "cd" || element == "cadmium") {
        Cadmium cd;
        return cd.getHeatFusion() * 1000.0 / (cd.getAtomicWeight() / 1000.0);
    }
    else if (element == "in" || element == "indium") {
        Indium in;
        return in.getHeatFusion() * 1000.0 / (in.getAtomicWeight() / 1000.0);
    }
    else if (element == "sn" || element == "tin") {
        Tin sn;
        return sn.getHeatFusion() * 1000.0 / (sn.getAtomicWeight() / 1000.0);
    }
    else if (element == "sb" || element == "antimony") {
        Antimony sb;
        return sb.getHeatFusion() * 1000.0 / (sb.getAtomicWeight() / 1000.0);
    }
    else if (element == "te" || element == "tellurium") {
        Tellurium te;
        return te.getHeatFusion() * 1000.0 / (te.getAtomicWeight() / 1000.0);
    }
    else if (element == "i" || element == "iodine") {
        Iodine i;
        return i.getHeatFusion() * 1000.0 / (i.getAtomicWeight() / 1000.0);
    }
    else if (element == "xe" || element == "xenon") {
        Xenon xe;
        return xe.getHeatFusion() * 1000.0 / (xe.getAtomicWeight() / 1000.0);
    }
    else if (element == "cs" || element == "caesium") {
        Cerium cs;
        return cs.getHeatFusion() * 1000.0 / (cs.getAtomicWeight() / 1000.0);
    }
    else if (element == "ba" || element == "barium") {
        Barium ba;
        return ba.getHeatFusion() * 1000.0 / (ba.getAtomicWeight() / 1000.0);
    }
    else if (element == "la" || element == "lanthanum") {
        Lanthanum la;
        return la.getHeatFusion() * 1000.0 / (la.getAtomicWeight() / 1000.0);
    }
    else if (element == "ce" || element == "cerium") {
        Cerium ce;
        return ce.getHeatFusion() * 1000.0 / (ce.getAtomicWeight() / 1000.0);
    }
    else if (element == "pr" || element == "praseodymium") {
        Praseodymium pr;
        return pr.getHeatFusion() * 1000.0 / (pr.getAtomicWeight() / 1000.0);
    }
    else if (element == "nd" || element == "neodymium") {
        Neodymium nd;
        return nd.getHeatFusion() * 1000.0 / (nd.getAtomicWeight() / 1000.0);
    }
    else if (element == "pm" || element == "promethium") {
        Promethium pm;
        return pm.getHeatFusion() * 1000.0 / (pm.getAtomicWeight() / 1000.0);
    }
    else if (element == "sm" || element == "samarium") {
        Samarium sm;
        return sm.getHeatFusion() * 1000.0 / (sm.getAtomicWeight() / 1000.0);
    }
    else if (element == "eu" || element == "europium") {
        Europium eu;
        return eu.getHeatFusion() * 1000.0 / (eu.getAtomicWeight() / 1000.0);
    }
    else if (element == "gd" || element == "gadolinium") {
        Gadolinium gd;
        return gd.getHeatFusion() * 1000.0 / (gd.getAtomicWeight() / 1000.0);
    }
    else if (element == "tb" || element == "terbium") {
        Terbium tb;
        return tb.getHeatFusion() * 1000.0 / (tb.getAtomicWeight() / 1000.0);
    }
    else if (element == "dy" || element == "dysprosium") {
        Dysprosium dy;
        return dy.getHeatFusion() * 1000.0 / (dy.getAtomicWeight() / 1000.0);
    }
    else if (element == "ho" || element == "holmium") {
        Holmium ho;
        return ho.getHeatFusion() * 1000.0 / (ho.getAtomicWeight() / 1000.0);
    }
    else if (element == "er" || element == "erbium") {
        Erbium er;
        return er.getHeatFusion() * 1000.0 / (er.getAtomicWeight() / 1000.0);
    }
    else if (element == "tm" || element == "thulium") {
        Thulium tm;
        return tm.getHeatFusion() * 1000.0 / (tm.getAtomicWeight() / 1000.0);
    }
    else if (element == "yb" || element == "ytterbium") {
        Ytterbium yb;
        return yb.getHeatFusion() * 1000.0 / (yb.getAtomicWeight() / 1000.0);
    }
    else if (element == "lu" || element == "lutetium") {
        Lutetium lu;
        return lu.getHeatFusion() * 1000.0 / (lu.getAtomicWeight() / 1000.0);
    }
    else if (element == "hf" || element == "hafnium") {
        Hafnium hf;
        return hf.getHeatFusion() * 1000.0 / (hf.getAtomicWeight() / 1000.0);
    }
    else if (element == "ta" || element == "tantalum") {
        Tantalum ta;
        return ta.getHeatFusion() * 1000.0 / (ta.getAtomicWeight() / 1000.0);
    }
    else if (element == "w" || element == "tungsten") {
        Tungsten w;
        return w.getHeatFusion() * 1000.0 / (w.getAtomicWeight() / 1000.0);
    }
    else if (element == "re" || element == "rhenium") {
        Rhenium re;
        return re.getHeatFusion() * 1000.0 / (re.getAtomicWeight() / 1000.0);
    }
    else if (element == "os" || element == "osmium") {
        Osmium os;
        return os.getHeatFusion() * 1000.0 / (os.getAtomicWeight() / 1000.0);
    }
    else if (element == "ir" || element == "iridium") {
        Iridium ir;
        return ir.getHeatFusion() * 1000.0 / (ir.getAtomicWeight() / 1000.0);
    }
    else if (element == "pt" || element == "platinum") {
        Platinum pt;
        return pt.getHeatFusion() * 1000.0 / (pt.getAtomicWeight() / 1000.0);
    }
    else if (element == "au" || element == "gold") {
        Gold au;
        return au.getHeatFusion() * 1000.0 / (au.getAtomicWeight() / 1000.0);
    }
    else if (element == "hg" || element == "mercury") {
        Mercury hg;
        return hg.getHeatFusion() * 1000.0 / (hg.getAtomicWeight() / 1000.0);
    }
    else if (element == "tl" || element == "thallium") {
        Thallium tl;
        return tl.getHeatFusion() * 1000.0 / (tl.getAtomicWeight() / 1000.0);
    }
    else if (element == "pb" || element == "lead") {
        Lead pb;
        return pb.getHeatFusion() * 1000.0 / (pb.getAtomicWeight() / 1000.0);
    }
    else if (element == "bi" || element == "bismuth") {
        Bismuth bi;
        return bi.getHeatFusion() * 1000.0 / (bi.getAtomicWeight() / 1000.0);
    }
    else if (element == "po" || element == "polonium") {
        Polonium po;
        return po.getHeatFusion() * 1000.0 / (po.getAtomicWeight() / 1000.0);
    }
    else if (element == "at" || element == "astatine") {
        Astatine at;
        return at.getHeatFusion() * 1000.0 / (at.getAtomicWeight() / 1000.0);
    }
    else if (element == "rn" || element == "radon") {
        Radon rn;
        return rn.getHeatFusion() * 1000.0 / (rn.getAtomicWeight() / 1000.0);
    }
    else if (element == "fr" || element == "francium") {
        Francium fr;
        return fr.getHeatFusion() * 1000.0 / (fr.getAtomicWeight() / 1000.0);
    }
    else if (element == "ra" || element == "radium") {
        Radium ra;
        return ra.getHeatFusion() * 1000.0 / (ra.getAtomicWeight() / 1000.0);
    }
    else if (element == "rf" || element == "rutherfordium") {
        Rutherfordium rf;
        return rf.getHeatFusion() * 1000.0 / (rf.getAtomicWeight() / 1000.0);
    }
    else if (element == "db" || element == "dubnium") {
        Dubnium db;
        return db.getHeatFusion() * 1000.0 / (db.getAtomicWeight() / 1000.0);
    }
    else if (element == "sg" || element == "seaborgium") {
        Seaborgium sg;
        return sg.getHeatFusion() * 1000.0 / (sg.getAtomicWeight() / 1000.0);
    }
    else if (element == "bh" || element == "bohrium") {
        Bohrium bh;
        return bh.getHeatFusion() * 1000.0 / (bh.getAtomicWeight() / 1000.0);
    }
    else if (element == "hs" || element == "hassium") {
        Hassium hs;
        return hs.getHeatFusion() * 1000.0 / (hs.getAtomicWeight() / 1000.0);
    }
    else if (element == "mt" || element == "meitnerium") {
        Meitnerium mt;
        return mt.getHeatFusion() * 1000.0 / (mt.getAtomicWeight() / 1000.0);
    }
    else if (element == "ds" || element == "darmstadtium") {
        Darmstadtium ds;
        return ds.getHeatFusion() * 1000.0 / (ds.getAtomicWeight() / 1000.0);
    }
    else if (element == "rg" || element == "roentgenium") {
        Roentgenium rg;
        return rg.getHeatFusion() * 1000.0 / (rg.getAtomicWeight() / 1000.0);
    }
    else if (element == "cn" || element == "copernicium") {
        Copernicium cn;
        return cn.getHeatFusion() * 1000.0 / (cn.getAtomicWeight() / 1000.0);
    }
    else if (element == "nh" || element == "nihonium") {
        Nihonium nh;
        return nh.getHeatFusion() * 1000.0 / (nh.getAtomicWeight() / 1000.0);
    }
    else if (element == "fl" || element == "flerovium") {
        Flerovium fl;
        return fl.getHeatFusion() * 1000.0 / (fl.getAtomicWeight() / 1000.0);
    }
    else if (element == "mc" || element == "moscovium") {
        Moscovium mc;
        return mc.getHeatFusion() * 1000.0 / (mc.getAtomicWeight() / 1000.0);
    }
    else if (element == "lv" || element == "livermorium") {
        Livermorium lv;
        return lv.getHeatFusion() * 1000.0 / (lv.getAtomicWeight() / 1000.0);
    }
    else if (element == "ts" || element == "tennessine") {
        Tennessine ts;
        return ts.getHeatFusion() * 1000.0 / (ts.getAtomicWeight() / 1000.0);
    }
    else if (element == "og" || element == "oganesson") {
        Oganesson og;
        return og.getHeatFusion() * 1000.0 / (og.getAtomicWeight() / 1000.0);
    }
    else {
        return 0.0;
    }

}
