#include <bits/stdc++.h>
using namespace std;

// brute force - using 3 loops
int lenOfLongSubarr(vector<int> &arr, int n, int target)
{

    int maxi = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum = 0;

            for (int k = i; k <= j; k++)
            {
                cout << arr[k] << " ";
                sum += arr[k];
            }
            cout << "sum " << sum;
            if (sum == target)
            {
                int maxLength = j - i + 1;
                maxi = max(maxi, maxLength);
            }
            cout << endl;
        }
    }
    return maxi;
}

// better - using 2 loops
int lenOfLongSubarray(vector<int> &arr, int n, int target)
{

    int maxi = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {

            cout << arr[j] << " ";
            sum += arr[j];
            cout << "sum " << sum;
            if (sum == target)
            {
                int maxLength = j - i + 1;
                maxi = max(maxi, maxLength);
            }
            cout << endl;
        }
    }
    return maxi;
}

// optimal

int main()
{
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int n = arr.size();
    int ans = lenOfLongSubarray(arr, n, 15);
    cout << "ans " << ans;
    return 0;
}