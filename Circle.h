//
// Created by Ryan.Zurrin001 on 12/15/2021.
//

#ifndef PHYSICSFORMULA_CIRCLE_H
#define PHYSICSFORMULA_CIRCLE_H
/**
 * @class Circle
 * @details class to represent a Circle object
 * @author Ryan Zurrin
 * @dateBuilt  11/5/2021
 * @lastEdit 11/5/2021
 */
#include <iostream>
#include <cmath>
constexpr auto pi_ = 3.14159265358979323846;

static int circleObjectCount = 0;
typedef long double ld;

class Circle
{
    ld radius;
    ld circumference;
    ld area;
    static auto countIncrease() { circleObjectCount += 1; }
    static auto countDecrease() { circleObjectCount -= 1; }
    ld calculateRadius()const;
    ld calculateCircumference()const;
    ld calculateArea()const;
public:

    Circle()
    {
        radius = 0.0;
        circumference = 0.0;
        area = 0.0;
        countIncrease();
    }

    Circle(ld radius)
    {
        this->radius = radius;
        this->circumference = calculateCircumference();
        this->area = calculateArea();
        countIncrease();
    }

    /**
     * @brief copy constructor
     */
    Circle(const Circle& s)
    {
        radius = s.radius;
        circumference = s.circumference;
        area = s.area;
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    Circle(Circle&& s) noexcept
    {
        radius = s.radius;
        circumference = s.circumference;
        area = s.area;
        countIncrease();
    }
    /**
     * @brief copy assignment operator
     */
    Circle& operator=(Circle&& s) noexcept
    {
        if (this != &s)
        {
            radius = s.radius;
            circumference = s.circumference;
            area = s.area;
            countIncrease();
        }
        return *this;
    }

    Circle& operator=(Circle other)
    {
        std::swap(radius, other.radius);
        std::swap(circumference, other.circumference);
        std::swap(area, other.area);
        return *this;
    }

    static void show_objectCount() {
        std::cout << "\n circle object count: "
                  << circleObjectCount << std::endl;
    }
    static int get_objectCount() { return circleObjectCount; }


    ~Circle() = default;

    auto setArea(ld a);
    auto setRadius(ld r);
    auto setCircumference(ld c);

    [[nodiscard]] auto getRadius() const { return radius; }
    [[nodiscard]] auto getCircumference() const { return circumference; }
    [[nodiscard]] auto getArea() const { return area; }

    void printCircleInfo()const;
};

#endif //PHYSICSFORMULA_CIRCLE_H
inline ld Circle::calculateRadius() const
{
    return circumference / (2.0 * pi_);
}

inline ld Circle::calculateCircumference() const
{
    return 2.0* pi_ * radius;
}

inline ld Circle::calculateArea() const
{
    return pi_ * (radius * radius);
}

inline auto Circle::setArea(ld a)
{
    area = a;
    radius = sqrt(area / pi_);
    circumference = calculateCircumference();
}

inline auto Circle::setRadius(ld r)
{
    radius = r;
    circumference = calculateCircumference();
    area = calculateArea();
}

inline auto Circle::setCircumference(ld c)
{
    circumference = c;
    radius = calculateRadius();
    area = calculateArea();
}

inline void Circle::printCircleInfo() const
{
    std::cout << "radius:        " << radius << std::endl;
    std::cout << "circumference: " << circumference << std::endl;
    std::cout << "area:	       " << area << std::endl;
}


