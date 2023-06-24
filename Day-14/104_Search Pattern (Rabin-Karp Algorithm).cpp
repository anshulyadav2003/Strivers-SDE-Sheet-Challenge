#define base 256
vector<int> stringMatch(string txt, string pat) {
	vector<int> ans;
	int n=txt.length(), m=pat.length();
	int mod = INT_MAX;
	int mul=1;
	int t=0,p=0;
	for(int i=0; i<m-1; i++)	mul = (mul*base)%mod;

	// calculate hash for 'pat' and first window of 'text'
	for(int i=0; i<m; i++){
		t = (t*base + txt[i])%mod;
		p = (p*base + pat[i])%mod;
	}

    for (int i=0; i<=n-m; i++) {
        if (p==t) {
			int j=0;
            for (j=0; j<m; j++) {
                if (txt[i + j] != pat[j]) break;
            }
            if(j==m)	ans.push_back(i+1);
        }
        if(i<n-m){
            t = ( base*(t-txt[i]*mul) + txt[i+m] )%mod;
			if(t<0)	t=t+mod;
        }
    }
	return ans;
}
