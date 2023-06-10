#include <bits/stdc++.h>

// approach without using set
void solve(vector<int> &arr, int idx, int n, vector<int> curr, 
			vector<vector<int>> &ans, int target)
{
    if(target==0){
		ans.push_back(curr);	return;
    }
    
	for(int i=idx; i<n; i++){
		if(i>idx && arr[i]==arr[i-1])	continue;
		if(target < arr[i])	break;	// because further elemnts are greater (as arr is sorted)
		curr.push_back(arr[i]);
		solve(arr,i+1,n,curr,ans,target-arr[i]);
		curr.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	sort(begin(arr),end(arr));
	vector<vector<int>> ans;
    vector<int> curr;
    solve(arr,0,n,curr,ans,target);
    return ans;
}



/************** TIME LIMIT EXCEEDED :-- we are using SET to find Unique combinations ************/
// #include <bits/stdc++.h>

// void solve(vector<int> &arr, int i, int n, vector<int> curr, int sum,
//             set<vector<int>> &st, int k)
// {
//     if(i>=n){
//         if(sum==k){
// 			sort(begin(curr),end(curr));
// 			st.insert(curr);
// 		}
//         return;
//     }
//     // take it
//     curr.push_back(arr[i]);
//     solve(arr,i+1,n,curr,sum+arr[i],st,k);
//     // don't take it
//     curr.pop_back();
//     solve(arr,i+1,n,curr,sum,st,k);
// }

// vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
// {
// 	set<vector<int>> st;
//     vector<int> curr;
//     solve(arr,0,n,curr,0,st,target);

// 	vector<vector<int>> ans;
// 	for(auto v:st)	ans.push_back(v);
//     return ans;
// }
