int removeDuplicates(vector<int> &arr, int n) {
	int ans=n;
	int curr=1;
	for(int i=1; i<n; i++){
		if(arr[i]!=arr[i-1]){
			ans -= (curr-1);
			curr=0;
		}
		curr++;
	}
	ans -= (curr-1);
	return ans;
}