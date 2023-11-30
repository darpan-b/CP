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
void dfs(int node, int par)
{
	anc[node][0] = par;
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
		dfs(e,node);
	}
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
	dfs(0,-1);
	while(q--)
	{
		int x,k;
		cin >> x >> k;
		x--;
		int curnode = x;
		for(int i=0; i<LOGN; i++)
		{
			if(curnode == -1) break;
			if(k&(1<<i)) curnode = anc[curnode][i];
		}
		cout << (curnode == -1? curnode:curnode+1) << '\n';
	}
	return 0;	
}
