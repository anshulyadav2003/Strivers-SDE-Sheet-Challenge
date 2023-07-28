#include <bits/stdc++.h> 

vector<vector<int>> dp;

bool solve(int i, int j, vector <string>& arr, int n, string& target){
    if(j==target.size())    return true;
    if(i==n)    return false;
    if(dp[i][j]!=2)    return dp[i][j];

    for(auto str: arr){
        int x = str.length();
        bool take = false;
        if(target.size()-j>=x && str==target.substr(j,x))
            take = solve(i,j+x,arr,n,target);
        if(take)    return dp[i][j]=true;
    }

    return dp[i][j]=false;
}

bool wordBreak(vector <string>& arr, int n, string& target) {
    dp.clear();
    int m=target.size();
    dp.resize(n+1,vector<int>(m+1,2));
    return solve(0,0,arr,n,target);
}