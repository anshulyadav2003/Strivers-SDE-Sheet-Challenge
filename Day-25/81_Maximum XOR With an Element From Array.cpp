#include <bits/stdc++.h>
class Node{
public:
	Node* links[2];
	bool containsKey(int num)	{return links[num]!=nullptr;}
	Node* get(int num)	{return links[num];}
	void put(int num, Node* node)	{links[num]=node;}
};

class Trie{
public:
	Node* root;
	Trie(){
		root = new Node();
	}
	
	void insert(int num){
		Node* node = root;
		for(int i=31; i>=0; i--){
			int bit = ((num>>i)&1);
			if(!node->containsKey(bit)){
				node->put(bit, new Node());
			}
			node = node->get(bit);
		}
	}

	int findMaxXOR(int num){
		Node* node = root;
		int currXor = 0;
		for(int i=31; i>=0; i--){
			int bit = ((num>>i)&1);
			if(node->containsKey(!bit)){
				currXor = currXor | (1<<i);
				node = node->get(!bit);
			} else{
				node = node->get(bit);
			}
		}
		return currXor;
	}
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	Trie t;
	int n=arr.size();
	int m=queries.size();
	sort(arr.begin(),arr.end());

	vector<pair<int,pair<int,int>>> qry;
	for(int i=0; i<m; i++){
		int Xi = queries[i][0],		Ai=queries[i][1];
		qry.push_back({Ai,{Xi,i}});
	}
	sort(begin(qry),end(qry));
	
	vector<int> ans(m,0);
	int k=0;
	for(auto it: qry){
		int Ai=it.first,	Xi=it.second.first;
		int idx = it.second.second;
		while(k<n && arr[k]<=Ai){
			t.insert(arr[k]);
			k++;
		}
		if (k!=0) 	ans[idx] = t.findMaxXOR(Xi);
		else 		ans[idx] = -1;
	}
	
	return ans;
}