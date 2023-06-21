#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	stack<int> st;
	for(int i=0; i<n; i++)	st.push(i);

	while(st.size()>1){
		int a=st.top();	st.pop();
		int b=st.top(); st.pop();
		bool ab=knows(a,b), ba=knows(b,a);
		if(ab && !ba)	st.push(b);
		else if(!ab && ba)	st.push(a);
	} 
	if(st.size()==0)	return -1;
	// remaining is not necessary a celebrity, so just cross check it
	int celeb = st.top();
	// does celeb knows anyone ?  OR
	// does all knows celeb ?
	for(int i=0; i<n; i++){
		if(i==celeb)	continue;
		if(knows(celeb,i) || !knows(i,celeb))	return -1;
	}
	return celeb;
}