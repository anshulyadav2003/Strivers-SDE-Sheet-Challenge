
/*********** N ************/
#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    vector<int> ans;
    unordered_map<int,int> mp;
    int distinct=0;
    for(int i=0; i<arr.size(); i++){
        if(mp[arr[i]]==0)    distinct++;
        mp[arr[i]]++;
        if(i>=k && --mp[arr[i-k]]==0)   distinct--;
        if(i>=k-1)  
            ans.push_back(distinct);
    }
    return ans;
	
}


/************** NlogN *********/
#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    vector<int> ans;
    unordered_map<int,int> mp;
    for(int i=0; i<arr.size(); i++){
        mp[arr[i]]++;
        if(i>=k && --mp[arr[i-k]]==0)
            mp.erase(arr[i-k]);
        if(i>=k-1)  
            ans.push_back(mp.size());
    }
    return ans;
	
}