// c-style mess

#include <stdio.h>

int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	long long a[n];
	for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	long long pre[n];
	pre[0]=a[0];
	for(int i=1;i<n;i++)
		pre[i]=pre[i-1]+a[i];
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		l--; r--;
		long long ans=pre[r];
		if(l>0)
			ans-=pre[l-1];
		printf("%lld\n",ans);
	}
	return 0;
}
