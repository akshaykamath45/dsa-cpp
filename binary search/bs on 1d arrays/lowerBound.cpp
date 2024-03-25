// Using binary search
int lowerBound(vector<int> arr, int n, int x)
{
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x)
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

// Using C++ STL Library
int lowerBound(vector<int> arr, int n, int x)
{
    int lb = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    return lb;
}
