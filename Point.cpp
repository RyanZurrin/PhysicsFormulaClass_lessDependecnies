//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#include "Point.h"

bool rez::sort2DLRTB(const Point2d& a, const Point2d& b)
{
    if ((a[X] < b[X])
        || (a[X] == b[X]) && (a[Y] < b[Y]))
    {
        return true;
    }
    return false;
}

bool rez::sort3DTBLR(const Point3d& a, const Point3d& b)
{
    if ((a[Y] > b[Y])
        || (a[Y] == b[Y]) && (a[X] < b[X]))
    {
        return true;
    }
    return false;
}

bool rez::sort2DTBLR(const Point2d& a, const Point2d& b)
{
    if ((a[Y] > b[Y])
        || (a[Y] == b[Y]) && (a[X] < b[X]))
    {
        return true;
    }
    return false;
}

bool rez::sort2DbyX(const Point2d& a, const Point2d& b)
{
    if (a[X] < b[X])
        return true;
    return false;
}

bool rez::sort2DbyY(const Point2d& a, const Point2d& b)
{
    if (a[Y] < b[Y])
        return true;
    return false;
}