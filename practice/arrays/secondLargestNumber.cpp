#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// better code
int print2largest(int arr[], int n)
{
    int firstLargest = -1;
    int maxi = -1;
    int secondLargest = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > firstLargest)
        {
            firstLargest = arr[i];
            maxi = arr[i];
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (arr[j] > secondLargest && arr[j] < maxi)
        {
            secondLargest = arr[j];
        }
    }
    return secondLargest;
}

// optimal code
int print2largestOptimal(int arr[], int n)
{
    int firstLargest = -1;
    int secondLargest = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > firstLargest)
        {
            secondLargest = firstLargest;
            firstLargest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] < firstLargest)
        {
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}
int main()
{
    int arr[] = {1, 2, 4, 7, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int sL = print2largestOptimal(arr, n);

    cout << "Second largest is " << sL << endl;
    return 0;
}
