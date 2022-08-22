//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#include "Line.h"

void rez::Line::setDirection(Vector3f& _dir)
{
    dir.assign(X_, _dir[X_]);
    dir.assign(Y_, _dir[Y_]);
    dir.assign(Z_, _dir[Z_]);
}

void rez::Line::setPoint(Point3d& _point)
{
    point_in_line.assign(X_, _point[X_]);
    point_in_line.assign(Y_, _point[Y_]);
    point_in_line.assign(Z_, _point[Z_]);
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