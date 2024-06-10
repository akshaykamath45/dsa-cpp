#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// brute force - using hash map
int singleNumber(vector<int> &nums)
{
    int n = nums.size();
    map<int, int> hash;
    for (int i = 0; i < n; i++)
    {
        hash[nums[i]]++;
    }
    for (auto i : hash)
    {
        if (i.second == 1)
        {
            return i.first;
            break;
        }
    }
    return -1;
}

// optimal - using xor
int singleNumber2(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans ^= nums[i];
    }
    return ans;
}
int main()
{
    vector<int> nums = {4, 1, 2, 1, 2};
    int ans = singleNumber2(nums);
    cout << "ans " << ans;
    return 0;
}