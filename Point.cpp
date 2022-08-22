//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#include "Point.h"

bool rez::sort2DLRTB(const Point2d& a, const Point2d& b)
{
    if ((a[X_] < b[X_])
        || (a[X_] == b[X_]) && (a[Y_] < b[Y_]))
    {
        return true;
    }
    return false;
}

bool rez::sort3DTBLR(const Point3d& a, const Point3d& b)
{
    if ((a[Y_] > b[Y_])
        || (a[Y_] == b[Y_]) && (a[X_] < b[X_]))
    {
        return true;
    }
    return false;
}

bool rez::sort2DTBLR(const Point2d& a, const Point2d& b)
{
    if ((a[Y_] > b[Y_])
        || (a[Y_] == b[Y_]) && (a[X_] < b[X_]))
    {
        return true;
    }
    return false;
}

bool rez::sort2DbyX(const Point2d& a, const Point2d& b)
{
    if (a[X_] < b[X_])
        return true;
    return false;
}

bool rez::sort2DbyY(const Point2d& a, const Point2d& b)
{
    if (a[Y_] < b[Y_])
        return true;
    return false;
}