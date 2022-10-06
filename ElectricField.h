//
// Created by ryanz on 10/5/2022.
//

#ifndef PHYSICSFORMULA_ELECTRICFIELD_H
#define PHYSICSFORMULA_ELECTRICFIELD_H
#include <iostream>

//  Created by Ryan.Zurrin001 on 12/16/2021.

/**
 * @brief ElectricField class represents the electric field
 */
class ElectricField {
public:
    ElectricField();
    ElectricField(const ElectricField& t);
    ElectricField(ElectricField&& t) noexcept;
    ElectricField& operator=(const ElectricField& t);
    ElectricField& operator=(ElectricField&& t) noexcept;
    ~ElectricField();


    static double electricFieldStrength();
    static double electricFieldEnergy();
    static double electricFieldForce();
    static double electricFieldPower();
    static double electricFieldPotential();
    static double electricFieldWork();
    static double electricFieldVoltage();
    static double electricFieldResistance();
    static double electricFieldCapacitance();
    static double electricFieldInductance();
    static double electricFieldMagneticFlux();
    
};


#endif //PHYSICSFORMULA_ELECTRICFIELD_H
