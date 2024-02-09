// Mine approach : Brute Force (Works if no duplicates)
// Sort the array
// Return second index array element as second smallest
// Return second last index array element as second largest

int secondLargest(vector<int> arr, int n)
{
    int slargest = arr[n - 2];
    return slargest;
}
int secondSmallest(vector<int> arr, int n)
{
    int ssmallest = arr[1];
    return ssmallest;
}
vector<int> getSecondOrderElements(int n, vector<int> a)
{
    sort(a.begin(), a.end());
    int slargest = secondLargest(a, n);
    int ssmallest = secondSmallest(a, n);
    return {slargest, ssmallest};
}

// Better

// Intuition:
// Even though we want to have just the second smallest and largest elements, we are still sorting the entire array for that and thus increasing the time complexity. Can we somehow try to not sort the array and still get our answer?

// Approach:
// Find the smallest and largest element in the array in a single traversal
// After this, we once again traverse the array and find an element that is just greater than the smallest element we just found.
// Similarly, we would find the largest element which is just smaller than the largest element we just found
// Indeed, this is our second smallest and second largest element

vector<int> getSecondOrderElements(int n, vector<int> arr)
{
    if (n == 0 || n == 1)
        cout << -1 << " " << -1 << endl; // edge case when only one element is present in array
    int small = INT_MAX, second_small = INT_MAX;
    int large = INT_MIN, second_large = INT_MIN;
    int i;
    for (i = 0; i < n; i++)
    {
        small = min(small, arr[i]);
        large = max(large, arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i] < second_small && arr[i] != small)
            second_small = arr[i];
        if (arr[i] > second_large && arr[i] != large)
            second_large = arr[i];
    }

    return {second_large, second_small};
}

// Optimal

// Intuition:
// In the previous solution, even though we were able to bring down the time complexity to O(N), we still needed to do two traversals to find our answer. Can we do this in a single traversal by using smart comparisons on the go?

// Approach:
// We would require four variables: small,second_small, large, and second_large. Variable small and second_small are initialized to INT_MAX while large and second_large are initialized to INT_MIN.

// Second Smallest Algo:
// If the current element is smaller than ‘small’, then we update second_small and small variables
// Else if the current element is smaller than ‘second_small’ then we update the variable ‘second_small’
// Once we traverse the entire array, we would find the second smallest element in the variable second_small.
// Here’s a quick demonstration of the same.

// Second Largest Algo:
// If the current element is larger than ‘large’ then update second_large and large variables
// Else if the current element is larger than ‘second_large’ then we update the variable second_large.
// Once we traverse the entire array, we would find the second largest element in the variable second_large.
// Here’s a quick demonstration of the same.

vector<int> getSecondOrderElements(int n, vector<int> arr)
{
    int small = INT_MAX, second_small = INT_MAX;
    int large = INT_MIN, second_large = INT_MIN;
    int i;
    if (n == 0 || n == 1)
        cout << -1 << " " << -1 << endl; // edge case when only one element is present in array

    for (i = 0; i < n; i++)
    {
        if (arr[i] > large)
        {
            second_large = large;
            large = arr[i];
        }
        if (arr[i] > second_large && arr[i] != large)
        {
            second_large = arr[i];
        }
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i] < small)
        {
            second_small = small;
            small = arr[i];
        }
        if (arr[i] < second_small && arr[i] != small)
        {
            second_small = arr[i];
        }
    }
    return {second_large, second_small};
}
