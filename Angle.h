//
// Created by Ryan.Zurrin001 on 12/15/2021.
//

#ifndef PHYSICSFORMULA_ANGLE_H
#define PHYSICSFORMULA_ANGLE_H
#include "Line.h"
#include "Plane.h"

namespace rez {
    float AngleLines2D(const Line2d& l1, const Line2d l2);

    float AngleLines3D(const Line& l1, const Line& l2);

    float AngleLinePlane(const Line& l, const Planef p);

    float AnglePlanes(const Planef p1, const Planef p2);
};
#endif //PHYSICSFORMULA_ANGLE_H
