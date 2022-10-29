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

    Circuits::unknownCapacitor(3.0e-6, 1.0e-6, 2.0e-6, 100.0, 5.8e-3);

//    CapacitorNode c345({3.0, 5.0, 6.0}, 'p');
//    CapacitorNode c26({11.0, 3.0}, 's');
//    CapacitorNode c23456({c345.equivalentCapacitance, c26.equivalentCapacitance}, 'p');
//    CapacitorNode ctot({c23456.equivalentCapacitance, 3.0}, 's');
//    ctot.print();



    //**************************************************************************
    //Stopping RunTimer and displaying the programs' execution time
    //__________________________________________________________________________
    timer.stop();
    timer.display();
    //__________________________________________________________________________
    return EXIT_SUCCESS;

}