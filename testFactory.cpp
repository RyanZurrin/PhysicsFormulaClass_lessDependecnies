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
    Physics_World world;
    Eigen::Vector3d pos(2, 4, 6);
    Eigen::Vector3d vel(1, 2, 3);
    // add the two vetors and display the result
    auto result = pos.dot(vel);
    std::cout << result << std::endl;










    //**************************************************************************
    //Stopping timer and displaying the programs' execution time
    //_________________________________________________________________________
    timer.stop();
    timer.display();
    //_________________________________________________________________________
    return EXIT_SUCCESS;

}