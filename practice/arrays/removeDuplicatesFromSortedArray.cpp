#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// mine solution brute force, using hash map
// int removeDuplicates(vector<int> &nums)
// {
//     int count = 0;
//     int n = nums.size();
//     map<int, int> hash;
//     vector<int> ans;
//     cout << endl
//          << "Before inserting" << endl;
//     cout << "ans array : ";
//     for (auto i : ans)
//     {
//         cout << i << " ";
//     }
//     cout << endl;
//     cout << "hash array : ";
//     for (auto i : hash)
//     {
//         cout << i.first << " ";
//     }
//     cout << endl;
//     for (int i = 0; i < n; i++)
//     {
//         hash[nums[i]++];
//     }
//     for (auto i : hash)
//     {
//         ans.push_back(i.first);
//     }
//     cout << "After inserting" << endl;
//     cout << "ans array : ";
//     for (auto i : ans)
//     {
//         cout << i << " ";
//     }
//     cout << endl;
//     cout << "hash array : ";
//     for (auto i : hash)
//     {
//         cout << i.first << " ";
//     }

//     for (int i = 0; i < ans.size(); i++)
//     {
//         nums[i] = ans[i];
//     }
//     cout << endl
//          << "original nums array " << endl;
//     for (auto i : nums)
//     {
//         cout << i << " ";
//     }
//     return ans.size();
// }

// better apporach using 2 pointer

int removeDuplicates(vector<int> &arr)
{
    int i = 0;
    int n = arr.size();
    for (int j = i + 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
            // arr[i + 1] = arr[j];
            // i++;
        }
    }
    return i + 1;
}
int main()
{
    vector<int> arr = {1, 1, 2};
    cout << "original array : ";
    for (auto i : arr)
    {
        cout << i << " ";
    }
    int ans = removeDuplicates(arr);
    cout << endl
         << "Ans is " << ans << endl;
    return 0;
}