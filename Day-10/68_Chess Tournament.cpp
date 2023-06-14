#include <bits/stdc++.h> 

bool isPossible(vector<int> pos, int n, int players, int mid)
{
	int cnt=1, ptr=0;
	for(int i=1; i<n; i++){
		if(pos[i]-pos[ptr]>=mid){
			cnt++;	ptr=i;
			if(cnt>=players)	return true;
		}
	}
	return false;
}

int chessTournament(vector<int> pos , int n ,  int c){
	sort(begin(pos),end(pos));
	int l=1, h=pos[n-1]-pos[0];
	int ans=-1;
	while(l<=h)
	{
		int mid = (l+(h-l)/2);
		if(isPossible(pos,n,c,mid)){
			ans = mid;
			l = mid+1;
		} else{
			h = mid-1;
		}
	}
	return ans;
}