#include <iostream>
#include <vector>

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
	int m = obstacleGrid.size() ;
	int n = obstacleGrid[0].size() ;   
	int a[m][n], i, j;
	for(i = 0; i < m; i++){
		if(obstacleGrid[i][0] == 1){
			a[i][0] = 0 ;
		}else{
			a[i][0] = 1 ;
		}
	}
	for(j = 0; j < n; j++){
		if(obstacleGrid[i][0] == 1){
			a[0][j] = 0 ;
		}else{
			a[0][j] = 1 ;
		}
	}
	for(i = 1; i < m; i++){
		for(j = 1; j < n; j++){
			if(obstacleGrid[i][0] == 1){
				a[i][j] = 0;
			}else{
				a[i][j] = a[i - 1][j] + a[i][j - 1] ;
			}
		}
	}
	return a[m - 1][n - 1] ;

}
