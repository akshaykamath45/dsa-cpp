#include <bits/stdc++.h>
using namespace std;

// brute force markin row and col
// void markRow(int i, vector<vector<int>> &matrix)
// {

//     for (int j = 0; j < matrix[0].size(); j++)
//     {
//         if (matrix[i][j] != 0)
//         {
//             matrix[i][j] = -1;
//         }
//     }
// }
// void markCol(int j, vector<vector<int>> &matrix)
// {
//     for (int i = 0; i < matrix.size(); i++)
//     {

//         if (matrix[i][j] != 0)
//         {
//             matrix[i][j] = -1;
//         }
//     }
// }
// void setMatrixZeroes(vector<vector<int>> &matrix)
// {
//     int n = matrix.size();
//     int m = matrix[0].size();
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (matrix[i][j] == 0)
//             {
//                 markRow(i, matrix);
//                 markCol(j, matrix);
//             }
//         }
//     }
//     // setting to 0
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (matrix[i][j] == -1)
//             {
//                 matrix[i][j] = 0;
//             }
//         }
//     }
// }

// better - maintaining row and col array
void setMatrixZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> row(n, 0);
    vector<int> col(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    // setting to 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] || col[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}
int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    cout << "before setting zeros : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    setMatrixZeroes(matrix);

    cout << "after setting zeros : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
