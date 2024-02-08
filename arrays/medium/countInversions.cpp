// count number of pairs (i,j) where i < j and arr[i]>arr[j]

// brute force: directly comparing
// time compexity : O(n^2)
// space complexity: O(1)
int numberOfInversions(vector<int> &a, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                count++;
            }
        }
    }
    return count;
}

// optimal: using merge sort
// splitting the array into 2 parts , cnt+=(mid-left+1)
// [2 3 4 6] [2,4,4,6,8]
// arr[left]=3
// arr[right]=2
// 3>2,so we can assume 4 and 6 will also be greater than 2,hence directly increase the final count for remaining elements
// to spilt the array , we use merge sort (divide and conquer)
// this is modifying the original array,tell the interviewer we can maintain a copy of original array,then do merge sort.

int cnt = 0;
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr

    // storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);

            left++;
        }
        // right is smaller
        else
        {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);      // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);    // merging sorted halves
}

int numberOfInversions(vector<int> &a, int n)
{
    mergeSort(a, 0, n - 1);
    return cnt;
}
