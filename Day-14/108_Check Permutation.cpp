#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    if(str1.length()!=str2.length())    return false;
    vector<int> v(26,0);
    for(int i=0; i<str1.length(); i++)   
        v[str1[i]-'a']++, v[str2[i]-'a']--;
    for(auto it: v) if(it!=0)   return false;
    return true;
}