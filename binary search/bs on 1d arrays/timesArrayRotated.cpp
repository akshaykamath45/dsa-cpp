// we find the index of the minimum element,which would directly give us the number of times array has rotated
#include <bits/stdc++.h>
int findKRotation(vector<int> &arr)
{

    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int index = -1;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[low] <= arr[high])
        {
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }
            break;
        }
        if (arr[low] <= arr[mid])
        {
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }
            low = mid + 1;
        }
        else
        {
            if (arr[mid] < ans)
            {
                index = mid;
                ans = arr[mid];
            }
            high = mid - 1;
        }
    }
    return index;
}