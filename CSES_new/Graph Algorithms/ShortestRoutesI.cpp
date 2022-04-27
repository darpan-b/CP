#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e5+5;
const long long INF=1e18;
vector<pair<int,long long>> adj[MAXN];
long long dist[MAXN];
bool done[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        long long w;
        cin>>u>>v>>w;
        u--; v--;
        adj[u].push_back({v,w});
    }

    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> pq;
    for(int i=1;i<n;i++)
        dist[i]=INF;
    pq.push({0,0});
    // done[0]=true;
    while(!pq.empty())
    {
        auto node=pq.top();
        pq.pop();
        if(done[node.second])
            continue;
        done[node.second]=true;
        // if(dist[node.second]>node.first)
        //     continue;
        for(auto& u:adj[node.second])
        {
            if(dist[u.first]>dist[node.second]+u.second)
            {
                dist[u.first]=dist[node.second]+u.second;
                pq.push({dist[u.first],u.first});
            }
        }
    }

    for(int i=0;i<n;i++)
        cout<<dist[i]<<" ";
    cout<<"\n";
    return 0;
}
