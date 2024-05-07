int firstOccurence(vector<int> &arr)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int first = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= 1)
        {
            first = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return first;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int index = -1;
    int maxi = -1;
    for (int i = 0; i < n; i++)
    {
        int firstOcc = firstOccurence(matrix[i]);
        int rowCount = (firstOcc == -1) ? 0 : m - firstOcc;
        if (rowCount > maxi)
        {
            maxi = rowCount;
            index = i;
        }
    }
    return index;
}
