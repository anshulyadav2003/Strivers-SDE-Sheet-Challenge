#include <stack>
int largestRectangle(vector<int> &h) {
  int n=h.size();
  // store prev smaller for each element in 'h'
  vector<int> left(n);
  stack<int> st;  st.push(-1);
  for(int i=0; i<n; i++){
    while(st.top()!=-1 && h[st.top()]>=h[i])  st.pop();
    left[i] = st.top();
    st.push(i);
  }

  // store next smaller for each element in 'h'
  vector<int> right(n);
  stack<int> st1; st1.push(n);
  for(int i=n-1; i>=0; i--){
    while(st1.top()!=n && h[st1.top()]>=h[i])  st1.pop();
    right[i] = st1.top();
    st1.push(i);
  }

  // go for each bar in histogram and calculate area possible with that current height
  int maxArea=0;
  for(int i=0; i<n; i++){
    int width = right[i]-left[i]-1;
    maxArea = max(maxArea, h[i]*width);
  }
  return maxArea;
}