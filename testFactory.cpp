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
    double r1 = 2.0;
    double r2 = 5.0;
    double r3 = 1.0;
    double r4 = 7.0;
    double r5 = 3.0;
    double r6 = 3.0;
    double r7 = 3.0;

    ResistorNode R16({r1, r6}, 's');
    ResistorNode R162({R16.eR, r2}, 'p');
    ResistorNode R47({r4, r7}, 'p');
    ResistorNode R162345({R162.eR, r3, R47.eR, r5}, 's');
    R162345.print();



//    CapacitorNode c345({3.0, 5.0, 6.0}, 'p');
//    CapacitorNode c26({11.0, 3.0}, 's');
//    CapacitorNode c23456({c345.eC, c26.eC}, 'p');
//    CapacitorNode ctot({c23456.eC, 3.0}, 's');
//    ctot.print();
//    ResistorNode Rc({1.0, 3.0, Rd.eR}, 's');
//    ResistorNode Re({2.0, Rf.eR}, 's');
//    ResistorNode Requiv({Rc.eR, Re.eR}, 'p');
//    Requiv.print();

    //**************************************************************************
    //Stopping RunTimer and displaying the programs' execution time
    //__________________________________________________________________________
    timer.stop();
    timer.display();
    //__________________________________________________________________________
    return EXIT_SUCCESS;
}
