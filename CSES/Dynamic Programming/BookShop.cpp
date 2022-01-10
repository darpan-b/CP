#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif



int main()
{
#ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, X;
    cin >> n >> X;

    vector<int> h(n), s(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> s[i];

    const int maxn = (int) 1e5 + 5;
    vector<vector<int>> dp(n, vector<int>(maxn, 0));
    
    for (int i = h[0]; i < maxn; i++) dp[0][i] = s[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= maxn; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - h[i] < 0) continue;
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - h[i]] + s[i]);
        }
        dbg(dp[i][X]);
    }

    dbg(dp);

    cout << dp[n - 1][X];
    return 0;

}
