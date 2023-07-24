#include <vector>
int lcs(string s, string t)
{
	int ns = s.length();
	int nt = t.length();
	vector<vector<int>> dp(ns+1,vector<int>(nt+1,0));

	for(int i=1; i<=ns; i++){
		for(int j=1; j<=nt; j++){
			if(s[i-1]==t[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else	
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[ns][nt];
}