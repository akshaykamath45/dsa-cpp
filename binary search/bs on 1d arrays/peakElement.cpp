// brute force
class Solution
{
public:
    int findPeakElement(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if ((i == 0 || arr[i - 1] < arr[i]) && (i == n - 1 || arr[i] > arr[i + 1]))
            {
                return i;
            }
        }
        return -1;
    }
};

// better: using binary search

class Solution
{
public:
    int findPeakElement(vector<int> &arr)
    {
        int n = arr.size();

        // handling edge cases
        // if array contains one element
        if (n == 1)
        {
            return 0;
        }

        // if peak element is first - [1,2,3,4,5]
        if (arr[n - 1] > arr[n - 2])
        {
            return n - 1;
        }

        // if peak element is first - [5,4,3,2,1]
        if (arr[0] > arr[1])
        {
            return 0;
        }
        int low = 1;
        int high = n - 2;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                return mid;
            }
            else if (arr[mid] > arr[mid - 1])
            {                  // we are on the increasing curve
                low = mid + 1; // peak element is on right
            }
            else if (arr[mid] > arr[mid + 1])
            {                   //  we are on the decreasing curve
                high = mid - 1; // peak element is on left
            }
            else
            {
                high = mid - 1; // for multiple peaks, eg - [1,5,1,2,1] , if mid is on 1 , it will run into infinite loop , for this we can move either right/left,we will get one peak
                // low=mid+1;
            }
        }
        return -1; // just a hypothetical scenario since the return type is int
    }
};