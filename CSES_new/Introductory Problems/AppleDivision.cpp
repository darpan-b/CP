#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<long long> a(n);
	for (auto &e :a)
		scanf("%lld", &e);
	long long ans = (long long) 1e18;
	for (int mask = 0; mask < (1<<n); mask++)
	{
		long long lw=0, rw=0;
		for (int i=0; i<n; i++)
		{
			if (mask & (1<<i))
				rw += a[i];
			else
				lw += a[i];
		}
		ans = min(ans, abs(lw-rw));
	}
	printf("%lld\n", ans);
	return 0;
}
