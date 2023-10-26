#include <iostream>
#include <string>
using namespace std;

void permutation(string prefix, string str)
{
    int n = str.length();
    if (n == 0)
        cout << prefix << endl;
    else
    {
        for (int i = 0; i < n; i++)
            permutation(prefix + str.at(i), str.substr(0, i) + str.substr(i + 1, n - i - 1));
    }
}

void combine(string instr, string outstr, int index = 0)
{
    for (int i = index; i < instr.length(); i++)
    {
        outstr += instr.at(i);
        cout << (outstr) << endl;
        combine(instr, outstr, i + 1);
        outstr.erase(outstr.length() - 1, 1);
    }
}

int main()
{
    string str;
    cout << "Enter your string: ";
    getline(cin, str);

    cout << "combination:" << endl;
    combine(str, "");
    cout << "permutation:" << endl;
    permutation("", str);
}
