#include <bits/stdc++.h>
using namespace std;

// brute force - little hardcoded
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int maxi = INT_MIN;
    int count = 0;
    if (nums.size() == 1 && nums[0] == 1)
    {
        return 1;
    }
    if (nums.size() == 1 && nums[0] == 0)
    {
        return 0;
    }
    if ((nums[0] == 0 && nums[1] == 0) && nums.size() == 2)
    {
        return 0;
    }
    for (int i = 1; i < nums.size(); i++)
    {
        if ((nums[i] && nums[i - 1]) == 1)
        {
            count++;
        }
        else
        {
            count = 0;
        }
        maxi = max(maxi, count);
    }
    return maxi + 1;
}

// better
int findMaxConsecutiveOness(vector<int> &nums)
{
    int n = nums.size();
    int j = 0;
    int maxi = INT_MIN;
    int count = 0;

    if (nums.size() == 1 && nums[0] == 1)
    {
        return 1;
    }
    if (nums.size() == 1 && nums[0] == 0)
    {
        return 0;
    }
    if ((nums[0] == 0 && nums[1] == 0) && nums.size() == 2)
    {
        return 0;
    }
    for (int i = 1; i < n; i++)
    {
        if ((nums[i] && nums[j]) == 1)
        {
            count++;
        }
        else
        {
            j = i;
            count = 0;
        }
        maxi = max(maxi, count);
    }
    return maxi + 1;
}

// optimal - the solution was simple :)
int findMaxConsecutiveOnesss(vector<int> &nums)
{
    int maxi = INT_MIN;
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            count++;
        }
        else
        {
            count = 0;
        }
        maxi = max(maxi, count);
    }
    return maxi;
}
int main()
{
    vector<int> arr = {1, 1, 0, 1, 1, 1};
    int ans = findMaxConsecutiveOnesss(arr);
    cout << "ans " << ans;
    return 0;
}