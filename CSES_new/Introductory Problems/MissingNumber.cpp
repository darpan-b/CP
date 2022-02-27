#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n;
	scanf("%d", &n);
	vector<int> a(n-1);
	for (int i=0; i<n-1; i++)
		scanf("%d", &a[i]);
	long long sum=0;
	for(int i=0; i<n-1; i++)
		sum += a[i];
	printf("%lld\n", (n*(n+1LL))/2 - sum);
	return 0;
}
