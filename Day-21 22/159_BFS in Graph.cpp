#include <bits/stdc++.h> 
vector<int> BFS(int V, vector<pair<int, int>> edges)
{
    // make adj list
    vector<int> adj[V];
    for(auto it: edges){
        int u=it.first, v=it.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0; i<V; i++)  
        sort(begin(adj[i]),end(adj[i]));
    
    vector<int> ans;
    vector<bool> vis(V,0);
    queue<int> q;
    for(int i=0; i<V; i++){ // for all disconnected components
        if(vis[i]==true)    continue;
        q.push(i);
        vis[i]=true;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=true;
                }
            }
        }
    }
    return ans;
}