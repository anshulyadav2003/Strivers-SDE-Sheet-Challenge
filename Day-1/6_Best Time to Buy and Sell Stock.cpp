#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int n = prices.size();
    int ans = 0;
    int buy = 0;
    for(int i=1; i<n; i++){
        if(prices[i]<prices[buy]){
            buy = i;    continue;
        }
        ans = max(ans, prices[i]-prices[buy]);
    }
    return ans;
}