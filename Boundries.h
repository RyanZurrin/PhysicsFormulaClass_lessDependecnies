//
// Created by Ryan.Zurrin001 on 12/15/2021.
//

#ifndef PHYSICSFORMULA_BOUNDRIES_H
#define PHYSICSFORMULA_BOUNDRIES_H
#include "Point.h"

namespace rez {

    struct AABB {
        float x_min;
        float x_max;
        float y_min;
        float y_max;

        bool isInside(Point2d& point) {
            if (x_min <= point[X_] && point[X_] <= x_max
                && y_min <= point[Y_] && point[Y_] <= y_max)
                return true;
            return false;
        }
    };
}
#endif //PHYSICSFORMULA_BOUNDRIES_H
