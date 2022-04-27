#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,q;
    cin>>n>>m>>q;
    const long long INF=1e15;
    vector<vector<long long>> dist(n,vector<long long>(n,INF));
    for(int i=0;i<m;i++)
    {
        int u,v;
        long long w;
        cin>>u>>v>>w;
        u--; v--;
        dist[u][v]=dist[v][u]=min(dist[u][v],w);
    }
    for(int i=0;i<n;i++)
        dist[i][i]=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
            }
        }
    }

    while(q--)
    {
        int u,v;
        cin>>u>>v;
        u--; v--;
        cout<<(dist[u][v]==INF?-1:dist[u][v])<<"\n";
    }
    return 0;
}
