#include <bits/stdc++.h> 

void solve(int idx, string curr, vector<string>& ans, 
        unordered_map<string,bool> mp, string& s)
{
    int n = s.length();
    if(idx==n){
        if(curr.back()==' ')    curr.pop_back();
        ans.push_back(curr);    return;
    }

    for(int i=idx; i<n; i++){
        string word = s.substr(idx,i-idx+1);
        if(mp[word]==false) continue;
        string prev = curr;
        curr += word + " ";
        solve(i+1,curr,ans,mp,s);
        curr = prev;
    }
}

vector<string> wordBreak(string &s, vector<string> &dict)
{
    int n=s.length();
    unordered_map<string,bool> mp;
    for(auto str: dict)   mp[str]=true;

    vector<string> ans;
    string curr = "";
    solve(0,curr,ans,mp,s);
    sort(begin(ans),end(ans));
    return ans;
}