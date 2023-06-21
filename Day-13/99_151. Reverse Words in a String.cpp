#include <stack>
string reverseString(string &str){
	stack<string> st;
	string temp = "";
	for(auto it:str){
		if(it==' '){
			if(temp=="")	continue;
			st.push(temp);
			temp = "";
		} else{
			temp += it;
		}
	}
	if(temp!="")	st.push(temp);
	string ans = "";
	while(!st.empty()){
		ans += st.top() + " ";
		st.pop();
	}
	ans.pop_back();
	return ans;
}


/*********** TLE **********/
string reverseString(string &str){
	string ans="";
	string temp = "";
	for(auto it:str){
		if(it==' '){
			if(temp=="")	continue;
			reverse(temp.begin(),temp.end());
			ans += " " + temp;
			temp = "";
		}
		else	temp = temp + it;
	}
	reverse(temp.begin(),temp.end());
	if(temp!="")	ans += " " + temp;
	reverse(begin(ans),end(ans));
	if(ans.back()==' ')	ans.pop_back();
	return ans;
}