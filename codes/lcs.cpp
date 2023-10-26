#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

class LCS
{
private:
    string x, y;
    int m, n;
    int **C;

    void lcs_length()
    {
        for (int i = 0; i <= m; ++i)
            C[i][0] = 0;
        for (int j = 0; j <= n; ++j)
            C[0][j] = 0;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (x[i - 1] == y[j - 1])
                {
                    C[i][j] = C[i - 1][j - 1] + 1;
                }
                else
                {
                    if (C[i][j - 1] > C[i - 1][j])
                    {
                        C[i][j] = C[i][j - 1];
                    }
                    else
                    {
                        C[i][j] = C[i - 1][j];
                    }
                }
            }
        }
    }

    void recursive_lcs(int i, int j)
    {
        if (i == 0 || j == 0)
            return;
        if (C[i][j] == C[i - 1][j])
            return recursive_lcs(i - 1, j);
        else if (C[i][j] == C[i][j - 1])
            return recursive_lcs(i, j - 1);
        else
        {
            recursive_lcs(i - 1, j - 1);
            // cout << y[j-1];
            cout << x[i - 1];
        }
    }

public:
    LCS(string a, string b)
    {
        m = a.length();
        n = b.length();
        x = a;
        y = b;

        C = new int *[m + 1];
        for (int i = 0; i <= m; ++i)
        {
            C[i] = new int[n + 1];
        }
        lcs_length();
    }

    int get_length()
    {
        return C[m][n];
    }

    void get_lcs_string()
    {
        recursive_lcs(m, n);
    }

    void display_lcs_array()
    {
        int k;
        cout << endl;
        for (int i = 0; i <= m; ++i)
        {
            if (i != 0)
                cout << x[i - 1] << "  ";
            for (int j = 0; j <= n; ++j)
            {
                if (i == 0 && j == 0)
                {
                    cout << " Yi ";
                    for (k = 0; k < n; ++k)
                        cout << y[k] << setw(4);
                    cout << endl;
                    cout << "Xi ";
                }
                else if (i > 0 && j > 0)
                {

                    if (x[i - 1] == y[j - 1])
                    {
                        cout << "(" << C[i][j] << ") ";
                    }
                    else
                    {
                        cout << " " << C[i][j] << "  ";
                    }
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    string a, b;

    cout << "Enter 1st String: ";
    getline(cin, a);
    cout << "Enter 2nd String: ";
    getline(cin, b);

    LCS lcs(a, b);

    cout << "\nLength of the Longest Common Subsequence: " << lcs.get_length();
    cout << endl;

    cout << "\nLongest Common Subsequence of ( " << a << " ) & ( " << b << " ) : ";
    lcs.get_lcs_string();
    cout << endl;

    cout << "\nLCS Table : " << endl;
    lcs.display_lcs_array();

    return 0;
}
