#include <bits/stdc++.h>
void findMedian(int *arr, int n)
{
    priority_queue<int> pq1;
    priority_queue<int,vector<int>,greater<int>> pq2;
    for(int i=0; i<n; i++)
    {
        if(pq1.size()==0)   pq1.push(arr[i]);
        else{
            if(arr[i]>pq1.top()){
                pq2.push(arr[i]);
                if(pq2.size()>pq1.size()){
                    pq1.push(pq2.top());
                    pq2.pop();
                }
            }
            else{
                pq1.push(arr[i]);
                if(pq1.size()-pq2.size() > 1){
                    pq2.push(pq1.top());
                    pq1.pop();
                }
            }
            
        }
        int currMedian = ((i+1)%2!=0) ? pq1.top() :
                            (pq1.top()+pq2.top())/2;  
        cout<<currMedian<<" ";
    }
    cout<<endl;
}