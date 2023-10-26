#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
class HeapSort
{
    struct Node
    {
        int key;
    };
    // int * Heap;
    Node *Heap;
    int maxSize;

public:
    HeapSort(int size = 1000)
    {
        Heap = new Node[size];
        maxSize = size;
        randomInput(Heap, size);
    }
    ~HeapSort()
    {
        delete[] Heap;
    }
    void randomInput(Node *Heap, int n)
    {
        int i;
        srand(time(0));
        for (i = 0; i < n; i++)
        {
            Heap[i].key = rand() % 100;
        }
    }
    void rebuildHeap(Node Heap[], int parent, int n)
    {
        int child = 2 * parent + 1; // set child to root�s left child, if any
        if (child < n)              // if root�s left child exists . . .
        {
            int rightChild = child + 1;
            if (rightChild < n && Heap[rightChild].key > Heap[child].key)
                child = rightChild; // child indicates the larger item
            if (Heap[parent].key < Heap[child].key)
            {
                swap(Heap[parent], Heap[child]);
                rebuildHeap(Heap, child, n);
            }
        }
    }
    void bSort()
    {
        int i, j;
        for (i = 0; i < maxSize; i++)
        {
            for (j = maxSize - 1; j > 0; j--)
            {
                if (Heap[j].key < Heap[j - 1].key)
                    swap(Heap[j], Heap[j - 1]);
            }
        }
    }

    void hSort()
    {
        int i;
        int n = maxSize;
        // transform array Heap[ ], containing n items, into a heap
        for (int parent = n / 2 - 1; parent >= 0; parent--)
        {
            // transform a semiheap with the given parent into a heap
            rebuildHeap(Heap, parent, n);
        }

        for (int last = n; last > 0;)
        { // move the largest item in the heap, heap[ 0 .. last ], to the
          //  beginning of the sorted region, Heap[ last+1 .. n�1 ], and
          //  increase the sorted region
            swap(Heap[0], Heap[last - 1]);
            last--;
            // transform the semiheap in a[ 0 .. last ] into a heap
            rebuildHeap(Heap, 0, last);
        }
    }
    void display()
    {
        int i;
        cout << endl
             << "Array Contents:" << endl;
        ;
        for (i = 0; i < maxSize; i++)
        {
            cout << Heap[i].key << " ";
        }

        cout << endl;
    }
};

int main()
{
    clock_t c_start, c_end;
    HeapSort obj(50);

    obj.display();

    c_start = clock();
    obj.bSort();
    c_end = clock();

    obj.display();

    cout << "Total Time: " << (c_end - c_start) / (double)CLOCKS_PER_SEC;
    cout << endl;
    return 0;
}
