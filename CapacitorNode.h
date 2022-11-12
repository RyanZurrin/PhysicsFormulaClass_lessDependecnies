//
// Created by ryanz on 11/11/2022.
//

#ifndef PHYSICSFORMULA_CAPACITORNODE_H
#define PHYSICSFORMULA_CAPACITORNODE_H
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>


class CapacitorNode {
public:
    double VCC{};
    std::vector<double> capacitances;
    std::vector<double> storedEnergies;
    std::vector<double> voltages;
    char type{}; // 'p' for parallel, 's' for series
    double eC{}; // equivalent capacitance
    double Q{}; // total charge

    CapacitorNode() {
        capacitances = {};
        storedEnergies = {};
        voltages = {};
        VCC = 0.0;
        type = 'p';
        eC = 0.0;
        Q = 0.0;
    }

    [[nodiscard]] double calculateTotalCharge() const {
        return VCC * eC;
    }

    CapacitorNode(std::vector<double> c, char t) {
        capacitances = std::move(c);
        type = t;
        VCC = 0.0;
        storedEnergies = {};
        voltages = {};
        eC = calculateEquivalentCapacitance();
        Q = calculateTotalCharge();
    }

    CapacitorNode(std::vector<double> c, double v, char t) {
        capacitances = std::move(c);
        type = t;
        VCC = v;
        eC = calculateEquivalentCapacitance();
        Q = calculateTotalCharge();
        voltages = calculateVoltages();
        storedEnergies = calculateStoredEnergy();
    }

    double calculateEquivalentCapacitance() {
        double sum = 0.0;
        if (type == 'p') {
            for (double capacitance : capacitances) {
                sum += capacitance;
            }
        } else if (type == 's') {
            for (double capacitance : capacitances) {
                sum += 1.0 / capacitance;
            }
            sum = 1.0 / sum;
        }
        return sum;
    }

    std::vector<double> calculateStoredEnergy() {
        std::vector<double> energies;
        if (type == 'p') {
            for (double capacitance : capacitances) {
                energies.push_back((capacitance * pow(VCC, 2)) / 2.0);
            }
        } else if (type == 's') {
            for (int i = 0; i < capacitances.size(); i++) {
                energies.push_back((capacitances[i] * pow(voltages[i], 2)) / 2.0);
            }
        }
        return energies;
    }

    std::vector<double> calculateVoltages() {
        std::vector<double> _voltages;
        if (type == 'p') {
            // in parallel node voltages are equal to the voltage of the
            // source across each capacitor
            for (double capacitance : capacitances) {
                _voltages.push_back(VCC);
            }
        } else if (type == 's') {
            for (double capacitance : capacitances) {
                _voltages.push_back((Q / capacitance));
            }
        }
        return _voltages;
    }

    void setVoltage(double v) {
        VCC = v;
        storedEnergies = calculateStoredEnergy();
        voltages = calculateVoltages();
        Q = calculateTotalCharge();
    }

    void setCapacitances(std::vector<double> c) {
        // assert that VCC is not 0
        assert(VCC != 0.0);
        capacitances = std::move(c);
        eC = calculateEquivalentCapacitance();
        storedEnergies = calculateStoredEnergy();
        voltages = calculateVoltages();
        Q = calculateTotalCharge();
    }

    void print() {
        std::cout << string(60, '*') << std::endl;
        std::cout << string(25, ' ') << "CapacitorNode" << std::endl;
        std::cout << "type: " << (type == 'p' ? "parallel" : "series")
        << std::endl;
        std::cout << "VCC: " << VCC << " V" << std::endl;
        std::cout << std::endl;
        std::cout << "Capacitances: " << std::endl;
       for (int i = 0; i < capacitances.size(); i++) {
            std::cout << "capacitor " << i + 1 << ": "
                 << capacitances[i] << " F, voltage: "
                 << voltages[i] << " V, stored energy: "
                 << storedEnergies[i] << " J" << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Equivalent Capacitance: " << eC << " F" << std::endl;
        std::cout << "Total Charge: " << Q << " C" << std::endl;
        std::cout << string(60, '*') << std::endl;
    }

    // destructor
    ~CapacitorNode() {
        std::cout << "CapacitorNode object destroyed" << std::endl;
    }
};

#endif //PHYSICSFORMULA_CAPACITORNODE_H
