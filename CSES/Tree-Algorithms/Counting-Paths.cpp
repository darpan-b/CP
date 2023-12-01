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
int tin[MAXN], tout[MAXN];
int pref[MAXN*2+5];
int timer = -1;
void dfs(int node, int par)
{
	tin[node] = ++timer;
	for(auto e:adj[node])
	{
		if(e == par) continue;
		dfs(e,node);
	}
	tout[node] = ++timer;
}
int anc[MAXN][LOGN];
int depth[MAXN];
void dfs_lca(int node, int par, int dep)
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
		dfs_lca(e,node,dep+1);
	}
}
int query_lca(int u, int v)
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
	return anc[u][0];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,q;
	cin >> n >> q;
	for(int i=0; i<n-1; i++)
	{
		int u,v;
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0,-1);
	dfs_lca(0,-1,0);
	while(q--)
	{
		int u,v;
		cin >> u >> v;
		u--; v--;
		int lca = query_lca(u,v);
		pref[tin[lca]]++;
		pref[tin[u]+1]--;
		pref[tin[lca]]++;
		pref[tin[v]+1]--;
		pref[tin[lca]]--;
		pref[tin[lca]+1]++;
	}
	for(int i=1; i<=timer; i++)
		pref[i] += pref[i-1];
	for(int i=0; i<n; i++)
		cout << pref[tin[i]]-pref[tout[i]] << " ";
	cout << "\n";
	return 0;
}
