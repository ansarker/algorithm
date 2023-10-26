/*
Example VERIFICACION of MST
9 11
1 2 4
1 8 9
2 3 9
2 8 11
3 9 2
7 8 1
7 9 6
8 9 7
4 5 10
4 6 15
5 6 11
*/

#include <algorithm>
#include <iostream>
using namespace std;
#define MAX 100 // Maximum  number of vertices
int V, E;       // number of vertices and edges
/// UNION-FIND
int parent[MAX]; // This array contains the parent of the ith node

// set initialization
void MakeSet(int n)
{
    for (int i = 1; i <= n; ++i)
        parent[i] = i;
}

// find the root of the current vetiint V , E;
// number of vertices and edgesce X
int Find(int x)
{
    return (x == parent[x]) ? x : parent[x] = Find(parent[x]);
}

// join two related sets
void Union(int x, int y)
{
    parent[Find(y)] = Find(x);
}

// determined whether the two vetices connected
bool sameComponent(int x, int y)
{
    if (Find(x) == Find(y))
        return true;
    return false;
}
/// FIN UNION-FIND

// Edge data structure (Edge ​​)
struct Edge
{
    int origin;      // Vetice origin
    int destination; // Vetice destination
    int weight;      // Vetice weight between the origin and destination
    Edge() {}
    // Compare by weight, helps to sort in ascending order
    bool operator<(const Edge &e) const
    {
        return weight < e.weight;
    }
} edge[MAX];   // Total Number of edges used in the Algorithm
Edge MST[MAX]; // Total Number of edges after MST creation

void Kruskal()
{
    int origin, destination, weight;
    int total = 0;    // total weight of the MST
    int numedges = 0; // total number of edges of the MST

    MakeSet(V);           // initialize each set
    sort(edge, edge + E); // order the edges by weight

    for (int i = 0; i < E; ++i)
    {                                      // Create MST from the edges sorted by weight
        origin = edge[i].origin;           // Origin Vetice of the current edge i
        destination = edge[i].destination; // destination Vetice of the current edge i
        weight = edge[i].weight;           // weight of the current edge i

        // check whether they are in the same set
        if (!sameComponent(origin, destination))
        {                               // avoid cycles
            total += weight;            // Increase the total weight of the MST
            MST[numedges++] = edge[i];  // current edge is added to MST
            Union(origin, destination); // Union of both sets in a single set
        }
    }
    //    if the MST is not found by all vertices show error message
    //    To find out whether it contains all the vertices check the number of edges equals the number of vertices - 1

    if (V - 1 != numedges)
    {
        cout << "No MST is possible for the graph entered.";
        return;
    }
    cout << "-----The MST is made of the following edges-----" << endl;
    for (int i = 0; i < numedges; ++i)
    {
        cout << MST[i].origin << "--" << MST[i].destination << "(" << MST[i].weight << ")+";
        if (i == numedges - 1)
            cout << "\b " << endl;
        else
            cout << endl; //( vertice u , vertice v ) : weight
    }

    cout << "The minimum cost of all edges of the MST is: " << total << endl;
}

int main()
{
    int mst;
    cout << "Number of Vertices & Edges: " << endl;
    cin >> V >> E;
    for (int i = 0; i < E; ++i)
        cin >> edge[i].origin >> edge[i].destination >> edge[i].weight;
    Kruskal();
    return 0;
}
