#include <bits/stdc++.h> 

bool cmp(vector<int>v1, vector<int>v2){
    return (v1[1]>v2[1]);
}

int jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    sort(jobs.begin(),jobs.end(), cmp);
    int maxi=INT_MIN;
    for(auto it: jobs)  maxi = (it[0]>maxi) ? it[0] : maxi;

    vector<int> allotTime(maxi+1, -1);  // 1-based indexing
    
    int profit=0, cnt=0;
    for(int i=0; i<n; i++){
        int deadline = jobs[i][0];
        // find which time can be alloted to this job
        for(int j=deadline; j>0; j--){
            if(allotTime[j]==-1){ // this time is free
                allotTime[j] = i;
                cnt++;
                profit += jobs[i][1];
                break;
            }
        }
    }
    return profit;
}
