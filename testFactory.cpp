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
    MatrixND<double> m(3, 3);
    m = { { 3, 0, 1 }, { 4, 5, 6 }, { 7, 2, 9 } };

    cout << m << endl;

    cout << m.transpose() << endl;

    cout << m.determinant() << endl;

    cout << m.inverse() << endl;

    cout << m.trace() << endl;

    MatrixND<double> m2{ { 1, 2, 3 }, { 4, 5, 6}, { 7, 8, 9}};

    cout << m2 << endl;

    cout << m * m2 << endl;








    //*************************************************************************
    //Stopping timer and displaying the programs' execution time
    //_________________________________________________________________________
    timer.stop();
    timer.display();
    //_________________________________________________________________________
    return EXIT_SUCCESS;

}
