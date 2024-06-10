#include <bits/stdc++.h>
using namespace std;

// brute force
int heightChecker(vector<int> &heights)
{
    vector<int> actual = heights;
    int count = 0;
    int n = heights.size();
    // sorting height, becomes the expected height
    sort(heights.begin(), heights.end());
    for (int i = 0; i < n; i++)
    {
        if (heights[i] != actual[i])
        {
            count++;
        }
    }
    return count;
}
int main()
{
    vector<int> heights = {1, 1, 4, 2, 1, 3};
    int ans = heightChecker(heights);
    cout << "ans " << ans;
    return 0;
}