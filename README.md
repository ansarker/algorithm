# Algorithms
Algorithms implementation in C++

## Lists
* [Best Fit Algorithm](codes/best_fit_algo.cpp)
* [BFS Traversal](codes/BFS/BFS.cpp)
* [DFS]()
  * [Cycle Detection V1](codes/DFS_CycleDetection.cpp)
  * [Cycle Detection V2](codes/cycle_detection.cpp)
* [Kruskal Algorithm](codes/kruskal.cpp)
  <details close>
    <summary>Example</summary>
    
    ```bash
      Number of Vertices & Edges: 
      9 14
      1 2 4
      1 8 9
      2 3 9
      2 8 11
      3 4 7
      3 9 2
      3 6 4 
      4 5 10
      4 6 15
      5 6 11
      6 7 2
      7 8 1
      7 9 6
      8 9 7
      -----The MST is made of the following edges-----
      7--8(1)+
      3--9(2)+
      6--7(2)+
      1--2(4)+
      3--6(4)+
      3--4(7)+
      1--8(9)+
      4--5(10) 
      The minimum cost of all edges of the MST is: 39
    ```
  </details>
* [Lowest Common Subsequence](codes/lcs.cpp)
  <details close>
    <summary>Example</summary>
    
    ```bash
      Enter 1st String: Crocus sativus
      Enter 2nd String: Nigella sativa

      Length of the Longest Common Subsequence: 6

      Longest Common Subsequence of ( Crocus sativus ) & ( Nigella sativa ) :  sativ

      LCS Table : 

      Yi N   i   g   e   l   l   a       s   a   t   i   v   a
      Xi 
      C   0   0   0   0   0   0   0   0   0   0   0   0   0   0  
      r   0   0   0   0   0   0   0   0   0   0   0   0   0   0  
      o   0   0   0   0   0   0   0   0   0   0   0   0   0   0  
      c   0   0   0   0   0   0   0   0   0   0   0   0   0   0  
      u   0   0   0   0   0   0   0   0   0   0   0   0   0   0  
      s   0   0   0   0   0   0   0   0  (1)  1   1   1   1   1  
          0   0   0   0   0   0   0  (1)  1   1   1   1   1   1  
      s   0   0   0   0   0   0   0   1  (2)  2   2   2   2   2  
      a   0   0   0   0   0   0  (1)  1   2  (3)  3   3   3  (3) 
      t   0   0   0   0   0   0   1   1   2   3  (4)  4   4   4  
      i   0  (1)  1   1   1   1   1   1   2   3   4  (5)  5   5  
      v   0   1   1   1   1   1   1   1   2   3   4   5  (6)  6  
      u   0   1   1   1   1   1   1   1   2   3   4   5   6   6  
      s   0   1   1   1   1   1   1   1  (2)  3   4   5   6   6  
    ```
  </details>
* [Permutation Combination Recursive](codes/perm_comb_rec.cpp)
* [Prim's Algorithm](codes/prims_algorithm.cpp)
  <details close>
    <summary>Example</summary>

    ```bash
      ------------------------
          Prim's algorithm    
      ------------------------
      ----------------------------
                Matrix           
      ----------------------------
        -1  18  10   6  19   8   9
        18  -1  11   1   7  19  14
        10  11  -1   5   7  20  11
        6   1   5  -1  11  12  16
        19   7   7  11  -1  18  18
        8  19  20  12  18  -1   7
        9  14  11  16  18   7  -1

      Edge found: 0 -> 3 : 6
      Edge found: 3 -> 1 : 1
      Edge found: 3 -> 2 : 5
      Edge found: 1 -> 4 : 7
      Edge found: 0 -> 5 : 8
      Edge found: 5 -> 6 : 7
      The total weight of the minimum spanning tree is: 34
    ```
  </details>
* [Queue Array](codes/QueueArray.cpp)
* [Sorting Algorithms](codes/sort/)
  * [Bubble Sort](codes/sort/bubble_sort.cpp)
  * [Bucket Sort](codes/sort/bucket_sort.cpp)
  * [Counting Sort](codes/sort/counting_sort.cpp)
  * [Heap Sort](codes/sort/HeapSort.cpp)
  * [Insertion Sort](codes/sort/insertion_sort.cpp)
  * [Merge Sort](codes/sort/MergeSort.cpp)
  * [Quick Sort](codes/sort/quick_sort.cpp)
  * [Radix Sort](codes/sort/radix_sort.cpp)
  * [Selection Sort](codes/sort/selection_sort.cpp)
* [Tower of Hanoi](codes/tower_of_hanoi.cpp)