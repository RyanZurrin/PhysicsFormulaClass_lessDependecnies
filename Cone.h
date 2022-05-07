//
// Created by Ryan.Zurrin001 on 12/15/2021.
//

#ifndef PHYSICSFORMULA_CONE_H
#define PHYSICSFORMULA_CONE_H
/**
 * @class Cone
 * @details class to represent a Cone object
 * @author Ryan Zurrin
 * @dateBuilt  11/4/2021
 * @lastEdit 11/4/2021
 */
#include <iostream>
#include <cmath>
#include "Constants.h"

static int coneObjectCount = 0;
typedef long double ld;

class Cone
{
    ld height;
    ld radius;
    ld volume;
    ld surfaceArea;
    static auto countIncrease() { coneObjectCount += 1; }
    static auto countDecrease() { coneObjectCount -= 1; }
    ld calculateVolume()const;
    ld calculateSurfaceArea()const;
public:

    Cone()
    {
        height = 0.0;
        radius = 0.0;
        volume = 0.0;
        surfaceArea = 0.0;
        countIncrease();
    }

    Cone(ld height, ld radius)
    {
        this->height = height;
        this->radius = radius;
        this->volume = calculateVolume();
        this->surfaceArea = calculateSurfaceArea();
        countIncrease();
    }

    /**
     * @brief copy constructor
     */
    Cone(const Cone& s)
    {
        height = s.height;
        radius = s.radius;
        volume = s.volume;
        surfaceArea = s.surfaceArea;
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    Cone(Cone&& s) noexcept
    {
        height = s.height;
        radius = s.radius;
        volume = s.volume;
        surfaceArea = s.surfaceArea;
        countIncrease();
    }
    /**
     * @brief copy assignment operator
     */
    Cone& operator=(Cone&& s) noexcept
    {
        if (this != &s)
        {
            height = s.height;
            radius = s.radius;
            volume = s.volume;
            surfaceArea = s.surfaceArea;
            countIncrease();
        }
        return *this;
    }

    Cone& operator=(Cone other)
    {
        std::swap(height, other.height);
        std::swap(radius, other.radius);
        std::swap(volume, other.volume);
        std::swap(surfaceArea, other.surfaceArea);
        return *this;
    }

    static void show_objectCount() {
        std::cout << "\n cone object count: "
                  << coneObjectCount << std::endl;
    }
    static int get_objectCount() { return coneObjectCount; }


    ~Cone() = default;

    auto setHeight(ld h);
    auto setRadius(ld r);

    [[nodiscard]] auto getHeight() const { return height; }
    [[nodiscard]] auto getRadius() const { return radius; }
    [[nodiscard]] auto getVolume() const { return volume; }
    [[nodiscard]] auto getSurfaceArea() const { return surfaceArea; }
    [[nodiscard]] auto getWeight(ld densityKgM) const;

    void printConeInfo()const;
};

#endif //PHYSICSFORMULA_CONE_H
inline ld Cone::calculateVolume() const
{
    return (1.0/3.0)*constants::PI*(radius*radius)*height;
}

inline ld Cone::calculateSurfaceArea() const
{
    return constants::PI*radius*(sqrt((radius*radius) + (height*height)))+
    constants::PI*(radius*radius);
}

inline auto Cone::setHeight(ld h)
{
    height = h;
    volume = calculateVolume();
    surfaceArea = calculateSurfaceArea();
}

inline auto Cone::setRadius(ld r)
{
    radius = r;
    volume = calculateVolume();
    surfaceArea = calculateSurfaceArea();
}

inline auto Cone::getWeight(ld densityKgM) const
{
    return densityKgM * volume;
}

inline void Cone::printConeInfo() const
{
    std::cout << "height:		" << height << std::endl;
    std::cout << "radius:		" << radius << std::endl;
    std::cout << "volume:		" << volume << std::endl;
    std::cout << "surface area: " << surfaceArea << std::endl;
}
