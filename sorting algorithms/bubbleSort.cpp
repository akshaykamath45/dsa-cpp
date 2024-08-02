#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// time complexity - worst,avg O(N^2)
// best case - when array is sorted,no swaps needed O(N)

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    vector<int> arr = {12, 18, 13, 6, 9, 4};
    bubbleSort(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}