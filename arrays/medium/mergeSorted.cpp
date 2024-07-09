#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            ans.push_back(nums1[i]);
            i++;
        }
        else
        {
            ans.push_back(nums2[j]);
            j++;
        }
    }
    while (i < m)
    {
        ans.push_back(nums1[i]);
        i++;
    }
    while (j < n)
    {
        ans.push_back(nums2[j]);
        j++;
    }

    // ans array
    cout << "ans array " << endl;
    for (auto i : ans)
    {
        cout << i << " ";
    }
    for (int i = 0; i < ans.size(); i++)
    {
        nums1[i] = ans[i];
    }
};

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    cout << "before merging " << endl;
    for (auto i : nums1)
    {
        cout << i << " ";
    }
    cout << endl;

    merge(nums1, 3, nums2, 3);
    cout << endl;
    cout
        << "after merging " << endl;
    for (auto i : nums1)
    {
        cout << i << " ";
    }

    return 0;
}