#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>> ans;
  ans.push_back({1});
  if(n==1)  return ans;
  ans.push_back({1,1});
  if(n==2)  return ans;

  for(int k=3; k<=n; k++){
    auto last = ans.back();
    vector<long long int> v = {1};
    for(int i=0; i<k-2; i++)  v.push_back(last[i]+last[i+1]);
    v.push_back(1);
    ans.push_back(v);
  }
  return ans;
}
