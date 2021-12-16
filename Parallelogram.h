//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_PARALLELOGRAM_H
#define PHYSICSFORMULA_PARALLELOGRAM_H
/**
 * @class Parallelogram
 * @details class that represents a Parallelogram object
 * @author Ryan Zurrin
 * @dateBuilt  11/4/2021
 * @lastEdit 11/4/2021
 */
#define _USE_MATH_DEFINES
#include <cassert>
#include <iostream>
#include <cmath>

static int parallelogramObjectCount = 0;
typedef long double ld;

class Parallelogram
{
    ld base;
    ld side_a;
    ld height;
    ld perimeter;
    ld area;
    ld angle_A;
    ld angle_B;
    static auto countIncrease() { parallelogramObjectCount += 1; }
    static auto countDecrease() { parallelogramObjectCount -= 1; }
    ld calculateBase()const;
    ld calculateSideA()const;
    ld calculateHeight()const;
    ld calculatePerimeter()const;
    ld calculateArea()const;
    ld calculateAngleA()const;
    ld calculateAngleB()const;

public:

    Parallelogram()
    {
        base = 0.0;
        side_a = 0.0;
        height = 0.0;
        perimeter = 0.0;
        area = 0.0;
        angle_A = 0.0;
        angle_B = 0.0;
        countIncrease();
    }

    Parallelogram(ld base, ld side, ld height)
    {
        assert(height <= side);
        this->base = base;
        this->side_a = side;
        this->height = height;
        this->perimeter = calculatePerimeter();
        this->area = calculateArea();
        this->angle_A = calculateAngleA();
        this->angle_B = calculateAngleB();
        countIncrease();
    }

    /**
     * @brief copy constructor
     */
    Parallelogram(const Parallelogram& s)
    {
        base = s.base;
        side_a = s.side_a;
        height = s.height;
        perimeter = s.perimeter;
        area = s.area;
        angle_A = s.angle_A;
        angle_B = s.angle_B;
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    Parallelogram(Parallelogram&& s) noexcept
    {
        base = s.base;
        side_a = s.side_a;
        height = s.height;
        perimeter = s.perimeter;
        area = s.area;
        angle_A = s.angle_A;
        angle_B = s.angle_B;
        countIncrease();
    }
    /**
     * @brief copy assignment operator
     */
    Parallelogram& operator=(Parallelogram&& s) noexcept
    {
        if (this != &s)
        {
            base = s.base;
            side_a = s.side_a;
            height = s.height;
            perimeter = s.perimeter;
            area = s.area;
            angle_A = s.angle_A;
            angle_B = s.angle_B;
            countIncrease();
        }
        return *this;
    }

    Parallelogram& operator=(Parallelogram other)
    {
        std::swap(base, other.base);
        std::swap(side_a, other.side_a);
        std::swap(height, other.height);
        std::swap(perimeter, other.perimeter);
        std::swap(area, other.area);
        std::swap(angle_A, other.angle_A);
        std::swap(angle_B, other.angle_B);
        return *this;
    }

    static void show_objectCount() {
        std::cout << "\n parallelogram object count: "
                  << parallelogramObjectCount << std::endl;
    }
    static int get_objectCount() { return parallelogramObjectCount; }


    ~Parallelogram() = default;

    auto setBase(ld b);
    auto setSide(ld s);
    auto setHeight(ld h);

    [[nodiscard]] auto getBase() const { return base; }
    [[nodiscard]] auto getSide() const { return side_a; }
    [[nodiscard]] auto getHeight() const { return height; }
    [[nodiscard]] auto getPerimeter() const { return perimeter; }
    [[nodiscard]] auto getArea() const { return area; }
    [[nodiscard]] auto getAngleA() const { return angle_A; }
    [[nodiscard]] auto getAngleB() const { return angle_B; }

    void printParallelogramInfo()const;
};

#endif //PHYSICSFORMULA_PARALLELOGRAM_H

inline ld Parallelogram::calculateBase() const
{
    return ld();
}

inline ld Parallelogram::calculateSideA() const
{
    return ld();
}

inline ld Parallelogram::calculateHeight() const
{
    return ld();
}

inline ld Parallelogram::calculatePerimeter() const
{
    return 2.0*(base + side_a);
}

inline ld Parallelogram::calculateArea() const
{
    return base * height;
}

inline ld Parallelogram::calculateAngleA() const
{
    return asin(height/side_a) * 180.0 / M_PI;
}

inline ld Parallelogram::calculateAngleB() const
{
    return 180.0 - angle_A;
}

inline auto Parallelogram::setBase(ld b)
{
    base = b;
    area = calculateArea();
    perimeter = calculatePerimeter();
}

inline auto Parallelogram::setSide(ld s)
{
    assert(s > height);
    side_a = s;
    area = calculateArea();
    perimeter = calculatePerimeter();
}

inline auto Parallelogram::setHeight(ld h)
{
    assert(h <= side_a);
    height = h;
    area = calculateArea();
}

inline void Parallelogram::printParallelogramInfo() const
{
    std::cout << "base:      " << base << std::endl;
    std::cout << "side:      " << side_a << std::endl;
    std::cout << "height:    " << height << std::endl;
    std::cout << "perimeter: " << perimeter << std::endl;
    std::cout << "area:      " << area << std::endl;
    std::cout << "angle A:   " << angle_A << std::endl;
    std::cout << "angle B:   " << angle_B << std::endl;
}
