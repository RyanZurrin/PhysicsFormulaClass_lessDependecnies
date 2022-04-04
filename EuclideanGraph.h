//
// Created by ryanz on 4/2/2022.
//

#ifndef PHYSICSFORMULA_EUCLIDEANGRAPH_H
#define PHYSICSFORMULA_EUCLIDEANGRAPH_H

#include "Point2D.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Edge {
public:
    Edge(int v1, int v2, double weight) : v1(v1), v2(v2), weight(weight) {}
    int v1;
    int v2;
    double weight;
};

template <typename T>
class EuclideanGraph {
    // make points smart pointer array

    int V{};
    int E{};
    vector<vector<Edge>> adj;
    vector<Point2D<T>> points;
public:
    EuclideanGraph(int V, int E) : V(V), E(E) {
        points = vector<Point2D<T>>(V);
        adj = vector<vector<Edge>>(V);
        for (int i = 0; i < V; i++) {
            adj[i] = vector<Edge>();
        }

    }
    // read in a graph from a file
    explicit EuclideanGraph(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Error: file not found" << endl;
            return;
        }
        file >> V >> E;
        cout << "V: " << V << " E: " << E << endl;
        points = vector<Point2D<T>>(V);
        adj = vector<vector<Edge>>(V);
        for (int i = 0; i < V; i++) {
            adj[i] = vector<Edge>();
        }
        // print out the size of the adj and points
        cout << "adj size: " << adj.size() << endl;
        cout << "points size: " << points.size() << endl;
        int v = 0;
        int x = 0;
        int y = 0;
        for (int i = 0; i < V; i++) {
            try {
                file >> v >> x >> y;
                points[v].setX(x);
                points[v].setY(y);
            } catch (exception e) {
                cout << "Error: at v:" << v << " x:" << x << " y:" << y << endl;

                return;
            }

        }
        for (int i = 0; i < E; i++) {
            int v1, v2;
            // weight is  distance between points
            double weight = points[v1].distanceTo(points[v2]);
            cout << "v1: " << v1 << " v2: " << v2 << " weight: " << weight << endl;
            file >> v1 >> v2 >> weight;
            adj[v1].push_back(Edge(v1, v2, weight));
            adj[v2].push_back(Edge(v2, v1, weight));
            cout << i << "edges read" << endl;
        }
    }

    EuclideanGraph(const EuclideanGraph& other) {
        V = other.V;
        E = other.E;
        points = other.points;
        adj = vector<vector<Edge>>(V);
        for (int i = 0; i < V-1; i++) {
            adj[i] = vector<Edge>();
        }
        for (int i = 0; i < V; i++) {
            points[i] = other.points[i];
            for (int j = 0; j < other.adj[i].size(); j++) {
                adj[i].push_back(other.adj[i][j]);
            }
        }
    }

    EuclideanGraph& operator=(const EuclideanGraph& other) {
        V = other.V;
        E = other.E;
        points = other.points;
        adj = vector<vector<Edge>>(V);
        for (int i = 0; i < V; i++) {
            adj[i] = vector<Edge>();
        }
        for (int i = 0; i < V; i++) {
            points[i] = other.points[i];
            for (int j = 0; j < other.adj[i].size(); j++) {
                adj[i].push_back(other.adj[i][j]);
            }
        }
        return *this;
    }

    int getV() {
        return V;
    }
    int getE() {
        return E;
    }
    Point2D<T> getPoint(int v) {
        return points[v];
    }
    vector<Edge> getAdj(int v) {
        return adj[v];
    }
    void print() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": ";
            for (int j = 0; j < adj[i].size(); j++) {
                cout << adj[i][j].v2 << " ";
            }
            cout << endl;
        }
    }

    ~EuclideanGraph() {
    }

};


#endif //PHYSICSFORMULA_EUCLIDEANGRAPH_H
