#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

int main() {
#ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);
    dp[n] = 0;

    for (int i = n; i >= 1; i--)
    {
        if (dp[i] == -1) continue;
        int curNum = i;
        while (curNum)
        {
            int d = curNum % 10;
            curNum /= 10;
            if (i - d >= 0)
            {
                if (dp[i - d] == -1) dp[i - d] = dp[i] + 1;
                else dp[i - d] = min(dp[i - d], dp[i] + 1);
            }
        }
    }

    cout << dp[0];
    return 0;
  
}
