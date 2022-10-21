#include "Physics_World.h"
#include "GeoUtils.h"
#include "RunTimer.h"
#include "BinarySearchTree.h"
#include "Constants.h"

int main(int argc, char* argv[])
{
    //starting time do not edit code between solid comment lines
    //__________________________________________________________________________
    RunTimer timer(SECONDS);
    timer.start();
    //__________________________________________________________________________
    //add test code between starred areas
    //**************************************************************************

    EP::distanceFromLineOfCharge(6.50e-12, .17, 1100.0);

    //**************************************************************************
    //Stopping RunTimer and displaying the programs' execution time
    //__________________________________________________________________________
    timer.stop();
    timer.display();
    //__________________________________________________________________________
    return EXIT_SUCCESS;

}