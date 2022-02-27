#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> set1, set2;
	if(n%4 == 0)
	{
		printf("YES\n");
		for(int i=1; i<=n; i+=4)
		{
			set1.push_back(i);
			set1.push_back(i+3);
			set2.push_back(i+1);
			set2.push_back(i+2);
		}
		printf("%lu\n", set1.size());
		for(auto e : set1)
			printf("%d ", e);
		printf("\n%lu\n", set2.size());
		for(auto e : set2)
			printf("%d ", e);
		printf("\n");
	}
	else if((n-3)%4 == 0)
	{
		printf("YES\n");
		set1.push_back(1);
		set1.push_back(2);
		set2.push_back(3);
		for(int i=4; i<=n; i+=4)
		{
			set1.push_back(i);
			set1.push_back(i+3);
			set2.push_back(i+1);
			set2.push_back(i+2);
		}
		printf("%lu\n", set1.size());
		for(auto e : set1)
			printf("%d ", e);
		printf("\n%lu\n", set2.size());
		for(auto e : set2)
			printf("%d ", e);
		printf("\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}
