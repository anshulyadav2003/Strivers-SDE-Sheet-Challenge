bool isSafe(int r, int c, vector<vector<int>> board, int n)
{
    int x=r-1,y=c-1;
    while(x>=0 && y>=0){
        if(board[x][y]==1)  return false;
        x--;    y--;
    }

    x=r, y=c-1;
    while(y>=0){
        if(board[x][y]==1)  return false;
        y--;
    }

    x=r+1, y=c-1;
    while(x<n && y>=0){
        if(board[x][y]==1)  return false;
        x++;    y--;
    }

    return true;
}

void solve(int c, int n, vector<vector<int>>& ans, vector<vector<int>> &board)
{
    if(c==n){
        // put board into ans as vector
        vector<int> temp;
        for(auto v:board)
            for(auto it:v)  temp.push_back(it);
        ans.push_back(temp);
        return;
    }


    // in current column, check where our queen will be safe
    for(int r=0; r<n; r++){
        // if Queen is safe then mark in board and make recursive call
        // after returning backtrack changes
        if(isSafe(r,c,board,n)){
            board[r][c] = 1;
            solve(c+1,n,ans,board);
            board[r][c] = 0;
        }
    }

}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> ans;
    vector<vector<int>> board(n,vector<int>(n,0));
    // go column by column
    // and check in that where we can put QUEEN
    solve(0,n,ans,board);
    return ans;
}