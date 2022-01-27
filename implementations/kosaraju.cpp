/* Kosaraju's algorithm to find strongly connected components in a directed graph */
// ASSUMES that the following are present globally:
// const int MAXN = (int) 1e5 + 5;
// int n;
// bool vis[MAXN];
// vector<int> adj[MAXN];
// vector<int> transposeAdj[MAXN];


void process(int node, stack<int>& stk)
{
    vis[node] = true;
    for (const auto& u : adj[node])
    {
        if (!vis[u])
            process(u, stk);
    }
    stk.push(node);
}

void dfs(int node, vector<int>& currentComponent)
{
    vis[node] = true;
    currentComponent.push_back(node);
    for (const auto& u : transposeAdj[node])
    {
        if (!vis[u])
            dfs(u, currentComponent);
    }
}

// returns the strongly connected components of the graph
vector<vector<int>> kosaraju()
{
    stack<int> stk;
    fill(vis, vis + n, false);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            process(i, stk);
    }
    for (int i = 0; i < n; i++)
    {
        for (const auto& u : adj[i])
            transposeAdj[u].push_back(i);
    }
    fill(vis, vis + n, false);
    vector<vector<int>> connectedComponents;
    while (!stk.empty())
    {
        int node = stk.top();
        stk.pop();
        vector<int> currentComponent;
        if (!vis[node])
            dfs(node, currentComponent);
        connectedComponents.push_back(currentComponent);
    }
    return connectedComponents;
}
