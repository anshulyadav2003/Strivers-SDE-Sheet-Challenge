#include <bits/stdc++.h> 

vector<vector<int>> dp;

int solve(int i, int j, int n, int m, vector<vector<int>>& grid){
    if(i==n-1 && j==m-1)    return grid[n-1][m-1];
    if(dp[i][j]!=-1)    return dp[i][j];

    int right=INT_MAX, down=INT_MAX;
    if(i+1<n)   right = grid[i][j] + solve(i+1,j,n,m,grid);
    if(j+1<m)   down = grid[i][j] + solve(i,j+1,n,m,grid);

    return dp[i][j] = min(right, down);
}

int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size(), m=grid[0].size();
    dp.clear();
    dp.resize(n,vector<int>(m,-1));
    return solve(0,0,n,m,grid);
}