#include <bits/stdc++.h>

string fourSum(vector<int> nums, int target, int n) {
    // vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    
    for(int i=0; i<n; i++)
    {
        int a = nums[i];
        // int k1 = target-a;
        long long k1 = (long long)target - (long long)a;
        for(int j=i+1; j<n; j++)
        {
            int b = nums[j];
            // long long int k2 = k1-b;
            long long k2 = (long long)k1 - (long long)b;
            int s=j+1, e=n-1;
            while(s<e)
            {
                int sum = nums[s]+nums[e];
                if(sum==k2){
                    return "Yes";
                    // ans.push_back({a, b, nums[s], nums[e]});
                    // while(s<e && nums[s+1]==nums[s])    s++;
                    // while(s<e && nums[e-1]==nums[e])    e--;
                    // s++; e--;
                }
                else if(sum<k2){
                    s++;
                }
                else{
                    e--;
                }
            }
            while(j+1<n && nums[j+1]==nums[j])  j++;
        }
        while(i+1<n && nums[i+1]==nums[i])  i++;
    }
    return "No";
    // return ans;
}
