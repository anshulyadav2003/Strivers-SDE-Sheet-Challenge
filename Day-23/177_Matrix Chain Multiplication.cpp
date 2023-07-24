#include <bits/stdc++.h> 

vector<vector<int>> dp;

int solve(int i, int j, vector<int>& arr)
{
    if(i==j)    return 0;
    if(dp[i][j]!=-1)    return dp[i][j];

    int ans = INT_MAX;
    for(int k=i; k<j; k++){
        int l = solve(i,k,arr);
        int r = solve(k+1,j,arr);
        int curr = (arr[i-1]*arr[k]*arr[j]) + l + r;
        ans = min(ans, curr);
    }
    return dp[i][j] = ans;
}

int matrixMultiplication(vector<int> &arr, int n) {
    dp.clear();
    dp.resize(n,vector<int>(n,-1));
    return solve(1,n-1,arr);
}