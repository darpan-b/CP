#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

#define ll long long

const int INF = 1e9;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(auto& e:grid){
        cin >> e;
    }

    vector<vector<char>> par(n, vector<char>(m, '?'));
    vector<vector<int>> dist(n, vector<int>(m, INF));
    queue<pair<int, pair<int,int>>> bfs;

    for(int i = 0; i < n && bfs.empty(); i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'A'){
                dist[i][j] = 0;
                bfs.push({0, {i,j}});
                break;
            }
        }
    }

    auto is_valid = [&](int x,int y){
        return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
    };

    while(!bfs.empty()){
        auto cur = bfs.front();
        bfs.pop();
        int x = cur.second.first, y = cur.second.second, d = cur.first;
        if(dist[x][y] != d){
            continue;
        }
        for(int i = 0; i < 4; i++){
            int cx = x+dx[i];
            int cy = y+dy[i];
            if(is_valid(cx,cy) && dist[cx][cy] > d+1){
                dist[cx][cy] = d+1;
                if(i == 0){
                    par[cx][cy] = 'U';
                }
                else if(i == 1){
                    par[cx][cy] = 'D';
                }
                else if(i == 2){
                    par[cx][cy] = 'L';
                }
                else{
                    par[cx][cy] = 'R';
                }
                bfs.push({dist[cx][cy], {cx,cy}});
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'B'){
                if(dist[i][j] == INF){
                    cout << "NO\n";
                    return 0;
                }
                cout << "YES\n" << dist[i][j] << "\n";
                string ans = "";
                int cx = i, cy = j;
                while(grid[cx][cy] != 'A'){
                    ans += par[cx][cy];
                    if(par[cx][cy] == 'U'){
                        cx++;
                    }
                    else if(par[cx][cy] == 'D'){
                        cx--;
                    }
                    else if(par[cx][cy] == 'L'){
                        cy++;
                    }
                    else{
                        cy--;
                    }
                }
                reverse(ans.begin(),ans.end());
                cout << ans << "\n";
                return 0;
            }
        }
    }
    return 0;
}
