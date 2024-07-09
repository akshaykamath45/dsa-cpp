#include <bits/stdc++.h>
using namespace std;

// brute force
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    set<int> st;
    int n = nums1.size();
    int m = nums2.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (nums1[i] == nums2[j])
            {
                st.insert(nums1[i]);
            }
        }
    }
    for (auto i : st)
    {
        ans.push_back(i);
    }
    return ans;
}

// optimal
vector<int> intersectionOf2Arrays(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> ans;
    int n = arr1.size();
    int m = arr2.size();
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
            i++;
        }
        else
        {
            j++;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    cout << "after intersection: " << endl;
    vector<int> ans = intersectionOf2Arrays(nums1, nums2);
    cout << "final ans" << endl;
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}