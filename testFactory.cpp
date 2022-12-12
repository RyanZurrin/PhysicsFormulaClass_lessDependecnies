#include "Physics_World.h"
#include "RunTimer.h"


int main(int argc, char* argv[])
{
    //starting time do not edit code between solid comment lines
    //__________________________________________________________________________
    RunTimer timer(SECONDS);
    timer.start();
    //__________________________________________________________________________
    //add test code between starred areas
    //**************************************************************************

    ECH::workDoneByElectricForce(2.20e-6, -5.00e-6, {.170, 0}, {.255, .235});

    //**************************************************************************
    //Stopping RunTimer and displaying the programs' execution time
    //__________________________________________________________________________
    timer.stop();
    timer.display();
    //__________________________________________________________________________
    return EXIT_SUCCESS;
}
