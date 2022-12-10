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
    Vector2D v1(1,2);
    cout << v1 << endl;
    Vector3D v2(1,2,3);
    cout << v2 << endl;
    VectorND v3(1,2,3,4);
    cout << v3 << endl;

    Thermodynamics::energyUsedByRefrigerator(280.0, 300.0, 5.0, 3600.0, 3600.0);

    //**************************************************************************
    //Stopping RunTimer and displaying the programs' execution time
    //__________________________________________________________________________
    timer.stop();
    timer.display();
    //__________________________________________________________________________
    return EXIT_SUCCESS;
}
