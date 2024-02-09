// Brute Force

// Intuition:
// We can sort the array in ascending order, hence the largest element will be at the last index of the array.

// Approach:
// Sort the array in ascending order.
// Print the (size of the array -1)th index.

#include <bits/stdc++.h>
int largestElement(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());
    int max = arr[n - 1];
    return max;
}



// Optimal

// Intuition:
// We can maintain a max variable that will update whenever the current value is greater than the value in the max variable.  

// Approach: 
// Create a max variable and initialize it with arr[0].
// Use a for loop and compare it with other elements of the array
// If any element is greater than the max value, update max value with the element’s value
// Print the max variable

#include <bits/stdc++.h>
int largestElement(vector<int> &arr, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
