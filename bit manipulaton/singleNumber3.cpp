// brute force: hashing,using map data structure.

// better approach:
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        while (i < n)
        {
            if (i == n - 1 || nums[i] != nums[i + 1])
            {
                ans.push_back(nums[i]);
                i++;
            }
            else
            {
                i += 2;
            }
        }
        return ans;
    }
};

// optimal approach:using concept of buckets.
// time complexity: O(2N)->O(N).
// space complexity:O(1).
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        long int xorr = 0;
        long int b1 = 0;
        long int b2 = 0;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            xorr = xorr ^ nums[i];
        }
        int rightMost = (xorr & (xorr - 1)) ^ xorr;
        for (int i = 0; i < n; i++)
        {
            if ((nums[i] & rightMost) != 0)
            {
                b1 ^= nums[i];
            }
            else
            {
                b2 ^= nums[i];
            }
        }
        ans.push_back(b1);
        ans.push_back(b2);
        return ans;
    }
};