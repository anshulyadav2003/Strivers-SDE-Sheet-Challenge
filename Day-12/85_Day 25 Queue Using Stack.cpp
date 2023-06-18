#include <stack>
class Queue {
    // Define the data members(if any) here.    
public:
    stack<int> s1;
    stack<int> s2;
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        s1.push(val);
    }

    int deQueue() {
        while(!s1.empty()){
            s2.push(s1.top());  s1.pop();
        }  
        if(s2.size()==0)    return -1;
        int ans=s2.top();   s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());  s2.pop();
        }
        return ans;
    }

    int peek() {
        if(s1.size()==0)    return -1;
        while(!s1.empty()){
            s2.push(s1.top());  s1.pop();
        }  
        int ans=s2.top();
        while(!s2.empty()){
            s1.push(s2.top());  s2.pop();
        }
        return ans;
    }

    bool isEmpty() {
        return s1.size()==0;
    }
};