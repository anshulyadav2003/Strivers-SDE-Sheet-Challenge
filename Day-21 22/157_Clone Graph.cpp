#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
graphNode* solve(graphNode* node, unordered_map<graphNode*,graphNode*> &mp) {
	graphNode *cnode = new graphNode(node->data);
	mp[node] = cnode;
	for(auto it: node->neighbours){
		graphNode *temp;
		if(mp.count(it))	temp = mp[it];
		else				temp = solve(it,mp);
		cnode->neighbours.push_back(temp);
	}
	return cnode;
}


graphNode *cloneGraph(graphNode *node)
{
	unordered_map<graphNode*,graphNode*> mp;
	return solve(node,mp);
}