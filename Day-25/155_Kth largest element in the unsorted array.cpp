#include <bits/stdc++.h> 

/*********** Quick Select ( Average T.C - O(N) ) **************/
int partition(vector<int>& arr, int left, int right) {
	int pivot = arr[left];
	int i=left+1,	j=right;
	while(i<=j){
		if(arr[i]<pivot && arr[j]>pivot)	swap(arr[i++],arr[j--]);
		if(arr[i]>=pivot)	i++;
		if(arr[j]<=pivot)	j--;
	}
	swap(arr[left], arr[j]);
	return j;
}

int kthLargest(vector<int>& arr, int size, int k) {
	int left=0, right=size-1;
	while(true){
		int idx = partition(arr,left,right);
		if(idx==k-1)	return arr[idx];
		else if(idx<k-1)	left = idx+1;
		else				right = idx-1;
	}
	return -1;
}


/********* Min Heap *********/
int kthLargest(vector<int>& arr, int size, int k) {
	priority_queue<int,vector<int>, greater<int>> pq;
	for(auto it: arr){
		pq.push(it);
		if(pq.size()>k)	pq.pop();
	}
	return pq.empty() ? -1 : pq.top();
}