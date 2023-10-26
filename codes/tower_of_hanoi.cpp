#include <iostream>
using namespace std;

void tower_of_hanoi(int n, int s, int d);
int main()
{
    int n, s, d;
    cout << "How many rings? ";
    cin >> n;
    cout << "Source and destination: ";
    cin >> s >> d;
    tower_of_hanoi(n, s, d);
    return 0;
}

void tower_of_hanoi(int n, int s, int d)
{
    if (n == 1)
        cout << s << " -> " << d << endl;
    else
    {
        tower_of_hanoi(n - 1, s, 1 + 2 + 3 - s - d);
        cout << s << " -> " << d << endl;
        tower_of_hanoi(n - 1, 1 + 2 + 3 - s - d, d);
    }
}