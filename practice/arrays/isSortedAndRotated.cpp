#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// mine approach - passes 50% test case
bool check(vector<int> &arr)
{
    int n = arr.size();
    bool ans = true;
    // to check rotated
    vector<int> arr2;
    for (int i = 0; i < n; i++)
    {
        arr2.push_back(arr[i]);
    }
    cout << "before checking for rotation" << endl;
    cout << "arr" << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl
         << "arr2" << endl;
    for (auto i : arr2)
    {
        cout << i << " ";
    }
    reverse(arr2.begin(), arr2.end());
    reverse(arr2.begin(), arr2.begin() + n / 2);
    reverse(arr2.begin() + n / 2, arr2.end());
    sort(arr.begin(), arr.end());
    cout << endl
         << "After checking for rotation" << endl;
    cout << "arr" << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl
         << "arr2" << endl;
    for (auto i : arr2)
    {
        cout << i << " ";
    }
    if (arr2 == arr)
    {
        ans = true;
    }

    cout << "before checking for sorting";
    // to check sorted
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            ans = false;
        }
    }
    return ans;
}

// optimal approach using formula
class Solution
{
public:
    bool check(vector<int> &arr)
    {
        int n = arr.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > arr[(i + 1) % n])
            {
                count++;
            }
        }

        return count <= 1;
    }
};
int main()
{
    vector<int> arr = {2, 1, 3, 4};
    int n = arr.size();
    bool ans = check(arr);
    cout << ans;
    return 0;
}