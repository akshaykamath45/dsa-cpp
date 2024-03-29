class Solution
{
public:
    bool possible(vector<int> &arr, int divisor, int threshold)
    {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += ceil((double)arr[i] / (double)divisor);
        }
        if (sum <= threshold)
        {
            return true;
        }
        return false;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int n = nums.size();
        if (n > threshold)
        {
            return -1;
        }
        long int mini = *min_element(nums.begin(), nums.end());
        long int maxi = *max_element(nums.begin(), nums.end());
        long int low = 1;
        long int high = maxi;
        long int ans = maxi;
        while (low <= high)
        {
            long int mid = low + (high - low) / 2;
            long int isPossible = possible(nums, mid, threshold);
            if (isPossible)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};