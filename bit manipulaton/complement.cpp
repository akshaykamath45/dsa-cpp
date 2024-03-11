#include <iostream>
using namespace std;

// brute force
string onesComplement(string x)
{
    string res = "";
    int n = x.size();
    for (int i = 0; i < n; i++)
    {
        if (x[i] == '1')
        {
            res += '0';
        }
        else
        {
            res += '1';
        }
    }
    return res;
}

int main()
{
    string ans = onesComplement("11010101011");
    cout << ans;
    return 0;
}
