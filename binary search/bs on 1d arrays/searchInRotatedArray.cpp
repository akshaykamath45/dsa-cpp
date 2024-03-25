class Solution
{
public:
    int search(vector<int> &arr, int target)
    {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] == target)
            {
                return mid;
            }
            if (arr[low] <= arr[mid])
            { // left half is sorted
                if (arr[low] <= target && target <= arr[mid])
                { // check if element is already there in sorted left half
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1; // search in unsorted right half
                }
            }
            else
            { // right half is sorted
                if (arr[mid] <= target && target <= arr[high])
                { // check if element is already present in sorted right half
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1; // search in unsorted left half
                }
            }
        }
        return -1;
    }
};