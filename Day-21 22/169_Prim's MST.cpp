#include <bits/stdc++.h>
#define vi vector<int>

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &edges)
{
    vector<vector<int>> adj[n+1];
    for(auto it: edges){
        int u=it.first.first, v=it.first.second;
        int wt=it.second;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    vector<pair<pair<int, int>, int>> mst;
    vector<bool> vis(n+1,false);
    priority_queue<vi, vector<vi>, greater<vi>> pq;
    pq.push({0,1,-1});
    while(!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        int weight=curr[0], node=curr[1], par=curr[2];

        // if already visited node then continue;
        if(vis[node]==true) continue;
        vis[node]=true; // if not already , then mark visited

        if(par!=-1) mst.push_back({{par,node},weight}); // other than first node, push this edge into MST

        for(auto it: adj[node]){
            int adjNode=it[0], edWt=it[1];
            if(!vis[adjNode]){
                pq.push({edWt,adjNode,node});
            }
        }
    }
    return mst;
}
