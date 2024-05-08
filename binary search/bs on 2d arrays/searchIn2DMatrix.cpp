// brute force approach: directly travers the rows and columns

// better approach: using binary search
bool binarySearch(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return true;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    if (rows == 0)
        return false;
    int cols = matrix[0].size();
    if (target < matrix[0][0] || target > matrix[rows - 1][cols - 1])
    {
        return false;
    }
    for (int i = 0; i < rows; i++)
    {
        if (target >= matrix[i][0] && target <= matrix[i][cols - 1])
        {
            if (binarySearch(matrix[i], target))
            {
                return true;
            }
        }
    }
    return false;
}

// optimised apporach: flattening 2d into 1d array

bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int n = mat.size();
    int m = mat[0].size();
    int low = 0;
    int high = n * m - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int row = mid / m;
        int col = mid % m;
        if (mat[row][col] == target)
        {
            return true;
        }
        else if (mat[row][col] <= target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}