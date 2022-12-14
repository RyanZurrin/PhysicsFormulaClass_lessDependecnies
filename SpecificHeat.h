//
// Created by ryanz on 12/13/2022.
//

#ifndef PHYSICSFORMULA_SPECIFICHEAT_H
#define PHYSICSFORMULA_SPECIFICHEAT_H
#include <iostream>
#include <cmath>

class SpecificHeat {
    long double mass; // m in kg
    long double temperature; // T in K
    long double specificHeat; // c in J/(kg*K)
    long double heat; // Q in J

public:
    SpecificHeat(): mass(0), temperature(0), specificHeat(0), heat(0) {}
    SpecificHeat(long double m, long double T, long double c): mass(m),
    temperature(T), specificHeat(c), heat(calculateHeat()) {}
    void setMass(long double m);
    void setTemperature(long double T);
    void setSpecificHeat(long double c);
    [[nodiscard]] long double getMass() const;
    [[nodiscard]] long double getTemperature() const;
    [[nodiscard]] long double getSpecificHeat() const;
    [[nodiscard]] long double getHeat() const;
    [[nodiscard]] long double calculateHeat() const;
    [[nodiscard]] long double calculateMass() const;
    [[nodiscard]] long double calculateTemperature() const;
    [[nodiscard]] long double calculateSpecificHeat() const;

    friend std::ostream& operator<<(std::ostream& os, const SpecificHeat& h);

};

void SpecificHeat::setMass(long double m) {
    SpecificHeat::mass = m;
    SpecificHeat::temperature = calculateTemperature();
    SpecificHeat::specificHeat = calculateSpecificHeat();
    SpecificHeat::heat = calculateHeat();
}

void SpecificHeat::setTemperature(long double T) {
    SpecificHeat::temperature = T;
    SpecificHeat::mass = calculateMass();
    SpecificHeat::specificHeat = calculateSpecificHeat();
    SpecificHeat::heat = calculateHeat();
}

void SpecificHeat::setSpecificHeat(long double c) {
    SpecificHeat::specificHeat = c;
    SpecificHeat::mass = calculateMass();
    SpecificHeat::temperature = calculateTemperature();
    SpecificHeat::heat = calculateHeat();
}

long double SpecificHeat::getMass() const {
    return SpecificHeat::mass;
}

long double SpecificHeat::getTemperature() const {
    return SpecificHeat::temperature;
}

long double SpecificHeat::getSpecificHeat() const {
    return SpecificHeat::specificHeat;
}

long double SpecificHeat::getHeat() const {
    return SpecificHeat::heat;
}

long double SpecificHeat::calculateHeat() const {
    return SpecificHeat::mass * SpecificHeat::specificHeat * SpecificHeat::temperature;
}

long double SpecificHeat::calculateMass() const {
    return SpecificHeat::heat / (SpecificHeat::specificHeat * SpecificHeat::temperature);
}

long double SpecificHeat::calculateTemperature() const {
    return SpecificHeat::heat / (SpecificHeat::specificHeat * SpecificHeat::mass);
}

long double SpecificHeat::calculateSpecificHeat() const {
    return SpecificHeat::heat / (SpecificHeat::mass * SpecificHeat::temperature);
}

std::ostream &operator<<(ostream &os, const SpecificHeat &h) {
    os << "Mass: " << h.mass << " kg" << std::endl;
    os << "Temperature: " << h.temperature << " K" << std::endl;
    os << "Specific Heat: " << h.specificHeat << " J/(kg*K)" << std::endl;
    os << "Heat: " << h.heat << " J" << std::endl;
    return os;
}

#endif //PHYSICSFORMULA_SPECIFICHEAT_H
