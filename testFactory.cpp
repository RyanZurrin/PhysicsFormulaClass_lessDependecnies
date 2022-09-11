#include "Physics_World.h"
#include "GeoUtils.h"
#include "RunTimer.h"
#include "BinarySearchTree.h"

#define _USE_MATH_DEFINES

int main(int argc, char* argv[])
{
    //starting time do not edit code between solid comment lines
    //_________________________________________________________________________
    RunTimer timer(SECONDS);
    timer.start();
    //_________________________________________________________________________
    //add test code between starred areas
    //**************************************************************************
   Thermodynamics::tempOfSystemAfterBeingInStateForTime(3600,
                                                        2880,
                                                        36.6,
                                                        .250,
                                                        2100,
                                                        true);












    //**************************************************************************
    //Stopping timer and displaying the programs' execution time
    //_________________________________________________________________________
    timer.stop();
    timer.display();
    //_________________________________________________________________________
    return EXIT_SUCCESS;

}
