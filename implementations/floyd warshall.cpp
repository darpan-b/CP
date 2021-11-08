//NOT TESTED

// Floyd-Warshall algorithm to find all pairs shortest path.
// Time complexity: O(N * N * N)

//Initialize dist[i][j] to inf or edge weight for all i, j before function call

void floydWarshall(vector<vector<long long>>& dist) {
    int n = dist.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (dist[j][k] > dist[j][i] + dist[i][k]) {
                    dist[j][k] = dist[j][i] + dist[j][k];
                }
            }
        }
    }
}
