// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int> > &grid) {
	int m = grid.size(), n = grid[0].size() , i, j ;
	int dp[m][n] ;
	if(m == 0){
		return 0 ;
	}
	
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			if( i == 0 && j == 0){
				dp[i][j] = grid[i][j] ;
			}else if(i == 0){
				dp[i][j] = dp[i][j - 1] + grid[i][j];
			}else if(j == 0){
				dp[i][j] = dp[i - 1][j] + grid[i][j] ;
			}else{
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j] ;
			}
		}
	}
	return dp[m - 1][n - 1] ;
}
int _tmain(int argc, _TCHAR* argv[]){
	vector<int> sample(1, 1);
	vector<vector<int> > in (1, sample) ;
	cout << "result: " << minPathSum(in) << '\n' ;
	while(1);
	return 0;
}

