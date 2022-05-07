//
// Created by Ryan.Zurrin001 on 12/15/2021.
//

#ifndef PHYSICSFORMULA_ELASTICITY_H
#define PHYSICSFORMULA_ELASTICITY_H
// class for doing physics problems
// author: Ryan Zurrin
// last Modified: 10/11/2020
#include <iostream>
#include <vector>
#include <cmath>
#include "Constants.h"
using namespace std;

//static object counter for Elasticity class
static int elasticity_objectCount = 0;

static struct Elastic_Moduli  // all units are multiplied by(10^9 N/m^2)
{
    ///<young's modulus, Shear modulus, Bulk modulus>
    vector<double> aluminum{70e9, 25e9, 75e9};
    ///<young's modulus, Shear modulus, Bulk modulus>
    vector<double> bone_tension{
            16 * pow(10, 9), 80 * pow(10, 9), 8 * pow(10, 9)
    };
    ///<young's modulus, Shear modulus, Bulk modulus>
    vector<double> bone_compression{
            9 * pow(10, 9), 0 * pow(10, 9), 0 * pow(10, 9)
    };
    ///<young's modulus, Shear modulus, Bulk modulus>
    vector<double> brass{
            90 * pow(10, 9), 35 * pow(10, 9), 75 * pow(10, 9)
    };
    ///<young's modulus, Shear modulus, Bulk modulus>
    vector<double> brick{15 * pow(10, 9), 0 * pow(10, 9), 0 * pow(10, 9)};
    ///<young's modulus, Shear modulus, Bulk modulus>
    vector<double> concrete{
            20 * pow(10, 9), 0 * pow(10, 9), 0 * pow(10, 9)
    };
    ///<young's modulus, Shear modulus, Bulk modulus>
    vector<double> glass{
            70 * pow(10, 9), 20 * pow(10, 9), 30 * pow(10, 9)
    };
    ///<young's modulus, Shear modulus, Bulk modulus>
    vector<double> granite{
            45 * pow(10, 9), 20 * pow(10, 9), 45 * pow(10, 9)
    };
    ///<young's modulus, Shear modulus, Bulk modulus>
    vector<long double> hair_human{
            10 * pow(10, 9), 0 * pow(10, 9), 0 * pow(10, 9)
    };
    ///<young's modulus, Shear modulus, Bulk modulus>
    vector<long double> hardwood{
            25 * pow(10, 9), 10 * pow(10, 9), 0 * pow(10, 9)
    };
    ///<young's modulus, Shear modulus, Bulk modulus>
    vector<long double> cast_iron{
            100 * pow(10, 9), 40 * pow(10, 9), 90 * pow(10, 9)
    };
    ///<young's modulus, Shear modulus, Bulk modulus>
    vector<long double> lead{16 * pow(10, 9), 5 * pow(10, 9), 50 * pow(10, 9)};
    ///<young's modulus, Shear modulus, Bulk modulus>
    vector<long double> marble{
            60 * pow(10, 9), 20 * pow(10, 9), 70 * pow(10, 9)
    };
    ///<young's modulus, Shear modulus, Bulk modulus>
    vector<long double> nylon{5 * pow(10, 9), 0 * pow(10, 9), 0 * pow(10, 9)};
    ///<young's modulus, Shear modulus, Bulk modulus>
    vector<long double> polystyrene{
            3 * pow(10, 9), 0 * pow(10, 9), 0 * pow(10, 9)
    };
    ///<young's modulus, Shear modulus, Bulk modulus>
    vector<long double> silk{6 * pow(10, 9), 0 * pow(10, 9), 0 * pow(10, 9)};
    ///<young's modulus, Shear modulus, Bulk modulus>
    vector<long double> spider_thread{
            3 * pow(10, 9), 0 * pow(10, 9), 0 * pow(10, 9)
    };
    ///<young's modulus, Shear modulus, Bulk modulus>
    vector<long double> steel{
            210 * pow(10, 9), 80 * pow(10, 9), 130 * pow(10, 9)
    };
    ///<young's modulus, Shear modulus, Bulk modulus>
    vector<long double> tendon{1 * pow(10, 9), 0 * pow(10, 9), 0 * pow(10, 9)};
    ///<young's modulus, Shear modulus, Bulk modulus>
    vector<long double> acetone{
            0 * pow(10, 9), 0 * pow(10, 9), 0.7 * pow(10, 9)
    };
    ///<young's modulus, Shear modulus, Bulk modulus>
    vector<long double> ethanol{
            0 * pow(10, 9), 0 * pow(10, 9), 0.9 * pow(10, 9)
    };
    ///<young's modulus, Shear modulus, Bulk modulus>
    vector<long double> glycerin{
            0 * pow(10, 9), 0 * pow(10, 9), 4.5 * pow(10, 9)
    };
    ///<young's modulus, Shear modulus, Bulk modulus>
    vector<long double> mercury{
            0 * pow(10, 9), 0 * pow(10, 9), 25 * pow(10, 9)
    };
    ///<young's modulus, Shear modulus, Bulk modulus>
    vector<long double> water{0 * pow(10, 9), 0 * pow(10, 9), 2.2 * pow(10, 9)};
} moduli;


class Elasticity
{
public:
    static void countShow() { std::cout << "elasticity count: " << elasticity_objectCount << std::endl; }

    void setElasticityVal(long double val) { _elasticityVal = val; }

    Elasticity* _ptrElastic;

    /**
     * structure: Elastic_Moduli vector
     * components: <young's modulus, Shear modulus, Bulk modulus> Y, S, B
     * purpose:	store data on elastic moduli for using in physics calculations
     * returns: specified component value
     */


    // default constructor
    Elasticity()
    {
        _ptrElastic =  nullptr;
        _elasticityVal = 0.0;
        countIncrease();
        //countShow();
    }
    Elasticity(long double val)
    {
        _ptrElastic =  nullptr;
        _elasticityVal = 0.0;
        countIncrease();

    }

    // copy constructor
    Elasticity(const Elasticity& e)
    {
        _ptrElastic = e._ptrElastic;
        _elasticityVal = e._elasticityVal;
        countIncrease();
        //countShow();
    }

    // copy assignment operator
    Elasticity& operator=(const Elasticity& r)
    {
        if (this != &r)
        {
            _ptrElastic = r._ptrElastic;
            _elasticityVal = r._elasticityVal;
            countIncrease();
            //countShow();
        }
        return  *this;
    }


    /**
     * method: cross_sectional(const long double radius)
     * arguments: radius
     * purpose:	calculates the cross sectional, which is used in many elasticity problems
     * returns: long double, cross sectional
     */
    static long double cross_sectional_area(const long double radius)
    { return constants::PI * (radius * radius); }

    /**
    * Returns the calculated deformation of an object which is used in hooks law equation
    * @param appliedForce the force in newtons
    * @param modulus <young's modulus, Shear modulus, Bulk modulus> values can be accessed by .moduli.
    * @param crossSectionalArea
    * @param original	 *
    * @returns the deformation
    */
    static long double deformations(const long double appliedForce, const long double modulus, const long double diameter, const long double original)
    { return (1 / modulus) * (appliedForce / (constants::PI * (diameter * diameter)) * original); }

    /**
    * method: stress_usingY(const long double YoungsModulus, const long double strain)
    * arguments: 1)YoungsModulus 2)strain
    * purpose:	calculates the stress which is defined as the ratio of force to area
    * returns: long double, stress
    */
    static long double stress_usingY(const long double youngsModulus, const long double strain)
    { return youngsModulus * strain; }

    /**
    * method:  stress_usingF(const long double force, const long double area)
    * arguments: 1)force 2)area = PI*r^2
    * purpose:	calculates the stress which is defined as the ratio of force to area
    * returns: long double, stress
    */
    static long double stress_usingF(const long double force, const long double area)
    { return force / area;	}

    /**
    * method: strain(const long double change_in_length, const long double total_length)
    * arguments: 1)change_in_length 2)total_length
    * purpose:	calculates the strain which is defined as the ratio of the change in length to length
    * returns: long double, strain
    */
    static long double strain(const long double change_in_length, const long double total_length)
    { return change_in_length / total_length; }


    /// <summary>
    ///  Uses Hookes law to find the force applied
    /// </summary>
    /// <param name="k">The force constant.</param>
    /// <param name="x">The deformation from starting point.</param>
    /// <returns>force applied</returns>
    static long double hookes_law(const long double k, const long double x)
    { return k * x; }


    /**
    * method: deforming_force(const long double modulus, const long double crossSectionalArea, const long double originalLength, const long double amountDeformed)
    * arguments: 1)modulus 2)crossSectionalArea 3)originalLength 4)amountDeformed
    * purpose:	calculates the force required to bend or deform a something depending on the material
    * returns: long double, deforming force
    */
    static long double deforming_force(const long double modulus, const long double crossSectionalArea, const long double originalLength, const long double amountDeformed)
    { return ((modulus) * (crossSectionalArea) / (originalLength)) * amountDeformed; }

    /**
     * Returns the total displacement to the side of an object due to a sheering force.
     * @param length total length of the object
     * @param diameter of object
     * @param forceN in newtons
     * @param sheerModuli for the material being measured
     * @returns displacement of a material to side due to sheering force
     */
    static long double displacement_side_sheer_force(const long double length, const long double diameter, const long double forceN, const long double sheerModuli)
    {
        return (1 / sheerModuli) * (4.0 / (constants::PI * (diameter *
        diameter))) * forceN * length;
    }

    /**
     * @brief Returns the amount of compression an object undergoes, such as weight on a steel beam
     * @param length is the length of the object
     * @param crossSectionalArea is the area as if it was sliced in half
     * @param youngsModulus is the modulus used in this equation
     * @param force is the amount of force being applied
     * @returns the compression amount in meters
     */
    static long double compression(const long double length, const long double crossSectionalArea, const long double youngsModulus, const long double force)
    {
        return (force * length) / (youngsModulus * crossSectionalArea);
    }

    /**
     * @brief Returns the maximum force something will take before it fails
     * @param compressiveStrength is dependant on the material used
     * @param crossSectionalArea is the area of a cross section of the object
     * @returns the max force before failure will occur
     */
    static long double max_support_force(const long double compressiveStrength, const long double crossSectionalArea)
    {
        return compressiveStrength * crossSectionalArea;
    }

    ~Elasticity()
    {
        delete _ptrElastic;
        countDecrease();
        //countShow();
    }

private:

    static void countIncrease() { elasticity_objectCount += 1; }
    static void countDecrease() { elasticity_objectCount -= 1; }
    long double _elasticityVal;
};
#endif //PHYSICSFORMULA_ELASTICITY_H
