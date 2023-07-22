#include <queue>
bool isGraphBirpatite(vector<vector<int>> &edges) {
	int n=edges.size();
	vector<int> adj[n];
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if(edges[i][j]==1){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	vector<int> vis(n,-1);
	for(int i=0; i<n; i++){
		if(vis[i]!=-1)	continue;
		queue<int> q;
		q.push(i);	vis[i]=1;
		while(!q.empty()){
			auto node = q.front();
			q.pop();
			for(auto it: adj[node]){
				if(vis[it]==-1){
					q.push(it);
					vis[it] = abs(vis[node]-1);
				} else{
					if(vis[node]==vis[it])	return false;
				}
			}
		}
	}
	return true;
}