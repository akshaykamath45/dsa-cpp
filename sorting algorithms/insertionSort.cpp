#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// time complexity - worst,avg O(N^2)
// best case - when array is sorted,no swaps needed O(N)

void insertionSort(vector<int> &arr)
{

    for (int i = 1; i < arr.size(); i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

int main()
{
    vector<int> arr = {12, 18, 13, 6, 9, 4};
    insertionSort(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}