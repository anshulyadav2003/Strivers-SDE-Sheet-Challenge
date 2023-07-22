bool dfs(int node, vector<int> adj[], vector<bool> &vis, int par)
{
    vis[node]=true;
    for(auto it: adj[node]){
        if(!vis[it]){
            if(dfs(it,adj,vis,node))   return true;
        } 
        else if(it!=par)    return true;
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> adj[n+1];
    for(auto it: edges){
        int u=it[0], v=it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n+1,false);
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(dfs(i,adj,vis,-1))    return "Yes";
        }
    }
    return "No";
}
