//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_GEOMETRICOPTICS_H
#define PHYSICSFORMULA_GEOMETRICOPTICS_H
#include <map>

#include "ElectroMagneticWaves.h"
#include <iostream>
using namespace std;

static int geometricOptics_objectCount = 0;

static struct RefractionIndexes
{
    //gases at 0 C, 1 atm
    const ld AIR = 1.000293;
    const ld CARBON_DIOXIDE = 1.00045;
    const ld HYDROGEN = 1.000139;
    const ld OXYGEN = 1.000271;
    //Liquids at 20 C
    const ld BENZENE = 1.501;
    const ld CARBON_DISULFIDE = 1.628;
    const ld CARBON_TETRACHLORIDE = 1.461;
    const ld ETHANOL = 1.361;
    const ld GLYCERINE = 1.473;
    const ld WATER_FRESH = 1.333;
    //Solids at 20 C
    const ld DIAMOND = 2.419;
    const ld FLUORITE = 1.434;
    const ld GLASS_CROWN = 1.52;
    const ld GLASS_FLINT = 1.66;
    const ld ICE = 1.309;
    const ld POLYSTYRENE = 1.49;
    const ld PLEXIGLAS = 1.51;
    const ld QUARTZ_CRYSTALLINE = 1.544;
    const ld QUARTZ_FUSED = 1.458;
    const ld SODIUM_CHLORIDE = 1.544;
    const ld ZIRCON = 1.923;

}refraction;

static std::multimap<std::string, ld> refractions {
        {"AIR", 1.0},
        {"AIR", 1.00},
        {"AIR", 1.000},
        {"AIR", 1.0003},
        {"AIR", 1.00029},
        {"AIR", 1.000293},
        {"CARBON_DIOXIDE~",1.0},
        {"CARBON_DIOXIDE",1.00},
        {"CARBON_DIOXIDE~",1.000},
        {"CARBON_DIOXIDE",1.0005},
        {"CARBON_DIOXIDE",1.00045},
        {"HYDROGEN",1.0},
        {"HYDROGEN",1.00},
        {"HYDROGEN",1.000},
        {"HYDROGEN",1.0001},
        {"HYDROGEN",1.00014},
        {"HYDROGEN",1.000139},
        {"OXYGEN",1.0},
        {"OXYGEN",1.00},
        {"OXYGEN",1.000},
        {"OXYGEN",1.000},
        {"OXYGEN",1.0003},
        {"OXYGEN",1.00027},
        {"BENZENE",1.5},
        {"BENZENE",1.50},
        {"BENZENE",1.501},
        {"BENZENE",1.502},
        {"CARBON_DISULFIDE",1.6},
        {"CARBON_DISULFIDE",1.63},
        {"CARBON_DISULFIDE",1.628},
        {"CARBON_DISULFIDE",1.6279},
        {"CARBON_TETRACHLORIDE",1.50},
        {"CARBON_TETRACHLORIDE",1.46},
        {"CARBON_TETRACHLORIDE",1.461},
        {"CARBON_TETRACHLORIDE",1.4614},
        {"ETHANOL",1.4},
        {"ETHANOL",1.36},
        {"ETHANOL",1.361},
        {"ETHANOL",1.3614},
        {"GLYCERINE",1.5},
        {"GLYCERINE",1.47},
        {"GLYCERINE",1.473},
        {"GLYCERINE",1.4734},
        {"WATER_FRESH",1.3},
        {"WATER_FRESH Red 660nm",1.331},
        {"WATER_FRESH Orange 610nm",1.332},
        {"WATER_FRESH Yellow 580nm",1.333},
        {"WATER_FRESH Green 550nm",1.335},
        {"WATER_FRESH",1.33},
        {"WATER_FRESH Blue 470nm",1.338},
        {"WATER_FRESH Violet 410nm",1.342},
        {"DIAMOND",2.4},
        {"DIAMOND Red 660nm",2.41},
        {"DIAMOND Orange 610nm",2.415},
        {"DIAMOND Yellow 580nm",2.417},
        {"DIAMOND",2.419},
        {"DIAMOND",2.42},
        {"DIAMOND Green 550nm",2.426},
        {"DIAMOND",2.3},
        {"DIAMOND",2.36},
        {"DIAMOND",2.38},
        {"DIAMOND",2.42},
        {"DIAMOND Blue 470nm",2.444},
        {"DIAMOND Violet 410nm",2.458},
        {"FLUORITE",1.4},
        {"FLUORITE",1.43},
        {"FLUORITE",1.434},
        {"FLUORITE",1.4345},
        {"GLASS_CROWN",1.5},
        {"GLASS_CROWN Red 660nm",1.512},
        {"GLASS_CROWN Orange 610nm",1.514},
        {"GLASS_CROWN Yellow 580nm",1.518},
        {"GLASS_CROWN  Green 550nm",1.519},
        {"GLASS_CROWN",1.52},
        {"GLASS_CROWN Blue 470nm",1.524},
        {"GLASS_CROWN",1.529},
        {"GLASS_CROWN Violet 410nm",1.530},
        {"GLASS_FLINT",1.7},
        {"GLASS_FLINT",1.66},
        {"GLASS_FLINT",1.664},
        {"ICE",1.3},
        {"ICE",1.31},
        {"ICE",1.309},
        {"ICE",1.3091},
        {"POLYSTYRENE",1.5},
        {"POLYSTYRENE",1.49},
        {"POLYSTYRENE",1.491},
        {"POLYSTYRENE",1.495},
        {"PLEXIGLAS",1.5},
        {"PLEXIGLAS",1.51},
        {"PLEXIGLAS",1.512},
        {"PLEXIGLAS",1.513},
        {"QUARTZ_CRYSTALLINE",1.5},
        {"QUARTZ_CRYSTALLINE",1.54},
        {"QUARTZ_CRYSTALLINE",1.544},
        {"QUARTZ_CRYSTALLINE",1.5443},
        {"QUARTZ_FUSED",1.5},
        {"QUARTZ_FUSED",1.45},
        {"QUARTZ_FUSED",1.458},
        {"QUARTZ_FUSED",1.457},
        {"QUARTZ_FUSED",1.459},
        {"QUARTZ_FUSED",1.456},
        {"SODIUM_CHLORIDE",1.5},
        {"SODIUM_CHLORIDE",1.54},
        {"SODIUM_CHLORIDE",1.544},
        {"SODIUM_CHLORIDE",1.543},
        {"ZIRCON",1.9},
        {"ZIRCON",1.92},
        {"ZIRCON",1.923},
        {"ZIRCON",1.924}
};
template<typename T>
static void printVec(const T& t) {
    std::copy(t.cbegin(), t.cend(), ostream_iterator<typename T::value_type>(std::cout, ", "));
}//end printVector

template<typename K, typename V>
static bool findMedium(std::vector<K> & vec, std::multimap<K, V> mapOfElemen, V value)
{
    bool bResult = false;
    auto it = mapOfElemen.begin();
    while(it != mapOfElemen.end())
    {
        if(it->second == value)
        {
            bResult = true;
            vec.push_back(it->first);
        }
        it++;
    }
    return bResult;
}//end searchMapByValue
template<typename K, typename V>
static void printMedium(std::multimap<K,V> m, const V val)
{
    std::cout << "looking for value: "<< val<<endl;
    std::vector<std::string> results;
    bool tests = findMedium(results, m, val);
    if(tests)
    {
        std::cout<<"Keys with value "<< val<< " are:"<<std::endl;
        printVec(results);

    }
    else
    {
        std::cout<<"No Key is found with the given value"<<std::endl;
    }

}//end printMapByValue

class GeometricOptics :
        public ElectromagneticWaves
{


public:
    GeometricOptics* _geoOpticPtr;

    GeometricOptics()
    {
        _geoOpticPtr = nullptr;
        geometricOpticsVar = 0.0;
        countIncrease();
    }

    /**
     * @brief copy constructor
     */
    GeometricOptics(const GeometricOptics& t)
    {
        _geoOpticPtr = t._geoOpticPtr;
        geometricOpticsVar = t.getGeometricOpticsVar();
        countIncrease();
    }
    /**
     * #brief move constructor
     */
    GeometricOptics(GeometricOptics&& t) noexcept
    {
        _geoOpticPtr = t._geoOpticPtr;
        geometricOpticsVar = t.getGeometricOpticsVar();
        countIncrease();
    }
    /**
     * @brief copy assignment operator
     */
    GeometricOptics& operator=(const GeometricOptics& t)
    {
        if (this != &t)
        {
            _geoOpticPtr = t._geoOpticPtr;
            geometricOpticsVar = t.getGeometricOpticsVar();
            countIncrease();
        }
        return *this;
    }

    static void show_objectCount() { std::cout
                << "\n geometric optics object count: "
                << geometricOptics_objectCount << std::endl; }
    static int get_objectCount() { return geometricOptics_objectCount; }


    ~GeometricOptics()
    {
        delete _geoOpticPtr;
    }

    void setGeometricOpticsVar(ld var) { geometricOpticsVar = var; }
    ld getGeometricOpticsVar() const { return geometricOpticsVar; }

    /// <summary>
    /// Calculates the index of refraction (n) where v is the observed speed of
    /// light in the material.
    /// </summary>
    /// <param name="v">The observed speed of light in a material.</param>
    /// <returns>the index of refraction (n) is unit less</returns>
    static ld indexOfRefraction(const ld v, int precision);

    /// <summary>
    /// Calculates the speeds of the light from a know refraction index of n
    /// </summary>
    /// <param name="n">The refraction index.</param>
    /// <returns>the speed of the light through a substance or material</returns>
    static ld speedOfLightFromRefractionIndex(const ld n);

    /// <summary>
    /// calculates the index of refraction medium 2.
    /// </summary>
    /// <param name="n1">The index of refraction from the incident ray.</param>
    /// <param name="incidentAng1">The incident ray angle.</param>
    /// <param name="angRefraction2">The angle of the refracted ray.</param>
    /// <returns>index of refraction for medium 2</returns>
    static ld indexOfRefractionMedium2(const ld n1, const ld incidentAng1, const ld angRefraction2, int precision);

    /// <summary>
    /// calculates the index of refraction medium 1.
    /// </summary>
    /// <param name="n2">The index of refraction of material 2.</param>
    /// <param name="incidentAng1">The incident angle .</param>
    /// <param name="angRefraction2">The angle of  refraction.</param>
    /// <param name="precision">The precision.</param>
    /// <returns>index of refraction for medium 1</returns>
    static ld indexOfRefractionMedium1(const ld n2, const ld incidentAng1, const ld angRefraction2, int precision);

    /// <summary>
    /// Calculates the angle of refraction.
    /// </summary>
    /// <param name="n1">The index of refraction from the incident ray.</param>
    /// <param name="n2">The index of refraction from refracted ray.</param>
    /// <param name="incidentAng1">The incident angle.</param>
    /// <returns>the angle of refraction</returns>
    static ld angleOfRefraction(const ld n1, const ld n2, const ld incidentAng1);

    /// <summary>
    /// Calculates the incident angle.
    /// </summary>
    /// <param name="n1">The index of refraction from the incident ray.</param>
    /// <param name="n2">The index of refraction from refracted ray.</param>
    /// <param name="angRefraction2">The angle of refraction.</param>
    /// <returns>the incident angle</returns>
    static ld incidentAngle(const ld n1, const ld n2, const ld angRefraction2);

    /// <summary>
    /// Calculates the critical angle for conditions {n1 > n2}
    /// </summary>
    /// <param name="n1">The n1.</param>
    /// <param name="n2">The n2.</param>
    /// <returns>the critical angle</returns>
    static ld criticalAngle(const ld n1, const ld n2);

    /// <summary>
    /// Waves the length from index refraction.
    /// </summary>
    /// <param name="waveLFromSourceRay">The wave l from source ray.</param>
    /// <param name="n">The n.</param>
    /// <returns></returns>
    static ld waveLength_fromIndexRefraction(const ld waveLFromSourceRay, const ld n);

    /// <summary>
    /// Suppose a person stands in front of a mirror their eyes are floorToEyes(m)
    /// above the floor, and the top of their head is eyesToTopHea m higher.
    /// Find the height above the floor of the top and bottom of the smallest mirror
    /// in which he can see both the top of his head and his feet. How is this
    /// distance related to the man’s height?
    /// </summary>
    /// <param name="floorToEyes">The floor to eyes.</param>
    /// <param name="eyesToTopHead">The eyes to top head.</param>
    /// <returns></returns>
    static std::map<std::string, ld> heightOfMirror(const ld floorToEyes, const ld eyesToTopHead);

    /// <summary>
    /// Components of some computers communicate with each other through optical
    /// fibers having an index of refraction n=1.55 but this can be generalized
    /// to any matter having a refraction index of n. What time in seconds
    /// is required for a signal to travel d m through that material?
    /// </summary>
    /// <param name="n">The refraction index.</param>
    /// <param name="d">The distance.</param>
    /// <returns>time for signal to travel</returns>
    static ld timeForSignalToTravel(const ld n, const ld d);
    /// <summary>
    /// Calculates the powers of the lens, which is the inverse of its focal
    /// length f. The units of a lens power is in diopters(D) which is 1/m or
    /// 1m^-1
    /// </summary>
    /// <param name="f">The focal length.</param>
    /// <returns>diopters of lens</returns>
    static ld powerOfLens(const ld f);

    /// <summary>
    /// Calculates the focal length of a lens having a power of P diopters
    /// </summary>
    /// <param name="P">The power of the lens.</param>
    /// <returns>the focal length</returns>
    static ld focalLength(const ld P);

    /// <summary>
    /// Focals the length.
    /// </summary>
    /// <param name="m">The magnification.</param>
    /// <param name="d_o">The object distance.</param>
    /// <returns>focal length</returns>
    static ld focalLength(const ld m, const ld d_o);

    /// <summary>
    /// Angles the and distance of bounced laser to sensor.
    /// </summary>
    /// <param name="disFromLas2Mirror">The dis from las2 mirror.</param>
    /// <param name="disSouthSensor">The dis south sensor.</param>
    /// <param name="angleOffBy">The angle off by.</param>
    /// <returns></returns>
    static std::map<std::string, ld> angleAndDistanceOfBouncedLaserToSensor(
            const ld disFromLas2Mirror, const ld disSouthSensor, const ld angleOffBy);

    /// <summary>
    /// A scuba diver training in a pool looks at his instructor. What angle
    /// does the ray from the instructor’s face make with the perpendicular to
    /// the water at the point where the ray enters? The angle between the ray
    /// in the water and the perpendicular to the water is angRefrac2∘.
    /// </summary>
    /// <param name="n1">The n1.</param>
    /// <param name="n2">The n2.</param>
    /// <param name="angRefrac2">The refraction angle2.</param>
    /// <returns></returns>
    static ld incidentRayToMaterial(const ld n1, const ld n2, const ld angRefrac2);

    /// <summary>
    /// Calculates the image distance with a known focal lenght of f and the
    /// objects distance of dObj
    /// </summary>
    /// <param name="dObj">The objects distance.</param>
    /// <param name="f">The focal distance.</param>
    /// <returns>the image distance</returns>
    static ld imageDistance_diRaytracing(const ld dObj, const ld f);

    /// <summary>
    /// An object h_o units high is held d_o units from a person’s cornea, and
    /// its reflected image is measured to be h_i units high.
    /// calculate Where the image is.
    /// </summary>
    /// <param name="d_o">The object distance.</param>
    /// <param name="h_i">The image height.</param>
    /// <param name="h_o">The object height.</param>
    /// <returns>image distance, or position of image</returns>
    static auto imageDistance_hihodo(const ld d_o, const ld h_i, const ld h_o);

    /// <summary>
    /// Calculates the Magnification.
    /// </summary>
    /// <param name="di">The distance of image.</param>
    /// <param name="dObj">The distance of object.</param>
    /// <returns></returns>
    static ld magnification(const ld di, const ld dObj);

    /// <summary>
    ///  Calculates the index of refraction of a substance that has a critical
    ///  angle of cA° when submerged in a substance, which has an index of
    ///  refraction of n2?
    /// </summary>
    /// <param name="cA">The known critical angle.</param>
    /// <param name="n2">The index known index of refraction.</param>
    /// <returns>the unknown index of refraction of substance</returns>
    static ld indexOfRefractionFromCriticalAngle(const ld cA, const ld n2);

    /// <summary>
    /// If a converging lens forms a real, inverted image d_i units to the right
    /// of the lens when the object is placed d_o units to the left of a lens,
    /// determine the focal length of the lens.
    /// </summary>
    /// <param name="d_i">The distance image makes.</param>
    /// <param name="d_o">The distance object is placed.</param>
    /// <returns>the focal length</returns>
    static ld focalLength_ConvergingLens_dido(const ld d_i, const ld d_o);

    /// <summary>
    /// Calculates the focal length from the radius of curvature
    /// </summary>
    /// <param name="R">The r.</param>
    /// <returns></returns>
    static ld focalLength_R(const ld R);

    /// <summary>
    /// Objects the distance.
    /// </summary>
    /// <param name="f">The f.</param>
    /// <param name="d_i">The d i.</param>
    /// <returns></returns>
    static ld objectDistance(const ld f, const ld d_i);

    /// <summary>
    /// Calculates the radius of curvature.
    /// </summary>
    /// <param name="f">The focal length.</param>
    /// <returns></returns>
    static ld radiusOfCurvature(const ld f);

    /// <summary>
    /// Calculate the intensity of IR radiation in W/m2 from a space heater
    /// projected by a concave mirror on a person d_i units away. Assume that
    /// the heating element radiates P Watts and has an area of A units^2, and
    /// that half of the radiated power is reflected and focused by the mirror
    /// </summary>
    /// <param name="d_i">The image distance, how far a person is standing.</param>
    /// <param name="d_o">The object distance.</param>
    /// <param name="P">The power.</param>
    /// <param name="A">the area of mirror.</param>
    /// <returns> Intensity (W/m^2)</returns>
    static ld intensityOfIR_radiation(const ld d_i, const ld d_o, const ld P, const ld A);



private:
    ld geometricOpticsVar;
    static void countIncrease() { geometricOptics_objectCount += 1; }
    static void countDecrease() { geometricOptics_objectCount -= 1; }

};

#endif //PHYSICSFORMULA_GEOMETRICOPTICS_H
//=============================================================================
//in-line class Implementation

inline ld GeometricOptics::indexOfRefraction(const ld v, int precision = 3)
{
    if (precision == 1)
    {
        ld scale = 0.1;
        ld a = _C_ / v;
        return floor(a/scale+.5)* scale;
    }
    if (precision == 2)
    {
        ld scale = 0.01;
        ld a = _C_ / v;
        return floor(a/scale+.5)* scale;
    }
    if (precision == 3)
    {
        ld scale = 0.001;
        ld a = _C_ / v;
        return floor(a/scale+.5)* scale;
    }
    if (precision == 4)
    {
        ld scale = 0.0001;
        ld a = _C_ / v;
        return floor(a/scale+.5)* scale;
    }
    else
        return _C_ / v;;
}

inline ld GeometricOptics::speedOfLightFromRefractionIndex(const ld n)
{
    return _C_ / n;
}

inline ld GeometricOptics::indexOfRefractionMedium2(const ld n1, const ld incidentAng1, const ld angRefraction2, int precision = 3)
{
    if (precision == 1)
    {
        ld val = n1 * (sin(incidentAng1 * RADIAN) / sin(angRefraction2 * RADIAN));
        ld scale = .1;
        ld v = floor(val / scale + .5) * scale;
        return v;
    }
    if (precision == 2)
    {
        ld val = n1 * (sin(incidentAng1 * RADIAN) / sin(angRefraction2 * RADIAN));
        ld scale = .01;
        return floor(val/scale+.5)*scale;
    }
    if (precision == 3)
    {
        ld val = n1 * (sin(incidentAng1 * RADIAN) / sin(angRefraction2 * RADIAN));
        ld scale = .001;
        return floor(val/scale+.5)*scale;
    }
    if (precision == 4)
    {
        ld val = n1 * (sin(incidentAng1 * RADIAN) / sin(angRefraction2 * RADIAN));
        ld scale = .0001;
        return floor(val / scale + .5) * scale;
    }
    else
        return n1 * (sin(incidentAng1 * RADIAN) / sin(angRefraction2 * RADIAN));

}

inline ld GeometricOptics::indexOfRefractionMedium1(const ld n2, const ld incidentAng1, const ld angRefraction2, int precision)
{
    if (precision == 1)
    {
        ld val = n2 * (sin(angRefraction2 * RADIAN) / sin(incidentAng1 * RADIAN));
        ld scale = .1;
        ld v = floor(val / scale + .5) * scale;
        return v;
    }
    if (precision == 2)
    {
        ld val = n2 * (sin(angRefraction2 * RADIAN) / sin(incidentAng1 * RADIAN));;
        ld scale = .01;
        return floor(val/scale+.5)*scale;
    }
    if (precision == 3)
    {
        ld val = n2 * (sin(angRefraction2 * RADIAN) / sin(incidentAng1 * RADIAN));
        ld scale = .001;
        return floor(val/scale+.5)*scale;
    }
    if (precision == 4)
    {
        ld val = n2 * (sin(angRefraction2 * RADIAN) / sin(incidentAng1 * RADIAN));
        ld scale = .0001;
        return floor(val / scale + .5) * scale;
    }
    else
        return n2 * (sin(incidentAng1 * RADIAN) / sin(incidentAng1 * RADIAN));
}

inline ld GeometricOptics::angleOfRefraction(const ld n1, const ld n2, const ld incidentAng1)
{
    ld temp = (n1 / n2) * sin(incidentAng1*RADIAN);
    return asin(temp)*DEGREE;
}

inline ld GeometricOptics::incidentAngle(const ld n1, const ld n2, const ld angRefraction2)
{
    ld temp = (n2 / n1) * sin(angRefraction2 * RADIAN);
    return asin(temp) * DEGREE;
}

inline ld GeometricOptics::criticalAngle(const ld n1, const ld n2)
{
    return asin(n2/n1)*DEGREE;
}

inline ld GeometricOptics::waveLength_fromIndexRefraction(const ld waveLFromSourceRay, const ld n)
{
    return waveLFromSourceRay / n;
}

inline std::map<std::string, ld> GeometricOptics::heightOfMirror(const ld floorToEyes, const ld eyesToTopHead)
{
    map<string, ld> result;
    result["floor to bottom of mirror"] = floorToEyes / 2.0;//height from floor to bottom of mirror

    result["1/2 from eyes to top of head"] =  eyesToTopHead / 2.0;

    result["height of person"] = floorToEyes + eyesToTopHead;

    result["length of mirror"] = result.at("height of person") -
                                 result.at("floor to bottom of mirror") -
                                 result.at("1/2 from eyes to top of head");
    result["floor to top of mirror"] = result.at("floor to bottom of mirror") +
                                       result.at("length of mirror");

    return result;
}

inline ld GeometricOptics::timeForSignalToTravel(const ld n, const ld d)
{
    return (d* n)/_C_;//s
}

inline ld GeometricOptics::powerOfLens(const ld f)
{
    return 1 / f;//diopters = D
}

inline ld GeometricOptics::focalLength(const ld P)
{
    return 1.0 / P;
}

inline ld GeometricOptics::focalLength(const ld m, const ld d_o)
{
    return (1 / d_o) - (1 / (m * d_o));
}

inline std::map<std::string, ld> GeometricOptics::angleAndDistanceOfBouncedLaserToSensor(const ld disFromLas2Mirror, const ld disSouthSensor, const ld angleOffBy)
{
    std::map<string, ld> results;
    ld angle = (atan(disSouthSensor / disFromLas2Mirror) * DEGREE) / 2.0;
    results["angle with respect to due west"] = angle;
    ld offBy = disFromLas2Mirror * tan((2.0 * (angle + angleOffBy))*RADIAN);
    results["distance between laser and point south"] = offBy;
    results["how far need to move the light sensor"] = offBy - disSouthSensor;

    return results;
}

inline ld GeometricOptics::incidentRayToMaterial(const ld n1, const ld n2, const ld angRefrac2)
{
    return asin((n2 * sin(angRefrac2*RADIAN)) / n1) * DEGREE;
}

inline ld GeometricOptics::imageDistance_diRaytracing(const ld dObj, const ld f)
{
    return (f * dObj) / (dObj - f);
}

inline auto GeometricOptics::imageDistance_hihodo(const ld d_o, const ld h_i, const ld h_o)
{
    return -(d_o * h_i) / h_o;
}

inline ld GeometricOptics::magnification(const ld di, const ld dObj)
{
    return -(di / dObj);
}

inline ld GeometricOptics::indexOfRefractionFromCriticalAngle(const ld cA, const ld n2)
{
    return n2 / sin(cA * RADIAN);
}

inline ld GeometricOptics::focalLength_ConvergingLens_dido(const ld d_i, const ld d_o)
{
    return (d_i * d_o) / (d_i + d_o);
}

inline ld GeometricOptics::focalLength_R(const ld R)
{
    return R / 2.0;
}

inline ld GeometricOptics::objectDistance(const ld f, const ld d_i)
{
    return 1.0 / ((1.0 / f) - (1.0 / d_i));
}

inline ld GeometricOptics::radiusOfCurvature(const ld f)
{
    return 2.0 * f;
}

inline ld GeometricOptics::intensityOfIR_radiation(const ld d_i, const ld d_o, const ld P, const ld A)
{
    return P * pow(d_o, 2) / 2 / (A / 100) / pow(d_i, 2);
}