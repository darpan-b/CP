//NOT TESTED

// Bellman Ford algorithm to find single source shortest path in a graph.
// The graph is assumed to be directed and is stored in the form of a vector of edges.
// It works for graphs with negative weight cycle, unlike dijkstra. However, its time complexity is 
// greater than that of dijkstra.
// Time complexity: O(|V|*|E|) 

//const int MAXN = 2e5 + 5;
long long dist[MAXN];

void bellmanFord(int source, int n, vector<pair<long long, pair<int, int>>>& edges) {
    for (int i = 0; i < n; i++) dist[i] = 1e18;
    dist[source] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (auto& edge : edges) {
            int start = edge.second.first;
            int end = edge.second.second;
            long long weight = edge.first;
            if (dist[end] > dist[start] + weight) {
                dist[end] = dist[start] + weight;
            }
        }
    }
}
