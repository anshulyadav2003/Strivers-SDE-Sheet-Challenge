#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   int n = arr.size();
   unordered_map<int,int> mp;
   vector<vector<int>> ans;
   for(int i=0; i<n; i++){
      if(mp[s-arr[i]]>0){
         vector<int> temp = {arr[i],s-arr[i]};
         sort(temp.begin(),temp.end());
         for(int k=1; k<=mp[s-arr[i]]; k++)
            ans.push_back(temp);
      } 
      mp[arr[i]]++;
   }
   sort(ans.begin(),ans.end());
   return ans;
}