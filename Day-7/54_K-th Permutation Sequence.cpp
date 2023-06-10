#include <bits/stdc++.h>

string kthPermutation(int n, int k) {
    vector<int> nums;
    long fac=1;
    for(int i=1; i<n; i++){
        nums.push_back(i);  fac*=i;
    }
    nums.push_back(n);

    string ans="";
    k = k-1;
    while(true){
        ans += to_string(nums[k/fac]);
        nums.erase(nums.begin() + (k/fac));
        if(nums.size()==0)  break;
        k = k%fac;
        fac = fac/nums.size();
    }
    return  ans;
}
