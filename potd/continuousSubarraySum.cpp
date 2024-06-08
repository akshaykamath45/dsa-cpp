#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool checkIsMultiple(int sum, int k)
{
    if (sum % k == 0)
    {
        return true;
    }
    return false;
}

// brute
bool checkSubarraySum(vector<int> &nums, int x)
{

    int n = nums.size();
    cout << "printting subarrays" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {

                sum += nums[k];
                cout << nums[k] << " ";
            }
            bool answer = checkIsMultiple(sum, x);
            if (answer)
            {
                return true;
            }
            cout << "sum " << sum << endl;
        }
    }

    return false;
}

// better
bool checkSubarraySum(vector<int> &nums, int x)
{
    int n = nums.size();
    cout << "printting subarrays" << endl;
    for (int i = 0; i < n; i++)
    {
        int sum = nums[i];
        for (int j = i + 1; j < n; j++)
        {
            sum += nums[j];
            cout << nums[j] << " ";
            bool answer = checkIsMultiple(sum, x);
            if (answer)
            {
                return true;
            }
        }
        cout << "sum " << sum << endl;
    }
    return false;
};

// optimal
bool checkSubarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> remainderMap;
    remainderMap[0] = -1;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        int remainder = sum % k;
        if (remainder < 0)
            remainder += k;
        if (remainderMap.find(remainder) != remainderMap.end())
        {
            if (i - remainderMap[remainder] > 1)
            {
                return true;
            }
        }
        else
        {
            remainderMap[remainder] = i;
        }
    }
    return false;
};
int main()
{
    vector<int> nums = {23, 6, 9};
    bool ans = checkSubarraySum(nums, 6);
    cout << "ans " << ans;
    return 0;
}