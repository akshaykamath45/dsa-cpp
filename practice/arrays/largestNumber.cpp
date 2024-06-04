#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int largestNumber(vector<int> &arr, int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }
    return maxi;
}
int main()
{
    vector<int> arr = {14, 34, 76, 4, 89};
    int n = arr.size();
    int maxi = largestNumber(arr, n);
    cout << maxi;
    return 0;
}