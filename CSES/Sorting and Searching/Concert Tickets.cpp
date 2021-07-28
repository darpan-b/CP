#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	multiset<long long> ms;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		ms.insert(x);
	}
	while (m--) {
		long long x;
		cin >> x;
		if (!ms.empty() && *ms.begin() <= x) {
			auto itr = ms.upper_bound(x);
			--itr;
			cout << *itr << '\n';
			ms.erase(itr);
		} else {
			cout << "-1\n";
		}
	}
	return 0;
}
