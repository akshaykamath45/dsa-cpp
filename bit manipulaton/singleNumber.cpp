int missingNumber(int n, vector<int> &arr)
{
    int ans = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}