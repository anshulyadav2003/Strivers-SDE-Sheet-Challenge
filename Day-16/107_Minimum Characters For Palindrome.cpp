#include <bits/stdc++.h>
int findLps(string str)
    {
        int n = str.length();
        vector<int> lps(n);
        lps[0]=0;
        int len=0;
        int i=1;
        while(i<n){
            if(str[i]==str[len])    lps[i++]= ++len;
            else{
                if(len!=0)  len = lps[len-1];
                else    lps[i++]=0;
            }
        }
        return lps[n-1];
    }


int minCharsforPalindrome(string str) {
	int n=str.length();
	string rev = str;
	reverse(begin(rev),end(rev));
	str += "$" + rev;
	int x = findLps(str);
	return n-x;
}
