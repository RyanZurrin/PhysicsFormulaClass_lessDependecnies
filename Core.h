//
// Created by Ryan.Zurrin001 on 12/15/2021.
//

#ifndef PHYSICSFORMULA_CORE_H
#define PHYSICSFORMULA_CORE_H
#define _USE_MATH_DEFINES

#include <math.h>

namespace rez {
#define TOLERANCE 0.0000000001
#define TOLERANCEL 0.00001
#define TOLERANCELL 0.01
#define ZERO 0.0

#define CW  1
#define CCW 2

    typedef unsigned int uint;
    typedef const unsigned int cuint;


    enum RELATIVE_POSITION {
        LEFT, RIGHT, BEYOND, BEHIND, BETWEEN, ORIGIN, DESTINATION
    };


    enum INTERSECTION_OPS {
        CROSSES,
        POSITIVE,
        NEGATIVE,
        COINCIDENT
    };

    static bool isEqualD(double x, double y)
    {
        return fabs(x - y) < TOLERANCE;
    }

    static bool isEqualDL(double x, double y)
    {
        return fabs(x - y) < TOLERANCEL;
    }

    static bool isEqualDLL(double x, double y)
    {
        return fabs(x - y) < TOLERANCELL;
    }

    static bool _xor(bool x, bool y) {
        return x ^ y;
    }

    static float RadianceToDegrees(float radiance) {
        return radiance * 360 / (2 * M_PI);
    }
}
#endif //PHYSICSFORMULA_CORE_H
