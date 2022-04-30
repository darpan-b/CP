#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN=2e5+5;
ll arr[MAXN];
ll seg[4*MAXN],lazy[4*MAXN];

void build(int node,int ss,int se)
{
	if(ss>se)return;
	if(ss==se)
	{
		seg[node]=arr[ss];
		return;
	}
	int mid=(ss+se)/2;
	build(node*2+1,ss,mid);
	build(node*2+2,mid+1,se);
	seg[node]=seg[node*2+1]+seg[node*2+2];
}

void push(int node,int ss,int se)
{
	seg[node]+=lazy[node];
	if(ss<se)
	{
		lazy[node*2+1]+=lazy[node];
		lazy[node*2+2]+=lazy[node];
	}
	lazy[node]=0;
}

void update(int node,int ss,int se,int us,int ue,ll val)
{
	if(ss>se || us>se || ue<ss)return;
	push(node,ss,se);
	if(ss>=us && se<=ue)
	{
		seg[node]+=val;
		if(ss<se)
		{
			lazy[node*2+1]+=val;
			lazy[node*2+2]+=val;
		}
	}
	else
	{
		int mid=(ss+se)/2;
		update(node*2+1,ss,mid,us,ue,val);
		update(node*2+2,mid+1,se,us,ue,val);
		seg[node]=seg[node*2+1]+seg[node*2+2];
	}
}

ll query(int node,int ss,int se,int qs,int qe)
{
	if(ss>se || qs>se || qe<ss)return 0;
	push(node,ss,se);
	if(ss>=qs && se<=qe)return seg[node];
	int mid=(ss+se)/2;
	ll ql=query(node*2+1,ss,mid,qs,qe);
	ll qr=query(node*2+2,mid+1,se,qs,qe);
	return ql+qr;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++)cin>>arr[i];
	build(0,0,n-1);

	while(q--)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			int l,r;
			ll val;
			cin>>l>>r>>val;
			l--; r--;
			update(0,0,n-1,l,r,val);
		}
		else
		{
			int idx;
			cin>>idx;
			idx--;
			cout<<query(0,0,n-1,idx,idx)<<"\n";
		}
	}
	return 0;
}
