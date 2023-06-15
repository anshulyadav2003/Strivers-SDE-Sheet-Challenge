#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	vector<int> ans;
	sort(begin(a),end(a),greater<int>());
	sort(begin(b),end(b),greater<int>());
	
	priority_queue<pair<int,pair<int,int>>> pq;	// {sum, {i,j}}
	vector<vector<int>> mp(n,vector<int>(n,false));
	
	pq.push({a[0]+b[0], {0,0}});
	mp[0][0]=true;
	while(k--){
		int top = pq.top().first;
		int i=pq.top().second.first, 	j=pq.top().second.second;
		pq.pop();
		ans.push_back(top);
		
		// (i+1,j)	and (i,j+1)	;--> push their comb. sum if not already taken
		if(i+1<n && mp[i+1][j]==false){
			pq.push({a[i+1]+b[j], {i+1,j}});
			mp[i+1][j]=true;
		}
		if(j+1<n && mp[i][j+1]==false){
			pq.push({a[i]+b[j+1], {i,j+1}});
			mp[i][j+1]=true;
		}
	}

	return ans;
}


/************************ Brute force *******************/
#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	priority_queue<int> pq;
	for(auto x:a){
		for(auto y:b){
			int comb = x+y;
			pq.push(comb);
		}
	}

	vector<int> ans;
	while(k--){
		ans.push_back(pq.top());
		pq.pop();
	}
	return ans;
}