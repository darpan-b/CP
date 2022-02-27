#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
 
void solve()
{
	LL x, y;
	scanf("%lld%lld", &x, &y);
	LL ans = 0;
	if (x >= y)
	{
		if (x%2 == 0)
			ans = x*x - y + 1;
		else
			ans = (x-1)*(x-1) + y;
	}
	else
	{
		if (y%2 != 0)
			ans = y*y - x + 1;
		else
			ans = (y-1)*(y-1) + x;
	}
	printf("%lld\n", ans);
}
 
int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
		solve();
	return 0;
}
