#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	int ans=arr[0];
	int cnt=1;
	for(int i=1; i<n; i++){
		if(arr[i]==ans)	cnt++;
		else{
			cnt--;
			if(cnt==0){
				ans = arr[i];
				cnt=1;
			}
		}
	}

	cnt=0;
	for(int i=0; i<n; i++){
		if(arr[i]==ans)	cnt++;
	}
	return (cnt>n/2) ? ans : -1;
}