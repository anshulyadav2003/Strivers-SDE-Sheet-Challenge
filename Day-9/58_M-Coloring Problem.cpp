#include <bits/stdc++.h> 

bool isSafe(int node, int c, int n, vector<int> color, vector<vector<int>> &adj)
{
    // go for all adjacent nodes of 'node'
    for(int i=0; i<n; i++){
        if(adj[node][i]==0 || node==i)  continue;
        if(color[i]==c)   return false;
    }
    return true;
}

bool solve(int node, int n, vector<int> color, vector<vector<int>> &adj, int m)
{
    if(node==n) return true;

    //at current 'node' try out every possible color 
    for(int k=1; k<=m; k++){
        if(isSafe(node,k,n,color,adj)==false)   continue;
        color[node] = k;
        if(solve(node+1,n,color,adj,m)) return true;
        color[node] = 0;    // back track
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int n = mat.size();
    vector<int> color(n,0);
    bool ans = solve(0,n,color,mat,m);
    return ans ? "YES" : "NO";
}