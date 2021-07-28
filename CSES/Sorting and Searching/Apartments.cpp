#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<long long> a(n), b(m);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int ans = 0;
	int aptr = 0, bptr = 0;
	while (aptr < n && bptr < m) {
		if (abs(a[aptr] - b[bptr]) <= k) {
			++aptr;
			++bptr;
			++ans;
		} else if (a[aptr] < b[bptr]) {
			++aptr;
		} else {
			++bptr;
		}
	}
	cout << ans << '\n';
	return 0;
}
