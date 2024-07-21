#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s = "hjsdflffdfjdfjsdfjnfjsf";
    int n = s.size();

    // converting to upper
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] -= 32;
        }
    }
    cout << s << endl;
    // converting to lower
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += 32;
        }
    }
    cout << s << endl;
    return 0;
}