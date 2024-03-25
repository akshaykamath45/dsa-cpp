// Using binary search
int upperBound(vector<int> &arr, int x, int n)
{
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > x)
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
int upperBound(vector<int> &arr, int x, int n)
{
    int ub = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
    return ub;
}