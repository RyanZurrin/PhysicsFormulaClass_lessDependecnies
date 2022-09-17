#include "Physics_World.h"
#include "GeoUtils.h"
#include "RunTimer.h"
#include "BinarySearchTree.h"

int main(int argc, char* argv[])
{
    //starting time do not edit code between solid comment lines
    //_________________________________________________________________________
    RunTimer timer(SECONDS);
    timer.start();
    //_________________________________________________________________________
    //add test code between starred areas
    //**************************************************************************
    auto C = SHC.carbonDioxideGas.J_kgC;
    auto molarMass = (elements.C.atomic_weight + 2*elements.O.atomic_weight)
            /1000.0;
    auto cv = Thermodynamics::molarSpecificHeatCapacity_Cv(C, molarMass, true);
    Thermodynamics::changeInInternalEnergyAnyProcess(.25, cv, 100.0, true);









    //**************************************************************************
    //Stopping timer and displaying the programs' execution time
    //_________________________________________________________________________
    timer.stop();
    timer.display();
    //_________________________________________________________________________
    return EXIT_SUCCESS;

}
