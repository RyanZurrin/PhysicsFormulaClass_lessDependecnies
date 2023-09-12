//
// Created by ryanz on 12/3/2022.
//

#ifndef PHYSICSFORMULA_INDUCTORNODE_H
#define PHYSICSFORMULA_INDUCTORNODE_H
#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

template<typename T>
class InductorNode {
public:
    T L{};
    T I{};
    T V{};
    T P{};
    T VCC{};
    T eL{};
    std::vector<T> inductances;
    std::vector<T> couplingCoefficients;
    std::vector<T> mutualInductances;
    std::vector<T> currents;
    std::vector<T> voltages;
    std::vector<T> powers;
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

    InductorNode(T vcc, std::vector<T> l, char t) {
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

    InductorNode(T vcc, const std::vector<InductorNode>& l, char t) {
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
            for (T inductance : inductor.inductances) {
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

    void removeInductance(T l)
    {
        for (int i = 0; i < inductances.size(); i++) {
            if (inductances[i] == l) {
                inductances.erase(inductances.begin() + i);
                break;
            }
        }
    }

    std::vector<T> calculateCouplingCoefficients() {
        std::vector<T> couplingCoefficients_;
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

    std::vector<T> calculateMutualInductances() {
        std::vector<T> mutualInductances_;
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

    T calculateEquivalentInductance() {
        T sum = 0.0;
        if (type == 'p') {
            for (T inductance : inductances) {
                sum += 1.0 / inductance;
            }
            sum = 1.0 / sum;
        } else if (type == 's') {
            for (T inductance : inductances) {
                sum += inductance;
            }

        }
        return sum;
    }

    std::vector<T> calculateVoltages() {
        std::vector<T> _voltages;
        if (type == 'p') {
            // calculate the voltage across each inductor
            for (T inductance : inductances) {
                _voltages.push_back((I * inductance));
            }
        } else if (type == 's') {
            for (T inductance : inductances) {
                _voltages.push_back(VCC);
            }
        }
        return _voltages;
    }

    std::vector<T> calculateCurrents() {
        std::vector<T> _currents;
        if (type == 'p') {
            // calculate the current through each inductor
            for (T inductance : inductances) {
                _currents.push_back((VCC / inductance));
            }
        } else if (type == 's') {
            for (T inductance : inductances) {
                _currents.push_back(I);
            }
        }
        return _currents;
    }

    std::vector<T> calculatePowers() {
        std::vector<T> _powers;
        for (int i = 0; i < inductances.size(); i++) {
            _powers.push_back((pow(currents[i], 2)) * inductances[i]);
        }
        return _powers;
    }

    T calculateTotalPower() {
        T sum = 0.0;
        if (type == 'p') {
            for (T power : powers) {
                sum += power;
            }
        } else if (type == 's') {
            sum = pow(I, 2) * eL;
        }
        return sum;
    }

    T calculateTotalCurrent() {
        T sum = 0.0;
        if (type == 'p') {
            for (T current : currents) {
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
