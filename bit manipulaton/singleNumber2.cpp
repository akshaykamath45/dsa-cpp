#include <bits/stdc++.h>

// brute force: using map data structure,calculating frequency of each number.

// 1st approach: better
// calculating the number of 1s for each bit index for all the numbers.
// if count%3==1,setting that bit in ans,initially ans=0.
// time complexity: O(N X 32) -> in all cases (worst,average,best).
// space complexity: O(1).
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int bitIndex = 0; bitIndex < 32; bitIndex++)
        {
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                // counting no of 1s - set bits
                if (nums[i] & (1 << bitIndex))
                {
                    count++;
                }
            }
            if (count % 3 == 1)
            {
                // setting the bits
                ans = ans | (1 << bitIndex);
            }
        }
        return ans;
    }
};

// 2nd approach: more better
// sorting and checking if number present at i and i-1 same or not,increasing i by 3 positions
// time complexity: O(N X log N) + N/3 -> better than previous one, worst case will be when number of elements will be 2^32 and log N =32
// space complexity: O(1).
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i += 3)
        {
            if (nums[i] != nums[i - 1])
            {
                return nums[i - 1];
            }
        }
        return nums[n - 1];
    }
};

// 3rd approach: optimal,need to remember
// using concept of buckets,finding the number that appears ones,twos and threes in the bucket using bitwise operations,no need for threes.
// nums[i] will go to ones,if not in twoes.
// nums[i] will go to twos,if not in ones.
// nums[i] will go to threes,if not in twoes. (Not needed here)
// return ones.
// concept of buckets: think of a smaller solution,which will eventually spread to bigger one.
// time complexity:
// space complexity: O(1).

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        int ones = 0;
        int twos = 0;
        for (int i = 0; i < n; i++)
        {
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
    }
};