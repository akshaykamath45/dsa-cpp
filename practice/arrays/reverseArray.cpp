#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr, int n)
{
    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}
void reverseArrayInIntervals(vector<int> &arr , int startIndex, int endIndex)
{
    while (startIndex <= endIndex)
    {
        swap(arr[startIndex], arr[endIndex]);
        startIndex++;
        endIndex--;
    }
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    cout << "before reversing" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // reverseArray(arr, n);
    reverseArrayInIntervals(arr, 0, 2);
    cout << "after reversing" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}