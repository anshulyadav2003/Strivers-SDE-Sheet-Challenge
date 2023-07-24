#include <bits/stdc++.h> 

vector<vector<int>> dp;

int solve(vector<int>& rack, int pi, int i, int n) {
	if(i==n)	return 0;
	if(dp[pi+1][i]!=-1)	return dp[pi+1][i];

	int take,notTake;
	if(pi==-1){
		take = rack[i] + solve(rack,i,i+1,n);
		notTake = solve(rack,pi,i+1,n);
	} else{
		take = (rack[i]>rack[pi]) ? rack[i]+solve(rack,i,i+1,n) : 0;
		notTake = solve(rack,pi,i+1,n);
	}
	return dp[pi+1][i] = max(take,notTake);
}

int maxIncreasingDumbbellsSum(vector<int> &rack, int n) {
	dp.clear();
	dp.resize(n+2,vector<int>(n+2,-1));
	int ans = solve(rack, -1, 0, n);
	return ans;
}