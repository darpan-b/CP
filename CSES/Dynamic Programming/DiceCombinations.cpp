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

    int n;
    cin >> n;
    const long long mod = 1e9 + 7;
    vector<long long> dp(n + 10, 0);
    for(int i = 1; i <= 6; i++) dp[i] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i - 1; j >= max(1, i - 6); j--)
        {
            dp[i] += dp[j];
            dp[i] %= mod;
        }
    }
    cout << dp[n];
    return 0;
}
