/************* BFS question ***********/

#include <queue>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // vector<vector<bool>> vis(n,vector<bool>(m,false));
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]!=2)   continue;
            q.push({i,j});
        }
    }
    int level=0;
    int x[4] = {1,0,-1,0};
    int y[4] = {0,-1,0,1};
    while(!q.empty())
    {
        int size=q.size();
        // cout<<size<<" ";
        while(size--){
            int i=q.front().first, j=q.front().second;
            q.pop();
            for(int k=0; k<4; k++){
                int r=i+x[k], c=j+y[k];
                if(r>=0 && c>=0 && r<n && c<m && grid[r][c]==1){
                  q.push({r, c});
                  grid[r][c]=2;
                }
            }
        }
        level++;
    }
    // not able to rotten all fresh oranges
    for(auto v: grid){
        for(auto it:v){
            if(it==1)   return -1;
        }
    }
    return level==0 ? 0:level-1;
}