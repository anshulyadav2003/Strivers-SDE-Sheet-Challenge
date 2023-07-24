#include <bits/stdc++.h>
int editDistance(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));
    for(int i=0; i<=n1; i++)    dp[i][0] = i;
    for(int i=0; i<=n2; i++)    dp[0][i] = i;

    for(int i=1; i<=n1; i++){
        for(int j=1; j<=n2; j++){
            if(s1[i-1]==s2[j-1])    
                dp[i][j] = dp[i-1][j-1];
            else{
                int del = dp[i-1][j];
                int rep = dp[i-1][j-1];
                int ins = dp[i][j-1];
                dp[i][j] = 1+ min({del,rep,ins});
            }
        }
    }
    return dp[n1][n2];
}