#include <iostream>
#include <cstdlib>
#include <ctime>
#include "QueueArray.cpp"

#define white 0
#define gray 1
#define black 2
#define nil -1
#define inf 32767

using namespace std;

class GraphTraversal
{
    int graph[100][100];
    int tVertex;
    int s, f;
    int color[100];
    int d[100];
    int pi[100];

public:
    void generateGraph()
    {
        int i, j;
        cout << "How many Vertices: ";
        cin >> tVertex;
        srand(time(0));
        for (i = 0; i < tVertex; i++)
        {
            for (j = 0; j < tVertex; j++)
            {
                if (rand() % 3)
                    graph[i][j] = 0;
                else
                    graph[i][j] = 1;
            }
        }
    }
    void displayGraph()
    {
        int i, j;
        for (i = 0; i < tVertex; i++)
        {
            for (j = 0; j < tVertex; j++)
            {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
    }
    void BFS(int graph[][100], int n, int s)
    {
        int u, v;
        double x;
        for (u = 0; u < n; u++)
        {
            color[u] = white;
            d[u] = 0;
            pi[u] = nil;
        }
        color[s] = gray;
        d[s] = 0;
        pi[s] = nil;
        Queue q(n);
        q.Enqueue(s);
        cout << "\nTraversal Order: ";
        while (!q.IsEmpty())
        {
            q.Dequeue(x);
            u = (int)x;
            cout << u << " ";
            for (v = 0; v < tVertex; v++)
            {
                if (graph[u][v] == 1)
                {
                    if (color[v] == white)
                    {
                        color[v] = gray;
                        d[v] = d[u] + 1;
                        pi[v] = u;
                        q.Enqueue(v);
                    }
                }
            }
            color[u] = black;
        }
    }
    void getPath(int pi[], int f)
    {
        if (pi[f] == -1)
            return;
        getPath(pi, pi[f]);
        cout << pi[f] << "->";
    }
    void generateBFSPath()
    {
        cout << "Enter Source vertex: ";
        cin >> s;
        BFS(graph, tVertex, s);
        cout << "\nEnter a destination vertex: ";
        cin >> f;
        cout << "\nPath from " << s << " to " << f << " is :" << endl;
        getPath(pi, f);
        cout << f << endl;
    }
};

int main()
{
    GraphTraversal obj;
    obj.generateGraph();
    obj.displayGraph();
    obj.generateBFSPath();

    return 0;
}
