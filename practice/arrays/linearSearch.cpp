#include <bits/stdc++.h>
using namespace std;

int searchInSorted(vector<int> &arr, int N, int K)
{

    for (int i = 0; i < N; i++)
    {
        if (arr[i] == K)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int n = arr.size();
    int k = 3;
    int ans = searchInSorted(arr, n, k);
    cout << "element present at index " << ans << endl;
    return 0;
}
