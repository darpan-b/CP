#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> a(N), b(N), c(N);
    for(int i = 0; i < N; i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    vector<vector<int>> dp(N, vector<int>(3,0));
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];

    for(int i = 1; i < N; i++){
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b[i];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c[i];
    }

    cout << max({dp[N-1][0], dp[N-1][1], dp[N-1][2]}) << "\n";
    return 0;
}
