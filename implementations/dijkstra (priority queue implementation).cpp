// const int MAXN = 2e5 + 5;
// int n;
// vector<pair<int, long long>> adj[MAXN];
long long dist[MAXN];

void dijkstra(int source)
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    for (int i = 0; i < n; i++)
        dist[i] = 1e18;
    pq.push({0, source});
    dist[source] = 0;
    while (!pq.empty())
    {
        int node = pq.top().second;
        pq.pop();
        for (auto& u : adj[node])
        {
            if (dist[u.first] > dist[node] + u.second)
            {
                dist[u.first] = dist[node] + u.second;
                pq.push({dist[u.first], u.first});
            }
        }
    }
}
