class Solution
{
public:
    bool possible(vector<int> &arr, int day, int m, int k)
    {
        int count = 0;
        int noOfBouquet = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= day)
            {
                count++;
            }
            else
            {
                noOfBouquet += (count / k);
                count = 0;
            }
        }
        noOfBouquet += (count / k);
        if (noOfBouquet >= m)
        {
            return true;
        }
        return false;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int n = bloomDay.size();
        long long val = m * 1LL * k * 1LL;
        if (n < val)
        {
            return -1;
        }
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, bloomDay[i]);
            mini = min(mini, bloomDay[i]);
        }
        int low = mini;
        int high = maxi;
        int ans = high;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (possible(bloomDay, mid, m, k))
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