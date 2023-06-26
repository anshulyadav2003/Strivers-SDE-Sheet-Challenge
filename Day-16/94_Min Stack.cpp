/************** O(1)-Time & O(N)-Space ***********/
#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack{
public:
	typedef long long ll;
	stack<ll> st;
	ll mini;
	minStack() 
	{ 
		while(!st.empty())	st.pop();
		mini=INT_MAX;
	}
	
	// Function to add another element equal to num at the top of stack.
	void push(int num)
	{
		num = (ll)num;
		if(st.empty()){
			st.push(num); 
			mini=num;	
			return;
		}
		if(num<mini){
			ll modifiedVal = 2*num*1LL-mini;
			st.push(modifiedVal);
			mini = num;
		} 
		else	st.push(num);
	}
	
	// Function to remove the top element of the stack.
	int pop()
	{
		if(st.empty())	return -1;
		int ans=st.top();
		if(st.top()<mini){
			ans = mini;
			ll prevMin = 2*mini - st.top();
			mini = prevMin;
		} 
		st.pop();
		if(st.empty())	mini=INT_MAX;
		return ans;
	}
	
	// Function to return the top element of stack if it is present. Otherwise return -1.
	int top()
	{
		if(st.empty())	return -1;
		ll top = st.top();
		return (top<mini) ? mini : top;
	}
	
	// Function to return minimum element of stack if it is present. Otherwise return -1.
	int getMin()
	{
		return st.empty() ? -1 : mini;
	}
};




/************** O(1)-Time & O(2N)-Space ***********/



/****************** TLE **************/
#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
public:
		stack<int> stMin;
		stack<int> st;
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			st.push(num);
			// if(stMin.empty()){
			// 	stMin.push(num);	return;
			// }
			stack<int> temp;
			while(!stMin.empty() && stMin.top()<num){
				temp.push(stMin.top());	stMin.pop();
			}
			stMin.push(num);
			while(!temp.empty()){
				stMin.push(temp.top());	temp.pop();
			}
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			if(st.empty())	return -1;
			int ans = st.top();	st.pop();
			stack<int> temp;
			while(!stMin.empty() && stMin.top()!=ans){
				temp.push(stMin.top());	stMin.pop();
			}
			stMin.pop();
			while(!temp.empty()){
				stMin.push(temp.top());	temp.pop();
			}
			return ans;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			return st.empty() ? -1 : st.top();
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			return stMin.empty() ? -1 : stMin.top();
		}
};