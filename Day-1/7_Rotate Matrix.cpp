#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int top=0, bottom=n-1, left=0, right=m-1;
    while(top<bottom && left<right){
        int last = mat[top][left];
        for(int i=left+1; i<=right; i++){
            int temp = mat[top][i];
            // cout<<temp<<" ";
            mat[top][i]=last;
            last = temp;
        }
        for(int i=top+1; i<=bottom; i++){
            int temp = mat[i][right];
            // cout<<temp<<" ";
            mat[i][right] = last;
            last = temp;
        }
        for(int i=right-1; i>=left; i--){
            int temp = mat[bottom][i];
            // cout<<temp<<" ";
            mat[bottom][i] = last;
            last = temp;
        }
        for(int i=bottom-1; i>=top+1; i--){
            int temp = mat[i][left];
            // cout<<temp<<" ";
            mat[i][left] = last;
            last = temp;
        }
        mat[top][left]=last;
        top++;  bottom--;
        left++; right--;
    }
}