#include <bits/stdc++.h> 
int atoi(string str) {
    int n = str.length();
    int ans=0;
    int fac=1;
    int sign=1;
    for(int i=n-1; i>=0; i--){
        if(str[i]=='-') sign *= -1;
        int x = str[i]-'0';
        if(x<0 || x>9) continue;
        ans = x*fac + ans;
        fac *= 10;
    }
    return ans*sign;
}