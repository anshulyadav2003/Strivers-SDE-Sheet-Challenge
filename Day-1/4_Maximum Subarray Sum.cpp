#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long ans=INT_MIN,curr=0;
    for(int i=0; i<n; i++){
        curr += arr[i];
        ans = max(ans, (long long)curr);
        if(curr<0)  curr=0;
    }
    return ans<0 ? 0 : ans;
}