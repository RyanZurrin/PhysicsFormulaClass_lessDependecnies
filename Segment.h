//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_SEGMENT_H
#define PHYSICSFORMULA_SEGMENT_H
#include "Point.h"

namespace rez {

    struct Segment {
        Point3d& p1;
        Point3d& p2;
    };

    struct Segment2d {
        Point2d p1 = DEFAULT_POINT_2D;
        Point2d p2 = DEFAULT_POINT_2D;
        Segment2d() {}

        //Segment2d(Point2d _p1, Point2d _p2) : p1(_p1), p2(_p2) {}
        Segment2d(Point2d& _p1, Point2d& _p2) : p1(_p1), p2(_p2) {}

        double get_x(double y) const
        {
            double x1 = p1[X_];
            double y1 = p1[Y_];
            double x2 = p2[X_];
            double y2 = p2[Y_];

            double y2_y1 = y2 - y1;

            return y * (x2 - x1) / y2_y1 + (y2 * x1 - y1 * x2) / y2_y1;
        }
    };
}
#endif //PHYSICSFORMULA_SEGMENT_H
