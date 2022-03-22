//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_VORONOI_H
#define PHYSICSFORMULA_VORONOI_H
#include <vector>
#include "Point.h"
#include "Polygon.h"
#include "Bounds.h"

// Implementation of Voronoi diagram calculation and related utility functions.
namespace rez
{
    // Compute the voronoi diagram nively using halfplane intersection
    void constructVoronoiDiagram_halfplaneIntersection(std::vector<Point2d>&);

    // Compute the voronoi diagram using fortune's algorithm
    void constructVoronoiDiagram_fortunes(std::vector<Point2d>&, std::vector<Edge2dSimple>&, BoundRectangle& rect);
}
#endif //PHYSICSFORMULA_VORONOI_H
