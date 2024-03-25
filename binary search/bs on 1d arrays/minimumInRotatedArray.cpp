// for unique values
class Solution
{
public:
    int findMin(vector<int> &arr)
    {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int ans = INT_MAX;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            // optimization: if search space is already sorted,then always arr[low] will be smaller
            if (arr[low] <= arr[high])
            {
                ans = min(ans, arr[low]);
                break;
            }
            if (arr[low] <= arr[mid])
            {                             // left half is sorted
                ans = min(ans, arr[low]); // compare and pick the minimum
                low = mid + 1;            // search in right half
            }
            else
            {                             // right half is sorted
                ans = min(ans, arr[mid]); // compare and pick the minimum
                high = mid - 1;           // search in left half
            }
        }
        return ans;
    }
}

// for duplicate values
class Solution
{
public:
    int findMin(vector<int> &arr)
    {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int ans = INT_MAX;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            // we will shrink the search space
            if (arr[low] == arr[mid] && arr[mid] == arr[high])
            {
                ans = min(ans, arr[high]);
                low++;
                high--;
                continue;
            }

            if (arr[low] <= arr[mid])
            {                             // left half is sorted
                ans = min(ans, arr[low]); // compare and pick the minimum
                low = mid + 1;            // search in right half
            }
            else
            {                             // right half is sorted
                ans = min(ans, arr[mid]); // compare and pick the minimum
                high = mid - 1;           // search in left half
            }
        }
        return ans;
    }
};