#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void solve()
{
	LL L, R;
	scanf("%lld%lld", &L, &R);
	LL P = -1, Q = -1;
	if ((2*L - R)%3 == 0)
	{
		Q = (2*L - R)/3;
		P = L - 2*Q;
	}
	else if ((2*R - L)%3 == 0)
	{
		Q = (2*R - L)/3;
		P = R - 2*Q;
	}
	if (P>=0 && Q>=0)
		printf("YES\n");
	else
		printf("NO\n");
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
		solve();
	return 0;
}
