/***************************
*   C++ codes
*   Author: Anis Sarker
*
*   Program List:
*       dynamically create array
*       populate array
*       displaying the array
*       finding max value
*       finding max digit
*       swap two variable
*       merge two array ;for merge sort
*       pivot ;for quick sort
*
*   finding value in a given array
*       find a key or linear search
*       binary search
*
*   comparison based sorting algorithm
*       bubble sort
*       insertion sort
*       selection sort
*       merge sort
*       quick sort
*
*   linear time sorting algorithm
*
*****************************/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

void create_array(int* &A, int s);
void populate_array(int* A, int s, int l, int h);
void display_array(int* A, int s);
int max_value(int* A, int s);
int max_dig(int);
void swap(int&, int&);
void merge_me(int *A, int *B, int j, int k);
void merge(int A[], int i, int j, int k);
int pivot(int *A, int s, int e);

int find_key(int* A, int s, int key);
int bin_search(int* A, int s, int key);
int r_bin_search(int* A, int l, int r, int key);

void bubble_sort(int* A, int s);
void insertion_sort(int* A, int s);
void insertion_sort2(int* A, int i, int j);
void selection_sort(int* A, int s);
void merge_sort(int *A, int l, int r);
void quick_sort(int *A, int l, int r);

void counting_sort(int *A, int n);

void simple_pattern();

int main() {
	int *A;
	int *B;
	int s, s1;
	int h, l;
	int value;
	s = 10;
	s1 = 3;
	l = 10;
	h = 10000;

	create_array(A, s);
	create_array(B, s1);
	populate_array(A, s, l, h);
	display_array(A, s);
	//cout << "\nMax Value : " << max_value(A,s) << endl;
	//cout << "\nLength of Max Value : " << max_dig(max_value(A,s)) << endl;
	//cout << "\nValue at index : " << find_key(A, s, -1) << endl;

	//bubble_sort(A,s);
	//insertion_sort(A, s);
	//insertion_sort2(A, 20, 39);
	//selection_sort(A, s);
	merge_sort(A, 0, s-1);
	//quick_sort(A, 0, s-1);

	//merge(A, 5, 15, 25);
	//merge_me(A, B, s, s1);

   	//counting_sort(A,s);

	display_array(A, s);

	//simple_pattern();

    /*cout << "Value to search : ";
    cin >> value;
    //int index = bin_search(A,s,value);
    int index = r_bin_search(A, 0, s-1, value);
    if (index >= 0) cout << endl << value << " found @ index " << index+1 << endl;
    else cout << endl << value << " not found" << endl;
*/
	return 0;
}

void create_array(int* &A, int s) {
	A = new int[s];
}

void populate_array(int* A, int s, int l, int h) {
	srand(time(0));
	for (int i = 0; i < s; ++i) {
		A[i] = l + rand() % (h + 1 - l);
	}
}

void display_array(int* A, int s) {
	cout << endl;
	for (int i = 0; i < s; ++i) {
		if (i%10 == 0) cout << endl;
		cout << left << setw(max_dig(max_value(A,s)) + 2) << A[i];
	}
	cout << endl;
}

int max_value(int* A, int s) {
	int mx = A[0];
	for (int i = 1; i < s; ++i) {
		if (A[i] > mx) mx = A[i];
	}
	return mx;
}

int max_dig(int dig) {
	if (dig < 10) return 1;
	return 1 + max_dig(dig/10);
}

int find_key(int* A, int s, int key) {
	for (int i = 0; i < s; ++i){
		if (A[i] == key) return i;
	}
	return -1;
}

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

void bubble_sort(int* A, int s) {
	for (int pass = 0; pass < s; ++pass)
	for (int i = 0; i < s-1; ++i) {
		if (A[i] > A[i+1]) {
			swap(A[i], A[i+1]);
		}
	}
}

int bin_search(int* A, int s, int key) {
    int l = 0;
    int r = s - 1;
    int mid;
    while (l <= r) {
        mid = (l+r)/2;
        if (A[mid] == key) return mid;
        else if (key < A[mid]) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

int r_bin_search(int* A, int l, int r, int key) {
    int mid = (l+r)/2;
    if (l > r)  return -1;
    if (A[mid] == key) return mid;
    else if (key < A[mid]) return r_bin_search(A, l, mid-1, key);
    else if (key > A[mid]) return r_bin_search(A, mid+1, r, key);
}

void insertion_sort(int* A, int s) {
    int i, j, key;

    for(j = 1; j < s; ++j) {
        key = A[j];
        i = j - 1;
        while (A[i] > key && i >= 0) {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}

void insertion_sort2(int* A, int k, int l) {
	int i, j, key;

	for(j = k+1; j <= l; ++j) {
		key = A[j];
		i = j-1;
		while(A[i] > key && i >= k) {
			A[i+1] = A[i];
			i--;
		}
		A[i+1] = key;
	}
}

void selection_sort(int* A, int s) {
    int i, j, smallest, temp;
    for (j = 0; j < s - 1; ++j) {
        smallest = j;
        for (i = j + 1; i < s; ++i) {
            if (A[i] < A[smallest])
                smallest = i;
        }

        if (smallest != j) {
            temp = A[j];
            A[j] = A[smallest];
            A[smallest] = temp;
        }

    }
}

/*
void merge_me(int *A, int *B, int m, int n) {
    int *C;
    int l = m + n;
    C = new int[l];

    for(int i=0; i<m; ++i){
        populate_array(A, m, 10, 55);
    }
    display_array(A, m);

    for(int j=0; j<n; ++j){
        populate_array(B, n, 5, 50);
    }
    display_array(B, n);

    cout << "L = " << l << endl;

    for(int k=0; k<l; ++k){
        for(int i=0; i<m; ++i)
            C[k++] = A[i];
        for(int j=0; j<n; ++j)
            C[k++] = B[j];
    }

    display_array(C,l);
}
*/

void merge(int A[], int i, int j, int k){
	int l, r, m;
	int s1 = j-i+1;
	int s2 = k-j;
	int *L = new int[s1];
	int *R = new int[s2];

	for(l = 0; l < s1; ++l) L[l] = A[i+l];
	for(r = 0; r < s2; ++r) R[r] = A[j+1+r];
	l = r = 0;

	for(m = i; m <= k; m++){
		if(l == s1){
			A[m] = R[r];
			r++;
		}else if(r == s2){
			A[m] = L[l];
			l++;
		}else if(L[l] <= R[r]){
			A[m] = L[l];
			l++;
		}else if(R[r] <= L[l]){
			A[m] = R[r];
			r++;
		}
	}
}

void merge_sort(int *A, int l, int r){
	int m = (l+r)/2;
	if(r > l){
		merge_sort(A, l, m);
		merge_sort(A, m+1, r);
		merge(A, l, m, r);
	}
}

int pivot(int *A, int s, int e){
	int pivot = A[e];
	int pIndex = s;	//pIndex = partition index
	for(int i = s; i < e; ++i){
		if(A[i] <= pivot){
			swap(A[i],A[pIndex]);
			pIndex += 1;
		}
	}
	swap(A[pIndex], A[e]);
	return pIndex;
}

void quick_sort(int *A, int l, int r){
	if(l < r){
		int p = pivot(A, l, r);
		quick_sort(A, l, p-1);
		quick_sort(A, p+1, r);
	}
}

void counting_sort(int *A, int n){
    int t, r;
    t = 250000;
    r = 1000;
    int *B;
    int *C;
    B = new int [t];
    C = new int [r];

    for(int i = 0; i < r; ++i){
        C[i] = 0;
    }
	for(int i = 0; i < n; ++i){
		C[A[i]]++;
	}
	for(int i = 1; i < r; ++i){
		C[i] = C[i] + C[i-1];
	}
	for(int j = n; j > 0; j--){
		B[C[A[j]]] = A[j];
		C[A[j]] = C[A[j]] - 1;
	}
	for(int i = 0; i < n; ++i){
		A[i] = B[i];
	}
}

void simple_pattern()
{
    int inc = -1;
    for(int i = 0; i < 5; ++i){
        inc += 2;
        for(int j = i; j < 4; ++j){
            cout << " ";
        }
        int t = inc;
        while(t > 0){
            cout << t;
            t--;
        }
        cout << endl;
    }
}























