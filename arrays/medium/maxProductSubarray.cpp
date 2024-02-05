// similar to kadane's algorithm problem

// brute force: generate all subarrays,return the maximum product
int maxProduct(vector<int> &arr)
{
    int maxi = INT_MIN;
    int product = 1;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            product = 1;
            for (int k = i; k <= j; k++)
            {
                product = product * arr[k];
                cout << arr[k] << " ";
                maxi = max(maxi, product);
            }
            cout << product << endl;
        }
    }
    return maxi;
}

// better: multiply previous subarray with next element
int maxProduct(vector<int> &arr)
{
    int maxi = INT_MIN;
    int product = 1;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        product = 1;
        for (int j = i; j < n; j++)
        {
            product = product * arr[j];
            maxi = max(maxi, product);
        }
    }
    return maxi;
}

// optimal: Use preffix and suffix to find the product of subarray,not kadane's algorithm
int subarrayWithMaxProduct(vector<int> &arr)
{
    int n = arr.size();
    int maxi = INT_MIN;
    int pref = 1;
    int suff = 1;
    for (int i = 0; i < n; i++)
    {
        if (pref == 0)
            pref = 1;
        if (suff == 0)
            suff = 1;
        pref *= arr[i];
        suff *= arr[n - i - 1];
        maxi = max(maxi, max(pref, suff));
    }
    return maxi;
}