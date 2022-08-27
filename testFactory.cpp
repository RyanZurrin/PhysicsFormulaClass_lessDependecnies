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
    auto q = constants::PROTON_CHARGE;
    vector<ld> charges = { -q, q};
    vector<pair<ld, ld>> points = { {-1, 0}, {1, 0} };
    EMW::superpositionPrinciple(q, pair(0, 3), charges, points, true);








    //*************************************************************************
    //Stopping timer and displaying the programs' execution time
    //_________________________________________________________________________
    timer.stop();
    timer.display();
    //_________________________________________________________________________
    return EXIT_SUCCESS;

}
