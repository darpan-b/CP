#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	scanf("%lld", &n);
	for (long long i=1; i<=n; i++)
		printf("%lld\n", (i*i * (i*i-1))/2 - (i-1)*(i-2)*4);
	return 0;
}

