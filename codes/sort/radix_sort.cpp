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
void radix_sort(int *A, int s);

int main()
{
	int *A;
	int s = 15;
	int l, h;

	l = 0;
	h = 90;

	cout << "Radix Sort\n";

	create_array(A, s);
	populate_array(A, s, l, h);
	display_array(A, s, h);
	radix_sort(A, s);
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

void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

void radix_sort(int *A, int s)
{
	int F[10] = {0};
	int *B = new int[s];

	int mx = A[0];
	int *digits = new int[s];

	for (int i = 1; i < s; ++i)
	{
		if (A[i] > mx)
			mx = A[i];
	}
	int mxdig = num_dig(mx);
	for (int i = 1; i <= mxdig; i++)
	{
		for (int k = 0; k < 10; ++k)
			F[k] = 0;
		for (int j = 0; j < s; ++j)
		{
			digits[j] = i_th_dig(A[j], i);
		}

		for (int j = 0; j < s; ++j)
			F[digits[j]]++;
		for (int j = 1; j < 10; ++j)
			F[j] += F[j - 1];
		cout << endl;

		for (int j = s - 1; j >= 0; --j)
		{
			B[--F[digits[j]]] = A[j];
		}

		for (int i = 0; i < s; ++i)
			A[i] = B[i];
	}
}
int i_th_dig(int n, int i)
{
	int rem = 0;
	for (int j = 1; j <= i; ++j)
	{
		// cout<<"Here n = "<<n<<endl;
		rem = n % 10;
		n = n / 10;
	}
	return rem;
}