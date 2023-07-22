bool dfs(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &dfsvis) {
  vis[node]=true;
  dfsvis[node]=true;
  for(auto it: adj[node]){
    if(!vis[it]){
      if(dfs(it, adj, vis, dfsvis)) return true;
    } 
    else if(dfsvis[it]) return true;
  }
  dfsvis[node] = false;
  return false;
}


int detectCycleInDirectedGraph(int n, vector <pair < int, int >> & edges) {
  vector<int> adj[n+1];
  for(auto it: edges){
    int u=it.first, v=it.second;
    adj[u].push_back(v);
  }

  vector<bool> vis(n+1,false);
  vector<bool> dfsvis(n+1,false);
  for(int i=1; i<=n; i++){
    if(!vis[i]){
      if(dfs(i,adj,vis,dfsvis)) return 1;
    }
  }
  return 0;
}