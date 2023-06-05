#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    int n=arr.size();
    // there will be no more than 2 majority elements
    int ele1=-1, ele2=-1;
    int cnt1=0, cnt2=0;
    for(auto it: arr){
        if(it==ele1)    cnt1++;
        else if(it==ele2)   cnt2++;
        else if(cnt1==0){
            ele1=it;    cnt1=1; 
        } 
        else if(cnt2==0){
            ele2=it;    cnt2=1;
        } else{
            cnt1--; cnt2--;
        }
    }

    // confirm for ele1 and ele2
    cnt1=0, cnt2=0;
    for(auto it:arr){
        if(it==ele1)    cnt1++;
        if(it==ele2)    cnt2++;
    }

    vector<int> ans;
    if(cnt1 > floor(n/3))   ans.push_back(ele1);
    if(cnt2 > floor(n/3))   ans.push_back(ele2);
    return ans;
}