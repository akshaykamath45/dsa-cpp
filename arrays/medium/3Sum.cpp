#include <bits/stdc++.h>

// brute force: using 3 pointer approach
// we use set to store unique triplets
// add sorted vector to set
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

//  better: using hashing/hashset
//  arr[i]+arr[j] + arr[k]=0
//  third element : arr[k]=-(arr[i]+arr[j])
//  hashset would contain j-1 elements,between i and j,not itself,increasing gradually
//  will use 2 loops,check if the third element is present in hashset , if yes,then add to ans set
//  add next element to hashet
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // set so that all are unique
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            int third = -(arr[i] + arr[j]);
            // if its not pointing towards end,then its there in hashset
            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// optimal:using 2 pointer approach
// sort the array
// three pointers i,j,k
// i->left
// j->mid (i+1)
// k->right
// 3 conditons : if(sum<0) : j++, else if (sum>0) : k-- , else sum=0 , store the ans,j++ && k--
// since array is sorted,move i to the next greatest element,similar for j and k
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
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
                j += 1;
            }
            else if (sum > 0)
            {
                k -= 1;
            }
            else // if sum = 0
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j += 1;
                k -= 1;
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
    return ans;
}
