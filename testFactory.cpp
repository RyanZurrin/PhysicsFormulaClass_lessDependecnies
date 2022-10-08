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

    vector<ld> charges {8.0e-9, 6e-9};
    vector<pair<ld, ld>> positions {{16, 0}, {-9, 0}};
    pair<ld, ld> refQ {0, 12};
    ElectricCharge::electricFieldForce(-2.0e-6, .075, true);


//    Vector2D q2 {-9, 0};
//    Vector2D q1 {16, 0};
//    Vector2D A {0, 12};
//    Vector2D r1 =  q1 + A;
//    r1.displayAllData();
//    Vector2D r2 =  q2 + A;
//    r2.displayAllData();
//    Vector2D r = r1 + r2;
//    r.displayAllData();


    //**************************************************************************
    //Stopping RunTimer and displaying the programs' execution time
    //_________________________________________________________________________
    timer.stop();
    timer.display();
    //_________________________________________________________________________
    return EXIT_SUCCESS;

}