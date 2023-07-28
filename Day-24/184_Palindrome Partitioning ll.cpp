#include <bits/stdc++.h> 

vector<int> dp;

bool isPalin(string s, int i, int j){
    while(i<j){
        if(s[i]!=s[j])  return false;
        i++;    j--;
    }
    return true;
}

int solve (string& s, int i, int j){     
    if(i>=j or isPalin(s, i, j)) return 0;
    if(dp[i]!=-1) return dp[i];
    
    int ans = INT_MAX;
    for(int k=i; k<j; k++){
        if(isPalin(s, i, k)){                         
            int temp = 1 + solve(s, k+1, j);
            ans = min(ans,temp);
        }
    }
    return dp[i]=ans;
}

int palindromePartitioning(string str) {
    int n=str.length();
    dp.clear();
    dp.resize(n,-1);
    return solve(str, 0, n-1);
}
