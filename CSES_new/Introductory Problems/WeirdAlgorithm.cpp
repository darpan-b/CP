#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	scanf("%lld", &n);
	while(true)
	{
		printf("%lld ", n);
		if(n == 1)
			break;
		if(n%2 == 0)
			n /= 2;
		else
			n = n*3 + 1;
	}
	return 0;
}
