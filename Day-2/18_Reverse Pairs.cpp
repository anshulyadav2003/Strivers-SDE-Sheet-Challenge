#include <bits/stdc++.h> 
#define ll long long
int merge(vector<int> &arr,vector<int> temp,int left,int mid,int right)
{
	int cnt=0;
    int i=left, j=mid;
	while(i<=mid-1 && j<=right){
        if(arr[i] <= 2*arr[j])    i++;
        else{
			cnt += (mid-i);
			j++;
        }
    }

	i=left, j=mid;
	int k=left;
    while(i<=mid-1 && j<=right){
        if(arr[i] <= arr[j])    temp[k++] = arr[i++];
        else					temp[k++] = arr[j++];
    }
    while(i<=mid-1) temp[k++]=arr[i++];
    while(j<=right) temp[k++]=arr[j++];
    for(i=left; i<=right;i++)   arr[i]=temp[i];
    return cnt;
}

int merge_Sort(vector<int> &arr,vector<int> temp,int left,int right)
{
    int mid;    int cnt=0;
    if(right>left)
    {
        mid = (left+right)/2;

        cnt += merge_Sort(arr,temp,left,mid);
        cnt += merge_Sort(arr,temp,mid+1,right);

        cnt += merge(arr,temp,left,mid+1,right);
    }
    return cnt;
}

int reversePairs(vector<int> &arr, int n){
	vector<int> temp(n);
	return merge_Sort(arr,temp,0,n-1);
}