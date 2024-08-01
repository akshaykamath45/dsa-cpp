#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// time complexity - worst,avg,and best case :  O(N^2)
// no of comparisons = (n-1)+(n-2)+...1 ~ n(n+1)/2 =~O(N^2)
void selectionSort(vector<int> &arr)
{

    for (int i = 0; i < arr.size(); i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    vector<int> arr = {12, 18, 13, 6, 9, 4};

    selectionSort(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}