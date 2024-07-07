// find max sum of 4 elements consecutively

// 2 pointer approach
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int k)
{
    int n = arr.size();
    int l = 0;
    int r = k - 1;
    int maxSum = INT_MIN;
    int sum = 0;
    int storeL = -1;
    int storeR = -1;
    for (int i = l; i <= r; i++)
    {
        sum += arr[i];
    }
    maxSum = sum;
    while (r < n)
    {

        if (sum > maxSum)
        {
            maxSum = sum;
            storeL = l ;
            storeR = r ;
        }
        sum -= arr[l];
        l++;
        r++;
        sum += arr[r];
    }
    cout << endl
         << "subarray with " << k << " consecutives with max sum " << maxSum << endl;
    for (int i = storeL; i <= storeR; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    vector<int> arr = {-1, 2, 3, 3, 4, 5, -1};
    cout << "before calling function " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    solve(arr, 4);
    cout << endl;
    // cout << "after calling function " << endl;
    // for (auto i : arr)
    // {
    //     cout << i << " ";
    // }
    return 0;
}
