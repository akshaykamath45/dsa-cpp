#include <bits/stdc++.h>
using namespace std;

// brute force - create  a  single set , insert elements of arr1 and arr2
vector<int> removeDuplicates(vector<int> &arr)
{
    vector<int> ans;
    int n = arr.size();
    map<int, int> hash;
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    for (auto i : hash)
    {
        ans.push_back(i.first);
    }
    return ans;
}

// optimal approach
vector<int> findUnion(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    vector<int> ans;
    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
        }
        else
        {
            ans.push_back(arr2[j]);
            j++;
        }
    }
    // check if remaining elements left in each array
    while (i < n)
    {
        ans.push_back(arr1[i]);
        i++;
    }
    while (j < m)
    {
        ans.push_back(arr2[j]);
        j++;
    }
    vector<int> finalAns = removeDuplicates(ans);
    return finalAns;
}
int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5};
    int n = arr1.size();
    vector<int> arr2 = {
        1,
        2,
        3,
    };
    int m = arr2.size();
    vector<int> ans = findUnion(arr1, arr2, n, m);
    cout << "union of 2 sorted arrays" << endl;
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}