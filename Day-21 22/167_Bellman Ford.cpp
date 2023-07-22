#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dist(n+1,1e9);
    dist[src]=0;

    //  relax edges (n-1) times
    for(int i=1; i<=n-1; i++){
        for(auto it: edges){
            int u=it[0], v=it[1], wt=it[2];
            if(dist[u]!=1e9 && dist[u]+wt<dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }

    // if negative weight cycle occurs
    // for(auto it: edges){
    //     int u=it[0], v=it[1], wt=it[2];
    //     if(dist[u]!=INT_MAX && dist[u]+wt<dist[v])  return 1e9; 
    // }

    return dist[dest];
}