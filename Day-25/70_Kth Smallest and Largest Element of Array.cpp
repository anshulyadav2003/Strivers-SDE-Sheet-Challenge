#include <bits/stdc++.h> 
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	sort(arr.begin(),arr.end());
	return {arr[k-1], arr[n-k]};


	// priority_queue<int> pq1;	// kth smallest
	// priority_queue<int,vector<int>,greater<int>> pq2;	// kth smallest
	// for(auto it:arr){
	// 	pq1.push(it);
	// 	pq2.push(it);
	// 	if(pq1.size()>k)	pq1.pop();
	// 	if(pq2.size()>k)	pq2.pop();
	// }

	// return {pq1.top(), pq2.top()};


}