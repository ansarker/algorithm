#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
bool has_cycle(int **G, int n);
void display(int **G, int n);

int main()
{
	int **G;
	int n = 5;
	G = new int *[n];
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		G[i] = new int[n];
	}
	for (int i = 0; i < n; ++i)
	{
		G[i][i] = 1;
		for (int j = i + 1; j < n; ++j)
		{
			G[j][i] = G[i][j] = rand() % 2;
			// G[j][i]=G[i][j];
		}
	}
	cout << endl
		 << endl;
	if (has_cycle(G, n))
		cout << "CYCLE EXISTS\n";
	else
		cout << "NO CYCLE\n";
	return 0;
}

bool has_cycle(int **G, int n)
{
	// ASSUMPTION: G is an adjacency matrix representation of a graph
	int **R;
	int i, j;
	R = new int *[n];
	for (i = 0; i < n; ++i)
	{
		R[i] = new int[n];
	}
	// First make a copy of the adjacency array so that the Graph is not lost
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			R[i][j] = G[i][j];
			cout << G[i][j] << "\t";
		}
		cout << endl;
	}

	int first, second, next;

	for (i = 0; i < n; ++i)
	{
		first = second = -1;
		next = n;
		for (j = 0; j < n; ++j)
		{
			if (i == j)
				continue;
			if (first == -1 && R[i][j] == 1)
			{
				first = j;
				// cout<<"\nSetting first="<<j<<endl;
			}
			else if (first != -1 && R[i][j] == 1)
			{
				second = j;
				if (next == n)
					next = j;
				// cout<<"\nSetting second="<<j<<endl;
			}
			if (first != -1 && second != -1)
			{
				if (R[first][second] == 1)
				{
					display(R, n);
					return true;
				}
				R[first][second] = R[second][first] = 1;
				second = -1;
			}
			// This bit of code is tricky, resetting the inner loop, messing up complexity analysis
			if (j == n - 1 && next != n)
			{
				j = next;
				next = n;
			}
		}
	}
	display(R, n);
	return false;
}

void display(int **G, int n)
{
	cout << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << G[i][j] << "\t";
		}
		cout << endl;
	}
}
