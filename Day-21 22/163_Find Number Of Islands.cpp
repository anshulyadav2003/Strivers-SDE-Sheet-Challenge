void dfs(int i, int j, int n, int m, int **grid)
{
   if(i<0 || j<0 || i>=n || j>=m)  return;
   if(grid[i][j]!=1)   return;
   grid[i][j] = 2;
   dfs(i+1,j,n,m,grid);
   dfs(i-1,j,n,m,grid);
   dfs(i,j-1,n,m,grid);
   dfs(i,j+1,n,m,grid);
   dfs(i+1,j+1,n,m,grid);
   dfs(i-1,j+1,n,m,grid);
   dfs(i-1,j-1,n,m,grid);
   dfs(i+1,j-1,n,m,grid);
}

int getTotalIslands(int** grid, int n, int m)
{
   int ans =0;
   for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
            if(grid[i][j]==1){
               ans++;
               dfs(i,j,n,m,grid);
            }
      }
   }
   return ans;
}