#include <bits/stdc++.h>
class MedianFinder {
public:
    int n;
    int n1=0,n2=0;
    priority_queue<int> q1;
    priority_queue<int,vector<int>,greater<int>> q2;
    MedianFinder() {
        this->n = 0;
    }
    
    void addNum(int num) {
        if(n1==0 || num<q1.top()){
            q1.push(num);   n1++;
        }else{
            q2.push(num);   n2++;
        }

        // we have to maintain abs(n1-n2)<=1
        if(n1-n2>1){
            q2.push(q1.top());
            q1.pop();
            n1--; n2++;
        } else if(n2-n1>1){
            q1.push(q2.top());
            q2.pop();
            n1++; n2--;
        }
        n++;
    }
    
    int findMedian() {
        if(n1==0 && n2==0)  return -1;

        if(n%2==0)  
            return (q1.top()+q2.top())/2;
        else
            return (n1>n2) ? q1.top() : q2.top();
    }
};

vector<int> findMedian(vector<int> &arr, int n){
	MedianFinder mf;
	vector<int> ans;
	for(auto num: arr){
		mf.addNum(num);
		ans.push_back(mf.findMedian());
	}
	return ans;
}
