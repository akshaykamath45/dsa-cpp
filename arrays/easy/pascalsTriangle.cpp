#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(int numRows)
{
    vector<vector<int>> ans;
    for(int i=1;i<=numRows;i++){
        for(int j=1;j<=i;j++){
            
        }
    }
    return ans;
}
int main()
{
    int numRows = 5;
    vector<vector<int>> arr = solve(numRows);
    cout << endl;
    cout << "after calling function " << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}