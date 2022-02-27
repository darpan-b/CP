#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<long long> a(n);
	for (auto &e : a)
		cin >> e;
	long long last = a[0], ans = 0;
	for (int i = 1; i < n; i++)
	{
		ans += max(0LL, last - a[i]);
		last = max(last, a[i]);
	}
	cout << ans << "\n";
	return 0;
}
