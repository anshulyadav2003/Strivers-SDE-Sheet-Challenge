/***********Bit manipulation ***********/
#include <bits/stdc++.h> 
vector<vector<int>> pwset(vector<int>v)
{
    int n=v.size();
    vector<vector<int>> ans;
    int size = pow(2,n);
    for(int k=0; k<size; k++)
    {
        vector<int> curr;
        for(int i=0; i<n; i++){
            if(k&(1<<i)) curr.push_back(v[i]);
        }
        ans.push_back(curr);
    }
    return ans;
}

/********** Recursion & Backtrack solution*/
#include <bits/stdc++.h> 

void solve(int i, vector<int> v, vector<int> curr, vector<vector<int>> &ans, int n)
{
    if(i==n){
        ans.push_back(curr);    return;
    }
    
    //take it
    curr.push_back(v[i]);
    solve(i+1,v,curr,ans,n);
    // donot take
    curr.pop_back();
    solve(i+1,v,curr,ans,n);
}

vector<vector<int>> pwset(vector<int>v)
{
    int n=v.size();
    vector<vector<int>> ans;
    vector<int> curr;
    solve(0,v,curr,ans,n);
    return ans;
}