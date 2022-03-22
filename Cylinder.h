//
// Created by Ryan.Zurrin001 on 12/15/2021.
//

#ifndef PHYSICSFORMULA_CYLINDER_H
#define PHYSICSFORMULA_CYLINDER_H
/**
 * @class Cylinder
 * @details class to represent a Cylinder object
 * @author Ryan Zurrin
 * @dateBuilt  11/4/2021
 * @lastEdit 11/4/2021
 */
#include <iostream>
#define PI_ 3.14159265358979323846

static int cylinderObjectCount = 0;
typedef long double ld;

class Cylinder
{
    ld height;
    ld radius;
    ld volume;
    ld surfaceArea;
    static auto countIncrease() { cylinderObjectCount += 1; }
    static auto countDecrease() { cylinderObjectCount -= 1; }
    ld calculateVolume()const;
    ld calculateSurfaceArea()const;
public:

    Cylinder()
    {
        height = 0.0;
        radius = 0.0;
        volume = 0.0;
        surfaceArea = 0.0;
        countIncrease();
    }

    Cylinder(ld height, ld radius)
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
    Cylinder(const Cylinder& s)
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
    Cylinder(Cylinder&& s) noexcept
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
    Cylinder& operator=(Cylinder&& s) noexcept
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

    Cylinder& operator=(Cylinder other)
    {
        std::swap(height, other.height);
        std::swap(radius, other.radius);
        std::swap(volume, other.volume);
        std::swap(surfaceArea, other.surfaceArea);
        return *this;
    }

    static void show_objectCount() {
        std::cout << "\n cylinder object count: "
                  << cylinderObjectCount << std::endl;
    }
    static int get_objectCount() { return cylinderObjectCount; }


    ~Cylinder() = default;

    auto setHeight(ld h);
    auto setRadius(ld r);

    [[nodiscard]] auto getHeight() const { return height; }
    [[nodiscard]] auto getRadius() const { return radius; }
    [[nodiscard]] auto getVolume() const { return volume; }
    [[nodiscard]] auto getSurfaceArea() const { return surfaceArea; }
    [[nodiscard]] auto getWeight(ld densityKgM) const;

    void printCylinderInfo()const;
};

#endif //PHYSICSFORMULA_CYLINDER_H
inline ld Cylinder::calculateVolume() const
{
    return PI_ * (radius*radius) * height;
}

inline ld Cylinder::calculateSurfaceArea() const
{
    return 2.0 * PI_ * (radius * radius) + 2.0 * PI_ * radius * height;
}

inline auto Cylinder::setHeight(ld h)
{
    height = h;
    volume = calculateVolume();
    surfaceArea = calculateSurfaceArea();
}

inline auto Cylinder::setRadius(ld r)
{
    radius = r;
    volume = calculateVolume();
    surfaceArea = calculateSurfaceArea();
}

inline auto Cylinder::getWeight(ld densityKgM) const
{
    return densityKgM * volume;
}

inline void Cylinder::printCylinderInfo() const
{
    std::cout << "height:		" << height << std::endl;
    std::cout << "radius:		" << radius << std::endl;
    std::cout << "volume:		" << volume << std::endl;
    std::cout << "surface area: " << surfaceArea << std::endl;
}