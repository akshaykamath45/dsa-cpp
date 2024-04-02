// brute force
bool canWePlace(vector<int> &arr, int distance, int cows)
{
    int countCows = 1;
    int last = arr[0];
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] - last >= distance)
        {
            countCows++;
            last = arr[i];
        }
    }
    if (countCows >= cows)
    {
        return true;
    }
    return false;
}
int aggressiveCows(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int high = arr[n - 1] - arr[0];
    int ans = -1;
    for (int i = 1; i <= high; i++)
    {
        if (canWePlace(arr, i, k))
        {
            ans = i;
        }
        else
        {
            break;
        }
    }
    return ans;
}


// better: using binary search
bool canWePlace(vector<int> &arr, int distance, int cows)
{
    int countCows = 1;
    int last = arr[0];
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] - last >= distance)
        {
            countCows++;
            last = arr[i];
        }
    }
    if (countCows >= cows)
    {
        return true;
    }
    return false;
}
int aggressiveCows(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int low = 0;
    int high = arr[n - 1] - arr[0];
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canWePlace(arr, mid, k))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}