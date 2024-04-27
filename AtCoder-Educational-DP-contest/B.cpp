#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    vector<int> dp(n,INF);
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        for(int j = i-1; j >= max(0,i-k); j--){
            dp[i] = min(dp[i], dp[j] + abs(h[i]-h[j]));
        }
    }
    cout << dp[n-1] << "\n";
    return 0;
}
