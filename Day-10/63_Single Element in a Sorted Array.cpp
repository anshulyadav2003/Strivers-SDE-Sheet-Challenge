int singleNonDuplicate(vector<int>& arr)
{
	// as array is sorted :- Binary search O(log n)
	int l=0, h=arr.size()-1;
	while(l<=h)
	{
		int mid = (l+(h-l)/2);
		if(mid%2==0){
			if(arr[mid]==arr[mid+1])	l=mid+1;
			else	h=mid-1;	
		} 
		else{
			if(arr[mid]==arr[mid-1])	l=mid+1;
			else	h=mid-1;
		}
	}
	return arr[l];
	
	/******** Using XOR property: - O(n)********/
	// int ele=0;
	// for(auto it:arr)	ele ^=it;
	// return ele;
}