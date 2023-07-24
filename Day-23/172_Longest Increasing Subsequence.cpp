#include <bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> lis;
    lis.push_back(arr[0]);
    for(int i=1; i<n; i++){
        if(lis.back()<arr[i])   lis.push_back(arr[i]);
        else{
            int idx = lower_bound(begin(lis), end(lis), arr[i]) - lis.begin();
            lis[idx] = arr[i];
        }
    }
    return lis.size();
}




// int longestIncreasingSubsequence(int arr[], int n)
// {
//     if(n==1)    return 1;
//     vector<int> dp(n,1);
//     for(int i=1; i<n; i++){
//         for(int j=i-1; j>=0; j--){
//             if(arr[j]<arr[i]){
//                 dp[i] = max(dp[i], 1+dp[j]);
//             }
//         }
//     }
//     return *max_element(dp.begin(), dp.end());
// }
