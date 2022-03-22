//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_PYRAMID_H
#define PHYSICSFORMULA_PYRAMID_H
/**
 * @class Pyramid
 * @details class that represents a Pyramid object
 * @author Ryan Zurrin
 * @dateBuilt  11/4/2021
 * @lastEdit 11/4/2021
 */
#include <iostream>
#include <cmath>
static int pyramidObjectCount = 0;
typedef long double ld;

class Pyramid
{
    ld lenght;
    ld width;
    ld height;
    ld volume;
    ld surfaceArea;
    static auto countIncrease() { pyramidObjectCount += 1; }
    static auto countDecrease() { pyramidObjectCount -= 1; }
    ld calculateVolume()const;
    ld calculateSurfaceArea()const;
public:

    Pyramid()
    {
        lenght = 0.0;
        width = 0.0;
        height = 0.0;
        volume = 0.0;
        surfaceArea = 0.0;
        countIncrease();
    }

    Pyramid(ld length, ld width, ld height)
    {
        this->lenght = length;
        this->width = width;
        this->height = height;
        this->volume = calculateVolume();
        this->surfaceArea = calculateSurfaceArea();
        countIncrease();
    }

    /**
     * @brief copy constructor
     */
    Pyramid(const Pyramid& s)
    {
        lenght = s.lenght;
        width = s.width;
        height = s.height;
        volume = s.volume;
        surfaceArea = s.surfaceArea;
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    Pyramid(Pyramid&& s) noexcept
    {
        lenght = s.lenght;
        width = s.width;
        height = s.height;
        volume = s.volume;
        surfaceArea = s.surfaceArea;
        countIncrease();
    }
    /**
     * @brief copy assignment operator
     */
    Pyramid& operator=(Pyramid&& s) noexcept
    {
        if (this != &s)
        {
            lenght = s.lenght;
            width = s.width;
            height = s.height;
            volume = s.volume;
            surfaceArea = s.surfaceArea;
            countIncrease();
        }
        return *this;
    }

    Pyramid& operator=(Pyramid other)
    {
        std::swap(lenght, other.lenght);
        std::swap(width, other.width);
        std::swap(height, other.height);
        std::swap(volume, other.volume);
        std::swap(surfaceArea, other.surfaceArea);
        return *this;
    }

    static void show_objectCount() {
        std::cout << "\n rectangle object count: "
                  << pyramidObjectCount << std::endl;
    }
    static int get_objectCount() { return pyramidObjectCount; }


    ~Pyramid() = default;

    auto setWidth(ld w);
    auto setLength(ld l);
    auto setHeight(ld h);

    [[nodiscard]] auto getWidth() const { return width; }
    [[nodiscard]] auto getLength() const { return lenght; }
    [[nodiscard]] auto getHeight() const { return height; }
    [[nodiscard]] auto getVolume() const { return volume; }
    [[nodiscard]] auto getSurfaceArea() const { return surfaceArea; }
    [[nodiscard]] auto getWeight(ld densityKgM) const;

    void printPyramidInfo()const;
};

#endif //PHYSICSFORMULA_PYRAMID_H

inline ld Pyramid::calculateVolume() const
{
    return 1.0/3.0*(lenght*width)*height;
}

inline ld Pyramid::calculateSurfaceArea() const
{
    return lenght * width + lenght * (sqrt(pow((width / 2.0), 2) + height * height)) +
           width * (sqrt(pow((lenght / 2.0), 2) + height * height));
}

inline auto Pyramid::setWidth(ld w)
{
    width = w;
    volume = calculateVolume();
    surfaceArea = calculateSurfaceArea();
}

inline auto Pyramid::setLength(ld l)
{
    lenght = l;
    volume = calculateVolume();
    surfaceArea = calculateSurfaceArea();
}

inline auto Pyramid::setHeight(ld h)
{
    height = h;
    volume = calculateVolume();
    surfaceArea = calculateSurfaceArea();
}

inline auto Pyramid::getWeight(ld densityKgM) const
{
    return densityKgM * volume;
}

inline void Pyramid::printPyramidInfo() const
{
    std::cout << "length:		" << lenght << std::endl;
    std::cout << "width:		" << width << std::endl;
    std::cout << "height:		" << height << std::endl;
    std::cout << "volume:		" << volume << std::endl;
    std::cout << "surface area: " << surfaceArea << std::endl;
}


