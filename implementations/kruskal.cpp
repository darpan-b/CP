// DSU.cpp used here

vector<pair<long long, pair<int, int>>> kruskal(vector<pair<long long, pair<int, int>>> edgesCopy)
{
    DSU dsu(n);
    vector<pair<long long, pair<int, int>>> spanningTree;

    sort(edgesCopy.begin(), edgesCopy.end());

    for (const auto& e : edgesCopy)
    {
        if (dsu.unite(e.second.first, e.second.second))
            spanningTree.push_back(e);
    }
    return spanningTree;
}
