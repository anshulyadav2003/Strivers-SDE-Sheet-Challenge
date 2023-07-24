int maxProfit(vector<int> &val, vector<int> &wgt, int n, int cap) {
	if(cap==0)	return 0;
	vector<vector<int>> dp(n+1, vector<int>(cap+1,0));

	for(int i=1; i<=n; i++){
		for(int j=1; j<=cap; j++){
			dp[i][j] = dp[i-1][j];
			if(wgt[i-1]<=j){
				dp[i][j] = max(val[i-1]+dp[i-1][j-wgt[i-1]],
								dp[i-1][j]);
			}
		}
	}
	return dp[n][cap];
}