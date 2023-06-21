/*********** Using Next smaller and previous smaller technique ***********/
#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> arr, int n) {
    stack<int> s;
    // prev smaller idx
    vector<int> left(n+1,-1);
    for (int i=0; i<n; i++){
        while(!s.empty() && arr[s.top()]>=arr[i])
        s.pop();
        if (!s.empty())
        left[i] = s.top();
        s.push(i);
    }
    while(!s.empty())  s.pop();
    
    // next smaller idx
    vector<int> right(n+1,n);
    for (int i=n-1; i>=0; i--){
        while(!s.empty() && arr[s.top()]>=arr[i])
        s.pop();
        if (!s.empty())
        right[i] = s.top();
        s.push(i);
    }

    vector<int> temp(n+1,INT_MIN);
    for(int i=0; i<n; i++){
        int len = right[i]-left[i]-1;
        temp[len] = max(temp[len],arr[i]);
    }
    for(int i=n-1; i>=1; i--)   temp[i] = max(temp[i],temp[i+1]);
    
    vector<int> ans(temp.begin()+1,temp.end());
    return ans;
}




/***************** TLE : using approach of Maximum in sliding window of size k *********/
#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> ans;
    for(int k=1; k<=n; k++){
        // similar to question : minimum element in every window of size k
        // just store maxm of all those minm
        int maxi=INT_MIN;   // maximum of all minm ofevery window of size 'k'
        deque<int> dq;
        for(int i=0; i<n; i++){
            if(!dq.empty() && dq.front()==i-k)  dq.pop_front();
            while(!dq.empty() && arr[dq.back()]>arr[i])    dq.pop_back();
            dq.push_back(i);
            if(i>=k-1)  maxi = max(maxi, arr[dq.front()]);
        }
        ans.push_back(maxi);
    }
    return ans;
}