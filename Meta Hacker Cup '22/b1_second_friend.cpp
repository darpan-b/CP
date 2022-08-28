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
    int n, m;
    cin >> n >> m;
    bool tree = false;
    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        tree |= count(str.begin(), str.end(), '^') != 0;
    }
    
    if ((n == 1 || m == 1) && tree)
    {
        cout << "Case #" << tc << ": Impossible\n";
        return;
    }

    cout << "Case #" << tc << ": Possible\n";
    if (tree)
    {
        for (int i = 0; i < n; i++) cout << string(m, '^') << "\n";
    }
    else
    {
        for (int i = 0; i < n; i++) cout << string(m, '.') << "\n";
    }
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
