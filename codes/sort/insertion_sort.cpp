#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void generateArray(int *, int);
void printArray(int *, int);
void insertionSort(int *, int);

void generateArray(int *arr, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 500;
    }
}

void printArray(int *arr, int size)
{
    for (int j = 0; j < size; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;
}

void insertionSort(int *arr, int size)
{
    for (int k = 1; k < size; k++)
    {
        int key = arr[k];
        int l = k - 1;
        while (l > -1 && arr[l] > key)
        {
            arr[l + 1] = arr[l];
            l = l - 1;
        }
        arr[l + 1] = key;
    }
}

int main()
{
    int *arr;
    int size;

    cout << "Insertion sort" << endl;

    cout << "Size of array? ";
    cin >> size;

    arr = new int[size];
    generateArray(arr, size);
    printArray(arr, size);
    insertionSort(arr, size);
    printArray(arr, size);

    delete arr;
    return 0;
}