//
// Created by Ryan.Zurrin001 on 12/15/2021.
//

#ifndef PHYSICSFORMULA_CUBE_H
#define PHYSICSFORMULA_CUBE_H
/**
 * @class Cube
 * @details Cube class that represents a cube object
 * @author Ryan Zurrin
 * @dateBuilt  11/4/2021
 * @lastEdit 11/4/2021
 */
#include <iostream>
#include <cmath>

static int cubeObjectCount = 0;
typedef long double ld;

class Cube
{
    ld side;
    ld surfaceArea;
    ld volume;
    static auto countIncrease() { cubeObjectCount += 1; }
    static auto countDecrease() { cubeObjectCount -= 1; }
    ld calculateSide()const;
    ld calculateSurfaceArea()const;
    ld calculateVolume()const;
public:

    Cube()
    {
        side = 0.0;
        surfaceArea = 0.0;
        volume = 0.0;
        countIncrease();
    }

    Cube(ld side)
    {
        this->side = side;
        this->surfaceArea = calculateSurfaceArea();
        this->volume = calculateVolume();
        countIncrease();
    }

    /**
     * @brief copy constructor
     */
    Cube(const Cube& s)
    {
        side = s.side;
        surfaceArea = s.surfaceArea;
        volume = s.volume;
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    Cube(Cube&& s) noexcept
    {
        side = s.side;
        surfaceArea = s.surfaceArea;
        volume = s.volume;
        countIncrease();
    }
    /**
     * @brief copy assignment operator
     */
    Cube& operator=(Cube&& s) noexcept
    {
        if (this != &s)
        {
            side = s.side;
            surfaceArea = s.surfaceArea;
            volume = s.volume;
            countIncrease();
        }
        return *this;
    }

    Cube& operator=(Cube other)
    {
        std::swap(side, other.side);
        std::swap(surfaceArea, other.surfaceArea);
        std::swap(volume, other.volume);
        return *this;
    }

    static void show_objectCount() {
        std::cout << "\n cube object count: "
                  << cubeObjectCount << std::endl;
    }
    static int get_objectCount() { return cubeObjectCount; }


    ~Cube() = default;

    auto setSide(ld s);
    auto setSurfaceArea(ld sa);
    auto setVolume(ld v);

    [[nodiscard]] auto getSide() const { return side; }
    [[nodiscard]] auto getSurfaceArea() const { return surfaceArea; }
    [[nodiscard]] auto getVolume() const { return volume; }
    [[nodiscard]] auto getWeight(ld densityKgM) const;

    void printCubeInfo()const;

};

#endif //PHYSICSFORMULA_CUBE_H
inline ld Cube::calculateSide() const
{
    return std::cbrt(volume);
}
inline ld Cube::calculateSurfaceArea() const
{
    return 6.0 * (side * side);
}

inline ld Cube::calculateVolume() const
{
    return (side*side*side);
}

inline auto Cube::setSide(ld s)
{
    side = s;
    volume = calculateVolume();
    surfaceArea = calculateSurfaceArea();
}

inline auto Cube::setSurfaceArea(ld sa)
{
    surfaceArea = sa;
    side = sqrt(surfaceArea / 6);
    volume = calculateVolume();
}

inline auto Cube::setVolume(ld v)
{
    volume = v;
    side = calculateSide();
    surfaceArea = calculateSurfaceArea();
}

inline auto Cube::getWeight(ld densityKgM) const
{
    return densityKgM * volume;
}

inline void Cube::printCubeInfo() const
{
    std::cout << "side:         " << side << std::endl;
    std::cout << "surface area: " << surfaceArea << std::endl;
    std::cout << "volume:       " << volume << std::endl;
}

