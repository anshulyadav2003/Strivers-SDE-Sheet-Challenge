#include <bits/stdc++.h> 
void computeLps(string pat, int m, vector<int> &lps)
{
    int len=0;
    lps[0]=0;
    int i=1;
    while(i<m) {
        if(pat[i]==pat[len]){
            len++;  lps[i]=len;
            i++;
        } else{
            if(len!=0)  len = lps[len-1];
            else{
                lps[i]=0;  i++;
            }
        }
    }
}

bool findPattern(string pat, string txt)
{
    int n=txt.length(), m=pat.length();
    vector<int> lps(m);
    // compute longest prefix suffix array 
    // it helps not to do repeative searching
    computeLps(pat,m,lps);
    int i=0, j=-1;
    while(i<n)
    {
        if(txt[i]==pat[j+1]){
            i++, j++;    
            if(j==m-1)    return true;    // pattern found in given text
        }
        else{
            if(j==-1)    i++;
            else        j=lps[j]-1; // -1 is to convert 1-based index to 0-based index
            
        }
    }
    return false;
}