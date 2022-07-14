const int MAXN = 2e5 + 5;
const int MAXLOG = 20;
vector<int> adj[MAXN];
int dep[MAXN];
int anc[MAXN][MAXLOG];
 
void dfs(int node, int p)
{
    anc[node][0] = p;
    if (p == -1) dep[node] = 0;
    else dep[node] = dep[p] + 1;
    for (int i = 1; i < MAXLOG; i++) {
        if (anc[node][i - 1] == -1) anc[node][i] = -1;
        else anc[node][i] = anc[anc[node][i - 1]][i - 1];
    }
    for (auto u : adj[node]) {
        if (u == p) continue;
        dfs(u, node);
    }
}
int lca(int u, int v)
{
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = MAXLOG - 1; i >= 0; i--) {
        if (dep[anc[u][i]] >= dep[v]) u = anc[u][i];
    }
    if (u == v) return u;
    for (int i = MAXLOG - 1; i >= 0; i--) { 
        if (anc[u][i] != anc[v][i]) {
            u = anc[u][i];
            v = anc[v][i];
        }
    }
    return anc[u][0];
}
int dist(int u, int v)
{
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}
void initLCA(int root, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < MAXLOG; j++) anc[i][j] = -1;
    }
    dfs(root, root);
}
