class Solution
{
    bool possible(vector<int> &arr, int capacity, int days)
    {
        int n = arr.size();
        int sum = 0;
        int day = 1;
        for (int i = 0; i < n; i++)
        {
            if (sum + arr[i] > capacity)
            {
                sum = arr[i];
                day++;
            }
            else
            {
                sum += arr[i];
            }
        }
        if (day <= days)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int max = *max_element(weights.begin(), weights.end());
        int sum = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            sum += weights[i];
        }
        int low = max;
        int high = sum;
        int ans = high;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (possible(weights, mid, days))
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