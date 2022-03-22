//
// Created by Ryan.Zurrin001 on 12/16/2021.
//

#ifndef PHYSICSFORMULA_TRANSITIVECLOSURE_H
#define PHYSICSFORMULA_TRANSITIVECLOSURE_H
#include<cstdio>
#include<cstring>
#include<iostream>
#include <list>
using namespace std;


// Number of vertices's in the graph
const int V = 7;

// A function to print the solution matrix
/* A utility function to print solution */
template<typename T>
auto printSolution(T reach[][V])
{
    printf ("Following matrix is transitive");
    printf("closure of the given graph\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            /* because "i==j means same vertex"
             and we can reach same vertex
             from same vertex. So, we print 1....
             and we have not considered this in
             Floyd Warshall Algo. so we need to
             make this true by ourself
             while printing transitive closure.*/
            if(i == j)
                printf("1 ");
            else
                printf ("%d ", reach[i][j]);
        }
        printf("\n");
    }
}

// Prints transitive closure of graph[][]
// using Floyd Warshall algorithm
template<typename T>
auto transitiveClosure(T graph[][V])
{
    /* reach[][] will be the output matrix
    // that will finally have the
       shortest distances between
       every pair of vertices */
    int reach[V][V], i, j, k;

    /* Initialize the solution matrix same
    as input graph matrix. Or
       we can say the initial values of
       shortest distances are based
       on shortest paths considering
       no intermediate vertex. */
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            reach[i][j] = graph[i][j];

    /* Add all vertices one by one to the
    set of intermediate vertices.
      ---> Before start of a iteration,
           we have reachability values for
           all pairs of vertices such that
           the reachability values
           consider only the vertices in
           set {0, 1, 2, .. k-1} as
           intermediate vertices.
     ----> After the end of a iteration,
           vertex no. k is added to the
            set of intermediate vertices
            and the set becomes {0, 1, .. k} */
    for (k = 0; k < V; k++)
    {
        // Pick all vertices as
        // source one by one
        for (i = 0; i < V; i++)
        {
            // Pick all vertices as
            // destination for the
            // above picked source
            for (j = 0; j < V; j++)
            {
                // If vertex k is on a path
                // from i to j,
                // then make sure that the value
                // of reach[i][j] is 1
                reach[i][j] = reach[i][j] ||
                              (reach[i][k] && reach[k][j]);
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(reach);
}

/**
  Let us create the following weighted graph
			10
	   (0)------->(3)
		|         /|\
	  5 |          |
		|          | 1
	   \|/         |
	   (1)------->(2)
			3
	int graph[V][V] = { {0, 1, 0, 1},
						{0, 1, 0, 1},
						{1, 1, 0, 0},
						{0, 1, 0, }
					  };

	// Print the solution
	transitiveClosure(graph);
 */
class Graph
{
    int V; // No. of vertices
    bool **tc; // To store transitive closure
    list<int> *adj; // array of adjacency lists
    void DFSUtil(int u, int v);
public:
    Graph(int V); // Constructor

    // function to add an edge to graph
    void addEdge(int v, int w) { adj[v].push_back(w); }

    // prints transitive closure matrix
    void transitiveClosure();
};

inline Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];

    tc = new bool* [V];
    for (int i=0; i<V; i++)
    {
        tc[i] = new bool[V];
        memset(tc[i], false, V*sizeof(bool));
    }
}

// A recursive DFS traversal function that finds
// all reachable vertices for s.
inline void Graph::DFSUtil(int s, int v)
{
    // Mark reachability from s to t as true.
    tc[s][v] = true;

    // Find all the vertices reachable through v
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (tc[s][*i] == false)
            DFSUtil(s, *i);
}

// The function to find transitive closure. It uses
// recursive DFSUtil()
inline void Graph::transitiveClosure()
{
    // Call the recursive helper function to print DFS
    // traversal starting from all vertices one by one
    for (int i = 0; i < V; i++)
        DFSUtil(i, i); // Every vertex is reachable from self.

    for (int i=0; i<V; i++)
    {
        for (int j=0; j<V; j++)
            cout << tc[i][j] << " ";
        cout << endl;
    }
}
#endif //PHYSICSFORMULA_TRANSITIVECLOSURE_H
