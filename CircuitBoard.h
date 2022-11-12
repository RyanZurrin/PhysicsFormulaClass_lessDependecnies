//
// Created by ryanz on 11/9/2022.
//

#ifndef PHYSICSFORMULA_CIRCUITBOARD_H
#define PHYSICSFORMULA_CIRCUITBOARD_H

#include <iostream>
#include <utility>
#include <vector>
namespace CB {
    // abstract base class Component to be used as a base class for all components
    class Component {
    public:
        // pure virtual function
        virtual void print() const = 0;

        char type{};
    };


    class Capacitor : public Component {
    public:
        // capacitance in Farads
        double capacitance{};
        // working voltage in Volts
        double voltage{};
        // tolerance in percent
        double tolerance{};
        // leakage current in Amps
        double leakageCurrent{};
        // working temperature in Celsius
        double temperature{};
        // the polarization of the capacitor
        char polarization{};

        // default constructor
        Capacitor() : capacitance(0.0), voltage(0.0), tolerance(0.0),
        leakageCurrent(0.0), temperature(0.0), polarization('p') {
            type = 'c';
        }
        // constructor with parameters
        explicit Capacitor(double c=0.0, double v=0.0, double t=0.0, double l=0.0,
                  double temp=0.0, char p='p')
        : capacitance(c), voltage(v), tolerance(t), leakageCurrent(l),
        temperature(temp), polarization(p) {
            type = 'c';
        }
        // copy constructor
        Capacitor(const Capacitor& c)
        : capacitance(c.capacitance), voltage(c.voltage), tolerance(c.tolerance),
        leakageCurrent(c.leakageCurrent), temperature(c.temperature),
        polarization(c.polarization) {
            type = 'c';
        }

        // print function
        void print() const override {
            std::cout << "Capacitance: " << capacitance << " Farads" << std::endl;
            std::cout << "Voltage: " << voltage << " Volts" << std::endl;
            std::cout << "Tolerance: " << tolerance << " percent" << std::endl;
            std::cout << "Leakage Current: " << leakageCurrent << " Amps" << std::endl;
            std::cout << "Temperature: " << temperature << " Celsius" << std::endl;
            std::cout << "Polarization: " << polarization << std::endl;
        }

        // destructor
        ~Capacitor() = default;
    };

    class CapacitorNode : public Component {
    public:
        std::vector<Capacitor> capacitances;
        char type; // 'p' for parallel, 's' for series
        double equivalentCapacitance;

        // default constructor
        CapacitorNode() : capacitances(), type('p'), equivalentCapacitance(0.0) {}
        // constructor with parameters
        CapacitorNode(std::vector<Capacitor> c, char t) {
            capacitances = std::move(c);
            type = t;
            equivalentCapacitance = calculateEquivalentCapacitance();
        }
        double calculateEquivalentCapacitance() {
            double sum = 0.0;
            if (type == 'p') {
                for (const Capacitor& c : capacitances) {
                    sum += c.capacitance;
                }
            } else if (type == 's') {
                for (const Capacitor& c : capacitances) {
                    sum += 1.0 / c.capacitance;
                }
                sum = 1.0 / sum;
            }
            return sum;
        }

        // print function to print each capacitor in the node and the equivalent capacitance
        void print() const override {
            std::cout << "CapacitorNode Node: " << std::endl;
            for (Capacitor c : capacitances) {
                c.print();
            }
            std::cout << "Equivalent Capacitance: " << equivalentCapacitance << " Farads" << std::endl;
        }
    };

    class Resistor : public Component {
    public:
        // resistance in Ohms
        double resistance{};
        // accuracy
        double accuracy{};
        // stability
        double stability{};
        // reliability
        double reliability{};
        // tolerance
        double tolerance{};
        // voltage coefficient
        double voltageCoefficient{};
        // noise
        double noise{};
        // temperature rating
        double temperatureRating{};
        // thermal resistance
        double thermalResistance{};

        // default constructor
        Resistor() : resistance(0.0), accuracy(0.0), stability(0.0), reliability(0.0),
        tolerance(0.0), voltageCoefficient(0.0), noise(0.0), temperatureRating(0.0),
        thermalResistance(0.0) {
            type = 'r';
        }
        // constructor with parameters
        explicit Resistor(double r=0.0, double a=0.0, double s=0.0, double re=0.0,
                  double t=0.0, double v=0.0, double n=0.0, double temp=0.0,
                  double th=0.0)
        : resistance(r), accuracy(a), stability(s), reliability(re), tolerance(t),
        voltageCoefficient(v), noise(n), temperatureRating(temp), thermalResistance(th) {
            type = 'r';
        }
        // copy constructor
        Resistor(const Resistor& r)
        : resistance(r.resistance), accuracy(r.accuracy), stability(r.stability),
        reliability(r.reliability), tolerance(r.tolerance), voltageCoefficient(r.voltageCoefficient),
        noise(r.noise), temperatureRating(r.temperatureRating), thermalResistance(r.thermalResistance) {
            type = 'r';
        }

        // print function
        void print() const override {
            std::cout << "Resistance: " << resistance << " Ohms" << std::endl;
            std::cout << "Accuracy: " << accuracy << std::endl;
            std::cout << "Stability: " << stability << std::endl;
            std::cout << "Reliability: " << reliability << std::endl;
            std::cout << "Tolerance: " << tolerance << std::endl;
            std::cout << "Voltage Coefficient: " << voltageCoefficient << std::endl;
            std::cout << "Noise: " << noise << std::endl;
            std::cout << "Temperature Rating: " << temperatureRating << std::endl;
            std::cout << "Thermal Resistance: " << thermalResistance << std::endl;
        }

        // destructor
        ~Resistor() = default;
    };

    class ResistorNode : public Component {
    public:
        std::vector<Resistor> resistors;
        char type; // 'p' for parallel, 's' for series
        double equivalentResistance;

        ResistorNode() : resistors(), type('p'), equivalentResistance(0.0) {}
        ResistorNode(std::vector<Resistor> r, char t) {
            resistors = r;
            type = t;
            equivalentResistance = calculateEquivalentResistance();
        }
        double calculateEquivalentResistance() {
            double sum = 0.0;
            if (type == 'p') {
                for (const Resistor& resistor : resistors) {
                    sum += 1.0 / resistor.resistance;
                }
                sum = 1.0 / sum;
            } else if (type == 's') {
                for (const Resistor& resistor : resistors) {
                    sum += resistor.resistance;
                }

            }
            return sum;
        }

        void print() const override {
            std::cout << "Resistor Node: " << std::endl;
            for (Resistor r : resistors) {
                r.print();
            }
            std::cout << "Equivalent Resistance: " << equivalentResistance << " Ohms" << std::endl;
        }
    };

    class Inductor : public Component {
    public:
        // inductance in Henrys
        double inductance{};
        // tolerance in percent
        double tolerance{};
        // working temperature in Celsius
        double temperature{};

        // default constructor
        Inductor() : inductance(0.0), tolerance(0.0), temperature(0.0) {
            type = 'i';
        }
        // constructor with parameters
        explicit Inductor(double i=0.0, double t=0.0, double temp=0.0)
        : inductance(i), tolerance(t), temperature(temp) {
            type = 'i';
        }
        // copy constructor
        Inductor(const Inductor& i)
        : inductance(i.inductance), tolerance(i.tolerance), temperature(i.temperature) {
            type = 'i';
        }

        // print function
        void print() const override {
            std::cout << "Inductance: " << inductance << " Henrys" << std::endl;
            std::cout << "Tolerance: " << tolerance << std::endl;
            std::cout << "Temperature: " << temperature << std::endl;
        }

        // destructor
        ~Inductor() = default;
    };

    class InductorNode : public Component {
    public:
        std::vector<Inductor> inductances;
        char type; // 'p' for parallel, 's' for series
        double equivalentInductance;

        InductorNode() : inductances(), type('p'), equivalentInductance(0.0) {}
        InductorNode(std::vector<Inductor> i, char t) {
            inductances = i;
            type = t;
            equivalentInductance = calculateEquivalentInductance();
        }
        double calculateEquivalentInductance() {
            double sum = 0.0;
            if (type == 'p') {
                for (const Inductor& inductor : inductances) {
                    sum += inductor.inductance;
                }
            } else if (type == 's') {
                for (const Inductor& inductor : inductances) {
                    sum += 1.0 / inductor.inductance;
                }
                sum = 1.0 / sum;
            }
            return sum;
        }

        void print() const override {
            std::cout << "Inductor Node: " << std::endl;
            for (Inductor i : inductances) {
                i.print();
            }
        }
    };

    class VoltageSource : public Component {
    public:
        // voltage in Volts
        double voltage{};
        // tolerance in percent
        double tolerance{};
        // working temperature in Celsius
        double temperature{};

        // default constructor
        VoltageSource() : voltage(0.0), tolerance(0.0), temperature(0.0) {
            type = 'v';
        }
        // constructor with parameters
        explicit VoltageSource(double v=0.0, double t=0.0, double temp=0.0)
        : voltage(v), tolerance(t), temperature(temp) {
            type = 'v';
        }
        // copy constructor
        VoltageSource(const VoltageSource& v)
        : voltage(v.voltage), tolerance(v.tolerance), temperature(v.temperature) {
            type = 'v';
        }

        // print function
        void print() const override {
            std::cout << "Voltage: " << voltage << " Volts" << std::endl;
            std::cout << "Tolerance: " << tolerance << std::endl;
            std::cout << "Temperature: " << temperature << std::endl;
        }
    };

    class CircuitNode {
    public:
        std::vector<Component> components;
        std::vector<CircuitNode> children;
        double voltage;
        double current;
        double resistance;
        double inductance;
        double capacitance;
        double impedance;
        double admittance;
        double power;
        double energy;

        CircuitNode() : components(), children(), voltage(0.0),
        current(0.0), resistance(0.0), inductance(0.0), capacitance(0.0),
        impedance(0.0), admittance(0.0), power(0.0), energy(0.0) {}

        CircuitNode(std::vector<Component> c, std::vector<CircuitNode> ch) {
            components = std::move(c);
            children = std::move(ch);
            voltage = calculateVoltage();
            current = calculateCurrent();
            resistance = calculateResistance();
            inductance = calculateInductance();
            capacitance = calculateCapacitance();
            impedance = calculateImpedance();
            admittance = calculateAdmittance();
            power = calculatePower();
            energy = calculateEnergy();
        }

//        void addComponent(Component c) {
//            components.push_back(c);
//        }


        double calculateVoltage() {
            double sum = 0.0;
            for (const Component& component : components) {
                if (component.type == 'v') {
                    sum += dynamic_cast<VoltageSource&>(const_cast<Component&>(component)).voltage;
                }
            }
            return sum;
        }

        double calculateCurrent() {
            double sum = 0.0;
            for (const Component& component : components) {
                if (component.type == 'r') {
                    sum += dynamic_cast<Resistor&>(const_cast<Component&>(component)).resistance;
                }
            }
            return voltage / sum;
        }

        double calculateResistance() {
            double sum = 0.0;
            for (const Component& component : components) {
                if (component.type == 'r') {
                    sum += dynamic_cast<Resistor&>(const_cast<Component&>(component)).resistance;
                }
            }
            return sum;
        }

        double calculateInductance() {
            double sum = 0.0;
            for (const Component& component : components) {
                if (component.type == 'i') {
                    sum += dynamic_cast<Inductor&>(const_cast<Component&>(component)).inductance;
                }
            }
            return sum;
        }

        double calculateCapacitance() {
            double sum = 0.0;
            for (const Component& component : components) {
                if (component.type == 'c') {
                    sum += dynamic_cast<Capacitor&>(const_cast<Component&>(component)).capacitance;
                }
            }
            return sum;
        }

        double calculateImpedance() {
            double sum = 0.0;
            for (const Component& component : components) {
                if (component.type == 'r') {
                    sum += dynamic_cast<Resistor&>(const_cast<Component&>(component)).resistance;
                }
            }
            return sum;
        }

        double calculateAdmittance() {
            double sum = 0.0;
            for (const Component& component : components) {
                if (component.type == 'c') {
                    sum += 1.0 / dynamic_cast<Capacitor&>(const_cast<Component&>(component)).capacitance;
                }
            }
            return sum;
        }

        double calculatePower() const {
            return voltage * current;
        }

        double calculateEnergy() const {
            return 0.5 * voltage * current;
        }



        void print() const {
            std::cout << "Circuit Node: " << std::endl;
            // print components which hve the print implemeted in the derived classes
            for (const Component& component : components) {
                component.print();
            }
            // print children
            for (const CircuitNode& child : children) {
                child.print();
            }
            std::cout << "Voltage: " << voltage << std::endl;
            std::cout << "Current: " << current << std::endl;
            std::cout << "Resistance: " << resistance << std::endl;
            std::cout << "Inductance: " << inductance << std::endl;
            std::cout << "Capacitance: " << capacitance << std::endl;
            std::cout << "Impedance: " << impedance << std::endl;
            std::cout << "Admittance: " << admittance << std::endl;
            std::cout << "Power: " << power << std::endl;
            std::cout << "Energy: " << energy << std::endl;

        }
//
//        // conect two components in series
//        void connectSeries(Component& c1, Component& c2) {
//            std::vector<Component> components;
//            components.push_back(c1);
//            components.push_back(c2);
//            CircuitNode node(components, std::vector<CircuitNode>());
//            children.push_back(node);
//        }
//
//        // connect two components in parallel
//        void connectParallel(Component& c1, Component& c2) {
//            // create a new circuit node
//            CircuitNode node;
//            // add the components to the node
//            node.components.push_back(*c1);
//            node.components.push_back(*c2);
//            // add the node to the children
//            children.push_back(node);
//        }

    };


    class CircuitBoard {
    public:
        std::vector<CircuitNode*> nodes;
        CircuitBoard() : nodes() {}
        explicit CircuitBoard(std::vector<CircuitNode*> n) : nodes(std::move(n)) {}

        // kirchoff's current law using nodal analysis
        void kirchoffCurrentLaw() {
            // for each node
            for (CircuitNode* node : nodes) {
                // for each component in the node
                for (Component& component : node->components) {
                    // if the component is a resistor
                    if (component.type == 'r') {
                        // add the resistance to the node's resistance
                        node->resistance += dynamic_cast<Resistor&>(component).resistance;
                    }
                    // if the component is a capacitor
                    if (component.type == 'c') {
                        // add the capacitance to the node's capacitance
                        node->capacitance += dynamic_cast<Capacitor&>(component).capacitance;
                    }
                    // if the component is an inductor
                    if (component.type == 'i') {
                        // add the inductance to the node's inductance
                        node->inductance += dynamic_cast<Inductor&>(component).inductance;
                    }
                    // if the component is a voltage source
                    if (component.type == 'v') {
                        // add the voltage to the node's voltage
                        node->voltage += dynamic_cast<VoltageSource&>(component).voltage;
                    }
                }
                // calculate the node's impedance
                node->impedance = node->resistance + (node->inductance * node->capacitance);
                // calculate the node's admittance
                node->admittance = 1.0 / node->impedance;
                // calculate the node's current
                node->current = node->voltage / node->impedance;
                // calculate the node's power
                node->power = node->voltage * node->current;
                // calculate the node's energy
                node->energy = node->power * 1.0 / 2.0;
            }
        }

//        void kirchoffCurrentLaw() {
//            // for each node
//            for (CircuitNode* node : nodes) {
//                // for each component in the node
//                for (Component* component : node->components) {
//                    // if the component is a resistor
//                    if (dynamic_cast<Resistor*>(component)) {
//                        // add the resistance to the node's resistance
//                        node->resistance += dynamic_cast<Resistor*>(component)->resistance;
//                    }
//                    // if the component is a capacitor
//                    if (dynamic_cast<CapacitorNode*>(component)) {
//                        // add the capacitance to the node's capacitance
//                        node->capacitance += dynamic_cast<CapacitorNode*>(component)->capacitance;
//                    }
//                    // if the component is an inductor
//                    if (dynamic_cast<Inductor*>(component)) {
//                        // add the inductance to the node's inductance
//                        node->inductance += dynamic_cast<Inductor*>(component)->inductance;
//                    }
//                }
//            }
//        }

        void print() {
            std::cout << "Circuit Board: " << std::endl;
            for (CircuitNode* n : nodes) {
                n->print();
            }
        }

    };


#endif //PHYSICSFORMULA_CIRCUITBOARD_H
}
//
//Circuits::voltageAcrossBattery(.020, 125.0, 12.0);
//CB::CapacitorNode c1(1.0, 1.0);
//CB::CapacitorNode c2(1.0, 1.0);
//CB::Resistor r1(1.0, 1.0);
//CB::Resistor r2(1.0, 1.0);
//CB::Inductor i1(1.0, 1.0);
//CB::Inductor i2(1.0, 1.0);
//CB::ResistorNode rn1({r1, r2}, 's');
//CB::InductorNode ln1({i1, i2}, 's');
//CB::VoltageSource vs12(12.0, 1.0);
//CB::CircuitNode cn1({c1, c2}, 's');
