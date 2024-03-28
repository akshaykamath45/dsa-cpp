// brute force
class Solution
{
public:
    long long func(vector<int> &arr, int mid)
    {
        long long totalHrs = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            totalHrs += ceil((double)arr[i] / (double)mid);
        }
        return totalHrs;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();
        int maxPiles = *max_element(piles.begin(), piles.end());
        int ans = 1;
        for (int i = 1; i <= maxPiles; i++)
        {
            int totalHrs = func(piles, i);
            if (totalHrs <= h)
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

// better: using binary search
class Solution
{
public:
    long long func(vector<int> &arr, int mid)
    {
        long long totalHrs = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            totalHrs += ceil((double)arr[i] / (double)mid);
        }
        return totalHrs;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();
        int maxPiles = *max_element(piles.begin(), piles.end());
        int ans = 1;
        int low = 1;
        int high = maxPiles;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            long long totalHrs = func(piles, mid);
            if (totalHrs <= h)
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