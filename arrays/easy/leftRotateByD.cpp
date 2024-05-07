#include <bits/stdc++.h>

// Brute Force
// Approach 1: Using a temp array 

// For Rotating the Elements to right
// Step 1: Copy the last k elements into the temp array.

// Step 2: Shift n-k elements from the beginning by k position to the right

// Step 3: Copy the elements into the main array from the temp array.

// Time Complexity: O(n)

// Space Complexity: O(k) since k array element needs to be stored in temp array

vector<int> rotateArray(vector<int> arr, int d)
{
    int n = arr.size();
    d = d % n;
    vector<int> temp;
    for (int i = 0; i < d; i++)
    {
        temp.push_back(arr[i]);
    }
    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }
    for (int i = n - d; i < n; i++)
    {
        arr[i] = temp[i - (n - d)];
    }
    return arr;
}
