//
// Created by ryanz on 11/11/2022.
//

#ifndef PHYSICSFORMULA_RESISTORNODE_H
#define PHYSICSFORMULA_RESISTORNODE_H
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

class ResistorNode {
public:
    std::vector<double> resistances;
    std::vector<double> voltages;
    std::vector<double> currents;
    std::vector<double> powers;
    double VCC;
    char type;
    double eR;
    double I;
    double P;

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

    ResistorNode(std::vector<double> r, double v, char t) {
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

    ResistorNode(std::vector<ResistorNode> r, double v, char t) {
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
            for (double resistance : resistor.resistances) {
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

    void removeResistance(double r) {
        for (int i = 0; i < resistances.size(); i++) {
            if (resistances[i] == r) {
                resistances.erase(resistances.begin() + i);
                break;
            }
        }
    }

    void setVoltage(double v) {
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

    void setResistances(std::vector<double> r) {
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

    double calculateEquivalentResistance() {
        double sum = 0.0;
        if (type == 'p') {
            for (double resistance : resistances) {
                sum += 1.0 / resistance;
            }
            sum = 1.0 / sum;
        } else if (type == 's') {
            for (double resistance : resistances) {
                sum += resistance;
            }

        }
        return sum;
    }

    std::vector<double> calculateVoltages() {
        std::vector<double> _voltages;
        if (type == 'p') {
            // in parallel node voltages are equal to the voltage of the
            // source across each resistor
            for (double resistance : resistances) {
                _voltages.push_back(VCC);
            }
        } else if (type == 's') {
            for (double resistance : resistances) {
                _voltages.push_back((I * resistance));
            }
        }
        return _voltages;
    }

    std::vector<double> calculateCurrents() {
        std::vector<double> _currents;
        if (type == 'p') {
            for (int i = 0; i < resistances.size(); i++) {
                _currents.push_back((VCC / resistances[i]));
            }
        } else if (type == 's') {
            for (double resistance : resistances) {
                _currents.push_back(I);
            }
        }
        return _currents;

    }

    std::vector<double> calculatePowers() {
        std::vector<double> _powers;
        for (int i = 0; i < resistances.size(); i++) {
            _powers.push_back((pow(currents[i], 2)) * resistances[i]);
        }
        return _powers;
    }

    double calculateTotalPower() {
        return VCC * I;
    }

    double calculateTotalCurrent() {
        double sum = 0.0;
        if (type == 'p') {
            for (double current : currents) {
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
