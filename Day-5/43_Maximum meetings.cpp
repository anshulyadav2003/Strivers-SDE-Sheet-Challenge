#include <bits/stdc++.h> 
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();
    vector<vector<int>> v;
    for(int i=0; i<n; i++)  v.push_back({start[i],end[i],i+1});
    sort(v.begin(),v.end());

    // int cnt=1;
    vector<int> ans = {v[0][2]};
    for(int i=1; i<n; i++){
        int ptr = ans.back()-1;
        if(v[i][0] > end[ptr]){
            ans.push_back(v[i][2]);
        } else{
            if((v[i][1] < end[ptr]) ||
                    (v[i][1]==end[ptr] && v[i][2]<ptr)){
                ans.pop_back();
                ans.push_back(v[i][2]);
            }
        }
    }
    return ans;
}