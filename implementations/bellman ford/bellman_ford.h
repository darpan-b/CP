// returns the distance vector
vector<ll> bellman_ford(int src, int n, vector<pair<ll, pair<int, int>>> &edges)
{
    vector<ll> dist(n, 1e18);
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto &edge : edges)
        {
            int from = edge.second.first;
            int to = edge.second.second;
            ll wt = edge.first;
            if (dist[to] > dist[from] + wt) dist[to] = dist[from] + wt;
        }
    }
    return dist;
}
