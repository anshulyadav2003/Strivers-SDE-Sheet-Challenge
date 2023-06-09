#include <bits/stdc++.h>

int maximumActivities(vector<int> &s, vector<int> &f) {
    int n = f.size();
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++)  v.push_back({f[i],s[i]});
    sort(v.begin(), v.end());

    int limit = v[0].first;
    int cnt=1;
    for(auto p: v){
        if(p.second>=limit){
            cnt++;
            limit = p.first;
        }
    }
    return cnt;
}