/************************ Binary search in space of possible answer ****************/
bool isPossible(vector<int> &row1, vector<int> &row2, int m, int n, int mid, int k)
{
    int cnt=0;
    cnt += upper_bound(begin(row1),end(row1),mid) - row1.begin();
    cnt += upper_bound(begin(row2),end(row2),mid) - row2.begin();
    return cnt>=k;
}

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    int l=0, h=1e5;
    int ans;
    while(l<=h)
    {
        int mid = (l+(h-l)/2);
        if(isPossible(row1,row2,m,n,mid,k)){
            ans = mid;
            h = mid-1;
        } else{
            l = mid+1;
        }
    }
    return ans;
}


/************************ Linearly : TWO Pointers *****************/
// int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
//     int i=0,j=0;
//     while(i<m && j<n)
//     {
//         k--;
//         if(k==0)    return min(row1[i],row2[j]);
//         if(row1[i]<row2[j]) i++;
//         else    j++;
//     }
//     while(i<m){
//         k--;
//         if(k==0)    return row1[i];
//         i++;
//     }
//     while(j<n){
//         k--;
//         if(k==0)    return row2[j];
//         j++;
//     }
//     return -1;
// }