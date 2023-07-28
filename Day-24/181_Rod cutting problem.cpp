/************* Tabulation approach **************/
int cutRod(vector<int> &price, int n){
	vector<int> dp(n+1,0);

	for(int i=0; i<=n; i++){
		int cost = 0;
		for(int j=1; j<=i; j++){
			int temp = price[j-1] + dp[i-j];
			cost = max(cost,temp);
		}
		dp[i] = cost;
	}
	return dp[n];
}



/************** Memoisation Approach ************/
vector<int> dp;
int solve(int curr, vector<int> &price, int n){
	if(curr==0)	return 0;
	if(dp[curr]!=-1)	return dp[curr];

	int cost=0;
	for(int i=1; i<=curr; i++){
		int temp = price[i-1] + solve(curr-i, price,n);
		cost = max(cost, temp);
	}
	return dp[curr] = cost;
}

int cutRod(vector<int> &price, int n){
	dp.clear();
	dp.resize(n+1,-1);
	return solve(n,price,n);
}
