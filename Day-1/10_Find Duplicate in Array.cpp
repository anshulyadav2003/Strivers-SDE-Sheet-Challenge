#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	int k = arr[0];
	while(true){
		int temp = arr[k];
		if(arr[k]==-1)	return k;
		arr[k] = -1;
		k = temp;
	}
	return -1;
}
