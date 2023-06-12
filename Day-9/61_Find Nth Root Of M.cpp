double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1;i<=n;i++) {
        ans = ans * number;
    }
    return ans; 
}

int NthRoot(int n, int m) {
  // binary search
  double l=1, h=m;
  while(l<=h){
    int mid = (l+(h-l)/2); //taking only integer value
    double ans = multiply(mid,n);
    if(ans==m)  return mid;
    else if(ans<m)  l=mid+1;
    else  h=mid-1;
  }
  return -1;
}