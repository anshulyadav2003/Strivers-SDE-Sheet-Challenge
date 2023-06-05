bool searchMatrix(vector<vector<int>>& mat, int x) {
    int n=mat.size(), m=mat[0].size();
    int l=1, r=n*m;
    while(l<=r){
        int mid = (l+(r-l)/2);
        int i=(mid+m-1)/m - 1 , j=(mid-1)%m;
        if(mat[i][j]==x)    return true;
        else if(mat[i][j]<x)    l = mid+1;
        else                    r=mid-1;
    }
    return false;
}