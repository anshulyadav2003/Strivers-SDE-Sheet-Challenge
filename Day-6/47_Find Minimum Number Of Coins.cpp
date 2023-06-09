#include <bits/stdc++.h> 
int findMinimumCoins(int amt) 
{
    vector<int> c = {1,2,5,10,20,50,100,500,1000};
    int j = upper_bound(c.begin(), c.end(), amt) - c.begin() - 1;
    
    int coins=0;
    while(j>=0){
        if(c[j] <= amt){
            coins++;
            amt -= c[j];
            if(amt==0)  break;
        } else{
            j--;
        }
    }
    return coins;
}
