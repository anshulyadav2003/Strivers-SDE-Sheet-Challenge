#include <bits/stdc++.h> 

int uniqueSubstrings(string input)
{
    int n = input.length();
    unordered_map<char,int> mp; //stores last occurence idx of element
    int left=0,right=0;
    int maxi=1;
    while(right<n)
    {
        if(mp[input[right]]>0){
            left = max(left, mp[input[right]]+1);
        }
        mp[input[right]]=right;
        maxi = max(maxi, right-left+1);
        right++;
    }

    // vector<int> map(26,0);
    // int left=0;
    // int maxi= 1;
    // for(int right=0; right<input.length(); right++){
    //     map[input[right]-'a']++;
    //     while(map[input[right]-'a']>1){
    //        map[input[left]-'a']--;
    //        left++;
    //     }
    //     maxi = max(maxi,right-left+1);
    // }

    return maxi;

}