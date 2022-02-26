#include <bits/stdc++.h>
#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif
using namespace std;
#define fr(i, n) for (int i = 0; i < (int) n; i++)
#define fra(i, a, b) for (auto i = (a); i <= (b); i++)
#define rfr(i, a, b) for (auto i = (a); i >= (b); i--)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1005;
int n, m;
int root[MAXN][MAXN], ranks[MAXN][MAXN];
string grid[MAXN];

void initDSU()
{
    fr(i, n) fr(j, m)
    {
        root[i][j] = i * m + j;
        ranks[i][j] = 1;
    }
}

int findRoot(int r, int c)
{
    if (root[r][c] == r * m + c) return root[r][c];
    else return root[r][c] = findRoot(root[r][c] / m, root[r][c] % m);
}

bool unite(int r1, int c1, int r2, int c2)
{
    int p1 = findRoot(r1, c1), p2 = findRoot(r2, c2);
    if (p1 == p2) return false;
    if (ranks[p1 / m][p1 % m] >= ranks[p2 / m][p2 % m])
    {
        root[p2 / m][p2 % m] = p1;
        ranks[p1 / m][p1 % m] += ranks[p2 / m][p2 % m];
    }
    else
    {
        root[p1 / m][p1 % m] = p2;
        ranks[p2 / m][p2 % m] += ranks[p1 / m][p1 % m];
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    fr(i, n) cin >> grid[i];
    initDSU();
    fr(i, n) fr(j, m)
    {
        if (grid[i][j] == '#') continue;
        if (i - 1 >= 0 && grid[i - 1][j] == '.') unite(i, j, i - 1, j);
        if (i + 1 < n && grid[i + 1][j] == '.') unite(i, j, i + 1, j);
        if (j - 1 >= 0 && grid[i][j - 1] == '.') unite(i, j, i, j - 1);
        if (j + 1 < n && grid[i][j + 1] == '.') unite(i, j, i, j + 1);
    }
    set<int> rooms;
    fr(i, n) fr(j, m) if (grid[i][j] == '.') rooms.insert(findRoot(i, j));
    cout << rooms.size() << "\n";
    return 0;
}
