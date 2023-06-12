#include <bits/stdc++.h> 

bool isPalin(string str){
    int l=0,r=str.length()-1;
    while(l<r){
        if(str[l]!=str[r])  return false;
        l++;   r--;
    }
    return true;
}

void solve(int idx, vector<string> curr,
            vector<vector<string>>& ans, int n, string &s)
{
    if(idx==n){
        ans.push_back(curr);    return;
    }

    for(int k=1; k<=(n-idx); k++){
        string temp = s.substr(idx,k);
        if(isPalin(temp)==false)    continue;
        curr.push_back(temp);
        solve(idx+k,curr,ans,n,s); // recusive call
        curr.pop_back();    // backtrack
    }
}

vector<vector<string>> partition(string &s) 
{
    int n = s.length();
    vector<vector<string>> ans;
    vector<string> curr;
    solve(0,curr,ans,n,s);
    return ans;    
}