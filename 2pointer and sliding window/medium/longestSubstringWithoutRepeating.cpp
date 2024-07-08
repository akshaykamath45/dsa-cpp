// brute force - generating all substrings and creating a hashmap
int lengthOfLongestSubstring(string s)
{

    int n = s.size();
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> hash(256, 0);
        string substr = "";
        for (int j = i; j < n; j++)
        {
            if (hash[s[j]] == 1)
            {
                break;
            }
            substr += s[j];
            maxLen = max(maxLen, j - i + 1);
            hash[s[j]] = 1;
        }
    }
    return maxLen;
}

// better - sliding window , l=0,r=0 if already present (false condition) move l and do some computation
int lengthOfLongestSubstring(string s)
{
    int n = s.size();
    int maxLen = 0;
    int l = 0;
    int r = 0;
    vector<int> hash(256, -1);
    while (r < n)
    {
        if (hash[s[r]] != -1)
        { // if character repeating
            if (hash[s[r]] >= l)
            {
                l = hash[s[r]] + 1;
            }
        }
        maxLen = max(maxLen, r - l + 1);
        hash[s[r]] = r;

        r++;
    }
    return maxLen;
}