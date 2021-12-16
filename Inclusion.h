//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_INCLUSION_H
#define PHYSICSFORMULA_INCLUSION_H
#include "Point.h"

namespace rez {

    // Return true if point [d] is inside the boundary of triangle defined by the points a, b, c
    bool isInside(Point3d& a, Point3d& b, Point3d& c, Point3d& d);

}
#endif //PHYSICSFORMULA_INCLUSION_H
