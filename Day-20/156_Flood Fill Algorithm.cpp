void dfs(int i, int j, int n, int m, int newColor, int org, vector<vector<int>>&image)
{
    if(i<0 || i>=image.size()) return;
    if(j<0 || j>=image[0].size()) return;
    if(image[i][j]!=org)   return;

    image[i][j] = newColor;
  
    dfs(i-1,j,n,m,newColor,org,image);
    dfs(i+1,j,n,m,newColor,org,image);
    dfs(i,j-1,n,m,newColor,org,image);
    dfs(i,j+1,n,m,newColor,org,image);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int i, int j, int newColor)
{
    int n = image.size(), m = image[0].size();
    int org = image[i][j];
    if(org==newColor) return image;
    dfs(i,j,n,m,newColor,org,image);
    return image;
}




// #include <queue>
// vector<vector<int>> floodFill(vector<vector<int>> &image, int i, int j, int newColor)
// {
//     int n=image.size();
//     int m=image[0].size();
//     int org = image[i][j];
//     if(org==newColor)   return image;
//     queue<pair<int,int>> q;
//     q.push({i,j});
//     int x[4] = {1,0,-1,0};
//     int y[4] = {0,-1,0,1};
//     while(!q.empty())
//     {
//         int r = q.front().first;
//         int c = q.front().second;
//         q.pop();
//         image[r][c]=newColor;
//         for(int k=0; k<4; k++){
//             int nr=r+x[k];  int nc=c+y[k];
//             if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==org){
//                 q.push({nr,nc});
//             }
//         }
//     }
//     return image;
// }