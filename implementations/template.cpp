#ifdef LOCAL
	#include "debugger.h"
	#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", debug(__VA_ARGS__)
#else
	#define dbg(...) 5
#endif
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second

void solve() {
	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int test; cin >> test;
	while(test--) solve();
	return 0;
}
