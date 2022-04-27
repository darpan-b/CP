#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

#define pii pair<int,int>
#define F first
#define S second

int main()
{
    int n,m;
    cin>>n>>m;
    vector<string> grid(n);
    for(auto& i:grid)
        cin>>i;
    
    const int INF=1e9;
    const array<int,4> dx={-1,1,0,0};
    const array<int,4> dy={0,0,1,-1};

    vector<vector<int>> monsDP(n,vector<int>(m,INF));
    queue<pair<pii,int>> bfs;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='M')
            {
                bfs.push({{i,j},0});
                monsDP[i][j]=0;
            }
        }
    }

    auto isValid=[&](int x,int y)
    {
        return x>=0 && x<n && y>=0 && y<m;
    };

    while(!bfs.empty())
    {
        auto cur=bfs.front();
        dbg(cur,bfs.size());
        bfs.pop();
        // if(monsDP[cur.F.F][cur.F.S]<cur.S)
        //     continue;

        for(int i=0;i<4;i++)
        {
            if(isValid(cur.F.F+dx[i],cur.F.S+dy[i]) && grid[cur.F.F+dx[i]][cur.F.S+dy[i]]!='#')
            {
                dbg(cur.F.F+dx[i],cur.F.S+dy[i],cur.S+1,monsDP[cur.F.F+dx[i]][cur.F.S+dy[i]]);

                if(monsDP[cur.F.F+dx[i]][cur.F.S+dy[i]]>cur.S+1)
                {
                    // dbg(cur.F.F+dx[i],cur.F.S+dy[i],cur.S+1);
                    monsDP[cur.F.F+dx[i]][cur.F.S+dy[i]]=cur.S+1;
                    bfs.push({{cur.F.F+dx[i],cur.F.S+dy[i]},cur.S+1});
                }
            }            
        }
    }
    dbg(monsDP);
    dbg("mons DP DONE");

    vector<vector<int>> myDP(n,vector<int>(m,INF));
    queue<pair<pii,int>> bfs2;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='A')
            {
                bfs2.push({{i,j},0});
                myDP[i][j]=0;
            }
        }
    }
    while(!bfs2.empty())
    {
        auto cur=bfs2.front();
        bfs2.pop();
        // if(myDP[cur.F.F][cur.F.S]<cur.S)
        //     continue;
        dbg(cur);

        for(int i=0;i<4;i++)
        {
            if(isValid(cur.F.F+dx[i],cur.F.S+dy[i]) && grid[cur.F.F+dx[i]][cur.F.S+dy[i]]!='#')
            {
                if(myDP[cur.F.F+dx[i]][cur.F.S+dy[i]]>cur.S+1)
                {
                    myDP[cur.F.F+dx[i]][cur.F.S+dy[i]]=cur.S+1;
                    bfs2.push({{cur.F.F+dx[i],cur.F.S+dy[i]},cur.S+1});
                }
            }            
        }        
    }
    dbg(myDP);

    auto isCornerCell=[&](int x,int y)
    {
        return x==0 || y==0 || x==n-1 || y==m-1;
    };

    pii startingCell={-1,-1};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(isCornerCell(i,j) && grid[i][j]!='#')
            {
                if(myDP[i][j]<monsDP[i][j])
                {
                    startingCell={i,j};
                    break;
                }
            }
        }
    }
    dbg(startingCell);

    if(startingCell.F==-1)
    {
        cout<<"NO\n";
        return 0;
    }

    vector<pii> ansCells;
    pii curCell=startingCell;
    vector<vector<bool>> done(n,vector<bool>(m,false));
    while(true)
    {
        ansCells.push_back(curCell);
        done[curCell.F][curCell.S]=true;
        dbg(ansCells);
        if(myDP[curCell.F][curCell.S]==0)
            break;
        for(int i=0;i<4;i++)
        {
            if(isValid(curCell.F+dx[i],curCell.S+dy[i]) && 
                myDP[curCell.F+dx[i]][curCell.S+dy[i]]<monsDP[curCell.F+dx[i]][curCell.S+dy[i]] &&
                !done[curCell.F+dx[i]][curCell.S+dy[i]])
            {
                curCell.F+=dx[i];
                curCell.S+=dy[i];                
                break;
            }
        }
        if(curCell==ansCells.back())
        {
            cout << "NO\n";
            return 0;
        }
    }

    string ans="";
    int ansSz=ansCells.size()-1;
    for(int i=0;i<ansSz;i++)
    {
        if(ansCells[i+1].F==ansCells[i].F+1)
            ans+='U';
        else if(ansCells[i+1].F==ansCells[i].F-1)
            ans+='D';
        else if(ansCells[i+1].S==ansCells[i].S+1)
            ans+='L';
        else
            ans+='R';
    }
    reverse(ans.begin(),ans.end());

    cout<<"YES\n";
    cout<<ansSz<<"\n"<<ans<<"\n";
    return 0;
}
