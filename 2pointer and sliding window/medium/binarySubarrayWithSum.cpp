// brute force - generate all subarrays
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    int count = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum == goal)
            {
                count++;
            }
        }
    }

    return count;
}


// sliding window