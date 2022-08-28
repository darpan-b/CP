#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

#define ll long long

void solve(int tc)
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &e : a) cin >> e;
    sort(a.begin(), a.end());
    bool ok = n <= k * 2;
    for (int i = 2; i < n; i++)
    {
        if (a[i] == a[i - 1] && a[i - 1] == a[i - 2]) ok = false;
    }
    cout << "Case #" << tc << ": " << (ok ? "YES\n" : "NO\n");
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test;
    cin >> test;
    for (int i = 1; i <= test; i++) solve(i);
}
