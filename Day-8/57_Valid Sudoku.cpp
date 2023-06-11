bool isPossible(int mat[9][9], int row, int col, int val)
{
  for(int i=0; i<9; i++) {
    // check in row
    if(mat[i][col]==val)   return false;
    // check in col
    if(mat[row][i]==val)  return false;
    // check in sub-matrix in which (row,col) cell lies
    if(mat[3*(row/3) + i/3][3*(col/3) + i%3] == val)
      return false;
  }
  return true;
}

bool solve(int mat[9][9]) 
{
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            if (mat[i][j]!=0) continue;
            // find possible val for non-empty cell
            for (int val=1; val<=9; val++) {
                if(isPossible(mat,i,j,val)) {
                    mat[i][j] = val;
                    if(solve(mat))   return true;
                    mat[i][j] = 0;  // backtrack
                }
            }
            // if val is possible for non-empty cell
            return false;
        }
    }
    // no empty cell is found
    // that means our matrix if completely filled
    return true;
}

bool isItSudoku(int mat[9][9]) {
    return solve(mat);
}
