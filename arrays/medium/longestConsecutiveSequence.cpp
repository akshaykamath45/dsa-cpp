// brute force - on my own, doesn't pass last few test cases, but good to solve on own
// time and space complexity ☠️☠️

int longestConsecutive(vector<int> &arr)
{
    int maxLen = 0;
    int n = arr.size();
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }

    vector<int> arr2(st.begin(), st.end());
    int n2 = arr2.size();
    sort(arr2.begin(), arr2.end());
    for (int i = 0; i < n2; i++)
    {
        int count = 0;
        for (int j = i; j < n2 - 1; j++)
        {
            if (arr2[j] == (arr2[j + 1] - 1))
            {
                count++;
                maxLen = max(maxLen, count);
            }
            else
            {
                break;
            }
        }
    }
    return maxLen + 1;
};

// better - finding the longest subbarray with atmost k (2) zeroes
// sliding window
// if zeros > k, check if arr[l]==0 -> countZeroes-- ( to balance out the count) ,  move l++
int longestOnes(vector<int> &nums, int k)
{
    int n = nums.size();
    int l = 0;
    int r = 0;
    int maxLen = 0;
    int zeros = 0;
    while (r < n)
    {
        if (nums[r] == 0)
        {
            zeros++;
        }
        if (zeros > k)
        {
            if (nums[l] == 0)
            {
                zeros--;
            }
            l++;
        }
        if (zeros <= k)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }

    return maxLen;
}