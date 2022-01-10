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
    
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    const long long mod = (long long) 1e9 + 7;
    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    dp[0][0] = grid[0][0] == '.';

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '*') continue;
            if (i - 1 >= 0) dp[i][j] += dp[i - 1][j];
            dp[i][j] %= mod;
            if (j - 1 >= 0) dp[i][j] += dp[i][j - 1];
            dp[i][j] %= mod;
        }
    }

    cout << dp[n - 1][n - 1];
    return 0;

}
