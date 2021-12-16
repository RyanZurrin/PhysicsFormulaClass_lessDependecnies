//
// Created by Ryan.Zurrin001 on 12/15/2021.
//

#ifndef PHYSICSFORMULA_DISTANCE_H
#define PHYSICSFORMULA_DISTANCE_H
#pragma once
// Include functions to calculate distance between different geometric promitives
#include "Point.h"
#include "Line.h"
#include "Plane.h"

namespace rez {

    /// <summary>
    /// Returns the distance to the point C from line [AB]. Return value > 0
    /// Not the sign distance.</summary>
    /// <param name="A"> One end point of the segment</param>
    /// <param name="B"> Other end point of the segment</param>
    /// <param name="C"> Point we need to find the distance from the segment</param>
    /// <returns>void</returns>
    float distance(Point3d& A, Point3d& B, Point3d& C);

    float distance(Line& line, Point3d& C);

    float distance(Line2d& line, Point2d& C);

    float distance(Point3d& p1, Point3d& p2);

    float distance(Point2d& p1, Point2d& p2);

    float distance(Planef& p, Point3d& Q);
}
#endif //PHYSICSFORMULA_DISTANCE_H
