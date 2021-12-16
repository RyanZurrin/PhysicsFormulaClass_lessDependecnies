#include <stack>

#include "Physics_World.h"
#include "GeoUtils.h"
#include "RunTimer.h"
#include "BinarySearchTree.h"



int main(int argc, char* argv[])
{
    //starting time do not edit code between solid comment lines
    //_________________________________________________________________________
    RunTimer timer;
    timer.start();
    //_________________________________________________________________________
    //add test code between starred areas
    //*************************************************************************
    rez::Point2d A, B, C, D, intersection;
    A.assign(X, 7.48723741889);
    A.assign(Y, 3.49889397007);
    B.assign(X, 0.73216262482);
    B.assign(Y, 2.03039944963);
    rez::Line2d ln(A, B);
    rez::Segment2d seg1(A, B);
    C.assign(X, 1.36151741933);
    C.assign(Y, 3.96042081937);
    D.assign(X, 5.89287193955);
    D.assign(Y, 1.08636725791);
    rez::Segment2d seg0(C, D);
    rez::Point2d p1, p2, p_intersect;
    bool r = rez::intersect(ln, seg0, intersection); //should be (3.4671, 2.6249) is (0,0)
    std::cout << "intersection 1 is " << r << endl;
    std::cout << intersection << endl;
    p1.assign(X, 5);
    p1.assign(Y, 10);
    p2.assign(X, 11);
    p2.assign(Y, 8.4);
    rez::Vector2f v1, v2;
    v1.assign(X, 3);
    v1.assign(Y, -3);
    v2.assign(X, -5);
    v2.assign(Y, -3);
    rez::Line2d l1(p1, v1);
    rez::Line2d l2(p2, v2);
    std::stack<Point2D<int>> pnts;
    bool result = rez::intersect(l1, l2, p_intersect);
    std::cout << "intersection 2 is " << result << endl;
    std::cout << p_intersect << endl; // saying its (8.25, 6.75) but should be (3.98, 3.4)
    rez::Vector3f p3(1, 2, -2);
    rez::Vector3f p4(3, -2, 1);
    rez::Vector3f p5(5, 1, -4);
    rez::Planef plane(p3, p4, p5);
    cout << "dir vector" << plane.getD() << endl;
    std::cout << plane << endl;


    //*************************************************************************
    //Stopping timer and displaying the programs execution time
    //_________________________________________________________________________
    timer.stop();
    timer.displayRunTime("ms");
    //_________________________________________________________________________
    return EXIT_SUCCESS;

}
