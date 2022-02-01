#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

bool check(long long mask, const vector<long long> &pre, int n, int k)
{
    vector<vector<bool>> dp(n, vector<bool>(k, false));
    for (int i = 0; i < n; i++)
    {
        if ((pre[i] & mask) == mask)
            dp[i][0] = true;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < k; j++)
        {
            for (int l = i - 1; l >= 0; l--)
            {
                if (dp[l][j - 1])
                {
                    if (((pre[i] - pre[l]) & mask) == mask)
                        dp[i][j] = true;
                }
            }
        }
    }
    return dp[n - 1][k - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (auto &e : a)
        cin >> e;
    vector<long long> pre(n);
    partial_sum(a.begin(), a.end(), pre.begin());
    long long ans = 0;
    for (long long bit = 63; bit >= 0; bit--)
    {
        if (check(ans | (1LL << bit), pre, n, k))
            ans |= (1LL << bit);
    }
    cout << ans << "\n";
    return 0;
}
