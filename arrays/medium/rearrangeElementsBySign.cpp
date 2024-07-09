#include <bits/stdc++.h>
using namespace std;
vector<int> rearrangeArray(vector<int> &arr)
{
    vector<int> positive;
    vector<int> negative;
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > 0)
        {
            positive.push_back(arr[i]);
        }
        else
        {
            negative.push_back(arr[i]);
        }
    }
    int n = arr.size();
    // positive array
    cout << "positives " << endl;
    for (auto i : positive)
    {
        cout << i << " ";
    }
    cout << endl;
    // negative array
    cout << "negatives " << endl;
    for (auto i : negative)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        ans.push_back(positive[i]);
        ans.push_back(negative[i]);
    }
    // for (int i = 1; i < n; i++)
    // {
    //     ans[i] = negative[i];
    // }
    return ans;
}

int main()
{
    vector<int> arr = {3, 1, -2, -5, 2, -4};
    cout << "before rearranging" << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> ans = rearrangeArray(arr);
    cout << "after rearranging " << endl;
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}