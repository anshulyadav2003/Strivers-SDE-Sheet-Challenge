#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    stack<int> st;
    vector<int> ans(n,-1);
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && st.top()<=arr[i])   st.pop();
        ans[i] = st.empty() ? -1: st.top();
        st.push(arr[i]);
    }
    return ans;
}