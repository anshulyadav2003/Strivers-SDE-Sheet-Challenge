#include <bits/stdc++.h> 
string writeAsYouSpeak(int n) 
{
	if(n==1)	return "1";
	if(n==2)	return "11";

	string s = writeAsYouSpeak(n-1);
	string ans = "";	
	int len=s.length();
	int cnt=1;
	for(int i=1; i<len; i++){
		if(s[i]!=s[i-1]){
			ans += to_string(cnt) + s[i-1];
			cnt=0;
		}
		cnt++;
	}	
	if(cnt>0)	ans += to_string(cnt) + s[len-1];	
	return ans;
}