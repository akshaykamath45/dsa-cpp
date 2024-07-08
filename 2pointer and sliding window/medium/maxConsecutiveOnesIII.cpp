// tip - find the longest subarray with atmost k zeroes

// brute force - generate all subarrays,if countZeros exceeds k break, else keep updating maxLen
int longestOnes(vector<int> &nums, int k)
{
    int n = nums.size();
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        int countZeros = 0;
        for (int j = i; j < n; j++)
        {
            if (nums[j] == 0)
            {
                countZeros++;
            }
            if (countZeros <= k)
            {
                maxLen = max(maxLen, j - i + 1);
            }
            else
            {
                break;
            }
        }
    }

    return maxLen;
}

// better - using sliding window, if countZeros > k , increase l ,also if arr[l]==0 countZeros-- to maintain the correct count
int longestOnes(vector<int> &nums, int k)
{
    int n = nums.size();
    int l = 0;
    int r = 0;
    int maxLen = 0;
    int zeros = 0;
    while (r < n)
    {
        if (nums[r] == 0)
        {
            zeros++;
        }
        while (zeros > k) // use if to optimize this
        {
            if (nums[l] == 0)
            {
                zeros--;
            }
            l++;
        }
        if (zeros <= k)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }

    return maxLen;
}