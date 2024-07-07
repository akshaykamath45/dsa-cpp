#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int k)
{
    int n = arr.size();
    int maxLen = 1;
    int l = 0;
    int r = 0;
    int storeL = -1;
    int storeR = -1;
    int sum = 0;
    while (r < n)
    {
        sum += arr[r];
        while (sum > k)
        {
            sum = sum - arr[l];
            l++;
        }
        if (sum <= k)
        {
            int len = r - l + 1;
            if (len > maxLen)
            {
                maxLen = len;
                storeL = l;
                storeR = r;
            }
        }

        r++;
    }
    cout << "longest subarray with sum<=k is of length " << maxLen << " below" << endl;
    for (int i = storeL; i <= storeR; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    vector<int> arr = {10, 5, 1, 7, 10};
    cout << "before calling function " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    solve(arr, 14);
    // cout << endl;
    // cout << "after calling function " << endl;
    // for (auto i : arr)
    // {
    //     cout << i << " ";
    // }
    // return 0;
}