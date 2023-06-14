/************** Optimal appraoch - Binary search *****************/
double median(vector<int>& a, vector<int>& b) {
	int n1=a.size() , n2=b.size();
    if(n1>n2)   median(b,a);

    int l=0, h=n1;
    while(l<=h)
    {
        // no of elements in left part to be taken from Vector 'a'
        int cut1 = (l+h)>>1;
        int leftPart = (n1+n2+1)/2; // if n1+n2 is odd always keep extra element in left part
        // no of elements in left part to be taken from vector 'b'
        int cut2 = leftPart-cut1;

        int l1 = (cut1==0)  ?   INT_MIN : a[cut1-1];
        int l2 = (cut2==0)  ?   INT_MIN : b[cut2-1];
        int r1 = (cut1==n1)  ?   INT_MAX : a[cut1];
        int r2 = (cut2==n2)  ?   INT_MAX : b[cut2];

        if(l1<=r2 && l2<=r1){
            // cuts that we put were correct 
            if((n1+n2)%2 == 0)      return ( max(l1,l2) + min(r1,r2) )/2.0;
            else    return (double)max(l1,l2);
        }

        if(l1>r2)   h = cut1-1;
        if(l2>r1)   l = cut1+1;
    }
    return -1.0;
}




/*************************** Two Priority queue appraoch  ********************/
// double median(vector<int>& a, vector<int>& b) {
// 	int n1=a.size(), n2=b.size();
// 	priority_queue<int> pq1;
// 	priority_queue<int,vector<int>,greater<int>> pq2;

// 	int i=0,j=0;
// 	while(i<n1 && j<n2)
// 	{
// 		int ele;
// 		if(a[i]<=b[j])	ele = a[i++];
// 		else	ele = b[j++];

// 		pq2.push(ele);
// 		if(!pq2.empty() && pq2.size()>pq1.size()){
// 			pq1.push(pq2.top());	pq2.pop();
// 		}
// 	}
// 	while(i<n1){
// 		pq2.push(a[i++]);
// 		if(!pq2.empty() && pq2.size()>pq1.size()){
// 			pq1.push(pq2.top());	pq2.pop();
// 		}
// 	}
// 	while(j<n2){
// 		pq2.push(b[j++]);
// 		if(!pq2.empty() && pq2.size()>pq1.size()){
// 			pq1.push(pq2.top());	pq2.pop();
// 		}
// 	}

// 	if(pq1.size()>pq2.size())	return pq1.top();
// 	return (pq1.top() + pq2.top())/(double)2;
// }