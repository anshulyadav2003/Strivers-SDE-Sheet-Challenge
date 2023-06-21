#include <bits/stdc++.h> 
// nothing but a type of next greater element in reverse order
vector<int> findSpans(vector<int> &price) {
    stack<int> st;
    st.push(-1);
    vector<int> left(price.size());
    for(int i=0; i<price.size(); i++){
        while(st.top()!=-1 && price[st.top()]<=price[i])    st.pop();
        left[i] = st.top();
        st.push(i); 
    }

    for(int i=0; i<left.size(); i++)    left[i] = i-left[i];
    return left;
}