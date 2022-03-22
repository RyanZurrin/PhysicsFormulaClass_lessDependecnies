//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_SQUARE_H
#define PHYSICSFORMULA_SQUARE_H
/**
 * @class Square
 * @details class to represent a square object
 * @author Ryan Zurrin
 * @dateBuilt  11/4/2021
 * @lastEdit 11/4/2021
 */
#include <iostream>

static int squareObjectCount = 0;
typedef long double ld;

class Square
{
    ld side;
    ld perimeter;
    ld area;
    static auto countIncrease() { squareObjectCount += 1; }
    static auto countDecrease() { squareObjectCount -= 1; }
    ld calculatePerimeter()const;
    ld calculateArea()const;
    ld calculateSide()const;
public:

    Square()
    {
        side = 0.0;
        perimeter = 0.0;
        area = 0.0;
        countIncrease();
    }

    Square(ld side)
    {
        this->side = side;
        this->perimeter = 4.0 * side;
        this->area = side * side;
        countIncrease();
    }

    /**
     * @brief copy constructor
     */
    Square(const Square& s)
    {
        side = s.side;
        perimeter = s.perimeter;
        area = s.area;
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    Square(Square&& s) noexcept
    {
        side = s.side;
        perimeter = s.perimeter;
        area = s.area;
        countIncrease();
    }
    /**
     * @brief copy assignment operator
     */
    Square& operator=(Square&& s) noexcept
    {
        if (this != &s)
        {
            side = s.side;
            perimeter = s.perimeter;
            area = s.area;
            countIncrease();
        }
        return *this;
    }

    Square& operator=(Square other)
    {
        std::swap(side, other.side);
        return *this;
    }

    static void show_objectCount() {
        std::cout << "\n square object count: "
                  << squareObjectCount << std::endl;
    }
    static int get_objectCount() { return squareObjectCount; }


    ~Square() = default;

    auto setSide(ld s);
    auto setPerimeter(ld p);
    auto setArea(ld a);

    [[nodiscard]] auto getSide() const { return side; }
    [[nodiscard]] auto getPerimeter() const { return perimeter; }
    [[nodiscard]] auto getArea() const { return area; }

    void printSquareInfo()const;
};

#endif //PHYSICSFORMULA_SQUARE_H

inline auto Square::setSide(ld s)
{
    side = s;
    perimeter = calculatePerimeter();
    area = calculateArea();
}

inline auto Square::setPerimeter(ld p)
{
    perimeter = p;
    side = calculateSide();
    area = calculateArea();
}

inline auto Square::setArea(ld a)
{
    area = a;
    side = sqrt(a);
    perimeter = calculatePerimeter();
}

inline void Square::printSquareInfo()const
{
    std::cout << "side:      " << side << std::endl;
    std::cout << "perimeter: " << perimeter << std::endl;
    std::cout << "area:      " << area << std::endl;
}

inline ld Square::calculatePerimeter()const
{
    return  4.0 * side;
}

inline ld Square::calculateArea()const
{
    return side * side;
}

inline ld Square::calculateSide()const
{
    return perimeter / 4.0;
}