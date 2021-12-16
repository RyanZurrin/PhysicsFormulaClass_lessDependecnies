//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#include "Vector.h"

//template<typename coordinate_type, size_t dimensions>
//float jmk::dotProduct(Vector<coordinate_type, dimensions>& v1, Vector<coordinate_type, dimensions>& v2)
//{
//	if (v1.coords.size() != v2.coords.size())
//		return FLT_MIN;
//
//	float product = 0;
//	for (int i = 0; i < v1.coords.size(); i++)
//		product = product + v1[i] * v2[i];
//	return product;
//}

rez::Vector3f rez::crossProduct3d(Vector3f a, Vector3f b)
{
    float x_, y_, z_;
    x_ = a[Y] * b[Z] - b[Y] * a[Z];
    y_ = -(b[Z] * a[X] - a[Z] * b[X]);
    z_ = a[X] * b[Y] - b[X] * a[Y];

    return Vector3f(x_, y_, z_);
}

float rez::corssProduct2d(Vector2f a, Vector2f b)
{
    return 0.0f;
}

float rez::scalerTripleProduct(Vector3f a, Vector3f b, Vector3f c)
{
    Vector3f b_cross_c = crossProduct3d(b, c);
    float value = dotProduct(a, b_cross_c);
    return value;
}

bool rez::orthogonal(Vector3f a, Vector3f b)
{
    float value = dotProduct(a, b);
    return isEqualD(value, 0.0);
}

rez::Vector2f rez::prependicluar(Vector2f& vec)
{
    return Vector2f(vec[Y], -vec[X]);
}