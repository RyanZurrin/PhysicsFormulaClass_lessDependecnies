//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_INTERSECTION_H
#define PHYSICSFORMULA_INTERSECTION_H
#pragma once
// Include functions to calculate intersection between different geometric promitives
#include "Point.h"
#include "Line.h"
#include "Plane.h"
#include "Segment.h"
#include "Polygon.h"
#include "Polyhedron.h"

namespace rez {

    bool intersect(rez::Line&, rez::Line&, rez::Point3d&);

    // Return true if two 2d lines are intersecting and store the intersection point in final argument
    // 1 - First line
    // 2 - Second line
    bool intersect(rez::Line2d&, rez::Line2d&, rez::Point2d&);

    bool intersect(rez::Line2d&, rez::Segment2d&);

    bool intersect(rez::Line2d&, rez::Segment2d&, rez::Point2d&);

    //bool intersect(rez::Segment2d&, rez::Segment2d&, rez::Point2d&);

    // Return true if 2d segments represeted by points are intersecting
    // 1 - start point of first segment
    // 2 - end point of first segmenet
    // 3 - start point of second segment
    // 4 - end point of second segment
    bool intersect(const rez::Point2d&, const rez::Point2d&, const rez::Point2d&, const rez::Point2d&);

    //// Return true if 2d segments represeted by points are intersecting. Store the intersecting point in final argument
    //// 1 - start point of first segment
    //// 2 - end point of first segmenet
    //// 3 - start point of second segment
    //// 4 - end point of second segment
    //// 5 - intersection point
    bool intersect(rez::Point2d&, rez::Point2d&, rez::Point2d&, rez::Point2d&, rez::Point2d&);

    // Return true if Plane and Line are intersecting. Intersection point will be stored point pass as 3rd argument
    bool intersect(rez::Planef&, rez::Line&, rez::Point3d&);

    // Return true if the given two planes are intersecting. Store the line of intersect in the line pass as 3rd argument
    bool intersect(rez::Planef&, rez::Planef&, rez::Line&);
}
#endif //PHYSICSFORMULA_INTERSECTION_H
