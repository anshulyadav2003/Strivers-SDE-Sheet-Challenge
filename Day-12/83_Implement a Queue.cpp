#include <bits/stdc++.h> 
class Queue {
public:
    vector<int> arr;
    int s,e;
    Queue() {
        // Implement the Constructor
        arr.resize(5000);
        s=0, e=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return s==e;

    }

    void enqueue(int data) {
        // Implement the enqueue() function
        arr[e++] = data;
    }

    int dequeue() {
        // Implement the dequeue() function
        return s==e ? -1 : arr[s++];
    }

    int front() {
        // Implement the front() function
        return s==e ? -1 : arr[s];
    }
};