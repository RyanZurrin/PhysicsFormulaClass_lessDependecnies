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

    ResistorNode R1({2.0, 1.0}, 60.0, 'p');
    R1.print();
    ResistorNode R2({4.0, 1.0}, 10.0, 'p');
    R2.print();


    //**************************************************************************
    //Stopping RunTimer and displaying the programs' execution time
    //__________________________________________________________________________
    timer.stop();
    timer.display();
    //__________________________________________________________________________
    return EXIT_SUCCESS;
}
