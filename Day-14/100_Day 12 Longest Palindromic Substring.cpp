/*************  Two Pointers **********/
string longestPalinSubstring(string str)
{
    int n = str.length();
    if(n<2) return str;
    int idx=0, maxLen=1;
    for(int i=0; i<n; i++){
        int l=i-1, r=i+1;
        while(l>=0 && str[l]==str[i])   l--;
        while(r<n && str[r]==str[i])   r++;
        while(l>=0 && r<n && str[l]==str[r])    l--, r++;
        int currLen = r-l-1;
        if(currLen > maxLen){
            idx = l+1;  maxLen=currLen;
        }
    }
    return str.substr(idx,maxLen);
}


/*************** DP approach ***************/
string longestPalinSubstring(string str)
{
    int n=str.length();
    bool dp[n][n] = {false};

    // length 1
    for(int i=0; i<n; i++)  dp[i][i]=true;
    int idx=0, maxLen=1;
    // length 2
    for(int i=n-1; i>=0; i--){
        if(str[i]==str[i+1]){
            dp[i][i+1] = true;
            idx = i;    maxLen=2;
        } 
    }
    // length 3 to n
    for(int k=3; k<=n; k++){
        for(int i=0; i<=n-k; i++){
            int j = i+k-1;
            if(str[i]==str[j] && dp[i+1][j-1]==true){
                dp[i][j]=true;
                if(k>maxLen){
                    idx = i;
                    maxLen = k;
                }
            }
        }
    }
    return str.substr(idx,maxLen);
}