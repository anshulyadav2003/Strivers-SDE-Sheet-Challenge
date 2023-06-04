#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &perm, int n)
{
    // int n = perm.size();
    int breakPoint=-1;
    for(int i=n-1; i>0; i--){
        if(perm[i]>perm[i-1]){
            breakPoint=i-1;
            break;
        }
    }
    // no next lexicographically greater perm possible
    if(breakPoint==-1){
        reverse(begin(perm),end(perm));
        return perm;
    }

    for(int i=n-1; i>breakPoint; i--){
        if(perm[i]>perm[breakPoint]){
            swap(perm[i],perm[breakPoint]);
            break;
        }
    }
    reverse(perm.begin()+breakPoint+1, perm.end());
    return perm;
}