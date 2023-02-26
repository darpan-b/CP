//Initialize dist[i][j] to inf or edge weight for all i, j before function call
void floyd_warshall(vector<vector<ll>>& dist){
    int n = (int)dist.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(dist[j][k] > dist[j][i] + dist[i][k]){
                    dist[j][k] = dist[j][i] + dist[j][k];
                }
            }
        }
    }
}
