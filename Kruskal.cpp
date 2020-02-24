/**
 * The following code is an implementation of the Kruskal's algorithm.
 * Kruskal's algorithm is a greedy algorithm used to find the minimum spanning tree in a graph.
 * Time complexity: O(ElogV)
 */

/**
 * @author Darpan Bhattacharya
 * Created on: 24.02.2020
 */

#include <bits/stdc++.h>

// MAXN stores the maximum number of nodes in the graph 
const int MAXN = 2e5+5;

// root[] stores the root of each disjoint set
// ranks[] stores the size of the set

int root[MAXN];
int ranks[MAXN];


/*
 * findroot(node) returns the root of the set to which node belongs
 * (uses path compression)
 */
 
int findroot(int node) {
    
    if(root[node] == node) {
        return node;
    } else {
        return root[node] = findroot(root[node]);
    }
    
}


/*
 * unite(u, v) returns false if u and v are already in the same set
 * otherwise, it unites the two sets to which u and v belong and returns true 
 */

bool unite(int u, int v) {
    
    // root_u and root_v stores the root of the sets to which the nodes u and v belong respectively
    int root_u = findroot(u);
    int root_v = findroot(v);

    // returns false if u and v are in the same set
    if(root_u == root_v) {
        return false;
    }
    
    // unites the disjoint sets by comparing ranks
    if(ranks[root_u] > ranks[root_v]) {
        root[root_v] = root_u;
        ranks[root_u] += ranks[root_v];
    } else {
        root[root_u] = root_v;
        ranks[root_v] += ranks[root_u];
    }

    return true;

}


/*
 * kruskal() returns the weight of the minimum spanning tree of the graph
 * by using kruskal's algorithm
 */

long long kruskal() {
    
    // the graph is stored in the form of a vector of edges
    // edges.first stores the weight of the edge
    // edges.second stores the two nodes which are connected by the edge
    // for representation purpose: { cost, { node, node} }
    std::vector<std::pair<long long, std::pair<int, int>>> edges;
    
    // take the graph as input
    int no_edges; 
    std::cin >> no_edges;
    
    for(int i = 0; i < no_edges; i++) {
        int u, v;
        long long wt;
        std::cin >> u >> v;
        std::cin >> wt;
        edges.push_back(std::make_pair(wt, std::make_pair(u, v)));
    }
    
    
    // sort the edges according to edge weights
    std::sort(edges.begin(), edges.end());
    
    // stores the total weight of the spanning tree of the graph
    long long tot = 0;
    
    // stores the edges in the spanning tree of the graph, use it if required
    std::vector<std::pair<long long, std::pair<int, int>>> s_tree;
    
    for(auto& i: edges) {
        bool is_included = unite(i.second.first, i.second.second);
        
        if(is_included) {
            // i is an edge that is included in the spanning tree
            s_tree.push_back(i);
            tot += i.first;
        }
    }
    
    return tot;
    
}


/*
 *  driver code
 */
 
int main() {
    
    kruskal();
    
    return 0;
    
}
