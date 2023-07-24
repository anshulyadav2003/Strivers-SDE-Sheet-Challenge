#include <vector>

long countWaysToMakeChange(int *denom, int n, int val){
    if(val==0)  return 1;
    vector<vector<long>> dp(n+1,vector<long>(val+1,0));
    for(int i=0; i<n+1; i++)    dp[i][0] = 1;
    for(int i=1; i<val+1; i++)  dp[0][i] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=val; j++){
            dp[i][j] = dp[i-1][j];
            if(denom[i-1]<=j)
                dp[i][j] = dp[i][j-denom[i-1]] + dp[i-1][j];
        }
    }
    return dp[n][val];
}