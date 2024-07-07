// find longest subarray with sum<=k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int k)
{
    int maxLen = 1;
    int n = arr.size();
    int storeI = -1;
    int storeJ = -1;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum <= k)
            {
                int len = j - i + 1;
                if (len > maxLen)
                {
                    maxLen = len;
                    storeI = i;
                    storeJ = j;
                }
            }
          
        }
    }
    cout << "longest subarray is of length " << maxLen << " below" << endl;
    for (int i = storeI; i <= storeJ; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    vector<int> arr = {9, 5, 1, 7, 4};
    cout << "before calling function " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    solve(arr, 20);
    cout << endl;
    // cout << "after calling function " << endl;
    // for (auto i : arr)
    // {
    //     cout << i << " ";
    // }
    return 0;
}