#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

#define ll long long

#define YES cout << "Case #" << tc << ": YES\n"
#define NO cout << "Case #" << tc << ": NO\n"

void solve(int tc)
{
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto& e : a) cin >> e;
    for (auto& e : b) cin >> e;
    bool is_equal = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i]) is_equal = false;
    }
    if (k == 0)
    {
        if (is_equal) YES;
        else NO;
        return;
    }
    if (is_equal)
    {
        if (k == 1)
        {
            NO;
        }
        else if (n == 2)
        {
            if (k % 2 == 1) NO;
            else YES;
        }
        else 
        {
            YES;
        }
        return;
    }
    if (n == 2)
    {
        if (k % 2 == 0) NO;
        else YES;
        return;
    }
    int bidx = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == a[0])
        {
            bidx = i;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[(bidx+i)%n])
        {
            NO;
            return;
        }
    }
    YES;
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
    return 0;
}
