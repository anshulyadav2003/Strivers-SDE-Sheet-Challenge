#include <bits/stdc++.h> 

void solve(vector<int> &nums, int i, int n, int sum, vector<int> &ans)
{
    if(i>=n){
        ans.push_back(sum); return;
    }

    // do not take current element 
    solve(nums, i+1, n, sum, ans);

    // take current element
    solve(nums, i+1, n, sum+nums[i], ans);
}

vector<int> subsetSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;
    solve(nums,0,n,0,ans);
    sort(begin(ans),end(ans));
    return ans;
}