//
// Created by ryanz on 12/3/2022.
//

#ifndef PHYSICSFORMULA_INDUCTORNODE_H
#define PHYSICSFORMULA_INDUCTORNODE_H
#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

class InductorNode {
public:
    double L{};
    double I{};
    double V{};
    double P{};
    double VCC{};
    double eL{};
    std::vector<double> inductances;
    std::vector<double> couplingCoefficients;
    std::vector<double> mutualInductances;
    std::vector<double> currents;
    std::vector<double> voltages;
    std::vector<double> powers;
    char type;

    InductorNode() {
        L = 0.0;
        I = 0.0;
        V = 0.0;
        P = 0.0;
        VCC = 0.0;
        eL = 0.0;
        inductances = {};
        couplingCoefficients = {};
        currents = {};
        voltages = {};
        powers = {};
        type = 'p';
    }

    InductorNode(double vcc, std::vector<double> l, char t) {
        VCC = vcc;
        inductances = std::move(l);
        type = t;
        couplingCoefficients = calculateCouplingCoefficients();
        mutualInductances = calculateMutualInductances();
        eL = calculateEquivalentInductance();
        currents = calculateCurrents();
        I = calculateTotalCurrent();
        voltages = calculateVoltages();
        powers = calculatePowers();
        P = calculateTotalPower();
    }

    InductorNode(double vcc, const std::vector<InductorNode>& l, char t) {
        VCC = vcc;
        type = t;
        // add all the inductances from each node to the vector
        for (const InductorNode& inductor : l) {
            inductances.push_back(inductor.eL);
        }
        couplingCoefficients = calculateCouplingCoefficients();
        mutualInductances = calculateMutualInductances();
        eL = calculateEquivalentInductance();
        // remove all the inductances from the vector that were just added
        for (const InductorNode& inductor : l) {
            removeInductance(inductor.eL);
        }
        // add all the inductors from each node to the vector
        for (const InductorNode& inductor : l) {
            for (double inductance : inductor.inductances) {
                inductances.push_back(inductance);
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

    void removeInductance(double l)
    {
        for (int i = 0; i < inductances.size(); i++) {
            if (inductances[i] == l) {
                inductances.erase(inductances.begin() + i);
                break;
            }
        }
    }

    std::vector<double> calculateCouplingCoefficients() {
        std::vector<double> couplingCoefficients_;
        for (int i = 0; i < inductances.size(); i++) {
            couplingCoefficients_.push_back(0.0);
        }
        for (int i = 0; i < inductances.size(); i++) {
            for (int j = 0; j < inductances.size(); j++) {
                if (i != j) {
                    couplingCoefficients_[i] += (inductances[j] / inductances[i]);
                }
            }
        }
        return couplingCoefficients_;
    }

    std::vector<double> calculateMutualInductances() {
        std::vector<double> mutualInductances_;
        for (int i = 0; i < inductances.size(); i++) {
            mutualInductances_.push_back(0.0);
        }
        for (int i = 0; i < inductances.size(); i++) {
            for (int j = 0; j < inductances.size(); j++) {
                if (i != j) {
                    mutualInductances_[i] += (inductances[j] / couplingCoefficients[j]);
                }
            }
        }
        return mutualInductances_;
    }

    double calculateEquivalentInductance() {
        double sum = 0.0;
        if (type == 'p') {
            for (double inductance : inductances) {
                sum += 1.0 / inductance;
            }
            sum = 1.0 / sum;
        } else if (type == 's') {
            for (double inductance : inductances) {
                sum += inductance;
            }

        }
        return sum;
    }

    std::vector<double> calculateVoltages() {
        std::vector<double> _voltages;
        if (type == 'p') {
            // calculate the voltage across each inductor
            for (double inductance : inductances) {
                _voltages.push_back((I * inductance));
            }
        } else if (type == 's') {
            for (double inductance : inductances) {
                _voltages.push_back(VCC);
            }
        }
        return _voltages;
    }

    std::vector<double> calculateCurrents() {
        std::vector<double> _currents;
        if (type == 'p') {
            // calculate the current through each inductor
            for (double inductance : inductances) {
                _currents.push_back((VCC / inductance));
            }
        } else if (type == 's') {
            for (double inductance : inductances) {
                _currents.push_back(I);
            }
        }
        return _currents;
    }

    std::vector<double> calculatePowers() {
        std::vector<double> _powers;
        for (int i = 0; i < inductances.size(); i++) {
            _powers.push_back((pow(currents[i], 2)) * inductances[i]);
        }
        return _powers;
    }

    double calculateTotalPower() {
        double sum = 0.0;
        if (type == 'p') {
            for (double power : powers) {
                sum += power;
            }
        } else if (type == 's') {
            sum = pow(I, 2) * eL;
        }
        return sum;
    }

    double calculateTotalCurrent() {
        double sum = 0.0;
        if (type == 'p') {
            for (double current : currents) {
                sum += current;
            }
        } else if (type == 's') {
            sum = VCC / eL;
        }
        return sum;
    }

    void print() {
        std::cout << std::string(66, '*') << std::endl;
        std::cout << "Inductors: " << std::endl;
        // print out  each inductor as well as the voltage across it and the current through it
        for (int i = 0; i < inductances.size(); i++) {
            std::cout << "inductor " << i + 1 << ": "
                      << inductances[i] << " H, voltage: "
                      << voltages[i] << " V, current: "
                      << currents[i] << " A, power: "
                      << powers[i] << " W" << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Equivalent Inductance: " << eL << " H" << std::endl;
        std::cout << "Total Current: " << I << " A" << std::endl;
        std::cout << "Total Power: " << P << " W" << std::endl;
        std::cout << std::string(66, '*') << std::endl;
    }


};


#endif //PHYSICSFORMULA_INDUCTORNODE_H
