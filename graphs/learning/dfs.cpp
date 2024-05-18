private:
void dfsTraversal(int node, vector<int> adj[], int vis[], vector<int> &dfs)
{
    vis[node] = 1;
    dfs.push_back(node);
    // traverse all neighbors
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfsTraversal(it, adj, vis, dfs);
        }
    }
}

public:

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    int vis[V] = {0};
    int start = 0;
    vector<int> dfs;
    dfsTraversal(start, adj, vis, dfs);
    return dfs;
}