/*******
 * Sun 05 Mar 2017 08:21:03 PM BDT
 ********/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void create_array(int *&A, int s);
void populate_array(int *A, int s, int l, int h);
void display_array(int *A, int s);
int max_value(int *A, int s);
int max_dig(int dig);
void swap(int &, int &);
void selection_sort(int *A, int s);

int main()
{
    int *A, n;
    int h, l;
    int key;

    cout << "Selection Sort\n";
    n = 100;
    h = 10;
    l = 100;
    create_array(A, n);
    populate_array(A, n, h, l);
    display_array(A, n);
    selection_sort(A, n);
    display_array(A, n);

    return 0;
}

void create_array(int *&A, int s)
{
    A = new int[s];
}

void populate_array(int *A, int s, int l, int h)
{
    srand(time(NULL));
    for (int i = 0; i < s; ++i)
    {
        A[i] = l + rand() % (h + 1 - l);
    }
}

int max_value(int *A, int s)
{
    int mx = A[0];
    for (int i = 1; i < s; ++i)
    {
        if (A[i] > mx)
            mx = A[i];
    }
    return mx;
}

int max_dig(int dig)
{
    if (dig < 10)
        return 1;
    return 1 + max_dig(dig / 10);
}

void display_array(int *A, int s)
{
    cout << endl;
    for (int i = 0; i < s; ++i)
    {
        if (i % 10 == 0)
            cout << endl;
        cout << setw(max_dig(max_value(A, s)) + 1) << A[i];
    }
    cout << endl;
}

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void selection_sort(int *A, int s)
{
    for (int i = 0; i < s - 1; ++i)
    {
        int smallest = i;
        for (int j = i + 1; j < s; ++j)
        {
            if (A[j] < A[smallest])
            {
                smallest = j;
            }
        }
        swap(A[i], A[smallest]);
    }
}