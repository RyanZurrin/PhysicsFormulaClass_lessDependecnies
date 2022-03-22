//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_QUADTREE_H
#define PHYSICSFORMULA_QUADTREE_H
#pragma once

#include "Point.h"
#include "Segment.h"
#include "Boundries.h"

#include <vector>

namespace rez {

#define NUM_POINTS 4
#define INE 0
#define INW 1
#define ISE 2
#define ISW 3


    struct QDTNode {
        QDTNode* NE = nullptr, * NW = nullptr, * SE = nullptr, * SW = nullptr;
        QDTNode* parent = nullptr;
        AABB box{};
        Point2d point = DEFAULT_POINT_2D;
        bool isALeaf = false;
        //bool isAEmptyNode = false;
    };

    class QuadTree {

        QDTNode* root = nullptr;

    public:
        QuadTree() = default;

        explicit QuadTree(const std::vector<Point2d>& _points);

        QuadTree(const std::vector<Point2d>& _points, AABB& bounds);

        void BalanceTheTree();

        void GenerateMesh();

        void GetUniqueSegmentList(std::vector<Segment2d>& _segList);
    };
}
#endif //PHYSICSFORMULA_QUADTREE_H
