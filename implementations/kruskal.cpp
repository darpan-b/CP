//NOT TESTED

// Kruskal's algorithm to find minimum spanning tree in a graph.
//use DSU.cpp 

vector<pair<long long, pair<int, int>>> kruskal(vector<pair<long long, pair<int, int>>>& edges, int n) {
    DSU dsu(n);
    sort(edges.begin(), edges.end());
    vector<pair<long long, pair<int, int>>> spanningTree;
    for (auto& e : edges) {
        if (dsu.unite(e.second.first, e.second.second)) {
            spanningTree.push_back(e);
        }
    }
    return spanningTree;
}
