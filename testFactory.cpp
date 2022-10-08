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

    ElectricCharge::magnitudeOfElectricFieldAtByWire(1.0e3, 264e-3, 54.3e-2,
                                                     true);




    //**************************************************************************
    //Stopping RunTimer and displaying the programs' execution time
    //_________________________________________________________________________
    timer.stop();
    timer.display();
    //_________________________________________________________________________
    return EXIT_SUCCESS;

}