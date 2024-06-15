#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr)
{
    int n = arr.size();
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << "before calling function " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    solve(arr);
    cout << endl;
    cout << "after calling function " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}