void solve(vector<int> arr, int i, int n, vector<int> curr, int sum,
            vector<vector<int>> &ans, int k)
{
    if(i>=n){
        if(sum==k)  ans.push_back(curr);
        return;
    }
    // take it
    curr.push_back(arr[i]);
    solve(arr,i+1,n,curr,sum+arr[i],ans,k);
    // don't take it
    curr.pop_back();
    solve(arr,i+1,n,curr,sum,ans,k);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> curr;
    solve(arr,0,n,curr,0,ans,k);
    return ans;
}