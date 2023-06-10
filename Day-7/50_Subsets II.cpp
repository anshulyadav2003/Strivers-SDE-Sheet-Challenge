#include <bits/stdc++.h> 

void solve(vector<int> &arr, int i, int n, vector<int> curr, 
            set<vector<int>> &st) {
    if(i>=n){
        sort(begin(curr),end(curr));
        st.insert(curr);    return;
    }
    // take 
    curr.push_back(arr[i]);
    solve(arr,i+1,n,curr,st);
    // don't take
    curr.pop_back();
    solve(arr,i+1,n,curr,st);
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    set<vector<int>> st;
    vector<int> curr;
    solve(arr,0,n,curr,st);

    vector<vector<int>> ans;
    for(auto v:st)  ans.push_back(v);
    return ans;
}