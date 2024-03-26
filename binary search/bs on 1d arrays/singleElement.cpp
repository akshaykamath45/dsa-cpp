int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size();
    int low = 1;
    int high = n - 2;

    // edge cases

    // if contains only 1 element
    if (n == 1)
    {
        return arr[0];
    }
    // element on first index
    if (arr[0] != arr[1])
    {
        return arr[0];
    }
    // element on last index
    if (arr[n - 1] != arr[n - 2])
    {
        return arr[n - 1];
    }
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
        {
            return arr[mid];
        }
        if ((((mid % 2) == 1) && arr[mid - 1] == arr[mid]) or
            ((mid % 2 == 0) && arr[mid] == arr[mid + 1]))
        {                  // we are on left half
            low = mid + 1; // element is on right half
        }
        else
        {                   // we are on right half
            high = mid - 1; // element is on left hald
        }
    }
    return -1;
}