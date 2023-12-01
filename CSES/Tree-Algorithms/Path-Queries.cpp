#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif
#define ll long long
const int MAXN = 2e5+5;
int tin[MAXN], tout[MAXN];
ll value[MAXN];
int timer = -1;
vector<int> adj[MAXN];
vector<ll> euler;
void dfs(int node, int par)
{
	tin[node] = ++timer;
	euler.push_back(value[node]);
	for(auto e:adj[node])
	{
		if(e == par) continue;
		dfs(e,node);
	}
	tout[node] = ++timer;
	euler.push_back(-value[node]);
}
template<typename T>
struct SegmentTree
{
	vector<T> seg;
	SegmentTree(){}
	SegmentTree(int n){ seg.assign(4*n,0LL); }
	void build(int node, int ss, int se, vector<T>& arr)
	{
		if(ss>se) return;
		if(ss == se) seg[node] = arr[ss];
		else
		{
			int mid = (ss+se)/2;
			build(node*2+1, ss, mid, arr);
			build(node*2+2, mid+1, se, arr);
			seg[node] = seg[node*2+1]+seg[node*2+2];
		}
	}
	void update(int node, int ss, int se, int uidx, T val)
	{
		if(ss>se || uidx>se || uidx<ss) return;
		if(ss>=uidx && se<=uidx) seg[node] = val;
		else
		{
			int mid = (ss+se)/2;
			update(node*2+1,ss,mid,uidx,val);
			update(node*2+2,mid+1,se,uidx,val);
			seg[node] = seg[node*2+1]+seg[node*2+2];
		}
	}
	T query(int node, int ss, int se, int qs, int qe)
	{
		if(ss>se || qs>se || qe<ss) return 0;
		if(ss>=qs && se<=qe) return seg[node];
		int mid = (ss+se)/2;
		T q1 = query(node*2+1,ss,mid,qs,qe);
		T q2 = query(node*2+2,mid+1,se,qs,qe);
		return q1+q2;
	}
};
int main()
{
	int n,q;
	cin >> n >> q;
	for(int i=0; i<n; i++) cin >> value[i];
	for(int i=0; i<n-1; i++)
	{
		int u,v;
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0,-1);
	int esz = euler.size();
	SegmentTree<ll> segtree(esz);
	segtree.build(0,0,esz-1,euler);
	while(q--)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			int u; ll val;
			cin >> u >> val; u--;
			segtree.update(0,0,esz-1,tin[u],val);
			segtree.update(0,0,esz-1,tout[u],-val);
		}
		else
		{
			int u;
			cin >> u; u--;
			cout << segtree.query(0,0,esz-1,tin[0],tin[u]) << "\n";
		}
	}
	return 0;
}
