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
    //*************************************************************************
    Temperature::iceNeeded(.240, 50, 0, true);




    //*************************************************************************
    //Stopping timer and displaying the programs' execution time
    //_________________________________________________________________________
    timer.stop();
    timer.display();
    //_________________________________________________________________________
    return EXIT_SUCCESS;

}
