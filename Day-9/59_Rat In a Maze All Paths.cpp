#include <bits/stdc++.h> 

int x[4] = {1,0,-1,0};
int y[4] = {0,-1,0,1};

void solve(int i, int j, vector<vector<int>> vis, vector<vector<int>>&ans,
            vector<vector<int>>& maze, int n)
{
  vis[i][j] = 1;
  if(i==n-1 && j==n-1){
    vector<int> temp;
    for(auto v:vis) for(auto it:v)  temp.push_back(it);
    ans.push_back(temp);
    return;
  }

  for(int k=0; k<4; k++){
    int r = i+x[k], c=j+y[k];
    if(r>=0 && c>=0 && r<n && c<n && maze[r][c]==1 && vis[r][c]!=1){
      solve(r,c,vis,ans,maze,n);
    }
  }
  vis[i][j] = 0;
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n)
{
    vector<vector<int>> ans;  
    vector<vector<int>> vis(n,vector<int>(n,0));
    solve(0,0,vis,ans,maze,n);
    return ans;
}