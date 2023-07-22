#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int n, int m)  {
    vector<int> adj[n];
    vector<int> indeg(n,0);
    for(auto it: edges){
        int u=it[0], v=it[1];
        adj[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;
    for(int i=0; i<n; i++){
        if(indeg[i]==0) q.push(i);
    }

    vector<int> topo;
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it: adj[node]){
            if(--indeg[it]==0)  q.push(it);
        }
    }
    return topo;
}