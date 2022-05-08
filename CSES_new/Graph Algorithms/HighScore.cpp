#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

const int MAXN = 2505;
const long long INF = 1e18;
int n,m;
vector<pair<pair<int,int>,long long>> edges;
vector<pair<int,long long>> adj[MAXN];
vector<pair<int,long long>> adj2[MAXN];
long long dist[MAXN];
bool changed[MAXN], vis[MAXN], vis2[MAXN];

void dfs(int node)
{
	vis[node] = true;
	for(auto &u : adj[node])
	{
		if(!vis[u.first]) dfs(u.first);
	}
}

void dfs2(int node)
{
	vis2[node] = true;
	for(auto &u : adj2[node])
	{
		if(!vis2[u.first]) dfs2(u.first);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i=0; i<m; i++)
	{
		int u,v;
		long long w;
		cin >> u >> v >> w;
		u--; v--;
		adj[v].push_back({u,w});
		adj2[u].push_back({v,w});
		edges.push_back({{u,v}, -w});
	}
	dist[0] = 0;
	for(int i=1; i<n; i++) dist[i] = INF;
	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(dist[edges[j].first.second] > dist[edges[j].first.first]+edges[j].second)
			{
				dist[edges[j].first.second] = dist[edges[j].first.first]+edges[j].second;
			}
		}
	}
	dfs(n-1);
	dfs2(0);
	for(int i=0; i<m; i++)
	{
		if(dist[edges[i].first.second] > dist[edges[i].first.first]+edges[i].second)
		{

			dist[edges[i].first.second] = dist[edges[i].first.first]+edges[i].second;
			// changed[edges[i].first.first] = true;
			// changed[edges[i].first.second] = true;
			if(vis[edges[i].first.second] && vis2[edges[i].first.second])
			{
				cout << -1 << "\n";
				return 0;
			}
		}
	}
	long long ans = -dist[n-1];
	// for(int i=0; i<n; i++)
	// {
	// 	dbg(i,vis[i],changed[i]);
	// 	if(vis[i] && vis2[i] && changed[i])
	// 	{
	// 		cout << -1 << "\n";
	// 		return 0;
	// 	}
	// }
	cout << ans << "\n";
	return 0;
}
