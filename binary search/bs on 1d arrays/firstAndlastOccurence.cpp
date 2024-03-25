// using upper and lower bound
class Solution
{
public:
    int lowerBound(vector<int> arr, int x, int n)
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
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int lb = lowerBound(nums, target, n);
        if (lb == n || nums[lb] != target)
            return {-1, -1};
        int ub = upperBound(nums, target, n);
        return {lb, ub - 1};
    }
};

// Using binary search directly
int firstOccurence(vector<int> &arr, int x)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int first = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return first;
}

int lastOccurence(vector<int> &arr, int x)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int last = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return last;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    int first = firstOccurence(arr, k);
    if (first == -1)
    {
        return {-1, -1};
    }
    int last = lastOccurence(arr, k);

    return {first, last};
}
