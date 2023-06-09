int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at,at+n);    sort(dt,dt+n);
    int dept=0;
    int cnt=1, ans=1;
    for(int i=1; i<n; i++){
        while(at[i] > dt[dept]){
            dept++; cnt--;  // a train departed
        }
        cnt++;  // train arrived
        ans = max(ans,cnt);
    }
    return ans;
}