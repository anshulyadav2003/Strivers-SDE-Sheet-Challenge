#include <bits/stdc++.h>
int smallerThanEqualMid(vector<vector<int>> &mat, int mid, int n, int m)
{
    int cnt=0;
    for(auto v: mat){
        int idx = upper_bound(begin(v),end(v),mid) - v.begin();
        cnt += idx;
    }
    return cnt;
}

int getMedian(vector<vector<int>> &mat)
{
    int n=mat.size(), m=mat[0].size();
    int total = n*m;
    
    int ans=-1;
    int l=1, h=1e5;
    while(l<=h)
    {
        int mid = (l+(h-l)/2);
        int left = smallerThanEqualMid(mat,mid,n,m);
        if(left >= total/2+1){
            ans = mid;
            h=mid-1;
        } 
        else    l=mid+1;
    }
    return ans; 
}


/***** Brute force******/
// #include <bits/stdc++.h>
// int getMedian(vector<vector<int>> &matrix)
// {
//     vector<int> arr;
//     for(auto v:matrix){
//         for(auto it:v)  arr.push_back(it);
//     }

//     sort(arr.begin(), arr.end());
//     int n=arr.size();
//     return (n%2 != 0) ? arr[n/2] : (arr[n/2] + arr[n/2 +1])/2;
// }