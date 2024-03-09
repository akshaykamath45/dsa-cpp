#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// converting to binary
string convertToBinary(int n)
{
    string res = "";
    while (n != 1)
    {

        if (n % 2 == 0)
            res += '0';
        else
            res += '1';
        n = n / 2;
    }
    res += '1';
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string ans = convertToBinary(18);
    cout << ans;
    return 0;
}


// converting to binary
int convertToDecimal(string x)
{
    int n = x.size();
    int num = 0;
    int p2 = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (x[i] == '1')
        {
            num = num + p2;
        }
        p2 = p2 * 2;
    }
    return num;
}

int main()
{
    int ans = convertToDecimal("1101");
    cout << ans;
    return 0;
}
