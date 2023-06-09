#include <bits/stdc++.h> 

bool cmp(pair<int,int> p1, pair<int,int> p2){
    return ((double)p1.second/(double)p1.first) > ((double)p2.second/(double)p2.first);
}

double maximumValue (vector<pair<int, int>>& items, int n, int wt)
{
    sort(items.begin(), items.end(), cmp);
    double ans=0;

    for(auto p: items){
        int weight=p.first, value=p.second;
        if(wt>=weight){
            ans += value;
            wt -= weight;
        } else{
            ans += ((double)value/(double)weight)*(wt);
            break;
        }
    }
    return ans;
}