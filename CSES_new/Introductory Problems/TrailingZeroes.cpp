#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	scanf("%lld", &n);
	long long ans=0, curpow=1;
	while (pow(5,curpow) <= n)
	{
		ans += (n/pow(5,curpow));
		curpow++;
	}
	printf("%lld\n", ans);
	return 0;
}
