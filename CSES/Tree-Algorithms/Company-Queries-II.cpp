#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif
#define ll long long
const int MAXN = 2e5+5;
const int LOGN = __lg(MAXN)+2;
vector<int> adj[MAXN];
int anc[MAXN][LOGN]; // anc[node][k] stores (1<<k)th ancestor of node
int depth[MAXN];
void dfs(int node, int par, int dep)
{
	anc[node][0] = par;
	depth[node] = dep;
	for(int i=1; i<LOGN; i++)
	{
		if(anc[node][i-1] == -1)
			anc[node][i] = -1;
		else
			anc[node][i] = anc[anc[node][i-1]][i-1];
	}
	for(auto e:adj[node])
	{
		if(e == par) continue;
		dfs(e,node,dep+1);
	}
}
int query(int u, int v)
{
	if(depth[u]<depth[v]) swap(u,v);
	for(int i=LOGN-1; i>=0; i--)
	{
		if(depth[u]-(1<<i) >= depth[v]) u = anc[u][i];
	}
	if(u == v) return u;
	for(int i=LOGN-1; i>=0; i--)
	{
		if(anc[u][i] != anc[v][i])
		{
			u = anc[u][i];
			v = anc[v][i];
		}
	}
	dbg(u,v,anc[u][0],anc[v][0]);
	int res = anc[u][0];
	assert(res == anc[v][0]);
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,q;
	cin >> n >> q;
	for(int i=1; i<n; i++)
	{
		int boss;
		cin >> boss; boss--;
		adj[i].push_back(boss);
		adj[boss].push_back(i);
	}
	dfs(0,-1,0);
	while(q--)
	{
		int u,v;
		cin >> u >> v;
		u--; v--;
		cout << query(u,v)+1 << "\n";
	}
	return 0;	
}
