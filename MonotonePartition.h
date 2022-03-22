//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_MONOTONEPARTITION_H
#define PHYSICSFORMULA_MONOTONEPARTITION_H
#include <vector>
#include "Vector.h"
#include "PolygonDCEL.h"
#include "GeoUtils.h"

namespace rez {
    void get_monotone_polygons(Polygon2d* poly, std::vector<Polygon2d*>& mono_polies);
}
#endif //PHYSICSFORMULA_MONOTONEPARTITION_H
