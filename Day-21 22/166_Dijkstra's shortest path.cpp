/********************** Using set ***************************/
#include <bits/stdc++.h> 
#define pi pair<int,int>
vector<int> dijkstra(vector<vector<int>> &edges, int n, int m, int src) {
    vector<vector<int>> adj[n];
    for(auto it: edges){
        int u=it[0], v=it[1], wt=it[2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    set<pi> st;
    st.insert({0,src});
    vector<int> dist(n,INT_MAX);
    dist[src]=0;
    while(!st.empty()){
        auto curr = *st.begin();
        int node = curr.second;
        int d = curr.first;
        st.erase(st.begin());
        for(auto it: adj[node]){
            int v = it[0];
            int wt = it[1];
            if(d+wt < dist[v]){
                if(dist[v]!=INT_MAX){
                    st.erase({dist[v],v});
                }
                dist[v] = d+wt;
                st.insert({dist[v],v});
            }
        }
    }
    return dist;
}




/********************** Priority Queue **********************/
#include <bits/stdc++.h> 
#define pi pair<int,int>
vector<int> dijkstra(vector<vector<int>> &edges, int n, int m, int src) {
    vector<vector<int>> adj[n];
    for(auto it: edges){
        int u=it[0], v=it[1], wt=it[2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0,src});
    vector<int> dist(n,INT_MAX);
    dist[src]=0;
    while(!pq.empty()){
        auto curr = pq.top();
        int node = curr.second;
        int d = curr.first;
        pq.pop();
        for(auto it: adj[node]){
            int v = it[0];
            int wt = it[1];
            if(d+wt < dist[v]){
                dist[v] = d+wt;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}
