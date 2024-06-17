class Solution
{
public:
    int maxProfit(vector<int> &arr)
    {
        int n = arr.size();
        int mini = arr[0];
        int maxProfit = 0;
        for (int i = 0; i < n; i++)
        {
            int cost = arr[i] - mini;
            maxProfit = max(cost, maxProfit);
            mini = min(mini, arr[i]);
        }
        return maxProfit;
    }
};