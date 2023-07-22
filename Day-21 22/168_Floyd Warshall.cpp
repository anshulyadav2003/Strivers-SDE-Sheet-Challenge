int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<vector<int>> dist(n+1,vector<int>(n+1,1e9));
    for(int i=1; i<=n; i++) 
        dist[i][i]=0;
    
    // put edges in 'dist' matrix
    for(auto it: edges){
        int u=it[0], v=it[1], wt=it[2];
        dist[u][v] = wt;
    }

    // DP kinda approach
    for(int k=1; k<=n; k++){
        for(int u=1; u<=n; u++){
            for(int v=1; v<=n; v++){
                if(dist[u][k]==1e9 || dist[k][v]==1e9)   continue;
                dist[u][v] = min(dist[u][v], dist[u][k]+dist[k][v]);
            }
        }
    }

    return dist[src][dest];
}