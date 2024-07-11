// extreme brute force

int totalFruits(int N, vector<int> &arr)
{
    int maxLen = 0;
    for (int i = 0; i < N; ++i)
    {
        int count = 0;
        int pick1 = arr[i];
        int pick2 = -1;

        for (int j = i; j < N; ++j)
        {
            if (arr[j] == pick1 || (pick2 == -1 || arr[j] == pick2))
            {
                count++;
                if (arr[j] != pick1)
                {
                    pick2 = arr[j];
                }
            }
            else
            {
                break;
            }
        }

        maxLen = max(maxLen, count);
    }
    return maxLen;
}

// brute force
// using set, insert the element in set, if set size > 2 break, maintain the maxLen
// sc will be O(log 2) ~ 1 // since we are storing only 2 elements in the set
// tc will be O(N^2)
int totalFruits(int N, vector<int> &arr)
{
    int maxLen = 0;

    for (int i = 0; i < N; ++i)
    {
        set<int> st;
        for (int j = i; j < N; j++)
        {
            st.insert(arr[j]);
            if (st.size() > 2)
            {
                break;
            }
            maxLen = max(maxLen, j - i + 1);
        }
    }

    return maxLen;
}


// better - using sliding window and hashmap
// add elements into hashmap
// if size exceeds 2 , remove elements from hashmap, until the size becomes 2, and increase l
// update maxLen
int totalFruits(int N, vector<int> &arr)
{
    int maxLen = 0;
    int l = 0;
    int r = 0;
    map<int, int> mpp;
    while (r < N)
    {
        mpp[arr[r]]++;
        if (mpp.size() > 2)
        {
            if (mpp.size() > 2)
            { // can be optimized by using if, it will not allow to exceed maxLength
                mpp[arr[l]]--;
                if (mpp[arr[l]] == 0)
                {
                    mpp.erase(arr[l]);
                }
                l++;
            }
        }
        if (mpp.size() <= 2)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }
    return maxLen;
}