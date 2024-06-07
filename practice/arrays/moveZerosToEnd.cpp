#include <bits/stdc++.h>
using namespace std;

// brute force
void moveZeroes(vector<int> &arr)
{
    int countZeros = 0;
    int n = arr.size();
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            countZeros++;
        }
    }
    cout << "zeros " << countZeros << endl;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            temp.push_back(arr[i]);
        }
    }
    cout << "temp: ";
    for (auto i : temp)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < n - countZeros; i++)
    {
        arr[i] = temp[i];
    }
    for (int i = n - countZeros; i < n; i++)
    {
        arr[i] = 0;
    }
}

// optimal approach : using 2 pointers
// find 1st index (j) with 0;
// swap it with next element (i) if arr[i]!=0 & j++
// j will always point at zero
// i will automatically increase

void moveZerosToEnd(vector<int> &arr)
{
    int n = arr.size();
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        // get 1st index with zero element
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }
    if (n == 1 || j == -1)
    {
        return;
    }
    for (int i = j + 1; i < n; i++)
    {
        // swap if current element is not equal to zero
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}
int main()
{
    vector<int> arr = {0, 1, 0, 3, 12};
    int n = arr.size();
    cout << "before moving zeros " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    moveZerosToEnd(arr);
    cout << "after moving zeros " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}