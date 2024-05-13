#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

#define ll long long

const ll MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto& e : grid) cin >> e;
    vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i-1][j-1] == '#') continue;
            if (i == 1 && j == 1) continue;
            dp[i][j] = ((dp[i-1][j]%MOD) + (dp[i][j-1]%MOD))%MOD;
        }
    }
    cout << dp[n][m] << "\n";
    return 0;
}
