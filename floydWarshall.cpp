// floyd-warshall algorithm to find all pairs shortest path
// g[i][j] should be initialized to INF before accepting the edge weights as input

ll g[MAXN][MAXN];
int n;

void floyd_warshall(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				if(g[j][k] > g[j][i]+g[i][k]){
					g[j][k] = g[j][i]+g[i][k];
				}
			}
		}
	}
}
