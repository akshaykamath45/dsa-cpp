// Mine Approach: Brute Force using Hashing without modifying the original array
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int removeDuplicates(vector<int> &arr, int n)
{
    vector<int> hash(n);
    cout << "Hash Size : " << hash.size() << endl;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (hash[i] >= 1)
        {
            count += 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << hash[i] << " ";
    }

    return count;
}
int main()
{
    int n = 10;
    vector<int> arr = {0, 1, 2, 3, 3, 3, 4, 4, 5, 5};
    // vector<int> arr={1,1,2,3,3,4,5,5,5};
    int ans = removeDuplicates(arr, n);
    cout << ans;
    return 0;
}


// Brute Force: Using hashset,modifies the original array (required in leetcode question)
// Intuition: We have to think of a data structure that does not store duplicate elements. So can we use a Hash set? Yes! We can. As we know HashSet only stores unique elements.

// Approach:

// Declare a HashSet.
// Run a for loop from starting to the end.
// Put every element of the array in the set.
// Store size of the set in a variable K.
// Now put all elements of the set in the array from the starting of the array.
// Return K.

// Time complexity: O(n*log(n))+O(n)
// O(n*log(n)) to insert into set
// O(n) to update the array
// Space Complexity: O(n)

int removeDuplicates(vector<int> &arr)
{
    int n = arr.size();
    set<int> set;
    for (int i = 0; i < n; i++)
    {
        set.insert(arr[i]);
    }
    int k = set.size();
    int j = 0;
    for (int x : set)
    {
        arr[j++] = x;
    }
    return k;
}

// Optimal Approach: Using 2 Pointer

// Intuition: We can think of using two pointers ‘i’ and ‘j’, we move ‘j’ till we don’t get a number arr[j] which is different from arr[i]. As we got a unique number we will increase the i pointer and update its value by arr[j].

// Approach:
// Take a variable i as 0;
// Use a for loop by using a variable ‘j’ from 1 to length of the array.
// If arr[j] != arr[i], increase ‘i’ and update arr[i] == arr[j].
//  After completion of the loop return i+1, i.e size of the array of unique elements.

// Time Complexity: O(N)
// Space Complexity: O(1)
int removeDuplicates(vector<int> &arr, int n)
{
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    return i + 1;
}
int main()
{
    int n = 7;
    vector<int> arr = {1, 1, 2, 2, 2, 3, 3};
    int ans = removeDuplicates(arr, n);
    cout << ans;
    return 0;
}
