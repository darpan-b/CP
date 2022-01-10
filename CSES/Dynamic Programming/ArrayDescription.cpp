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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    const long long mod = (long long) 1e9 + 7;
    vector<vector<long long>> dp(n, vector<long long>(m + 1, 0));

    // dp[i][j] = number of arrays such that there is j in the i'th position in array

    if (a[0] == 0)
    {
        for (int i = 1; i <= m; i++) dp[0][i] = 1;
    }
    else
    {
        dp[0][a[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        if (a[i] != 0)
        {
            if (a[i] - 1 >= 1) dp[i][a[i]] += dp[i - 1][a[i] - 1];
            dp[i][a[i]] %= mod;
            dp[i][a[i]] += dp[i - 1][a[i]];
            dp[i][a[i]] %= mod;
            if (a[i] + 1 <= m) dp[i][a[i]] += dp[i - 1][a[i] + 1];
            dp[i][a[i]] %= mod;
        }
        else
        {
            for (int j = 1; j <= m; j++)
            {
                if (j - 1 >= 1) dp[i][j] += dp[i - 1][j - 1];
                dp[i][j] %= mod;
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= mod;
                if (j + 1 <= m) dp[i][j] += dp[i - 1][j + 1];
                dp[i][j] %= mod;
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans += dp[n - 1][i];
        ans %= mod;
    }

    cout << ans;
    return 0;

}
