#include <bits/stdc++.h> 
#define ll long long

ll merge(ll *arr,vector<ll> temp,int left,int mid,int right)
{
    ll cnt=0;
    int i=left, j=mid;
    int k=left;
    while(i<=mid-1 && j<=right){
        if(arr[i] <= arr[j])    temp[k++] = arr[i++];
        else{
            temp[k++] = arr[j++];
            cnt += (mid-i);
        }
    }

    while(i<=mid-1) temp[k++] = arr[i++];
    while(j<=right) temp[k++] = arr[j++];

    for(i=left; i<=right;i++)   arr[i] = temp[i];
    return cnt;
}

ll merge_Sort(ll *arr,vector<ll> temp,int left,int right)
{
    int mid;    ll cnt=0;
    if(right>left)
    {
        mid = (left+right)/2;

        cnt += merge_Sort(arr,temp,left,mid);
        cnt += merge_Sort(arr,temp,mid+1,right);

        cnt += merge(arr,temp,left,mid+1,right);
    }
    return cnt;
}

long long getInversions(long long *arr, int n){
    vector<ll> temp(n);
    return merge_Sort(arr,temp,0,n-1);
}