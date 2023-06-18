#include <bits/stdc++.h> 

void insertSortedManner(stack<int>& st, int ele){
	stack<int> temp;
	while(!st.empty() && st.top()>ele){
		temp.push(st.top());
		st.pop();
	}
	st.push(ele);
	while(!temp.empty()){
		st.push(temp.top());	temp.pop();
	}
}

void sortStack(stack<int> &st)
{
	if(st.empty())	return;
	int ele = st.top();	
	st.pop();
	sortStack(st);
	insertSortedManner(st,ele);
}