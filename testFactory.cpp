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

    POINT_CHARGE_2D q1(1.0e-6, {0.0, 0.0, 0.0});
    POINT_CHARGE_2D q2(1.0e-6, {2.0e-3, 0.0, 0.0});
    Vector2D p1(1.0e-3, 0.0);
    vector<POINT_CHARGE_2D> charges = {q1, q2};






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