#include <bits/stdc++.h> 

bool isPossible(vector<int> time,int m, long long int mid, int n)
{
	int cnt=1;
	long long int curr=0;
	for(int i=0; i<m; i++){
		if(curr+time[i] <= mid){
			curr += time[i];
		} else{
			cnt++;	
			if(cnt>n || time[i]>mid)	return false;
			curr=time[i];
		}
	}
	return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long int low=0, high=accumulate(time.begin(), time.end(), 0LL);
	long long int ans=-1;
	while(low<=high)
	{
		long long int mid = (low+(high-low)/2);
		if(isPossible(time,m,mid,n)){
			ans = mid;
			high = mid-1;
		} else{
			low = mid+1;
		}
	}
	return ans;
}