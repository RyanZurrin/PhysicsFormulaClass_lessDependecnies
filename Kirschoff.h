//
// Created by ryanz on 8/29/2022.
//

#ifndef PHYSICSFORMULA_KIRSCHOFF_H
#define PHYSICSFORMULA_KIRSCHOFF_H
#include <iostream>
#include <cmath>
#include <utility>
#include "MatrixND.h"
using namespace std;


class Kirschoff {
    MatrixND<long double> kirschoffMatrix;
    vector<long double> resistances;
    vector<long double> currents;
    vector<long double> voltages;
public:
    Kirschoff() {
        kirschoffMatrix = MatrixND<long double>(0, 0);
        resistances = vector<long double>();
        currents = vector<long double>();
        voltages = vector<long double>();
    }
    Kirschoff(MatrixND<long double> kirschoffMatrix_,
              vector<long double> resistances_,
              vector<long double> currents_,
              vector<long double> voltages_) {
        kirschoffMatrix = std::move(kirschoffMatrix_);
        resistances = std::move(resistances_);
        currents = std::move(currents_);
        voltages = std::move(voltages_);
    }
    Kirschoff(vector<long double> resistances_,
              vector<long double> currents_,
              vector<long double> voltages_) {
        resistances = std::move(resistances_);
        currents = std::move(currents_);
        voltages = std::move(voltages_);
        buildKirschoffMatrix(resistances, currents, voltages);
    }


    Kirschoff(const Kirschoff& kirschoff_) {
        kirschoffMatrix = kirschoff_.kirschoffMatrix;
        resistances = kirschoff_.resistances;
        currents = kirschoff_.currents;
        voltages = kirschoff_.voltages;
    }

    Kirschoff(Kirschoff&& kirschoff_) {
        kirschoffMatrix = std::move(kirschoff_.kirschoffMatrix);
        resistances = std::move(kirschoff_.resistances);
        currents = std::move(kirschoff_.currents);
        voltages = std::move(kirschoff_.voltages);
    }

    Kirschoff& operator=(const Kirschoff& kirschoff_) {
        if (this != &kirschoff_) {
            kirschoffMatrix = kirschoff_.kirschoffMatrix;
            resistances = kirschoff_.resistances;
            currents = kirschoff_.currents;
            voltages = kirschoff_.voltages;
        }
        return *this;
    }

    Kirschoff& operator=(Kirschoff&& kirschoff_) {
        if (this != &kirschoff_) {
            kirschoffMatrix = std::move(kirschoff_.kirschoffMatrix);
            resistances = std::move(kirschoff_.resistances);
            currents = std::move(kirschoff_.currents);
            voltages = std::move(kirschoff_.voltages);
        }
        return *this;
    }

    MatrixND<long double> getKirschoffMatrix() const {
        return kirschoffMatrix;
    }

    vector<long double> getResistances() const {
        return resistances;
    }

    vector<long double> getCurrents() const {
        return currents;
    }

    vector<long double> getVoltages() const {
        return voltages;
    }

    void setKirschoffMatrix(MatrixND<long double> kirschoffMatrix_) {
        kirschoffMatrix = std::move(kirschoffMatrix_);
    }

    void setResistances(vector<long double> resistances_) {
        resistances = std::move(resistances_);
    }

    void setCurrents(vector<long double> currents_) {
        currents = std::move(currents_);
    }

    void setVoltages(vector<long double> voltages_) {
        voltages = std::move(voltages_);
    }

    void showKirschoffMatrix() const {
        kirschoffMatrix.print();
    }

    void showResistances() const {
        for (int i = 0; i < resistances.size(); i++) {
            cout << resistances[i] << " ";
        }
        cout << endl;
    }

    void showCurrents() const {
        for (int i = 0; i < currents.size(); i++) {
            cout << currents[i] << " ";
        }
        cout << endl;
    }

    void showVoltages() const {
        for (int i = 0; i < voltages.size(); i++) {
            cout << voltages[i] << " ";
        }
        cout << endl;
    }

    void addResistance(long double resistance_) {
        resistances.push_back(resistance_);
    }

    void addCurrent(long double current_) {
        currents.push_back(current_);
    }

    void addVoltage(long double voltage_) {
        voltages.push_back(voltage_);
    }

    void buildKirschoffMatrix() {
        kirschoffMatrix = MatrixND<long double>(resistances.size(), resistances.size());
        for (int i = 0; i < resistances.size(); i++) {
            for (int j = 0; j < resistances.size(); j++) {
                if (i == j) {
                    kirschoffMatrix.set(i, j, resistances[i]);
                } else {
                    kirschoffMatrix.set(i, j, 0);
                }
            }
        }
    }

    void buildKirschoffMatrix(vector<long double> resistances_) {
        kirschoffMatrix = MatrixND<long double>(resistances_.size(), resistances_.size());
        for (int i = 0; i < resistances_.size(); i++) {
            for (int j = 0; j < resistances_.size(); j++) {
                if (i == j) {
                    kirschoffMatrix.set(i, j, resistances_[i]);
                } else {
                    kirschoffMatrix.set(i, j, 0);
                }
            }
        }
    }

    void buildKirschoffMatrix(vector<long double> resistances_, vector<long double> currents_) {
        kirschoffMatrix = MatrixND<long double>(resistances_.size(), resistances_.size());
        for (int i = 0; i < resistances_.size(); i++) {
            for (int j = 0; j < resistances_.size(); j++) {
                if (i == j) {
                    kirschoffMatrix.set(i, j, resistances_[i]);
                } else {
                    kirschoffMatrix.set(i, j, 0);
                }
            }
        }
        for (int i = 0; i < currents_.size(); i++) {
            kirschoffMatrix.set(i, i, -currents_[i]);
        }
    }

    void buildKirschoffMatrix(vector<long double> resistances_, vector<long double> currents_, vector<long double> voltages_) {
        kirschoffMatrix = MatrixND<long double>(resistances_.size(), resistances_.size());
        for (int i = 0; i < resistances_.size(); i++) {
            for (int j = 0; j < resistances_.size(); j++) {
                if (i == j) {
                    kirschoffMatrix.set(i, j, resistances_[i]);
                } else {
                    kirschoffMatrix.set(i, j, 0);
                }
            }
        }
        for (int i = 0; i < currents_.size(); i++) {
            kirschoffMatrix.set(i, i, -currents_[i]);
        }
        for (int i = 0; i < voltages_.size(); i++) {
            kirschoffMatrix.set(i, i, -voltages_[i]);
        }
    }

    long double findVoltage(int index_) {
        long double voltage = 0;
        for (int i = 0; i < kirschoffMatrix.getRows(); i++) {
            voltage += kirschoffMatrix.get(i, index_) * currents[i];
        }
        return voltage;
    }


};


#endif //PHYSICSFORMULA_KIRSCHOFF_H
