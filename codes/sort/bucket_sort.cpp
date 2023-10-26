#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void create_array(int* &A, int s);
void populate_array(int* A, int s, int l, int h);
void display_array(int* A, int s);
int min_value(int* A, int s);
int max_value(int* A, int s);
int max_dig(int);
void bucket_sort(int *A, int n);

int main()
{
    int *A;
	int s;
	int h, l;
	s = 20;
	l = 0;
	h = 1024;

	cout << "Bucket Sort\n";
	create_array(A, s);
	populate_array(A, s, l, h);
	display_array(A, s);
   	bucket_sort(A, s);
	display_array(A, s);

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

int max_dig(int dig) {
	if (dig < 10) return 1;
	return 1 + max_dig(dig/10);
}

void display_array(int* A, int s) {
	for (int i = 0; i < s; ++i) {
		if (i%10 == 0) cout << endl;
		cout << left << setw(max_dig(max_value(A,s)) + 2) << A[i];
	}
	cout << endl;
}

int min_value(int* A, int s) {
    int mn = A[0];
    for(int i = 0; i < s; ++i) {
        if(A[i] < mn) mn = A[i];
    }
    return mn;
}

int max_value(int* A, int s) {
	int mx = A[0];
	for (int i = 1; i < s; ++i) {
		if (A[i] > mx) mx = A[i];
	}
	return mx;
}

void bucket_sort(int *A, int n){
    int *Buck;
    int minValue = min_value(A, n);
    int maxValue = max_value(A, n);
    int s = minValue/10;
    int e = maxValue/10;
    int buck_size = maxValue+1;
    Buck = new int[buck_size];

    cout << "Min = " << minValue << endl;
    cout << "Max = " << maxValue << endl;
    cout << "Start = " << s << endl;
    cout << "End = " << e << endl;
    cout << "Buck Size = " << buck_size << endl;

    for(int i = 0; i < buck_size; ++i){
        Buck[i] = 0;
    }

    for(int i = 0; i < n; ++i) {
        Buck[A[i]]++;
    }

    for(int i = 0, j = 0; j < buck_size; ++j){
        for(int k = Buck[j]; k > 0; --k){
            A[i++] = j;
        }
    }
}
