#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

#define ll long long
#define ld long double

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int n;
    cin >> n;
    vector<ld> p(n);
    for (auto& e : p) cin >> e;
    vector<vector<ld>> dp(n+1, vector<ld>(n+1, 0));
    // dp[i][j] = probab of j heads in i tosses
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                dp[i][j] = dp[i-1][j]*(1-p[i-1]);
                continue;
            }
            dp[i][j] = dp[i-1][j-1]*p[i-1] + dp[i-1][j]*(1-p[i-1]);
        }
    }
    ld ans = 0;
    for (int i = n; i >= 0; i--) {
        if (i <= n-i) break;
        ans += dp[n][i];
    }
    cout << ans << "\n";
    return 0;
}
