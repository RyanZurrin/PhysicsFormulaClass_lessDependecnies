//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_RECTANGLE_H
#define PHYSICSFORMULA_RECTANGLE_H
/**
 * @class Rectangle
 * @details rectangle class that represents a rectangle object
 * @author Ryan Zurrin
 * @dateBuilt  11/4/2021
 * @lastEdit 11/4/2021
 */
#include <iostream>


static int rectangleObjectCount = 0;
typedef long double ld;

class Rectangle
{
    ld lenght;
    ld width;
    ld diagnal;
    ld perimeter;
    ld area;
    static auto countIncrease() { rectangleObjectCount += 1; }
    static auto countDecrease() { rectangleObjectCount -= 1; }
    ld calculateLength()const;
    ld calculateWidth()const;
    ld calculateDiagnal()const;
    ld calculatePerimeter()const;
    ld calculateArea()const;
public:

    Rectangle()
    {
        lenght = 0.0;
        width = 0.0;
        diagnal = 0.0;
        perimeter = 0.0;
        area = 0.0;
        countIncrease();
    }

    Rectangle(ld length, ld width)
    {
        this->lenght = length;
        this->width = width;
        this->diagnal = calculateDiagnal();
        this->perimeter = calculatePerimeter();
        this->area = calculateArea();
        countIncrease();
    }

    /**
     * @brief copy constructor
     */
    Rectangle(const Rectangle& s)
    {
        lenght = s.lenght;
        width = s.width;
        diagnal = s.diagnal;
        perimeter = s.perimeter;
        area = s.area;
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    Rectangle(Rectangle&& s) noexcept
    {
        lenght = s.lenght;
        width = s.width;
        diagnal = s.diagnal;
        perimeter = s.perimeter;
        area = s.area;
        countIncrease();
    }
    /**
     * @brief copy assignment operator
     */
    Rectangle& operator=(Rectangle&& s) noexcept
    {
        if (this != &s)
        {
            lenght = s.lenght;
            width = s.width;
            diagnal = s.diagnal;
            perimeter = s.perimeter;
            area = s.area;
            countIncrease();
        }
        return *this;
    }

    Rectangle& operator=(Rectangle other)
    {
        std::swap(lenght, other.lenght);
        std::swap(width, other.width);
        std::swap(diagnal, other.diagnal);
        std::swap(perimeter, other.perimeter);
        std::swap(area, other.area);
        return *this;
    }

    static void show_objectCount() {
        std::cout << "\n rectangle object count: "
                  << rectangleObjectCount << std::endl;
    }
    static int get_objectCount() { return rectangleObjectCount; }


    ~Rectangle() = default;

    auto setWidth(ld w);
    auto setLength(ld l);
    auto setPerimeter(ld p);
    auto setArea(ld a);

    [[nodiscard]] auto getWidth() const { return width; }
    [[nodiscard]] auto getLength() const { return lenght; }
    [[nodiscard]] auto getDiagnol() const { return diagnal; }
    [[nodiscard]] auto getPerimeter() const { return perimeter; }
    [[nodiscard]] auto getArea() const { return area; }

    void printRectangleInfo()const;
};

#endif //PHYSICSFORMULA_RECTANGLE_H
inline ld Rectangle::calculateLength() const
{
    return (perimeter*sqrt((perimeter*perimeter) - 8.0*area))/2.0;
}

inline ld Rectangle::calculateWidth() const
{
    return area/lenght;
}

inline ld Rectangle::calculateDiagnal() const
{
    return sqrt((lenght*lenght) + (width*width));
}

inline ld Rectangle::calculatePerimeter() const
{
    return 2.0 * (lenght + width);
}

inline ld Rectangle::calculateArea() const
{
    return lenght * width;
}

inline auto Rectangle::setWidth(ld w)
{
    width = w;
    perimeter = calculatePerimeter();
    area = calculateArea();
    diagnal = calculateDiagnal();
}

inline auto Rectangle::setLength(ld l)
{
    lenght = l;
    perimeter = calculatePerimeter();
    area = calculateArea();
    diagnal = calculateDiagnal();
}

inline auto Rectangle::setPerimeter(ld p)
{
    perimeter = p;
    lenght = calculateLength();
    width = calculateWidth();
    diagnal = calculateDiagnal();
}

inline auto Rectangle::setArea(ld a)
{
    area = a;
    lenght = calculateLength();
    width = calculateWidth();
    diagnal = calculateDiagnal();
}

inline void Rectangle::printRectangleInfo() const
{
    std::cout << "length:    " << lenght << std::endl;
    std::cout << "width:     " << width << std::endl;
    std::cout << "diagonal:  " << diagnal << std::endl;
    std::cout << "perimeter: " << perimeter << std::endl;
    std::cout << "area:      " << area << std::endl;
}