#include <bits/stdc++.h>
using namespace std;

void leftRotateArrayByDPlaces(vector<int> &arr, int n, int d)
{
    d = d % n;
    vector<int> temp;
    // pushing 1st d elements in temp array
    // temp= [1 2 3]
    for (int i = 0; i < d; i++)
    {
        temp.push_back(arr[i]);
    }
    // shifting last n-d elements left
    /// arr=[4 5 6 _ _ _ ]
    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }
    // pushing elements from temp (containing 1st d elements) to arr
    // arr=[4 5 6 1 2 3 ]
    for (int i = n - d; i < n; i++)
    {
        arr[i] = temp[i - (n - d)];
    }
}

// optimal solution - using reverse
void leftRotateArrayByD(vector<int> &arr, int n, int d)
{
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int n = arr.size();
    cout << "before rotation " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    leftRotateArrayByD(arr, n, 4);
    cout << endl;
    cout << "after rotation " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}