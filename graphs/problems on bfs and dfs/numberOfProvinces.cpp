class Solution
{
private:
    void dfsTraversal(int node, vector<int> adj[], vector<int> &visited)
    {
        visited[node] = 1;
        // traversing neighbours
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                dfsTraversal(it, adj, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int V = isConnected[0].size();
        vector<int> visited(V, 0);
        vector<int> adjList[V];
        // converting to adjacency list
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int count = 0;
        for (int i = 0; i < V; i++)
        {
            // dfs traversal automatically marks the visited nodes,
            // hence when visited[i]==0,it marks the new province and we increase the count
            if (visited[i] == 0)
            {
                dfsTraversal(i, adjList, visited);
                count++;
            }
        }
        return count;
    }
};
