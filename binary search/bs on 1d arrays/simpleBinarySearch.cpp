// iterative code
// time complexity: O(log N)
int search(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (target > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

// recursive code
int bs(vector<int> &arr, int low, int high, int target)
{
    if (low > high)
    {
        return -1;
    }
    if (arr.size() == 1 && target != arr[0])
    {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (target > arr[mid])
    {
        return bs(arr, mid + 1, high, target);
    }
    return bs(arr, low, mid - 1, target);
}

int search(vector<int> &arr, int target)
{

    int ans = bs(arr, 0, arr.size(), target);
    return ans;
}