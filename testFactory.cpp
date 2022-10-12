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

    ElectricCharge::fluxThroughHalfCylinder(6.8e3, .034, .15, true);




    //**************************************************************************
    //Stopping RunTimer and displaying the programs' execution time
    //_________________________________________________________________________
    timer.stop();
    timer.display();
    //_________________________________________________________________________
    return EXIT_SUCCESS;

}