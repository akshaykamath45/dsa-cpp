class Solution
{
public:
    int trap(vector<int> &arr)
    {
        // water will get logged only between the buildings when left and right
        // buildings are greater otherwise it will flow, water won't be trapped
        int n = arr.size();

        // computing leftMax and rightMax using prefix and postfix arrays
        vector<int> prefixMax(n); // will contain the max element on the left
                                  // side of a particular index
        vector<int> suffixMax(n); // will contain the max element on the right
                                  // side of a particular index
        prefixMax[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            prefixMax[i] = max(prefixMax[i - 1], arr[i]);
        }
        suffixMax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suffixMax[i] = max(suffixMax[i + 1], arr[i]);
        }
        int waterTrapped = 0;
        for (int i = 0; i < n; i++)
        {
            int leftMax = suffixMax[i];
            int rightMax = prefixMax[i];
            if (leftMax > arr[i] && rightMax > arr[i])
            {
                waterTrapped += min(leftMax, rightMax) - arr[i];
            }
        }
        return waterTrapped;
    }
};

// optimal using 2 pointers

int trap(vector<int> &arr)
{
    int n = arr.size();
    int lmax = 0, rmax = 0, total = 0;
    int l = 0;
    int r = n - 1;
    while (l < r)
    {
        if (arr[l] <= arr[r])
        {
            if (lmax > arr[l])
            {
                total += lmax - arr[l];
            }
            else
            {
                lmax = arr[l];
            }
            l = l + 1;
        }
        else
        {
            if (rmax > arr[r])
            {
                total += rmax - arr[r];
            }
            else
            {
                rmax = arr[r];
            }
            r = r - 1;
        }
    }
    return total;
}