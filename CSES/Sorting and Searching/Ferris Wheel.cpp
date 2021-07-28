#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	long long x;
	cin >> n >> x;
	multiset<long long> ms;
	for (int i = 0; i < n; i++) {
		long long e;
		cin >> e;
		ms.insert(e);
	}
	int ans = 0;
	while (!ms.empty()) {
		long long ele = *ms.begin();
		long long other = -1;
		if (ele <= x / 2) {
			auto itr = ms.upper_bound(x - ele);
			if (itr != ms.begin()) --itr;
			if (itr != ms.begin()) other = *itr;
		}
		++ans;
		ms.erase(ms.find(ele));
		if (other != -1 && ele + other <= x) ms.erase(ms.find(other));
	}
	cout << ans << '\n';
	return 0;
}
