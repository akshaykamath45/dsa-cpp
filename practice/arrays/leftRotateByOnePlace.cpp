#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
void rotateArray(vector<int> &arr, int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int n = arr.size();
    cout << "before rotation" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    rotateArray(arr, n);
    cout << "after rotation" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}