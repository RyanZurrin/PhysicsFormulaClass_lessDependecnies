//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_SPHERE_H
#define PHYSICSFORMULA_SPHERE_H
/**
 * @class Sphere
 * @details class to represent a Sphere object
 * @author Ryan Zurrin
 * @dateBuilt  11/5/2021
 * @lastEdit 11/5/2021
 */
#include <iostream>
constexpr auto pi = 3.14159265358979323846;

static int sphereObjectCount = 0;
typedef long double ld;

class Sphere
{
    ld radius;
    ld volume;
    ld surfaceArea;
    static auto countIncrease() { sphereObjectCount += 1; }
    static auto countDecrease() { sphereObjectCount -= 1; }
    ld calculateRadius()const;
    ld calculateVolume()const;
    ld calculateSurfaceArea()const;
public:

    Sphere()
    {
        radius = 0.0;
        volume = 0.0;
        surfaceArea = 0.0;
        countIncrease();
    }

    explicit Sphere(ld radius)
    {
        this->radius = radius;
        this->volume = calculateVolume();
        this->surfaceArea = calculateSurfaceArea();
        countIncrease();
    }

    /**
     * @brief copy constructor
     */
    Sphere(const Sphere& s)
    {
        radius = s.radius;
        volume = s.volume;
        surfaceArea = s.surfaceArea;
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    Sphere(Sphere&& s) noexcept
    {
        radius = s.radius;
        volume = s.volume;
        surfaceArea = s.surfaceArea;
        countIncrease();
    }
    /**
     * @brief copy assignment operator
     */
    Sphere& operator=(Sphere&& s) noexcept
    {
        if (this != &s)
        {
            radius = s.radius;
            volume = s.volume;
            surfaceArea = s.surfaceArea;
            countIncrease();
        }
        return *this;
    }

    Sphere& operator=(Sphere other)
    {
        std::swap(radius, other.radius);
        std::swap(volume, other.volume);
        std::swap(surfaceArea, other.surfaceArea);
        return *this;
    }

    static void show_objectCount() {
        std::cout << "\n sphere object count: "
                  << sphereObjectCount << std::endl;
    }
    static int get_objectCount() { return sphereObjectCount; }


    ~Sphere() = default;

    auto setVolume(ld v);
    auto setRadius(ld r);
    auto setSurfaceArea(ld sa);

    [[nodiscard]] auto getRadius() const { return radius; }
    [[nodiscard]] auto getVolume() const { return volume; }
    [[nodiscard]] auto getSurfaceArea() const { return surfaceArea; }
    [[nodiscard]] auto getWeight(ld densityKgM) const;

    void printSphereInfo()const;
};

#endif //PHYSICSFORMULA_SPHERE_H
inline ld Sphere::calculateRadius() const
{
    return pow(3.0*(volume/(4.0*pi)), 1.0/3.0);
}

inline ld Sphere::calculateVolume() const
{
    return 4.0/3.0*(pi*pow(radius, 3));
}

inline ld Sphere::calculateSurfaceArea() const
{
    return 4.0*pi*(radius*radius);
}

inline auto Sphere::setVolume(ld v)
{
    volume = v;
    radius = calculateRadius();
    surfaceArea = calculateSurfaceArea();
}

inline auto Sphere::setRadius(ld r)
{
    radius = r;
    volume = calculateVolume();
    surfaceArea = calculateSurfaceArea();
}

inline auto Sphere::setSurfaceArea(ld sa)
{
    surfaceArea = sa;
    radius = sqrt(surfaceArea / 4.0);
    volume = calculateVolume();
}

inline auto Sphere::getWeight(ld densityKgM) const
{
    return densityKgM * volume;
}

inline void Sphere::printSphereInfo() const
{
    std::cout << "radius:       " << radius << std::endl;
    std::cout << "surface area: " << surfaceArea << std::endl;
    std::cout << "volume:       " << volume << std::endl;
}