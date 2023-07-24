#include <bits/stdc++.h> 

bool subsetSumToK(int n, int k, vector<int> &arr) {
    if(k==0)  return true;
    vector<vector<bool>> dp(n+1,vector<bool>(k+1,false));
    for(int i=0; i<n+1; i++)    dp[i][0] = true;
    for(int i=1; i<k+1; i++)  dp[0][i] = false;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            dp[i][j] = dp[i-1][j];
            if(arr[i-1]<=j)
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
        }
    }
    return dp[n][k];
}