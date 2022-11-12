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

    ResistorNode r1({ 180.0, 68.0 }, 7.0, 'p');
    r1.print();
    ResistorNode r2({ 240.0, r1.eR }, 7.0, 's');
    r2.print();



    //**************************************************************************
    //Stopping RunTimer and displaying the programs' execution time
    //__________________________________________________________________________
    timer.stop();
    timer.display();
    //__________________________________________________________________________
    return EXIT_SUCCESS;
}
