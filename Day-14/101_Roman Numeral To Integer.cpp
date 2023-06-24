#include <bits/stdc++.h> 
int romanToInt(string s) {
    int n=s.length();
    unordered_map<char,int> mp;
    mp['I']=1, mp['V']=5, mp['X']=10, mp['L']=50;
    mp['C']=100, mp['D']=500, mp['M']=1000;

    int ans=0; int last=INT_MIN;
    for(int i=n-1; i>=0 ; i--){
        int val = mp[s[i]];
        if(val<last){
            ans -= val;
        } else{
            ans += val;
            last = val;
        }
    }
    return ans;
}
