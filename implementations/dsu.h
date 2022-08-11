#include <bits/stdc++.h>
using namespace std;

struct disjoint_set_union
{
    vector<int> roots, ranks;

    disjoint_set_union()
    {
        roots.clear();
        ranks.clear();
    }

    disjoint_set_union(int n)
    {
        roots.assign(n + 1, 0);
        ranks.assign(n + 1, 0);
        iota(roots.begin(), roots.end(), 0);
    }

    int find_root(int u)
    {
        if (roots[u] == u) return u;
        return roots[u] = find_root(roots[u]);
    }

    bool unite(int u, int v)
    {
        u = find_root(u);
        v = find_root(v);
        if (u == v) return false;
        if (ranks[u] > ranks[v])
        {
            roots[v] = u;
            ranks[u] += ranks[v];
        }
        else
        {
            roots[u] = v;
            ranks[v] += ranks[u];
        }
        return true;
    }
};



