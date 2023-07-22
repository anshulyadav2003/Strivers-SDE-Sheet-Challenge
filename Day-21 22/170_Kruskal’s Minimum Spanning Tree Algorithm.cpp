#include <bits/stdc++.h> 

class DisjointSet {
public:
    vector<int> parent, rank;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++) parent[i]=i;
    }

    int findPar(int u){
        if(parent[u]==u)   return u;
        return parent[u] = findPar(parent[u]);
    }

    void unionByRank(int u, int v){
        int up = findPar(u);
        int vp = findPar(v);
        if(up==vp)  return;
        if(rank[up]>rank[vp])       parent[vp]=up;
        else if(rank[up]<rank[vp])  parent[up]=vp;
        else{
            parent[vp]=up;
            rank[up]++;
        }
    }
};


bool cmp(vector<int> v1, vector<int> v2){
    return (v1[2]<v2[2]);
}

int kruskalMST(int n, int m, vector<vector<int>> &edges) {
    sort(begin(edges), end(edges),cmp);

    DisjointSet dsu(n);
    int mst=0;
    for(auto it: edges){
        int u=it[0], v=it[1];
        int wt=it[2];
        if(dsu.findPar(u) != dsu.findPar(v)){
            dsu.unionByRank(u,v);
            mst += wt;
        }
    }
    return mst;
}