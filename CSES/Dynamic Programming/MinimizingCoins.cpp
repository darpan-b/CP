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
    vector<int> values(n);
    for (int i = 0; i < n; i++) cin >> values[i];

    vector<int> dp((int) 1e6 + 10, -1);
    for (auto e : values) dp[e] = 1;

    for (auto e : values)
    {
        for (int i = 1; i <= X; i++)
        {   
            if (dp[i] == -1) continue;
            if(i + e > X) continue;
            if (dp[i + e] == -1) dp[i + e] = dp[i] + 1;
            else dp[i + e] = min(dp[i + e], dp[i] + 1);
        }
    }

    cout << dp[X];
    return 0;

}
