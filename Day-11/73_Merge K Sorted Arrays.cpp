/************ Using priority queue with one traversal ***********/
#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
                        greater<pair<int,pair<int,int>>>> pq;
    for(int i=0; i<k; i++)  pq.push({arr[i][0], {i,0}});
    
    vector<int> ans;
    while(!pq.empty())
    {
        auto top = pq.top();   pq.pop();
        int val=top.first, i=top.second.first, j=top.second.second;
        ans.push_back(val);
        if(j+1 < arr[i].size()) pq.push({arr[i][j+1], {i,j+1}});
    }
    return ans;
}


/************ Without priority queue ***********/
#include <bits/stdc++.h> 
vector<int> mergeTwoSortedArrays(vector<int> v1, vector<int> v2)
{
    vector<int> ans;
    int i=0, j=0, n1=v1.size(), n2=v2.size();
    while(i<n1 && j<n2){
        if(v1[i]<v2[j]) ans.push_back(v1[i++]);
        else            ans.push_back(v2[j++]);
    }
    while(i<n1) ans.push_back(v1[i++]);
    while(j<n2) ans.push_back(v2[j++]);
    return ans;
}

vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    vector<int> v1 = arr[0];
    for(int i=1; i<k; i++){
        auto v2 = arr[i];
        v1 = mergeTwoSortedArrays(v1,v2);
    }
    return v1;
}
