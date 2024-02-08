// brute force :generate all subarrays and check
int subarraysWithSumK(vector<int> arr, int b)
{
    int n = arr.size();
    int xorOp = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {

        for (int j = i; j < n; j++)
        {
            xorOp = 0;
            for (int k = i; k <= j; k++)
            {
                xorOp ^= arr[k];
                if (xorOp == b)
                {
                    count++;
                }
            }
        }
    }
    return count;
}

// better: reduces one inner loop,checks previous subarray
int subarraysWithSumK(vector<int> arr, int b)
{
    int n = arr.size();
    int xorOp = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        xorOp = 0;
        for (int j = i; j < n; j++)
        {
            xorOp ^= arr[j];
            if (xorOp == b)
            {
                count++;
            }
        }
    }
    return count;
}

// optimal: using hashmap,x=XOR^k,main focus in on ending point
int subarraysWithSumK(vector<int> arr, int b)
{
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++; // intialize with {0,1}
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ arr[i];
        int x = xr ^ b;
        count += mpp[x];
        mpp[xr]++;
    }
    return count;
}