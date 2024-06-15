#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// brute force - using 3 pointers
vector<vector<int>> solve(vector<int> &arr)
{
    set<vector<int>> st;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if ((arr[i] + arr[j] + arr[k]) == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    // to avoid duplicates
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// better using hashset
vector<vector<int>> solve1(vector<int> &arr)
{

    set<vector<int>> st;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            int k = -(arr[i] + arr[j]);
            if (hashset.find(k) != hashset.end()) // checks if present in hashset
            {
                vector<int> temp = {arr[i], arr[j], k};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// optimal using 2 pointers
vector<vector<int>> solve2(vector<int> &arr)
{
    set<vector<int>> st;

    sort(arr.begin(), arr.end());
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            { // sum==0
                vector<int> temp = {arr[i], arr[j], arr[k]};
                st.insert(temp);
                j++;
                k--;
                while (j < k && arr[j] == arr[j - 1])
                {
                    j++;
                }
                while (j < k && arr[k] == arr[k + 1])
                {
                    k--;
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    cout << "before calling function " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    vector<vector<int>> ans = solve2(arr);
    cout << endl;
    cout << "after calling function " << endl;
    int n = ans.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}