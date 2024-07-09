class Solution
{
public:
    int missingNumber(vector<int> &arr)
    {
        // int n = arr.size();
        // int sum = n * (n + 1) / 2;
        // int ogsum = 0;
        // for (int i = 0; i < n; i++) {
        //     ogsum += arr[i];
        // }
        // int missingNumber = sum - ogsum;
        // return missingNumber;

        int n = arr.size();
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != i)
            {
                return i;
            }
        }
        return n;
    }
};