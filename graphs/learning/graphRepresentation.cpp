#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// adjacency matrix
// sc: O(n*n)
int main()
{
    int n, m;
    cin >> n >> m;
    int adjMat[n + 1][n + 1];
    memset(adjMat, 0, sizeof(adjMat));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// adjacency list
// sc: O(2*e)
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "Adjacency list of vertex " << i << ": ";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
