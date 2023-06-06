#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x){
    int n=arr.size();
    unordered_map<int,int> mp;
    int currXor=0, cnt=0;
    mp[currXor]++;
    for(int i=0; i<n; i++){
        currXor ^= arr[i];
        int prev = currXor ^ x;
        cnt += mp[prev];    // increment cnt by no. of previous occurence which can result in target 'x'
        mp[currXor]++;  // INSERT current XOR value into map
    }
    return cnt;
}