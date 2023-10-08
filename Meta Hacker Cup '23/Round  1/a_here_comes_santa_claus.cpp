#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

#define ll long long
#define ld long double

const ld INF = 1e18 + 5;

void solve(int testcase) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& e : a) cin >> e;
    sort(a.begin(), a.end());
    ld ans = 0;
    ld thisone = ((ld)a[1] + (ld)a[0]) / 2.0;
    ld otherone = ((ld)a[n - 1] + (ld)a[n - 2]) / 2.0;
    ans = otherone - thisone;
    if (n == 5) {
        thisone = ((ld)a[2] + (ld)a[0]) / 2.0;
        otherone = ((ld)a[n - 1] + (ld)a[n - 2]) / 2.0;
        ans = otherone - thisone;
        thisone = ((ld)a[1] + (ld)a[0]) / 2.0;
        otherone = ((ld)a[n - 1] + (ld)a[n - 3]) / 2.0;
        ans = max(ans, otherone - thisone);
    }
    // vector<ld> pre(n), suf(n);
    // pre[0] = a[0];
    // for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + a[i];
    // suf[n - 1] = a[n - 1];
    // for (int i = n - 2; i >= 0; i--) suf[i] = suf[i + 1] + a[i];
    // for (int i = 1; i < n - 2; i++) {
    //     ld thisone = ((ld)a[i] + (ld)a[0]) / 2.0;
    //     ld otherone = ((ld)a[n - 1] + (ld)a[i + 1]) / 2.0;
    //     // ld thisone = pre[i] / (ld)(i + 1);
    //     // ld otherone = suf[i + 1] / (ld)(n - (i + 1) + 1);
        
    //     ans = max(ans, otherone - thisone);
    //     dbg(thisone, otherone, i, ans);
    // }
    cout << "Case #" << testcase << ": " << ans << "\n";
}

int main() {
    freopen("here_comes_santa_claus_input_final.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cout << fixed << setprecision(8);
    int test;
    cin >> test;
    for (int i = 1; i <= test; i++) solve(i);
    return 0;
}
