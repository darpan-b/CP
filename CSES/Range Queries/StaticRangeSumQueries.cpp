#include <bits/stdc++.h>

#ifdef LOCAL

#include "/home/winxtron/CLionProjects/cp_clion/debugger.h"

#else
#define dbg(...) 5
#endif

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    for (auto& e : a)
        cin >> e;
    partial_sum(a.begin(), a.end(), a.begin());

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        r--;
        l--;
        long long ans = a[r];
        if (l)
            ans -= a[l - 1];
        cout << ans << "\n";
    }
    return 0;
}
