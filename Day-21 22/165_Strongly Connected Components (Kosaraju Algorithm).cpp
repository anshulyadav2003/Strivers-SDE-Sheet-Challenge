/************ KOSARAJU ALGO ****************/
#include <stack>
void dfsSort(int node, vector<int> adj[], vector<bool> &vis, stack<int> &st)
{
    vis[node]=true;
    for(auto it: adj[node]){
        if(!vis[it])    dfsSort(it,adj,vis,st);
    }
    st.push(node);
}

void dfs(int node, vector<int> adj[], vector<bool> &vis, vector<int> &comp)
{
    vis[node]=true;
    comp.push_back(node);
    for(auto it: adj[node]){
        if(!vis[it])    dfs(it,adj,vis,comp);
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // make adjacency list
    vector<int> adj[n];
    for(auto it: edges){
        int u=it[0], v=it[1];
        adj[u].push_back(v);
    }

    // sort according to finish time using DFS and store in stack
    stack<int> st;
    vector<bool> vis(n,false);
    for(int i=0; i<n; i++){
        if(!vis[i]) 
            dfsSort(i,adj,vis,st);
    }

    // reverse the adjacency list
    for(int i=0; i<n; i++)  adj[i].clear();
    for(auto it: edges){
        int u=it[0], v=it[1];
        adj[v].push_back(u);
    }

    vector<vector<int>> scc;
    for(int i=0; i<n; i++)  vis[i]=false;
    while(!st.empty()){
        auto node = st.top();
        st.pop();
        if(vis[node])   continue;

        vector<int> comp;
        dfs(node,adj,vis,comp);
        scc.push_back(comp);
    }
    return scc;
}