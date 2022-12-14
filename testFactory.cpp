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

    ECH::diskRadiusAndCharge(544.0e3, 417.0e3, 1.27);
    Thermodynamics::gasPressure(1.0e5, 1.0e5, 1.0e5);
    Thermodynamics::massOfBlock(1.0e5, "copper");

    //**************************************************************************
    //Stopping RunTimer and displaying the programs' execution time
    //__________________________________________________________________________
    timer.stop();
    timer.display();
    //__________________________________________________________________________
    return EXIT_SUCCESS;
}
