#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define white 0
#define grey 1
#define black 2
#define inf 32767
#define nil -1

class DFS
{
    int color[100];
    int d[100];
    int pi[100];
    int Time;
    int tNode;
    int f[100];
    int graph[100][100];
    int v;

public:
    DFS()
    {
        Time = 0;
        generateGraph();
    }
    void generateGraph()
    {
        int i, j;
        cout << "Enter total no of Vertices: ";
        cin >> tNode;

        srand(time(0));

        for (i = 0; i < tNode; i++)
        {
            for (j = 0; j < tNode; j++)
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
        cout << endl;
        for (i = 0; i < tNode; i++)
        {
            for (j = 0; j < tNode; j++)
            {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    void getPath(int f)
    {
        if (pi[f] == -1)
        {
            return;
        }
        getPath(pi[f]);
        cout << pi[f] << "->";
    }

    void generateDFSPath()
    {
        int s, f;
        cout << "\nEnter source vertex: ";
        cin >> s;
        Time = 0;
        for (int u = 0; u < tNode; u++)
        {
            color[u] = white;
            pi[u] = nil;
        }
        DFS_Visit(s);

        cout << "\nEnter destination vertex: ";
        cin >> f;
        cout << endl
             << s << " to " << f << " Path: ";
        getPath(f);
        cout << f << endl;
    }

    void createDFS()
    {
        int u;
        Time = 0;
        for (u = 0; u < tNode; u++)
        {
            color[u] = white;
            pi[u] = nil;
        }
        for (u = 0; u < tNode; u++)
        {
            if (color[u] == white)
            {
                DFS_Visit(u);
            }
        }
    }
    void DFS_Visit(int u)
    {
        color[u] = grey;
        Time = Time + 1;
        d[u] = Time;
        cout << u << " ";
        for (v = 0; v < tNode; v++)
        {
            if (graph[u][v] == 1)
            {
                if (color[v] == white)
                {
                    pi[v] = u;
                    DFS_Visit(v);
                }
            }
        }
        color[u] = black;
        f[u] = ++Time;
        cout << u << " ";
    }

    bool find_cycle()
    {
        for (int u = 0; u < tNode; u++)
        {
            for (int k = 0; k < tNode; k++)
            {
                color[k] = white;
                pi[u] = nil;
            }
            bool cyc = false;
            dfs(u, -1, u, cyc);
            if (cyc)
            {
                return true;
            }
        }
        return false;
    }
    // -CYCLE DETECTION
    void dfs(int u, int p, int s, bool &cyc)
    {
        if (color[u])
        {
            if (u == s)
                cyc = true;
            return;
        }
        color[u] = 1;

        for (int v = 0; v < tNode; v++)
        {
            if (graph[u][v])
            {
                pi[v] = u;
                dfs(v, u, s, cyc);
            }
        }
    }
};

int main()
{

    DFS obj;
    obj.displayGraph();
    obj.createDFS();
    obj.generateDFSPath();
    cout << endl;
    if (obj.find_cycle())
        cout << "Graph Contains cycle" << endl;
    else
        cout << "The graph does not have a cycle" << endl;

    return 0;
}
