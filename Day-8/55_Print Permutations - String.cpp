/************* Without extra space **************/
#include <bits/stdc++.h>

void solve(string &s, int idx, int len, int n, string curr, vector<string> &ans)
{
    if(len==n){
        ans.push_back(curr);    return;
    }

    // for every index, just what possible char we can fit
    // for each possible char:- just swap it with curr index and make rcursive call for next index
    // after returning from recursive call, backtrack the changes done
    for(int i=idx; i<n; i++){
        curr += s[i];
        swap(s[idx],s[i]);
        solve(s,idx+1,len+1,n,curr,ans);
        curr.pop_back();
        swap(s[idx],s[i]);
    }
}

vector<string> findPermutations(string &s) {
    int n=s.length();
    vector<string> ans;
    string curr= "";
    solve(s,0,0,n,curr,ans);
    return ans;
}



/****************** Extra space used --- map use to keep track of index taken ***********/
// #include <bits/stdc++.h>

// void solve(string &s, int idx, int len, int n, string curr, vector<string> &ans, 
//         unordered_map<int,bool> mp)
// {
//     if(len==n){
//         ans.push_back(curr);    return;
//     }

//     for(int i=0; i<n; i++){
//         if(mp[i])   continue;
//         curr += s[i];   mp[i]=true;
//         solve(s,i+1,len+1,n,curr,ans,mp);
//         curr.pop_back();    mp[i]=false;
//     }
// }

// vector<string> findPermutations(string &s) {
//     int n=s.length();
//     vector<string> ans;
//     string curr= "";
//     unordered_map<int,bool> mp; // to keep track of taken index
//     solve(s,0,0,n,curr,ans,mp);
//     return ans;
// }