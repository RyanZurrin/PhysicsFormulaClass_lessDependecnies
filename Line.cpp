//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#include "Line.h"

void rez::Line::setDirection(Vector3f& _dir)
{
    dir.assign(X, _dir[X]);
    dir.assign(Y, _dir[Y]);
    dir.assign(Z, _dir[Z]);
}

void rez::Line::setPoint(Point3d& _point)
{
    point_in_line.assign(X, _point[X]);
    point_in_line.assign(Y, _point[Y]);
    point_in_line.assign(Z, _point[Z]);
}

rez::Vector3f rez::Line::direction() const
{
    return dir;
}

rez::Point3d rez::Line::point() const
{
    return point_in_line;
}

rez::Vector2f rez::Line2d::direction() const
{
    return dir;
}

rez::Point2d rez::Line2d::point() const
{
    return point_in_line;
}

rez::Vector2f rez::Line2d::normal() const
{
    return normal_vec;
}