#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MOD = (LL) 1e9+7;

LL fxp(LL base, LL power)
{
	if (power == 0)
		return 1LL;
	LL res = fxp(base, power/2);
	res *= res;
	res %= MOD;
	if (power & 1)
		res *= base;
	res %= MOD;
	return res;
}

int main()
{
	LL n;
	scanf("%lld", &n);
	printf("%lld\n", fxp(2,n));
	return 0;
}
