// brute force - run an inner while loop to ensure the current element is greater than all the elements on the right side
vector<int> leaders(int n, int arr[])
{
    vector<int> ans;
    for (int i = 0; i < n - 1; i++)
    {
        int ele = arr[i];
        int j = i + 1;
        while (j < n)
        {
            if (ele >= arr[j])
            {
                j++;
            }
            else
            {
                break;
            }
        }
        if (j == n)
        {
            ans.push_back(arr[i]);
        }
    }
    ans.push_back(arr[n - 1]);
    return ans;
}

// optimal - we know that an element is a leader if it is greater than max(elements on right side of array)

// traverse from back side of array
// maintain max variable
// if arr[i]> max - > push it to ans and update max variable

vector<int> leaders(int n, int arr[])
{
    vector<int> ans;
    int maxi = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] >= maxi)
        {
            ans.push_back(arr[i]);
            maxi = arr[i];
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}