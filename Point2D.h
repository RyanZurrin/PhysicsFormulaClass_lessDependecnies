//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_POINT2D_H
#define PHYSICSFORMULA_POINT2D_H
/**
 * @class Point2D
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @dateBuilt  11/22/21
 * @lastEdit 11/22/21
 */

#include "Vector2D.h"
#include <iostream>

static int pointObjectCount = 0;

template <typename NumericType>
class Point2D
{
    Vector2D points;
    static auto countIncrease() { pointObjectCount += 1; }
    static auto countDecrease() { pointObjectCount -= 1; }
public:
    /// <summary>
    /// Initializes a new instance of the <see cref="Point2D"/> class.
    /// </summary>
    Point2D() :points(0,0)
    { countIncrease(); }

    /// <summary>
    /// Initializes a new instance of the <see cref="Point2D"/> class.
    /// </summary>
    /// <param name="x_val">The x value.</param>
    /// <param name="y_val">The y value.</param>
    Point2D(NumericType x_val, NumericType y_val)
    {
        if (x_val == NAN || x_val == INFINITY || y_val == NAN || y_val == INFINITY)
        {
            throw std::invalid_argument("Coordinates must be finite");
        }
        points.set_x(x_val);
        points.set_y(y_val);
        countIncrease();
    }


    /// <summary>
    /// Initializes a new instance of the <see cref="Point2D"/> class.
    /// </summary>
    /// <param name="p">The p.</param>
    Point2D(const Point2D& p)
    {
        points.set_x(p.getX());
        points.set_y(p.getY());
        countIncrease();
    }


    /// <summary>
    /// Initializes a new instance of the <see cref="Point2D"/> class.
    /// </summary>
    /// <param name="p">The p.</param>
    Point2D(Point2D&& p) noexcept
    {
        points.set_x(p.getX());
        points.set_y(p.getY());
        countIncrease();
    }


    /// <summary>
    /// Operator=s the specified p.
    /// </summary>
    /// <param name="p">The p.</param>
    /// <returns></returns>
    Point2D& operator=(Point2D&& p) noexcept
    {
        if (this != &p)
        {
            points.set_x(p.getX());
            points.set_y(p.getY());
            countIncrease();
        }
        return *this;
    }

    /// <summary>
    /// Operator=s the specified other.
    /// </summary>
    /// <param name="other">The other.</param>
    /// <returns></returns>
    Point2D& operator=(Point2D other)
    {
        points.set_x(other.getX());
        points.set_y(other.getY());
        return *this;
    }

    /// <summary>
    /// Finalizes an instance of the <see cref="Point2D"/> class.
    /// </summary>
    ~Point2D() = default;

    static void show_objectCount()
    {
        std::cout << "\n template object count: "
                  << pointObjectCount << std::endl;
    }

    /// <summary>
    /// Gets the Point2D object count.
    /// </summary>
    /// <returns>number of Point2D objects instantiated</returns>
    static int get_objectCount() { return pointObjectCount; }

    /// <summary>
    /// Sets the x.
    /// </summary>
    /// <param name="xVar">The x variable.</param>
    /// <returns>void</returns>
    auto setX(NumericType xVar) { points.set_x(xVar); }

    /// <summary>
    /// Sets the y.
    /// </summary>
    /// <param name="yVar">The y variable.</param>
    /// <returns>void</returns>
    auto setY(NumericType yVar) { points.set_y(yVar); }

    /// <summary>
    /// returns the x instance.
    /// </summary>
    /// <returns>the x-coordinate</returns>
    [[nodiscard]] auto getX() const { return points.getX(); }

    /// <summary>
    /// returns the y instance.
    /// </summary>
    /// <returns>the y-coordinate</returns>
    [[nodiscard]] auto getY() const { return points.getY(); }

    /// <summary>
    /// the polar radius of this point.
    /// </summary>
    /// <returns>the polar radius of this point in polar coordinates: sqrt(x*x + y*y)</returns>
    auto r() { return points.square(); }

    /// <summary>
    /// the angle of this point in polar coordinates.
    /// </summary>
    /// <returns>the angle (in radians) of this point in polar coordinates (between –&pi; and &pi;)</returns>
    auto theta() { return atan2(points.getY(), points.getX()); }

    /// <summary>
    /// the angle between this point and that point.
    /// </summary>
    /// <param name="that">The that.</param>
    /// <returns>the angle in radians (between –&pi; and &pi;) between this point and that point (0 if equal)</returns>
    auto angleTo(Point2D<NumericType> that);

    /// <summary>
    /// twice the signed area of the triangle a-b-c.
    /// </summary>
    /// <param name="a">a first point.</param>
    /// <param name="b">b second point</param>
    /// <param name="c">c third point</param>
    /// <returns>twice the signed area of the triangle a-b-c</returns>
    static auto area2(Point2D<NumericType>a, Point2D<NumericType> b, Point2D<NumericType> c);

    /// <summary>
    /// Returns true if a→b→c is a counterclockwise turn.
    /// </summary>
    /// <param name="a">a first point</param>
    /// <param name="b">b second point</param>
    /// <param name="c">c third point</param>
    /// <returns>{ -1, 0, +1 } if a→b→c is a { clockwise, collinear; counterclockwise } turn.</returns>
    static int ccw(Point2D<NumericType> a, Point2D<NumericType> b, Point2D<NumericType> c);

    /// <summary>
    /// the Euclidean distance between this point and that point.
    /// </summary>
    /// <param name="that">that the other point</param>
    /// <returns>the Euclidean distance between this point and that point</returns>
    auto distanceTo(Point2D<NumericType> that);

    /// <summary>
    /// the square of the Euclidean distance between this point and that point.
    /// </summary>
    /// <param name="that">that the other point</param>
    /// <returns>the square of the Euclidean distance between this point and that point</returns>
    auto distanceSquaredTo(Point2D<NumericType> that);

    /// <summary>
    /// Compares two points by x-coordinate
    /// </summary>
    /// <param name="other">The other.</param>
    /// <returns></returns>
    auto compareByX(Point2D<NumericType> other);

    /// <summary>
    /// Compares two points by y-coordinate.
    /// </summary>
    /// <param name="other">The other.</param>
    /// <returns></returns>
    auto compareByY(Point2D<NumericType> other);

    /// <summary>
    /// Compares two points by polar radius.
    /// </summary>
    /// <param name="other">The other.</param>
    /// <returns></returns>
    auto compareByR(Point2D<NumericType> other);

    /// <summary>
    /// To the string.
    /// </summary>
    /// <returns></returns>
    auto display() { std::cout << "(" << this->getX() << ", " << this->getY() << ")"; }

    template<typename T>
    friend ostream& operator<<(ostream& os, const Point2D<NumericType>& p);

    template<typename T>
    friend istream& operator>>(istream& is, Point2D<NumericType> p);

};
#endif //PHYSICSFORMULA_POINT2D_H

template<typename NumericType>
inline auto Point2D<NumericType>::angleTo(Point2D<NumericType> that)
{
    auto dx = that.x_ - this->x_;
    auto dy = that.y_ - this->y_;
    return atan2(dy, dx);
}



template<typename NumericType>
inline auto Point2D<NumericType>::area2(Point2D<NumericType> a, Point2D<NumericType> b, Point2D<NumericType> c)
{
    return (b.points.getX() - a.points.getX()) *
           (c.points.getY() - a.points.getY()) -
           (b.points.getY() - a.points.getY()) *
           (c.points.getX() - a.points.getX());
}
template<typename NumericType>
inline int Point2D<NumericType>::ccw(Point2D<NumericType> a, Point2D<NumericType> b, Point2D<NumericType> c)
{
    double area2 = area2(a, b, c);
    if (area2 < 0)
        return -1;
    else if (area2 > 0)
        return +1;
    else
        return  0;
}
template<typename NumericType>
inline auto Point2D<NumericType>::distanceTo(Point2D<NumericType> that)
{
    double dx = this->points.getX() - that.points.getX();
    double dy = this->points.getY() - that.points.getY();
    return sqrt(dx * dx + dy * dy);
}

template<typename NumericType>
inline auto Point2D<NumericType>::distanceSquaredTo(Point2D<NumericType> that)
{
    auto dx = this->points.getX() - that.points.getX();
    auto dy = this->points.getY() - that.points.getY();
    return dx * dx + dy * dy;
}




template <typename NumericType>
inline auto Point2D<NumericType>::compareByX(Point2D<NumericType> other)
{
    if (this->points.getX() > other.points.getX())
        return 1;
    else if (this->x_ < other->x_)
        return -1;
    else
        return 0;
}

template <typename NumericType>
inline auto Point2D<NumericType>::compareByY(Point2D<NumericType> other)
{
    if (this->points.getY() > other.points.getY())
        return 1;
    else if (this->y_ < other->y_)
        return -1;
    else
        return 0;
}

template<typename NumericType>
inline auto Point2D<NumericType>::compareByR(Point2D other)
{
    const double delta = this->r() - other.r();
    if (delta < 0)
        return -1;
    else if (delta > 0)
        return 1;
    else
        return 0;
}

template<typename T>
inline ostream& operator<<(ostream& os, const Point2D<T>& p)
{
    os << "(" << p.x_ << ", " << p.y_ << ")" << std::endl;
    return os;
}

template<typename T>
inline istream& operator>>(istream& is, Point2D<T> p)
{
    std::cout << "\nEnter the x and y values of this point seperated by a space\n";;
    is >> p.x_ >> p.y_;
    return is;
}

