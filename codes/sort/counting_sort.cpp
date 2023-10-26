#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

void create_array(int *&A, int s);
void display_array(int *A, int s, int high);
void populate_array(int *A, int s, int low, int high);
int num_dig(int);
int i_th_dig(int n, int i);
void counting_sort(int *A, int s);
int get_max(int A[], int s);

int main()
{
    int *A;
    int s = 10;
    int l, h;

    l = 0;
    h = 150563;

    cout << "Counting Sort\n";

    create_array(A, s);
    populate_array(A, s, l, h);
    display_array(A, s, h);
    counting_sort(A, s);
    display_array(A, s, h);
    return 0;
}

void create_array(int *&A, int s)
{
    A = new int[s];
}

void display_array(int *A, int s, int high)
{
    for (int i = 0; i < s; ++i)
    {
        if (i % 10 == 0)
            cout << endl;
        cout << setw(num_dig(high) + 2) << A[i];
    }
    cout << endl;
}

void populate_array(int *A, int s, int low, int high)
{
    srand(time(0));
    for (int i = 0; i < s; ++i)
    {
        A[i] = low + rand() % (high + 1 - low);
    }
}

int num_dig(int n)
{
    if (n < 10)
        return 1;
    return 1 + num_dig(n / 10);
}

int get_max(int A[], int s)
{
    int max = A[0];
    for (int i = 1; i < s; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

void counting_sort(int *A, int s)
{
    int max = get_max(A, s);
    int F[max];
    int O[max];

    for (int i = 0; i <= max; ++i)
        F[i] = 0;

    for (int i = 0; i < s; i++)
        F[A[i]]++;

    for (int i = 1; i <= max; i++)
        F[i] += F[i - 1];

    for (int j = s - 1; j >= 0; j--)
    {
        O[F[A[j]] - 1] = A[j];
        F[A[j]]--;
    }

    for (int i = 0; i < s; i++)
        A[i] = O[i];
}