//
// Created by ryanz on 11/11/2022.
//

#ifndef PHYSICSFORMULA_RESISTORNODE_H
#define PHYSICSFORMULA_RESISTORNODE_H
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

template<typename T>
class ResistorNode {
public:
    std::vector<T> resistances;
    std::vector<T> voltages;
    std::vector<T> currents;
    std::vector<T> powers;
    T VCC;
    char type;
    T eR;
    T I;
    T P;

    ResistorNode() {
        resistances = {};
        type = 'p';
        VCC = 0.0;
        eR = 0.0;
        voltages = {};
        currents = {};
        powers = {};
        I = 0.0;
        P = 0.0;
    }

    ResistorNode(std::vector<T> r, T v, char t) {
        resistances = r;
        type = t;
        VCC = v;
        eR = calculateEquivalentResistance();
        if (type == 'p') {
            currents = calculateCurrents();
            I = calculateTotalCurrent();
            voltages = calculateVoltages();
            powers = calculatePowers();
            P = calculateTotalPower();
        } else {
            I = calculateTotalCurrent();
            voltages = calculateVoltages();
            currents = calculateCurrents();
            powers = calculatePowers();
            P = calculateTotalPower();
        }
    }

    ResistorNode(std::vector<ResistorNode> r, T v, char t) {
        resistances = {};
        type = t;
        VCC = v;
        for (const ResistorNode& resistor : r) {
            resistances.push_back(resistor.eR);
        }
        eR = calculateEquivalentResistance();
        // remove all the resistances from the vector that were just added
        for (const ResistorNode& resistor : r) {
            removeResistance(resistor.eR);
        }
        // add all the resistors from each node to the vector
        for (const ResistorNode& resistor : r) {
            for (T resistance : resistor.resistances) {
                resistances.push_back(resistance);
            }
        }
        if (type == 'p') {
            currents = calculateCurrents();
            I = calculateTotalCurrent();
            voltages = calculateVoltages();
            powers = calculatePowers();
            P = calculateTotalPower();
        } else {
            I = calculateTotalCurrent();
            voltages = calculateVoltages();
            currents = calculateCurrents();
            powers = calculatePowers();
            P = calculateTotalPower();
        }
    }

    void removeResistance(T r) {
        for (int i = 0; i < resistances.size(); i++) {
            if (resistances[i] == r) {
                resistances.erase(resistances.begin() + i);
                break;
            }
        }
    }

    void setVoltage(T v) {
        VCC = v;
        if (type == 'p') {
            currents = calculateCurrents();
            I = calculateTotalCurrent();
            voltages = calculateVoltages();
            powers = calculatePowers();
            P = calculateTotalPower();
        } else {
            I = calculateTotalCurrent();
            voltages = calculateVoltages();
            currents = calculateCurrents();
            powers = calculatePowers();
            P = calculateTotalPower();
        }
    }

    void setResistances(std::vector<T> r) {
        // assert that VCC is not 0
        assert(VCC != 0.0);
        resistances = r;
        eR = calculateEquivalentResistance();
        if (type == 'p') {
            currents = calculateCurrents();
            I = calculateTotalCurrent();
            voltages = calculateVoltages();
            powers = calculatePowers();
            P = calculateTotalPower();
        } else {
            I = calculateTotalCurrent();
            voltages = calculateVoltages();
            currents = calculateCurrents();
            powers = calculatePowers();
            P = calculateTotalPower();
        }
    }

    T calculateEquivalentResistance() {
        T sum = 0.0;
        if (type == 'p') {
            for (T resistance : resistances) {
                sum += 1.0 / resistance;
            }
            sum = 1.0 / sum;
        } else if (type == 's') {
            for (T resistance : resistances) {
                sum += resistance;
            }

        }
        return sum;
    }

    std::vector<T> calculateVoltages() {
        std::vector<T> _voltages;
        if (type == 'p') {
            // in parallel node voltages are equal to the voltage of the
            // source across each resistor
            for (T resistance : resistances) {
                _voltages.push_back(VCC);
            }
        } else if (type == 's') {
            for (T resistance : resistances) {
                _voltages.push_back((I * resistance));
            }
        }
        return _voltages;
    }

    std::vector<T> calculateCurrents() {
        std::vector<T> _currents;
        if (type == 'p') {
            for (int i = 0; i < resistances.size(); i++) {
                _currents.push_back((VCC / resistances[i]));
            }
        } else if (type == 's') {
            for (T resistance : resistances) {
                _currents.push_back(I);
            }
        }
        return _currents;

    }

    std::vector<T> calculatePowers() {
        std::vector<T> _powers;
        for (int i = 0; i < resistances.size(); i++) {
            _powers.push_back((pow(currents[i], 2)) * resistances[i]);
        }
        return _powers;
    }

    T calculateTotalPower() {
        return VCC * I;
    }

    T calculateTotalCurrent() {
        T sum = 0.0;
        if (type == 'p') {
            for (T current : currents) {
                sum += current;
            }
        } else if (type == 's') {
            sum = VCC / eR;
        }
        return sum;
    }

    void print() {
        // print a star banner
        std::cout << std::string(66, '*') << std::endl;
        std::cout << std::string(25, ' ') << "ResistorNode" << std::endl;
        std::cout << "type: " << (type == 'p' ? "parallel" : "series") << std::endl;
        std::cout << "VCC: " << VCC << " V" << std::endl;
        std::cout << std::endl;
        std::cout << "Resistances: " << std::endl;
        // print out  each resistor as well as the voltage across it and the current through it
        for (int i = 0; i < resistances.size(); i++) {
            std::cout << "resistor " << i + 1 << ": "
            << resistances[i] << " Ohm, voltage: "
            << voltages[i] << " V, current: "
            << currents[i] << " A, power: "
            << powers[i] << " W" << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Equivalent Resistance: " << eR << " Ohms" << std::endl;
        std::cout << "Total Current: " << I << " A" << std::endl;
        std::cout << "Total Power: " << P << " W" << std::endl;
        std::cout << std::string(66, '*') << std::endl;
    }

};


#endif //PHYSICSFORMULA_RESISTORNODE_H
