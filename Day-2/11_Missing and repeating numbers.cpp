#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
    pair<int,int> res; // missing, repeating
    vector<int> A;
    A=arr;
    for(int i=0; i<A.size(); i++){
        int curr = abs(A[i]);
        if(A[curr-1]<0){
            // repeating
            res.second = curr;
            continue;
        }
        A[curr-1] = -A[curr-1];
    }
    for(int i=0; i<A.size(); i++){
        if(A[i]>0){
            // missing
            res.first = i+1; 
            break;
        }
    }
    return res;
	
}
