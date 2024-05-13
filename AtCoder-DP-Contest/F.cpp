#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (s[i-1] == t[j-1]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
    }
    string ans = "";
    int cn = n, cm = m;
    while (cn > 0 && cm > 0) {
        if (dp[cn][cm] == dp[cn-1][cm-1] + 1 && s[cn-1] == t[cm-1]) {
            ans += s[cn-1];
            cn--;
            cm--;
        } else if (dp[cn][cm] == dp[cn-1][cm]) {
            cn--;
        } else {
            cm--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
    return 0;
}
