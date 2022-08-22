//
// Created by Ryan.Zurrin001 on 12/16/2021.
//
#include "Core.h"
#include "Intersection.h"
#include "GeoUtils.h"

using namespace rez;

bool rez::intersect(rez::Line2d& l1, rez::Line2d& l2, rez::Point2d& pi) {
    Vector2f l1p = l1.point();
    Vector2f l2p = l2.point();
    Vector2f l1d = l1.direction();
    Vector2f l2d = l2.direction();

    float a, b, c, d, e, f;

    a = l1d[X_];
    b = -l2d[X_];
    c = l2p[X_] - l1p[X_];
    d = l1d[Y_];
    e = -l2d[Y_];
    f = l2p[Y_] - l1p[Y_];

    Vector2f diff = l2p - l1p;
    auto prep_l2d = prependicluar(l2d);
    float dot_d0_prepd1 = dotProduct(l1d, prep_l2d);

    if (!isEqualD(dot_d0_prepd1, ZERO))
    {
        float denominator = a * e - b * d;
        float t_numerator = c * e - b * f;
        float s_numerator = a * f - c * a;

        float t = t_numerator / denominator;

        float x = l1p[X_] + t * l1d[X_];
        float y = l1p[Y_] + t * l1d[Y_];

        if ((x - l1p[X_]) / l1d[X_] < 0) return false;
        if ((y - l1p[Y_]) / l1d[Y_] < 0) return false;

        if ((x - l2p[X_]) / l2d[X_] < 0) return false;
        if ((y - l2p[Y_]) / l2d[Y_] < 0) return false;

        pi.assign(X_, x);
        pi.assign(Y_, y);
        return true;
    }
    else
    {
        //Lines are parallel
        return false;
    }
}

bool rez::intersect(const rez::Point2d& a, const rez::Point2d& b, const rez::Point2d& c, const rez::Point2d& d) {

    // if one of the end points of a segment is in between other segment endpoints we consider it as intersection.
    if (rez::orientation2d(a, b, c) == rez::BETWEEN
        || rez::orientation2d(a, b, d) == rez::BETWEEN
        || rez::orientation2d(c, d, a) == rez::BETWEEN
        || rez::orientation2d(c, d, b) == rez::BETWEEN)
    {
        return true;
    }

    return rez::_xor(rez::left(a, b, c), rez::left(a, b, d)) && rez::_xor(rez::left(c, d, a), rez::left(c, d, b));
}

bool rez::intersect(rez::Point2d& a, rez::Point2d& b, rez::Point2d& c, rez::Point2d& d, rez::Point2d& interseciton)
{
    Vector2f AB = b - a;
    Vector2f CD = d - c;

    //Normal vector to CD
    Vector2f n(CD[Y_], -CD[X_]);

    //Denominator = n.(b-a)
    auto deno = dotProduct(n, AB);

    if (!isEqualD(deno, ZERO))
    {
        auto AC = c - a;
        auto nume = dotProduct(n, AC);
        auto t = nume / deno;

        auto x = a[X_] + t * AB[X_];
        auto y = a[Y_] + t * AB[Y_];

        interseciton.assign(X_, x);
        interseciton.assign(Y_, y);
        return true;
    }
    else
    {
        // Lines are parallel or colinear
        return false;
    }
}

bool rez::intersect(rez::Planef& plane, rez::Line& line, rez::Point3d& point) {

    auto n = plane.getNormal();
    auto D = plane.getD();
    auto d = line.direction();
    auto p = line.point();

    auto denominator = dotProduct(n, d);

    if (!isEqualD(denominator, ZERO)) {
        auto t = (-1 * dotProduct(n, p) + D) / denominator;
        point.assign(X_, p[X_] + t * d[X_]);
        point.assign(Y_, p[Y_] + t * d[Y_]);
        point.assign(Z_, p[Z_] + t * d[Z_]);
        return true;
    }
    else {
        return false;
    }
}

bool rez::intersect(rez::Planef& p1, rez::Planef& p2, rez::Line& l) {

    auto n1 = p1.getNormal();
    auto n2 = p2.getNormal();
    auto d1 = p1.getD();
    auto d2 = p2.getD();

    auto direction = crossProduct3d(n1, n2);
    direction.normalize();

    // Check if the planes are parallel.
    if (isEqualD(direction.magnitude(), ZERO))
        return false;

    auto n1n2 = dotProduct(n1, n2);
    auto n1n2_2 = n1n2 * n1n2;

    auto a = (d2 * n1n2 - d1) / (n1n2_2 - 1);
    auto b = (d1 * n1n2 - d2) / (n1n2_2 - 1);

    auto point = n1 * a + n2 * b;

    l.setPoint(point);
    l.setDirection(direction);

    return true;
}

bool rez::intersect(rez::Line2d& line, rez::Segment2d& seg) {

    // TODO : This can be done efficiently by checking the end points orientation
    // compared to the line.
    Vector2f dir = seg.p2 - seg.p1;
    Point2d point = seg.p1;
    rez::Line2d seg_line(point, dir);
    return intersect(line, seg_line, point);
}

bool rez::intersect(rez::Line2d& line, rez::Segment2d& seg, rez::Point2d& pi) {
    Vector2f dir = seg.p2 - seg.p1;
    Point2d point = seg.p1;
    rez::Line2d seg_line(point, dir);
    return intersect(line, seg_line, pi);
}
