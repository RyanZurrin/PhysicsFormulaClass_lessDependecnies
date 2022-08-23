//
// Created by Ryan.Zurrin001 on 12/17/2021.
//

#ifndef PHYSICSFORMULA_TEMPLATEGRAPH_H
#define PHYSICSFORMULA_TEMPLATEGRAPH_H
#include <iostream>
#include <vector>
// a template graph class
namespace graph {
    template<class T>
    class GraphNode {
        T data;
        std::vector<GraphNode<T> *> neighbors;
    public:
        GraphNode(T _data) : data(_data) {}

        void addNeighbor(GraphNode<T> *neighbor) {
            neighbors.push_back(neighbor);
        }

        void removeNeighbor(GraphNode<T> *neighbor) {
            neighbors.erase(
                    std::remove(neighbors.begin(), neighbors.end(), neighbor),
                    neighbors.end());
        }

        std::vector<GraphNode<T> *> getNeighbors() {
            return neighbors;
        }

        T getData() {
            return data;
        }
    };

    template<class T>
    class Graph {
        std::vector<GraphNode<T> *> nodes;
    public:
        Graph() {}

        void addNode(GraphNode<T> *node) {
            nodes.push_back(node);
        }

        std::vector<GraphNode<T> *> getNodes() {
            return nodes;
        }

        // add an edge between two nodes
        void addEdge(GraphNode<T> *node1, GraphNode<T> *node2) {
            node1->addNeighbor(node2);
            node2->addNeighbor(node1);
        }

        // remove an edge between two nodes
        void removeEdge(GraphNode<T> *node1, GraphNode<T> *node2) {
            node1->removeNeighbor(node2);
            node2->removeNeighbor(node1);
        }

        // remove a node from the graph
        void removeNode(GraphNode<T> *node) {
            for (auto n: nodes) {
                n->removeNeighbor(node);
            }
            nodes.erase(std::remove(nodes.begin(), nodes.end(), node),
                        nodes.end());
        }

    };
}

#endif //PHYSICSFORMULA_TEMPLATEGRAPH_H
