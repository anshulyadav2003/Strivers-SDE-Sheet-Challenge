void solve(int node, vector<int> &vis, vector<int> &comp, vector<int> adj[])
{
    comp.push_back(node);
    vis[node]=true;
    for(auto it: adj[node]){
        if(!vis[it]){
            solve(it,vis,comp,adj);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;

    // make adj list
    vector<int> adj[V];
    for(auto it: edges){
        int u=it[0], v=it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> vis(V,0);
    for(int i=0; i<V; i++){
        if(!vis[i]){
            vector<int> comp;
            solve(i,vis,comp,adj);
            ans.push_back(comp);
        }
    }
    return ans;
}