#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector<int> arr) {
  int n = arr.size();
  unordered_map<int,int> mp;
  int ans=0;
  int sum=0;
  for(int i=0; i<n; i++){
    sum += arr[i];
    if(sum==0)  ans=(i+1);
    else{
      // if current sum previously existed then we have got required subarray 
      if(mp.find(sum)!=mp.end()){
        int prevIdx = mp[sum];
        ans = max(ans, i-prevIdx);
      } else{
        mp[sum] = i;
      }
    }
  } 

  return ans;
}