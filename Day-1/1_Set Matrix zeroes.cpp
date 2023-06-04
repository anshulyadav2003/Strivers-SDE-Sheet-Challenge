#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &mat)
{
	int n=mat.size(), m=mat[0].size();

	bool firstRowZero=false, firstColZero=false;
	for(int i=0; i<m; i++){	// check if first row has zero
		if(mat[0][i]==0)	firstRowZero=true;
	}
	for(int i=0; i<n; i++){	// check if first col has zero
		if(mat[i][0]==0)	firstColZero=true;
	}

	// check zeroes and store in first row and col
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			if(mat[i][j]==0){
				mat[0][j]=0;
				mat[i][0]=0;
			}
		}
	}

	// using stored values put zero in matrix
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			if(mat[i][0]==0 || mat[0][j]==0)
				mat[i][j]=0;
		}
	}

	// if first row had any zero, then make it completely zero
	if(firstRowZero){
		for(int j=0; j<m; j++)	mat[0][j]=0;
	}
	// if first col had any zero, then make it completely zero
	if(firstColZero){
		for(int i=0; i<n; i++)	mat[i][0]=0;
	}
}