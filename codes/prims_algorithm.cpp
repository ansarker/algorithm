#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void adjacency_matrix(int **&G, int v);
void create_matrix(int **G, int v, int *V);
void display_matrix(int **G, int v);
void prim_mst(int **G, int n, int *V);

int main()
{
    cout << "------------------------" << endl;
    cout << "    Prim's algorithm    " << endl;
    cout << "------------------------" << endl;

    srand(time(NULL));

    int **Matrix;
    int *Visited;
    int n = 7;

    Visited = new int[n];        // 1D Matrix Allocation
    adjacency_matrix(Matrix, n); // 2D Matrix Allocation

    create_matrix(Matrix, n, Visited); // Create Graph
    display_matrix(Matrix, n);         // Display Grah
    prim_mst(Matrix, n, Visited);      // Create and Display the MST

    return 0;
}

void adjacency_matrix(int **&G, int v)
{
    G = new int *[v];
    for (int i = 0; i < v; ++i)
    {
        G[i] = new int[v];
    }
}

void create_matrix(int **Matrix, int n, int *Visited)
{
    for (int i = 0; i < n; ++i)
    {
        Visited[i] = 0;
        for (int j = 0; j < n; ++j)
        {
            // cin >> Matrix[i][j];
            if (i == j)
            {
                Matrix[i][j] = 0;
            }
            else if (j > i)
            {
                Matrix[i][j] = 1 + rand() % 20;
            }
            else if (i > j)
            {
                Matrix[i][j] = Matrix[j][i];
            }
            if (Matrix[i][j] == 0)
            {
                Matrix[i][j] = -1;
            }
        }
    }
}

void display_matrix(int **Matrix, int n)
{
    cout << "----------------------------" << endl;
    cout << "           Matrix           " << endl;
    cout << "----------------------------" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << setw(4) << Matrix[i][j];
        }
        cout << endl;
    }
    cout << "\n";
}

void prim_mst(int **Matrix, int n, int *Visited)
{
    int min;
    int u = 0;
    int v = 0;
    int total = 0;
    Visited[0] = 1;

    for (int c = 0; c < n - 1; ++c)
    {
        min = 999;
        for (int i = 0; i < n; ++i)
        {
            if (Visited[i] == 1)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (Visited[j] == 0)
                    {
                        if (min > Matrix[i][j])
                        {
                            min = Matrix[i][j];
                            u = i;
                            v = j;
                        }
                    }
                }
            }
        }
        Visited[v] = 1;
        total += min;
        cout << "Edge found: " << u << " -> " << v << " : " << min << endl;
    }
    cout << "The total weight of the minimum spanning tree is: " << total << endl;
}
