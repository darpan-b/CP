#include <bits/stdc++.h>
using namespace std;

void solve(int tc)
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &e : a) cin >> e;
    
    if(n == 1 || m == 1)
    {
        bool tree = false;
        for (auto e : a)
        {
            for (auto f : e) tree |= (f == '^');
        }
        if (tree)
        {
            cout << "Case #" << tc << ": Impossible\n";
        }
        else
        {
            cout << "Case #" << tc << ": Possible\n";
            for (auto e : a) cout << e << "\n";
        }
        return;
    }
    
    vector<vector<int>> neigh(n, vector<int>(m, 0));
    vector<string> ans(n, string(m, '^'));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '#') ans[i][j] = '#';
        }
    }
    
    auto is_valid = [&](int x, int y)
    {
        return x >= 0 && x < n && y >= 0 && y < m;
    };
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            neigh[i][j] += is_valid(i - 1, j) && (ans[i - 1][j] == '^');
            neigh[i][j] += is_valid(i, j - 1) && (ans[i][j - 1] == '^');
            neigh[i][j] += is_valid(i + 1, j) && (ans[i + 1][j] == '^');
            neigh[i][j] += is_valid(i, j + 1) && (ans[i][j + 1] == '^');
        }
    }
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
            greater<>> pq;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ans[i][j] == '#') continue;
            pq.push({neigh[i][j], {i, j}});
        }
    }
    
    while (!pq.empty())
    {
        auto ele = pq.top();
        pq.pop();
        if (neigh[ele.second.first][ele.second.second] != ele.first) continue;
        if (ele.first >= 2) break;
        ans[ele.second.first][ele.second.second] = '.';
        int i = ele.second.first;
        int j = ele.second.second;
        if (is_valid(i - 1, j) && ans[i - 1][j] == '^')
        {
            neigh[i - 1][j]--;
            pq.push({neigh[i - 1][j], {i - 1, j}});
        }
        if (is_valid(i + 1, j) && ans[i + 1][j] == '^')
        {
            neigh[i + 1][j]--;
            pq.push({neigh[i + 1][j], {i + 1, j}});
        }
        if (is_valid(i, j - 1) && ans[i][j - 1] == '^')
        {
            neigh[i][j - 1]--;
            pq.push({neigh[i][j - 1], {i, j - 1}});
        }
        if (is_valid(i, j + 1) && ans[i][j + 1] == '^')
        {
            neigh[i][j + 1]--;
            pq.push({neigh[i][j + 1], {i, j + 1}});
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '^' && ans[i][j] == '.')
            {
                cout << "Case #" << tc << ": Impossible\n";
                return;
            }
        }
    }
    
    cout << "Case #" << tc << ": Possible\n";
    for (auto e : ans) cout << e << "\n";
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test;
    cin >> test;
    for (int i = 1; i <= test; i++) solve(i);
    return 0;
}
