#include <bits/stdc++.h>
using namespace std;

// brute force - sort the array

// better - count zeros, ones and twos
void sortColors(vector<int> &arr)
{
    vector<int> temp;
    int n = arr.size();
    int countZeros = 0;
    int countOnes = 0;
    int countTwos = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            countZeros++;
        }
        else if (arr[i] == 1)
        {
            countOnes++;
        }
        else
        {
            countTwos++;
        }
    }
    cout << endl;
    cout << "zeros " << countZeros << endl;
    cout << "oness " << countOnes << endl;
    cout << "twos " << countTwos << endl;
    for (int i = 0; i < countZeros; i++)
    {
        temp.push_back(0);
    }
    for (int i = countZeros; i < countZeros + countOnes; i++)
    {
        temp.push_back(1);
    }
    for (int i = countZeros + countOnes; i < countZeros + countOnes + countTwos; i++)
    {
        temp.push_back(2);
    }
    cout << endl
         << "temp array " << endl;
    for (auto i : temp)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
};

// opitmal - dnf (dutch national flag)
void sortColors1(vector<int> &arr)
{
    int n = arr.size();
    int low = 0;      // represents all 0's - 0 to low -1
    int mid = 0;      // represents all 1's - low to mid-1
    int high = n - 1; // represent all 2's - high to mid-1
    while (mid <= high)
    {
        if (arr[mid] == 0) 
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
};

int main()
{
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    // before sorting
    cout << "before sorting " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    sortColors1(arr);
    cout << endl;
    cout << "after sorting " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}