#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &arr)
{
    int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> v;
        v.push_back(arr[0]);
        
        for(int i=1; i<n; i++)
        {
            vector<int> last = v.back();
            if(last[1]>=arr[i][0]){
                v.pop_back();
                v.push_back( {last[0],max(last[1],arr[i][1])} );
            } else{
                v.push_back(arr[i]);
            }
        }
        return v;
}
