#include <bits/stdc++.h> 
class Stack {
	// Define the data members.
public:
    queue<int> q1,q2;
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q1.size();
    }

    bool isEmpty() {
        return q1.empty();
    }

    void push(int element) {
        while(!q1.empty()){
            q2.push(q1.front());    q1.pop();
        }
        q1.push(element);
        while(!q2.empty()){
            q1.push(q2.front());    q2.pop();
        }
    }

    int pop() {
        int ans = q1.empty() ? -1 : q1.front();
        if(!q1.empty()) q1.pop();
        return ans;
    }

    int top() {
        return q1.empty() ? -1 : q1.front();
    }
};