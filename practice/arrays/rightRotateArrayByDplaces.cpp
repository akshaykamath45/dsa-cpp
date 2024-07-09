#include <bits/stdc++.h>
using namespace std;

void rotateArray(vector<int> &arr, int d)
{
    vector<int> temp;
    int n = arr.size();
    d = d % n;
    // store last d elements in temp
    for (int i = n - d; i < n; i++)
    {
        temp.push_back(arr[i]);
    }
    cout << "temp array" << endl;
    for (auto i : temp)
    {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 0; i < n - d; i++)
    {
        arr[i + d] = arr[i];
    }
    for (int i = 0; i < n - d; i++)
    {
        arr[6] = arr[3];
    }
    // shift remaining elements by d places
    cout << "after shifting n-d elements right in the array" << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    // add temp elements (last d elements) in arr
    for (int i = 0; i < d; i++)
    {
        arr[i] = temp[i];
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int n = arr.size();
    cout << "before rotation " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    rotateArray(arr, 3);
    cout << "after rotation " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}