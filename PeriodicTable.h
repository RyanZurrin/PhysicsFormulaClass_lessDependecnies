//
// Created by ryanz on 12/11/2022.
//

#ifndef PHYSICSFORMULA_PERIODICTABLE_H
#define PHYSICSFORMULA_PERIODICTABLE_H
#include "Element.h"
#include <vector>
#include <string>
#include <iostream>

class PeriodicTable {
    // vector of elements using index as atomic number so 0 is empty, 1 is H, 2 is He, etc.
    std::vector<Element> elements;
public:
    PeriodicTable() {
        // initialize elements vector with empty elements
        for (int i = 0; i < 119; i++) {
            elements.push_back(Element());
        }
        // add elements to vector
        elements[1] = Hydrogen();
        elements[2] = Helium();
        elements[3] = Lithium();
        elements[4] = Beryllium();
        elements[5] = Boron();
        elements[6] = Carbon();
        elements[7] = Nitrogen();
        elements[8] = Oxygen();
        elements[9] = Fluorine();
        elements[10] = Neon();
        elements[11] = Sodium();
        elements[12] = Magnesium();
        elements[13] = Aluminium();
        elements[14] = Silicon();
        elements[15] = Phosphorus();
        elements[16] = Sulfur();
        elements[17] = Chlorine();
        elements[18] = Argon();
        elements[19] = Potassium();
        elements[20] = Calcium();
        elements[21] = Scandium();
        elements[22] = Titanium();
        elements[23] = Vanadium();
        elements[24] = Chromium();
        elements[25] = Manganese();
        elements[26] = Iron();
        elements[27] = Cobalt();
        elements[28] = Nickel();
        elements[29] = Copper();
        elements[30] = Zinc();
        elements[31] = Gallium();
        elements[32] = Germanium();
        elements[33] = Arsenic();
        elements[34] = Selenium();
        elements[35] = Bromine();
        elements[36] = Krypton();
        elements[37] = Rubidium();
        elements[38] = Strontium();
        elements[39] = Yttrium();
        elements[40] = Zirconium();
        elements[41] = Niobium();
        elements[42] = Molybdenum();
        elements[43] = Technetium();
        elements[44] = Ruthenium();
        elements[45] = Rhodium();
        elements[46] = Palladium();
        elements[47] = Silver();
        elements[48] = Cadmium();
        elements[49] = Indium();
        elements[50] = Tin();
        elements[51] = Antimony();
        elements[52] = Tellurium();
        elements[53] = Iodine();
        elements[54] = Xenon();
        elements[55] = Caesium();
        elements[56] = Barium();
        elements[57] = Lanthanum();
        elements[58] = Cerium();
        elements[59] = Praseodymium();
        elements[60] = Neodymium();
        elements[61] = Promethium();
        elements[62] = Samarium();
        elements[63] = Europium();
        elements[64] = Gadolinium();
        elements[65] = Terbium();
        elements[66] = Dysprosium();
        elements[67] = Holmium();
        elements[68] = Erbium();
        elements[69] = Thulium();
        elements[70] = Ytterbium();
        elements[71] = Lutetium();
        elements[72] = Hafnium();
        elements[73] = Tantalum();
        elements[74] = Tungsten();
        elements[75] = Rhenium();
        elements[76] = Osmium();
        elements[77] = Iridium();
        elements[78] = Platinum();
        elements[79] = Gold();
        elements[80] = Mercury();
        elements[81] = Thallium();
        elements[82] = Lead();
        elements[83] = Bismuth();
        elements[84] = Polonium();
        elements[85] = Astatine();
        elements[86] = Radon();
        elements[87] = Francium();
        elements[88] = Radium();
        elements[89] = Actinium();
        elements[90] = Thorium();
        elements[91] = Protactinium();
        elements[92] = Uranium();
        elements[93] = Neptunium();
        elements[94] = Plutonium();
        elements[95] = Americium();
        elements[96] = Curium();
        elements[97] = Berkelium();
        elements[98] = Californium();
        elements[99] = Einsteinium();
        elements[100] = Fermium();
        elements[101] = Mendelevium();
        elements[102] = Nobelium();
        elements[103] = Lawrencium();
        elements[104] = Rutherfordium();
        elements[105] = Dubnium();
        elements[106] = Seaborgium();
        elements[107] = Bohrium();
        elements[108] = Hassium();
        elements[109] = Meitnerium();
        elements[110] = Darmstadtium();
        elements[111] = Roentgenium();
        elements[112] = Copernicium();
        elements[113] = Nihonium();
        elements[114] = Flerovium();
        elements[115] = Moscovium();
        elements[116] = Livermorium();
        elements[117] = Tennessine();
        elements[118] = Oganesson();
    }
    Element getElement(int atomicNumber) {
        return elements[atomicNumber];
    }
    Element getElement(const std::string& symbol) {
        for (int i = 1; i < 119; i++) {
            if (elements[i].getSymbol() == symbol) {
                return elements[i];
            }
        }
        return {};
    }
    Element getElement(std::string name, bool exact) {
        // convert name to lowercase
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        if (exact) {
            for (int i = 1; i < 119; i++) {
                std::string n = typeid(elements[i]).name()+1;
                transform(n.begin(), n.end(), n.begin(), ::tolower);
                if (n == name) {
                    return elements[i];
                }
            }
        }
        else {
            for (int i = 1; i < 119; i++) {
                std::string n = typeid(elements[i]).name()+1;
                transform(n.begin(), n.end(), n.begin(), ::tolower);
                if (n.find(name) != std::string::npos) {
                    return elements[i];
                }
            }
        }
        return {};
    }


    void printTable() {
        std::cout << "Atomic # Symbol Name Group Type CrystalType Electron "
                     "Configuration AtomicWeight EnergyLevels Density "
                     "STP MeltingPoint BoilingPoint ThermalConductivity "
                     "ElectricConductivity Resistivity HeatSpecific  "
                     "HeatVaporization HeatFusion Ionization1st" << std::endl;
        for (auto elem : elements) {
            std::cout << elem.getAtomicNumber() << " " << elem.getSymbol() << " " << typeid(elem).name()+1 << " " << elem.getGroup() << " " << elem.getType() << " " << elem.getCrystalType() << " " << elem.getElectronConfiguration() << " " << elem.getAtomicWeight() << " ";
            std::vector<long double> energyLevels = elem.getEnergyLevels();
            for (int j = 0; j < energyLevels.size(); j++) {
                std::cout << energyLevels[j] << " ";
            }
            std::cout << " " << elem.getDensitySTP() << " " << elem.getMeltingPoint() << " " << elem.getBoilingPoint() << " " << elem.getThermalConductivity() << " " << elem.getElectricConductivity() << " " << elem.getResistivity() << " " << elem.getHeatSpecific() << " " << elem.getHeatVaporization() << " " << elem.getHeatFusion() << " " << elem.getIonization1st() << std::endl;
        }
    }

    void printElement(std::string element) {
        Element elem = getElement(element, false);
        std::cout << "Atomic # Symbol Name Group Type CrystalType Electron "
                     "Configuration AtomicWeight EnergyLevels Density "
                     "STP MeltingPoint BoilingPoint ThermalConductivity "
                     "ElectricConductivity Resistivity HeatSpecific  "
                     "HeatVaporization HeatFusion Ionization1st" << std::endl;
        std::cout << elem.getAtomicNumber() << " " << elem.getSymbol() << " " << typeid(elem).name()+1 << " " << elem.getGroup() << " " << elem.getType() << " " << elem.getCrystalType() << " " << elem.getElectronConfiguration() << " " << elem.getAtomicWeight() << " ";
        std::vector<long double> energyLevels = elem.getEnergyLevels();
        for (int j = 0; j < energyLevels.size(); j++) {
            std::cout << energyLevels[j] << " ";
        }
        std::cout << " " << elem.getDensitySTP() << " " << elem.getMeltingPoint() << " " << elem.getBoilingPoint() << " " << elem.getThermalConductivity() << " " << elem.getElectricConductivity() << " " << elem.getResistivity() << " " << elem.getHeatSpecific() << " " << elem.getHeatVaporization() << " " << elem.getHeatFusion() << " " << elem.getIonization1st() << std::endl;
    }

};

#endif //PHYSICSFORMULA_PERIODICTABLE_H
