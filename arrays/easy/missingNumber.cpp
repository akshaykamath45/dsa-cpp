#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// brute force - sorting and checking
int missingNumber(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != i)
        {
            return i;
            break;
        }
    }
    return n;
}

// optimal - using formula
int missingNumber2(vector<int> &arr)
{
    int n = arr.size();
    int actualSum = n * (n + 1) / 2;
    int originalSum = 0;
    for (int i = 0; i < n; i++)
    {
        originalSum += arr[i];
    }
    return actualSum - originalSum;
}

// optimal - using xor
int missingNumber3(vector<int> &arr)
{
    int xor1 = 0;
    int xor2 = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        xor1 ^= arr[i];
    }
    cout << "xor1 " << xor1 << endl;
    for (int i = 0; i <= n; i++)
    {
        xor2 ^= i;
    }
    cout << "xor2 " << xor2 << endl;
    int ans = xor1 ^ xor2;
    return ans;
}

int main()
{
    vector<int> nums = {0, 1, 2, 4};
    int ans = missingNumber3(nums);
    cout << "ans " << ans;
    return 0;
}