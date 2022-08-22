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
    x_ = a[Y_] * b[Z_] - b[Y_] * a[Z_];
    y_ = -(b[Z_] * a[X_] - a[Z_] * b[X_]);
    z_ = a[X_] * b[Y_] - b[X_] * a[Y_];

    return {x_, y_, z_};
}

float rez::crossProduct2d(Vector2f a, Vector2f b)
{
    return 0.0f;
}

float rez::scalarTripleProduct(Vector3f a, Vector3f b, Vector3f c)
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
    return {vec[Y_], -vec[X_]};
}