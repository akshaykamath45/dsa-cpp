#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    // i need to place smaller elements on the left of pivot and greater elements on the right of pivot
    while (i < j)
    {
        // pick the first index on left where arr[i] is greater (>) than pivot
        while (arr[i] <= pivot && i <= high)
        {
            i++;
        }
        // pick the first index where arr[j] is smaller (<) than pivot
        while (arr[j] > pivot && j >= low)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
    }
}

int main()
{
    vector<int> arr = {13, 46, 24, 2, 20, 9};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
    ;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}