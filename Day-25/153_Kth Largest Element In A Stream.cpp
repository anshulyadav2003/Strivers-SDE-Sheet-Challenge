#include <algorithm>

class Kthlargest {
public:
    priority_queue<int,vector<int>, greater<int>> pq;
    int k;
    Kthlargest(int k, vector<int> &arr) {
        for(auto it: arr){
            pq.push(it);
            if(pq.size()>k) pq.pop();
        }
        this->k = k;
    }

    int add(int num) {
        pq.push(num);
        if(pq.size()>k) pq.pop();
        return pq.empty() ? -1 : pq.top();
    }

};