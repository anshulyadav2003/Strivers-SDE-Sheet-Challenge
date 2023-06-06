#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // unordered_map<int,int> mp;
    // int ans=0;
    // for(auto it:arr){
    //     if(mp[it])  continue;   // to avoid duplicates
    //     mp[it] = mp[it-1] + mp[it+1] + 1;
    //     mp[it-mp[it-1]] = mp[it];
    //     mp[it+mp[it+1]] = mp[it];
    //     ans = max(ans, mp[it]);
    // }
    // return ans;
    
    sort(arr.begin(), arr.end());
    if(n==0 || n==1)    return n;
    int lcsLen = 1;
    int curr = 1;
    for(int i=1; i<n; i++)
    {
        if(arr[i]==arr[i-1])  continue;
        
        if(arr[i] == arr[i-1]+1)  curr++;
        else curr=1;
        lcsLen = max(lcsLen, curr);   
    }
    
    return lcsLen;
    
    
    // unordered_map<int,int> mp;
    // for(auto it: arr)    mp[it]++;
    // int ans=0;
    // for(auto it: arr){
    //     if(mp[it-1])    continue;
    //     else{
    //         int len=0,  ele=it;
    //         while(mp[ele]){
    //             len++;  ele++;
    //         }
    //         ans = max(ans,len);
    //     }
    // }
    // return ans;
}