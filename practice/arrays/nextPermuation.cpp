#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr)
{
    int n = arr.size();
    next_permutation(arr.begin(), arr.end());
}

void solve1(vector<int> &arr)
{
    int n = arr.size();
    int index = -1;
    // find the index, where arr[i]<arr[i+1]
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            index = i;
            break;
        }
    }
    // for (int i = 0; i < n - 1; i++)
    // {
    //     if (arr[i] < arr[i + 1])
    //     {
    //         index = i;
    //         break;
    //     }
    // }
    cout << endl;
    cout << "first index " << index << " element " << arr[index];

    // smallest value greater than arr[index]
    cout << endl;
    for (int j = n - 1; j > index; j--)
    {
        if (arr[j] > arr[index])
        {
            int storeSwap = j;
            cout << "swapping index " << storeSwap << " element " << arr[storeSwap];
            swap(arr[storeSwap], arr[index]);
            break;
        }
    }
    // sort remaining part by reversing/sorting
    reverse(arr.begin() + index + 1, arr.end());

    if (index == -1)
    {
        reverse(arr.begin(), arr.end());
    }
}
int main()
{
    vector<int> arr = {1, 1, 5};
    cout << "before calling function " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    solve1(arr);
    cout << endl;
    cout << "after calling function " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}