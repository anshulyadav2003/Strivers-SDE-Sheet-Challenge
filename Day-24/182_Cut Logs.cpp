#include <bits/stdc++.h>

// exact same to EGG DROPPING Problem
vector<vector<int>> dp;
int solve(int k, int n){
    if(k==1 || n==1 || n==0)    return n;
    if(dp[k][n]!=-1)    return dp[k][n];

    int ans = INT_MAX;
    int low=1, high=n;
    while(low<=high){ // Binary search to get rid of TLE 
        int mid = (low+high)>>1;
        int success = solve(k,n-mid);
        int fail = solve(k-1,mid-1);
        ans = min(ans, 1+max(success, fail));
        if(fail < success)  low = mid+1;
        else                high = mid-1;
    }
    return dp[k][n] = ans;
}

int cutLogs(int k, int n){
    if(k==1 || n==1)    return n;
    dp.clear();
    dp.resize(k+1, vector<int>(n+1,-1));
    return solve(k,n);
}



