//
// Created by Ryan.Zurrin001 on 12/16/2021.
//
#include <cmath>

#include "Angle.h"

//float rez::AngleLines2D( const Line2d& l1, const Line2d l2)
//{
//	auto mag_l1 = l1.direction().magnitude();
//	auto mag_l2 = l2.direction().magnitude();
//	auto dot = dot(l1.direction(), l2.direction());
//
//	auto theta = acos( fabs(dot) / (mag_l1 * mag_l2));
//	return RadianceToDegrees(theta);
//}

//float rez::AngleLines3D(const Line& l1, const Line& l2)
//{
//	auto mag_l1 = l1.direction().magnitude();
//	auto mag_l2 = l2.direction().magnitude();
//	auto dot = dot(l1.direction(), l2.direction());
//
//	auto theta = acos(fabs(dot) / (mag_l1 * mag_l2));
//	return RadianceToDegrees(theta);
//}

//float rez::AngleLinePlane(const Line& l, const Planef p)
//{
//	auto dot = dot(l.direction(), p.getNormal());
//	auto theta = acos(fabs(dot));
//	theta = RadianceToDegrees(theta);
//	return 90- theta;
//}

using namespace rez;

template<class T, size_t dimensions >
static float getAngle(rez::Vector<T, dimensions> v1, rez::Vector<T, dimensions> v2)
{
    auto dot = dotProduct(v1, v2);
    auto theta = acos(fabs(dot));
    return RadianceToDegrees(theta);
}

float rez::AngleLines2D(const Line2d& l1, const Line2d l2)
{
    return getAngle(l1.direction(), l2.direction());
}

float rez::AngleLines3D(const Line& l1, const Line& l2)
{
    return getAngle(l1.direction(), l2.direction());
}

float rez::AngleLinePlane(const Line& l, const Planef p)
{
    auto theta = getAngle(l.direction(), p.getNormal());
    return 90 - theta;
}

float rez::AnglePlanes(const Planef p1, const Planef p2)
{
    return getAngle(p1.getNormal(), p2.getNormal());
}
