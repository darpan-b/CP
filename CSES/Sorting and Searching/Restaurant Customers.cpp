#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<long long> a;
	for (int i = 0; i < n; i++) {
		long long x, y;
		cin >> x >> y;
		a.push_back(x);
		a.push_back(-y);
	}
	sort(a.begin(), a.end(), [&](long long& x, long long& y) {
		return abs(x) < abs(y);
	});
	int ptr = 0;
	int cur = 0, ans = 0;
	while (ptr < 2 * n) {
		long long x = a[ptr];
		while (ptr < 2 * n && abs(a[ptr]) == abs(x)) {
			if (a[ptr] < 0) --cur; else ++cur;
			++ptr;
		}
		ans = max(ans, cur);
	}
	cout << ans << '\n';
	return 0;
}
