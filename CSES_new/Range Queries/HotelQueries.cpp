#include <bits/stdc++.h>
using namespace std;

const int MAXN=2e5+5;
long long a[MAXN];
long long seg[4*MAXN];

void build(int node,int ss,int se)
{
	if(ss>se)return;
	if(ss==se)
	{
		seg[node]=a[ss];
		return;
	}
	int mid=(ss+se)/2;
	build(node*2+1,ss,mid);
	build(node*2+2,mid+1,se);
	seg[node]=max(seg[node*2+1],seg[node*2+2]);
}

void update(int node,int ss,int se,int idx,long long val)
{
	if(ss>se || ss>idx || se<idx)return;
	if(ss==se && ss==idx)
	{
		seg[node]-=val;
		return;
	}
	int mid=(ss+se)/2;
	update(node*2+1,ss,mid,idx,val);
	update(node*2+2,mid+1,se,idx,val);
	seg[node]=max(seg[node*2+1],seg[node*2+2]);
}

long long query(int node,int ss,int se,int qs,int qe)
{
	if(ss>se || qs>se || qe<ss)return 0;
	if(ss>=qs && se<=qe)return seg[node];
	int mid=(ss+se)/2;
	long long ql=query(node*2+1,ss,mid,qs,qe);
	long long qr=query(node*2+2,mid+1,se,qs,qe);
	return max(ql,qr);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	build(0,0,n-1);

	while(m--)
	{
		long long val;
		cin>>val;
		long long maxQ=query(0,0,n-1,0,n-1);
		if(maxQ<val)
		{
			cout<<0<<" ";
			continue;
		}
		int lo=0,hi=n-1,mid;
		while(lo<hi)
		{
			mid=(lo+hi)/2;
			long long q=query(0,0,n-1,lo,mid);
			if(q>=val)hi=mid;
			else lo=mid+1;
		}
		cout<<lo+1<<" ";
		update(0,0,n-1,lo,val);
	}
	cout<<"\n";
	return 0;
}
